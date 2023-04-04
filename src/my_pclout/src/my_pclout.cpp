#include "my_pclout/my_pclout.hpp"
#include <cstdio>

tutorial_interfaces::msg::IfAlgorhmitcloud rcvmsg;    

template<typename _Tp>
std::vector<_Tp> convertMat2Vector(cv::Mat &mat)
{
	return (std::vector<_Tp>)(mat.reshape(1, 1));//通道数不变，按行转为一行
}

namespace my_pclout
{

volatile int b_fuzhi;
volatile int b_updatafinish;


My_Pclout::My_Pclout(const rclcpp::NodeOptions & options)
: Node("my_pclout_node", options)
{
  ptr_pcl_lineclould.reset(new pcl::PointCloud<pcl::PointXYZ>);
  ptr_pcl_deepclould.reset(new pcl::PointCloud<pcl::PointXYZ>);

  b_pclpush=false;

  b_fuzhi=0;
  b_updatafinish=0;

  _declare_parameters();

  subscription_cloud_result = this->create_subscription<tutorial_interfaces::msg::IfAlgorhmitcloud>(
        _sub_cloudresult_name, rclcpp::SensorDataQoS(), std::bind(&My_Pclout::cloud_result_callback, this, _1));

  subcription_pos_result = this->create_subscription<tutorial_interfaces::msg::IfAlgorhmitrobpos>(
        _sub_robposresult_name, rclcpp::SensorDataQoS(), std::bind(&My_Pclout::robpos_result_callback, this, _1));

  _pub_robline = this->create_publisher<IfAlgorhmitroblinecloud>(_pub_pcllineresult_name, rclcpp::SensorDataQoS());

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
        else if(p.get_name()=="b_pclpush")
        {
          b_pclpush=p.as_bool();
        }
        else if(p.get_name()=="clear_pcl")
        {
          if(p.as_bool()==true)
          {
            ptr_pcl_deepclould->clear();
          }
        }
        else if(p.get_name()=="save_pcl")
        {
          if(p.as_bool()==true)
          {
            MyPlcFunction pcl_f;
            pcl_f.save_pcldata_pclclould(ptr_pcl_deepclould);
          //pcl::visualization::CloudViewer viewer ("test");
          //viewer.showCloud(ptr_pcl_deepclould);
          }
        }
      }
      return result;
    }
  );   
}

My_Pclout::~My_Pclout()
{
  _cloudresulttcpthread.join();
    try {
    RCLCPP_INFO(this->get_logger(), "Destroyed successfully");
  } catch (const std::exception & e) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: %s", e.what());
  } catch (...) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: unknown");
  }
}

