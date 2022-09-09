#ifndef E2CAMMDATA_H
#define E2CAMMDATA_H

#include "fileout/tistdtypes.h"
#include "fileout/FileOut.h"
#include "float.h"

//分辨率设置
#define E2POOM_CAMER_SAVEBUFF              20
#define E2POOM_CAMER_SYSPATH_MOTO			"./SAVE/E2P_CAMER_DLG.bsd"

//分辨率设置
#define E2POOM_CAMER_SIZE_WIDTH_MIN         640      //相机最小横向分辨率
#define E2POOM_CAMER_SIZE_WIDTH_USE         1536     //相机默认横向分辨率
#define E2POOM_CAMER_SIZE_WIDTH_MAX         1536     //相机最大横向分辨率
#define E2POOM_CAMER_SIZE_HEIGHT_MIN        480      //相机最小纵向分辨率
#define E2POOM_CAMER_SIZE_HEIGHT_USE        1024     //相机默认纵向分辨率
#define E2POOM_CAMER_SIZE_HEIGHT_MAX        1024     //相机最大纵向分辨率    


class E2proomData
{
public:
    E2proomData();
    ~E2proomData();

    //相机分辨率参数
    Uint16 camer_size_width;    //相机横向分辨率
    Uint16 camer_size_height;   //相机纵向分辨率

    void write_camer_para();	//保存相机参数
    void init_camer_para();		//初始化相机参数

    Uint16 camer_size_width_min;
    Uint16 camer_size_width_max;
    Uint16 camer_size_width_use;
    Uint16 camer_size_height_min;
    Uint16 camer_size_height_max;
    Uint16 camer_size_height_use;

/****************************/
private:
    void read_para();				//读取
    void check_para();			//检查参数
};

#endif // E2PROOMDATA_H
