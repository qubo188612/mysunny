#include "fileout/E2proomData.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>  
#include <unistd.h>

void E2proomData::Init_als107_E2proomData()
{
    als107_pingjun_min=E2POOM_ALG107_LASERIMAGEPOS_PINGJUN_MIN;
    als107_pingjun_use=E2POOM_ALG107_LASERIMAGEPOS_PINGJUN_USE;
    als107_pingjun_max=E2POOM_ALG107_LASERIMAGEPOS_PINGJUN_MAX;
    als107_exposure_time_min=E2POOM_ALG107_LASERIMAGEPOS_EXPOSURE_TIME_MIN;
    als107_exposure_time_max=E2POOM_ALG107_LASERIMAGEPOS_EXPOSURE_TIME_MAX;
    als107_exposure_time_use=E2POOM_ALG107_LASERIMAGEPOS_EXPOSURE_TIME_USE;
    als107_b_yanmofuzhu_min=E2POOM_ALG107_LASERIMAGEPOS_B_YANMOFUZHU_MIN;
    als107_b_yanmofuzhu_use=E2POOM_ALG107_LASERIMAGEPOS_B_YANMOFUZHU_USE;
    als107_b_yanmofuzhu_max=E2POOM_ALG107_LASERIMAGEPOS_B_YANMOFUZHU_MAX;
    als107_b_gudingquyu_min=E2POOM_ALG107_LASERIMAGEPOS_B_GUDINGQUYU_MIN;
    als107_b_gudingquyu_use=E2POOM_ALG107_LASERIMAGEPOS_B_GUDINGQUYU_USE;
    als107_b_gudingquyu_max=E2POOM_ALG107_LASERIMAGEPOS_B_GUDINGQUYU_MAX;
    als107_widthliantongdis_min=E2POOM_ALG107_LASERIMAGEPOS_WIDTHLIANTONGDIS_MIN;
    als107_widthliantongdis_use=E2POOM_ALG107_LASERIMAGEPOS_WIDTHLIANTONGDIS_USE;
    als107_widthliantongdis_max=E2POOM_ALG107_LASERIMAGEPOS_WIDTHLIANTONGDIS_MAX;
    als107_highliantongdis_min=E2POOM_ALG107_LASERIMAGEPOS_HIGHLIANTONGDIS_MIN;
    als107_highliantongdis_use=E2POOM_ALG107_LASERIMAGEPOS_HIGHLIANTONGDIS_USE;
    als107_highliantongdis_max=E2POOM_ALG107_LASERIMAGEPOS_HIGHLIANTONGDIS_MAX;
    als107_gujiaerzhi_min=E2POOM_ALG107_LASERIMAGEPOS_GUJIAERZHI_MIN;
    als107_gujiaerzhi_use=E2POOM_ALG107_LASERIMAGEPOS_GUJIAERZHI_USE;
    als107_gujiaerzhi_max=E2POOM_ALG107_LASERIMAGEPOS_GUJIAERZHI_MAX;
    als107_jiguanghight_min=E2POOM_ALG107_LASERIMAGEPOS_JIGUANGHIGHT_MIN;
    als107_jiguanghight_use=E2POOM_ALG107_LASERIMAGEPOS_JIGUANGHIGHT_USE;
    als107_jiguanghight_max=E2POOM_ALG107_LASERIMAGEPOS_JIGUANGHIGHT_MAX;
    als107_jiguanglong_min=E2POOM_ALG107_LASERIMAGEPOS_JIGUANGLONG_MIN;
    als107_jiguanglong_use=E2POOM_ALG107_LASERIMAGEPOS_JIGUANGLONG_USE;
    als107_jiguanglong_max=E2POOM_ALG107_LASERIMAGEPOS_JIGUANGLONG_MAX;
    als107_jiguangkuandu_min=E2POOM_ALG107_LASERIMAGEPOS_JIGUANGKUANDU_MIN;
    als107_jiguangkuandu_use=E2POOM_ALG107_LASERIMAGEPOS_JIGUANGKUANDU_USE;
    als107_jiguangkuandu_max=E2POOM_ALG107_LASERIMAGEPOS_JIGUANGKUANDU_MAX;
    als107_Updif_min=E2POOM_ALG107_LASERIMAGEPOS_UPDIF_MIN;
    als107_Updif_use=E2POOM_ALG107_LASERIMAGEPOS_UPDIF_USE;
    als107_Updif_max=E2POOM_ALG107_LASERIMAGEPOS_UPDIF_MAX;
    als107_Updifmin_min=E2POOM_ALG107_LASERIMAGEPOS_UPDIFMIN_MIN;
    als107_Updifmin_use=E2POOM_ALG107_LASERIMAGEPOS_UPDIFMIN_USE;
    als107_Updifmin_max=E2POOM_ALG107_LASERIMAGEPOS_UPDIFMIN_MAX;
    als107_Uplong_min=E2POOM_ALG107_LASERIMAGEPOS_UPLONG_MIN;
    als107_Uplong_use=E2POOM_ALG107_LASERIMAGEPOS_UPLONG_USE;
    als107_Uplong_max=E2POOM_ALG107_LASERIMAGEPOS_UPLONG_MAX;
    als107_Downdif_min=E2POOM_ALG107_LASERIMAGEPOS_DOWNDIF_MIN;
    als107_Downdif_use=E2POOM_ALG107_LASERIMAGEPOS_DOWNDIF_USE;
    als107_Downdif_max=E2POOM_ALG107_LASERIMAGEPOS_DOWNDIF_MAX;
    als107_Downdifmin_min=E2POOM_ALG107_LASERIMAGEPOS_DOWNDIFMIN_MIN;
    als107_Downdifmin_use=E2POOM_ALG107_LASERIMAGEPOS_DOWNDIFMIN_USE;
    als107_Downdifmin_max=E2POOM_ALG107_LASERIMAGEPOS_DOWNDIFMIN_MAX;
    als107_Downdlong_min=E2POOM_ALG107_LASERIMAGEPOS_DOWNDLONG_MIN;
    als107_Downdlong_use=E2POOM_ALG107_LASERIMAGEPOS_DOWNDLONG_USE;
    als107_Downdlong_max=E2POOM_ALG107_LASERIMAGEPOS_DOWNDLONG_MAX;
    als107_St_Down_min=E2POOM_ALG107_LASERIMAGEPOS_ST_DOWN_MIN;
    als107_St_Down_use=E2POOM_ALG107_LASERIMAGEPOS_ST_DOWN_USE;
    als107_St_Down_max=E2POOM_ALG107_LASERIMAGEPOS_ST_DOWN_MAX;
    als107_Ed_Down_min=E2POOM_ALG107_LASERIMAGEPOS_ED_DOWN_MIN;
    als107_Ed_Down_use=E2POOM_ALG107_LASERIMAGEPOS_ED_DOWN_USE;
    als107_Ed_Down_max=E2POOM_ALG107_LASERIMAGEPOS_ED_DOWN_MAX;
    als107_St_Up_min=E2POOM_ALG107_LASERIMAGEPOS_ST_UP_MIN;
    als107_St_Up_use=E2POOM_ALG107_LASERIMAGEPOS_ST_UP_USE;
    als107_St_Up_max=E2POOM_ALG107_LASERIMAGEPOS_ST_UP_MAX;
    als107_Ed_Up_min=E2POOM_ALG107_LASERIMAGEPOS_ED_UP_MIN;
    als107_Ed_Up_use=E2POOM_ALG107_LASERIMAGEPOS_ED_UP_USE;
    als107_Ed_Up_max=E2POOM_ALG107_LASERIMAGEPOS_ED_UP_MAX;
    als107_dis_center_st_min=E2POOM_ALG107_LASERIMAGEPOS_DIS_CENTER_ST_MIN;
    als107_dis_center_st_use=E2POOM_ALG107_LASERIMAGEPOS_DIS_CENTER_ST_USE;
    als107_dis_center_st_max=E2POOM_ALG107_LASERIMAGEPOS_DIS_CENTER_ST_MAX;
    als107_dis_center_st2_min=E2POOM_ALG107_LASERIMAGEPOS_DIS_CENTER_ST2_MIN;   
    als107_dis_center_st2_max=E2POOM_ALG107_LASERIMAGEPOS_DIS_CENTER_ST2_MAX;  
    als107_dis_center_st2_use=E2POOM_ALG107_LASERIMAGEPOS_DIS_CENTER_ST2_USE;
    als107_dis_center_ed2_min=E2POOM_ALG107_LASERIMAGEPOS_DIS_CENTER_ED2_MIN;   
    als107_dis_center_ed2_max=E2POOM_ALG107_LASERIMAGEPOS_DIS_CENTER_ED2_MAX;  
    als107_dis_center_ed2_use=E2POOM_ALG107_LASERIMAGEPOS_DIS_CENTER_ED2_USE;
    als107_b_KalmanFilter_min=E2POOM_ALG107_LASERIMAGEPOS_B_KALMANFILTER_MIN;
    als107_b_KalmanFilter_max=E2POOM_ALG107_LASERIMAGEPOS_B_KALMANFILTER_MAX;
    als107_b_KalmanFilter_use=E2POOM_ALG107_LASERIMAGEPOS_B_KALMANFILTER_USE;
    als107_KalmanQF_min=E2POOM_ALG107_LASERIMAGEPOS_KALMANQF_MIN;
    als107_KalmanQF_max=E2POOM_ALG107_LASERIMAGEPOS_KALMANQF_MAX;
    als107_KalmanQF_use=E2POOM_ALG107_LASERIMAGEPOS_KALMANQF_USE;
    als107_KalmanRF_min=E2POOM_ALG107_LASERIMAGEPOS_KALMANRF_MIN;
    als107_KalmanRF_max=E2POOM_ALG107_LASERIMAGEPOS_KALMANRF_MAX;
    als107_KalmanRF_use=E2POOM_ALG107_LASERIMAGEPOS_KALMANRF_USE;
}

