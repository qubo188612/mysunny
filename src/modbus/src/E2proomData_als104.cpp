#include "fileout/E2proomData.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>  
#include <unistd.h>

void E2proomData::Init_als104_E2proomData()
{
    als104_pingjun_min=E2POOM_ALG104_LASERIMAGEPOS_PINGJUN_MIN;
    als104_pingjun_use=E2POOM_ALG104_LASERIMAGEPOS_PINGJUN_USE;
    als104_pingjun_max=E2POOM_ALG104_LASERIMAGEPOS_PINGJUN_MAX;
    als104_exposure_time_min=E2POOM_ALG104_LASERIMAGEPOS_EXPOSURE_TIME_MIN;
    als104_exposure_time_max=E2POOM_ALG104_LASERIMAGEPOS_EXPOSURE_TIME_MAX;
    als104_exposure_time_use=E2POOM_ALG104_LASERIMAGEPOS_EXPOSURE_TIME_USE;
    als104_b_yanmofuzhu_min=E2POOM_ALG104_LASERIMAGEPOS_B_YANMOFUZHU_MIN;
    als104_b_yanmofuzhu_use=E2POOM_ALG104_LASERIMAGEPOS_B_YANMOFUZHU_USE;
    als104_b_yanmofuzhu_max=E2POOM_ALG104_LASERIMAGEPOS_B_YANMOFUZHU_MAX;
    als104_b_gudingquyu_min=E2POOM_ALG104_LASERIMAGEPOS_B_GUDINGQUYU_MIN;
    als104_b_gudingquyu_use=E2POOM_ALG104_LASERIMAGEPOS_B_GUDINGQUYU_USE;
    als104_b_gudingquyu_max=E2POOM_ALG104_LASERIMAGEPOS_B_GUDINGQUYU_MAX;
    als104_widthliantongdis_min=E2POOM_ALG104_LASERIMAGEPOS_WIDTHLIANTONGDIS_MIN;
    als104_widthliantongdis_use=E2POOM_ALG104_LASERIMAGEPOS_WIDTHLIANTONGDIS_USE;
    als104_widthliantongdis_max=E2POOM_ALG104_LASERIMAGEPOS_WIDTHLIANTONGDIS_MAX;
    als104_highliantongdis_min=E2POOM_ALG104_LASERIMAGEPOS_HIGHLIANTONGDIS_MIN;
    als104_highliantongdis_use=E2POOM_ALG104_LASERIMAGEPOS_HIGHLIANTONGDIS_USE;
    als104_highliantongdis_max=E2POOM_ALG104_LASERIMAGEPOS_HIGHLIANTONGDIS_MAX;
    als104_gujiaerzhi_min=E2POOM_ALG104_LASERIMAGEPOS_GUJIAERZHI_MIN;
    als104_gujiaerzhi_use=E2POOM_ALG104_LASERIMAGEPOS_GUJIAERZHI_USE;
    als104_gujiaerzhi_max=E2POOM_ALG104_LASERIMAGEPOS_GUJIAERZHI_MAX;
    als104_jiguanghight_min=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGHIGHT_MIN;
    als104_jiguanghight_use=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGHIGHT_USE;
    als104_jiguanghight_max=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGHIGHT_MAX;
    als104_jiguanglong_min=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGLONG_MIN;
    als104_jiguanglong_use=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGLONG_USE;
    als104_jiguanglong_max=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGLONG_MAX;
    als104_jiguangkuandu_min=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGKUANDU_MIN;
    als104_jiguangkuandu_use=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGKUANDU_USE;
    als104_jiguangkuandu_max=E2POOM_ALG104_LASERIMAGEPOS_JIGUANGKUANDU_MAX;
    als104_Updif_min=E2POOM_ALG104_LASERIMAGEPOS_UPDIF_MIN;
    als104_Updif_use=E2POOM_ALG104_LASERIMAGEPOS_UPDIF_USE;
    als104_Updif_max=E2POOM_ALG104_LASERIMAGEPOS_UPDIF_MAX;
    als104_Updifmin_min=E2POOM_ALG104_LASERIMAGEPOS_UPDIFMIN_MIN;
    als104_Updifmin_use=E2POOM_ALG104_LASERIMAGEPOS_UPDIFMIN_USE;
    als104_Updifmin_max=E2POOM_ALG104_LASERIMAGEPOS_UPDIFMIN_MAX;
    als104_Uplong_min=E2POOM_ALG104_LASERIMAGEPOS_UPLONG_MIN;
    als104_Uplong_use=E2POOM_ALG104_LASERIMAGEPOS_UPLONG_USE;
    als104_Uplong_max=E2POOM_ALG104_LASERIMAGEPOS_UPLONG_MAX;
    als104_Downdif_min=E2POOM_ALG104_LASERIMAGEPOS_DOWNDIF_MIN;
    als104_Downdif_use=E2POOM_ALG104_LASERIMAGEPOS_DOWNDIF_USE;
    als104_Downdif_max=E2POOM_ALG104_LASERIMAGEPOS_DOWNDIF_MAX;
    als104_Downdifmin_min=E2POOM_ALG104_LASERIMAGEPOS_DOWNDIFMIN_MIN;
    als104_Downdifmin_use=E2POOM_ALG104_LASERIMAGEPOS_DOWNDIFMIN_USE;
    als104_Downdifmin_max=E2POOM_ALG104_LASERIMAGEPOS_DOWNDIFMIN_MAX;
    als104_Downdlong_min=E2POOM_ALG104_LASERIMAGEPOS_DOWNDLONG_MIN;
    als104_Downdlong_use=E2POOM_ALG104_LASERIMAGEPOS_DOWNDLONG_USE;
    als104_Downdlong_max=E2POOM_ALG104_LASERIMAGEPOS_DOWNDLONG_MAX;
    als104_dis_center_st_min=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST_MIN;
    als104_dis_center_st_use=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST_USE;
    als104_dis_center_st_max=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ST_MAX;
    als104_dis_center_ed_min=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED_MIN;
    als104_dis_center_ed_use=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED_USE;
    als104_dis_center_ed_max=E2POOM_ALG104_LASERIMAGEPOS_DIS_CENTER_ED_MAX;
}

