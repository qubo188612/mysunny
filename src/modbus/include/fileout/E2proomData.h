#ifndef E2PROOMDATA_H
#define E2PROOMDATA_H

#include "fileout/tistdtypes.h"
#include "fileout/FileOut.h"
#include "float.h"

//机器人设置
#define E2POOM_ROBOT_SAVEBUFF              20
#define E2POOM_ROBOT_SYSPATH_MOTO			"./SAVE/E2P_ROBOT_DLG.bsd"

#define E2POOM_ROBOT_MOD_NULL               0        //无机器人
#define E2POOM_ROBOT_MOD_ZHICHANG           1        //智昌机器人
#define E2POOM_ROBOT_MOD_ZHICHANG_KAWASAKI  2        //智昌川崎机器人
#define E2POOM_ROBOT_MOD_MOKA_NABOTE        3        //摩卡纳博特机器人
#define E2POOM_ROBOT_PORT_MIN               1503     //机器人通信最小端口
#define E2POOM_ROBOT_PORT_USE               1503     //机器人通信默认端口
#define E2POOM_ROBOT_PORT_MAX               65535    //机器人通信最大端口


//算法100参数
#define E2POOM_ALG100_LASERIMAGEPOS_SAVEBUFF              20
#define E2POOM_ALG100_LASERIMAGEPOS_SYSPATH_MOTO			"./SAVE/E2P_MEASUREMENT_DLG.bsd"

#define E2POOM_ALG100_LASERIMAGEPOS_THRESHOLD_MIN				0         //显示模式最小值
#define E2POOM_ALG100_LASERIMAGEPOS_THRESHOLD_USE				120       //显示模式默认值   
#define E2POOM_ALG100_LASERIMAGEPOS_THRESHOLD_MAX				255       //显示模式最大值

class E2proomData
{
public:
    E2proomData();
    ~E2proomData();
/****************************/
    //机器人参数
    Uint16 robot_mod;           //机器人型号
    Uint16 robot_port;          //机器人端口

    void write_robot_para();				//保存机器人参数
    void init_robot_para();				//初始化机器人参数

    Uint16 robot_port_min;      //机器人端口最小值
    Uint16 robot_port_max;      //机器人端口最大值
    Uint16 robot_port_use;      //机器人端口默认值
/****************************/
    //任务100参数
    Int16 als100_threshold;  //显示模式

    void write_als100_para();				//保存任务100参数
    void init_als100_para();				//初始化任务100参数
    //默认参数
    Int16 als100_threshold_min;    //显示模式最小值
    Int16 als100_threshold_max;    //显示模式最大值
    Int16 als100_threshold_use;    //显示模式默认值


/****************************/
    void write();
private:
    void read_para();				//读取
    void check_para();			//检查参数
};

#endif // E2PROOMDATA_H
