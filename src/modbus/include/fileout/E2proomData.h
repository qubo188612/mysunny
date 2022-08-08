#ifndef E2PROOMDATA_H
#define E2PROOMDATA_H

#include "fileout/tistdtypes.h"
#include "fileout/FileOut.h"
#include "float.h"

//算法1页面参数
#define E2POOM_ALG1_LASERIMAGEPOS_SAVEBUFF              20
#define E2POOM_ALG1_LASERIMAGEPOS_SYSPATH_MOTO			"./SAVE/E2P_MEASUREMENT_DLG.bsd"

#define E2POOM_ALG1_LASERIMAGEPOS_THRESHOLD_MIN				0         //显示模式最小值
#define E2POOM_ALG1_LASERIMAGEPOS_THRESHOLD_USE				120       //显示模式默认值   
#define E2POOM_ALG1_LASERIMAGEPOS_THRESHOLD_MAX				255       //显示模式最大值

class E2proomData
{
public:
    E2proomData();
    ~E2proomData();

/****************************/
    //主页面参数
    Int16 als1_threshold;  //显示模式

    void write_als1_para();				//保存主页面参数
    void init_als1_para();				//初始化主页面参数
    //默认参数
    Int16 als1_threshold_min;    //显示模式最小值
    Int16 als1_threshold_max;    //显示模式最大值
    Int16 als1_threshold_use;    //显示模式默认值


/****************************/
    void write();
private:
    void read_para();				//读取
    void check_para();			//检查参数
};

#endif // E2PROOMDATA_H