void E2proomData::als104_check_para()
{
    if(als104_exposure_time<als104_exposure_time_min||als104_exposure_time>als104_exposure_time_max)
        als104_exposure_time=als104_exposure_time_use;
    if(als104_pingjun<als104_pingjun_min||als104_pingjun>als104_pingjun_max)
        als104_pingjun=als104_pingjun_use;
    if(als104_b_yanmofuzhu<als104_b_yanmofuzhu_min||als104_b_yanmofuzhu>als104_b_yanmofuzhu_max)
        als104_b_yanmofuzhu=als104_b_yanmofuzhu_use;
    if(als104_b_gudingquyu<als104_b_gudingquyu_min||als104_b_gudingquyu>als104_b_gudingquyu_max)
        als104_b_gudingquyu=als104_b_gudingquyu_use;
    if(als104_widthliantongdis<als104_widthliantongdis_min||als104_widthliantongdis>als104_widthliantongdis_max)
        als104_widthliantongdis=als104_widthliantongdis_use;
    if(als104_highliantongdis<als104_highliantongdis_min||als104_highliantongdis>als104_highliantongdis_max)
        als104_highliantongdis=als104_highliantongdis_use;
    if(als104_gujiaerzhi<als104_gujiaerzhi_min||als104_gujiaerzhi>als104_gujiaerzhi_max)
        als104_gujiaerzhi=als104_gujiaerzhi_use;
    if(als104_jiguanghight<als104_jiguanghight_min||als104_jiguanghight>als104_jiguanghight_max)
        als104_jiguanghight=als104_jiguanghight_use;
    if(als104_jiguanglong<als104_jiguanglong_min||als104_jiguanglong>als104_jiguanglong_max)
        als104_jiguanglong=als104_jiguanglong_use;
    if(als104_jiguangkuandu<als104_jiguangkuandu_min||als104_jiguangkuandu>als104_jiguangkuandu_max)
        als104_jiguangkuandu=als104_jiguangkuandu_use;
    if(als104_Updif<als104_Updif_min||als104_Updif>als104_Updif_max)
        als104_Updif=als104_Updif_use;
    if(als104_Updifmin<als104_Updifmin_min||als104_Updifmin>als104_Updifmin_max)
        als104_Updifmin=als104_Updifmin_use;
    if(als104_Uplong<als104_Uplong_min||als104_Uplong>als104_Uplong_max)
        als104_Uplong=als104_Uplong_use;
    if(als104_Downdif<als104_Downdif_min||als104_Downdif>als104_Downdif_max)
        als104_Downdif=als104_Downdif_use;
    if(als104_Downdifmin<als104_Downdifmin_min||als104_Downdifmin>als104_Downdifmin_max)
        als104_Downdifmin=als104_Downdifmin_use;
    if(als104_Downdlong<als104_Downdlong_min||als104_Downdlong>als104_Downdlong_max)
        als104_Downdlong=als104_Downdlong_use;    
    if(als104_dis_center_st<als104_dis_center_st_min||als104_dis_center_st>als104_dis_center_st_max)
        als104_dis_center_st=als104_dis_center_st_use;
    if(als104_dis_center_ed<als104_dis_center_ed_min||als104_dis_center_ed>als104_dis_center_ed_max)
        als104_dis_center_ed=als104_dis_center_ed_use;
}

