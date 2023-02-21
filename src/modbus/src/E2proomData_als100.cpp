#include "fileout/E2proomData.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>  
#include <unistd.h>

void E2proomData::Init_als100_E2proomData()
{
    als100_pingjun_min=E2POOM_ALG100_LASERIMAGEPOS_PINGJUN_MIN;
    als100_pingjun_use=E2POOM_ALG100_LASERIMAGEPOS_PINGJUN_USE;
    als100_pingjun_max=E2POOM_ALG100_LASERIMAGEPOS_PINGJUN_MAX;
    als100_exposure_time_min=E2POOM_ALG100_LASERIMAGEPOS_EXPOSURE_TIME_MIN;
    als100_exposure_time_max=E2POOM_ALG100_LASERIMAGEPOS_EXPOSURE_TIME_MAX;
    als100_exposure_time_use=E2POOM_ALG100_LASERIMAGEPOS_EXPOSURE_TIME_USE;
    als100_b_yanmofuzhu_min=E2POOM_ALG100_LASERIMAGEPOS_B_YANMOFUZHU_MIN;
    als100_b_yanmofuzhu_use=E2POOM_ALG100_LASERIMAGEPOS_B_YANMOFUZHU_USE;
    als100_b_yanmofuzhu_max=E2POOM_ALG100_LASERIMAGEPOS_B_YANMOFUZHU_MAX;
    als100_b_gudingquyu_min=E2POOM_ALG100_LASERIMAGEPOS_B_GUDINGQUYU_MIN;
    als100_b_gudingquyu_use=E2POOM_ALG100_LASERIMAGEPOS_B_GUDINGQUYU_USE;
    als100_b_gudingquyu_max=E2POOM_ALG100_LASERIMAGEPOS_B_GUDINGQUYU_MAX;
    als100_widthliantongdis_min=E2POOM_ALG100_LASERIMAGEPOS_WIDTHLIANTONGDIS_MIN;
    als100_widthliantongdis_use=E2POOM_ALG100_LASERIMAGEPOS_WIDTHLIANTONGDIS_USE;
    als100_widthliantongdis_max=E2POOM_ALG100_LASERIMAGEPOS_WIDTHLIANTONGDIS_MAX;
    als100_highliantongdis_min=E2POOM_ALG100_LASERIMAGEPOS_HIGHLIANTONGDIS_MIN;
    als100_highliantongdis_use=E2POOM_ALG100_LASERIMAGEPOS_HIGHLIANTONGDIS_USE;
    als100_highliantongdis_max=E2POOM_ALG100_LASERIMAGEPOS_HIGHLIANTONGDIS_MAX;
    als100_gujiaerzhi_min=E2POOM_ALG100_LASERIMAGEPOS_GUJIAERZHI_MIN;
    als100_gujiaerzhi_use=E2POOM_ALG100_LASERIMAGEPOS_GUJIAERZHI_USE;
    als100_gujiaerzhi_max=E2POOM_ALG100_LASERIMAGEPOS_GUJIAERZHI_MAX;
    als100_jiguanghight_min=E2POOM_ALG100_LASERIMAGEPOS_JIGUANGHIGHT_MIN;
    als100_jiguanghight_use=E2POOM_ALG100_LASERIMAGEPOS_JIGUANGHIGHT_USE;
    als100_jiguanghight_max=E2POOM_ALG100_LASERIMAGEPOS_JIGUANGHIGHT_MAX;
    als100_jiguanglong_min=E2POOM_ALG100_LASERIMAGEPOS_JIGUANGLONG_MIN;
    als100_jiguanglong_use=E2POOM_ALG100_LASERIMAGEPOS_JIGUANGLONG_USE;
    als100_jiguanglong_max=E2POOM_ALG100_LASERIMAGEPOS_JIGUANGLONG_MAX;
    als100_jiguangkuandu_min=E2POOM_ALG100_LASERIMAGEPOS_JIGUANGKUANDU_MIN;
    als100_jiguangkuandu_use=E2POOM_ALG100_LASERIMAGEPOS_JIGUANGKUANDU_USE;
    als100_jiguangkuandu_max=E2POOM_ALG100_LASERIMAGEPOS_JIGUANGKUANDU_MAX;
    als100_Updif_min=E2POOM_ALG100_LASERIMAGEPOS_UPDIF_MIN;
    als100_Updif_use=E2POOM_ALG100_LASERIMAGEPOS_UPDIF_USE;
    als100_Updif_max=E2POOM_ALG100_LASERIMAGEPOS_UPDIF_MAX;
    als100_Updifmin_min=E2POOM_ALG100_LASERIMAGEPOS_UPDIFMIN_MIN;
    als100_Updifmin_use=E2POOM_ALG100_LASERIMAGEPOS_UPDIFMIN_USE;
    als100_Updifmin_max=E2POOM_ALG100_LASERIMAGEPOS_UPDIFMIN_MAX;
    als100_Uplong_min=E2POOM_ALG100_LASERIMAGEPOS_UPLONG_MIN;
    als100_Uplong_use=E2POOM_ALG100_LASERIMAGEPOS_UPLONG_USE;
    als100_Uplong_max=E2POOM_ALG100_LASERIMAGEPOS_UPLONG_MAX;
    als100_Downdif_min=E2POOM_ALG100_LASERIMAGEPOS_DOWNDIF_MIN;
    als100_Downdif_use=E2POOM_ALG100_LASERIMAGEPOS_DOWNDIF_USE;
    als100_Downdif_max=E2POOM_ALG100_LASERIMAGEPOS_DOWNDIF_MAX;
    als100_Downdifmin_min=E2POOM_ALG100_LASERIMAGEPOS_DOWNDIFMIN_MIN;
    als100_Downdifmin_use=E2POOM_ALG100_LASERIMAGEPOS_DOWNDIFMIN_USE;
    als100_Downdifmin_max=E2POOM_ALG100_LASERIMAGEPOS_DOWNDIFMIN_MAX;
    als100_Downdlong_min=E2POOM_ALG100_LASERIMAGEPOS_DOWNDLONG_MIN;
    als100_Downdlong_use=E2POOM_ALG100_LASERIMAGEPOS_DOWNDLONG_USE;
    als100_Downdlong_max=E2POOM_ALG100_LASERIMAGEPOS_DOWNDLONG_MAX;
    als100_duanxianerzhi_min=E2POOM_ALG100_LASERIMAGEPOS_DUANXIANERZHI_MIN;
    als100_duanxianerzhi_use=E2POOM_ALG100_LASERIMAGEPOS_DUANXIANERZHI_USE;
    als100_duanxianerzhi_max=E2POOM_ALG100_LASERIMAGEPOS_DUANXIANERZHI_MAX;
    als100_erzhisize_min=E2POOM_ALG100_LASERIMAGEPOS_ERZHISIZE_MIN;
    als100_erzhisize_use=E2POOM_ALG100_LASERIMAGEPOS_ERZHISIZE_USE;
    als100_erzhisize_max=E2POOM_ALG100_LASERIMAGEPOS_ERZHISIZE_MAX;
    als100_erzhisize2_min=E2POOM_ALG100_LASERIMAGEPOS_ERZHISIZE2_MIN;
    als100_erzhisize2_use=E2POOM_ALG100_LASERIMAGEPOS_ERZHISIZE2_USE;
    als100_erzhisize2_max=E2POOM_ALG100_LASERIMAGEPOS_ERZHISIZE2_MAX;
    als100_searchdectancemax_min=E2POOM_ALG100_LASERIMAGEPOS_SEARCHDECTANCEMAX_MIN;
    als100_searchdectancemax_use=E2POOM_ALG100_LASERIMAGEPOS_SEARCHDECTANCEMAX_USE;
    als100_searchdectancemax_max=E2POOM_ALG100_LASERIMAGEPOS_SEARCHDECTANCEMAX_MAX;
    als100_searchdectancemin_min=E2POOM_ALG100_LASERIMAGEPOS_SEARCHDECTANCEMIN_MIN;
    als100_searchdectancemin_use=E2POOM_ALG100_LASERIMAGEPOS_SEARCHDECTANCEMIN_USE;
    als100_searchdectancemin_max=E2POOM_ALG100_LASERIMAGEPOS_SEARCHDECTANCEMIN_MAX;
    als100_dis_center_st_min=E2POOM_ALG100_LASERIMAGEPOS_DIS_CENTER_ST_MIN;
    als100_dis_center_st_use=E2POOM_ALG100_LASERIMAGEPOS_DIS_CENTER_ST_USE;
    als100_dis_center_st_max=E2POOM_ALG100_LASERIMAGEPOS_DIS_CENTER_ST_MAX;
    als100_dis_center_ed_min=E2POOM_ALG100_LASERIMAGEPOS_DIS_CENTER_ED_MIN;
    als100_dis_center_ed_use=E2POOM_ALG100_LASERIMAGEPOS_DIS_CENTER_ED_USE;
    als100_dis_center_ed_max=E2POOM_ALG100_LASERIMAGEPOS_DIS_CENTER_ED_MAX;
    als100_answerpoint_min=E2POOM_ALG100_LASERIMAGEPOS_ANSWERPOINT_MIN;
    als100_answerpoint_use=E2POOM_ALG100_LASERIMAGEPOS_ANSWERPOINT_USE;
    als100_answerpoint_max=E2POOM_ALG100_LASERIMAGEPOS_ANSWERPOINT_MAX;
}