void E2proomData::als107_check_para()
{
    if(als107_exposure_time<als107_exposure_time_min||als107_exposure_time>als107_exposure_time_max)
        als107_exposure_time=als107_exposure_time_use;
    if(als107_pingjun<als107_pingjun_min||als107_pingjun>als107_pingjun_max)
        als107_pingjun=als107_pingjun_use;
    if(als107_b_yanmofuzhu<als107_b_yanmofuzhu_min||als107_b_yanmofuzhu>als107_b_yanmofuzhu_max)
        als107_b_yanmofuzhu=als107_b_yanmofuzhu_use;
    if(als107_b_gudingquyu<als107_b_gudingquyu_min||als107_b_gudingquyu>als107_b_gudingquyu_max)
        als107_b_gudingquyu=als107_b_gudingquyu_use;
    if(als107_widthliantongdis<als107_widthliantongdis_min||als107_widthliantongdis>als107_widthliantongdis_max)
        als107_widthliantongdis=als107_widthliantongdis_use;
    if(als107_highliantongdis<als107_highliantongdis_min||als107_highliantongdis>als107_highliantongdis_max)
        als107_highliantongdis=als107_highliantongdis_use;
    if(als107_gujiaerzhi<als107_gujiaerzhi_min||als107_gujiaerzhi>als107_gujiaerzhi_max)
        als107_gujiaerzhi=als107_gujiaerzhi_use;
    if(als107_jiguanghight<als107_jiguanghight_min||als107_jiguanghight>als107_jiguanghight_max)
        als107_jiguanghight=als107_jiguanghight_use;
    if(als107_jiguanglong<als107_jiguanglong_min||als107_jiguanglong>als107_jiguanglong_max)
        als107_jiguanglong=als107_jiguanglong_use;
    if(als107_jiguangkuandu<als107_jiguangkuandu_min||als107_jiguangkuandu>als107_jiguangkuandu_max)
        als107_jiguangkuandu=als107_jiguangkuandu_use;
    if(als107_Updif<als107_Updif_min||als107_Updif>als107_Updif_max)
        als107_Updif=als107_Updif_use;
    if(als107_Updifmin<als107_Updifmin_min||als107_Updifmin>als107_Updifmin_max)
        als107_Updifmin=als107_Updifmin_use;
    if(als107_Uplong<als107_Uplong_min||als107_Uplong>als107_Uplong_max)
        als107_Uplong=als107_Uplong_use;
    if(als107_Downdif<als107_Downdif_min||als107_Downdif>als107_Downdif_max)
        als107_Downdif=als107_Downdif_use;
    if(als107_Downdifmin<als107_Downdifmin_min||als107_Downdifmin>als107_Downdifmin_max)
        als107_Downdifmin=als107_Downdifmin_use;
    if(als107_Downdlong<als107_Downdlong_min||als107_Downdlong>als107_Downdlong_max)
        als107_Downdlong=als107_Downdlong_use;    
    if(als107_St_Down<als107_St_Down_min||als107_St_Down>als107_St_Down_max)
        als107_St_Down=als107_St_Down_use;
    if(als107_Ed_Down<als107_Ed_Down_min||als107_Ed_Down>als107_Ed_Down_max)
        als107_Ed_Down=als107_Ed_Down_use;
    if(als107_St_Up<als107_St_Up_min||als107_St_Up>als107_St_Up_max)
        als107_St_Up=als107_St_Up_use;
    if(als107_Ed_Up<als107_Ed_Up_min||als107_Ed_Up>als107_Ed_Up_max)
        als107_Ed_Up=als107_Ed_Up_use;
    if(als107_dis_center_st<als107_dis_center_st_min||als107_dis_center_st>als107_dis_center_st_max)
        als107_dis_center_st=als107_dis_center_st_use;
    if(als107_dis_center_st2<als107_dis_center_st2_min||als107_dis_center_st2>als107_dis_center_st2_max)
        als107_dis_center_st2=als107_dis_center_st2_use;
    if(als107_dis_center_ed2<als107_dis_center_ed2_min||als107_dis_center_ed2>als107_dis_center_ed2_max)
        als107_dis_center_ed2=als107_dis_center_ed2_use;
    if(als107_b_KalmanFilter<als107_b_KalmanFilter_min||als107_b_KalmanFilter>als107_b_KalmanFilter_max)
        als107_b_KalmanFilter=als107_b_KalmanFilter_use;
    if(als107_KalmanQF<als107_KalmanQF_min||als107_KalmanQF>als107_KalmanQF_max)
        als107_KalmanQF=als107_KalmanQF_use;
    if(als107_KalmanRF<als107_KalmanRF_min||als107_KalmanRF>als107_KalmanRF_max)
        als107_KalmanRF=als107_KalmanRF_use;
}

