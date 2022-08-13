#ifndef LASER_LINE_IMAGEPOS__LASER_LINE_IMAGEPOS_HPP_
#define LASER_LINE_IMAGEPOS__LASER_LINE_IMAGEPOS_HPP_

#include <deque>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"

namespace laser_imagepos
{

using sensor_msgs::msg::Image;
using sensor_msgs::msg::PointCloud2;

const std::vector<std::string> KEYS = {"als100_threshold","task_num"};

/**
 * @brief To zip related parameters together.
 *
 */
struct Params
{
  int als100_threshold = 120;
  int task_num = 0;
};

struct Params_exposure
{
  u_int16_t _0_99_exposure;
  u_int16_t _200_299_exposure;
  u_int16_t _300_399_exposure;
};

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

  /**
   * @brief Publisher name.
   *
   */
  const char * _pub_name = "~/points";

  /**
   * @brief Shared pointer to publisher.
   *
   */
  rclcpp::Publisher<PointCloud2>::SharedPtr _pub;

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

  Params_exposure _get_nowexposure();

  Params_exposure ps;

  /**
   * @brief Update parameters from ROS.
   *
   * @return Params Zipped parameters
   */
  Params _update_parameters();

  Params pm;

  int _workers;

  void _worker();

  std::vector<std::thread> _threads;

  OnSetParametersCallbackHandle::SharedPtr _handle;

  std::mutex _images_mut;

  std::mutex _futures_mut;

  std::condition_variable _images_con;
  
  std::condition_variable _futures_con;

  void _push_back_image(Image::UniquePtr ptr);

  void _push_back_future(std::future<PointCloud2::UniquePtr> fut);

  std::deque<std::future<PointCloud2::UniquePtr>> _futures;

  std::deque<Image::UniquePtr> _images;

  int _0_99_exposure_time;

};

}

#endif