void E2proomData::als100_check_para()
{
    if(als100_exposure_time<als100_exposure_time_min||als100_exposure_time>als100_exposure_time_max)
        als100_exposure_time=als100_exposure_time_use;
    if(als100_pingjun<als100_pingjun_min||als100_pingjun>als100_pingjun_max)
        als100_pingjun=als100_pingjun_use;
    if(als100_b_yanmofuzhu<als100_b_yanmofuzhu_min||als100_b_yanmofuzhu>als100_b_yanmofuzhu_max)
        als100_b_yanmofuzhu=als100_b_yanmofuzhu_use;
    if(als100_b_gudingquyu<als100_b_gudingquyu_min||als100_b_gudingquyu>als100_b_gudingquyu_max)
        als100_b_gudingquyu=als100_b_gudingquyu_use;
    if(als100_widthliantongdis<als100_widthliantongdis_min||als100_widthliantongdis>als100_widthliantongdis_max)
        als100_widthliantongdis=als100_widthliantongdis_use;
    if(als100_highliantongdis<als100_highliantongdis_min||als100_highliantongdis>als100_highliantongdis_max)
        als100_highliantongdis=als100_highliantongdis_use;
    if(als100_gujiaerzhi<als100_gujiaerzhi_min||als100_gujiaerzhi>als100_gujiaerzhi_max)
        als100_gujiaerzhi=als100_gujiaerzhi_use;
    if(als100_jiguanghight<als100_jiguanghight_min||als100_jiguanghight>als100_jiguanghight_max)
        als100_jiguanghight=als100_jiguanghight_use;
    if(als100_jiguanglong<als100_jiguanglong_min||als100_jiguanglong>als100_jiguanglong_max)
        als100_jiguanglong=als100_jiguanglong_use;
    if(als100_jiguangkuandu<als100_jiguangkuandu_min||als100_jiguangkuandu>als100_jiguangkuandu_max)
        als100_jiguangkuandu=als100_jiguangkuandu_use;
    if(als100_Updif<als100_Updif_min||als100_Updif>als100_Updif_max)
        als100_Updif=als100_Updif_use;
    if(als100_Updifmin<als100_Updifmin_min||als100_Updifmin>als100_Updifmin_max)
        als100_Updifmin=als100_Updifmin_use;
    if(als100_Uplong<als100_Uplong_min||als100_Uplong>als100_Uplong_max)
        als100_Uplong=als100_Uplong_use;
    if(als100_Downdif<als100_Downdif_min||als100_Downdif>als100_Downdif_max)
        als100_Downdif=als100_Downdif_use;
    if(als100_Downdifmin<als100_Downdifmin_min||als100_Downdifmin>als100_Downdifmin_max)
        als100_Downdifmin=als100_Downdifmin_use;
    if(als100_Downdlong<als100_Downdlong_min||als100_Downdlong>als100_Downdlong_max)
        als100_Downdlong=als100_Downdlong_use;    
    if(als100_duanxianerzhi<als100_duanxianerzhi_min||als100_duanxianerzhi>als100_duanxianerzhi_max)
        als100_duanxianerzhi=als100_duanxianerzhi_use;
    if(als100_erzhisize<als100_erzhisize_min||als100_erzhisize>als100_erzhisize_max)
        als100_erzhisize=als100_erzhisize_use;
    if(als100_erzhisize2<als100_erzhisize2_min||als100_erzhisize2>als100_erzhisize2_max)
        als100_erzhisize2=als100_erzhisize2_use;
    if(als100_searchdectancemax<als100_searchdectancemax_min||als100_searchdectancemax>als100_searchdectancemax_max)
        als100_searchdectancemax=als100_searchdectancemax_use;
    if(als100_searchdectancemin<als100_searchdectancemin_min||als100_searchdectancemin>als100_searchdectancemin_max)
        als100_searchdectancemin=als100_searchdectancemin_use;
    if(als100_dis_center_st<als100_dis_center_st_min||als100_dis_center_st>als100_dis_center_st_max)
        als100_dis_center_st=als100_dis_center_st_use;
    if(als100_dis_center_ed<als100_dis_center_ed_min||als100_dis_center_ed>als100_dis_center_ed_max)
        als100_dis_center_ed=als100_dis_center_ed_use;
    if(als100_answerpoint<als100_answerpoint_min||als100_answerpoint>als100_answerpoint_max)
        als100_answerpoint=als100_answerpoint_use;
}

