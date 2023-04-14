#include <cstdio>

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
#include <modbus/modbus.hpp>
// #include <netinet/in.h>
// #include <sys/socket.h>
// #include <sys/socket.h>
// #include <errno.h>
#include <modbus.h>
// #include <stdio.h>
#include <unistd.h>
#include <fileout/FileOut.h>
#include <fileout/E2proomData.h>


// #include <climits>
#include <memory>
#include <set>

#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>

// #include <fstream>
// #include <string>
// #include <utility>
// #include <vector>
// #include <iostream>

static int oldparameter[PARAMETER_REGEDIST_NUM]={INT_MAX};
static int oldrobot[ROBOT_SET_REGEDIST_NUM]={INT_MAX};

long ZEGEstarttimems=0;

template<typename _Tp>
std::vector<_Tp> convertMat2Vector(cv::Mat &mat)
{
	return (std::vector<_Tp>)(mat.reshape(1, 1));//通道数不变，按行转为一行
}

long long pow1(int x,int y)
{
	long long num = 1;
	int i;
 
	for(i = 0; i < y; i++)
	{
		num = num*x;
	}
 
	return num;
}

int CM_Atof(char* source,double* doubleing)
{
	int offset1,offset2,n;
	double num;
	int signedflag;//+为1 -为0
 
	if(source == NULL || *source == 0 || doubleing == NULL)
	{
		return 0;
	}
 
	offset1 = 0;
	offset2 = 0;
	num = 0.0;
 
	while(*source > 0 && *source <= 32)//去除首部空格 \r \n \t \r 等异常字符
	{
		source++;
		offset1++;
	}
 
	signedflag = 1;//默认为+
	if(*source == '+')
	{
		signedflag = 1;
		source++;
		offset1++;
	}
	else if(*source == '-')
	{
		signedflag = 0;
		source++;
		offset1++;
	}
 
 
	//整数部分
	while(*source != '\0' && *source >= '0' && *source <= '9')
	{
		num = *source- '0' + num*10.0;
		source++;
		offset2++;
	}
 
	if(offset2 != 0 && *source == '.')
	{
		source++;
		offset2++;
 
		//小数部分
		n = 0;
		while(*source != '\0' && *source >= '0' && *source <= '9')
		{
			num = (*source- '0')*(1.0/pow1(10,++n)) + num;
			source++;
			offset2++;
		}
	}
 
	if(signedflag == 0)
	{
		num = -num;
	}
 
	if(offset2)
	{
		*doubleing = num;
		return offset1+offset2;
	}
	else
	{
		return 0;
	}
}

int CM_Atoi(char* source,int* integer)
{
	int offset1,offset2,num;
	int signedflag;//+为1 -为0
 
	if(source == NULL || *source == 0 ||integer == NULL)
	{
		return 0;
	}
 
	offset1 = 0;
	offset2 = 0;
	num = 0;
 
	while(*source > 0 && *source <= 32)//去除首部空格 \r \n \t \r 等异常字符
	{
		source++;
		offset1++;
	}
 
	signedflag = 1;//默认为+
	if(*source == '+')
	{
		signedflag = 1;
		source++;
		offset1++;
	}
	else if(*source == '-')
	{
		signedflag = 0;
		source++;
		offset1++;
	}
 
	while(*source != '\0' && *source >= '0' && *source <= '9')
	{
		num = *source- '0' + num*10;
		source++;
		offset2++;
	}
 
	if(signedflag == 0)
	{
		num = -num;
	}
 
	if(offset2)
	{
		*integer = num;
		return offset1+offset2;
	}
	else
	{
		return 0;
	}
}

namespace modbus
{
using rcl_interfaces::msg::SetParametersResult;
//tcp sock
TCPServer jsontcp;
TCPServer2 ftptcp;
std::mutex Modbus::mt;

std::string to_string_with_precision(float val, int fixed)
{
    auto str = std::to_string(val);
    return str.substr(0, str.find(".") + fixed + 1);
}

Modbus::Modbus(const rclcpp::NodeOptions & options)
: Node("modbus_node", options)
{
  int n=0;
  sleep(5);
  _param_camera = std::make_shared<rclcpp::AsyncParametersClient>(this, "camera_tis_node");
  _param_camera_get = std::make_shared<rclcpp::AsyncParametersClient>(this, "camera_tis_node");
  _param_gpio = std::make_shared<rclcpp::AsyncParametersClient>(this, "gpio_raspberry_node");
  _param_linecenter = std::make_shared<rclcpp::AsyncParametersClient>(this, "laser_line_center_node");
  _param_linecenter_set = std::make_shared<rclcpp::AsyncParametersClient>(this, "line_center_reconstruction_node");
  _param_linecenter_get = std::make_shared<rclcpp::AsyncParametersClient>(this, "line_center_reconstruction_node");
  _param_laserimagepos = std::make_shared<rclcpp::AsyncParametersClient>(this, "laser_imagepos_node");
  _param_pclout_set = std::make_shared<rclcpp::AsyncParametersClient>(this, "my_pclout_node");

  _pub_robpos = this->create_publisher<IfAlgorhmitrobpos>(_pub_robpos_name, rclcpp::SensorDataQoS());

  b_tcpsockershow=false;
  this->declare_parameter("b_tcpsockershow",false);

  this->declare_parameter("b_tcpforwardmappingshow",false);

  this->declare_parameter("printPdatanum",1000);

  b_resultreset=false;
  this->declare_parameter("b_resultreset",false);

  this->declare_parameter("robotsetport", 1501);    //机器人型号设置及通信端口
  auto robotsetport = this->get_parameter("robotsetport").as_int();

  this->declare_parameter("robot_mod", e2proomdata.robot_mod);

  robot_mapping=modbus_mapping_new(0, 0, ROBOT_SET_REGEDIST_NUM, 0);
  if (!robot_mapping) {
    RCLCPP_ERROR(this->get_logger(), "Failed to initialize modbusrobot registers.");
    rclcpp::shutdown();
    return;
  }
  robot_mapping->tab_registers[ROBOT_MOD_REG_ADD]=(u_int16_t)e2proomdata.robot_mod;
  robot_mapping->tab_registers[ROBOT_PORT_REG_ADD]=(u_int16_t)e2proomdata.robot_port;
  robot_mapping->tab_registers[ROBOT_IPADDRESS_1_REG_ADD]=(u_int16_t)e2proomdata.robot_ip1;
  robot_mapping->tab_registers[ROBOT_IPADDRESS_2_REG_ADD]=(u_int16_t)e2proomdata.robot_ip2;
  robot_mapping->tab_registers[ROBOT_IPADDRESS_3_REG_ADD]=(u_int16_t)e2proomdata.robot_ip3;
  robot_mapping->tab_registers[ROBOT_IPADDRESS_4_REG_ADD]=(u_int16_t)e2proomdata.robot_ip4;

/**********************************/
//P变量ROS2节点
  std::vector<double> pData_demdlg_R(9);
  std::vector<double> pData_demdlg_T(3);
  std::vector<double> matrix_camera2plane=convertMat2Vector<double>(e2proomdata.matrix_camera2plane);
  std::vector<double> matrix_plane2robot=convertMat2Vector<double>(e2proomdata.matrix_plane2robot);
  _param_pclout_set->set_parameters({rclcpp::Parameter("pData_En", e2proomdata.P_data_En)});
  _param_pclout_set->set_parameters({rclcpp::Parameter("pData_matrix_camera2plane", matrix_camera2plane)});
  _param_pclout_set->set_parameters({rclcpp::Parameter("pData_matrix_plane2robot", matrix_plane2robot)});
  n=0;
  for(int j=0;j<3;j++)
  {
    for(int i=0;i<3;i++)
    {
        pData_demdlg_R[n++]=e2proomdata.demdlg_R(j,i);
    }
  }
  _param_pclout_set->set_parameters({rclcpp::Parameter("pData_demdlg_R", pData_demdlg_R)}); 
  n=0;
  for(int i=0;i<3;i++)
  {
      pData_demdlg_T[n++]=e2proomdata.demdlg_T(i);
  }
  _param_pclout_set->set_parameters({rclcpp::Parameter("pData_demdlg_T", pData_demdlg_T)});
  _param_pclout_set->set_parameters({rclcpp::Parameter("PData_cal_posture", (u_int16_t)e2proomdata.P_data_cal_posture)});
  _param_pclout_set->set_parameters({rclcpp::Parameter("PData_eye_hand_calibrationmode", (u_int16_t)e2proomdata.P_data_eye_hand_calibrationmode)});
/*************************************/

  robot_mapping->tab_registers[P_DATA_EN_REG_ADD]=(u_int16_t)e2proomdata.P_data_En;
  robot_mapping->tab_registers[P_DATA_CAL_POSTURE_REG_ADD]=(u_int16_t)e2proomdata.P_data_cal_posture;
  robot_mapping->tab_registers[P_DATA_EYE_HAND_CALIBRATIONMODE_REG_ADD]=(u_int16_t)e2proomdata.P_data_eye_hand_calibrationmode;
  
  _param_linecenter_get->wait_for_service();
  auto linecenter_future = _param_linecenter_get->get_parameters(
                {"compensation_dx","compensation_dy","compensation_dz","reverse_y","reverse_z","homography_matrix"},
                std::bind(&Modbus::callbackCenterParam, this, std::placeholders::_1));

  _param_event_sub = _param_linecenter_get->on_parameter_event(std::bind(&Modbus::on_parameter_event_callback, this, std::placeholders::_1));


  RCLCPP_INFO(this->get_logger(), "zero_pointX: %d", e2proomdata.zero_pointX);
  RCLCPP_INFO(this->get_logger(), "zero_pointY: %d", e2proomdata.zero_pointY);
  RCLCPP_INFO(this->get_logger(), "zero_pointZ: %d", e2proomdata.zero_pointZ);

  camer_width=PIC_IMAGE_HEIGHT; //这里用相机翻转前的尺寸
  camer_height=PIC_IMAGE_WIDTH; //这里用相机翻转前的尺寸
  camer_fps=30;
  camer_view_width=3072;
  camer_view_height=2048;

  _param_camera_get->wait_for_service();
  auto parameters_future = _param_camera_get->get_parameters(
                {"width","height","fps","view_width","view_height"},
                std::bind(&Modbus::callbackGlobalParam, this, std::placeholders::_1));

  b_laser=false;
  b_camera=false;
  b_search=false;
  b_weld=false;
             
  ctx_robot = modbus_new_tcp(NULL, robotsetport);
  if (!ctx_robot) {
    RCLCPP_ERROR(this->get_logger(), "Failed to create modbusrobot context.");
    rclcpp::shutdown();
    return;
  }
  _thread_robotset = std::thread(&Modbus::_modbusrobotset, this, robotsetport);

  this->declare_parameter("parameterport", 1500);   //框架2参数设置端口
  auto parameterport = this->get_parameter("parameterport").as_int();
  
  int port;
  this->declare_parameter("port", 1502);  //modbustcp协议端口
  port = this->get_parameter("port").as_int(); 

  int robot_port;
  this->declare_parameter("robot_port", e2proomdata.robot_port);  //modbustcp协议端口
  robot_port = this->get_parameter("robot_port").as_int(); 

  int ftp_port;
  this->declare_parameter("ftp_port", 1476);  //ftp协议端口
  ftp_port = this->get_parameter("ftp_port").as_int(); 

//当前几个任务号
  for(int i=0;i<e2proomdata.taskfilename.size();i++)
  {
    RCLCPP_INFO(this->get_logger(), "taskfile: %d", e2proomdata.taskfilename[i].taskname);
    RCLCPP_INFO(this->get_logger(), "alg: %d", e2proomdata.taskfilename[i].alsnum);
  }
  RCLCPP_INFO(this->get_logger(), "taskfilenum: %d", e2proomdata.taskfilename.size());

  parameterport_mapping=modbus_mapping_new(0, 0, PARAMETER_REGEDIST_NUM, 0);
  if (!parameterport_mapping) {
    RCLCPP_ERROR(this->get_logger(), "Failed to initialize modbusparameter registers.");
    rclcpp::shutdown();
    return;
  }

  init_als100_parameter();
  init_als101_parameter();
  init_als102_parameter();
  init_als103_parameter();
  init_als104_parameter();
  init_als105_parameter();
  init_als106_parameter();
  init_als107_parameter();
  init_als108_parameter();
  
  for(int i=0;i<PARAMETER_REGEDIST_NUM;i++)
  {
    oldparameter[i]=parameterport_mapping->tab_registers[i];
    _task_parameter(i,parameterport_mapping->tab_registers[i]);
  }

  for(int i=0;i<ROBOT_SET_REGEDIST_NUM;i++)
  {
    oldrobot[i]=INT_MAX;
  }

  ctx_parameterport = modbus_new_tcp(NULL, parameterport);
  if (!ctx_parameterport) {
    RCLCPP_ERROR(this->get_logger(), "Failed to create modbusparameter context.");
    rclcpp::shutdown();
    return;
  }
  _thread_parameterport = std::thread(&Modbus::_modbusparameterport, this, parameterport);

  mb_mapping = modbus_mapping_new(0, 0, SERVER_REGEDIST_NUM, 0);
  if (!mb_mapping) {
    RCLCPP_ERROR(this->get_logger(), "Failed to initialize modbus registers.");
    rclcpp::shutdown();
    return;
  }

  close_pstate();

  mb_mapping->tab_registers[1] = 0xff;
  mb_mapping->tab_registers[0x102] = (u_int16_t)e2proomdata.task_num;
  mb_mapping->tab_registers[0x12a] = 1000;//跟踪p变量
  _task_numberset(e2proomdata.task_num);
  RCLCPP_INFO(this->get_logger(), "task=%d",e2proomdata.task_num);

  mb_forwardmapping = modbus_mapping_new(0, 0, SERVER_REGEDIST_NUM, 0);
  if (!mb_forwardmapping) {
    RCLCPP_ERROR(this->get_logger(), "Failed to initialize modbusforward registers.");
    rclcpp::shutdown();
    return;
  }

  ctx = modbus_new_tcp(NULL, port);
  if (!ctx) {
    RCLCPP_ERROR(this->get_logger(), "Failed to create modbus context.");
    rclcpp::shutdown();
    return;
  }
  _thread = std::thread(&Modbus::_modbus, this, port);

  num_ftpclient=0;
  _ftpthread = std::thread(&Modbus::_ftp, this, ftp_port);


  b_threadforward=false;
  b_jsontcpthread=false;
  b_clienttcpthread=false;
  b_sendentrecv=false;
  b_sendent=false;
  b_client=false;
  switch(e2proomdata.robot_mod)
  {
  case E2POOM_ROBOT_MOD_NULL:
  break;
  case E2POOM_ROBOT_MOD_ZHICHANG:       //Modbus
  case E2POOM_ROBOT_MOD_MOKA_NABOTE:    
  case E2POOM_ROBOT_MOD_MOKA:
  case E2POOM_ROBOT_MOD_ZEGE_2:
  case E2POOM_ROBOT_MOD_HUACHENG:
      ctx_forward = modbus_new_tcp(NULL, robot_port);
      if (!ctx_forward) {
        RCLCPP_ERROR(this->get_logger(), "Failed to create modbusforward context.");
        rclcpp::shutdown();
        return;
      }
      _threadforward = std::thread(&Modbus::_modbusforward, this, robot_port);
      b_threadforward = true;
      break;
  case E2POOM_ROBOT_MOD_ZHICHANG_KAWASAKI:    //TCP服务器
  case E2POOM_ROBOT_MOD_GANGSHANG:    
  case E2POOM_ROBOT_MOD_EFORT:    
  case E2POOM_ROBOT_MOD_STEP: 
      num_client=0;
      _jsontcpthread = std::thread(&Modbus::_json, this, robot_port);
      b_jsontcpthread = true;
      break;
  case E2POOM_ROBOT_MOD_ZHICHANG_KAWASAKI_AS: //TCP客户端
      _clienttcpthread = std::thread(&Modbus::_client, this);
      b_clienttcpthread=true;
  break;
  default:
      break;
  }

  _handle = this->add_on_set_parameters_callback(
    [this](const std::vector<rclcpp::Parameter> & parameters) {
      SetParametersResult result;
      result.successful = true;
      for (const auto & p : parameters) {
        if (p.get_name() == "b_tcpsockershow") {
            b_tcpsockershow=p.as_bool();
            return result;
        } 
        else if(p.get_name() == "b_resultreset") {
            b_resultreset=p.as_bool();
            return result;
        }
        else if (p.get_name() == "printPdatanum") {
            bool b_findID=false;
            int printPdatanum=p.as_int();
            for(int i=0;i<e2proomdata.P_data.size();i++)
            {
              if(e2proomdata.P_data[i].pID==printPdatanum)
              {
                b_findID=true;
                for(int j=0;j<e2proomdata.P_data[i].pos.size();j++)
                {
                  RCLCPP_INFO(this->get_logger(), "P%d:x=%0.3f",j,j<e2proomdata.P_data[i].pos[j].x);
                  RCLCPP_INFO(this->get_logger(), "P%d:y=%0.3f",j,j<e2proomdata.P_data[i].pos[j].y);
                  RCLCPP_INFO(this->get_logger(), "P%d:z=%0.3f",j,j<e2proomdata.P_data[i].pos[j].z);
                  RCLCPP_INFO(this->get_logger(), "P%d:rx=%0.3f",j,j<e2proomdata.P_data[i].pos[j].rx);
                  RCLCPP_INFO(this->get_logger(), "P%d:ry=%0.3f",j,j<e2proomdata.P_data[i].pos[j].ry);
                  RCLCPP_INFO(this->get_logger(), "P%d:rz=%0.3f",j,j<e2proomdata.P_data[i].pos[j].rz);
                  RCLCPP_INFO(this->get_logger(), "P%d:out1=%d",j,j<e2proomdata.P_data[i].pos[j].out1);
                  RCLCPP_INFO(this->get_logger(), "P%d:out2=%d",j,j<e2proomdata.P_data[i].pos[j].out2);
                  RCLCPP_INFO(this->get_logger(), "P%d:out3=%d",j,j<e2proomdata.P_data[i].pos[j].out3);
                  RCLCPP_INFO(this->get_logger(), "P%d:tool=%d",j,j<e2proomdata.P_data[i].pos[j].tool);
                  RCLCPP_INFO(this->get_logger(), "P%d:tcp=%d",j,j<e2proomdata.P_data[i].pos[j].tcp);
                  RCLCPP_INFO(this->get_logger(), "P%d:usertcp=%d",j,j<e2proomdata.P_data[i].pos[j].usertcp);
                  RCLCPP_INFO(this->get_logger(), "P%d:uy=%d",j,j<e2proomdata.P_data[i].pos[j].uy);
                  RCLCPP_INFO(this->get_logger(), "P%d:vz=%d",j,j<e2proomdata.P_data[i].pos[j].vz);
                }
              }
            }
            if(b_findID==false)
            {
              RCLCPP_INFO(this->get_logger(), "P变量当前没有为%d的点",printPdatanum);
            }
            return result;
        }
        else if (p.get_name() == "b_tcpforwardmappingshow") {
            bool b_tcpforwardmappingshow=p.as_bool();
            if(b_tcpforwardmappingshow==TRUE)
            {
              b_tcpforwardmappingshow=FALSE;
              switch(e2proomdata.robot_mod)
              {
                case E2POOM_ROBOT_MOD_ZHICHANG:
                {
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x00=%d 版本号",(int16_t)mb_forwardmapping->tab_registers[0x00]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x01=%d 延迟,单位是毫秒(当前时间-数据采集时间)",(int16_t)mb_forwardmapping->tab_registers[0x01]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x02=%#x 搜索状态(0xFF表示找到,0表示找不到)",(int16_t)mb_forwardmapping->tab_registers[0x02]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x03=%0.2f 焊缝y坐标,(point1)",(float)((int16_t)mb_forwardmapping->tab_registers[0x03]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x04=%0.2f 焊缝z坐标,(point1)",(float)((int16_t)mb_forwardmapping->tab_registers[0x04]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x05=%0.3f 焊缝法线y分量,(point1)",(float)((int16_t)mb_forwardmapping->tab_registers[0x05]/1000.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x06=%0.3f 焊缝法线z分量,(point1)",(float)((int16_t)mb_forwardmapping->tab_registers[0x06]/1000.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x07=%d 时(数据帧采集时间)",(int16_t)mb_forwardmapping->tab_registers[0x07]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x08=%d 分(数据帧采集时间)",(int16_t)mb_forwardmapping->tab_registers[0x08]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x09=%d 秒(数据帧采集时间)",(int16_t)mb_forwardmapping->tab_registers[0x09]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x0a=%d 毫秒(数据帧采集时间)",(int16_t)mb_forwardmapping->tab_registers[0x0a]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x0b=%0.2f 数据帧率",(float)((int16_t)mb_forwardmapping->tab_registers[0x0b]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x0c=%0.2f 相机帧率",(float)((int16_t)mb_forwardmapping->tab_registers[0x0c]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x0d=%d 时(当前时间)",(int16_t)mb_forwardmapping->tab_registers[0x0d]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x0e=%d 分(当前时间)",(int16_t)mb_forwardmapping->tab_registers[0x0e]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x0f=%d 秒(当前时间)",(int16_t)mb_forwardmapping->tab_registers[0x0f]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x10=%d 毫秒(当前时间)",(int16_t)mb_forwardmapping->tab_registers[0x10]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x11=%d 传感器状态,0表示正在处理,1表示成功,-1表示失败",(int16_t)mb_forwardmapping->tab_registers[0x11]);
                  RCLCPP_INFO(this->get_logger(), "");
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x50=%0.2f 焊缝y坐标,(point2)",(float)((int16_t)mb_forwardmapping->tab_registers[0x50]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x51=%0.2f 焊缝z坐标,(point2)",(float)((int16_t)mb_forwardmapping->tab_registers[0x51]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x52=%0.2f 焊缝y坐标,(point3)",(float)((int16_t)mb_forwardmapping->tab_registers[0x52]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x53=%0.2f 焊缝z坐标,(point3)",(float)((int16_t)mb_forwardmapping->tab_registers[0x53]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x54=%0.2f 焊缝y坐标,(point4)",(float)((int16_t)mb_forwardmapping->tab_registers[0x54]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x55=%0.2f 焊缝z坐标,(point4)",(float)((int16_t)mb_forwardmapping->tab_registers[0x55]/100.0));
                  RCLCPP_INFO(this->get_logger(), "");
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x60=%#x 焊点(0xFF表示焊点,0表示非焊点)",(int16_t)mb_forwardmapping->tab_registers[0x60]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x61=%0.2f 焊缝宽",(float)((int16_t)mb_forwardmapping->tab_registers[0x61])/100.0);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x62=%0.2f 焊缝高",(float)((int16_t)mb_forwardmapping->tab_registers[0x62])/100.0);
                  RCLCPP_INFO(this->get_logger(), "");
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x70=%0.2f 焊缝x坐标",(float)((int16_t)mb_forwardmapping->tab_registers[0x70])/100.0);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x71=%0.3f 焊缝法线x分量",(float)((int16_t)mb_forwardmapping->tab_registers[0x71])/100.0);
                  RCLCPP_INFO(this->get_logger(), "");
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x101=%#x 打开激光、跟踪(0xFF),关闭激光、跟踪(0)",(int16_t)mb_forwardmapping->tab_registers[0x101]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x102=%d 任务号",(int16_t)mb_forwardmapping->tab_registers[0x102]);
                }
                break;
                case E2POOM_ROBOT_MOD_MOKA_NABOTE:
                {
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x00=%d 焊缝设置,1~999,焊缝配置编号",(int16_t)mb_forwardmapping->tab_registers[0x00]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x01=%d 激光控制,1:激光打开;0:激光关闭",(int16_t)mb_forwardmapping->tab_registers[0x01]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x02=%d 寻位控制,1:寻位开始;0:寻位结束",(int16_t)mb_forwardmapping->tab_registers[0x02]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x03=%d 跟踪控制,1:跟踪开始;0:跟踪结束",(int16_t)mb_forwardmapping->tab_registers[0x03]);
                  RCLCPP_INFO(this->get_logger(), "");
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x10=%d 检测结果,1:识别正常;0:识别失败",(int16_t)mb_forwardmapping->tab_registers[0x10]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x11=%0.2f 坐标值LX,激光平面坐标系下的X值,2D激光线默认为0",(float)((int16_t)mb_forwardmapping->tab_registers[0x11]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x12=%0.2f 坐标值LY,激光平面坐标系下的Y值",(float)((int16_t)mb_forwardmapping->tab_registers[0x12]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x13=%0.2f 坐标值LZ,激光平面坐标系下的Z值",(float)((int16_t)mb_forwardmapping->tab_registers[0x13]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x14=%0.3f 坐标值LA",(float)((int16_t)mb_forwardmapping->tab_registers[0x14]/1000.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x15=%0.3f 坐标值LB",(float)((int16_t)mb_forwardmapping->tab_registers[0x15]/1000.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x16=%0.3f 坐标值LC",(float)((int16_t)mb_forwardmapping->tab_registers[0x16]/1000.0));
                  RCLCPP_INFO(this->get_logger(), "");
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x20=%d 时",(int16_t)mb_forwardmapping->tab_registers[0x20]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x21=%d 分",(int16_t)mb_forwardmapping->tab_registers[0x21]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x22=%d 秒",(int16_t)mb_forwardmapping->tab_registers[0x22]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x23=%d 毫秒",(int16_t)mb_forwardmapping->tab_registers[0x23]);
                  RCLCPP_INFO(this->get_logger(), "");
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x30=%d 跟踪控制,校零",(int16_t)mb_forwardmapping->tab_registers[0x30]);
                }
                break;
                case E2POOM_ROBOT_MOD_MOKA:
                {
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x00=%d 版本号",(int16_t)mb_forwardmapping->tab_registers[0x00]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x01=%d 延迟,单位是毫秒(当前时间-数据采集时间)",(int16_t)mb_forwardmapping->tab_registers[0x01]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x02=%#x 搜索状态(0xFF表示找到,0表示找不到)",(int16_t)mb_forwardmapping->tab_registers[0x02]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x03=%0.2f 焊缝y坐标",(float)((int16_t)mb_forwardmapping->tab_registers[0x03]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x04=%0.2f 焊缝z坐标",(float)((int16_t)mb_forwardmapping->tab_registers[0x04]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x05=%0.2f 焊缝宽",(float)((int16_t)mb_forwardmapping->tab_registers[0x05])/100.0);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x06=%0.2f 焊缝高",(float)((int16_t)mb_forwardmapping->tab_registers[0x06])/100.0);
                  RCLCPP_INFO(this->get_logger(), "");
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x11=%d 状态寄存器(<0错误,=0忙,>0成功)",(int16_t)mb_forwardmapping->tab_registers[0x11]);
                }
                break;
                case E2POOM_ROBOT_MOD_ZEGE_2:
                {
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x00=%d 版本号",(int16_t)mb_forwardmapping->tab_registers[0x00]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x01=%d 延迟,单位是毫秒(当前时间-数据采集时间)",(int16_t)mb_forwardmapping->tab_registers[0x01]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x02=%#x 搜索状态(0xFF表示找到,0表示找不到)",(int16_t)mb_forwardmapping->tab_registers[0x02]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x03=%0.2f 焊缝y坐标",(float)((int16_t)mb_forwardmapping->tab_registers[0x03]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x04=%0.2f 焊缝z坐标",(float)((int16_t)mb_forwardmapping->tab_registers[0x04]/100.0));
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x05=%0.2f 焊缝宽",(float)((int16_t)mb_forwardmapping->tab_registers[0x05])/100.0);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x06=%0.2f 焊缝高",(float)((int16_t)mb_forwardmapping->tab_registers[0x06])/100.0);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x07-0x08=%d 当前系统时间戳,单位为毫秒,开机上电后为0,硬件累加",(((uint32_t)mb_forwardmapping->tab_registers[0x07])<<16)+(uint32_t)mb_forwardmapping->tab_registers[0x08]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x09-0x0a=%d 当前结果帧时间戳,单位为毫秒,由硬件累加",(((uint32_t)mb_forwardmapping->tab_registers[0x09])<<16)+(uint32_t)mb_forwardmapping->tab_registers[0x0a]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x0b=%d 状态寄存器,0表示正在处理,1表示成功,-1表示失败",(int16_t)mb_forwardmapping->tab_registers[0xb]);
                }
                break;
                case E2POOM_ROBOT_MOD_HUACHENG:
                {
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x00=%0.2f 焊缝的左右偏移",(float)((int16_t)mb_forwardmapping->tab_registers[0x00])/100.0);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x01=%0.2f 焊缝的高低偏移",(float)((int16_t)mb_forwardmapping->tab_registers[0x01])/100.0);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x02=%0.2f 焊缝宽度",(float)((int16_t)mb_forwardmapping->tab_registers[0x02])/100.0);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x03=%0.2f 焊缝深度",(float)((int16_t)mb_forwardmapping->tab_registers[0x03])/100.0);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x04=%#x 激光器的开关,0xff表示开,其他为关",(int16_t)mb_forwardmapping->tab_registers[0x04]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x05=%#x 焊缝跟踪器使能的开关,0xff表示开,其他为关",(int16_t)mb_forwardmapping->tab_registers[0x05]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x06=%d 焊缝多端模式选择(0-15)",(int16_t)mb_forwardmapping->tab_registers[0x06]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x07=%#x 焊缝校准功能0xff为校准焊缝,其他为清零",(int16_t)mb_forwardmapping->tab_registers[0x07]);
                  RCLCPP_INFO(this->get_logger(), "forwardmapping_0x08=%#x 焊缝对准信号0xff为对准,其他未对准",(int16_t)mb_forwardmapping->tab_registers[0x08]);
                }
                break;
              }
            }
            return result;
        } 
      }
      return result;
    }
  );

  RCLCPP_INFO(this->get_logger(), "Initialized successfully");
}

