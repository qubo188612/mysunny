#include "fileout/E2proomData.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>  
#include <unistd.h>

void E2proomData::Init_als101_E2proomData()
{
    als101_pingjun_min=E2POOM_ALG101_LASERIMAGEPOS_PINGJUN_MIN;
    als101_pingjun_use=E2POOM_ALG101_LASERIMAGEPOS_PINGJUN_USE;
    als101_pingjun_max=E2POOM_ALG101_LASERIMAGEPOS_PINGJUN_MAX;
    als101_exposure_time_min=E2POOM_ALG101_LASERIMAGEPOS_EXPOSURE_TIME_MIN;
    als101_exposure_time_max=E2POOM_ALG101_LASERIMAGEPOS_EXPOSURE_TIME_MAX;
    als101_exposure_time_use=E2POOM_ALG101_LASERIMAGEPOS_EXPOSURE_TIME_USE;
    als101_b_yanmofuzhu_min=E2POOM_ALG101_LASERIMAGEPOS_B_YANMOFUZHU_MIN;
    als101_b_yanmofuzhu_use=E2POOM_ALG101_LASERIMAGEPOS_B_YANMOFUZHU_USE;
    als101_b_yanmofuzhu_max=E2POOM_ALG101_LASERIMAGEPOS_B_YANMOFUZHU_MAX;
    als101_b_gudingquyu_min=E2POOM_ALG101_LASERIMAGEPOS_B_GUDINGQUYU_MIN;
    als101_b_gudingquyu_use=E2POOM_ALG101_LASERIMAGEPOS_B_GUDINGQUYU_USE;
    als101_b_gudingquyu_max=E2POOM_ALG101_LASERIMAGEPOS_B_GUDINGQUYU_MAX;
    als101_widthliantongdis_min=E2POOM_ALG101_LASERIMAGEPOS_WIDTHLIANTONGDIS_MIN;
    als101_widthliantongdis_use=E2POOM_ALG101_LASERIMAGEPOS_WIDTHLIANTONGDIS_USE;
    als101_widthliantongdis_max=E2POOM_ALG101_LASERIMAGEPOS_WIDTHLIANTONGDIS_MAX;
    als101_highliantongdis_min=E2POOM_ALG101_LASERIMAGEPOS_HIGHLIANTONGDIS_MIN;
    als101_highliantongdis_use=E2POOM_ALG101_LASERIMAGEPOS_HIGHLIANTONGDIS_USE;
    als101_highliantongdis_max=E2POOM_ALG101_LASERIMAGEPOS_HIGHLIANTONGDIS_MAX;
    als101_gujiaerzhi_min=E2POOM_ALG101_LASERIMAGEPOS_GUJIAERZHI_MIN;
    als101_gujiaerzhi_use=E2POOM_ALG101_LASERIMAGEPOS_GUJIAERZHI_USE;
    als101_gujiaerzhi_max=E2POOM_ALG101_LASERIMAGEPOS_GUJIAERZHI_MAX;
    als101_jiguanghight_min=E2POOM_ALG101_LASERIMAGEPOS_JIGUANGHIGHT_MIN;
    als101_jiguanghight_use=E2POOM_ALG101_LASERIMAGEPOS_JIGUANGHIGHT_USE;
    als101_jiguanghight_max=E2POOM_ALG101_LASERIMAGEPOS_JIGUANGHIGHT_MAX;
    als101_jiguanglong_min=E2POOM_ALG101_LASERIMAGEPOS_JIGUANGLONG_MIN;
    als101_jiguanglong_use=E2POOM_ALG101_LASERIMAGEPOS_JIGUANGLONG_USE;
    als101_jiguanglong_max=E2POOM_ALG101_LASERIMAGEPOS_JIGUANGLONG_MAX;
    als101_jiguangkuandu_min=E2POOM_ALG101_LASERIMAGEPOS_JIGUANGKUANDU_MIN;
    als101_jiguangkuandu_use=E2POOM_ALG101_LASERIMAGEPOS_JIGUANGKUANDU_USE;
    als101_jiguangkuandu_max=E2POOM_ALG101_LASERIMAGEPOS_JIGUANGKUANDU_MAX;
    als101_Updif_min=E2POOM_ALG101_LASERIMAGEPOS_UPDIF_MIN;
    als101_Updif_use=E2POOM_ALG101_LASERIMAGEPOS_UPDIF_USE;
    als101_Updif_max=E2POOM_ALG101_LASERIMAGEPOS_UPDIF_MAX;
    als101_Updifmin_min=E2POOM_ALG101_LASERIMAGEPOS_UPDIFMIN_MIN;
    als101_Updifmin_use=E2POOM_ALG101_LASERIMAGEPOS_UPDIFMIN_USE;
    als101_Updifmin_max=E2POOM_ALG101_LASERIMAGEPOS_UPDIFMIN_MAX;
    als101_Uplong_min=E2POOM_ALG101_LASERIMAGEPOS_UPLONG_MIN;
    als101_Uplong_use=E2POOM_ALG101_LASERIMAGEPOS_UPLONG_USE;
    als101_Uplong_max=E2POOM_ALG101_LASERIMAGEPOS_UPLONG_MAX;
    als101_Downdif_min=E2POOM_ALG101_LASERIMAGEPOS_DOWNDIF_MIN;
    als101_Downdif_use=E2POOM_ALG101_LASERIMAGEPOS_DOWNDIF_USE;
    als101_Downdif_max=E2POOM_ALG101_LASERIMAGEPOS_DOWNDIF_MAX;
    als101_Downdifmin_min=E2POOM_ALG101_LASERIMAGEPOS_DOWNDIFMIN_MIN;
    als101_Downdifmin_use=E2POOM_ALG101_LASERIMAGEPOS_DOWNDIFMIN_USE;
    als101_Downdifmin_max=E2POOM_ALG101_LASERIMAGEPOS_DOWNDIFMIN_MAX;
    als101_Downdlong_min=E2POOM_ALG101_LASERIMAGEPOS_DOWNDLONG_MIN;
    als101_Downdlong_use=E2POOM_ALG101_LASERIMAGEPOS_DOWNDLONG_USE;
    als101_Downdlong_max=E2POOM_ALG101_LASERIMAGEPOS_DOWNDLONG_MAX;
    als101_duanxianerzhi_min=E2POOM_ALG101_LASERIMAGEPOS_DUANXIANERZHI_MIN;
    als101_duanxianerzhi_use=E2POOM_ALG101_LASERIMAGEPOS_DUANXIANERZHI_USE;
    als101_duanxianerzhi_max=E2POOM_ALG101_LASERIMAGEPOS_DUANXIANERZHI_MAX;
    als101_erzhisize_min=E2POOM_ALG101_LASERIMAGEPOS_ERZHISIZE_MIN;
    als101_erzhisize_use=E2POOM_ALG101_LASERIMAGEPOS_ERZHISIZE_USE;
    als101_erzhisize_max=E2POOM_ALG101_LASERIMAGEPOS_ERZHISIZE_MAX;
    als101_erzhisize2_min=E2POOM_ALG101_LASERIMAGEPOS_ERZHISIZE2_MIN;
    als101_erzhisize2_use=E2POOM_ALG101_LASERIMAGEPOS_ERZHISIZE2_USE;
    als101_erzhisize2_max=E2POOM_ALG101_LASERIMAGEPOS_ERZHISIZE2_MAX;
    als101_searchdectancemax_min=E2POOM_ALG101_LASERIMAGEPOS_SEARCHDECTANCEMAX_MIN;
    als101_searchdectancemax_use=E2POOM_ALG101_LASERIMAGEPOS_SEARCHDECTANCEMAX_USE;
    als101_searchdectancemax_max=E2POOM_ALG101_LASERIMAGEPOS_SEARCHDECTANCEMAX_MAX;
    als101_searchdectancemin_min=E2POOM_ALG101_LASERIMAGEPOS_SEARCHDECTANCEMIN_MIN;
    als101_searchdectancemin_use=E2POOM_ALG101_LASERIMAGEPOS_SEARCHDECTANCEMIN_USE;
    als101_searchdectancemin_max=E2POOM_ALG101_LASERIMAGEPOS_SEARCHDECTANCEMIN_MAX;
    als101_dis_center_st_min=E2POOM_ALG101_LASERIMAGEPOS_DIS_CENTER_ST_MIN;
    als101_dis_center_st_use=E2POOM_ALG101_LASERIMAGEPOS_DIS_CENTER_ST_USE;
    als101_dis_center_st_max=E2POOM_ALG101_LASERIMAGEPOS_DIS_CENTER_ST_MAX;
    als101_dis_center_ed_min=E2POOM_ALG101_LASERIMAGEPOS_DIS_CENTER_ED_MIN;
    als101_dis_center_ed_use=E2POOM_ALG101_LASERIMAGEPOS_DIS_CENTER_ED_USE;
    als101_dis_center_ed_max=E2POOM_ALG101_LASERIMAGEPOS_DIS_CENTER_ED_MAX;
    als101_answerpoint_min=E2POOM_ALG101_LASERIMAGEPOS_ANSWERPOINT_MIN;
    als101_answerpoint_use=E2POOM_ALG101_LASERIMAGEPOS_ANSWERPOINT_USE;
    als101_answerpoint_max=E2POOM_ALG101_LASERIMAGEPOS_ANSWERPOINT_MAX;
}

