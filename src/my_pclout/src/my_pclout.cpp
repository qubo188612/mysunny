#include "my_pclout/my_pclout.hpp"
#include <cstdio>


template<typename _Tp>
std::vector<_Tp> convertMat2Vector(cv::Mat &mat)
{
	return (std::vector<_Tp>)(mat.reshape(1, 1));//通道数不变，按行转为一行
}

namespace my_pclout
{

volatile int b_fuzhi;
volatile int b_updatafinish;
tutorial_interfaces::msg::IfAlgorhmitrobpos robposmsg;

My_Pclout::My_Pclout(const rclcpp::NodeOptions & options)
: Node("my_pclout_node", options)
{
  b_modbusconnect=false;
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

  _thread = std::thread(&My_Pclout::_modbus, this, 1502);

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
        else if(p.get_name()=="craft_Id")//(工艺包号)
        {
          craft_Id=p.as_int();
        }
        else if(p.get_name()=="craft_als1")
        {
          craft_als1=p.as_int();
        }
        else if(p.get_name()=="craft_als2")
        {
          craft_als2=p.as_int();
        }
        else if(p.get_name()=="craft_als3")
        {
          craft_als3=p.as_int();
        }
        else if(p.get_name()=="craft_als4")
        {
          craft_als4=p.as_int();
        }
        else if(p.get_name()=="craft_als5")
        {
          craft_als5=p.as_int();
        }
        else if(p.get_name()=="craft_als6")
        {
          craft_als6=p.as_int();
        }
        else if(p.get_name()=="craft_als7")
        {
          craft_als7=p.as_int();
        }
        else if(p.get_name()=="craft_als8")
        {
          craft_als8=p.as_int();
        }
        else if(p.get_name()=="craft_als9")
        {
          craft_als9=p.as_int();
        }
        else if(p.get_name()=="craft_als10")
        {
          craft_als10=p.as_int();
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

void My_Pclout::_modbus(int port)
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

void My_Pclout::cloud_result_callback(const tutorial_interfaces::msg::IfAlgorhmitcloud msg)
{
  if(pData_En==true)
  {
    auto ptr = std::make_unique<IfAlgorhmitroblinecloud>();
    ptr->header=msg.header;
    ptr->solderjoints=msg.solderjoints;
    ptr->lasertrackoutcloud.resize(msg.lasertrackoutcloud.size());

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
          data_group.robotpos.X=robposmsg.posx;
          data_group.robotpos.Y=robposmsg.posy;
          data_group.robotpos.Z=robposmsg.posz;
          data_group.robotpos.RX=robposmsg.posrx;
          data_group.robotpos.RY=robposmsg.posry;
          data_group.robotpos.RZ=robposmsg.posrz;
          data_group.robotpos.nEn=1;
          ptr->lasertrackoutcloud[i].u=msg.lasertrackoutcloud[i].u;
          ptr->lasertrackoutcloud[i].v=msg.lasertrackoutcloud[i].v;
          ptr->lasertrackoutcloud[i].uy=msg.lasertrackoutcloud[i].x;
          ptr->lasertrackoutcloud[i].vz=msg.lasertrackoutcloud[i].y;
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
          ptr->lasertrackoutcloud[i].uy=msg.lasertrackoutcloud[i].x;
          ptr->lasertrackoutcloud[i].vz=msg.lasertrackoutcloud[i].y;
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
          data_group.robotpos.X=robposmsg.posx;
          data_group.robotpos.Y=robposmsg.posy;
          data_group.robotpos.Z=robposmsg.posz;
          data_group.robotpos.RX=robposmsg.posrx;
          data_group.robotpos.RY=robposmsg.posry;
          data_group.robotpos.RZ=robposmsg.posrz;
          data_group.robotpos.nEn=1;
          ptr->targetpointoutcloud[i].u=msg.targetpointoutcloud[i].u;
          ptr->targetpointoutcloud[i].v=msg.targetpointoutcloud[i].v;
          ptr->targetpointoutcloud[i].uy=msg.targetpointoutcloud[i].x;
          ptr->targetpointoutcloud[i].vz=msg.targetpointoutcloud[i].y;
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
          ptr->targetpointoutcloud[i].uy=msg.targetpointoutcloud[i].x;
          ptr->targetpointoutcloud[i].vz=msg.targetpointoutcloud[i].y;
          Calibration::hand_out_yes_eyetohand(eye,pData_demdlg_R,pData_demdlg_T,hand);
          ptr->targetpointoutcloud[i].x=hand.x();
          ptr->targetpointoutcloud[i].y=hand.y();
          ptr->targetpointoutcloud[i].z=hand.z();
          ptr->targetpointoutcloud[i].name=msg.targetpointoutcloud[i].name;
        }
      }
      break;
    }
    u_int16_t Y,m,d,H,M,S,ms;
    if(b_modbusconnect==true&&pData_En==true)
    {  
      TimeFunction time;
      time.get_time_ms(Y,m,d,H,M,S,ms);
      u_int16_t tab_reg[4];
      tab_reg[0]=H;
      tab_reg[1]=M;
      tab_reg[2]=S;
      tab_reg[3]=ms;
      int rc=modbus_write_registers(ctx,0x0d,4,tab_reg);
    }
    if (msg.targetpointoutcloud.size()==0) 
    {
      if(msg.header.frame_id!="-1"&&b_modbusconnect==true&&pData_En==true)
      {
        u_int16_t tab_reg[4];
        auto stamp = msg.header.stamp;
        time_t t;
        u_int16_t msec = msg.header.stamp.nanosec/1000000;
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
        int rc;
        rc=modbus_write_registers(ctx,0x07,5,tab_reg);
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
      if(b_modbusconnect==true&&pData_En==true)
      {
        int rc;
        u_int16_t tab_reg[1];
        tab_reg[0]=0;
        rc=modbus_write_registers(ctx,0x02,1,tab_reg);
        tab_reg[0]=-1;
        rc=modbus_write_registers(ctx,0x11,1,tab_reg);
      }
    }
    else
    {
      if(b_modbusconnect==true&&pData_En==true)
      {
        u_int16_t tab_reg[21];

        auto stamp = msg.header.stamp;
        time_t t;
        u_int16_t msec = msg.header.stamp.nanosec/1000000;
        struct tm *p;
        t=stamp.sec;
        p=gmtime(&t);  

        int rc;

        if(msg.targetpointoutcloud.size()>2)
        {
          int num=msg.targetpointoutcloud.size();
          auto othertab_reg=new u_int16_t [(num-2)*2];
          for(int i=2;i<num;i++)
          {
            othertab_reg[(i-2)*2]=(uint16_t)((int32_t)(msg.targetpointoutcloud[i].x*100+0.5));
            othertab_reg[(i-2)*2+1]=(uint16_t)((int32_t)(msg.targetpointoutcloud[i].y*100+0.5));
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

        if(msg.solderjoints==true)
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
        
        int i_data;
        i_data=ptr->targetpointoutcloud[0].x*1000;
        tab_reg[0]=((uint16_t*)(&i_data))[0];
        tab_reg[1]=((uint16_t*)(&i_data))[1];
        i_data=ptr->targetpointoutcloud[0].y*1000;
        tab_reg[2]=((uint16_t*)(&i_data))[0];
        tab_reg[3]=((uint16_t*)(&i_data))[1];
        i_data=ptr->targetpointoutcloud[0].z*1000;
        tab_reg[4]=((uint16_t*)(&i_data))[0];
        tab_reg[5]=((uint16_t*)(&i_data))[1];
        i_data=robposmsg.posrx*10000;
        tab_reg[6]=((uint16_t*)(&i_data))[0];
        tab_reg[7]=((uint16_t*)(&i_data))[1];
        i_data=robposmsg.posry*10000;
        tab_reg[8]=((uint16_t*)(&i_data))[0];
        tab_reg[9]=((uint16_t*)(&i_data))[1];
        i_data=robposmsg.posrz*10000;
        tab_reg[10]=((uint16_t*)(&i_data))[0];
        tab_reg[11]=((uint16_t*)(&i_data))[1];
        i_data=robposmsg.posout1;
        tab_reg[12]=((uint16_t*)(&i_data))[0];
        tab_reg[13]=((uint16_t*)(&i_data))[1];
        i_data=robposmsg.posout2;
        tab_reg[14]=((uint16_t*)(&i_data))[0];
        tab_reg[15]=((uint16_t*)(&i_data))[1];
        i_data=robposmsg.posout3;
        tab_reg[16]=((uint16_t*)(&i_data))[0];
        tab_reg[17]=((uint16_t*)(&i_data))[1];
        tab_reg[18]=(uint16_t)robposmsg.toolid;
        tab_reg[19]=(uint16_t)robposmsg.tcpid;
        tab_reg[20]=(uint16_t)robposmsg.usertcpid;

        rc=modbus_write_registers(ctx,0x12,21,tab_reg);
        if(rc!=21)
        {
          RCLCPP_ERROR(this->get_logger(), "modbus send result error 0x21=%d",rc);
        }
        
        tab_reg[0]=0xff;
        tab_reg[1]=(uint16_t)((int32_t)(msg.targetpointoutcloud[0].x*100+0.5));
        tab_reg[2]=(uint16_t)((int32_t)(msg.targetpointoutcloud[0].y*100+0.5));
        tab_reg[3]=(uint16_t)((int32_t)(msg.targetpointoutcloud[1].x*1000+0.5));
        tab_reg[4]=(uint16_t)((int32_t)(msg.targetpointoutcloud[1].y*1000+0.5));
        tab_reg[5]=(p->tm_hour+8)%24;
        tab_reg[6]=p->tm_min;
        tab_reg[7]=p->tm_sec;
        tab_reg[8]=msec;

        static bool b_oldtime=0;
        static struct timespec oldtime;
        struct timespec nowtime;
        struct timespec timerun = {0, 0};
        clock_gettime(CLOCK_REALTIME, &timerun);
        if(b_oldtime!=0)
        {
          nowtime=timerun;
          double fps=1.0/((nowtime.tv_sec-oldtime.tv_sec)+(nowtime.tv_nsec-oldtime.tv_nsec)/1000000000.0);
          tab_reg[9]=(u_int16_t)(fps*100.0);
          oldtime=nowtime;
        }
        else
        {
          b_oldtime=1;
          oldtime=timerun;
          tab_reg[9]=0;
        }

        rc=modbus_write_registers(ctx,0x02,10,tab_reg);
        if(rc!=10)
        {
          RCLCPP_ERROR(this->get_logger(), "modbus send result error 0x02=%d",rc);
        }

        tab_reg[0]=1;
        rc=modbus_write_registers(ctx,0x11,1,tab_reg);
        if(rc!=1)
        {
          RCLCPP_ERROR(this->get_logger(), "modbus send result error 0x11=%d",rc);
        }
      }
    }

    _pub_robline->publish(std::move(ptr));
  }
}

void My_Pclout::robpos_result_callback(const tutorial_interfaces::msg::IfAlgorhmitrobpos msg) 
{
    robposmsg=msg;
/*
    robposmsg.posx=-923.618;
    robposmsg.posy=87.828;
    robposmsg.posz=291.972;
    robposmsg.posrx=-107.061;
    robposmsg.posry=148.910;
    robposmsg.posrz=-19.502;
*/    
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
  this->declare_parameter("craft_Id",0);
  this->declare_parameter("craft_als1",0);
  this->declare_parameter("craft_als2",0);
  this->declare_parameter("craft_als3",0);
  this->declare_parameter("craft_als4",0);
  this->declare_parameter("craft_als5",0);
  this->declare_parameter("craft_als6",0);
  this->declare_parameter("craft_als7",0);
  this->declare_parameter("craft_als8",0);
  this->declare_parameter("craft_als9",0);
  this->declare_parameter("craft_als10",0);
}

void My_Pclout::_cloudresult()
{
    while(rclcpp::ok())
    {
/*
      Eigen::Vector3d p_hand;
      TCP_Leaserpos data_group;
      data_group.leaserpos.nEn=1;
      data_group.leaserpos.Y=51.35;
      data_group.leaserpos.Z=-4.69;
      data_group.robotpos.nEn=1;
      data_group.robotpos.X=-915.588;
      data_group.robotpos.Y=389.689;
      data_group.robotpos.Z=495.626;
      data_group.robotpos.RX=47.541;
      data_group.robotpos.RY=175.201;
      data_group.robotpos.RZ=146.622;
      Calibration::hand_on_yes_eyetohand(PData_cal_posture,data_group,pData_matrix_camera2plane,pData_matrix_plane2robot,p_hand);
      RCLCPP_INFO(this->get_logger(), "x=%f,y=%f,z=%f",p_hand.x(),p_hand.y(),p_hand.z());
*/
		   sleep(2); 
    }
}

}


#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(my_pclout::My_Pclout)