#include "fileout/E2proomData.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>  
#include <unistd.h>

void E2proomData::Init_als102_E2proomData()
{
    als102_pingjun_min=E2POOM_ALG102_LASERIMAGEPOS_PINGJUN_MIN;
    als102_pingjun_use=E2POOM_ALG102_LASERIMAGEPOS_PINGJUN_USE;
    als102_pingjun_max=E2POOM_ALG102_LASERIMAGEPOS_PINGJUN_MAX;
    als102_exposure_time_min=E2POOM_ALG102_LASERIMAGEPOS_EXPOSURE_TIME_MIN;
    als102_exposure_time_max=E2POOM_ALG102_LASERIMAGEPOS_EXPOSURE_TIME_MAX;
    als102_exposure_time_use=E2POOM_ALG102_LASERIMAGEPOS_EXPOSURE_TIME_USE;
    als102_b_yanmofuzhu_min=E2POOM_ALG102_LASERIMAGEPOS_B_YANMOFUZHU_MIN;
    als102_b_yanmofuzhu_use=E2POOM_ALG102_LASERIMAGEPOS_B_YANMOFUZHU_USE;
    als102_b_yanmofuzhu_max=E2POOM_ALG102_LASERIMAGEPOS_B_YANMOFUZHU_MAX;
    als102_b_gudingquyu_min=E2POOM_ALG102_LASERIMAGEPOS_B_GUDINGQUYU_MIN;
    als102_b_gudingquyu_use=E2POOM_ALG102_LASERIMAGEPOS_B_GUDINGQUYU_USE;
    als102_b_gudingquyu_max=E2POOM_ALG102_LASERIMAGEPOS_B_GUDINGQUYU_MAX;
    als102_widthliantongdis_min=E2POOM_ALG102_LASERIMAGEPOS_WIDTHLIANTONGDIS_MIN;
    als102_widthliantongdis_use=E2POOM_ALG102_LASERIMAGEPOS_WIDTHLIANTONGDIS_USE;
    als102_widthliantongdis_max=E2POOM_ALG102_LASERIMAGEPOS_WIDTHLIANTONGDIS_MAX;
    als102_highliantongdis_min=E2POOM_ALG102_LASERIMAGEPOS_HIGHLIANTONGDIS_MIN;
    als102_highliantongdis_use=E2POOM_ALG102_LASERIMAGEPOS_HIGHLIANTONGDIS_USE;
    als102_highliantongdis_max=E2POOM_ALG102_LASERIMAGEPOS_HIGHLIANTONGDIS_MAX;
    als102_gujiaerzhi_min=E2POOM_ALG102_LASERIMAGEPOS_GUJIAERZHI_MIN;
    als102_gujiaerzhi_use=E2POOM_ALG102_LASERIMAGEPOS_GUJIAERZHI_USE;
    als102_gujiaerzhi_max=E2POOM_ALG102_LASERIMAGEPOS_GUJIAERZHI_MAX;
    als102_jiguanghight_min=E2POOM_ALG102_LASERIMAGEPOS_JIGUANGHIGHT_MIN;
    als102_jiguanghight_use=E2POOM_ALG102_LASERIMAGEPOS_JIGUANGHIGHT_USE;
    als102_jiguanghight_max=E2POOM_ALG102_LASERIMAGEPOS_JIGUANGHIGHT_MAX;
    als102_jiguanglong_min=E2POOM_ALG102_LASERIMAGEPOS_JIGUANGLONG_MIN;
    als102_jiguanglong_use=E2POOM_ALG102_LASERIMAGEPOS_JIGUANGLONG_USE;
    als102_jiguanglong_max=E2POOM_ALG102_LASERIMAGEPOS_JIGUANGLONG_MAX;
    als102_jiguangkuandu_min=E2POOM_ALG102_LASERIMAGEPOS_JIGUANGKUANDU_MIN;
    als102_jiguangkuandu_use=E2POOM_ALG102_LASERIMAGEPOS_JIGUANGKUANDU_USE;
    als102_jiguangkuandu_max=E2POOM_ALG102_LASERIMAGEPOS_JIGUANGKUANDU_MAX;
    als102_Updif_min=E2POOM_ALG102_LASERIMAGEPOS_UPDIF_MIN;
    als102_Updif_use=E2POOM_ALG102_LASERIMAGEPOS_UPDIF_USE;
    als102_Updif_max=E2POOM_ALG102_LASERIMAGEPOS_UPDIF_MAX;
    als102_Updifmin_min=E2POOM_ALG102_LASERIMAGEPOS_UPDIFMIN_MIN;
    als102_Updifmin_use=E2POOM_ALG102_LASERIMAGEPOS_UPDIFMIN_USE;
    als102_Updifmin_max=E2POOM_ALG102_LASERIMAGEPOS_UPDIFMIN_MAX;
    als102_Uplong_min=E2POOM_ALG102_LASERIMAGEPOS_UPLONG_MIN;
    als102_Uplong_use=E2POOM_ALG102_LASERIMAGEPOS_UPLONG_USE;
    als102_Uplong_max=E2POOM_ALG102_LASERIMAGEPOS_UPLONG_MAX;
    als102_Downdif_min=E2POOM_ALG102_LASERIMAGEPOS_DOWNDIF_MIN;
    als102_Downdif_use=E2POOM_ALG102_LASERIMAGEPOS_DOWNDIF_USE;
    als102_Downdif_max=E2POOM_ALG102_LASERIMAGEPOS_DOWNDIF_MAX;
    als102_Downdifmin_min=E2POOM_ALG102_LASERIMAGEPOS_DOWNDIFMIN_MIN;
    als102_Downdifmin_use=E2POOM_ALG102_LASERIMAGEPOS_DOWNDIFMIN_USE;
    als102_Downdifmin_max=E2POOM_ALG102_LASERIMAGEPOS_DOWNDIFMIN_MAX;
    als102_Downdlong_min=E2POOM_ALG102_LASERIMAGEPOS_DOWNDLONG_MIN;
    als102_Downdlong_use=E2POOM_ALG102_LASERIMAGEPOS_DOWNDLONG_USE;
    als102_Downdlong_max=E2POOM_ALG102_LASERIMAGEPOS_DOWNDLONG_MAX;
    als102_duanxianerzhi_min=E2POOM_ALG102_LASERIMAGEPOS_DUANXIANERZHI_MIN;
    als102_duanxianerzhi_use=E2POOM_ALG102_LASERIMAGEPOS_DUANXIANERZHI_USE;
    als102_duanxianerzhi_max=E2POOM_ALG102_LASERIMAGEPOS_DUANXIANERZHI_MAX;
    als102_erzhisize_min=E2POOM_ALG102_LASERIMAGEPOS_ERZHISIZE_MIN;
    als102_erzhisize_use=E2POOM_ALG102_LASERIMAGEPOS_ERZHISIZE_USE;
    als102_erzhisize_max=E2POOM_ALG102_LASERIMAGEPOS_ERZHISIZE_MAX;
    als102_erzhisize2_min=E2POOM_ALG102_LASERIMAGEPOS_ERZHISIZE2_MIN;
    als102_erzhisize2_use=E2POOM_ALG102_LASERIMAGEPOS_ERZHISIZE2_USE;
    als102_erzhisize2_max=E2POOM_ALG102_LASERIMAGEPOS_ERZHISIZE2_MAX;
    als102_searchdectancemax_min=E2POOM_ALG102_LASERIMAGEPOS_SEARCHDECTANCEMAX_MIN;
    als102_searchdectancemax_use=E2POOM_ALG102_LASERIMAGEPOS_SEARCHDECTANCEMAX_USE;
    als102_searchdectancemax_max=E2POOM_ALG102_LASERIMAGEPOS_SEARCHDECTANCEMAX_MAX;
    als102_searchdectancemin_min=E2POOM_ALG102_LASERIMAGEPOS_SEARCHDECTANCEMIN_MIN;
    als102_searchdectancemin_use=E2POOM_ALG102_LASERIMAGEPOS_SEARCHDECTANCEMIN_USE;
    als102_searchdectancemin_max=E2POOM_ALG102_LASERIMAGEPOS_SEARCHDECTANCEMIN_MAX;
    als102_dis_center_st_min=E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ST_MIN;
    als102_dis_center_st_use=E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ST_USE;
    als102_dis_center_st_max=E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ST_MAX;
    als102_dis_center_ed_min=E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ED_MIN;
    als102_dis_center_ed_use=E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ED_USE;
    als102_dis_center_ed_max=E2POOM_ALG102_LASERIMAGEPOS_DIS_CENTER_ED_MAX;
}