void My_Pclout::cloud_result_callback(const tutorial_interfaces::msg::IfAlgorhmitcloud msg)
{
    auto ptr = std::make_unique<IfAlgorhmitroblinecloud>();
    ptr->header=msg.header;
    ptr->solderjoints=msg.solderjoints;
    ptr->lasertrackoutcloud.resize(msg.lasertrackoutcloud.size());

    RobPos robotpos=rob;
    switch(PData_eye_hand_calibrationmode)
    {
      case HAND_IN_EYE:   //眼在手上
      {
        for(int i=0;i<ptr->lasertrackoutcloud.size();i++)
        {
          Eigen::Vector3d p_hand;
          TCP_Leaserpos data_group;
          data_group.leaserpos.nEn=1;
          data_group.leaserpos.Y=msg.lasertrackoutcloud[i].x;
          data_group.leaserpos.Z=msg.lasertrackoutcloud[i].y;
          data_group.robotpos=rob;
          ptr->lasertrackoutcloud[i].u=msg.lasertrackoutcloud[i].u;
          ptr->lasertrackoutcloud[i].v=msg.lasertrackoutcloud[i].v;
          Calibration::hand_on_yes_eyetohand(PData_cal_posture,data_group,pData_matrix_camera2plane,pData_matrix_plane2robot,p_hand);
          ptr->lasertrackoutcloud[i].x=p_hand.x();
          ptr->lasertrackoutcloud[i].y=p_hand.y();
          ptr->lasertrackoutcloud[i].z=p_hand.z();
        }
      }
      break;
      case HAND_OUT_EYE:     //眼在手外
      {
        for(int i=0;i<ptr->lasertrackoutcloud.size();i++)
        {
          Eigen::Vector3d eye,hand;
          eye.x()=0;
          eye.y()=msg.lasertrackoutcloud[i].x;
          eye.z()=msg.lasertrackoutcloud[i].y;
          ptr->lasertrackoutcloud[i].u=msg.lasertrackoutcloud[i].u;
          ptr->lasertrackoutcloud[i].v=msg.lasertrackoutcloud[i].v;
          Calibration::hand_out_yes_eyetohand(eye,pData_demdlg_R,pData_demdlg_T,hand);
          ptr->lasertrackoutcloud[i].x=hand.x();
          ptr->lasertrackoutcloud[i].y=hand.y();
          ptr->lasertrackoutcloud[i].z=hand.z();
        }
      }
      break;
    }
    ptr->targetpointoutcloud.resize(msg.targetpointoutcloud.size());
    switch(PData_eye_hand_calibrationmode)
    {
      case HAND_IN_EYE:   //眼在手上
      {
        for(int i=0;i<ptr->targetpointoutcloud.size();i++)
        {
          Eigen::Vector3d p_hand;
          TCP_Leaserpos data_group;
          data_group.leaserpos.nEn=1;
          data_group.leaserpos.Y=msg.targetpointoutcloud[i].x;
          data_group.leaserpos.Z=msg.targetpointoutcloud[i].y;
          data_group.robotpos=rob;
          ptr->targetpointoutcloud[i].u=msg.targetpointoutcloud[i].u;
          ptr->targetpointoutcloud[i].v=msg.targetpointoutcloud[i].v;
          Calibration::hand_on_yes_eyetohand(PData_cal_posture,data_group,pData_matrix_camera2plane,pData_matrix_plane2robot,p_hand);
          ptr->targetpointoutcloud[i].x=p_hand.x();
          ptr->targetpointoutcloud[i].y=p_hand.y();
          ptr->targetpointoutcloud[i].z=p_hand.z();
          ptr->targetpointoutcloud[i].name=msg.targetpointoutcloud[i].name;
        }
      }
      break;
      case HAND_OUT_EYE:     //眼在手外
      {
        for(int i=0;i<ptr->targetpointoutcloud.size();i++)
        {
          Eigen::Vector3d eye,hand;
          eye.x()=0;
          eye.y()=msg.targetpointoutcloud[i].x;
          eye.z()=msg.targetpointoutcloud[i].y;
          ptr->targetpointoutcloud[i].u=msg.targetpointoutcloud[i].u;
          ptr->targetpointoutcloud[i].v=msg.targetpointoutcloud[i].v;
          Calibration::hand_out_yes_eyetohand(eye,pData_demdlg_R,pData_demdlg_T,hand);
          ptr->targetpointoutcloud[i].x=hand.x();
          ptr->targetpointoutcloud[i].y=hand.y();
          ptr->targetpointoutcloud[i].z=hand.z();
          ptr->targetpointoutcloud[i].name=msg.targetpointoutcloud[i].name;
        }
      }
      break;
    }

    if(b_pclpush==true)
    {
      (*ptr_pcl_lineclould).clear();
      (*ptr_pcl_lineclould).reserve(ptr->lasertrackoutcloud.size());
      for(int i=0;i<ptr->lasertrackoutcloud.size();i++)
      {
        pcl::PointXYZ point;
        point.x=ptr->lasertrackoutcloud[i].x;
        point.y=ptr->lasertrackoutcloud[i].y;
        point.z=ptr->lasertrackoutcloud[i].z;
        (*ptr_pcl_lineclould).push_back(point);
      }
      (*ptr_pcl_lineclould).width = (int) (*ptr_pcl_lineclould).points.size ();
      (*ptr_pcl_lineclould).height = 1;

      (*ptr_pcl_deepclould)=(*ptr_pcl_deepclould)+(*ptr_pcl_lineclould);
    }

    _pub_robline->publish(std::move(ptr));
}

void My_Pclout::robpos_result_callback(const tutorial_interfaces::msg::IfAlgorhmitrobpos msg) 
{
    rob.X=msg.posx;
    rob.Y=msg.posy;
    rob.Z=msg.posz;
    rob.RX=msg.posrx;
    rob.RY=msg.posry;
    rob.RZ=msg.posrz;
    rob.nEn=1;
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
  this->declare_parameter("b_pclpush",b_pclpush);
  this->declare_parameter("clear_pcl",false);
  this->declare_parameter("save_pcl",false);
}

void My_Pclout::_cloudresult()
{
    while(rclcpp::ok())
    {
       
		   sleep(0); 
    }
}

}


#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(my_pclout::My_Pclout)