Modbus::~Modbus()
{
  try {
    _thread_robotset.join();
    _thread_parameterport.join();
    _thread.join();
    _ftpthread.join();
    if(b_jsontcpthread==true)
      _jsontcpthread.join();
    if(b_threadforward==true)
      _threadforward.join();
    if(b_clienttcpthread==true)
      _clienttcpthread.join();
    _param_gpio.reset();
    _param_camera.reset();
    _param_camera_get.reset();
    _param_linecenter.reset();
    _param_linecenter_set.reset();
    _param_linecenter_get.reset();
    _param_pclout_set.reset();
    _pub_robpos.reset();
//   _handle.reset();
    RCLCPP_INFO(this->get_logger(), "Destroyed successfully");
  } catch (const std::exception & e) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: %s", e.what());
  } catch (...) {
    RCLCPP_FATAL(this->get_logger(), "Exception in destructor: unknown");
  }
}

/**
 * @brief Control laser on of off.
 *
 * @param f true if on.
 */
void Modbus::_gpio_laser(bool f)
{
  if (f) {
    _param_gpio->set_parameters({rclcpp::Parameter("laser", true)});
    b_laser=true;
  } else {
    _param_gpio->set_parameters({rclcpp::Parameter("laser", false)});
    b_laser=false;
  }
}

void Modbus::callbackGlobalParam(std::shared_future<std::vector<rclcpp::Parameter>> future)
{
    auto result = future.get();
    if(result.size()>=5)
    {
      auto width = result.at(0);
      auto height = result.at(1);
      auto fps = result.at(2);
      auto view_width = result.at(3);
      auto view_height = result.at(4);
      RCLCPP_INFO(this->get_logger(), "width param: %d", width.as_int());
      RCLCPP_INFO(this->get_logger(), "height param: %d", height.as_int());
      RCLCPP_INFO(this->get_logger(), "fps param: %d", fps.as_int());
      RCLCPP_INFO(this->get_logger(), "view_width param: %d", view_width.as_int());
      RCLCPP_INFO(this->get_logger(), "view_height param: %d", view_height.as_int());

      robot_mapping->tab_registers[CAMER_SIZE_WIDTH_REG_ADD]=(u_int16_t)width.as_int();
      robot_mapping->tab_registers[CAMER_SIZE_HEIGHT_REG_ADD]=(u_int16_t)height.as_int();  
      robot_mapping->tab_registers[CAMER_FPS_REG_ADD]=(u_int16_t)fps.as_int();  
      robot_mapping->tab_registers[CAMER_SIZE_VIEW_WIDTH_REG_ADD]=(u_int16_t)view_width.as_int();  
      robot_mapping->tab_registers[CAMER_SIZE_VIEW_HEIGHT_REG_ADD]=(u_int16_t)view_height.as_int();  
    }
    else
    {
      RCLCPP_ERROR(this->get_logger(), "Get camer info error.");
    }
}

void Modbus::callbackCenterParam(std::shared_future<std::vector<rclcpp::Parameter>> future)
{
    auto result = future.get();
    if(result.size()>=6)
    {
      auto a_compensation_dx = result.at(0);
      auto a_compensation_dy = result.at(1);
      auto a_compensation_dz = result.at(2);
      auto a_reverse_y = result.at(3);
      auto a_reverse_z = result.at(4);
      auto a_homography_matrix = result.at(5);
      int compensation_dx=a_compensation_dx.as_int();
      int compensation_dy=a_compensation_dy.as_int();
      int compensation_dz=a_compensation_dz.as_int();
      int reverse_y=a_reverse_y.as_bool();
      int reverse_z=a_reverse_z.as_bool();
      std::vector<double> d_data=a_homography_matrix.as_double_array();
      RCLCPP_INFO(this->get_logger(), "compensation_dx param: %d", compensation_dx);
      RCLCPP_INFO(this->get_logger(), "compensation_dy param: %d", compensation_dy);
      RCLCPP_INFO(this->get_logger(), "compensation_dz param: %d", compensation_dz);
      RCLCPP_INFO(this->get_logger(), "reverse_y param: %d", reverse_y);
      RCLCPP_INFO(this->get_logger(), "reverse_z param: %d", reverse_z);
      RCLCPP_INFO(this->get_logger(), "homography_matrix[%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f,%.3f]",
      d_data[0],d_data[1],d_data[2],d_data[3],d_data[4],d_data[5],d_data[6],d_data[7],d_data[8]);

      robot_mapping->tab_registers[ALSROBOTCAM_COMPENSATION_X]=(u_int16_t)((int16_t)compensation_dx);
      robot_mapping->tab_registers[ALSROBOTCAM_COMPENSATION_Y]=(u_int16_t)((int16_t)compensation_dy);  
      robot_mapping->tab_registers[ALSROBOTCAM_REVERSE_Y_REG_ADD]=(u_int16_t)((int16_t)reverse_y);  
      robot_mapping->tab_registers[ALSROBOTCAM_REVERSE_Z_REG_ADD]=(u_int16_t)((int16_t)reverse_z);  
      homography_matrix=d_data;
    }
    else
    {
      RCLCPP_ERROR(this->get_logger(), "Get compensation info error.");
    }
}

void Modbus::on_parameter_event_callback(const rcl_interfaces::msg::ParameterEvent::SharedPtr event)
{
  std::lock_guard<std::mutex> l(mt);
  
  for (auto & changed_parameter : event->changed_parameters) {
    const auto & type = changed_parameter.value.type;
    const auto & name = changed_parameter.name;
    const auto & value = changed_parameter.value;

    if(name=="homography_matrix")
    {
      std::vector<double> d_data=value.double_array_value;
      homography_matrix=d_data;
    }

/*
    if (type == rcl_interfaces::msg::ParameterType::PARAMETER_DOUBLE) {
      // Trajectory
      if (name == "walk_distance") {
        walk_distance_ = value.double_value;
        RCLCPP_INFO(this->get_logger(), "update walk_distance: %.3f ", walk_distance_);
      }
    }
    else if(type == rcl_interfaces::msg::ParameterType::PARAMETER_INTEGER)
    {
      if (name == "execute_frequency") {
        execute_frequency_ = value.integer_value;//不会改变定时器执行频率，仅作为演示用
        RCLCPP_INFO(this->get_logger(), "update execute_frequency: %d ", execute_frequency_);
      }
    }
    else if (type == rcl_interfaces::msg::ParameterType::PARAMETER_BOOL)
    {
      if (name == "print_execute_duration") {
        print_execute_duration_ = value.bool_value;
        RCLCPP_INFO(this->get_logger(), "update print_execute_duration: %d ",print_execute_duration_);
      }
    }
    else if (type == rcl_interfaces::msg::ParameterType::PARAMETER_STRING)
    {
      if (name == "show_str") {
        show_str_ = value.string_value;
        RCLCPP_INFO(this->get_logger(), "update show_str: %s ",show_str_.c_str());
      }
    }
    */
  }
}

/*
void Modbus::_camera_get_size(int *width,int *height)
{
    const std::vector<std::string> KEYS = {"width","height"};
    _param_camera_get->wait_for_service();
    auto vp = _param_camera_get->get_parameters(KEYS);
    for (auto & p : vp)
    {
        if (p.get_name() == "width")
        {
            auto k = p.as_int();
            *width=k;
        }
        else if (p.get_name() == "height")
        {
            auto k = p.as_int();
            *height=k;
        }
    }
}
*/
void Modbus::_camera_set_size(int width,int height)
{
    _param_camera->set_parameters({rclcpp::Parameter("width", width)});
    _param_camera->set_parameters({rclcpp::Parameter("height", height)});
}
/**
 * @brief Control camera capture or not.
 *
 * @param f true if enable camera capture.
 */
void Modbus::_camera_power(bool f)
{
  if (f) {
    _param_camera->set_parameters({rclcpp::Parameter("power", true)});
    _param_laserimagepos->set_parameters({rclcpp::Parameter("start", 1)});
    b_camera=true;
  } else {
    _param_camera->set_parameters({rclcpp::Parameter("power", false)});
    b_camera=false;
  }
}

void Modbus::_task_numberset(u_int16_t num)
{
  u_int16_t num2=e2proomdata.loadtaskfile(num);
  switch (num2)
  {
  case 100:
    init_als100_parameter();
    break;
  case 101:
    init_als101_parameter();
    break;
  case 102:
    init_als102_parameter();
    break;
  case 103:
    init_als103_parameter();
    break;
  case 104:
    init_als104_parameter();
    break;
  case 105:
    init_als105_parameter();
    break;
  case 106:
    init_als106_parameter();
    break;
  case 107:
    init_als107_parameter();
    break;
  case 108:
    init_als108_parameter();
    break;
  default:
    break;
  }
  for(int i=0;i<PARAMETER_REGEDIST_NUM;i++)
  {
    if(oldparameter[i]!=parameterport_mapping->tab_registers[i])
    {
      oldparameter[i]=parameterport_mapping->tab_registers[i];
      _task_parameter(i,parameterport_mapping->tab_registers[i]);
    }
  }
  _param_linecenter->set_parameters({rclcpp::Parameter("task_num", num2)}); 
  _param_laserimagepos->set_parameters({rclcpp::Parameter("task_num", num2)}); 
  e2proomdata.task_num=num;
  e2proomdata.write_task_num_para();
}


void Modbus::_task_parameter(int ddr,u_int16_t num)
{
  switch(ddr)
  {
    case ALS_SHOW_STEP_REG_ADD:
      _param_laserimagepos->set_parameters({rclcpp::Parameter("show_step", num)});
      return;
    break;
  }
  if(0!=als100_task_parameter(ddr,num))
      return;
  if(0!=als101_task_parameter(ddr,num))
      return;
  if(0!=als102_task_parameter(ddr,num))
      return;
  if(0!=als103_task_parameter(ddr,num))
      return;
  if(0!=als104_task_parameter(ddr,num))
      return;
  if(0!=als105_task_parameter(ddr,num))
      return;
  if(0!=als106_task_parameter(ddr,num))
      return;
  if(0!=als107_task_parameter(ddr,num))
      return;
  if(0!=als108_task_parameter(ddr,num))
      return;
}