void E2proomData::als102_check_para()
{
    if(als102_exposure_time<als102_exposure_time_min||als102_exposure_time>als102_exposure_time_max)
        als102_exposure_time=als102_exposure_time_use;
    if(als102_pingjun<als102_pingjun_min||als102_pingjun>als102_pingjun_max)
        als102_pingjun=als102_pingjun_use;
    if(als102_b_yanmofuzhu<als102_b_yanmofuzhu_min||als102_b_yanmofuzhu>als102_b_yanmofuzhu_max)
        als102_b_yanmofuzhu=als102_b_yanmofuzhu_use;
    if(als102_b_gudingquyu<als102_b_gudingquyu_min||als102_b_gudingquyu>als102_b_gudingquyu_max)
        als102_b_gudingquyu=als102_b_gudingquyu_use;
    if(als102_widthliantongdis<als102_widthliantongdis_min||als102_widthliantongdis>als102_widthliantongdis_max)
        als102_widthliantongdis=als102_widthliantongdis_use;
    if(als102_highliantongdis<als102_highliantongdis_min||als102_highliantongdis>als102_highliantongdis_max)
        als102_highliantongdis=als102_highliantongdis_use;
    if(als102_gujiaerzhi<als102_gujiaerzhi_min||als102_gujiaerzhi>als102_gujiaerzhi_max)
        als102_gujiaerzhi=als102_gujiaerzhi_use;
    if(als102_jiguanghight<als102_jiguanghight_min||als102_jiguanghight>als102_jiguanghight_max)
        als102_jiguanghight=als102_jiguanghight_use;
    if(als102_jiguanglong<als102_jiguanglong_min||als102_jiguanglong>als102_jiguanglong_max)
        als102_jiguanglong=als102_jiguanglong_use;
    if(als102_jiguangkuandu<als102_jiguangkuandu_min||als102_jiguangkuandu>als102_jiguangkuandu_max)
        als102_jiguangkuandu=als102_jiguangkuandu_use;
    if(als102_Updif<als102_Updif_min||als102_Updif>als102_Updif_max)
        als102_Updif=als102_Updif_use;
    if(als102_Updifmin<als102_Updifmin_min||als102_Updifmin>als102_Updifmin_max)
        als102_Updifmin=als102_Updifmin_use;
    if(als102_Uplong<als102_Uplong_min||als102_Uplong>als102_Uplong_max)
        als102_Uplong=als102_Uplong_use;
    if(als102_Downdif<als102_Downdif_min||als102_Downdif>als102_Downdif_max)
        als102_Downdif=als102_Downdif_use;
    if(als102_Downdifmin<als102_Downdifmin_min||als102_Downdifmin>als102_Downdifmin_max)
        als102_Downdifmin=als102_Downdifmin_use;
    if(als102_Downdlong<als102_Downdlong_min||als102_Downdlong>als102_Downdlong_max)
        als102_Downdlong=als102_Downdlong_use;    
    if(als102_duanxianerzhi<als102_duanxianerzhi_min||als102_duanxianerzhi>als102_duanxianerzhi_max)
        als102_duanxianerzhi=als102_duanxianerzhi_use;
    if(als102_erzhisize<als102_erzhisize_min||als102_erzhisize>als102_erzhisize_max)
        als102_erzhisize=als102_erzhisize_use;
    if(als102_erzhisize2<als102_erzhisize2_min||als102_erzhisize2>als102_erzhisize2_max)
        als102_erzhisize2=als102_erzhisize2_use;
    if(als102_searchdectancemax<als102_searchdectancemax_min||als102_searchdectancemax>als102_searchdectancemax_max)
        als102_searchdectancemax=als102_searchdectancemax_use;
    if(als102_searchdectancemin<als102_searchdectancemin_min||als102_searchdectancemin>als102_searchdectancemin_max)
        als102_searchdectancemin=als102_searchdectancemin_use;
    if(als102_dis_center_st<als102_dis_center_st_min||als102_dis_center_st>als102_dis_center_st_max)
        als102_dis_center_st=als102_dis_center_st_use;
    if(als102_dis_center_ed<als102_dis_center_ed_min||als102_dis_center_ed>als102_dis_center_ed_max)
        als102_dis_center_ed=als102_dis_center_ed_use;
}

