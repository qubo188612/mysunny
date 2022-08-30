// Copyright 2019 Zhushi Tech, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "line_center_reconstruction/line_center_reconstruction.hpp"

#include <memory>
#include <utility>
#include <vector>

#include "opencv2/opencv.hpp"

namespace line_center_reconstruction
{

/**
 * @brief Construct a vector of points from ROS point cloud message.
 *
 * @param ptr Unique pointer to ROS point cloud.
 * @return std::vector<cv::Point2f> A vector of points.
 */
std::vector<cv::Point2f> from_pc2(const PointCloud2::UniquePtr & ptr)
{
  auto num = ptr->width;
  std::vector<cv::Point2f> pnts;
  pnts.reserve(num);
  auto p = reinterpret_cast<float *>(ptr->data.data());
  for (size_t i = 0; i < num; ++i) {
    if (p[i] > 0) {
      pnts.emplace_back(p[i], static_cast<float>(i));
    }
  }
  return pnts;
}

/**
 * @brief Construct ROS point cloud message from two vector of points with x, y, i information.
 *
 * @param dst A sequence of points represent x, y.
 * @param src A sequence of points represent u, v.
 * @return PointCloud2::UniquePtr Point cloud message to publish.
 */
PointCloud2::UniquePtr to_pc2(
  const std::vector<cv::Point2f> & dst,
  const std::vector<cv::Point2f> & src)
{
  auto num = dst.size();
  auto ptr = std::make_unique<PointCloud2>();

  ptr->height = 1;
  ptr->width = num;

  ptr->fields.resize(3);

  ptr->fields[0].name = "x";
  ptr->fields[0].offset = 0;
  ptr->fields[0].datatype = 7;
  ptr->fields[0].count = 1;

  ptr->fields[1].name = "y";
  ptr->fields[1].offset = 4;
  ptr->fields[1].datatype = 7;
  ptr->fields[1].count = 1;

  ptr->fields[2].name = "i";
  ptr->fields[2].offset = 8;
  ptr->fields[2].datatype = 7;
  ptr->fields[2].count = 1;

  ptr->is_bigendian = false;
  ptr->point_step = 4 * 3;
  ptr->row_step = 12 * num;

  ptr->data.resize(12 * num);

  ptr->is_dense = true;

  auto p = reinterpret_cast<float *>(ptr->data.data());
  for (size_t i = 0; i < num; ++i) {
    p[i * 3 + 0] = dst[i].x;
    p[i * 3 + 1] = dst[i].y;
    p[i * 3 + 2] = src[i].y;
  }

  return ptr;
}

std::vector<tutorial_interfaces::msg::IfAlgorhmitpoint4f> to_pc3(
  const std::vector<cv::Point2f> & dst,
  const std::vector<cv::Point2f> & src)
{
  auto num = dst.size();
  std::vector<tutorial_interfaces::msg::IfAlgorhmitpoint4f> ptr;
  if(dst.size()>0)
      ptr.resize(dst.size());
  for (size_t i = 0; i < num; ++i) {
    ptr[i].x = dst[i].x;
    ptr[i].y = dst[i].y;
    ptr[i].u = src[i].x;
    ptr[i].v = src[i].y;
  }

  return ptr;
}

/**
 * @brief The algorithm to transform points from image plane to laser plane.
 *
 * For more details of the algorithm, refer to the README.md.
 * @param ptr The input point cloud data.
 * @return PointCloud2::UniquePtr Point cloud message to publish.
 */
PointCloud2::UniquePtr LineCenterReconstruction::execute(PointCloud2::UniquePtr ptr, const Params & pm)
{
  if (ptr->header.frame_id == "-1" || ptr->data.empty()) {return ptr;}

  auto src = from_pc2(ptr);
  if (src.empty()) {
    auto msg = std::make_unique<PointCloud2>();
    msg->header = ptr->header;
    return msg;
  }

  auto _homo = cv::Mat(pm.homography_matrix, true).reshape(1, 3);

  std::vector<cv::Point2f> dst;
  dst.reserve(ptr->width);
  cv::perspectiveTransform(src, dst, _homo);
  auto msg = to_pc2(dst, src);
  msg->header = ptr->header;
  return msg;
}

IfAlgorhmitcloud::UniquePtr LineCenterReconstruction::_task100_199_execute(IfAlgorhmitmsg::UniquePtr ptr, const Params & pm)
{
  if (ptr->imageout.header.frame_id == "-1" 
   || ptr->targetpointout.size()==0
   || ptr->result==false) 
   {
      auto msg = std::make_unique<IfAlgorhmitcloud>();
      msg->header = ptr->imageout.header;

      if(b_modbusconnect==true)
      {
        u_int16_t tab_reg[1];
        tab_reg[0]=0;
        int rc=modbus_write_registers(ctx,0x02,1,tab_reg);
      }

      return msg;
   }

  auto msg = std::make_unique<IfAlgorhmitcloud>();

  auto _homo = cv::Mat(pm.homography_matrix, true).reshape(1, 3);
  std::vector<cv::Point2f> dst;
  dst.reserve(ptr->imageout.height);
  std::vector<cv::Point2f> src;
  for(int i=0;i<ptr->lasertrackout.size();i++)
  {
      cv::Point2f point(ptr->lasertrackout[i].x,ptr->lasertrackout[i].y);
      src.push_back(point);
  }
  if(src.size()>0)
      cv::perspectiveTransform(src, dst, _homo);
  auto cloud = to_pc3(dst, src);
  msg->lasertrackoutcloud = cloud;
  
  src.clear();
  for(int i=0;i<ptr->targetpointout.size();i++)
  {
      cv::Point2f point(ptr->targetpointout[i].x,ptr->targetpointout[i].y);
      src.push_back(point);
  }
  if(src.size()>0)
      cv::perspectiveTransform(src, dst, _homo);

  for(int i=0;i<dst.size();i++)
  {
    tutorial_interfaces::msg::IfAlgorhmittargetpoint4f pointtarget;
    pointtarget.x=dst[i].x;
    pointtarget.y=dst[i].y;
    pointtarget.u=src[i].x;
    pointtarget.v=src[i].y;
    pointtarget.name=ptr->targetpointout[i].name;
    msg->targetpointoutcloud.push_back(pointtarget);
  }
  msg->solderjoints = ptr->solderjoints;
  msg->header = ptr->imageout.header;


  if(b_modbusconnect==true)
  {
    u_int16_t tab_reg[3];
    tab_reg[0]=0xff;
    tab_reg[1]=(uint16_t)((int32_t)(msg->targetpointoutcloud[0].x*100+0.5));
    tab_reg[2]=(uint16_t)((int32_t)(msg->targetpointoutcloud[0].y*100+0.5));
    int rc=modbus_write_registers(ctx,0x02,3,tab_reg);
    if(rc!=3)
    {
      RCLCPP_ERROR(this->get_logger(), "modbus send result error 0x02=%d",rc);
    }

    if(msg->targetpointoutcloud.size()>1)
    {
      int num=msg->targetpointoutcloud.size();
      auto othertab_reg=new u_int16_t [(num-1)*2];
      for(int i=1;i<num;i++)
      {
        othertab_reg[(i-1)*2]=(uint16_t)((int32_t)(msg->targetpointoutcloud[i].x*100+0.5));
        othertab_reg[(i-1)*2+1]=(uint16_t)((int32_t)(msg->targetpointoutcloud[i].y*100+0.5));
      }
      int rc=modbus_write_registers(ctx,0x50,2*(num-1),othertab_reg);
      if(rc!=2*(num-1))
      {
        RCLCPP_ERROR(this->get_logger(), "modbus send result error 0x50=%d",rc);
      }
      delete othertab_reg;
    }

    if(msg->solderjoints==true)
    {
      tab_reg[0]=0xff;
    }
    else
    {
      tab_reg[0]=0;
    }
    rc=modbus_write_registers(ctx,0x60,1,tab_reg);
    if(rc!=1)
    {
      RCLCPP_ERROR(this->get_logger(), "modbus send result error 0x60=%d",rc);
    }
  }

  return msg;
}

/**
 * @brief Extract extra 'worker' parameter from ROS node options.
 *
 * @param options Encapsulation of options for node initialization.
 * @return int Number of workers.
 */
int workers(const rclcpp::NodeOptions & options)
{
  for (const auto & p : options.parameter_overrides()) {
    if (p.get_name() == "workers") {
      return p.as_int();
    }
  }
  return 1;
}

LineCenterReconstruction::LineCenterReconstruction(const rclcpp::NodeOptions & options)
: Node("line_center_reconstruction_node", options)
{
  b_modbusconnect=false;

  _thread = std::thread(&LineCenterReconstruction::_modbus, this, 1502);

  _pub = this->create_publisher<PointCloud2>(_pub_name, rclcpp::SensorDataQoS());

  _pub_task100_199 = this->create_publisher<IfAlgorhmitcloud>(_pub_task100_199_name, rclcpp::SensorDataQoS());

  _declare_parameters();

  _workers = workers(options);
  for (int i = 0; i < _workers; ++i) {
    _threads.push_back(std::thread(&LineCenterReconstruction::_worker, this));
  }
  _threads.push_back(std::thread(&LineCenterReconstruction::_manager, this));
  

  for (int i = 0; i < _workers; ++i) {
    _task100_199_threads.push_back(std::thread(&LineCenterReconstruction::_task100_199_worker, this));
  }
  _task100_199_threads.push_back(std::thread(&LineCenterReconstruction::_task100_199_manager, this));


  _sub = this->create_subscription<PointCloud2>(
    _sub_name,
    rclcpp::SensorDataQoS(),
    [this](PointCloud2::UniquePtr ptr)
    {
      _push_back_point(std::move(ptr));
    }
  );

  _sub_task100_199 = this->create_subscription<IfAlgorhmitmsg>(
    _sub_task100_199_name,
    rclcpp::SensorDataQoS(),
    [this](IfAlgorhmitmsg::UniquePtr ptr)
    {
      _push_back_point_task100_199(std::move(ptr));
    }
  );

  RCLCPP_INFO(this->get_logger(), "Ininitialized successfully");
}

LineCenterReconstruction::~LineCenterReconstruction()
{
  try {
    _thread.join();
    _sub.reset();
    _points_con.notify_all();
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

void LineCenterReconstruction::_declare_parameters()
{
  Params pm;
  // this->declare_parameter("camera_matrix", pm.camera_matrix);
  // this->declare_parameter("distort_coeffs", pm.distort_coeffs);
  this->declare_parameter("homography_matrix", pm.homography_matrix);
}

Params LineCenterReconstruction::_update_parameters()
{
  Params pm;
  const auto & vp = this->get_parameters(KEYS);
  for (const auto & p : vp) {
    if (p.get_name() == "homography_matrix") {
      pm.homography_matrix = p.as_double_array();
    }
    // if (p.get_name() == "camera_matrix") {
    //   pm.camera_matrix = p.as_double_array();
    // } else if (p.get_name() == "distort_coeffs") {
    //   pm.distort_coeffs = p.as_double_array();
    // } else if (p.get_name() == "homography_matrix") {
    //   pm.homography_matrix = p.as_double_array();
    // }
  }
  return pm;
  // for (const auto & p : vp) {
  //   if (p.get_name() == "camera_matrix") {
  //     _coef = cv::Mat(p.as_double_array(), true).reshape(1, 3);
  //   } else if (p.get_name() == "distort_coeffs") {
  //     _dist = cv::Mat(p.as_double_array(), true).reshape(1, 1);
  //   } else if (p.get_name() == "homography_matrix") {
  //     _homo = cv::Mat(p.as_double_array(), true).reshape(1, 3);
  //   }
  // }
}

void LineCenterReconstruction::_modbus(int port)
{
  while (rclcpp::ok()) 
  {
    ctx = modbus_new_tcp(NULL, 1502);
    if (!ctx) {
      RCLCPP_ERROR(this->get_logger(), "Failed to create modbus context.");
      rclcpp::shutdown();
      return;
    }
    if (modbus_connect(ctx) == -1)
    {
      modbus_free(ctx);
      usleep(5);
      continue;
    }
    RCLCPP_INFO(this->get_logger(), "connect modbus context succeed.");
    b_modbusconnect=true;
    break;
  }
}

void LineCenterReconstruction::_worker()
{
  while (rclcpp::ok()) {
    std::unique_lock<std::mutex> lk(_points_mut);
    if (_points.empty() == false) {
      auto ptr = std::move(_points.front());
      _points.pop_front();
      std::promise<PointCloud2::UniquePtr> prom;
      _push_back_future(prom.get_future());
      auto pm = _update_parameters();
      lk.unlock();
      auto msg = execute(std::move(ptr), pm);
      prom.set_value(std::move(msg));
    } else {
      _points_con.wait(lk);
    }
  }
}

void LineCenterReconstruction::_task100_199_worker()
{
  while (rclcpp::ok()) {
    std::unique_lock<std::mutex> lk(_task100_199_mut);
    if (_task100_199.empty() == false) {
      auto ptr = std::move(_task100_199.front());
      _task100_199.pop_front();
      std::promise<IfAlgorhmitcloud::UniquePtr> prom;
      _push_back_future_task100_199(prom.get_future());
      auto pm = _update_parameters();
      lk.unlock();
      auto msg = _task100_199_execute(std::move(ptr), pm);
      prom.set_value(std::move(msg));
    } else {
      _task100_199_con.wait(lk);
    }
  }
}

void LineCenterReconstruction::_manager()
{
  while (rclcpp::ok()) {
    std::unique_lock<std::mutex> lk(_futures_mut);
    if (_futures.empty() == false) {
      auto f = std::move(_futures.front());
      _futures.pop_front();
      lk.unlock();
      auto ptr = f.get();
      _pub->publish(std::move(ptr));
    } else {
      _futures_con.wait(lk);
    }
  }
}

void LineCenterReconstruction::_task100_199_manager()
{
  while (rclcpp::ok()) {
    std::unique_lock<std::mutex> lk(_task100_199_futures_mut);
    if (_task100_199_futures.empty() == false) {
      auto f = std::move(_task100_199_futures.front());
      _task100_199_futures.pop_front();
      lk.unlock();
      auto ptr = f.get();
      _pub_task100_199->publish(std::move(ptr));
    } else {
      _task100_19_futures_con.wait(lk);
    }
  }
}

void LineCenterReconstruction::_push_back_point(PointCloud2::UniquePtr ptr)
{
  std::unique_lock<std::mutex> lk(_points_mut);
  _points.emplace_back(std::move(ptr));
  auto s = static_cast<int>(_points.size());
  if (s > _workers + 1) {
    _points.pop_front();
  }
  lk.unlock();
  _points_con.notify_all();
}

void LineCenterReconstruction::_push_back_point_task100_199(IfAlgorhmitmsg::UniquePtr ptr)
{
  std::unique_lock<std::mutex> lk(_task100_199_mut);
  _task100_199.emplace_back(std::move(ptr));
  auto s = static_cast<int>(_task100_199.size());
  if (s > _workers + 1) {
    _task100_199.pop_front();
  }
  lk.unlock();
  _task100_199_con.notify_all();
}

void LineCenterReconstruction::_push_back_future(std::future<PointCloud2::UniquePtr> fut)
{
  std::unique_lock<std::mutex> lk(_futures_mut);
  _futures.emplace_back(std::move(fut));
  lk.unlock();
  _futures_con.notify_one();
}

void LineCenterReconstruction::_push_back_future_task100_199(std::future<IfAlgorhmitcloud::UniquePtr> fut)
{
  std::unique_lock<std::mutex> lk(_task100_199_futures_mut);
  _task100_199_futures.emplace_back(std::move(fut));
  lk.unlock();
  _task100_19_futures_con.notify_one();
}

}  // namespace line_center_reconstruction

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(line_center_reconstruction::LineCenterReconstruction)