void Modbus::_task_robot(int ddr,u_int16_t num)
{
  switch(ddr)
  {
    case ROBOT_MOD_REG_ADD: 
      e2proomdata.robot_mod=num;
      this->set_parameters({rclcpp::Parameter("robot_mod", (u_int16_t)e2proomdata.robot_mod)});
    break;
    case ROBOT_PORT_REG_ADD:
      e2proomdata.robot_port=num;
      this->set_parameters({rclcpp::Parameter("robot_port", (u_int16_t)e2proomdata.robot_port)});
    break;
    case ALSROBOTCAM_COMPENSATION_X:
      _param_linecenter_set->set_parameters({rclcpp::Parameter("compensation_dx", (int16_t)num)});
    break;
    case ALSROBOTCAM_COMPENSATION_Y:
      _param_linecenter_set->set_parameters({rclcpp::Parameter("compensation_dy", (int16_t)num)});
    break;
    case ALSROBOTCAM_COMPENSATION_Z:
      _param_linecenter_set->set_parameters({rclcpp::Parameter("compensation_dz", (int16_t)num)});
    break;
    case CAMER_SIZE_WIDTH_REG_ADD:
      _param_camera->set_parameters({rclcpp::Parameter("width", num)});
    break;
    case CAMER_SIZE_HEIGHT_REG_ADD:
      _param_camera->set_parameters({rclcpp::Parameter("height", num)});
    break;
    case CAMER_FPS_REG_ADD:
      _param_camera->set_parameters({rclcpp::Parameter("fps", num)});
    break;
    case CAMER_SIZE_VIEW_WIDTH_REG_ADD:
      _param_camera->set_parameters({rclcpp::Parameter("view_width", num)});
    break;
    case CAMER_SIZE_VIEW_HEIGHT_REG_ADD:
      _param_camera->set_parameters({rclcpp::Parameter("view_height", num)});
    break;
    case ALSROBOTCAM_REVERSE_Y_REG_ADD:
      if(num!=0)
        _param_linecenter_set->set_parameters({rclcpp::Parameter("reverse_y", true)});
      else
        _param_linecenter_set->set_parameters({rclcpp::Parameter("reverse_y", false)});
    break;
    case ALSROBOTCAM_REVERSE_Z_REG_ADD:
      if(num!=0)
        _param_linecenter_set->set_parameters({rclcpp::Parameter("reverse_z", true)});
      else
        _param_linecenter_set->set_parameters({rclcpp::Parameter("reverse_z", false)});
    break;
    case P_DATA_EN_REG_ADD:
      e2proomdata.P_data_En=num;
      _param_pclout_set->set_parameters({rclcpp::Parameter("P_data_En", (u_int16_t)e2proomdata.P_data_En)});
    break;
    case P_DATA_CAL_POSTURE_REG_ADD:
      e2proomdata.P_data_cal_posture=(CAL_POSTURE)num;
      _param_pclout_set->set_parameters({rclcpp::Parameter("PData_cal_posture", (u_int16_t)e2proomdata.P_data_cal_posture)});
    break;
    case P_DATA_EYE_HAND_CALIBRATIONMODE_REG_ADD:
      e2proomdata.P_data_eye_hand_calibrationmode=(Eye_Hand_calibrationmode)num;
      _param_pclout_set->set_parameters({rclcpp::Parameter("PData_eye_hand_calibrationmode", (u_int16_t)e2proomdata.P_data_eye_hand_calibrationmode)});
    break;
    case ROBOT_IPADDRESS_1_REG_ADD:
      e2proomdata.robot_ip1=num;
    break;
    case ROBOT_IPADDRESS_2_REG_ADD:
      e2proomdata.robot_ip2=num;
    break;  
    case ROBOT_IPADDRESS_3_REG_ADD:
      e2proomdata.robot_ip3=num;
    break;
    case ROBOT_IPADDRESS_4_REG_ADD:
      e2proomdata.robot_ip4=num;
    break;
    default:
    break;
  }
}

void Modbus::close_pstate()
{
  b_calibration=false;
  b_toolcalibration=false;
  b_movedif=false;
  b_posevalue=false;
  b_circleweld=false;
  b_linemove=false;
  b_searchpoint=false;
}

void Modbus::getProb_pinfo(rob_pinfo *pos)
{
  uint16_t u16_data[2];
  int32_t *i32_data=(int32_t*)u16_data;

  u16_data[0]=mb_mapping->tab_registers[0x12b];
  u16_data[1]=mb_mapping->tab_registers[0x12c];
  (*pos).x=*i32_data/1000.0;
  u16_data[0]=mb_mapping->tab_registers[0x12d];
  u16_data[1]=mb_mapping->tab_registers[0x12e];
  (*pos).y=*i32_data/1000.0;
  u16_data[0]=mb_mapping->tab_registers[0x12f];
  u16_data[1]=mb_mapping->tab_registers[0x130];
  (*pos).z=*i32_data/1000.0;
  u16_data[0]=mb_mapping->tab_registers[0x131];
  u16_data[1]=mb_mapping->tab_registers[0x132];
  (*pos).rx=*i32_data/10000.0;
  u16_data[0]=mb_mapping->tab_registers[0x133];
  u16_data[1]=mb_mapping->tab_registers[0x134];
  (*pos).ry=*i32_data/10000.0;
  u16_data[0]=mb_mapping->tab_registers[0x135];
  u16_data[1]=mb_mapping->tab_registers[0x136];
  (*pos).rz=*i32_data/10000.0;
  u16_data[0]=mb_mapping->tab_registers[0x137];
  u16_data[1]=mb_mapping->tab_registers[0x138];
  (*pos).out1=*i32_data;
  u16_data[0]=mb_mapping->tab_registers[0x139];
  u16_data[1]=mb_mapping->tab_registers[0x13a];
  (*pos).out2=*i32_data;
  u16_data[0]=mb_mapping->tab_registers[0x13b];
  u16_data[1]=mb_mapping->tab_registers[0x13c];
  (*pos).out3=*i32_data;
  (*pos).tool=mb_mapping->tab_registers[0x13d];
  (*pos).tcp=mb_mapping->tab_registers[0x13e];
  (*pos).usertcp=mb_mapping->tab_registers[0x13f];
  (*pos).uy=((int16_t)mb_mapping->tab_registers[0x03])/100.0;
  (*pos).vz=((int16_t)mb_mapping->tab_registers[0x04])/100.0;
}

/**
 * @brief Construct a new impl object.
 *
 * Declare parameters before usage.
 * Establish a new TCP modbus via a specific port.
 * Listen to port.
 * Initialize a mapping block.
 * Start a thread to recursively accept and receive requests.
 * @param ptr Reference to parent node.
 */
void Modbus::_modbus(int port)
{
  // int aaa = 0;
  // auto nnn = std::chrono::system_clock::now();
  // std::vector<double> vvv;
  // vvv.resize(1800);
  auto sock = modbus_tcp_listen(ctx, 10);
  if (sock == -1) 
  {
    modbus_mapping_free(mb_mapping);
    modbus_free(ctx);
    RCLCPP_ERROR(this->get_logger(), "Failed to listen.");
    rclcpp::shutdown();
    return;
  }

  std::set<int> fds {sock};

  fd_set refset;
  FD_ZERO(&refset);
  FD_SET(sock, &refset);

  int fdmax = sock;
  uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
  int ret = 0;
  while (rclcpp::ok() && ret != -1) 
  {
    auto rdset = refset;
    timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    ret = select(fdmax + 1, &rdset, NULL, NULL, &tv);
    if (ret == -1) 
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to select.");
      continue;
    } 
    else if (ret == 0) 
    {
      // time out.
      continue;
    }

    auto fds_bak = fds;
    for (auto fd : fds_bak) 
    {
      if (!FD_ISSET(fd, &rdset)) 
        {continue;}

      if (fd == sock) 
      {
        
        ret = modbus_tcp_accept(ctx, &sock);
        if (ret != -1) 
        {
          FD_SET(ret, &refset);
          fds.insert(fds.end(), ret);
          fdmax = *fds.rbegin();
        } else 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to accept.");
          break;
        }
      } 
      else 
      {
        // A client is asking for reply
        ret = modbus_set_socket(ctx, fd);
        if (ret == -1) 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to set socket.");
          break;
        }
        ret = modbus_receive(ctx, query);
        if (ret == -1) 
        {
          // Connection closed by the client or error
          close(fd);
          FD_CLR(fd, &refset);
          fds.erase(fd);
          fdmax = *fds.rbegin();
          ret = 0;
        } 
        else if (ret > 0) 
        {
          if (ret > 14 && query[7] == 0x10 && query[8] == 0x01 && query[9] == 0x01) 
          {
            if (query[14]) 
            {
              _gpio_laser(true);
              _camera_power(true);
            } else 
            {
              _camera_power(false);
              _gpio_laser(false);
            }
          }
          int rc = modbus_reply(ctx, query, ret, mb_mapping);
          if (rc == -1) 
          {
            RCLCPP_ERROR(this->get_logger(), "Failed to reply.");
            continue;
          }
          static int oldtasknum=INT_MAX;
          if(oldtasknum!=mb_mapping->tab_registers[0x102])
          {
            oldtasknum=mb_mapping->tab_registers[0x102];
            _task_numberset(oldtasknum);
          }

          switch(e2proomdata.robot_mod)
          {
            case E2POOM_ROBOT_MOD_NULL:
            {
              if(b_resultreset==true)
              {
                if (query[7] == 0x03)
                {
                  uint16_t stadd=(((uint16_t)query[8])<<8)+(uint16_t)query[9];
                  uint16_t num=(((uint16_t)query[10])<<8)+(uint16_t)query[11];
                  if(stadd<=0x02&&stadd+num>0x02)//读了状态寄存器
                  {
                    mb_mapping->tab_registers[0x02]=0;
                  }
                }
              }
              if (query[7] == 0x03)
              {
                uint16_t stadd=(((uint16_t)query[8])<<8)+(uint16_t)query[9];
                uint16_t num=(((uint16_t)query[10])<<8)+(uint16_t)query[11];
                if(stadd<=0x11&&stadd+num>0x11)//读了状态寄存器
                {
                  mb_mapping->tab_registers[0x11]=0;
                }
              }
              if (query[7] == 0x06||query[7] == 0x10||query[7] == 0x17)//写了状态寄存器
              {
                  auto ptr = std::make_unique<IfAlgorhmitrobpos>();
                  static int frame = 0;
                  uint16_t u16_data[2];
                  int32_t *i32_data=(int32_t*)u16_data;

                  ptr->header.stamp = this->now();
                  ptr->header.frame_id = std::to_string(frame++);
                  u16_data[0]=mb_mapping->tab_registers[ALS_REALTIME_POSX_REG_ADD];
                  u16_data[1]=mb_mapping->tab_registers[ALS_REALTIME_POSX_REG_ADD+1];
                  ptr->posx=*i32_data/1000.0;
                  u16_data[0]=mb_mapping->tab_registers[ALS_REALTIME_POSY_REG_ADD];
                  u16_data[1]=mb_mapping->tab_registers[ALS_REALTIME_POSY_REG_ADD+1];
                  ptr->posy=*i32_data/1000.0;
                  u16_data[0]=mb_mapping->tab_registers[ALS_REALTIME_POSZ_REG_ADD];
                  u16_data[1]=mb_mapping->tab_registers[ALS_REALTIME_POSX_REG_ADD+1];
                  ptr->posz=*i32_data/1000.0;
                  u16_data[0]=mb_mapping->tab_registers[ALS_REALTIME_POSRX_REG_ADD];
                  u16_data[1]=mb_mapping->tab_registers[ALS_REALTIME_POSRX_REG_ADD+1];
                  ptr->posrx=*i32_data/10000.0;
                  u16_data[0]=mb_mapping->tab_registers[ALS_REALTIME_POSRY_REG_ADD];
                  u16_data[1]=mb_mapping->tab_registers[ALS_REALTIME_POSRY_REG_ADD+1];
                  ptr->posry=*i32_data/10000.0;
                  u16_data[0]=mb_mapping->tab_registers[ALS_REALTIME_POSRZ_REG_ADD];
                  u16_data[1]=mb_mapping->tab_registers[ALS_REALTIME_POSRZ_REG_ADD+1];
                  ptr->posrz=*i32_data/10000.0;
                  u16_data[0]=mb_mapping->tab_registers[ALS_REALTIME_POSOUT1_REG_ADD];
                  u16_data[1]=mb_mapping->tab_registers[ALS_REALTIME_POSOUT1_REG_ADD+1];
                  ptr->posout1=*i32_data;
                  u16_data[0]=mb_mapping->tab_registers[ALS_REALTIME_POSOUT2_REG_ADD];
                  u16_data[1]=mb_mapping->tab_registers[ALS_REALTIME_POSOUT2_REG_ADD+1];
                  ptr->posout2=*i32_data;
                  u16_data[0]=mb_mapping->tab_registers[ALS_REALTIME_POSOUT3_REG_ADD];
                  u16_data[1]=mb_mapping->tab_registers[ALS_REALTIME_POSOUT3_REG_ADD+1];
                  ptr->posout3=*i32_data;
                  ptr->toolid=mb_mapping->tab_registers[ALS_REALTIME_TOOL_REG_ADD];
                  ptr->tcpid=mb_mapping->tab_registers[ALS_REALTIME_TCP_REG_ADD];
                  ptr->usertcpid=mb_mapping->tab_registers[ALS_REALTIME_USERTCP_REG_ADD];
                  _pub_robpos->publish(std::move(ptr));
              }
              /******************************/
              if(e2proomdata.P_data_En==true)//P寄存器有效
              {
                //P变量
                bool b_Pchange=false;//是否写了P变量
                if (query[7] == 0x06)//写了状态寄存器
                {
                  uint16_t stadd=(((uint16_t)query[8])<<8)+(uint16_t)query[9];
                  if(stadd==0x12a)//写了状态寄存器
                  {
                    b_Pchange=true;
                  }
                }
                else if(query[7] == 0x10)//写了状态寄存器
                {
                  uint16_t stadd=(((uint16_t)query[8])<<8)+(uint16_t)query[9];
                  uint16_t num=(((uint16_t)query[10])<<8)+(uint16_t)query[11];
                  if(stadd<=0x12a&&stadd+num>0x12a)//写了状态寄存器
                  {
                    b_Pchange=true;
                  }
                }
                else if(query[7] == 0x17)//写了状态寄存器
                {
                  uint16_t stadd=(((uint16_t)query[12])<<8)+(uint16_t)query[13];
                  uint16_t num=(((uint16_t)query[14])<<8)+(uint16_t)query[15];
                  if(stadd<=0x12a&&stadd+num>0x12a)//写了状态寄存器
                  {
                    b_Pchange=true;
                  }
                }
                if(b_Pchange==true)//写了P变量
                {
                  if(mb_mapping->tab_registers[0x12a]==0)//开启标定
                  {
                    close_pstate();
                    b_calibration=true;

                    for(int i=0;i<e2proomdata.P_data.size();i++)
                    {
                      if(e2proomdata.P_data[i].pID==0)//找到P0点
                      {
                        pIDnum_calibration=i;
                        e2proomdata.P_data[pIDnum_calibration].pos.clear();
                      }
                    }
                  }
                  else if(mb_mapping->tab_registers[0x12a]==1)//工具坐标矩阵
                  {
                    close_pstate();
                    b_toolcalibration=true;
                  }
                  else if(mb_mapping->tab_registers[0x12a]==2)//偏移量
                  {
                    close_pstate();
                    b_movedif=true;
                  }
                  else if(mb_mapping->tab_registers[0x12a]==3)//姿态值
                  {
                    close_pstate();
                    b_posevalue=true;
                  }
                  else if(mb_mapping->tab_registers[0x12a]==11)//圆孔跟踪
                  {
                    close_pstate();
                    b_circleweld=true;
                  }
                  else if(mb_mapping->tab_registers[0x12a]==1000)//跟踪p变量
                  {
                    close_pstate();
                  }
                  else if(mb_mapping->tab_registers[0x12a]==1001)//直线走点
                  {
                    close_pstate();
                    b_linemove=true;
                  }
                  else if(mb_mapping->tab_registers[0x12a]==1002)//单点寻位
                  {
                    close_pstate();
                    b_searchpoint=true;
                  }
                  else//切换了其他p变量
                  {
                    close_pstate();
                  }
                }
                else
                {
                  /******************************/
                  //P变量点位内容
                  bool b_Pinfochange=false;//是否写了P变量点位内容
                  if (query[7] == 0x06)//写了状态寄存器
                  {
                    uint16_t stadd=(((uint16_t)query[8])<<8)+(uint16_t)query[9];
                    if(stadd>=0x12b&&stadd<=0x13f)//写了状态寄存器
                    {
                      b_Pinfochange=true;
                    }
                  }
                  else if(query[7] == 0x10)//写了状态寄存器
                  {
                    uint16_t stadd=(((uint16_t)query[8])<<8)+(uint16_t)query[9];
                    uint16_t num=(((uint16_t)query[10])<<8)+(uint16_t)query[11];
                    if(stadd>=0x12b&&stadd<=0x13f&&stadd+num>0x12b)//写了状态寄存器
                    {
                      b_Pinfochange=true;
                    }
                  }
                  else if(query[7] == 0x17)//写了状态寄存器
                  {
                    uint16_t stadd=(((uint16_t)query[12])<<8)+(uint16_t)query[13];
                    uint16_t num=(((uint16_t)query[14])<<8)+(uint16_t)query[15];
                    if(stadd>=0x12b&&stadd<=0x13f&&stadd+num>0x12b)//写了状态寄存器
                    {
                      b_Pinfochange=true;
                    }
                  }
                  if(b_Pinfochange==true)//写了P变量点位内容
                  {
                    if(b_calibration==true)
                    {
                      rob_pinfo pos;
                      getProb_pinfo(&pos);
                      e2proomdata.P_data[pIDnum_calibration].pos.push_back(pos);
                      e2proomdata.write_P_data_para();
                      switch(e2proomdata.P_data_cal_posture)
                      {
                        case HAND_IN_EYE://眼在手上
                        {
                          if(e2proomdata.P_data[pIDnum_calibration].pos.size()>=5)//大于等于5个点后做手眼标定
                          {
                            std::vector<double> errgroup;
                            double err;
                            
                            RobPos robotpos;
                            std::vector<TCP_Leaserpos> data_group(e2proomdata.P_data[pIDnum_calibration].pos.size()-1);

                            robotpos.X=e2proomdata.P_data[pIDnum_calibration].pos[0].x;
                            robotpos.Y=e2proomdata.P_data[pIDnum_calibration].pos[0].y;
                            robotpos.Z=e2proomdata.P_data[pIDnum_calibration].pos[0].z;
                            robotpos.RX=e2proomdata.P_data[pIDnum_calibration].pos[0].rx;
                            robotpos.RY=e2proomdata.P_data[pIDnum_calibration].pos[0].ry;
                            robotpos.RZ=e2proomdata.P_data[pIDnum_calibration].pos[0].rz;
                            robotpos.nEn=1;
                            
                            for(int i=0;i<data_group.size();i++)
                            {
                              data_group[i].robotpos.X=e2proomdata.P_data[pIDnum_calibration].pos[i+1].x;
                              data_group[i].robotpos.Y=e2proomdata.P_data[pIDnum_calibration].pos[i+1].y;
                              data_group[i].robotpos.Z=e2proomdata.P_data[pIDnum_calibration].pos[i+1].z;
                              data_group[i].robotpos.RX=e2proomdata.P_data[pIDnum_calibration].pos[i+1].rx;
                              data_group[i].robotpos.RY=e2proomdata.P_data[pIDnum_calibration].pos[i+1].ry;
                              data_group[i].robotpos.RZ=e2proomdata.P_data[pIDnum_calibration].pos[i+1].rz;
                              data_group[i].robotpos.nEn=1;
                              data_group[i].leaserpos.Y=e2proomdata.P_data[pIDnum_calibration].pos[i+1].uy;
                              data_group[i].leaserpos.Z=e2proomdata.P_data[pIDnum_calibration].pos[i+1].vz;
                              data_group[i].leaserpos.nEn=1;
                            }

                            if(true==Calibration::hand_on_yes_point2RT(e2proomdata.P_data_cal_posture,
                                                              robotpos,data_group,
                                                              e2proomdata.matrix_camera2plane,
                                                              e2proomdata.matrix_plane2robot,
                                                              err,errgroup))
                            {
                              std::vector<double> matrix_camera2plane=convertMat2Vector<double>(e2proomdata.matrix_camera2plane);
                              std::vector<double> matrix_plane2robot=convertMat2Vector<double>(e2proomdata.matrix_plane2robot);
                              _param_pclout_set->set_parameters({rclcpp::Parameter("pData_matrix_camera2plane", matrix_camera2plane)});
                              _param_pclout_set->set_parameters({rclcpp::Parameter("pData_matrix_plane2robot", matrix_plane2robot)});
                              RCLCPP_INFO(this->get_logger(),"标定矩阵生成成功,误差:%f",err);
                            }
                            else
                            {
                              RCLCPP_INFO(this->get_logger(),"标定计算出现问题,请检查数据");
                            }
                            e2proomdata.write_demdlg_para();
                          }
                          else
                          {
                            if(e2proomdata.P_data[pIDnum_calibration].pos.size()==1)
                            {
                              RCLCPP_INFO(this->get_logger(),"写入测量点P");
                            }
                            else
                            { 
                              RCLCPP_INFO(this->get_logger(),"写入激光标定点P");
                            }
                          }
                        }
                        break;
                        case HAND_OUT_EYE://眼在手外
                        {
                          if(e2proomdata.P_data[pIDnum_calibration].pos.size()>=8)//大于等于8个点后做手眼标定
                          {
                            std::vector<double> errgroup;
                            double err;
                            int data=e2proomdata.P_data[pIDnum_calibration].pos.size();
                            if((data%2)==0)//偶数
                            {
                              int posnum=data/2;
                              int leasernum=posnum;
                              std::vector<Eigen::Vector3d> cloudpoint;
                              std::vector<Eigen::Vector3d> robotpoint;
                              for(int n=0;n<posnum;n++)
                              {
                                  Eigen::Vector3d cloudsing;
                                  Eigen::Vector3d robotsing;
                                  cloudsing[0]=0;
                                  cloudsing[1]=e2proomdata.P_data[pIDnum_calibration].pos[n+posnum].uy;
                                  cloudsing[2]=e2proomdata.P_data[pIDnum_calibration].pos[n+posnum].vz;
                                  cloudpoint.push_back(cloudsing);
                                  robotsing[0]=e2proomdata.P_data[pIDnum_calibration].pos[n].x;
                                  robotsing[1]=e2proomdata.P_data[pIDnum_calibration].pos[n].y;
                                  robotsing[2]=e2proomdata.P_data[pIDnum_calibration].pos[n].z;
                                  robotpoint.push_back(robotsing);
                              }
                              if(true==Calibration::hand_out_yes_point2RT(cloudpoint,robotpoint,e2proomdata.demdlg_R,e2proomdata.demdlg_T,err,errgroup))
                              {
                                std::vector<double> pData_demdlg_R(9);
                                int n=0;
                                for(int j=0;j<3;j++)
                                {
                                  for(int i=0;i<3;i++)
                                  {
                                      pData_demdlg_R[n++]=e2proomdata.demdlg_R(j,i);
                                  }
                                }
                                _param_pclout_set->set_parameters({rclcpp::Parameter("pData_demdlg_R", pData_demdlg_R)});
                                std::vector<double> pData_demdlg_T(3);
                                n=0;
                                for(int i=0;i<3;i++)
                                {
                                    pData_demdlg_T[n++]=e2proomdata.demdlg_T(i);
                                }
                                _param_pclout_set->set_parameters({rclcpp::Parameter("pData_demdlg_T", pData_demdlg_T)});
                                RCLCPP_INFO(this->get_logger(),"标定矩阵生成成功,误差:%f",err);
                              }
                              else
                              {
                                RCLCPP_INFO(this->get_logger(),"标定计算出现问题,请检查数据");
                              }
                              e2proomdata.write_demdlg_para(); 
                            }
                            else
                            {
                              RCLCPP_INFO(this->get_logger(),"等待下一个输入点P");
                            }
                          }
                          else
                          {
                            RCLCPP_INFO(this->get_logger(),"输入的P点数量最小为8个");
                          }
                        }
                        break;
                      }
                    }
                    else if(b_toolcalibration==true)
                    {

                    }
                    else if(b_movedif==true)
                    {

                    }
                    else if(b_posevalue==true)
                    {

                    }
                    else if(b_circleweld==true)
                    {

                    }
                    else if(b_linemove==true)
                    {

                    }
                    else if(b_searchpoint==true)
                    {

                    }
                    else
                    {
                      uint16_t p=mb_mapping->tab_registers[0x12a];
                      if(p!=1000)//非跟踪p变量,添加其他P变量点
                      {
                        bool b_find=false;
                        int pID;
                        for(int i=0;i<e2proomdata.P_data.size();i++)
                        {
                          if(e2proomdata.P_data[i].pID==(int)p)
                          {
                            pID=i;
                            b_find=true;
                            break;
                          }
                        }
                        if(b_find==true)
                        {
                          e2proomdata.P_data[pID].pos.resize(1);
                          getProb_pinfo(&e2proomdata.P_data[pID].pos[0]);
                        }
                        else
                        {
                          rob_group singl;
                          singl.pID=p;
                          singl.pos.resize(1);
                          getProb_pinfo(&singl.pos[0]);
                          e2proomdata.P_data.push_back(singl);
                          e2proomdata.write_P_data_para();
                        }
                      }
                    }
                  }
                  /********************************/
                }
              }
            }
            break;
            case E2POOM_ROBOT_MOD_ZHICHANG:
            {
              for(int i=0;i<SERVER_REGEDIST_NUM;i++)
              {
                mb_forwardmapping->tab_registers[i]=mb_mapping->tab_registers[i];
              }
            }
            break;
            case E2POOM_ROBOT_MOD_MOKA_NABOTE:
            {
              mb_forwardmapping->tab_registers[0x0000]=mb_mapping->tab_registers[0x102];
              if(mb_mapping->tab_registers[0x02]==0xff)
                  mb_forwardmapping->tab_registers[0x0010]=1;
              else 
                  mb_forwardmapping->tab_registers[0x0010]=0;

              static int learnzeropoint=0;
              if(mb_forwardmapping->tab_registers[0x0030]!=1)
              {
                if(learnzeropoint!=0)
                {
                  learnzeropoint=0;
                  e2proomdata.write_zeropoint_para();
                }
                mb_forwardmapping->tab_registers[0x0011]=mb_mapping->tab_registers[0x70]-e2proomdata.zero_pointX;
                mb_forwardmapping->tab_registers[0x0012]=mb_mapping->tab_registers[0x03]-e2proomdata.zero_pointY;
                mb_forwardmapping->tab_registers[0x0013]=mb_mapping->tab_registers[0x04]-e2proomdata.zero_pointZ;
              }
              else
              {
                learnzeropoint=1;
                e2proomdata.zero_pointX=(int16_t)mb_mapping->tab_registers[0x70];
                e2proomdata.zero_pointY=(int16_t)mb_mapping->tab_registers[0x03];
                e2proomdata.zero_pointZ=(int16_t)mb_mapping->tab_registers[0x04];
                mb_forwardmapping->tab_registers[0x0011]=mb_mapping->tab_registers[0x70]-e2proomdata.zero_pointX;
                mb_forwardmapping->tab_registers[0x0012]=mb_mapping->tab_registers[0x03]-e2proomdata.zero_pointY;
                mb_forwardmapping->tab_registers[0x0013]=mb_mapping->tab_registers[0x04]-e2proomdata.zero_pointZ;
              }
              mb_forwardmapping->tab_registers[0x0014]=mb_mapping->tab_registers[0x71];
              mb_forwardmapping->tab_registers[0x0015]=mb_mapping->tab_registers[0x05];
              mb_forwardmapping->tab_registers[0x0016]=mb_mapping->tab_registers[0x06];
            }
            break; 
            case E2POOM_ROBOT_MOD_MOKA:
            {
              for(int i=0;i<5;i++)
              {
                mb_forwardmapping->tab_registers[i]=mb_mapping->tab_registers[i];
              }
              mb_forwardmapping->tab_registers[0x005]=mb_mapping->tab_registers[0x61];
              mb_forwardmapping->tab_registers[0x006]=mb_mapping->tab_registers[0x62];
              if(mb_mapping->tab_registers[0x02]==0xff)
              {
                mb_forwardmapping->tab_registers[0x011]=1;
              }
              else if(mb_mapping->tab_registers[0x02]==0)
              {
                mb_forwardmapping->tab_registers[0x011]=(uint16_t)-1;
              }
              mb_forwardmapping->tab_registers[0x102]=mb_mapping->tab_registers[0x102];  
            }
            break;
            case E2POOM_ROBOT_MOD_ZEGE_2:
            {
              mb_forwardmapping->tab_registers[0x000]=6;
              for(int i=1;i<5;i++)
              {
                mb_forwardmapping->tab_registers[i]=mb_mapping->tab_registers[i];
              }
              mb_forwardmapping->tab_registers[0x005]=mb_mapping->tab_registers[0x61];
              mb_forwardmapping->tab_registers[0x006]=mb_mapping->tab_registers[0x62];
              static bool ZEGEstart=0;
              if(ZEGEstart==0&&mb_mapping->tab_registers[0x07]!=0&&mb_mapping->tab_registers[0x08]!=0&&mb_mapping->tab_registers[0x09]!=0&&mb_mapping->tab_registers[0xa]!=0)
              {
                ZEGEstart=1;
                ZEGEstarttimems=(long)(mb_mapping->tab_registers[0x0a])+
                                (long)(mb_mapping->tab_registers[0x09])*1000+
                                (long)(mb_mapping->tab_registers[0x08])*60*1000+
                                (long)(mb_mapping->tab_registers[0x07])*60*60*1000;
              }
              else
              {
                long  ZEGEresulttimems= (long)(mb_mapping->tab_registers[0x0a])+
                                        (long)(mb_mapping->tab_registers[0x09])*1000+
                                        (long)(mb_mapping->tab_registers[0x08])*60*1000+
                                        (long)(mb_mapping->tab_registers[0x07])*60*60*1000;
                long  ZEGEsystemtimems= (long)(mb_mapping->tab_registers[0x10])+
                                        (long)(mb_mapping->tab_registers[0x0f])*1000+
                                        (long)(mb_mapping->tab_registers[0x0e])*60*1000+
                                        (long)(mb_mapping->tab_registers[0x0d])*60*60*1000;
                int time2=ZEGEresulttimems-ZEGEstarttimems;
                int time1=ZEGEsystemtimems-ZEGEstarttimems;
                mb_forwardmapping->tab_registers[0x007]=(u_int16_t)(time1>>16);
                mb_forwardmapping->tab_registers[0x008]=(u_int16_t)(time1&0xffff);
                mb_forwardmapping->tab_registers[0x009]=(u_int16_t)(time2>>16);
                mb_forwardmapping->tab_registers[0x00a]=(u_int16_t)(time2&0xffff);

//              RCLCPP_INFO(this->get_logger(), "ZEGEresulttimems: %d", time2);
//              RCLCPP_INFO(this->get_logger(), "ZEGEsystemtimems: %d", time1);
              }
              if(mb_mapping->tab_registers[0x02]==0xff)
              {
                mb_forwardmapping->tab_registers[0x00b]=1;
              }
              else if(mb_mapping->tab_registers[0x02]==0)
              {
                mb_forwardmapping->tab_registers[0x00b]=(uint16_t)-1;
              }
            }
            break;
            case E2POOM_ROBOT_MOD_HUACHENG:
            {
                static int learnzeropoint=0;
                if(mb_forwardmapping->tab_registers[0x007]!=0xff)
                {
                  if(learnzeropoint!=0)
                  {
                    learnzeropoint=0;
                    e2proomdata.write_zeropoint_para();
                  }
                  mb_forwardmapping->tab_registers[0x000]=mb_mapping->tab_registers[0x03]-e2proomdata.zero_pointY;  
                  mb_forwardmapping->tab_registers[0x001]=mb_mapping->tab_registers[0x04]-e2proomdata.zero_pointZ;
                }
                else
                {
                  learnzeropoint=1;
                  e2proomdata.zero_pointY=(int16_t)mb_mapping->tab_registers[0x03];
                  e2proomdata.zero_pointZ=(int16_t)mb_mapping->tab_registers[0x04];
                  mb_forwardmapping->tab_registers[0x000]=mb_mapping->tab_registers[0x03]-e2proomdata.zero_pointY;  
                  mb_forwardmapping->tab_registers[0x001]=mb_mapping->tab_registers[0x04]-e2proomdata.zero_pointZ;
                }
                if(mb_mapping->tab_registers[0x02]==0xff)
                {
                  mb_forwardmapping->tab_registers[0x008]=0xff;
                }
                else if(mb_mapping->tab_registers[0x02]==0)
                {
                  mb_forwardmapping->tab_registers[0x008]=0;
                }
                mb_forwardmapping->tab_registers[0x002]=mb_mapping->tab_registers[0x61];
                mb_forwardmapping->tab_registers[0x003]=mb_mapping->tab_registers[0x62];
                if(b_laser==false)
                  mb_forwardmapping->tab_registers[0x004]=0;
                else
                  mb_forwardmapping->tab_registers[0x004]=0xff;
                if(b_camera==false)
                  mb_forwardmapping->tab_registers[0x005]=0;
                else
                  mb_forwardmapping->tab_registers[0x005]=0xff;
                mb_forwardmapping->tab_registers[0x006]=mb_mapping->tab_registers[0x102];
            }
            break;
            default:
            break;
          }

        }
      }
    }
  }

  close(sock);
  modbus_mapping_free(mb_mapping);
  modbus_free(ctx);
  if (ret == -1) 
  {
    rclcpp::shutdown();
  }
}