void E2proomData::als102_read_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_ALG102_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(E2POOM_ALG102_LASERIMAGEPOS_SYSPATH_MOTO,buff,E2POOM_ALG102_LASERIMAGEPOS_SAVEBUFF))
    {
        init_als102_para();
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
      als102_exposure_time=*ui16_p;
      ui16_p++;
      i16_p = (Int16*)ui16_p;
      als102_pingjun=*i16_p;
      i16_p++;
      als102_b_yanmofuzhu=*i16_p;
      i16_p++;
      als102_b_gudingquyu=*i16_p;
      i16_p++;
      als102_widthliantongdis=*i16_p;
      i16_p++;
      als102_highliantongdis=*i16_p;
      i16_p++;
      als102_gujiaerzhi=*i16_p;
      i16_p++;
      als102_jiguanghight=*i16_p;
      i16_p++;
      als102_jiguanglong=*i16_p;
      i16_p++;
      als102_jiguangkuandu=*i16_p;
      i16_p++;
      als102_Updif=*i16_p;
      i16_p++;
      als102_Updifmin=*i16_p;
      i16_p++;
      als102_Uplong=*i16_p;
      i16_p++;
      als102_Downdif=*i16_p;
      i16_p++;
      als102_Downdifmin=*i16_p;
      i16_p++;
      als102_Downdlong=*i16_p;
      i16_p++;
      als102_duanxianerzhi=*i16_p;
      i16_p++;
      als102_erzhisize=*i16_p;
      i16_p++;
      als102_erzhisize2=*i16_p;
      i16_p++;
      als102_searchdectancemax=*i16_p;
      i16_p++;
      als102_searchdectancemin=*i16_p;
      i16_p++;
      als102_dis_center_st=*i16_p;
      i16_p++;
      als102_dis_center_ed=*i16_p;
      i16_p++;

    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

}

