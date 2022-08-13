#include "laser_imagepos/laser_imagepos.hpp"
#include <cstdio>

#include "opencv2/opencv.hpp"

namespace laser_imagepos
{

using rcl_interfaces::msg::SetParametersResult;

int workers(const rclcpp::NodeOptions & options)
{
  for (const auto & p : options.parameter_overrides()) {
    if (p.get_name() == "workers") {
      return p.as_int();
    }
  }
  return 1;
}

LaserImagePos::LaserImagePos(const rclcpp::NodeOptions & options)
: Node("laser_imagepos_node", options)
{
  _param_camera = std::make_shared<rclcpp::AsyncParametersClient>(this, "camera_tis_node");

  ps = _get_nowexposure();

  _pub = this->create_publisher<PointCloud2>(_pub_name, rclcpp::SensorDataQoS());

  _declare_parameters();

  pm = _update_parameters();

  _workers = workers(options);
  for (int i = 0; i < _workers; ++i) {
    _threads.push_back(std::thread(&LaserImagePos::_worker, this));
  }

  _sub = this->create_subscription<Image>(
    _sub_name,
    rclcpp::SensorDataQoS(),
    [this](Image::UniquePtr ptr)
    {
      _push_back_image(std::move(ptr));
    }
  );

  _handle = this->add_on_set_parameters_callback(
    [this](const std::vector<rclcpp::Parameter> & vp) {
      SetParametersResult result;
      result.successful = true;
      for (const auto & p : vp) {
        if (p.get_name() == "als100_threshold") {
          auto k = p.as_int();
          if (k <20 || k>65535) {
            result.successful = false;
            result.reason = "Failed to set als100_threshold";
            return result;
          }
          else
          {
            pm.als100_threshold=k;
          }
        } else if (p.get_name() == "task_num") {
          if (p.as_int() < 0) {
            result.successful = false;
            result.reason = "Failed to set task_num";
            return result;
          }
          else
          {
            if(p.as_int()>=100&&p.as_int()<200)
            {
              if(pm.task_num>=0&&pm.task_num<100)
              {
                ps=_get_nowexposure();//保存当前曝光以便之后复位
              }
            }
            pm.task_num=p.as_int();
            if(pm.task_num>=0&&pm.task_num<100)
            {
              _param_camera->set_parameters({rclcpp::Parameter("exposure_time", ps._0_99_exposure)});
            }
            else if(pm.task_num>=100&&pm.task_num<200)
            {
              switch(pm.task_num)
              {
                case 100:
                  _param_camera->set_parameters({rclcpp::Parameter("exposure_time", pm.als100_threshold)});
                break;
                defatult:
                break;
              }
            }
          }
        }
      }
      return result;
    }
  );

  RCLCPP_INFO(this->get_logger(), "Ininitialized successfully");
}

LaserImagePos::~LaserImagePos()
{
  try {
    _sub.reset();
    _handle.reset();
    _param_camera.reset();
    _images_con.notify_all();
    _futures_con.notify_one();
    for (auto & t : _threads) {
      t.join();
    }
    _pub.reset();

    RCLCPP_INFO(this->get_logger(), "Destroyed successfully");
  } catch (const std::exception & e) {
    RCLCPP_ERROR(this->get_logger(), "Exception in destructor: %s", e.what());
  } catch (...) {
    RCLCPP_ERROR(this->get_logger(), "Exception in destructor: unknown");
  }
}

void LaserImagePos::_declare_parameters()
{
  this->declare_parameter("als100_threshold", pm.als100_threshold);
  this->declare_parameter("task_num", pm.task_num);
}

Params LaserImagePos::_update_parameters()
{
  const auto & vp = this->get_parameters(KEYS);
  for (const auto & p : vp) {
    if (p.get_name() == "als100_threshold") {
      pm.als100_threshold = p.as_int();
    } else if (p.get_name() == "task_num") {
      pm.task_num = p.as_int();
    }
  }
  return pm;
}

Params_exposure LaserImagePos::_get_nowexposure()
{
  const std::vector<std::string> KEYS2 = {"exposure_time"};
  const auto  vp = _param_camera->get_parameters(KEYS2);
  for (const auto  p : vp.get()) {
    if (p.get_name() == "exposure_time") {
      ps._0_99_exposure = p.as_int();
    } 
  }
  return ps;
}

PointCloud2::UniquePtr to_pc2(const std::vector<float> & pnts)
{
  auto ptr = std::make_unique<PointCloud2>();
  if (pnts.empty()) {return ptr;}

  auto num = pnts.size();

  ptr->height = 1;              // If the cloud is unordered, height is 1  如果cloud 是无序的 height 是 1
  ptr->width = num;             //点云的长度

  ptr->fields.resize(1);

  ptr->fields[0].name = "u";
  ptr->fields[0].offset = 0;
  ptr->fields[0].datatype = 7;    // 	 INT8    = 1
                                  //	 UINT8   = 2
                                  //	 INT16   = 3
                                  //	 UINT16  = 4
                                  //	 INT32   = 5
                                  //	 UINT32  = 6
                                  //	 FLOAT32 = 7
                                  //	 FLOAT64 = 8
  ptr->fields[0].count = 1;     

  ptr->is_bigendian = false;
  ptr->point_step = 4;        // Length of a point in bytes 一个点占的比特数 
  ptr->row_step = num * 4;    // Length of a row in bytes 一行的长度占用的比特数

  ptr->data.resize(num * 4);

  ptr->is_dense = true;       // 没有非法数据点

  memcpy(ptr->data.data(), pnts.data(), num * 4);

  return ptr;
}

std::vector<float> center(
  const cv::Mat & img,
  cv::Mat & buf,
  const Params & pm)
{
  std::vector<float> pnts;
  if (img.empty()) {return pnts;}

  pnts.clear();

  return pnts;
}

PointCloud2::UniquePtr execute(Image::UniquePtr ptr, cv::Mat & buf, const Params & pm)
{
  if (ptr->header.frame_id == "-1" || ptr->data.empty()) {
    auto line = std::make_unique<PointCloud2>();
    line->header = ptr->header;
    return line;
  }
  cv::Mat img(ptr->height, ptr->width, CV_8UC1, ptr->data.data());
  auto pnts = center(img, buf, pm);
  auto line = to_pc2(pnts);
  line->header = ptr->header;
  return line;
}

void LaserImagePos::_worker()
{
  cv::Mat buf;
  while (rclcpp::ok()) {
    std::unique_lock<std::mutex> lk(_images_mut);
    if (_images.empty() == false) {
      auto ptr = std::move(_images.front());
      _images.pop_front();
      std::promise<PointCloud2::UniquePtr> prom;
      _push_back_future(prom.get_future());
      lk.unlock();
      if(pm.task_num>=100&&pm.task_num<200)
      {
        auto line = execute(std::move(ptr), buf, pm);
        prom.set_value(std::move(line));
      }
    } else {
      _images_con.wait(lk);
    }
  }
}

void LaserImagePos::_push_back_image(Image::UniquePtr ptr)
{
  std::unique_lock<std::mutex> lk(_images_mut);
  _images.emplace_back(std::move(ptr));
  auto s = static_cast<int>(_images.size());
  if (s > _workers + 1) {
    _images.pop_front();
  }
  lk.unlock();
  _images_con.notify_all();
}

void LaserImagePos::_push_back_future(std::future<PointCloud2::UniquePtr> fut)
{
  std::unique_lock<std::mutex> lk(_futures_mut);
  _futures.emplace_back(std::move(fut));
  lk.unlock();
  _futures_con.notify_one();
}

}


#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(laser_imagepos::LaserImagePos)