void E2proomData::als100_read_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_ALG100_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(filename,buff,E2POOM_ALG100_LASERIMAGEPOS_SAVEBUFF))
    {
        init_als100_para();
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
      als100_exposure_time=*ui16_p;
      ui16_p++;
      i16_p = (Int16*)ui16_p;
      als100_pingjun=*i16_p;
      i16_p++;
      als100_b_yanmofuzhu=*i16_p;
      i16_p++;
      als100_b_gudingquyu=*i16_p;
      i16_p++;
      als100_widthliantongdis=*i16_p;
      i16_p++;
      als100_highliantongdis=*i16_p;
      i16_p++;
      als100_gujiaerzhi=*i16_p;
      i16_p++;
      als100_jiguanghight=*i16_p;
      i16_p++;
      als100_jiguanglong=*i16_p;
      i16_p++;
      als100_jiguangkuandu=*i16_p;
      i16_p++;
      als100_Updif=*i16_p;
      i16_p++;
      als100_Updifmin=*i16_p;
      i16_p++;
      als100_Uplong=*i16_p;
      i16_p++;
      als100_Downdif=*i16_p;
      i16_p++;
      als100_Downdifmin=*i16_p;
      i16_p++;
      als100_Downdlong=*i16_p;
      i16_p++;
      als100_duanxianerzhi=*i16_p;
      i16_p++;
      als100_erzhisize=*i16_p;
      i16_p++;
      als100_erzhisize2=*i16_p;
      i16_p++;
      als100_searchdectancemax=*i16_p;
      i16_p++;
      als100_searchdectancemin=*i16_p;
      i16_p++;
      als100_dis_center_st=*i16_p;
      i16_p++;
      als100_dis_center_ed=*i16_p;
      i16_p++;
      als100_answerpoint=*i16_p;
      i16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

}