void Modbus::_modbusrobotset(int port)
{
  auto sock = modbus_tcp_listen(ctx_robot, 10);
  if (sock == -1) 
  {
    modbus_mapping_free(robot_mapping);
    modbus_free(ctx_robot);
    RCLCPP_ERROR(this->get_logger(), "Failed to listen.");
    rclcpp::shutdown();
    return;
  }

  std::set<int> fds {sock};

  fd_set refset;
  FD_ZERO(&refset);
  FD_SET(sock, &refset);

  int fdmax = sock;
  uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
  int ret = 0;
  while (rclcpp::ok() && ret != -1) 
  {
    auto rdset = refset;
    timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    ret = select(fdmax + 1, &rdset, NULL, NULL, &tv);
    if (ret == -1) 
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to select.");
      continue;
    } 
    else if (ret == 0) 
    {
      // time out.
      continue;
    }

    auto fds_bak = fds;
    for (auto fd : fds_bak) 
    {
      if (!FD_ISSET(fd, &rdset)) 
        {continue;}

      if (fd == sock) 
      {
        // A client is asking a new connection
        // struct sockaddr_in clientaddr;
        // socklen_t addrlen = sizeof(clientaddr);
        // memset(&clientaddr, 0, sizeof(clientaddr));
        // ret = accept(sock, (struct sockaddr *)&clientaddr, &addrlen);
        ret = modbus_tcp_accept(ctx_robot, &sock);
        if (ret != -1) 
        {
          FD_SET(ret, &refset);
          fds.insert(fds.end(), ret);
          fdmax = *fds.rbegin();
        } 
        else 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to accept.");
          break;
        }
      }
      else 
      {
        // A client is asking for reply
        ret = modbus_set_socket(ctx_robot, fd);
        if (ret == -1) 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to set socket.");
          break;
        }
        ret = modbus_receive(ctx_robot, query);
        if (ret == -1) 
        {
          // Connection closed by the client or error
          close(fd);
          FD_CLR(fd, &refset);
          fds.erase(fd);
          fdmax = *fds.rbegin();
          ret = 0;
        } 
        else if (ret > 0) 
        {
          int rc = modbus_reply(ctx_robot, query, ret, robot_mapping);
          if (rc == -1) 
          {
            RCLCPP_ERROR(this->get_logger(), "Failed to reply.");
            continue;
          }
          u_int8_t u8_temp=0;
          for(int i=0;i<ROBOT_SET_REGEDIST_NUM;i++)
          {
            if(oldrobot[i]!=robot_mapping->tab_registers[i])
            {
              oldrobot[i]=robot_mapping->tab_registers[i];
              u8_temp=1;
              _task_robot(i,oldrobot[i]);
            }
          }
          if(u8_temp==1)
          {
            e2proomdata.write_robot_para();
            e2proomdata.write_P_data_set_para();
          }
        }
      }
    }
  }

  close(sock);
  modbus_mapping_free(robot_mapping);
  modbus_free(ctx_robot);
  if (ret == -1) 
  {
    rclcpp::shutdown();
  }
  // std::ofstream ofile("/diff.txt");
  // for(auto d : vvv) {
  //   ofile << d << "\n";
  // }
  // ofile.close();
}

void Modbus::_modbusparameterport(int port)
{
  // int aaa = 0;
  // auto nnn = std::chrono::system_clock::now();
  // std::vector<double> vvv;
  // vvv.resize(1800);
  auto sock = modbus_tcp_listen(ctx_parameterport, 10);
  if (sock == -1) 
  {
    modbus_mapping_free(parameterport_mapping);
    modbus_free(ctx_parameterport);
    RCLCPP_ERROR(this->get_logger(), "Failed to listen.");
    rclcpp::shutdown();
    return;
  }

  std::set<int> fds {sock};

  fd_set refset;
  FD_ZERO(&refset);
  FD_SET(sock, &refset);

  int fdmax = sock;
  uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
  int ret = 0;
  while (rclcpp::ok() && ret != -1) 
  {
    auto rdset = refset;
    timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    ret = select(fdmax + 1, &rdset, NULL, NULL, &tv);
    if (ret == -1) 
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to select.");
      continue;
    } 
    else if (ret == 0) 
    {
      // time out.
      continue;
    }

    auto fds_bak = fds;
    for (auto fd : fds_bak) 
    {
      if (!FD_ISSET(fd, &rdset)) {continue;}

      if (fd == sock) 
      {
        // A client is asking a new connection
        // struct sockaddr_in clientaddr;
        // socklen_t addrlen = sizeof(clientaddr);
        // memset(&clientaddr, 0, sizeof(clientaddr));
        // ret = accept(sock, (struct sockaddr *)&clientaddr, &addrlen);
        ret = modbus_tcp_accept(ctx_parameterport, &sock);
        if (ret != -1) 
        {
          FD_SET(ret, &refset);
          fds.insert(fds.end(), ret);
          fdmax = *fds.rbegin();
        } 
        else 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to accept.");
          break;
        }
      } 
      else 
      {
        // A client is asking for reply
        ret = modbus_set_socket(ctx_parameterport, fd);
        if (ret == -1) 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to set socket.");
          break;
        }
        ret = modbus_receive(ctx_parameterport, query);
        if (ret == -1) 
        {
          // Connection closed by the client or error
          close(fd);
          FD_CLR(fd, &refset);
          fds.erase(fd);
          fdmax = *fds.rbegin();
          ret = 0;
        } 
        else if (ret > 0) 
        {
          int rc = modbus_reply(ctx_parameterport, query, ret, parameterport_mapping);
          if (rc == -1) 
          {
            RCLCPP_ERROR(this->get_logger(), "Failed to reply.");
            continue;
          }
          u_int8_t u8_temp=0;
          for(int i=0;i<PARAMETER_REGEDIST_NUM;i++)
          {
            if(oldparameter[i]!=parameterport_mapping->tab_registers[i])
            {
              oldparameter[i]=parameterport_mapping->tab_registers[i];
              u8_temp=1;
              _task_parameter(i,parameterport_mapping->tab_registers[i]);
            }
          }
          if(u8_temp==1)
          {
            e2proomdata.write();
          }   
        }
      }
    }
  }
  close(sock);
  modbus_mapping_free(parameterport_mapping);
  modbus_free(ctx_parameterport);
  if (ret == -1) {
    rclcpp::shutdown();
  }
  // std::ofstream ofile("/diff.txt");
  // for(auto d : vvv) {
  //   ofile << d << "\n";
  // }
  // ofile.close();
}