void E2proomData::als107_read_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_ALG107_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(filename,buff,E2POOM_ALG107_LASERIMAGEPOS_SAVEBUFF))
    {
        init_als107_para();
        if(buff!=NULL)
        {
          delete []buff;
          buff=NULL;
        }
    }
    else
    {
      Uint16 *ui16_p;
      Int16 *i16_p;

      ui16_p = (Uint16*)buff;
      als107_exposure_time=*ui16_p;
      ui16_p++;
      i16_p = (Int16*)ui16_p;
      als107_pingjun=*i16_p;
      i16_p++;
      als107_b_yanmofuzhu=*i16_p;
      i16_p++;
      als107_b_gudingquyu=*i16_p;
      i16_p++;
      als107_widthliantongdis=*i16_p;
      i16_p++;
      als107_highliantongdis=*i16_p;
      i16_p++;
      als107_gujiaerzhi=*i16_p;
      i16_p++;
      als107_jiguanghight=*i16_p;
      i16_p++;
      als107_jiguanglong=*i16_p;
      i16_p++;
      als107_jiguangkuandu=*i16_p;
      i16_p++;
      als107_Updif=*i16_p;
      i16_p++;
      als107_Updifmin=*i16_p;
      i16_p++;
      als107_Uplong=*i16_p;
      i16_p++;
      als107_Downdif=*i16_p;
      i16_p++;
      als107_Downdifmin=*i16_p;
      i16_p++;
      als107_Downdlong=*i16_p;
      i16_p++;
      als107_St_Down=*i16_p;
      i16_p++;
      als107_Ed_Down=*i16_p;
      i16_p++;
      als107_St_Up=*i16_p;
      i16_p++;
      als107_Ed_Up=*i16_p;
      i16_p++;
      als107_dis_center_st=*i16_p;
      i16_p++;
      als107_dis_center_st2=*i16_p;
      i16_p++;
      als107_dis_center_ed2=*i16_p;
      i16_p++;
      als107_b_KalmanFilter=*i16_p;
      i16_p++;
      als107_KalmanQF=*i16_p;
      i16_p++;
      als107_KalmanRF=*i16_p;
      i16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

}