void E2proomData::write_als100_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_ALG100_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
      return;

    Uint16 *ui16_p;
    Int16 *i16_p;

    ui16_p = (Uint16*)buff;
    *ui16_p=als100_exposure_time;
    ui16_p++;
    i16_p = (Int16*)ui16_p;
    *i16_p=als100_pingjun;
    i16_p++;
    *i16_p=als100_b_yanmofuzhu;
    i16_p++;
    *i16_p=als100_b_gudingquyu;
    i16_p++;
    *i16_p=als100_widthliantongdis;
    i16_p++;
    *i16_p=als100_highliantongdis;
    i16_p++;
    *i16_p=als100_gujiaerzhi;
    i16_p++;
    *i16_p=als100_jiguanghight;
    i16_p++;
    *i16_p=als100_jiguanglong;
    i16_p++;
    *i16_p=als100_jiguangkuandu;
    i16_p++;
    *i16_p=als100_Updif;
    i16_p++;
    *i16_p=als100_Updifmin;
    i16_p++;
    *i16_p=als100_Uplong;
    i16_p++;
    *i16_p=als100_Downdif;
    i16_p++;
    *i16_p=als100_Downdifmin;
    i16_p++;
    *i16_p=als100_Downdlong;
    i16_p++;
    *i16_p=als100_duanxianerzhi;
    i16_p++;
    *i16_p=als100_erzhisize;
    i16_p++;
    *i16_p=als100_erzhisize2;
    i16_p++;
    *i16_p=als100_searchdectancemax;
    i16_p++;
    *i16_p=als100_searchdectancemin;
    i16_p++;
    *i16_p=als100_dis_center_st;
    i16_p++;
    *i16_p=als100_dis_center_ed;
    i16_p++;
    *i16_p=als100_answerpoint;
    i16_p++;


    fo.WriteFile(filename,buff,E2POOM_ALG100_LASERIMAGEPOS_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_als100_para()
{
    als100_exposure_time=als100_exposure_time_use;
    als100_pingjun=als100_pingjun_use;
    als100_b_yanmofuzhu=als100_b_yanmofuzhu_use;
    als100_b_gudingquyu=als100_b_gudingquyu_use;
    als100_widthliantongdis=als100_widthliantongdis_use;
    als100_highliantongdis=als100_highliantongdis_use;
    als100_gujiaerzhi=als100_gujiaerzhi_use;
    als100_jiguanghight=als100_jiguanghight_use;
    als100_jiguanglong=als100_jiguanglong_use;
    als100_jiguangkuandu=als100_jiguangkuandu_use;
    als100_Updif=als100_Updif_use;
    als100_Updifmin=als100_Updifmin_use;
    als100_Uplong=als100_Uplong_use;
    als100_Downdif=als100_Downdif_use;
    als100_Downdifmin=als100_Downdifmin_use;
    als100_Downdlong=als100_Downdlong_use;
    als100_duanxianerzhi=als100_duanxianerzhi_use;
    als100_erzhisize=als100_erzhisize_use;
    als100_erzhisize2=als100_erzhisize2_use;
    als100_searchdectancemax=als100_searchdectancemax_use;
    als100_searchdectancemin=als100_searchdectancemin_use;
    als100_dis_center_st=als100_dis_center_st_use;
    als100_dis_center_ed=als100_dis_center_ed_use;
    als100_answerpoint=als100_answerpoint_use;
}