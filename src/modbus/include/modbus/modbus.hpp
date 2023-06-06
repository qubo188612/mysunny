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

#ifndef MODBUS__MODBUS_HPP
#define MODBUS__MODBUS_HPP

#define USE_PARENTHESES_INSTEAD_QUOTATION      
#define DEL_SPACE_AND_LINEN

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include <json/jsonfuction.h>
#include <TCP/TCPServer.h>
#include <TCP/TCPServer2.h>
#include <modbus.h>
#include "fileout/E2proomData.h"

#define PIC_IMAGE_HEIGHT 2064
#define PIC_IMAGE_WIDTH  1544

namespace modbus
{

#define SERVER_REGEDIST_NUM               400


#define ROBOT_SET_REGEDIST_NUM            0x10
#define ROBOT_MOD_REG_ADD                 0x0000
#define ROBOT_PORT_REG_ADD                0x0001
#define ALSROBOTCAM_COMPENSATION_X        0x0002  //标定补偿X
#define ALSROBOTCAM_COMPENSATION_Y        0x0003  //标定补偿Y
#define ALSROBOTCAM_COMPENSATION_Z        0x0004  //标定补偿Z
#define CAMER_SIZE_WIDTH_REG_ADD          0x0005
#define CAMER_SIZE_HEIGHT_REG_ADD         0x0006
#define CAMER_FPS_REG_ADD                 0x0007
#define CAMER_SIZE_VIEW_WIDTH_REG_ADD     0x0008
#define CAMER_SIZE_VIEW_HEIGHT_REG_ADD    0x0009
#define ALSROBOTCAM_REVERSE_Y_REG_ADD     0x000a  //相机Y数据反向
#define ALSROBOTCAM_REVERSE_Z_REG_ADD     0x000b

#define PARAMETER_REGEDIST_NUM                 400

#define ALS100_EXPOSURE_TIME_REG_ADD           0x0000
#define ALS100_PINGJUN_REG_ADD                 0x0001
#define ALS100_B_YANMOFUZHU_REG_ADD            0x0002
#define ALS100_B_GUDINGQUYU_REG_ADD            0x0003
#define ALS100_WIDTHLIANTONGDIS_REG_ADD        0x0004
#define ALS100_HIGHLIANTONGDIS_REG_ADD         0x0005
#define ALS100_GUJIAERZHI_REG_ADD              0x0006
#define ALS100_JIGUANGHIGHT_REG_ADD            0x0007
#define ALS100_JIGUANGLONG_REG_ADD             0x0008
#define ALS100_JIGUANGKUANDU_REG_ADD           0x0009
#define ALS100_UPDIF_REG_ADD                   0x000a
#define ALS100_UPDIFMIN_REG_ADD                0x000b
#define ALS100_UPLONG_REG_ADD                  0x000c
#define ALS100_DOWNDIF_REG_ADD                 0x000d
#define ALS100_DOWNDIFMIN_REG_ADD              0x000e
#define ALS100_DOWNDLONG_REG_ADD               0x000f
#define ALS100_DUANXIANERZHI_REG_ADD           0x0010
#define ALS100_ERZHISIZE_REG_ADD               0x0011
#define ALS100_ERZHISIZE2_REG_ADD              0x0012
#define ALS100_SEARCHDECTANCEMAX_REG_ADD       0x0013
#define ALS100_SEARCHDECTANCEMIN_REG_ADD       0x0014
#define ALS100_DIS_CENTER_ST_REG_ADD           0x0015
#define ALS100_DIS_CENTER_ED_REG_ADD           0x0016
#define ALS100_ANSWERPOINT_REG_ADD             0x0017


#define ALS100_INIT_REG_ADD                    0x001f

#define ALS101_EXPOSURE_TIME_REG_ADD           0x0020
#define ALS101_PINGJUN_REG_ADD                 0x0021
#define ALS101_B_YANMOFUZHU_REG_ADD            0x0022
#define ALS101_B_GUDINGQUYU_REG_ADD            0x0023
#define ALS101_WIDTHLIANTONGDIS_REG_ADD        0x0024
#define ALS101_HIGHLIANTONGDIS_REG_ADD         0x0025
#define ALS101_GUJIAERZHI_REG_ADD              0x0026
#define ALS101_JIGUANGHIGHT_REG_ADD            0x0027
#define ALS101_JIGUANGLONG_REG_ADD             0x0028
#define ALS101_JIGUANGKUANDU_REG_ADD           0x0029
#define ALS101_UPDIF_REG_ADD                   0x002a
#define ALS101_UPDIFMIN_REG_ADD                0x002b
#define ALS101_UPLONG_REG_ADD                  0x002c
#define ALS101_DOWNDIF_REG_ADD                 0x002d
#define ALS101_DOWNDIFMIN_REG_ADD              0x002e
#define ALS101_DOWNDLONG_REG_ADD               0x002f
#define ALS101_DUANXIANERZHI_REG_ADD           0x0030
#define ALS101_ERZHISIZE_REG_ADD               0x0031
#define ALS101_ERZHISIZE2_REG_ADD              0x0032
#define ALS101_SEARCHDECTANCEMAX_REG_ADD       0x0033
#define ALS101_SEARCHDECTANCEMIN_REG_ADD       0x0034
#define ALS101_DIS_CENTER_ST_REG_ADD           0x0035
#define ALS101_DIS_CENTER_ED_REG_ADD           0x0036
#define ALS101_ANSWERPOINT_REG_ADD             0x0037

#define ALS101_INIT_REG_ADD                    0x003f

#define ALS102_EXPOSURE_TIME_REG_ADD           0x0040
#define ALS102_PINGJUN_REG_ADD                 0x0041
#define ALS102_B_YANMOFUZHU_REG_ADD            0x0042
#define ALS102_B_GUDINGQUYU_REG_ADD            0x0043
#define ALS102_WIDTHLIANTONGDIS_REG_ADD        0x0044
#define ALS102_HIGHLIANTONGDIS_REG_ADD         0x0045
#define ALS102_GUJIAERZHI_REG_ADD              0x0046
#define ALS102_JIGUANGHIGHT_REG_ADD            0x0047
#define ALS102_JIGUANGLONG_REG_ADD             0x0048
#define ALS102_JIGUANGKUANDU_REG_ADD           0x0049
#define ALS102_UPDIF_REG_ADD                   0x004a
#define ALS102_UPDIFMIN_REG_ADD                0x004b
#define ALS102_UPLONG_REG_ADD                  0x004c
#define ALS102_DOWNDIF_REG_ADD                 0x004d
#define ALS102_DOWNDIFMIN_REG_ADD              0x004e
#define ALS102_DOWNDLONG_REG_ADD               0x004f
#define ALS102_ST_DOWN_REG_ADD                 0x0050
#define ALS102_ED_DOWN_REG_ADD                 0x0051
#define ALS102_ST_UP_REG_ADD                   0x0052
#define ALS102_ED_UP_REG_ADD                   0x0053
#define ALS102_UPDIF2_REG_ADD                  0x0054
#define ALS102_UPDIFMIN2_REG_ADD               0x0055
#define ALS102_DIS_CENTER_ST_REG_ADD           0x0056
#define ALS102_DIS_CENTER_ED_REG_ADD           0x0057
#define ALS102_B_OPENGUDINGDIMIAN_REG_ADD      0x0058
#define ALS102_DIMIANPANGDINGJULI_REG_ADD      0x0059
#define ALS102_DIMIANPINGJUNSHUNUM_REG_ADD     0x005a
#define ALS102_DIS_CENTER_ST2_REG_ADD          0x005b
#define ALS102_DIS_CENTER_ED2_REG_ADD          0x005c
#define ALS102_DIS_CENTER_ST3_REG_ADD          0x005d
#define ALS102_DIS_CENTER_ED3_REG_ADD          0x005e
#define ALS102_XUEXIJULI_REG_ADD               0x005f
#define ALS102_B_PINGPOWENGDING_REG_ADD        0x0060
#define ALS102_PINGPOWENGDING_DIS_REG_ADD      0x0061
#define ALS102_B_XIELVOPEN_REG_ADD             0x0062
#define ALS102_XIELVFANWEI_REG_ADD             0x0063
#define ALS102_UPLONG2_REG_ADD                 0x0064
#define ALS102_CEBANKONGDONGDIS_REG_ADD        0x0065
#define ALS102_QIATOUQUWEI_REG_ADD             0x0066
#define ALS102_ANSWERPOINT_REG_ADD             0x0067

#define ALS102_INIT_REG_ADD                    0x006f

#define ALS103_EXPOSURE_TIME_REG_ADD           0x0070
#define ALS103_PINGJUN_REG_ADD                 0x0071
#define ALS103_GUJIAERZHI_REG_ADD              0x0072
#define ALS103_WIDTHLIANTONGDIS_REG_ADD        0x0073
#define ALS103_HIGHLIANTONGDIS_REG_ADD         0x0074
#define ALS103_JIGUANGLONG_REG_ADD             0x0075
#define ALS103_JIGUANGKUANDU_REG_ADD           0x0076
#define ALS103_JIGUANGDUIBIDU_REG_ADD          0x0077

#define ALS103_INIT_REG_ADD                    0x007f

#define ALS104_EXPOSURE_TIME_REG_ADD           0x0080
#define ALS104_PINGJUN_REG_ADD                 0x0081
#define ALS104_B_YANMOFUZHU_REG_ADD            0x0082
#define ALS104_B_GUDINGQUYU_REG_ADD            0x0083
#define ALS104_WIDTHLIANTONGDIS_REG_ADD        0x0084
#define ALS104_HIGHLIANTONGDIS_REG_ADD         0x0085
#define ALS104_GUJIAERZHI_REG_ADD              0x0086
#define ALS104_JIGUANGHIGHT_REG_ADD            0x0087
#define ALS104_JIGUANGLONG_REG_ADD             0x0088
#define ALS104_JIGUANGKUANDU_REG_ADD           0x0089
#define ALS104_UPDIF_REG_ADD                   0x008a
#define ALS104_UPDIFMIN_REG_ADD                0x008b
#define ALS104_UPLONG_REG_ADD                  0x008c
#define ALS104_DOWNDIF_REG_ADD                 0x008d
#define ALS104_DOWNDIFMIN_REG_ADD              0x008e
#define ALS104_DOWNDLONG_REG_ADD               0x008f
#define ALS104_DIS_CENTER_ST_REG_ADD           0x0090
#define ALS104_DIS_CENTER_ED_REG_ADD           0x0091

#define ALS104_INIT_REG_ADD                    0x009f

#define ALS105_EXPOSURE_TIME_REG_ADD           0x00b0
#define ALS105_PINGJUN_REG_ADD                 0x00b1
#define ALS105_B_YANMOFUZHU_REG_ADD            0x00b2
#define ALS105_WIDTHLIANTONGDIS_REG_ADD        0x00b3
#define ALS105_HIGHLIANTONGDIS_REG_ADD         0x00b4
#define ALS105_GUJIAERZHI_REG_ADD              0x00b5
#define ALS105_JIGUANGHIGHT_REG_ADD            0x00b6
#define ALS105_JIGUANGLONG_REG_ADD             0x00b7
#define ALS105_JIGUANGKUANDU_REG_ADD           0x00b8
#define ALS105_UPDIF_REG_ADD                   0x00b9
#define ALS105_UPDIFMIN_REG_ADD                0x00ba
#define ALS105_UPLONG_REG_ADD                  0x00bb
#define ALS105_DOWNDIF_REG_ADD                 0x00bc
#define ALS105_DOWNDIFMIN_REG_ADD              0x00bd
#define ALS105_DOWNDLONG_REG_ADD               0x00be
#define ALS105_DIS_CENTER_ST_REG_ADD           0x00bf
#define ALS105_DIS_CENTER_ED_REG_ADD           0x00c0
#define ALS105_B_CUT_REG_ADD                   0x00c1
#define ALS105_CUTLEFT_REG_ADD                 0x00c2
#define ALS105_CUTRIGHT_REG_ADD                0x00c3
#define ALS105_CUTTOP_REG_ADD                  0x00c4
#define ALS105_CUTDEEP_REG_ADD                 0x00c5
#define ALS105_GUAIDIANYUZHI_REG_ADD           0x00c6
#define ALS105_DUANDIANJULI_REG_ADD            0x00c7
#define ALS105_B_DIBUFAXIANGLIANG_REG_ADD      0x00c8
#define ALS105_ANSWERPOINT_REG_ADD             0x00c9

#define ALS105_INIT_REG_ADD                    0x00cf

#define ALS106_EXPOSURE_TIME_REG_ADD           0x00d0
#define ALS106_PINGJUN_REG_ADD                 0x00d1
#define ALS106_B_YANMOFUZHU_REG_ADD            0x00d2
#define ALS106_B_GUDINGQUYU_REG_ADD            0x00d3
#define ALS106_WIDTHLIANTONGDIS_REG_ADD        0x00d4
#define ALS106_HIGHLIANTONGDIS_REG_ADD         0x00d5
#define ALS106_GUJIAERZHI_REG_ADD              0x00d6
#define ALS106_JIGUANGHIGHT_REG_ADD            0x00d7
#define ALS106_JIGUANGLONG_REG_ADD             0x00d8
#define ALS106_JIGUANGKUANDU_REG_ADD           0x00d9
#define ALS106_B_CUT_REG_ADD                   0x00da
#define ALS106_CUTLEFT_REG_ADD                 0x00db
#define ALS106_CUTRIGHT_REG_ADD                0x00dc
#define ALS106_CUTTOP_REG_ADD                  0x00dd
#define ALS106_CUTDEEP_REG_ADD                 0x00de
#define ALS106_DIFMIN_REG_ADD                  0x00df
#define ALS106_SIDELONG_REG_ADD                0x00e0
#define ALS106_UPBACK_ST_REG_ADD               0x00e1
#define ALS106_UPBACK_ED_REG_ADD               0x00e2
#define ALS106_DOWNBACK_ST_REG_ADD             0x00e3
#define ALS106_DOWNBACK_ED_REG_ADD             0x00e4
#define ALS106_UPMINDIS_REG_ADD                0x00e5
#define ALS106_DOWNMINDIS_REG_ADD              0x00e6
#define ALS106_UPLONG_REG_ADD                  0x00e7
#define ALS106_DOWNDLONG_REG_ADD               0x00e8
#define ALS106_DISCENTER_ED_REG_ADD            0x00e9
#define ALS106_DUANDIANJULI_REG_ADD            0x00ea
#define ALS106_POKOUMOD_REG_ADD                0x00eb
#define ALS106_POKOUUPDIF_REG_ADD              0x00ec
#define ALS106_POKOUUPDIFMIN_REG_ADD           0x00ed
#define ALS106_POKOUUPBACK_ST_REG_ADD          0x00ee
#define ALS106_POKOUUPBACK_ED_REG_ADD          0x00ef
#define ALS106_POKOUDOWNDIF_REG_ADD            0x00f0
#define ALS106_POKOUDOWNDIFMIN_REG_ADD         0x00f1
#define ALS106_POKOUDOWNBACK_ST_REG_ADD        0x00f2
#define ALS106_POKOUDOWNBACK_ED_REG_ADD        0x00f3
#define ALS106_POKOUUPLONG_REG_ADD             0x00f4
#define ALS106_POKOUDOWNLONG_REG_ADD           0x00f5
#define ALS106_B_POKOUYAOBIAN_REG_ADD          0x00f6
#define ALS106_POKOUYAOBIANHSIZE_REG_ADD       0x00f7
#define ALS106_POKOUDUANXIANERZHI_REG_ADD      0x00f8
#define ALS106_POKOUSEARCHDECTANCEMAX_REG_ADD  0x00f9
#define ALS106_POKOUSEARCHDECTANCEMIN_REG_ADD  0x00fa
#define ALS106_ANSWERPOINT_REG_ADD             0x00fb


#define ALS106_INIT_REG_ADD                    0x00ff


#define ALS108_EXPOSURE_TIME_REG_ADD           0x0120
#define ALS108_CENTER_X_REG_ADD                0x0121
#define ALS108_CENTER_Y_REG_ADD                0x0122
#define ALS108_SEARCT_W_REG_ADD                0x0123
#define ALS108_SEARCT_H_REG_ADD                0x0124
#define ALS108_STC_ALPHA_REG_ADD               0x0125
#define ALS108_STC_BETA_REG_ADD                0x0126
#define ALS108_STC_RHO_REG_ADD                 0x0127
#define ALS108_STC_SIGMA_REG_ADD               0x0128


#define ALS108_INIT_REG_ADD                    0x012f

#define ALS_SHOW_STEP_REG_ADD                  0x018f

/**
 * @brief Modbus protocal wrapped from libmodbus-dev.
 *
 */
class Modbus : public rclcpp::Node
{
public:
  /**
   * @brief Construct a new Modbus object.
   *
   * Create an inner implementation.
   * Initialize subscription.
   * Initialize parameter client for camera.
   * Initialize parameter client for gpio.
   * Print success if all done.
   * @param options Encapsulation of options for node initialization.
   */
  explicit Modbus(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

  /**
   * @brief Destroy the Modbus:: Modbus object.
   *
   * Release parameter client for camera.
   * Release parameter client for gpio.
   * Release subscription.
   * Release inner implementation.
   * Print success if all done.
   * Throw no exception.
   */
  ~Modbus();

  //modbus sock
  modbus_t * ctx;
  //modbus register 400 sizeof u_int16_t  
  modbus_mapping_t *mb_mapping; 

  modbus_t * ctx_forward;
  modbus_mapping_t *mb_forwardmapping; 

  modbus_t * ctx_parameterport;
  modbus_mapping_t *parameterport_mapping; 

  modbus_t * ctx_robot;
  modbus_mapping_t *robot_mapping; 


  //tcp client;
  pthread_t client[MAX_CLIENT];

  //tcp number of client
  int num_client;

  //total client tcp message
  vector<descript_socket*> desc;

  //tcp number of ftpclient
  int num_ftpclient;

  vector<descript_socket2*> ftpdesc;

  /**
   * @brief Control laser on of off.
   *
   */
  void _gpio_laser(bool);

  /**
   * @brief Control camera capture or not.
   *
   */
  void _camera_power(bool);
  void callbackCenterParam(std::shared_future<std::vector<rclcpp::Parameter>> future);

//void _camera_get_size(int *width,int *height);

  int camer_width;
  int camer_height;
  int camer_fps;
  int camer_view_width;
  int camer_view_height;
  void callbackGlobalParam(std::shared_future<std::vector<rclcpp::Parameter>> future);

  bool b_laser; //激光开关状态
  bool b_camera;//相机开关状态
  bool b_search;//寻位状态
  bool b_weld;//跟踪状态

  void _camera_set_size(int width,int height);

  void _task_numberset(u_int16_t num);

  void _task_parameter(int ddr,u_int16_t num);

  int als100_task_parameter(int ddr,u_int16_t num);
  int als101_task_parameter(int ddr,u_int16_t num);
  int als102_task_parameter(int ddr,u_int16_t num);
  int als103_task_parameter(int ddr,u_int16_t num);
  int als104_task_parameter(int ddr,u_int16_t num);
  int als105_task_parameter(int ddr,u_int16_t num);
  int als106_task_parameter(int ddr,u_int16_t num);
  int als108_task_parameter(int ddr,u_int16_t num);
  void init_als100_parameter();
  void init_als101_parameter();
  void init_als102_parameter();
  void init_als103_parameter();
  void init_als104_parameter();
  void init_als105_parameter();
  void init_als106_parameter();
  void init_als108_parameter();

  void _task_robot(int ddr,u_int16_t num);

  E2proomData e2proomdata;

  bool b_tcpsockershow;

  
private:
  
  
  /**
   * @brief Control camera capture or not.
   *
   */
  void _modbus(int);

  void _modbusforward(int);//服务器数据modbus转发

/**
   * @brief Send and receive in json format.
   *
   */
  void _json(int);//服务器数据json转发

  void _modbusparameterport(int);//框架2数据通信

  void _modbusrobotset(int);//机器人类型和端口设置

  void _ftp(int);//服务器数据ftp转发

private:
  /**
   * @brief Parameter client for camera.
   *
   */
  std::shared_ptr<rclcpp::AsyncParametersClient> _param_camera;
  std::shared_ptr<rclcpp::AsyncParametersClient> _param_camera_get;

  /**
   * @brief Parameter client for gpio.
   *
   */
  std::shared_ptr<rclcpp::AsyncParametersClient> _param_gpio;
  std::shared_ptr<rclcpp::AsyncParametersClient> _param_gpio_get;

  std::shared_ptr<rclcpp::AsyncParametersClient> _param_linecenter;

  std::shared_ptr<rclcpp::AsyncParametersClient> _param_laserimagepos;

  std::shared_ptr<rclcpp::AsyncParametersClient> _param_robotconfig;

  std::shared_ptr<rclcpp::AsyncParametersClient> _param_linecenter_set;
  std::shared_ptr<rclcpp::AsyncParametersClient> _param_linecenter_get;

  OnSetParametersCallbackHandle::SharedPtr _handle;

  /**
   * @brief Thread for communication through modbus tcp.
   *
   */
  std::thread _thread;

/**
   * @brief Thread for communication through jsontcp.
   *
   */
  std::thread _jsontcpthread;

  std::thread _thread_parameterport;

  std::thread _thread_robotset;

  std::thread _threadforward;

  std::thread _ftpthread;


  bool b_jsontcpthread;
  bool b_threadforward;
};

void close_app(int s);
void* received(void * m);

void closeftp_app(int s);
void* ftpreceived(void * m);

}  // namespace modbus

#endif  // MODBUS__MODBUS_H
