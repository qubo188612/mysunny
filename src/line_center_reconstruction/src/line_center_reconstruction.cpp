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
#include "line_center_reconstruction/TimeFunction.h"

#include <memory>
#include <utility>
#include <vector>

#include "opencv2/opencv.hpp"

template<typename _Tp>
std::vector<_Tp> convertMat2Vector(cv::Mat &mat)
{
	return (std::vector<_Tp>)(mat.reshape(1, 1));//通道数不变，按行转为一行
}


namespace line_center_reconstruction
{
  using rcl_interfaces::msg::SetParametersResult;
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
  u_int16_t Y,m,d,H,M,S,ms;
  if(b_modbusconnect==true)
  {
      TimeFunction time;
      time.get_time_ms(Y,m,d,H,M,S,ms);
      u_int16_t tab_reg[4];
      tab_reg[0]=H;
      tab_reg[1]=M;
      tab_reg[2]=S;
      tab_reg[3]=ms;
      int rc=modbus_write_registers(ctx,0x0d,4,tab_reg);

      u_int16_t u_res=0;
      rc=modbus_write_registers(ctx,0x11,1,&u_res);
  }
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
        int16_t i_res=-1;
        u_int16_t u_res=(u_int16_t)i_res;
        rc=modbus_write_registers(ctx,0x11,1,&u_res);
      }
      if(ptr->imageout.header.frame_id != "-1")
      {
        u_int16_t tab_reg[4];
        auto stamp = msg->header.stamp;
        time_t t;
        u_int16_t msec = msg->header.stamp.nanosec/1000000;
        struct tm *p;
        t=stamp.sec;
        p=gmtime(&t);  
        
        tab_reg[0]=(p->tm_hour+8)%24;
        tab_reg[1]=p->tm_min;
        tab_reg[2]=p->tm_sec;
        tab_reg[3]=msec;
        static double oldtime=0;
        double nowtime;
        struct timespec timerun = {0, 0};
        clock_gettime(CLOCK_REALTIME, &timerun);
        if(oldtime!=0)
        {
          nowtime=(double)timerun.tv_sec+(double)timerun.tv_nsec/1000000000.0;
          double fps=1.0/(nowtime-oldtime);
          tab_reg[4]=(u_int16_t)(fps*100.0);
          oldtime=nowtime;
        }
        else
        {
          oldtime=(double)timerun.tv_sec+(double)timerun.tv_nsec/1000000000.0;
          tab_reg[4]=0;
        }
        int rc=modbus_write_registers(ctx,0x07,5,tab_reg);
        if(rc!=5)
        {
          RCLCPP_ERROR(this->get_logger(), "modbus send result error 0x05=%d",rc);
        }

        long nowmstime=(long)ms+(long)S*1000+(long)M*60*1000+(long)H*60*60*1000;
        long fpsmstime=(long)msec+(long)p->tm_sec*1000+(long)p->tm_min*60*1000+(long)((p->tm_hour+8)%24)*60*60*1000;
        if(nowmstime<fpsmstime)
        {
          nowmstime=nowmstime+24*60*60*1000;
        }
        u_int16_t msadd=(u_int16_t)(nowmstime-fpsmstime);
        rc=modbus_write_registers(ctx,0x01,1,&msadd);
        if(rc!=1)
        {
          RCLCPP_ERROR(this->get_logger(), "modbus send result error 0x01=%d",rc);
        }
      }
      return msg;
   }

  auto msg = std::make_unique<IfAlgorhmitcloud>();

  auto _homo = cv::Mat(pm.homography_matrix, true).reshape(1, 3);
  std::vector<cv::Point2f> dst;
  std::vector<cv::Point2f> src;
  for(int i=0;i<ptr->lasertrackout.size();i++)
  {
      cv::Point2f point;
      if(ptr->lasertrackout[i].x>=0)
      {
        point.x=ptr->lasertrackout[i].x;
        point.y=ptr->lasertrackout[i].y;
      }
      else
      {
        point.x=-1;
        point.y=ptr->lasertrackout[i].y;
      }
      src.push_back(point);
  }
  if(src.size()>0)
  {
      dst.reserve(src.size());
      cv::perspectiveTransform(src, dst, _homo);
  }
  float ddx=float(centerData.compensation_dx)/100;
  float ddy=float(centerData.compensation_dy)/100;
  float ddz=float(centerData.compensation_dz)/100;

  auto cloud = to_pc3(dst, src);

  int reverse_y,reverse_z;
  if(centerData.reverse_y==0)
  {
    reverse_y=1;
  }
  else
  {
    reverse_y=-1;
  }
  if(centerData.reverse_z==0)
  {
    reverse_z=1;
  }
  else
  {
    reverse_z=-1;
  }
  for(int i=0;i<cloud.size();i++)
  {
    cloud[i].x=cloud[i].x*reverse_y+ddy;
    cloud[i].y=cloud[i].y*reverse_z+ddz;
  }
  msg->lasertrackoutcloud = cloud;
  
  dst.clear();
  src.resize(ptr->targetpointout.size());
  for(int i=0;i<ptr->targetpointout.size();i++)
  {
      cv::Point2f point(ptr->targetpointout[i].x,ptr->targetpointout[i].y);
      src[i]=point;
  }
  if(src.size()>0)
  {
      dst.reserve(src.size());
      cv::perspectiveTransform(src, dst, _homo);
  }

  msg->targetpointoutcloud.resize(dst.size());
  for(int i=0;i<dst.size();i++)
  {
    msg->targetpointoutcloud[i].x=dst[i].x*reverse_y+ddy;
    msg->targetpointoutcloud[i].y=dst[i].y*reverse_z+ddz;
    msg->targetpointoutcloud[i].u=src[i].x;
    msg->targetpointoutcloud[i].v=src[i].y;
    msg->targetpointoutcloud[i].name=ptr->targetpointout[i].name;
  }
  msg->solderjoints = ptr->solderjoints;
  msg->header = ptr->imageout.header;


  if(b_modbusconnect==true)
  {
    u_int16_t tab_reg[10];

    auto stamp = msg->header.stamp;
    time_t t;
    u_int16_t msec = msg->header.stamp.nanosec/1000000;
    struct tm *p;
    t=stamp.sec;
    p=gmtime(&t);  

    //如果图像法向量为0则输出法向量0
    if(msg->targetpointoutcloud[1].u==0&&msg->targetpointoutcloud[1].v==0)
    {
        msg->targetpointoutcloud[1].x=0;
        msg->targetpointoutcloud[1].y=0;
    }
    else
    {
      double dis=sqrt(msg->targetpointoutcloud[1].x*msg->targetpointoutcloud[1].x+
                      msg->targetpointoutcloud[1].y*msg->targetpointoutcloud[1].y);
        msg->targetpointoutcloud[1].x=msg->targetpointoutcloud[1].x/dis;
        msg->targetpointoutcloud[1].y=msg->targetpointoutcloud[1].y/dis;
    }

    tab_reg[0]=0xff;
    tab_reg[1]=(uint16_t)((int32_t)(msg->targetpointoutcloud[0].x*100+0.5));
    tab_reg[2]=(uint16_t)((int32_t)(msg->targetpointoutcloud[0].y*100+0.5));
    tab_reg[3]=(uint16_t)((int32_t)(msg->targetpointoutcloud[1].x*1000+0.5));
    tab_reg[4]=(uint16_t)((int32_t)(msg->targetpointoutcloud[1].y*1000+0.5));
    tab_reg[5]=(p->tm_hour+8)%24;
    tab_reg[6]=p->tm_min;
    tab_reg[7]=p->tm_sec;
    tab_reg[8]=msec;

    static double oldtime=0;
    double nowtime;
    struct timespec timerun = {0, 0};
    clock_gettime(CLOCK_REALTIME, &timerun);
    if(oldtime!=0)
    {
      nowtime=(double)timerun.tv_sec+(double)timerun.tv_nsec/1000000000.0;
      double fps=1.0/(nowtime-oldtime);
      tab_reg[9]=(u_int16_t)(fps*100.0);
      oldtime=nowtime;
    }
    else
    {
      oldtime=(double)timerun.tv_sec+(double)timerun.tv_nsec/1000000000.0;
      tab_reg[9]=0;
    }

    int rc=modbus_write_registers(ctx,0x02,10,tab_reg);
    if(rc!=10)
    {
      RCLCPP_ERROR(this->get_logger(), "modbus send result error 0x02=%d",rc);
    }

    tab_reg[0]=(u_int16_t)centerData.compensation_dx;
    tab_reg[1]=(u_int16_t)0;
    rc=modbus_write_registers(ctx,0x70,2,tab_reg);
    if(rc!=2)
    {
      RCLCPP_ERROR(this->get_logger(), "modbus send compensation error 0x70=%d",rc);
    }

    if(msg->targetpointoutcloud.size()>2)
    {
      int num=msg->targetpointoutcloud.size();
      auto othertab_reg=new u_int16_t [(num-2)*2];
      for(int i=2;i<num;i++)
      {
        othertab_reg[(i-2)*2]=(uint16_t)((int32_t)(msg->targetpointoutcloud[i].x*100+0.5));
        othertab_reg[(i-2)*2+1]=(uint16_t)((int32_t)(msg->targetpointoutcloud[i].y*100+0.5));
      }
      int rc=modbus_write_registers(ctx,0x50,2*(num-2),othertab_reg);
      if(rc!=2*(num-2))
      {
        RCLCPP_ERROR(this->get_logger(), "modbus send result error 0x50=%d",rc);
      }
      delete othertab_reg;
    }

    long nowmstime=(long)ms+(long)S*1000+(long)M*60*1000+(long)H*60*60*1000;
    long fpsmstime=(long)msec+(long)p->tm_sec*1000+(long)p->tm_min*60*1000+(long)((p->tm_hour+8)%24)*60*60*1000;
    if(nowmstime<fpsmstime)
    {
      nowmstime=nowmstime+24*60*60*1000;
    }
    u_int16_t msadd=(u_int16_t)(nowmstime-fpsmstime);
    rc=modbus_write_registers(ctx,0x01,1,&msadd);
    if(rc!=1)
    {
      RCLCPP_ERROR(this->get_logger(), "modbus send result error 0x01=%d",rc);
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

    u_int16_t u_res=1;
    rc=modbus_write_registers(ctx,0x11,1,&u_res);
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
  
  this->declare_parameter("compensation_dx", centerData.compensation_dx);
  this->declare_parameter("compensation_dy", centerData.compensation_dy);
  this->declare_parameter("compensation_dz", centerData.compensation_dz);
  if(centerData.reverse_y==0)
    this->declare_parameter("reverse_y", false);
  else
    this->declare_parameter("reverse_y", true);
  if(centerData.reverse_z==0)
    this->declare_parameter("reverse_z", false);
  else
    this->declare_parameter("reverse_z", true);

  _param_camera_get = std::make_shared<rclcpp::AsyncParametersClient>(this, "camera_tis_node");

  picheight=PIC_IMAGE_HEIGHT;
  picwidth=PIC_IMAGE_WIDTH;
  _param_camera_get->wait_for_service();
  auto parameters_future = _param_camera_get->get_parameters(
                {"width","height"},
                std::bind(&LineCenterReconstruction::callbackGlobalParam, this, std::placeholders::_1));            

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

  _handle = this->add_on_set_parameters_callback(
    [this](const std::vector<rclcpp::Parameter> & parameters) {
      SetParametersResult result;
      result.successful = true;
      for (const auto & p : parameters) {
        if (p.get_name() == "compensation_dx") {
          centerData.compensation_dx=(Int16)p.as_int();
          centerData.write_center_para();
        } 
        else if (p.get_name() == "compensation_dy") {
          centerData.compensation_dy=(Int16)p.as_int();
          centerData.write_center_para();
        }    
        else if (p.get_name() == "compensation_dz") {
          centerData.compensation_dz=(Int16)p.as_int();
          centerData.write_center_para();
        }
        else if (p.get_name() == "reverse_y") {
          centerData.reverse_y=(Int16)p.as_bool();
          centerData.write_center_para();
        }
        else if (p.get_name() == "reverse_z") {
          centerData.reverse_z=(Int16)p.as_bool();
          centerData.write_center_para();
        }
      }
      return result;
    }
  );

  RCLCPP_INFO(this->get_logger(), "Ininitialized successfully");
}

LineCenterReconstruction::~LineCenterReconstruction()
{
  try {
//  _handle.reset();
    _thread.join();
    _sub.reset();
    _param_camera_get.reset();
    _sub_task100_199.reset();
    _points_con.notify_all();
    _task100_199_con.notify_all();
    _futures_con.notify_one();
    _task100_199_futures_con.notify_all();
    for (auto & t : _threads) {
      t.join();
    }
    for (auto & t : _task100_199_threads) {
      t.join();
    }
    _pub.reset();
    _pub_task100_199.reset();
    

    RCLCPP_INFO(this->get_logger(), "Destroyed successfully");
  } catch (const std::exception & e) {
    RCLCPP_ERROR(this->get_logger(), "Exception in destructor: %s", e.what());
  } catch (...) {
    RCLCPP_ERROR(this->get_logger(), "Exception in destructor: unknown");
  }
}
/*
int _set_homography_matrix(std::vector<double> homography_matrix)
{
    if(homography_matrix.size()!=9)
    {
      return 1;
    }
    return 0;
}
*/

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

      if(picwidth!=PIC_IMAGE_WIDTH||picheight!=PIC_IMAGE_HEIGHT)
      {
         auto _homo = cv::Mat(pm.homography_matrix, true).reshape(1, 3);
         std::vector<cv::Point2f> points_top(4);
         std::vector<cv::Point2f> corners_trans;
         points_top[0] = cv::Point2f(0,0);
         points_top[1] = cv::Point2f(PIC_IMAGE_WIDTH-1,0);
         points_top[2] = cv::Point2f(0,PIC_IMAGE_HEIGHT-1);
         points_top[3] = cv::Point2f(PIC_IMAGE_WIDTH-1,PIC_IMAGE_HEIGHT-1);
         cv::perspectiveTransform( points_top, corners_trans, _homo);
         std::vector<cv::Point2f> points_trans(4);
         points_trans[0] = cv::Point2f(0,0);
         points_trans[1] = cv::Point2f(picwidth-1,0);
         points_trans[2] = cv::Point2f(0,picheight-1);
         points_trans[3] = cv::Point2f(picwidth-1,picheight-1);
         
         cv::Mat transform = getPerspectiveTransform(points_trans,corners_trans);
         transform.convertTo(transform,CV_64FC1);
         pm.homography_matrix=convertMat2Vector<double>(transform);
      }
      
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
    ctx = modbus_new_tcp(NULL, port);
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
    sleep(0);
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
    sleep(0);
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
    sleep(0);
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
      _task100_199_futures_con.wait(lk);
    }
    sleep(0);
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
  _task100_199_futures_con.notify_one();
}

void LineCenterReconstruction::callbackGlobalParam(std::shared_future<std::vector<rclcpp::Parameter>> future)
{
    auto result = future.get();
    if(result.size()>=2)
    {
      picheight = result.at(0).as_int();
      picwidth = result.at(1).as_int();
      RCLCPP_INFO(this->get_logger(), "picwidth percent: %d", picwidth);
      RCLCPP_INFO(this->get_logger(), "picheight percent: %d", picheight);
    }
    else
    {
      RCLCPP_ERROR(this->get_logger(), "Get camer info error.");
    }
}


}  // namespace line_center_reconstruction

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(line_center_reconstruction::LineCenterReconstruction)