void E2proomData::als101_check_para()
{
    if(als101_exposure_time<als101_exposure_time_min||als101_exposure_time>als101_exposure_time_max)
        als101_exposure_time=als101_exposure_time_use;
    if(als101_pingjun<als101_pingjun_min||als101_pingjun>als101_pingjun_max)
        als101_pingjun=als101_pingjun_use;
    if(als101_b_yanmofuzhu<als101_b_yanmofuzhu_min||als101_b_yanmofuzhu>als101_b_yanmofuzhu_max)
        als101_b_yanmofuzhu=als101_b_yanmofuzhu_use;
    if(als101_b_gudingquyu<als101_b_gudingquyu_min||als101_b_gudingquyu>als101_b_gudingquyu_max)
        als101_b_gudingquyu=als101_b_gudingquyu_use;
    if(als101_widthliantongdis<als101_widthliantongdis_min||als101_widthliantongdis>als101_widthliantongdis_max)
        als101_widthliantongdis=als101_widthliantongdis_use;
    if(als101_highliantongdis<als101_highliantongdis_min||als101_highliantongdis>als101_highliantongdis_max)
        als101_highliantongdis=als101_highliantongdis_use;
    if(als101_gujiaerzhi<als101_gujiaerzhi_min||als101_gujiaerzhi>als101_gujiaerzhi_max)
        als101_gujiaerzhi=als101_gujiaerzhi_use;
    if(als101_jiguanghight<als101_jiguanghight_min||als101_jiguanghight>als101_jiguanghight_max)
        als101_jiguanghight=als101_jiguanghight_use;
    if(als101_jiguanglong<als101_jiguanglong_min||als101_jiguanglong>als101_jiguanglong_max)
        als101_jiguanglong=als101_jiguanglong_use;
    if(als101_jiguangkuandu<als101_jiguangkuandu_min||als101_jiguangkuandu>als101_jiguangkuandu_max)
        als101_jiguangkuandu=als101_jiguangkuandu_use;
    if(als101_Updif<als101_Updif_min||als101_Updif>als101_Updif_max)
        als101_Updif=als101_Updif_use;
    if(als101_Updifmin<als101_Updifmin_min||als101_Updifmin>als101_Updifmin_max)
        als101_Updifmin=als101_Updifmin_use;
    if(als101_Uplong<als101_Uplong_min||als101_Uplong>als101_Uplong_max)
        als101_Uplong=als101_Uplong_use;
    if(als101_Downdif<als101_Downdif_min||als101_Downdif>als101_Downdif_max)
        als101_Downdif=als101_Downdif_use;
    if(als101_Downdifmin<als101_Downdifmin_min||als101_Downdifmin>als101_Downdifmin_max)
        als101_Downdifmin=als101_Downdifmin_use;
    if(als101_Downdlong<als101_Downdlong_min||als101_Downdlong>als101_Downdlong_max)
        als101_Downdlong=als101_Downdlong_use;    
    if(als101_duanxianerzhi<als101_duanxianerzhi_min||als101_duanxianerzhi>als101_duanxianerzhi_max)
        als101_duanxianerzhi=als101_duanxianerzhi_use;
    if(als101_erzhisize<als101_erzhisize_min||als101_erzhisize>als101_erzhisize_max)
        als101_erzhisize=als101_erzhisize_use;
    if(als101_erzhisize2<als101_erzhisize2_min||als101_erzhisize2>als101_erzhisize2_max)
        als101_erzhisize2=als101_erzhisize2_use;
    if(als101_searchdectancemax<als101_searchdectancemax_min||als101_searchdectancemax>als101_searchdectancemax_max)
        als101_searchdectancemax=als101_searchdectancemax_use;
    if(als101_searchdectancemin<als101_searchdectancemin_min||als101_searchdectancemin>als101_searchdectancemin_max)
        als101_searchdectancemin=als101_searchdectancemin_use;
    if(als101_dis_center_st<als101_dis_center_st_min||als101_dis_center_st>als101_dis_center_st_max)
        als101_dis_center_st=als101_dis_center_st_use;
    if(als101_dis_center_ed<als101_dis_center_ed_min||als101_dis_center_ed>als101_dis_center_ed_max)
        als101_dis_center_ed=als101_dis_center_ed_use;
    if(als101_answerpoint<als101_answerpoint_min||als101_answerpoint>als101_answerpoint_max)
        als101_answerpoint=als101_answerpoint_use;
}