void E2proomData::write_als107_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_ALG107_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
      return;

    Uint16 *ui16_p;
    Int16 *i16_p;

    ui16_p = (Uint16*)buff;
    *ui16_p=als107_exposure_time;
    ui16_p++;
    i16_p = (Int16*)ui16_p;
    *i16_p=als107_pingjun;
    i16_p++;
    *i16_p=als107_b_yanmofuzhu;
    i16_p++;
    *i16_p=als107_b_gudingquyu;
    i16_p++;
    *i16_p=als107_widthliantongdis;
    i16_p++;
    *i16_p=als107_highliantongdis;
    i16_p++;
    *i16_p=als107_gujiaerzhi;
    i16_p++;
    *i16_p=als107_jiguanghight;
    i16_p++;
    *i16_p=als107_jiguanglong;
    i16_p++;
    *i16_p=als107_jiguangkuandu;
    i16_p++;
    *i16_p=als107_Updif;
    i16_p++;
    *i16_p=als107_Updifmin;
    i16_p++;
    *i16_p=als107_Uplong;
    i16_p++;
    *i16_p=als107_Downdif;
    i16_p++;
    *i16_p=als107_Downdifmin;
    i16_p++;
    *i16_p=als107_Downdlong;
    i16_p++;
    *i16_p=als107_St_Down;
    i16_p++;
    *i16_p=als107_Ed_Down;
    i16_p++;
    *i16_p=als107_St_Up;
    i16_p++;
    *i16_p=als107_Ed_Up;
    i16_p++;
    *i16_p=als107_dis_center_st;
    i16_p++;
    *i16_p=als107_dis_center_st2;
    i16_p++;
    *i16_p=als107_dis_center_ed2;
    i16_p++;
    *i16_p=als107_b_KalmanFilter;
    i16_p++;
    *i16_p=als107_KalmanQF;
    i16_p++;
    *i16_p=als107_KalmanRF;
    i16_p++;

    fo.WriteFile(filename,buff,E2POOM_ALG107_LASERIMAGEPOS_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_als107_para()
{
    als107_exposure_time=als107_exposure_time_use;
    als107_pingjun=als107_pingjun_use;
    als107_b_yanmofuzhu=als107_b_yanmofuzhu_use;
    als107_b_gudingquyu=als107_b_gudingquyu_use;
    als107_widthliantongdis=als107_widthliantongdis_use;
    als107_highliantongdis=als107_highliantongdis_use;
    als107_gujiaerzhi=als107_gujiaerzhi_use;
    als107_jiguanghight=als107_jiguanghight_use;
    als107_jiguanglong=als107_jiguanglong_use;
    als107_jiguangkuandu=als107_jiguangkuandu_use;
    als107_Updif=als107_Updif_use;
    als107_Updifmin=als107_Updifmin_use;
    als107_Uplong=als107_Uplong_use;
    als107_Downdif=als107_Downdif_use;
    als107_Downdifmin=als107_Downdifmin_use;
    als107_Downdlong=als107_Downdlong_use;
    als107_St_Down=als107_St_Down_use;
    als107_Ed_Down=als107_Ed_Down_use;
    als107_St_Up=als107_St_Up_use;
    als107_Ed_Up=als107_Ed_Up_use;
    als107_dis_center_st=als107_dis_center_st_use;
    als107_dis_center_st2=als107_dis_center_st2_use;
    als107_dis_center_ed2=als107_dis_center_ed2_use;
    als107_b_KalmanFilter=als107_b_KalmanFilter_use;
    als107_KalmanQF=als107_KalmanQF_use;
    als107_KalmanRF=als107_KalmanRF_use;
}