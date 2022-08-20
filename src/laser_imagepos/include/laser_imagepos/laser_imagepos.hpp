#ifndef LASER_LINE_IMAGEPOS__LASER_LINE_IMAGEPOS_HPP_
#define LASER_LINE_IMAGEPOS__LASER_LINE_IMAGEPOS_HPP_

#include <deque>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "tutorial_interfaces/msg/if_algorhmitmsg.hpp"
#include "myhalcv2/myhalcv2.h"
#include <cv_bridge/cv_bridge.h>

namespace laser_imagepos
{

using sensor_msgs::msg::Image;
using sensor_msgs::msg::PointCloud2;
using tutorial_interfaces::msg::IfAlgorhmitmsg;

const std::vector<std::string> KEYS = {"task_num","show_step","start"};

const std::vector<std::string> KEYS_ALS100 = {"als100_exposure_time",
                                              "als100_pingjun",
                                              "als100_b_yanmofuzhu",
                                              "als100_b_gudingquyu",
                                              "als100_widthliantongdis",
                                              "als100_highliantongdis",
                                              "als100_gujiaerzhi",
                                              "als100_jiguanghight",
                                              "als100_jiguanglong",
                                              "als100_jiguangkuandu",
                                              "als100_Updif",
                                              "als100_Updifmin",
                                              "als100_Uplong",
                                              "als100_Downdif",
                                              "als100_Downdifmin",
                                              "als100_Downdlong",
                                              "als100_duanxianerzhi",
                                              "als100_erzhisize",
                                              "als100_erzhisize2",
                                              "als100_searchdectancemax",
                                              "als100_searchdectancemin",
                                              "als100_dis_center_st",
                                              "als100_dis_center_ed"};

/**
 * @brief To zip related parameters together.
 *
 */
struct Params
{
/********************************/
//算法100参数
  int als100_exposure_time = 120;//曝光值
  int als100_pingjun = 15;  //二值阈值
  int als100_b_yanmofuzhu=1;//是否使用掩摸辅助
  int als100_b_gudingquyu=0;//是否固定区域
  int als100_widthliantongdis=2;//激光宽度连通距离
  int als100_highliantongdis=15;//激光长度连通距离
  int als100_gujiaerzhi=160;//找骨架二值图
  int als100_jiguanghight=50;//整体激光最短长度
  int als100_jiguanglong=20;//单边激光最短长度
  int als100_jiguangkuandu=4;//激光粗细
  int als100_Updif=0;//上半段倾斜开始斜度10
  int als100_Updifmin=-5;//上半段倾斜终止斜度10
  int als100_Uplong=5;//上半段直线长度
  int als100_Downdif=0;//下半段倾斜开始斜度0
  int als100_Downdifmin=5;//下半段倾斜终止斜度0
  int als100_Downdlong=5;//下半段直线长度
  int als100_duanxianerzhi=180;//找断线的二值阈值
  int als100_erzhisize=150;//断线二值图的上下阈值尺寸
  int als100_erzhisize2=60;//断线二值图的左右阈值尺寸
  int als100_searchdectancemax=160;//搜寻焊缝端点距离中央凹槽最远的距离
  int als100_searchdectancemin=25;//搜寻焊缝端点距离中央凹槽最近的距离
  int als100_dis_center_st=0;//距离中心点此处后开始统计
  int als100_dis_center_ed=500;  //距离中心点此处后停止统计
/************************************/
  int task_num = 0;
  int show_step = 0;      
};
/*
struct Params_exposure
{
  u_int16_t _0_99_exposure = 1000;
  u_int16_t _200_299_exposure = 0;
  u_int16_t _300_399_exposure = 0;
};
*/
class LaserImagePos : public rclcpp::Node
{
public:
  /**
   * @brief Construct a new Laser Line Center object.
   *
   * Initialize publisher.
   * Create an inner implementation.
   * Initialize subscription.
   * Print success if all done.
   * @param options Encapsulation of options for node initialization.
   */
  explicit LaserImagePos(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

  /**
   * @brief Destroy the Laser Line Center object.
   *
   * Release subscription.
   * Wake up all workers.
   * Wake up the manager.
   * Synchronize with all threads, wait for its return.
   * Release publisher.
   * Print success if all done.
   * Throw no exception.
   */
  virtual ~LaserImagePos();


private:

  /**
   * @brief Parameter client for camera.
   *
   */
  std::shared_ptr<rclcpp::AsyncParametersClient> _param_camera;

//  std::shared_ptr<rclcpp::SyncParametersClient> _param_camera_get;

  /**
   * @brief Publisher name.
   *
   */
  const char * _pub_name = "~/result";

  rclcpp::Publisher<IfAlgorhmitmsg>::SharedPtr _pub;


  /**
   * @brief Subscription name.
   *
   */
  const char * _sub_name = "~/image";

  /**
   * @brief Shared pointer to subscription.
   *
   */
  rclcpp::Subscription<Image>::SharedPtr _sub;

  /**
   * @brief Declare parameters with defaults before usage.
   *
   */
  void _declare_parameters();

  void alg100_declare_parameters();

//Params_exposure _get_nowexposure();

//Params_exposure ps;

  /**
   * @brief Update parameters from ROS.
   *
   * @return Params Zipped parameters
   */
  Params _update_parameters();

  void alg100_update_parameters();

  int alg100_getcallbackParameter(const rclcpp::Parameter &p);

  Params pm;

  int _workers;

  void _worker();

  void _manager();

  std::vector<std::thread> _threads;

  OnSetParametersCallbackHandle::SharedPtr _handle;

  std::mutex _images_mut;

  std::mutex _futures_mut;

  std::condition_variable _images_con;
  
  std::condition_variable _futures_con;

  void _push_back_image(Image::UniquePtr ptr);

  void _push_back_future(std::future<IfAlgorhmitmsg::UniquePtr> fut);

  std::deque<std::future<IfAlgorhmitmsg::UniquePtr>> _futures;

  std::deque<Image::UniquePtr> _images;

  int _0_99_exposure_time;

  IfAlgorhmitmsg::UniquePtr execute(Image::UniquePtr ptr, cv::Mat & buf, const Params & pm);

  std::string mat_type2encoding(int mat_type);

  void InitRunImage();//初始化算法
  //返回值1检测失败，0检测成功
  int RunImage(cv::Mat &imageIn,
               std::vector <cv::Point2f> &pointcloud,
               std::vector <cv::Point2f> &namepoint,
               bool &solderjoints,//是否焊点
               int step);   //输出结果点信息

  char *cv8uc1_Imagebuff_image;
  char *cv8uc1_Imagebuff1;
  char *cv8uc1_Imagebuff2;
  char *cv8uc1_Imagebuff3;
  char *cv8uc1_Imagebuff4;
  char *cv8uc1_Imagebuff5;
  char *cv8uc1_Imagebuff6;
  char *cv8uc1_Imagebuff7;
  char *cv8uc1_Imagebuff8;

  Int32 *X_line;
  float *f_line;
  Uint8 *X_lineMark;
  Int32 *X_linedif32,*niheX,*niheY;
  Myhalcv2::MyConect ImageConect,ImageConectlong,ImageConectlongPX,Imageheadline;
  Int32 firstsearch;
  Int32 firstsearch_stx,firstsearch_sty,firstsearch_edx,firstsearch_edy;

  int alg100_runimage(cv::Mat &cvimgIn,std::vector <cv::Point2f> &pointcloud,
                      std::vector <cv::Point2f> &namepoint,
                      bool &solderjoints,//是否焊点
                      int step);
};

}

#endif