void E2proomData::als101_read_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_ALG101_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(filename,buff,E2POOM_ALG101_LASERIMAGEPOS_SAVEBUFF))
    {
        init_als101_para();
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
      als101_exposure_time=*ui16_p;
      ui16_p++;
      i16_p = (Int16*)ui16_p;
      als101_pingjun=*i16_p;
      i16_p++;
      als101_b_yanmofuzhu=*i16_p;
      i16_p++;
      als101_b_gudingquyu=*i16_p;
      i16_p++;
      als101_widthliantongdis=*i16_p;
      i16_p++;
      als101_highliantongdis=*i16_p;
      i16_p++;
      als101_gujiaerzhi=*i16_p;
      i16_p++;
      als101_jiguanghight=*i16_p;
      i16_p++;
      als101_jiguanglong=*i16_p;
      i16_p++;
      als101_jiguangkuandu=*i16_p;
      i16_p++;
      als101_Updif=*i16_p;
      i16_p++;
      als101_Updifmin=*i16_p;
      i16_p++;
      als101_Uplong=*i16_p;
      i16_p++;
      als101_Downdif=*i16_p;
      i16_p++;
      als101_Downdifmin=*i16_p;
      i16_p++;
      als101_Downdlong=*i16_p;
      i16_p++;
      als101_duanxianerzhi=*i16_p;
      i16_p++;
      als101_erzhisize=*i16_p;
      i16_p++;
      als101_erzhisize2=*i16_p;
      i16_p++;
      als101_searchdectancemax=*i16_p;
      i16_p++;
      als101_searchdectancemin=*i16_p;
      i16_p++;
      als101_dis_center_st=*i16_p;
      i16_p++;
      als101_dis_center_ed=*i16_p;
      i16_p++;
      als101_answerpoint=*i16_p;
      i16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

}