void E2proomData::write_als102_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_ALG102_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
      return;

    Uint16 *ui16_p;
    Int16 *i16_p;

    ui16_p = (Uint16*)buff;
    *ui16_p=als102_exposure_time;
    ui16_p++;
    i16_p = (Int16*)ui16_p;
    *i16_p=als102_pingjun;
    i16_p++;
    *i16_p=als102_b_yanmofuzhu;
    i16_p++;
    *i16_p=als102_b_gudingquyu;
    i16_p++;
    *i16_p=als102_widthliantongdis;
    i16_p++;
    *i16_p=als102_highliantongdis;
    i16_p++;
    *i16_p=als102_gujiaerzhi;
    i16_p++;
    *i16_p=als102_jiguanghight;
    i16_p++;
    *i16_p=als102_jiguanglong;
    i16_p++;
    *i16_p=als102_jiguangkuandu;
    i16_p++;
    *i16_p=als102_Updif;
    i16_p++;
    *i16_p=als102_Updifmin;
    i16_p++;
    *i16_p=als102_Uplong;
    i16_p++;
    *i16_p=als102_Downdif;
    i16_p++;
    *i16_p=als102_Downdifmin;
    i16_p++;
    *i16_p=als102_Downdlong;
    i16_p++;
    *i16_p=als102_duanxianerzhi;
    i16_p++;
    *i16_p=als102_erzhisize;
    i16_p++;
    *i16_p=als102_erzhisize2;
    i16_p++;
    *i16_p=als102_searchdectancemax;
    i16_p++;
    *i16_p=als102_searchdectancemin;
    i16_p++;
    *i16_p=als102_dis_center_st;
    i16_p++;
    *i16_p=als102_dis_center_ed;
    i16_p++;


    fo.WriteFile(E2POOM_ALG102_LASERIMAGEPOS_SYSPATH_MOTO,buff,E2POOM_ALG102_LASERIMAGEPOS_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_als102_para()
{
    als102_exposure_time=als102_exposure_time_use;
    als102_pingjun=als102_pingjun_use;
    als102_b_yanmofuzhu=als102_b_yanmofuzhu_use;
    als102_b_gudingquyu=als102_b_gudingquyu_use;
    als102_widthliantongdis=als102_widthliantongdis_use;
    als102_highliantongdis=als102_highliantongdis_use;
    als102_gujiaerzhi=als102_gujiaerzhi_use;
    als102_jiguanghight=als102_jiguanghight_use;
    als102_jiguanglong=als102_jiguanglong_use;
    als102_jiguangkuandu=als102_jiguangkuandu_use;
    als102_Updif=als102_Updif_use;
    als102_Updifmin=als102_Updifmin_use;
    als102_Uplong=als102_Uplong_use;
    als102_Downdif=als102_Downdif_use;
    als102_Downdifmin=als102_Downdifmin_use;
    als102_Downdlong=als102_Downdlong_use;
    als102_duanxianerzhi=als102_duanxianerzhi_use;
    als102_erzhisize=als102_erzhisize_use;
    als102_erzhisize2=als102_erzhisize2_use;
    als102_searchdectancemax=als102_searchdectancemax_use;
    als102_searchdectancemin=als102_searchdectancemin_use;
    als102_dis_center_st=als102_dis_center_st_use;
    als102_dis_center_ed=als102_dis_center_ed_use;
}