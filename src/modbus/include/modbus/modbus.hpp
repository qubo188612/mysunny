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
#include <modbus.h>
#include "fileout/E2proomData.h"

namespace modbus
{

#define SERVER_REGEDIST_NUM               400


#define ROBOT_SET_REGEDIST_NUM            10
#define ROBOT_MOD_REG_ADD                 0x0000
#define ROBOT_PORT_REG_ADD                0x0001


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

#define ALS102_INIT_REG_ADD                    0x005f

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

  void _task_numberset(u_int16_t num);

  void _task_parameter(int ddr,u_int16_t num);

  int als100_task_parameter(int ddr,u_int16_t num);
  int als101_task_parameter(int ddr,u_int16_t num);
  int als102_task_parameter(int ddr,u_int16_t num);
  void init_als100_parameter();
  void init_als101_parameter();
  void init_als102_parameter();

  void _task_robot(int ddr,u_int16_t num);

  E2proomData e2proomdata;
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

private:
  /**
   * @brief Parameter client for camera.
   *
   */
  std::shared_ptr<rclcpp::AsyncParametersClient> _param_camera;

  /**
   * @brief Parameter client for gpio.
   *
   */
  std::shared_ptr<rclcpp::AsyncParametersClient> _param_gpio;

  std::shared_ptr<rclcpp::AsyncParametersClient> _param_linecenter;

  std::shared_ptr<rclcpp::AsyncParametersClient> _param_laserimagepos;

  std::shared_ptr<rclcpp::AsyncParametersClient> _param_robotconfig;

 // OnSetParametersCallbackHandle::SharedPtr _handle;

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
};

void close_app(int s);
void* send_client(void * m);
void* received(void * m);

}  // namespace modbus

#endif  // MODBUS__MODBUS_H