void E2proomData::write_als101_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_ALG101_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
      return;

    Uint16 *ui16_p;
    Int16 *i16_p;

    ui16_p = (Uint16*)buff;
    *ui16_p=als101_exposure_time;
    ui16_p++;
    i16_p = (Int16*)ui16_p;
    *i16_p=als101_pingjun;
    i16_p++;
    *i16_p=als101_b_yanmofuzhu;
    i16_p++;
    *i16_p=als101_b_gudingquyu;
    i16_p++;
    *i16_p=als101_widthliantongdis;
    i16_p++;
    *i16_p=als101_highliantongdis;
    i16_p++;
    *i16_p=als101_gujiaerzhi;
    i16_p++;
    *i16_p=als101_jiguanghight;
    i16_p++;
    *i16_p=als101_jiguanglong;
    i16_p++;
    *i16_p=als101_jiguangkuandu;
    i16_p++;
    *i16_p=als101_Updif;
    i16_p++;
    *i16_p=als101_Updifmin;
    i16_p++;
    *i16_p=als101_Uplong;
    i16_p++;
    *i16_p=als101_Downdif;
    i16_p++;
    *i16_p=als101_Downdifmin;
    i16_p++;
    *i16_p=als101_Downdlong;
    i16_p++;
    *i16_p=als101_duanxianerzhi;
    i16_p++;
    *i16_p=als101_erzhisize;
    i16_p++;
    *i16_p=als101_erzhisize2;
    i16_p++;
    *i16_p=als101_searchdectancemax;
    i16_p++;
    *i16_p=als101_searchdectancemin;
    i16_p++;
    *i16_p=als101_dis_center_st;
    i16_p++;
    *i16_p=als101_dis_center_ed;
    i16_p++;
    *i16_p=als101_answerpoint;
    i16_p++;


    fo.WriteFile(filename,buff,E2POOM_ALG101_LASERIMAGEPOS_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_als101_para()
{
    als101_exposure_time=als101_exposure_time_use;
    als101_pingjun=als101_pingjun_use;
    als101_b_yanmofuzhu=als101_b_yanmofuzhu_use;
    als101_b_gudingquyu=als101_b_gudingquyu_use;
    als101_widthliantongdis=als101_widthliantongdis_use;
    als101_highliantongdis=als101_highliantongdis_use;
    als101_gujiaerzhi=als101_gujiaerzhi_use;
    als101_jiguanghight=als101_jiguanghight_use;
    als101_jiguanglong=als101_jiguanglong_use;
    als101_jiguangkuandu=als101_jiguangkuandu_use;
    als101_Updif=als101_Updif_use;
    als101_Updifmin=als101_Updifmin_use;
    als101_Uplong=als101_Uplong_use;
    als101_Downdif=als101_Downdif_use;
    als101_Downdifmin=als101_Downdifmin_use;
    als101_Downdlong=als101_Downdlong_use;
    als101_duanxianerzhi=als101_duanxianerzhi_use;
    als101_erzhisize=als101_erzhisize_use;
    als101_erzhisize2=als101_erzhisize2_use;
    als101_searchdectancemax=als101_searchdectancemax_use;
    als101_searchdectancemin=als101_searchdectancemin_use;
    als101_dis_center_st=als101_dis_center_st_use;
    als101_dis_center_ed=als101_dis_center_ed_use;
    als101_answerpoint=als101_answerpoint_use;
}