void Modbus::_modbusforward(int port)
{
 // int aaa = 0;
  // auto nnn = std::chrono::system_clock::now();
  // std::vector<double> vvv;
  // vvv.resize(1800);
  auto sock = modbus_tcp_listen(ctx_forward, 10);
  if (sock == -1) 
  {
    modbus_mapping_free(mb_forwardmapping);
    modbus_free(ctx_forward);
    RCLCPP_ERROR(this->get_logger(), "Failed to listen.");
    rclcpp::shutdown();
    return;
  }

  std::set<int> fds {sock};

  fd_set refset;
  FD_ZERO(&refset);
  FD_SET(sock, &refset);

  int fdmax = sock;
  uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
  int ret = 0;
  while (rclcpp::ok() && ret != -1) 
  {
    auto rdset = refset;
    timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 100000;
    ret = select(fdmax + 1, &rdset, NULL, NULL, &tv);
    if (ret == -1) 
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to select.");
      continue;
    } 
    else if (ret == 0) 
    {
      // time out.
      continue;
    }

    auto fds_bak = fds;
    for (auto fd : fds_bak) 
    {
      if (!FD_ISSET(fd, &rdset)) {continue;}

      if (fd == sock) 
      {
        
        ret = modbus_tcp_accept(ctx_forward, &sock);
        if (ret != -1) 
        {
          FD_SET(ret, &refset);
          fds.insert(fds.end(), ret);
          fdmax = *fds.rbegin();
        } 
        else 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to accept.");
          break;
        }
      } 
      else 
      {
        // A client is asking for reply
        ret = modbus_set_socket(ctx_forward, fd);
        if (ret == -1) 
        {
          RCLCPP_ERROR(this->get_logger(), "Failed to set socket.");
          break;
        }
        ret = modbus_receive(ctx_forward, query);
        if (ret == -1) 
        {
          // Connection closed by the client or error
          close(fd);
          FD_CLR(fd, &refset);
          fds.erase(fd);
          fdmax = *fds.rbegin();
          ret = 0;
        } 
        else if (ret > 0) 
        {
          int rc = modbus_reply(ctx_forward, query, ret, mb_forwardmapping);
          if (rc == -1) 
          {
            RCLCPP_ERROR(this->get_logger(), "Failed to reply.");
            continue;
          }
          switch(e2proomdata.robot_mod)
          {
            case E2POOM_ROBOT_MOD_NULL: 
            case E2POOM_ROBOT_MOD_ZHICHANG:
            {
              if (ret > 14 && query[7] == 0x10 && query[8] == 0x01 && query[9] == 0x01) {
                if (query[14]) {
                  _gpio_laser(true);
                  _camera_power(true);
                  mb_mapping->tab_registers[0x101]=mb_forwardmapping->tab_registers[0x101];
                } else {
                  _camera_power(false);
                  _gpio_laser(false);
                  mb_mapping->tab_registers[0x101]=mb_forwardmapping->tab_registers[0x101];
                }
              }
            
              static int oldtasknum=INT_MAX;
              if(oldtasknum!=mb_forwardmapping->tab_registers[0x102])
              {
                oldtasknum=mb_forwardmapping->tab_registers[0x102];
                mb_mapping->tab_registers[0x102]=oldtasknum;
                _task_numberset(oldtasknum);
              }
              if(b_resultreset==true)
              {
                if (query[7] == 0x03)
                {
                  uint16_t stadd=(((uint16_t)query[8])<<8)+(uint16_t)query[9];
                  uint16_t num=(((uint16_t)query[10])<<8)+(uint16_t)query[11];
                  if(stadd<=0x02&&stadd+num>0x02)//读了状态寄存器
                  {
                    mb_forwardmapping->tab_registers[0x02]=0;
                  }
                }
              }
              if (query[7] == 0x03)
              {
                uint16_t stadd=(((uint16_t)query[8])<<8)+(uint16_t)query[9];
                uint16_t num=(((uint16_t)query[10])<<8)+(uint16_t)query[11];
                if(stadd<=0x11&&stadd+num>0x11)//读了状态寄存器
                {
                  mb_forwardmapping->tab_registers[0x11]=0;
                }
              }
            }
            break;
            case E2POOM_ROBOT_MOD_MOKA_NABOTE:
            {
              static int oldtasknum=INT_MAX;
              if(oldtasknum!=mb_forwardmapping->tab_registers[0x000])
              {
                oldtasknum=mb_forwardmapping->tab_registers[0x000];
                mb_mapping->tab_registers[0x102]=oldtasknum;
                _task_numberset(oldtasknum);
              }

              static int oldgpio_laser=INT_MAX;
              if(oldgpio_laser!=mb_forwardmapping->tab_registers[0x001])
              {
                oldgpio_laser=mb_forwardmapping->tab_registers[0x001];
                if(oldgpio_laser==0x001)
                {
                  _gpio_laser(true);
                }
                else if(oldgpio_laser==0x000)
                {
                  _gpio_laser(false);
                }
              }

              static int oldcamera_power=INT_MAX;
              if(mb_forwardmapping->tab_registers[0x002]==1||mb_forwardmapping->tab_registers[0x003]==1)
              {
                if(oldcamera_power!=1)
                {
                  oldcamera_power=1;
                  _camera_power(true);
                }
              }
              else
              {
                if(oldcamera_power!=0)
                {
                  oldcamera_power=0;
                  _camera_power(false);
                }
              }
              if(b_resultreset==true)
              {
                if (query[7] == 0x03)
                {
                  uint16_t stadd=(((uint16_t)query[8])<<8)+(uint16_t)query[9];
                  uint16_t num=(((uint16_t)query[10])<<8)+(uint16_t)query[11];
                  if(stadd<=0x10&&stadd+num>0x10)//读了状态寄存器
                  {
                    mb_forwardmapping->tab_registers[0x10]=0;
                  }
                }
              }
            }
            break;
            case E2POOM_ROBOT_MOD_MOKA:
            {
              static int oldtasknum=INT_MAX;
              if(oldtasknum!=mb_forwardmapping->tab_registers[0x102])
              {
                oldtasknum=mb_forwardmapping->tab_registers[0x102];
                mb_mapping->tab_registers[0x102]=oldtasknum;
                _task_numberset(oldtasknum);
              }
              static int oldgpio_laser=INT_MAX;
              if(oldgpio_laser!=mb_forwardmapping->tab_registers[0x100])
              {
                oldgpio_laser=mb_forwardmapping->tab_registers[0x100];
                if(oldgpio_laser==0x0ff)
                {
                  _gpio_laser(true);
                }
                else if(oldgpio_laser==0x000)
                {
                  _gpio_laser(false);
                }
              }

              static int oldcamera_power=INT_MAX;
              if(oldcamera_power!=mb_forwardmapping->tab_registers[0x101])
              {
                oldcamera_power=mb_forwardmapping->tab_registers[0x101];
                if(oldcamera_power!=0xff)
                {
                  oldcamera_power=0xff;
                  _camera_power(true);
                }
                else if(oldcamera_power!=0)
                {
                  oldcamera_power=0;
                  _camera_power(false);
                }
              }
              if(b_resultreset==true)
              {
                if (query[7] == 0x03)
                {
                  uint16_t stadd=(((uint16_t)query[8])<<8)+(uint16_t)query[9];
                  uint16_t num=(((uint16_t)query[10])<<8)+(uint16_t)query[11];
                  if(stadd<=0x02&&stadd+num>0x02)//读了状态寄存器
                  {
                    mb_forwardmapping->tab_registers[0x02]=0;
                  }
                }
              }       
              if (query[7] == 0x03)
              {
                uint16_t stadd=(((uint16_t)query[8])<<8)+(uint16_t)query[9];
                uint16_t num=(((uint16_t)query[10])<<8)+(uint16_t)query[11];
                if(stadd<=0x11&&stadd+num>0x11)//读了状态寄存器
                {
                  mb_forwardmapping->tab_registers[0x11]=0;
                }
              }         
            }
            break;
            case E2POOM_ROBOT_MOD_ZEGE_2:
            {
              static int oldtasknum=INT_MAX;
              if(oldtasknum!=mb_forwardmapping->tab_registers[0x102])
              {
                oldtasknum=mb_forwardmapping->tab_registers[0x102];
                mb_mapping->tab_registers[0x102]=oldtasknum;
                _task_numberset(oldtasknum);
              }
              static int oldgpio_laser=INT_MAX;
              if(oldgpio_laser!=mb_forwardmapping->tab_registers[0x100])
              {
                oldgpio_laser=mb_forwardmapping->tab_registers[0x100];
                if(oldgpio_laser==0x0ff)
                {
                  _gpio_laser(true);
                }
                else if(oldgpio_laser==0x000)
                {
                  _gpio_laser(false);
                }
              }
              static int oldcamera_power=INT_MAX;
              if(oldcamera_power!=mb_forwardmapping->tab_registers[0x101])
              {
                oldcamera_power=mb_forwardmapping->tab_registers[0x101];
                if(oldcamera_power!=0xff)
                {
                  oldcamera_power=0xff;
                  _camera_power(true);
                }
                else if(oldcamera_power!=0)
                {
                  oldcamera_power=0;
                  _camera_power(false);
                }
              }

              if(b_resultreset==true)
              {
                if (query[7] == 0x03)
                {
                  uint16_t stadd=(((uint16_t)query[8])<<8)+(uint16_t)query[9];
                  uint16_t num=(((uint16_t)query[10])<<8)+(uint16_t)query[11];
                  if(stadd<=0x02&&stadd+num>0x02)//读了状态寄存器
                  {
                    mb_forwardmapping->tab_registers[0x02]=0;
                  }
                }
              }
              if (query[7] == 0x03)
              {
                uint16_t stadd=(((uint16_t)query[8])<<8)+(uint16_t)query[9];
                uint16_t num=(((uint16_t)query[10])<<8)+(uint16_t)query[11];
                if(stadd<=0x0b&&stadd+num>0x0b)//读了状态寄存器
                {
                  mb_forwardmapping->tab_registers[0x0b]=0;
                }
              }
            }
            break;
            case E2POOM_ROBOT_MOD_HUACHENG:
            {
              static int oldtasknum=INT_MAX;
              if(oldtasknum!=mb_forwardmapping->tab_registers[0x06])
              {
                oldtasknum=mb_forwardmapping->tab_registers[0x06];
                mb_mapping->tab_registers[0x102]=oldtasknum;
                _task_numberset(oldtasknum);
              }
              static int oldgpio_laser=INT_MAX;
              if(oldgpio_laser!=mb_forwardmapping->tab_registers[0x04])
              {
                oldgpio_laser=mb_forwardmapping->tab_registers[0x04];
                if(oldgpio_laser==0x0ff)
                {
                  _gpio_laser(true);
                }
                else if(oldgpio_laser==0x000)
                {
                  _gpio_laser(false);
                }
              }
              static int oldcamera_power=INT_MAX;
              if(oldcamera_power!=mb_forwardmapping->tab_registers[0x05])
              {
                oldcamera_power=mb_forwardmapping->tab_registers[0x05];
                if(oldcamera_power!=0xff)
                {
                  oldcamera_power=0xff;
                  _camera_power(true);
                }
                else if(oldcamera_power!=0)
                {
                  oldcamera_power=0;
                  _camera_power(false);
                }
              }
              static int search=INT_MAX;
              if(search!=mb_forwardmapping->tab_registers[0x07])
              {
                search=mb_forwardmapping->tab_registers[0x07];
                if(search!=0xff)
                {
                  search=0xff;
                  _camera_power(true);
                }
                else if(search!=0)
                {
                  search=0;
                  _camera_power(false);
                }
              }
              if(b_resultreset==true)
              {
                if (query[7] == 0x03)
                {
                  uint16_t stadd=(((uint16_t)query[8])<<8)+(uint16_t)query[9];
                  uint16_t num=(((uint16_t)query[10])<<8)+(uint16_t)query[11];
                  if(stadd<=0x08&&stadd+num>0x08)//读了状态寄存器
                  {
                    mb_forwardmapping->tab_registers[0x08]=0;
                  }
                }
              }
            }
            break;
            default:
            break;
          }
          
        }
      }
    }
  }

  close(sock);
  modbus_mapping_free(mb_forwardmapping);
  modbus_free(ctx_forward);
  if (ret == -1) {
    rclcpp::shutdown();
  }
  // std::ofstream ofile("/diff.txt");
  // for(auto d : vvv) {
  //   ofile << d << "\n";
  // }
  // ofile.close();
}

void Modbus::_ftp(int port)
{
    pthread_t msg;
    std::signal(SIGINT, closeftp_app);
    std::vector<int> opts = { SO_REUSEPORT, SO_REUSEADDR };
    if( ftptcp.setup(port,opts) != 0)
    {
          RCLCPP_ERROR(this->get_logger(), "Errore ftp socket.");
    }
    else
    {
        if( pthread_create(&msg, NULL, ftpreceived, this) == 0)
        {
            while(rclcpp::ok()) {
                ftptcp.accepted();
                cerr << "Ftp accepted" << endl;
            }
        }
    }
}

void closeftp_app(int s) 
{
    ftptcp.closed();
    rclcpp::shutdown();
}

void* ftpreceived(void *m)
{
    Modbus *_p=(Modbus*)m;
    pthread_detach(pthread_self());
    while(rclcpp::ok())
    {
        _p->ftpdesc = ftptcp.getMessage();
        for(unsigned int i = 0; i < _p->ftpdesc.size(); i++) 
        {
            if( _p->ftpdesc[i] )
            {
                std::vector<char> vec=_p->ftpdesc[i]->message;
                vec.push_back('\0');
                std::string str(vec.begin(), vec.end());

                if(_p->b_tcpsockershow==true)
                {
                cerr << "id:      " << _p->ftpdesc[i]->id      << endl
                    << "ip:      " << _p->ftpdesc[i]->ip      << endl
                    << "message: " << str << endl
                    << "socket:  " << _p->ftpdesc[i]->socket  << endl
                    << "enable:  " << _p->ftpdesc[i]->enable_message_runtime << endl;
                }
                Json::Value root;
                jsonfuction js;
                Json::Value sent_root;
                if(0==js.readJsonFromString(str,&root))
                {
                    Json::Value::Members mem = root.getMemberNames();
                    Json::Value::Members::iterator it = mem.begin(), end = mem.end();
                    for(; it != end; it ++)
                    {
                        if(*it=="ls")   
                        {
                            if(root[*it].asString()=="task")
                            {
                                for(int n=0;n<_p->e2proomdata.taskfilename.size();n++)
                                {
                                  Json::Value newIterm; 
                                  newIterm["taskname"]=_p->e2proomdata.taskfilename[n].taskname;
                                  newIterm["alsnum"]=_p->e2proomdata.taskfilename[n].alsnum;
                                  sent_root["ls"].append(newIterm);
                                }
                            }
                        }
                        else if(*it=="touch")
                        {
                            uint16_t taskname;
                            uint16_t alsnum;
                            Json::Value::Members objmem = root[*it].getMemberNames();
                            Json::Value::Members::iterator objit = objmem.begin(), objend = objmem.end();
                            for(; objit != objend; objit ++)
                            {
                                if(*objit=="taskname")   
                                {
                                  taskname=root[*it][*objit].asInt();  
                                }
                                else if(*objit=="alsnum")
                                {
                                  alsnum=root[*it][*objit].asInt(); 
                                }
                            }
                            _p->e2proomdata.savetaskfile(taskname,alsnum);
                            _p->e2proomdata.taskfilename.clear();
                            _p->e2proomdata.findtaskfile(&_p->e2proomdata.taskfilename);
                            sent_root["touch"]="ok";
                        }
                        else if(*it=="rm")
                        {
                            uint16_t taskname;
                            Json::Value::Members objmem = root[*it].getMemberNames();
                            Json::Value::Members::iterator objit = objmem.begin(), objend = objmem.end();
                            for(; objit != objend; objit ++)
                            {
                              if(*objit=="taskname")   
                              {
                                switch(root[*it][*objit].type())
                                {
                                  case Json::intValue:
                                  {
                                    taskname=root[*it][*objit].asInt();  
                                    _p->e2proomdata.rmtaskfile(taskname);
                                  }
                                  break;
                                  case Json::stringValue:
                                  {
                                    Json::String ms=root[*it][*objit].asString(); 
                                    if(ms=="all")
                                      _p->e2proomdata.rmalltaskfile();
                                  }  
                                  break;
                                }
                              }
                            }
                            _p->e2proomdata.taskfilename.clear();
                            _p->e2proomdata.findtaskfile(&_p->e2proomdata.taskfilename);
                            sent_root["rm"]="ok";
                        }
                        else if(*it=="cat")
                        {
                          Json::Value data;
                          for(int t=0;t<root[*it].size();t++)
                          {
                            if(root[*it][t].asString()=="homography_matrix")
                            {   
                                Json::Value newIterm; 
                                for(int i=0;i<_p->homography_matrix.size();i++)
                                {
                                    newIterm.append(_p->homography_matrix[i]);
                                }  
                                data["homography_matrix"]=newIterm;
                            }
                            else if(root[*it][t].asString()=="pData_demdlg_R")
                            {
                                std::vector<double> pData_demdlg_R(9);
                                int n=0;
                                for(int j=0;j<3;j++)
                                {
                                  for(int i=0;i<3;i++)
                                  {
                                      pData_demdlg_R[n++]=_p->e2proomdata.demdlg_R(j,i);
                                  }
                                }
                                Json::Value newIterm; 
                                for(int i=0;i<pData_demdlg_R.size();i++)
                                {
                                    newIterm.append(pData_demdlg_R[i]);
                                } 
                                data["pData_demdlg_R"]=newIterm;
                            }
                            else if(root[*it][t].asString()=="pData_demdlg_T")
                            {
                                std::vector<double> pData_demdlg_T(3);
                                int n=0;
                                for(int i=0;i<3;i++)
                                {
                                    pData_demdlg_T[n++]=_p->e2proomdata.demdlg_T(i);
                                }
                                Json::Value newIterm; 
                                for(int i=0;i<pData_demdlg_T.size();i++)
                                {
                                    newIterm.append(pData_demdlg_T[i]);
                                } 
                                data["pData_demdlg_T"]=newIterm;
                            }
                            else if(root[*it][t].asString()=="pData_matrix_camera2plane")
                            {
                                std::vector<double> pData_matrix_camera2plane=convertMat2Vector<double>(_p->e2proomdata.matrix_camera2plane);
                                Json::Value newIterm; 
                                for(int i=0;i<pData_matrix_camera2plane.size();i++)
                                {
                                    newIterm.append(pData_matrix_camera2plane[i]);
                                } 
                                data["pData_matrix_camera2plane"]=newIterm;
                            }
                            else if(root[*it][t].asString()=="pData_matrix_plane2robot")
                            {
                                std::vector<double> pData_matrix_plane2robot=convertMat2Vector<double>(_p->e2proomdata.matrix_plane2robot);
                                Json::Value newIterm; 
                                for(int i=0;i<pData_matrix_plane2robot.size();i++)
                                {
                                    newIterm.append(pData_matrix_plane2robot[i]);
                                } 
                                data["pData_matrix_plane2robot"]=newIterm; 
                            }
                            else if(root[*it][t].asString()=="pData_point")
                            {
                                Json::Value newIterm; 
                                for(int i=0;i<_p->e2proomdata.P_data.size();i++)
                                {
                                    std::string id=to_string(_p->e2proomdata.P_data[i].pID);
                                    Json::Value minarry;
                                    for(int j=0;j<_p->e2proomdata.P_data[i].pos.size();j++)
                                    {
                                      Json::Value jpos;
                                      jpos["x"]=_p->e2proomdata.P_data[i].pos[j].x;
                                      jpos["y"]=_p->e2proomdata.P_data[i].pos[j].y;
                                      jpos["z"]=_p->e2proomdata.P_data[i].pos[j].z;
                                      jpos["rx"]=_p->e2proomdata.P_data[i].pos[j].rx;
                                      jpos["ry"]=_p->e2proomdata.P_data[i].pos[j].ry;
                                      jpos["rz"]=_p->e2proomdata.P_data[i].pos[j].rz;
                                      jpos["out1"]=_p->e2proomdata.P_data[i].pos[j].out1;
                                      jpos["out2"]=_p->e2proomdata.P_data[i].pos[j].out2;
                                      jpos["out3"]=_p->e2proomdata.P_data[i].pos[j].out3;
                                      jpos["tool"]=_p->e2proomdata.P_data[i].pos[j].tool;
                                      jpos["tcp"]=_p->e2proomdata.P_data[i].pos[j].tcp;
                                      jpos["usertcp"]=_p->e2proomdata.P_data[i].pos[j].usertcp;
                                      jpos["uy"]=_p->e2proomdata.P_data[i].pos[j].uy;
                                      jpos["vz"]=_p->e2proomdata.P_data[i].pos[j].vz;
                                      minarry.append(jpos);
                                    }
                                    newIterm[id.c_str()]=minarry;
                                }
                                data["pData_point"]=newIterm;
                            }
                          }
                          sent_root["cat"]=data;
                        }
                        else if(*it=="echo")
                        {
                            bool b_temp=true;
                            Json::Value::Members objmem = root[*it].getMemberNames();
                            Json::Value::Members::iterator objit = objmem.begin(), objend = objmem.end();
                            for(; objit != objend; objit ++)
                            {
                                if(*objit=="homography_matrix")   
                                {
                                    if(root[*it][*objit].size()==9)
                                    {
                                        _p->homography_matrix.resize(9);
                                        for(int i=0;i<root[*it][*objit].size();i++)
                                        {
                                          _p->homography_matrix[i]=root[*it][*objit][i].asDouble();  
                                        }
                                        _p->_param_linecenter_set->set_parameters({rclcpp::Parameter("homography_matrix",_p->homography_matrix)});
                                    }
                                    else
                                    {
                                      b_temp=false;
                                    }
                                }
                                else if(*objit=="pData_demdlg_R")
                                {
                                    if(root[*it][*objit].size()==9)
                                    {
                                        std::vector<double> pData_demdlg_R(9);
                                        for(int i=0;i<root[*it][*objit].size();i++)
                                        {
                                          pData_demdlg_R[i]=root[*it][*objit][i].asDouble();  
                                        }
                                        int n=0;
                                        for(int j=0;j<3;j++)
                                        {
                                            for(int i=0;i<3;i++)
                                            {
                                              _p->e2proomdata.demdlg_R(j,i)=pData_demdlg_R[n++];
                                            }
                                        }
                                        _p->_param_pclout_set->set_parameters({rclcpp::Parameter("pData_demdlg_R", pData_demdlg_R)}); 
                                    }
                                    else
                                    {
                                      b_temp=false;
                                    }
                                }
                                else if(*objit=="pData_demdlg_T")
                                {
                                    if(root[*it][*objit].size()==3)
                                    {
                                        std::vector<double> pData_demdlg_T(3);
                                        for(int i=0;i<root[*it][*objit].size();i++)
                                        {
                                          pData_demdlg_T[i]=root[*it][*objit][i].asDouble();  
                                        }
                                        int n=0;
                                        for(int i=0;i<3;i++)
                                        {
                                          _p->e2proomdata.demdlg_T(i)=pData_demdlg_T[n++];
                                        }
                                        _p->_param_pclout_set->set_parameters({rclcpp::Parameter("pData_demdlg_T", pData_demdlg_T)}); 
                                    }
                                    else
                                    {
                                      b_temp=false;
                                    }
                                }
                                else if(*objit=="pData_matrix_camera2plane")
                                {
                                    if(root[*it][*objit].size()==9)
                                    {
                                        std::vector<double> pData_matrix_camera2plane(9);
                                        for(int i=0;i<9;i++)
                                        {
                                            pData_matrix_camera2plane[i]=root[*it][*objit][i].asDouble();  
                                        }
                                        _p->e2proomdata.matrix_camera2plane=cv::Mat(pData_matrix_camera2plane, true).reshape(1, 3);
                                        _p->_param_pclout_set->set_parameters({rclcpp::Parameter("pData_matrix_camera2plane", pData_matrix_camera2plane)});
                                    }
                                    else
                                    {
                                      b_temp=false;
                                    }
                                }
                                else if(*objit=="pData_matrix_plane2robot")
                                {
                                    if(root[*it][*objit].size()==9)
                                    {
                                        std::vector<double> pData_matrix_plane2robot(9);
                                        for(int i=0;i<9;i++)
                                        {
                                            pData_matrix_plane2robot[i]=root[*it][*objit][i].asDouble();  
                                        }
                                        _p->e2proomdata.matrix_plane2robot=cv::Mat(pData_matrix_plane2robot, true).reshape(1, 3);
                                        _p->_param_pclout_set->set_parameters({rclcpp::Parameter("pData_matrix_plane2robot", pData_matrix_plane2robot)});
                                    }
                                    else
                                    {
                                      b_temp=false;
                                    }
                                }
                                else if(*objit=="pData_point")
                                {
                                    _p->e2proomdata.P_data.clear();
                                    Json::Value::Members objmem2 = root[*it][*objit].getMemberNames();
                                    Json::Value::Members::iterator objit2 = objmem2.begin(), objend2 = objmem2.end();
                                    for(; objit2 != objend2; objit2 ++)
                                    {
                                        std::string s_id=*objit2;
                                        int id=atoi(s_id.c_str());
                                        rob_group singl;
                                        singl.pID=id;
                                        for(int i=0;i<root[*it][*objit][*objit2].size();i++)
                                        {
                                          rob_pinfo pos;
                                          Json::Value jp=root[*it][*objit][*objit2][i];
                                          pos.x=jp["x"].asDouble();
                                          pos.y=jp["y"].asDouble();
                                          pos.z=jp["z"].asDouble();
                                          pos.rx=jp["rx"].asDouble();
                                          pos.ry=jp["ry"].asDouble();
                                          pos.rz=jp["rz"].asDouble();
                                          pos.out1=jp["out1"].asInt();
                                          pos.out2=jp["out2"].asInt();
                                          pos.out3=jp["out3"].asInt();
                                          pos.tool=jp["tool"].asInt();
                                          pos.tcp=jp["tcp"].asInt();
                                          pos.usertcp=jp["usertcp"].asInt();
                                          pos.uy=jp["uy"].asInt();
                                          pos.vz=jp["vz"].asInt();
                                          singl.pos.push_back(pos);
                                        }
                                        _p->e2proomdata.P_data.push_back(singl);
                                    }
                                }
                            }
                            if(b_temp==true)
                            {
                                sent_root["echo"]="ok";
                            }
                            else
                            {
                                sent_root["echo"]="ng";
                            }
                            _p->e2proomdata.write_demdlg_para();
                            _p->e2proomdata.write_P_data_para();
                        }
                    }
                }
                if(sent_root.size()!=0)
                {
                    Json::StreamWriterBuilder builder;
                    std::string json_file=Json::writeString(builder, sent_root);
                    if(!ftptcp.is_online() && ftptcp.get_last_closed_sockets() == _p->ftpdesc[i]->id) 
                    {
                        cerr << "Connessione chiusa: stop send_clients( id:" << _p->ftpdesc[i]->id << " ip:" << _p->ftpdesc[i]->ip << " )"<< endl;
                    }
                    ftptcp.Send(json_file, _p->ftpdesc[i]->id);
                    if(_p->b_tcpsockershow==true)
                    {  
                      cerr << "message: " << json_file << endl;
                    }
                }

                _p->num_ftpclient++;

                ftptcp.clean(i);
            }
        }
        sleep(0);
    }
    return 0;
}

