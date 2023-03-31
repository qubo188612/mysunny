#ifndef MY_PCLOUT_HPP_
#define MY_PCLOUT_HPP_

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/if_algorhmitcloud.hpp"

namespace my_pclout
{
using rcl_interfaces::msg::SetParametersResult;
using std::placeholders::_1;
using tutorial_interfaces::msg::IfAlgorhmitcloud;

class My_Pclout : public rclcpp::Node
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
    explicit My_Pclout(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

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
    virtual ~My_Pclout();

    OnSetParametersCallbackHandle::SharedPtr _handle;

private:

    const char * _sub_pclresult_name = "~/pclresult";
    
};

}

#endif