void E2proomData::als104_read_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_ALG104_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(filename,buff,E2POOM_ALG104_LASERIMAGEPOS_SAVEBUFF))
    {
        init_als104_para();
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
      als104_exposure_time=*ui16_p;
      ui16_p++;
      i16_p = (Int16*)ui16_p;
      als104_pingjun=*i16_p;
      i16_p++;
      als104_b_yanmofuzhu=*i16_p;
      i16_p++;
      als104_b_gudingquyu=*i16_p;
      i16_p++;
      als104_widthliantongdis=*i16_p;
      i16_p++;
      als104_highliantongdis=*i16_p;
      i16_p++;
      als104_gujiaerzhi=*i16_p;
      i16_p++;
      als104_jiguanghight=*i16_p;
      i16_p++;
      als104_jiguanglong=*i16_p;
      i16_p++;
      als104_jiguangkuandu=*i16_p;
      i16_p++;
      als104_Updif=*i16_p;
      i16_p++;
      als104_Updifmin=*i16_p;
      i16_p++;
      als104_Uplong=*i16_p;
      i16_p++;
      als104_Downdif=*i16_p;
      i16_p++;
      als104_Downdifmin=*i16_p;
      i16_p++;
      als104_Downdlong=*i16_p;
      i16_p++;
      als104_dis_center_st=*i16_p;
      i16_p++;
      als104_dis_center_ed=*i16_p;
      i16_p++;

    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

}

void E2proomData::write_als104_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_ALG104_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
      return;

    Uint16 *ui16_p;
    Int16 *i16_p;

    ui16_p = (Uint16*)buff;
    *ui16_p=als104_exposure_time;
    ui16_p++;
    i16_p = (Int16*)ui16_p;
    *i16_p=als104_pingjun;
    i16_p++;
    *i16_p=als104_b_yanmofuzhu;
    i16_p++;
    *i16_p=als104_b_gudingquyu;
    i16_p++;
    *i16_p=als104_widthliantongdis;
    i16_p++;
    *i16_p=als104_highliantongdis;
    i16_p++;
    *i16_p=als104_gujiaerzhi;
    i16_p++;
    *i16_p=als104_jiguanghight;
    i16_p++;
    *i16_p=als104_jiguanglong;
    i16_p++;
    *i16_p=als104_jiguangkuandu;
    i16_p++;
    *i16_p=als104_Updif;
    i16_p++;
    *i16_p=als104_Updifmin;
    i16_p++;
    *i16_p=als104_Uplong;
    i16_p++;
    *i16_p=als104_Downdif;
    i16_p++;
    *i16_p=als104_Downdifmin;
    i16_p++;
    *i16_p=als104_Downdlong;
    i16_p++;
    *i16_p=als104_dis_center_st;
    i16_p++;
    *i16_p=als104_dis_center_ed;
    i16_p++;


    fo.WriteFile(filename,buff,E2POOM_ALG104_LASERIMAGEPOS_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_als104_para()
{
    als104_exposure_time=als104_exposure_time_use;
    als104_pingjun=als104_pingjun_use;
    als104_b_yanmofuzhu=als104_b_yanmofuzhu_use;
    als104_b_gudingquyu=als104_b_gudingquyu_use;
    als104_widthliantongdis=als104_widthliantongdis_use;
    als104_highliantongdis=als104_highliantongdis_use;
    als104_gujiaerzhi=als104_gujiaerzhi_use;
    als104_jiguanghight=als104_jiguanghight_use;
    als104_jiguanglong=als104_jiguanglong_use;
    als104_jiguangkuandu=als104_jiguangkuandu_use;
    als104_Updif=als104_Updif_use;
    als104_Updifmin=als104_Updifmin_use;
    als104_Uplong=als104_Uplong_use;
    als104_Downdif=als104_Downdif_use;
    als104_Downdifmin=als104_Downdifmin_use;
    als104_Downdlong=als104_Downdlong_use;
    als104_dis_center_st=als104_dis_center_st_use;
    als104_dis_center_ed=als104_dis_center_ed_use;
}