void Modbus::_sentrecv()
{
  while(rclcpp::ok())
  {
    Uint16 robot_mod=e2proomdata.robot_mod;
    switch (robot_mod)
    {
      case E2POOM_ROBOT_MOD_ZHICHANG_KAWASAKI_AS:
      { 
      //RCLCPP_INFO(this->get_logger(), "sent laser_signal");
        usleep(200000);
        std::string str="list/R laser_signal\r\n"; 
        m_sendentrecv.Send(str.c_str(),str.size());//向机器人发送as语言的指令，查询photo的值  
      }
      break;
    }
    usleep(0);
  }
}

void Modbus::_client()
{
    while(rclcpp::ok())
    {
        Uint16 robot_mod=e2proomdata.robot_mod;
        sleep(5);//每隔5秒查看一次机器人
        char rodb_ip[50];
        u_int16_t ip[4];
        ip[0]=192;
        ip[1]=168;
        ip[2]=1;
        ip[3]=23;
        sprintf(rodb_ip,"%d.%d.%d.%d",ip[0],ip[1],ip[2],ip[3]);

        RCLCPP_INFO(this->get_logger(), "connecting robot...");
        switch (robot_mod)
        {
          case E2POOM_ROBOT_MOD_ZHICHANG_KAWASAKI_AS:
          {
            m_client.CreateSocket();
            if(false==m_client.Connect(rodb_ip,ROBOT_KAWASAKI_SEND_PORT))
            {
                RCLCPP_ERROR(this->get_logger(), "connecting error...");
                continue;
            }
            m_client.SetBlock(0);
            if(0!=m_client.SetRcvBufferlong(ROBOT_KAWASAKI_INFO_RECVBUFFER_MAX*2))
            {
                RCLCPP_ERROR(this->get_logger(), "connecting setrcvbuffer error...");
                continue;
            }

            b_client=true;
            rcv_buf=new uint8_t[ROBOT_KAWASAKI_INFO_RECVBUFFER_MAX*2+1];

            m_sendent.CreateSocket();
            if(false==m_sendent.Connect(rodb_ip,ROBOT_KAWASAKI_SEND_PORT))
            {
                RCLCPP_ERROR(this->get_logger(), "connecting m_sendent error...");
                continue;
            }
            m_sendent.SetBlock(0);
            b_sendent=true;

            m_sendentrecv.CreateSocket();
            if(false==m_sendentrecv.Connect(rodb_ip,ROBOT_KAWASAKI_SEND_PORT))
            {
                RCLCPP_ERROR(this->get_logger(), "connecting m_sendentrecv error...");
                continue;
            }
            m_sendentrecv.SetBlock(0);
            

            rcv_buf2=new uint8_t[ROBOT_KAWASAKI_INFO_RECVBUFFER_MAX*2+1];

            sleep(1);
            std::string str="as\r\n";
            m_client.Send(str.c_str(),str.size());
            m_sendent.Send(str.c_str(),str.size());
            m_sendentrecv.Send(str.c_str(),str.size());
            usleep(200000);

            b_sendentrecv=true;
            _sentrecvtcpthread = std::thread(&Modbus::_sentrecv, this);

            str="where 2\r\n";
            m_client.Send(str.c_str(),str.size());
          }
          break;
        }
        if(b_client==true&&b_sendent==true&&b_sendentrecv==true)
        {
          RCLCPP_INFO(this->get_logger(), "robot connected");
          while(rclcpp::ok())
          {
            switch (robot_mod)
            {
              case E2POOM_ROBOT_MOD_ZHICHANG_KAWASAKI_AS:
              {  
                  static int total_rcvnum=0;
                  static std::string s_rcvmsg;
                  int rcvnum=m_client.Recv((char*)rcv_buf,ROBOT_KAWASAKI_INFO_RECVBUFFER_MAX*2);
                  if(rcvnum>0)
                  {
                      rcv_buf[rcvnum]='\0';
                      if(b_tcpsockershow==true)
                      { 
                        RCLCPP_INFO(this->get_logger(), (const char*)rcv_buf);
                      }
                      total_rcvnum=total_rcvnum+rcvnum;
                      std::string rcvmsg=(char*)rcv_buf;
                      s_rcvmsg=s_rcvmsg+rcvmsg;
                      if(rcvmsg[rcvmsg.size()-1]=='\n')//结尾
                      {
                          if(s_rcvmsg.size()>=2&&s_rcvmsg[s_rcvmsg.size()-2]=='\r')
                          {
                              bool b_succeed=true;
                              std::vector<float> pos;
                              std::string msg=s_rcvmsg.substr(0,s_rcvmsg.size()-2);
                              istringstream in(msg);
                              vector<string> strList;
                              std::string t;
                              while (getline(in, t, ' ')) {	//这里单引号要注意
                                strList.push_back(t);
                              }
                              for(int i=0;i<strList.size();i++)
                              {
                                  std::string s_data=strList[i];
                                  if(s_data.size()>0)
                                  {
                                      int temp;
                                      double f_data;
                                      temp=CM_Atof((char*)(s_data.c_str()),&f_data);
                                      if(temp==0)
                                      {
                                          b_succeed=false;
                                          break;
                                      }
                                      pos.push_back(f_data);
                                  }
                              }
                              if(pos.size()>=6&&b_succeed==true)//解码成功
                              {
                                  int f_data;
                                  f_data=pos[0]*1000;
                                  mb_mapping->tab_registers[ALS_REALTIME_POSX_REG_ADD]=((uint16_t*)(&f_data))[0];
                                  mb_mapping->tab_registers[ALS_REALTIME_POSX_REG_ADD+1]=((uint16_t*)(&f_data))[1];
                                  f_data=pos[1]*1000;
                                  mb_mapping->tab_registers[ALS_REALTIME_POSY_REG_ADD]=((uint16_t*)(&f_data))[0];
                                  mb_mapping->tab_registers[ALS_REALTIME_POSY_REG_ADD+1]=((uint16_t*)(&f_data))[1];
                                  f_data=pos[2]*1000;
                                  mb_mapping->tab_registers[ALS_REALTIME_POSZ_REG_ADD]=((uint16_t*)(&f_data))[0];
                                  mb_mapping->tab_registers[ALS_REALTIME_POSZ_REG_ADD+1]=((uint16_t*)(&f_data))[1];
                                  f_data=pos[3]*10000;
                                  mb_mapping->tab_registers[ALS_REALTIME_POSRX_REG_ADD]=((uint16_t*)(&f_data))[0];
                                  mb_mapping->tab_registers[ALS_REALTIME_POSRX_REG_ADD+1]=((uint16_t*)(&f_data))[1];
                                  f_data=pos[4]*10000;
                                  mb_mapping->tab_registers[ALS_REALTIME_POSRY_REG_ADD]=((uint16_t*)(&f_data))[0];
                                  mb_mapping->tab_registers[ALS_REALTIME_POSRY_REG_ADD+1]=((uint16_t*)(&f_data))[1];
                                  f_data=pos[5]*10000;
                                  mb_mapping->tab_registers[ALS_REALTIME_POSRZ_REG_ADD]=((uint16_t*)(&f_data))[0];
                                  mb_mapping->tab_registers[ALS_REALTIME_POSRZ_REG_ADD+1]=((uint16_t*)(&f_data))[1];
                              }
                              //有外部轴
                              if(pos.size()>6&&pos.size()<=9)
                              {
                                  int st=0;
                                  for(int i=6;i<pos.size();i++)
                                  {
                                      int i_data;
                                      i_data=pos[i]*1000;//川崎第六轴放大1000倍
                                      mb_mapping->tab_registers[ALS_REALTIME_POSOUT1_REG_ADD+st]=((uint16_t*)(&i_data))[0];
                                      mb_mapping->tab_registers[ALS_REALTIME_POSOUT1_REG_ADD+st+1]=((uint16_t*)(&i_data))[1];
                                      st=st+2;
                                  }
                              }
                          }
                          s_rcvmsg.clear();
                          total_rcvnum=0;
                      }
                  }
                  int rcvnum2=m_sendentrecv.Recv((char*)rcv_buf2,ROBOT_KAWASAKI_INFO_RECVBUFFER_MAX*2);
                  if(rcvnum2>0)
                  {
                    rcv_buf2[rcvnum2]='\0';
                    if(b_tcpsockershow==true)
                    { 
                      RCLCPP_INFO(this->get_logger(), (const char*)rcv_buf2);
                    }
                    static int total_rcvnum=0;
                    static std::string s_rcvmsg;
                    total_rcvnum=total_rcvnum+rcvnum2;
                    std::string rcvmsg=(char*)rcv_buf2;
                    s_rcvmsg=s_rcvmsg+rcvmsg;
                    if(rcvmsg[rcvmsg.size()-1]=='\n')//结尾
                    {
                      if(s_rcvmsg.size()>=2&&s_rcvmsg[s_rcvmsg.size()-2]=='\r')
                      {
                        int s;
                        bool b_succeed=true;
                        string strTemp;
                        bool b_find=false;
                        if(b_find==false)
                        { 
                          strTemp = "laser_signal = "; 
                          s=s_rcvmsg.find(strTemp,0);

                          
                          if(s!=0xfffffff)
                          {
                            string s_data;
                            for(int i=s+strTemp.size();i<s_rcvmsg.size();i++)
                            {
                              if(s_rcvmsg[i]=='\r')
                              {
                                break;
                              }
                              else
                              {
                                s_data.push_back(s_rcvmsg[i]);
                              }
                            }
                            
                            int temp;
                            int i_data;
                            temp=CM_Atoi((char*)(s_data.c_str()),&i_data);
                            if(temp!=0)
                            {
                                if(i_data==1)//打开激光
                                {
                                //    RCLCPP_INFO(this->get_logger(), "打开激光");
                                    _gpio_laser(true);
                                    _camera_power(true);
                                    mb_mapping->tab_registers[0x101]=0xff; 
                                }
                                else if(i_data==0)//关闭激光
                                {
                                //    RCLCPP_INFO(this->get_logger(), "关闭激光");
                                    _gpio_laser(false);
                                    _camera_power(false);
                                    mb_mapping->tab_registers[0x101]=0x00; 
                                }
                                else
                                {
                                //    RCLCPP_INFO(this->get_logger(), "%d",i_data);
                                }
                            }
                            else
                            {
                            //  RCLCPP_INFO(this->get_logger(), s_data.c_str());
                            }
                            b_find=true;
                          }
                        }
                      }
                      s_rcvmsg.clear();
                      total_rcvnum=0;
                    }
                  }
              }
              break;
            }  
            usleep(0);
          }
        }
        else if(b_client==true)
        {
          delete[] rcv_buf;
          m_client.Close();
        }
        else if(b_sendent==true)
        {
          m_sendent.Close();
        }
        else if(b_sendentrecv==true)
        {
          delete[] rcv_buf2;
          m_sendentrecv.Close();
        }
    }
}

void Modbus::_json(int port)
{
    pthread_t msg;
    std::signal(SIGINT, close_app);
    std::vector<int> opts = { SO_REUSEPORT, SO_REUSEADDR };
    if( jsontcp.setup(port,opts) != 0)
    {
         RCLCPP_ERROR(this->get_logger(), "Errore json socket.");
    }
    else
    {
        if( pthread_create(&msg, NULL, received, this) == 0)
        {
            while(rclcpp::ok()) {
                jsontcp.accepted();
                cerr << "Accepted" << endl;
            }
        }
    } 
}

void close_app(int s) 
{
    jsontcp.closed();
    rclcpp::shutdown();
}

