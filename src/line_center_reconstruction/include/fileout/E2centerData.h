#ifndef E2CAMMDATA_H
#define E2CAMMDATA_H

#include "fileout/tistdtypes.h"
#include "fileout/FileOut.h"
#include "float.h"

//分辨率设置
#define E2POOM_CENTER_SAVEBUFF              20
#define E2POOM_CENTER_SYSPATH_MOTO			"./SAVE/E2P_CENTER_DLG.bsd"

//分辨率设置

class E2proomData
{
public:
    E2proomData();
    ~E2proomData();

    //标定补偿参数
    Int16 compensation_dx;   //标定补偿X
    Int16 compensation_dy;   //标定补偿Y
    Int16 compensation_dz;   //标定补偿Z
    Int16 reverse_y;         //反向Y
    Int16 reverse_z;         //反向Z

    void write_center_para();	//保存补偿参数
    void init_center_para();		//初始化补偿参数

/****************************/
private:
    void read_para();				//读取
    void check_para();			//检查参数
};

#endif // E2PROOMDATA_H
