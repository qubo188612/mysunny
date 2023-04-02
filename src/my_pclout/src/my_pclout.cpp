#include "my_pclout/my_pclout.hpp"
#include <cstdio>

template<typename _Tp>
std::vector<_Tp> convertMat2Vector(cv::Mat &mat)
{
	return (std::vector<_Tp>)(mat.reshape(1, 1));//通道数不变，按行转为一行
}

namespace my_pclout
{

My_Pclout::My_Pclout(const rclcpp::NodeOptions & options)
: Node("my_pclout_node", options)
{
  _declare_parameters();

  subscription_cloud_result = this->create_subscription<tutorial_interfaces::msg::IfAlgorhmitcloud>(
        _sub_cloudresult_name, rclcpp::SensorDataQoS(), std::bind(&My_Pclout::cloud_result_callback, this, _1));

  _cloudresulttcpthread = std::thread(&My_Pclout::_cloudresult, this);

  _handle = this->add_on_set_parameters_callback(
    [this](const std::vector<rclcpp::Parameter> & parameters) {
      SetParametersResult result;
      result.successful = true;
      for (const auto & p : parameters) {
        if(p.get_name()=="pData_En")
        {
          pData_En = p.as_int();
        }
        else if(p.get_name()=="pData_demdlg_R")
        {
          int n=0;
          std::vector<double> d_data=p.as_double_array();
          for(int j=0;j<3;j++)
          {
            for(int i=0;i<3;i++)
            {
                pData_demdlg_R(j,i)=d_data[n++];
            }
          }
        }
        else if(p.get_name()=="pData_demdlg_T")
        {
          int n=0;
          std::vector<double> d_data=p.as_double_array();
          for(int i=0;i<3;i++)
          {
              pData_demdlg_T(i)=d_data[n++];
          }
        }
        else if(p.get_name()=="pData_matrix_camera2plane")
        {
          std::vector<double> d_data=p.as_double_array();
          pData_matrix_camera2plane = cv::Mat(d_data, true).reshape(1, 3);
        }
        else if(p.get_name()=="pData_matrix_plane2robot")
        {
          std::vector<double> d_data=p.as_double_array();
          pData_matrix_plane2robot = cv::Mat(d_data, true).reshape(1, 3);
        }
        else if(p.get_name()=="PData_cal_posture")
        {
          PData_cal_posture=(CAL_POSTURE)p.as_int();
        }
        else if(p.get_name()=="PData_eye_hand_calibrationmode")
        {
          PData_eye_hand_calibrationmode=(Eye_Hand_calibrationmode)p.as_int();
        }
      }
      return result;
    }
  );   
}

My_Pclout::~My_Pclout()
{
    try {
    RCLCPP_INFO(this->get_logger(), "Destroyed successfully");
  } catch (const std::exception & e) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: %s", e.what());
  } catch (...) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: unknown");
  }
}

void My_Pclout::cloud_result_callback(const tutorial_interfaces::msg::IfAlgorhmitcloud msg)  const
{

}

void My_Pclout::_declare_parameters()
{
  int n=0;

  pData_matrix_camera2plane=cv::Mat::zeros(3,3,CV_64F);
  pData_matrix_plane2robot=cv::Mat::zeros(3,3,CV_64F);  
  std::vector<double> temp_pData_demdlg_R(9);
  std::vector<double> temp_pData_demdlg_T(3);
  std::vector<double> temp_matrix_camera2plane=convertMat2Vector<double>(pData_matrix_camera2plane);
  std::vector<double> temp_matrix_plane2robot=convertMat2Vector<double>(pData_matrix_plane2robot);
  n=0;
  for(int j=0;j<3;j++)
  {
    for(int i=0;i<3;i++)
    {
        temp_pData_demdlg_R[n++]=pData_demdlg_R(j,i);
    }
  }
  n=0;
  for(int i=0;i<3;i++)
  {
      temp_pData_demdlg_T[n++]=pData_demdlg_T(i);
  }
  this->declare_parameter("pData_En", pData_En);
  this->declare_parameter("pData_demdlg_R", temp_pData_demdlg_R);
  this->declare_parameter("pData_demdlg_T", temp_pData_demdlg_T);
  this->declare_parameter("pData_matrix_camera2plane", temp_matrix_camera2plane);
  this->declare_parameter("pData_matrix_plane2robot", temp_matrix_plane2robot);
  this->declare_parameter("PData_cal_posture", (u_int16_t)PData_cal_posture);
  this->declare_parameter("PData_eye_hand_calibrationmode", (u_int16_t)PData_eye_hand_calibrationmode);
}

void My_Pclout::_cloudresult()
{
    while(rclcpp::ok())
    {
        
    }
}

}


#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(my_pclout::My_Pclout)