void* received(void *m)
{
    Modbus *_p=(Modbus*)m;
    pthread_detach(pthread_self());
    while(rclcpp::ok())
    {
        _p->desc = jsontcp.getMessage();
        for(unsigned int i = 0; i < _p->desc.size(); i++) 
        {
            if( _p->desc[i] )
            {
                switch(_p->e2proomdata.robot_mod)
                {
                  case E2POOM_ROBOT_MOD_ZHICHANG_KAWASAKI:
                  {
                    Json::Value root;
                    jsonfuction js;
                    Json::Value sent_root;
                    std::vector<char> vec=_p->desc[i]->message;
                    vec.push_back('\0');
                    std::string str(vec.begin(), vec.end());
                    if(_p->b_tcpsockershow==true)
                    {
                    cerr << "id:      " << _p->desc[i]->id      << endl
                        << "ip:      " << _p->desc[i]->ip      << endl
                        << "message: " << str << endl
                        << "socket:  " << _p->desc[i]->socket  << endl
                        << "enable:  " << _p->desc[i]->enable_message_runtime << endl;
                    }
                  #ifdef USE_PARENTHESES_INSTEAD_QUOTATION
                    for(unsigned int n=0;n<str.size();n++)
                    {
                        if(str[n]==0x28||str[n]==0x29)   //"
                        {
                           str[n]=0x22; 
                        }
                    }
                  #endif
                    if(0==js.readJsonFromString(str,&root))
                    {
                        Json::Value::Members mem = root.getMemberNames();
                        Json::Value::Members::iterator it = mem.begin(), end = mem.end();
                        for(; it != end; it ++)
                        {
                        //  cout<<*it<< endl; 
                            if(*it=="leaser")   
                            {
                              //  cout<<root[*it].asString();
                                switch(root[*it].type())
                                {
                                    case Json::stringValue:
                                    {
                                        if(root[*it].asString()=="open")
                                        {
                                            _p->_gpio_laser(true);
                                            _p->_camera_power(true);
                                            _p->mb_mapping->tab_registers[0x101]=0xff;  
                                            sent_root["leaser"]="open ok";
                                        }
                                        else if(root[*it].asString()=="close")
                                        {
                                            _p->_gpio_laser(false);
                                            _p->_camera_power(false);
                                            _p->mb_mapping->tab_registers[0x101]=0; 
                                            sent_root["leaser"]="close ok";
                                        }
                                    }
                                    break;
                                    default:
                                    break;
                                }
                            }
                            else if(*it=="tasknum")
                            {
                                switch(root[*it].type())
                                {
                                    case Json::stringValue:
                                    {
                                        std::string s_tasknum=root[*it].asString();
                                        int ID = atoi(s_tasknum.c_str());
                                        _p->mb_mapping->tab_registers[0x102]=ID;
                                        sent_root["tasknum"]=s_tasknum+" ok";
                                        static int oldtasknum=INT_MAX;
                                        if(oldtasknum!=_p->mb_mapping->tab_registers[0x102])
                                        {
                                          oldtasknum=_p->mb_mapping->tab_registers[0x102];
                                          _p->_task_numberset(oldtasknum);
                                        }
                                        
                                    }
                                    break;
                                    default:
                                    break;
                                }
                            }
                            else if(*it=="getdelay")
                            {
                                switch(root[*it].type())
                                {
                                    case Json::stringValue:
                                    {
                                        if(root[*it].asString()=="once")
                                        {
                                            u_int16_t delay=_p->mb_mapping->tab_registers[0x001];
                                            sent_root["getdelay"]=to_string(delay);
                                        }
                                    }
                                    break;
                                    default:
                                    break;
                                }
                            }
                            else if(*it=="getsearchstat")
                            {
                                switch(root[*it].type())
                                {
                                    case Json::stringValue:
                                    {
                                        if(root[*it].asString()=="once")
                                        {
                                            u_int16_t stat=_p->mb_mapping->tab_registers[0x002];
                                            if(stat==0xff)
                                            {
                                                sent_root["getsearchstat"]="ok";
                                            }
                                            else if(stat==0)
                                            {
                                                sent_root["getsearchstat"]="ng";
                                            }
                                            else
                                            {
                                                sent_root["getsearchstat"]="failed";
                                            }
                                            if(_p->b_resultreset==true)
                                            {
                                              _p->mb_mapping->tab_registers[0x02]=0;
                                            }
                                        }
                                    }
                                    break;
                                    default:
                                    break;
                                }
                            }
                            else if(*it=="getpos2")
                            {
                                switch(root[*it].type())
                                {
                                    case Json::stringValue:
                                    {
                                        if(root[*it].asString()=="once")
                                        {
                                            u_int16_t stat=_p->mb_mapping->tab_registers[0x002];
                                            if(stat==0xff)
                                            {
                                                int16_t i_posy=_p->mb_mapping->tab_registers[0x003];
                                                int16_t i_posz=_p->mb_mapping->tab_registers[0x004];
                                                float posy=i_posy/100.0;
                                                float posz=i_posz/100.0;
                                                sent_root["getpos2"].append(posy);
                                                sent_root["getpos2"].append(posz);
                                            }
                                            else
                                            {
                                                sent_root["getpos2"]="failed";
                                            }
                                            if(_p->b_resultreset==true)
                                            {
                                              _p->mb_mapping->tab_registers[0x02]=0;
                                            }
                                        }
                                    }
                                    break;
                                    default:
                                    break;
                                }
                            }
                            else if(*it=="getsize2")
                            {
                                switch(root[*it].type())
                                {
                                    case Json::stringValue:
                                    {
                                        if(root[*it].asString()=="once")
                                        {
                                            u_int16_t stat=_p->mb_mapping->tab_registers[0x002];
                                            if(stat==0xff)
                                            {
                                                int16_t i_sizew=_p->mb_mapping->tab_registers[0x005];
                                                int16_t i_sizeh=_p->mb_mapping->tab_registers[0x006];
                                                float sizew=i_sizew/100.0;
                                                float sizeh=i_sizeh/100.0;
                                                sent_root["getsize2"].append(sizew);
                                                sent_root["getsize2"].append(sizeh);
                                            }
                                            else
                                            {
                                                sent_root["getsize2"]="failed";
                                            }
                                            if(_p->b_resultreset==true)
                                            {
                                              _p->mb_mapping->tab_registers[0x02]=0;
                                            }
                                        }
                                    }
                                    break;
                                    default:
                                    break;
                                }
                            }
                        }
                    }
                    if(sent_root.size()!=0)
                    {
                        Json::StreamWriterBuilder builder;
                        std::string json_file=Json::writeString(builder, sent_root);
                        if(!jsontcp.is_online() && jsontcp.get_last_closed_sockets() == _p->desc[i]->id) 
                        {
                            cerr << "Connessione chiusa: stop send_clients( id:" << _p->desc[i]->id << " ip:" << _p->desc[i]->ip << " )"<< endl;
                        }
                    #ifdef USE_PARENTHESES_INSTEAD_QUOTATION 
                        int time_s=0;
                        for(unsigned int n=0;n<json_file.size();n++)
                        {
                            if(json_file[n]==0x22)   //"
                            {
                                if(time_s==0)
                                {
                                    json_file[n]=0x28; //(
                                    time_s=1;
                                }
                                else if(time_s==1)
                                {
                                    json_file[n]=0x29; //)
                                    time_s=0;
                                }
                            }
                        }
                    #endif 
                    #ifdef DEL_SPACE_AND_LINEN
                        std::string json_file2;
                        for(unsigned int n=0;n<json_file.size();n++)
                        {
                            if(json_file[n]!='\n')
                            {
                                json_file2.push_back(json_file[n]);
                            }
                        }
                        json_file=json_file2;
                    #endif
                        jsontcp.Send(json_file, _p->desc[i]->id);
                    }


                    _p->num_client++;
                  // start message background thread
                  }
                  break;
                  case E2POOM_ROBOT_MOD_GANGSHANG:          //RTU
                  {
                    if(_p->b_tcpsockershow==true)
                    {  
                      std::string s_data;
                      for(int t=0;t<_p->desc[i]->message.size();t++)
                      {
                          std::string str;
                          u_int8_t u8_data=(u_int8_t)_p->desc[i]->message[t];
                          str=std::to_string(u8_data)+" ";
                          s_data=s_data+str;
                      }
                      cerr << "id:      " << _p->desc[i]->id      << endl
                          << "ip:      " << _p->desc[i]->ip      << endl
                          << "messagesize: " << _p->desc[i]->message.size() << endl 
                          << "message: " << s_data << endl                          
                          << "socket:  " << _p->desc[i]->socket  << endl
                          << "enable:  " << _p->desc[i]->enable_message_runtime << endl;
                    }
                    std::vector<u_int8_t> sendbuffer;
                    if(_p->desc[i]->message.size()>=4)
                    {
                        u_int8_t *u8_data=(u_int8_t*)&(_p->desc[i]->message[0]);
                        if(u8_data[0]==0x04&&u8_data[1]==0x01&&u8_data[2]==0x01)//设置任务号
                        {
                            uint16_t task=u8_data[3];
                            _p->mb_mapping->tab_registers[0x102]=task;
                            static int oldtasknum=INT_MAX;
                            if(oldtasknum!=_p->mb_mapping->tab_registers[0x102])
                            {
                              oldtasknum=_p->mb_mapping->tab_registers[0x102];
                              _p->_task_numberset(oldtasknum);
                            }
                            std::vector<u_int8_t> send;
                            send.resize(5);
                            send[0]=0x52;
                            send[1]=0x52;  
                            send[2]=0x54;  
                            send[3]=0x01;
                            send[4]=1;
                            sendbuffer=send;
                        }
                        else if(u8_data[0]==0x04&&u8_data[1]==0x01&&u8_data[2]==0x02&&u8_data[3]==0x01)//激光打开
                        {
                            _p->_gpio_laser(true);
                            _p->_camera_power(true);
                          //_p->mb_mapping->tab_registers[0x101]=0xff; 
                            std::vector<u_int8_t> send;
                            send.resize(5);
                            send[0]=0x52;
                            send[1]=0x52;  
                            send[2]=0x54;  
                            send[3]=0x02;
                            send[4]=1;
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x04&&u8_data[1]==0x01&&u8_data[2]==0x03&&u8_data[3]==0x00)//激光关闭
                        {
                            _p->_gpio_laser(false);
                            _p->_camera_power(false);
                          //_p->mb_mapping->tab_registers[0x101]=0; 
                            std::vector<u_int8_t> send;
                            send.resize(5);
                            send[0]=0x52;
                            send[1]=0x52;  
                            send[2]=0x54;  
                            send[3]=0x03;
                            send[4]=1;
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x04&&u8_data[1]==0x01&&u8_data[2]==0x04&&u8_data[3]==0x01)//开始寻位
                        {
                          //_p->_gpio_laser(true);
                          //_p->_camera_power(true);
                            _p->b_search=true;
                            _p->b_weld=false;
                            _p->mb_mapping->tab_registers[0x101]=0xff; 
                            std::vector<u_int8_t> send;
                            send.resize(5);
                            send[0]=0x52;
                            send[1]=0x52;  
                            send[2]=0x54;  
                            send[3]=0x04;
                            send[4]=1;
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x04&&u8_data[1]==0x01&&u8_data[2]==0x05&&u8_data[3]==0x00)//停止寻位
                        {
                          //_p->_gpio_laser(false);
                          //_p->_camera_power(false);
                            _p->b_search=false;
                            _p->b_weld=false;
                            _p->mb_mapping->tab_registers[0x101]=0; 
                            std::vector<u_int8_t> send;
                            send.resize(5);
                            send[0]=0x52;
                            send[1]=0x52;  
                            send[2]=0x54;  
                            send[3]=0x05;
                            send[4]=1;
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x04&&u8_data[1]==0x01&&u8_data[2]==0x06&&u8_data[3]==0x01)//开始跟踪
                        {
                          //_p->_gpio_laser(true);
                          //_p->_camera_power(true);
                            _p->b_search=false;
                            _p->b_weld=true;
                            _p->mb_mapping->tab_registers[0x101]=0xff; 
                            std::vector<u_int8_t> send;
                            send.resize(5);
                            send[0]=0x52;
                            send[1]=0x52;  
                            send[2]=0x54;  
                            send[3]=0x06;
                            send[4]=1;
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x04&&u8_data[1]==0x01&&u8_data[2]==0x07&&u8_data[3]==0x00)//停止跟踪
                        {
                          //_p->_gpio_laser(false);
                          //_p->_camera_power(false);
                            _p->b_search=false;
                            _p->b_weld=false;
                            _p->mb_mapping->tab_registers[0x101]=0; 
                            std::vector<u_int8_t> send;
                            send.resize(5);
                            send[0]=0x52;
                            send[1]=0x52;  
                            send[2]=0x54;  
                            send[3]=0x07;
                            send[4]=1;
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x08&&u8_data[1]==0x01&&u8_data[2]==0x07&&u8_data[3]==0x01)//查询相机状态
                        {
                            std::vector<u_int8_t> send;
                            u_int16_t state=0;
                            send.resize(7);
                            send[0]=0x52;
                            send[1]=0x52;  
                            send[2]=0x54;  
                            send[3]=0x08;
                            send[4]=1;
                            state=0;
                            if(_p->b_laser==true&&_p->b_camera==true)
                            {
                              state=(state|0x0001);
                            }
                            else
                            {
                              state=(state&0xfffe);
                            }
                            if(_p->b_search==true)
                            {
                              state=(state|0x0002);
                            }
                            else
                            {
                              state=(state&0xfffd);
                            }
                            if(_p->b_weld==true)
                            {
                              state=(state|0x0004);
                            }
                            else
                            {
                              state=(state&0xfffb);
                            }
                            send[5]=(state>>8);
                            send[6]=(state&0x00ff);
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x07&&u8_data[1]==0x06&&u8_data[2]==0x09&&u8_data[3]==0x01)//查询焊缝位置,相机坐标系
                        {
                            std::vector<u_int8_t> send;
                            u_int16_t state=0;
                            send.resize(17);
                            send[0]=0x52;
                            send[1]=0x52;  
                            send[2]=0x54;  
                            send[3]=0x09;
                            if(_p->mb_mapping->tab_registers[0x02]==0)
                            {
                              send[4]=0;    
                            }
                            else
                            {
                              send[4]=1;
                            }
                            if(_p->b_resultreset==true)
                            {
                              _p->mb_mapping->tab_registers[0x02]=0;
                            }
                            u_int16_t X,Y,Z,TA,TB,TC;
                            X=_p->mb_mapping->tab_registers[0x70];
                            Y=_p->mb_mapping->tab_registers[0x03];
                            Z=_p->mb_mapping->tab_registers[0x04];
                            TA=_p->mb_mapping->tab_registers[0x71];
                            TB=_p->mb_mapping->tab_registers[0x05];
                            TC=_p->mb_mapping->tab_registers[0x06];
                            send[5]=(X>>8);
                            send[6]=(X&0x00ff);
                            send[7]=(Y>>8);
                            send[8]=(Y&0x00ff);
                            send[9]=(Z>>8);
                            send[10]=(Z&0x00ff);
                            send[11]=(TA>>8);
                            send[12]=(TA&0x00ff);
                            send[13]=(TB>>8);
                            send[14]=(TB&0x00ff);
                            send[15]=(TC>>8);
                            send[16]=(TC&0x00ff);
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x07&&u8_data[1]==0x06&&u8_data[2]==0x0a&&u8_data[3]==0x01)//查询焊缝位置,光学坐标系
                        {
                            std::vector<u_int8_t> send;
                            u_int16_t state=0;
                            send.resize(17);
                            send[0]=0x52;
                            send[1]=0x52;  
                            send[2]=0x54;  
                            send[3]=0x0a;
                            if(_p->mb_mapping->tab_registers[0x02]==0)
                            {
                              send[4]=0;    
                            }
                            else
                            {
                              send[4]=1;
                            }
                            if(_p->b_resultreset==true)
                            {
                              _p->mb_mapping->tab_registers[0x02]=0;
                            }
                            u_int16_t X,Y,Z,TA,TB,TC;
                            X=_p->mb_mapping->tab_registers[0x70];
                            Y=_p->mb_mapping->tab_registers[0x03];
                            Z=_p->mb_mapping->tab_registers[0x04];
                            TA=_p->mb_mapping->tab_registers[0x71];
                            TB=_p->mb_mapping->tab_registers[0x05];
                            TC=_p->mb_mapping->tab_registers[0x06];
                            send[5]=(X>>8);
                            send[6]=(X&0x00ff);
                            send[7]=(Y>>8);
                            send[8]=(Y&0x00ff);
                            send[9]=(Z>>8);
                            send[10]=(Z&0x00ff);
                            send[11]=(TA>>8);
                            send[12]=(TA&0x00ff);
                            send[13]=(TB>>8);
                            send[14]=(TB&0x00ff);
                            send[15]=(TC>>8);
                            send[16]=(TC&0x00ff);
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x07&&u8_data[1]==0x01&&u8_data[2]==0x0b&&u8_data[3]==0x01)//查询任务号
                        {
                            std::vector<u_int8_t> send;
                            u_int16_t state=0;
                            send.resize(6);
                            send[0]=0x52;
                            send[1]=0x52;  
                            send[2]=0x54;  
                            send[3]=0x0b;
                            send[4]=1;
                            send[5]=_p->mb_mapping->tab_registers[0x102];
                            sendbuffer=send; 
                        }
                    }
                    if(sendbuffer.size()>0)
                    {
                        jsontcp.Send((char*)&sendbuffer[0], sendbuffer.size(),_p->desc[i]->id);
                    }
                    _p->num_client++;
                  // start message background thread 
                  }
                  break;
                  case E2POOM_ROBOT_MOD_EFORT:
                  {
                    if(_p->b_tcpsockershow==true)
                    { 
                      std::string s_data;
                      for(int t=0;t<_p->desc[i]->message.size();t++)
                      {
                          std::string str;
                          u_int8_t u8_data=(u_int8_t)_p->desc[i]->message[t];
                          str=std::to_string(u8_data)+" ";
                          s_data=s_data+str;
                      }
                      cerr << "id:      " << _p->desc[i]->id      << endl
                          << "ip:      " << _p->desc[i]->ip      << endl
                          << "message: " << s_data << endl
                          << "socket:  " << _p->desc[i]->socket  << endl
                          << "enable:  " << _p->desc[i]->enable_message_runtime << endl;
                    }
                    std::vector<u_int8_t> sendbuffer;
                    if(_p->desc[i]->message.size()>=9)
                    {
                        u_int8_t *u8_data=(u_int8_t*)&(_p->desc[i]->message[0]);
                        if(u8_data[0]==0x45&&u8_data[1]==0x46&&u8_data[2]==0x4f&&u8_data[3]==0x52&&u8_data[4]==0x54
                         &&u8_data[5]==0x01&&u8_data[6]==0x01&&u8_data[7]==0x01)//设置任务号
                        {
                            uint16_t task=u8_data[8];
                            _p->mb_mapping->tab_registers[0x102]=task;
                            static int oldtasknum=INT_MAX;
                            if(oldtasknum!=_p->mb_mapping->tab_registers[0x102])
                            {
                              oldtasknum=_p->mb_mapping->tab_registers[0x102];
                              _p->_task_numberset(oldtasknum);
                            }
                            std::vector<u_int8_t> send;
                            send.resize(5);
                            send[0]=0x43;
                            send[1]=0x61;  
                            send[2]=0x6d;  
                            send[3]=0x01;
                            send[4]=0x01;
                            sendbuffer=send;
                        }
                        else if(u8_data[0]==0x45&&u8_data[1]==0x46&&u8_data[2]==0x4f&&u8_data[3]==0x52&&u8_data[4]==0x54
                         &&u8_data[5]==0x01&&u8_data[6]==0x01&&u8_data[7]==0x02&&u8_data[8]==0x01)//激光打开
                        {
                            _p->_gpio_laser(true);
                            _p->_camera_power(true);
                          //_p->mb_mapping->tab_registers[0x101]=0xff; 
                            std::vector<u_int8_t> send;
                            send.resize(5);
                            send[0]=0x43;
                            send[1]=0x61;  
                            send[2]=0x6d;  
                            send[3]=0x02;
                            send[4]=0x01;
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x45&&u8_data[1]==0x46&&u8_data[2]==0x4f&&u8_data[3]==0x52&&u8_data[4]==0x54
                         &&u8_data[5]==0x01&&u8_data[6]==0x01&&u8_data[7]==0x03&&u8_data[8]==0x00)//激光关闭
                        {
                            _p->_gpio_laser(false);
                            _p->_camera_power(false);
                          //_p->mb_mapping->tab_registers[0x101]=0; 
                            std::vector<u_int8_t> send;
                            send.resize(5);
                            send[0]=0x43;
                            send[1]=0x61;  
                            send[2]=0x6d;  
                            send[3]=0x03;
                            send[4]=0x01;
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x45&&u8_data[1]==0x46&&u8_data[2]==0x4f&&u8_data[3]==0x52&&u8_data[4]==0x54
                         &&u8_data[5]==0x01&&u8_data[6]==0x01&&u8_data[7]==0x04&&u8_data[8]==0x01)//开始寻位
                        {
                          //_p->_gpio_laser(true);
                          //_p->_camera_power(true);
                            _p->b_search=true;
                            _p->b_weld=false;
                            _p->mb_mapping->tab_registers[0x101]=0xff; 
                            std::vector<u_int8_t> send;
                            send.resize(5);
                            send[0]=0x43;
                            send[1]=0x61;  
                            send[2]=0x6d;  
                            send[3]=0x04;
                            send[4]=0x01;
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x45&&u8_data[1]==0x46&&u8_data[2]==0x4f&&u8_data[3]==0x52&&u8_data[4]==0x54
                         &&u8_data[5]==0x01&&u8_data[6]==0x01&&u8_data[7]==0x05&&u8_data[8]==0x00)//停止寻位
                        {
                          //_p->_gpio_laser(false);
                          //_p->_camera_power(false);
                            _p->b_search=false;
                            _p->b_weld=false;
                            _p->mb_mapping->tab_registers[0x101]=0; 
                            std::vector<u_int8_t> send;
                            send.resize(5);
                            send[0]=0x43;
                            send[1]=0x61;  
                            send[2]=0x6d;  
                            send[3]=0x05;
                            send[4]=0x01;
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x45&&u8_data[1]==0x46&&u8_data[2]==0x4f&&u8_data[3]==0x52&&u8_data[4]==0x54
                         &&u8_data[5]==0x01&&u8_data[6]==0x01&&u8_data[7]==0x06&&u8_data[8]==0x01)//开始跟踪
                        {
                          //_p->_gpio_laser(true);
                          //_p->_camera_power(true);
                            _p->b_search=false;
                            _p->b_weld=true;
                            _p->mb_mapping->tab_registers[0x101]=0xff; 
                            std::vector<u_int8_t> send;
                            send.resize(5);
                            send[0]=0x43;
                            send[1]=0x61;  
                            send[2]=0x6d;  
                            send[3]=0x06;
                            send[4]=0x01;
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x45&&u8_data[1]==0x46&&u8_data[2]==0x4f&&u8_data[3]==0x52&&u8_data[4]==0x54
                         &&u8_data[5]==0x01&&u8_data[6]==0x01&&u8_data[7]==0x07&&u8_data[8]==0x00)//停止跟踪
                        {
                          //_p->_gpio_laser(false);
                          //_p->_camera_power(false);
                            _p->b_search=false;
                            _p->b_weld=false;
                            _p->mb_mapping->tab_registers[0x101]=0; 
                            std::vector<u_int8_t> send;
                            send.resize(5);
                            send[0]=0x43;
                            send[1]=0x61;  
                            send[2]=0x6d;  
                            send[3]=0x07;
                            send[4]=0x01;
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x45&&u8_data[1]==0x46&&u8_data[2]==0x4f&&u8_data[3]==0x52&&u8_data[4]==0x54
                         &&u8_data[5]==0x02&&u8_data[6]==0x01&&u8_data[7]==0x08&&u8_data[8]==0x01)//查询相机状态
                        {
                            std::vector<u_int8_t> send;
                            u_int16_t state=0;
                            send.resize(7);
                            send[0]=0x43;
                            send[1]=0x61;  
                            send[2]=0x6d;  
                            send[3]=0x08;
                            send[4]=0x01;
                            state=0;
                            if(_p->b_laser==true&&_p->b_camera==true)
                            {
                              state=(state|0x0001);
                            }
                            else
                            {
                              state=(state&0xfffe);
                            }
                            if(_p->b_search==true)
                            {
                              state=(state|0x0002);
                            }
                            else
                            {
                              state=(state&0xfffd);
                            }
                            if(_p->b_weld==true)
                            {
                              state=(state|0x0004);
                            }
                            else
                            {
                              state=(state&0xfffb);
                            }
                            send[5]=(state>>8);
                            send[6]=(state&0x00ff);
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x45&&u8_data[1]==0x46&&u8_data[2]==0x4f&&u8_data[3]==0x52&&u8_data[4]==0x54
                         &&u8_data[5]==0x03&&u8_data[6]==0x05&&u8_data[7]==0x09&&u8_data[8]==0x01)//查询焊缝位置,相机坐标系
                        {
                            std::vector<u_int8_t> send;
                            u_int16_t state=0;
                            send.resize(17);
                            send[0]=0x43;
                            send[1]=0x61;  
                            send[2]=0x6d;  
                            send[3]=0x09;
                            if(_p->mb_mapping->tab_registers[0x02]==0)
                            {
                              send[4]=0x00;    
                            }
                            else
                            {
                              send[4]=0x01;
                            }
                            if(_p->b_resultreset==true)
                            {
                              _p->mb_mapping->tab_registers[0x02]=0;
                            }
                            u_int16_t X,Y,Z,TA,TB,TC;
                            X=_p->mb_mapping->tab_registers[0x70];
                            Y=_p->mb_mapping->tab_registers[0x03];
                            Z=_p->mb_mapping->tab_registers[0x04];
                            TA=_p->mb_mapping->tab_registers[0x71]/10;
                            TB=_p->mb_mapping->tab_registers[0x05]/10;
                            TC=_p->mb_mapping->tab_registers[0x06]/10;
                            send[5]=(X>>8);
                            send[6]=(X&0x00ff);
                            send[7]=(Y>>8);
                            send[8]=(Y&0x00ff);
                            send[9]=(Z>>8);
                            send[10]=(Z&0x00ff);
                            send[11]=(TA>>8);
                            send[12]=(TA&0x00ff);
                            send[13]=(TB>>8);
                            send[14]=(TB&0x00ff);
                            send[15]=(TC>>8);
                            send[16]=(TC&0x00ff);
                            sendbuffer=send; 
                        }
                        else if(u8_data[0]==0x45&&u8_data[1]==0x46&&u8_data[2]==0x4f&&u8_data[3]==0x52&&u8_data[4]==0x54
                         &&u8_data[5]==0x04&&u8_data[6]==0x01&&u8_data[7]==0x0e&&u8_data[8]==0x01)//查询任务号
                        {
                            std::vector<u_int8_t> send;
                            u_int16_t state=0;
                            send.resize(6);
                            send[0]=0x43;
                            send[1]=0x61;  
                            send[2]=0x6d;  
                            send[3]=0x0e;
                            send[4]=0x01;
                            send[5]=_p->mb_mapping->tab_registers[0x102];
                            sendbuffer=send; 
                        }
                    }
                    if(sendbuffer.size()>0)
                    {
                        jsontcp.Send((char*)&sendbuffer[0], sendbuffer.size(),_p->desc[i]->id);
                    }
                    _p->num_client++;
                  }
                  break;
                  case E2POOM_ROBOT_MOD_STEP:
                  {
                    if(_p->b_tcpsockershow==true)
                    {  
                      std::vector<char> vec=_p->desc[i]->message;
                      vec.push_back('\0');
                      std::string str(vec.begin(), vec.end());

                      cerr << "id:     " << _p->desc[i]->id      << endl
                          << "ip:      " << _p->desc[i]->ip      << endl
                          << "message: " << str << endl                          
                          << "socket:  " << _p->desc[i]->socket  << endl
                          << "enable:  " << _p->desc[i]->enable_message_runtime << endl;
                    }
                    std::vector<u_int8_t> sendbuffer;
                    if(_p->desc[i]->message.size()>0)
                    {
                      bool b_cansend=true;//是否可以发送
                      xmlNodePtr sendcur=NULL;//xml发送节点
                      xmlDocPtr doc=NULL;   //xml整个文档的树形结构
                      xmlNodePtr cur=NULL;  //xml节点
                      char *u8_data=(char*)&(_p->desc[i]->message[0]);
                      int32_t rcvsize=_p->desc[i]->message.size();
                      xmlKeepBlanksDefault(0);
                      doc=xmlParseMemory(u8_data,rcvsize);  //字符串转xml
                      if(doc!=NULL) 
                      {  
                        cur = xmlDocGetRootElement(doc);//获取xml根节点
                        if(cur != NULL) 
                        {
                          if(xmlStrcmp(cur->name, (const xmlChar*)"cmd")==0)
                          {
                            sendcur=xmlNewNode(NULL, (xmlChar*)"rep");//创建xml根节点
                            if(sendcur==NULL)
                            {
                              b_cansend=false;
                            }
                            xmlChar *tsp = xmlGetProp(cur,(xmlChar*)"tsp"); //获得节点的属性                      
                            xmlChar *rtsp = xmlGetProp(cur,(xmlChar*)"rtsp"); //获得节点的属性                      
                            xmlChar *send = xmlGetProp(cur,(xmlChar*)"send"); //获得节点的属性                      
                            xmlChar *recv = xmlGetProp(cur,(xmlChar*)"recv"); //获得节点的属性                      
                            xmlNodePtr childcur = NULL;
                            xmlChar *cmd=NULL;     

                          //if(xmlStrcmp(send,(xmlChar*)"Robot")==0&&xmlStrcmp(recv,(xmlChar*)"Sensor")==0)
                            {
                              int datatime=(int)_p->mb_mapping->tab_registers[0x01];
                              int i_tsp=atoi((char*)tsp)+datatime;
                              std::string s_tsp=std::to_string(i_tsp);

                              //添加属性
                              xmlNewProp(sendcur,(xmlChar*)"tsp",(xmlChar*)(s_tsp.c_str()));//tsp此属性包含传感器发送命令的当前发送时间
                              xmlNewProp(sendcur,(xmlChar*)"rtsp",(xmlChar*)tsp);//rtsp此属性包含从传感器接受到的最后回应
                              xmlNewProp(sendcur,(xmlChar*)"send",recv);
                              xmlNewProp(sendcur,(xmlChar*)"recv",send);

                              childcur = cur->xmlChildrenNode;
                              if(childcur!=NULL)
                              {
                                if(xmlStrcmp(childcur->name, (const xmlChar*)"setPar")==0)//设置参数
                                {
                                  int task;
                                  cmd=xmlGetProp(childcur,(xmlChar*)"p1");//任务号
                                  task=atoi((char*)cmd);
                                  _p->mb_mapping->tab_registers[0x102]=task;
                                  static int oldtasknum=INT_MAX;
                                  if(oldtasknum!=_p->mb_mapping->tab_registers[0x102])
                                  {
                                    oldtasknum=_p->mb_mapping->tab_registers[0x102];
                                    _p->_task_numberset(oldtasknum);
                                  }
                                  xmlNodePtr sendchildcur=xmlNewChild(sendcur,NULL,(xmlChar*)"setPar",NULL);
                                  xmlNewProp(sendchildcur,(xmlChar*)"res",(xmlChar*)"1");
                                  xmlNewProp(sendchildcur,(xmlChar*)"error",(xmlChar*)"succeed");
                                }
                                else if(xmlStrcmp(childcur->name, (const xmlChar*)"getPar")==0)//获取参数
                                {
                                  int task=_p->mb_mapping->tab_registers[0x102];
                                  std::string c_task=to_string(task);
                                  xmlNodePtr sendchildcur=xmlNewChild(sendcur,NULL,(xmlChar*)"getPar",NULL);
                                  xmlNewProp(sendchildcur,(xmlChar*)"p1",(xmlChar*)(c_task.c_str()));
                                  xmlNewProp(sendchildcur,(xmlChar*)"res",(xmlChar*)"1");
                                  xmlNewProp(sendchildcur,(xmlChar*)"error",(xmlChar*)"succeed");
                                }
                                else if(xmlStrcmp(childcur->name, (const xmlChar*)"camOn")==0)//相机打开
                                {
                                  _p->_gpio_laser(true);
                                  _p->_camera_power(true);
                                  xmlNodePtr sendchildcur=xmlNewChild(sendcur,NULL,(xmlChar*)"camOn",NULL);
                                  xmlNewProp(sendchildcur,(xmlChar*)"res",(xmlChar*)"1");
                                  xmlNewProp(sendchildcur,(xmlChar*)"error",(xmlChar*)"succeed"); 
                                }
                                else if(xmlStrcmp(childcur->name, (const xmlChar*)"camEn")==0)//相机启用
                                {
                                  _p->mb_mapping->tab_registers[0x101]=0xff; 
                                  xmlNodePtr sendchildcur=xmlNewChild(sendcur,NULL,(xmlChar*)"camEn",NULL);
                                  xmlNewProp(sendchildcur,(xmlChar*)"res",(xmlChar*)"1");
                                  xmlNewProp(sendchildcur,(xmlChar*)"error",(xmlChar*)"succeed"); 
                                }
                                else if(xmlStrcmp(childcur->name, (const xmlChar*)"camDis")==0)//相机停止
                                {
                                  _p->mb_mapping->tab_registers[0x101]=0; 
                                  xmlNodePtr sendchildcur=xmlNewChild(sendcur,NULL,(xmlChar*)"camDis",NULL);
                                  xmlNewProp(sendchildcur,(xmlChar*)"res",(xmlChar*)"1");
                                  xmlNewProp(sendchildcur,(xmlChar*)"error",(xmlChar*)"succeed"); 
                                }
                                else if(xmlStrcmp(childcur->name, (const xmlChar*)"camOff")==0)//相机关闭
                                {
                                  _p->_gpio_laser(false);
                                  _p->_camera_power(false);
                                  xmlNodePtr sendchildcur=xmlNewChild(sendcur,NULL,(xmlChar*)"camOff",NULL);
                                  xmlNewProp(sendchildcur,(xmlChar*)"res",(xmlChar*)"1");
                                  xmlNewProp(sendchildcur,(xmlChar*)"error",(xmlChar*)"succeed"); 
                                }
                                else if(xmlStrcmp(childcur->name, (const xmlChar*)"getVal")==0)//获取位置
                                {
                                  cmd=xmlGetProp(childcur,(xmlChar*)"num");
                                  xmlNodePtr sendchildcur=xmlNewChild(sendcur,NULL,(xmlChar*)"getVal",NULL);
                                  if(_p->mb_mapping->tab_registers[0x02]==0)//检测失败
                                  {
                                    xmlNewProp(sendchildcur,(xmlChar*)"res",(xmlChar*)"-1");
                                    xmlNewProp(sendchildcur,(xmlChar*)"error",(xmlChar*)"failed");
                                  }
                                  else
                                  {
                                    xmlNewProp(sendchildcur,(xmlChar*)"res",(xmlChar*)"1");
                                    xmlNewProp(sendchildcur,(xmlChar*)"error",(xmlChar*)"succeed");
                                    if(_p->b_resultreset==true)
                                    {
                                      _p->mb_mapping->tab_registers[0x02]=0;
                                    }
                                  }
                                  float X=(int)((int16_t)_p->mb_mapping->tab_registers[0x70])/100.0;
                                  float Y=(int)((int16_t)_p->mb_mapping->tab_registers[0x03])/100.0;
                                  float Z=(int)((int16_t)_p->mb_mapping->tab_registers[0x04])/100.0;
                                  float TA=(int)((int16_t)_p->mb_mapping->tab_registers[0x71])/1000.0;
                                  float TB=(int)((int16_t)_p->mb_mapping->tab_registers[0x05])/1000.0;
                                  float TC=(int)((int16_t)_p->mb_mapping->tab_registers[0x06])/1000.0;
                                  float Y1=(int)((int16_t)_p->mb_mapping->tab_registers[0x50])/100.0;
                                  float Z1=(int)((int16_t)_p->mb_mapping->tab_registers[0x51])/100.0;
                                  float Y2=(int)((int16_t)_p->mb_mapping->tab_registers[0x52])/100.0;
                                  float Z2=(int)((int16_t)_p->mb_mapping->tab_registers[0x53])/100.0;
                                  float Y3=(int)((int16_t)_p->mb_mapping->tab_registers[0x54])/100.0;
                                  float Z3=(int)((int16_t)_p->mb_mapping->tab_registers[0x55])/100.0;
                                  int task=_p->mb_mapping->tab_registers[0x102];

                                  xmlNodePtr sendchildcur2=xmlNewChild(sendchildcur,NULL,(xmlChar*)"opt",NULL);
                                  xmlNewProp(sendchildcur2,(xmlChar*)"x",(xmlChar*)(to_string_with_precision(X,2).c_str()));
                                  xmlNewProp(sendchildcur2,(xmlChar*)"y",(xmlChar*)(to_string_with_precision(Y,2).c_str()));
                                  xmlNewProp(sendchildcur2,(xmlChar*)"z",(xmlChar*)(to_string_with_precision(Z,2).c_str()));
                                  xmlNewProp(sendchildcur2,(xmlChar*)"a",(xmlChar*)(to_string_with_precision(TA,2).c_str()));
                                  xmlNewProp(sendchildcur2,(xmlChar*)"b",(xmlChar*)(to_string_with_precision(TB,2).c_str()));
                                  xmlNewProp(sendchildcur2,(xmlChar*)"c",(xmlChar*)(to_string_with_precision(TC,2).c_str()));
                                  xmlNodePtr sendchildcur3=xmlNewChild(sendchildcur,NULL,(xmlChar*)"bp",NULL);
                                  xmlNewProp(sendchildcur3,(xmlChar*)"x1",(xmlChar*)(to_string_with_precision(X,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"y1",(xmlChar*)(to_string_with_precision(Y1,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"z1",(xmlChar*)(to_string_with_precision(Z1,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"x2",(xmlChar*)(to_string_with_precision(X,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"y2",(xmlChar*)(to_string_with_precision(Y2,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"z2",(xmlChar*)(to_string_with_precision(Z2,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"x3",(xmlChar*)(to_string_with_precision(X,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"y3",(xmlChar*)(to_string_with_precision(Y3,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"z3",(xmlChar*)(to_string_with_precision(Z3,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"x4",(xmlChar*)(to_string_with_precision(0,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"y4",(xmlChar*)(to_string_with_precision(0,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"z4",(xmlChar*)(to_string_with_precision(0,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"x5",(xmlChar*)(to_string_with_precision(0,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"y5",(xmlChar*)(to_string_with_precision(0,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"z5",(xmlChar*)(to_string_with_precision(0,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"x6",(xmlChar*)(to_string_with_precision(0,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"y6",(xmlChar*)(to_string_with_precision(0,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"z6",(xmlChar*)(to_string_with_precision(0,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"x7",(xmlChar*)(to_string_with_precision(0,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"y7",(xmlChar*)(to_string_with_precision(0,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"z7",(xmlChar*)(to_string_with_precision(0,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"x8",(xmlChar*)(to_string_with_precision(0,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"y8",(xmlChar*)(to_string_with_precision(0,2).c_str()));
                                  xmlNewProp(sendchildcur3,(xmlChar*)"z8",(xmlChar*)(to_string_with_precision(0,2).c_str()));
                                  xmlNodePtr sendchildcur4=xmlNewChild(sendchildcur,NULL,(xmlChar*)"go",NULL);
                                  xmlNewProp(sendchildcur4,(xmlChar*)"ar",(xmlChar*)"0");
                                  xmlNewProp(sendchildcur4,(xmlChar*)"gp",(xmlChar*)"0");
                                  xmlNewProp(sendchildcur4,(xmlChar*)"ny",(xmlChar*)"0");
                                  xmlNewProp(sendchildcur4,(xmlChar*)"ms",(xmlChar*)"0");
                                  xmlNodePtr sendchildcur5=xmlNewChild(sendchildcur,NULL,(xmlChar*)"apm",NULL);
                                  xmlNewProp(sendchildcur5,(xmlChar*)"p1",(xmlChar*)"0");
                                  xmlNewProp(sendchildcur5,(xmlChar*)"p2",(xmlChar*)"0");
                                  xmlNewProp(sendchildcur5,(xmlChar*)"p3",(xmlChar*)"0");
                                  xmlNewProp(sendchildcur5,(xmlChar*)"p4",(xmlChar*)"0");
                                  xmlNewProp(sendchildcur5,(xmlChar*)"p5",(xmlChar*)"0");
                                  xmlNewProp(sendchildcur5,(xmlChar*)"p6",(xmlChar*)"0");
                                }
                              }
                            }
                            if(_p->b_tcpsockershow==true)
                            {
                              cerr << "name:   "<< cur->name << endl
                                  << "tsp:   "<< tsp << endl
                                  << "rtsp:   "<< rtsp << endl
                                  << "send:   "<< send << endl
                                  << "recv:   "<< recv << endl  
                                  << "childname:   "<< childcur->name << endl
                                  << "cmd:   "<< cmd << endl;  
                            }
                            if(b_cansend==true)
                            {
                              xmlChar *doc_txt_ptr;
                              char *sendbuffer;
                              int size;
                              xmlBuffer * bufferPtr = xmlBufferCreate();
                              xmlNodeDump(bufferPtr,sendcur->doc,sendcur,0,0);
                              sendbuffer=(char*)bufferPtr->content;
                              size=std::strlen(sendbuffer)+1;
                              if(size>1)
                              {
                                  jsontcp.Send((char*)&sendbuffer[0], size,_p->desc[i]->id);
                              }
                              xmlBufferFree(bufferPtr);
                              _p->num_client++;
                            }
                            if(tsp != NULL)
                            {
                              xmlFree(tsp);
                            }
                            if(rtsp != NULL)
                            {
                              xmlFree(rtsp);
                            }
                            if(send != NULL)
                            {
                              xmlFree(send);
                            } 
                            if(recv != NULL)
                            {
                              xmlFree(recv);
                            }
                            if(cmd != NULL)
                            {
                              xmlFree(cmd);
                            }
                          }
                        }  
                      }
                      if(doc != NULL)
                      {
                        xmlFreeDoc(doc);
                      }
                    }
                  }
                  break;
                  default:
                  break;
                }
                jsontcp.clean(i);
            }
        }
        sleep(0);
    }
    return 0;
}

}  // namespace modbus

#include "rclcpp_components/register_node_macro.hpp"

// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
RCLCPP_COMPONENTS_REGISTER_NODE(modbus::Modbus)
