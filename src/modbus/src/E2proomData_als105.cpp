#include "fileout/E2proomData.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>  
#include <unistd.h>

void E2proomData::Init_als105_E2proomData()
{
    als105_pingjun_min=E2POOM_ALG105_LASERIMAGEPOS_PINGJUN_MIN;
    als105_pingjun_use=E2POOM_ALG105_LASERIMAGEPOS_PINGJUN_USE;
    als105_pingjun_max=E2POOM_ALG105_LASERIMAGEPOS_PINGJUN_MAX;
    als105_exposure_time_min=E2POOM_ALG105_LASERIMAGEPOS_EXPOSURE_TIME_MIN;
    als105_exposure_time_max=E2POOM_ALG105_LASERIMAGEPOS_EXPOSURE_TIME_MAX;
    als105_exposure_time_use=E2POOM_ALG105_LASERIMAGEPOS_EXPOSURE_TIME_USE;
    als105_b_yanmofuzhu_min=E2POOM_ALG105_LASERIMAGEPOS_B_YANMOFUZHU_MIN;
    als105_b_yanmofuzhu_use=E2POOM_ALG105_LASERIMAGEPOS_B_YANMOFUZHU_USE;
    als105_b_yanmofuzhu_max=E2POOM_ALG105_LASERIMAGEPOS_B_YANMOFUZHU_MAX;
    als105_widthliantongdis_min=E2POOM_ALG105_LASERIMAGEPOS_WIDTHLIANTONGDIS_MIN;
    als105_widthliantongdis_use=E2POOM_ALG105_LASERIMAGEPOS_WIDTHLIANTONGDIS_USE;
    als105_widthliantongdis_max=E2POOM_ALG105_LASERIMAGEPOS_WIDTHLIANTONGDIS_MAX;
    als105_highliantongdis_min=E2POOM_ALG105_LASERIMAGEPOS_HIGHLIANTONGDIS_MIN;
    als105_highliantongdis_use=E2POOM_ALG105_LASERIMAGEPOS_HIGHLIANTONGDIS_USE;
    als105_highliantongdis_max=E2POOM_ALG105_LASERIMAGEPOS_HIGHLIANTONGDIS_MAX;
    als105_gujiaerzhi_min=E2POOM_ALG105_LASERIMAGEPOS_GUJIAERZHI_MIN;
    als105_gujiaerzhi_use=E2POOM_ALG105_LASERIMAGEPOS_GUJIAERZHI_USE;
    als105_gujiaerzhi_max=E2POOM_ALG105_LASERIMAGEPOS_GUJIAERZHI_MAX;
    als105_jiguanghight_min=E2POOM_ALG105_LASERIMAGEPOS_JIGUANGHIGHT_MIN;
    als105_jiguanghight_use=E2POOM_ALG105_LASERIMAGEPOS_JIGUANGHIGHT_USE;
    als105_jiguanghight_max=E2POOM_ALG105_LASERIMAGEPOS_JIGUANGHIGHT_MAX;
    als105_jiguanglong_min=E2POOM_ALG105_LASERIMAGEPOS_JIGUANGLONG_MIN;
    als105_jiguanglong_use=E2POOM_ALG105_LASERIMAGEPOS_JIGUANGLONG_USE;
    als105_jiguanglong_max=E2POOM_ALG105_LASERIMAGEPOS_JIGUANGLONG_MAX;
    als105_jiguangkuandu_min=E2POOM_ALG105_LASERIMAGEPOS_JIGUANGKUANDU_MIN;
    als105_jiguangkuandu_use=E2POOM_ALG105_LASERIMAGEPOS_JIGUANGKUANDU_USE;
    als105_jiguangkuandu_max=E2POOM_ALG105_LASERIMAGEPOS_JIGUANGKUANDU_MAX;
    als105_Updif_min=E2POOM_ALG105_LASERIMAGEPOS_UPDIF_MIN;
    als105_Updif_use=E2POOM_ALG105_LASERIMAGEPOS_UPDIF_USE;
    als105_Updif_max=E2POOM_ALG105_LASERIMAGEPOS_UPDIF_MAX;
    als105_Updifmin_min=E2POOM_ALG105_LASERIMAGEPOS_UPDIFMIN_MIN;
    als105_Updifmin_use=E2POOM_ALG105_LASERIMAGEPOS_UPDIFMIN_USE;
    als105_Updifmin_max=E2POOM_ALG105_LASERIMAGEPOS_UPDIFMIN_MAX;
    als105_Uplong_min=E2POOM_ALG105_LASERIMAGEPOS_UPLONG_MIN;
    als105_Uplong_use=E2POOM_ALG105_LASERIMAGEPOS_UPLONG_USE;
    als105_Uplong_max=E2POOM_ALG105_LASERIMAGEPOS_UPLONG_MAX;
    als105_Downdif_min=E2POOM_ALG105_LASERIMAGEPOS_DOWNDIF_MIN;
    als105_Downdif_use=E2POOM_ALG105_LASERIMAGEPOS_DOWNDIF_USE;
    als105_Downdif_max=E2POOM_ALG105_LASERIMAGEPOS_DOWNDIF_MAX;
    als105_Downdifmin_min=E2POOM_ALG105_LASERIMAGEPOS_DOWNDIFMIN_MIN;
    als105_Downdifmin_use=E2POOM_ALG105_LASERIMAGEPOS_DOWNDIFMIN_USE;
    als105_Downdifmin_max=E2POOM_ALG105_LASERIMAGEPOS_DOWNDIFMIN_MAX;
    als105_Downdlong_min=E2POOM_ALG105_LASERIMAGEPOS_DOWNDLONG_MIN;
    als105_Downdlong_use=E2POOM_ALG105_LASERIMAGEPOS_DOWNDLONG_USE;
    als105_Downdlong_max=E2POOM_ALG105_LASERIMAGEPOS_DOWNDLONG_MAX;
    als105_dis_center_st_min=E2POOM_ALG105_LASERIMAGEPOS_DIS_CENTER_ST_MIN;
    als105_dis_center_st_use=E2POOM_ALG105_LASERIMAGEPOS_DIS_CENTER_ST_USE;
    als105_dis_center_st_max=E2POOM_ALG105_LASERIMAGEPOS_DIS_CENTER_ST_MAX;
    als105_dis_center_ed_min=E2POOM_ALG105_LASERIMAGEPOS_DIS_CENTER_ED_MIN;
    als105_dis_center_ed_use=E2POOM_ALG105_LASERIMAGEPOS_DIS_CENTER_ED_USE;
    als105_dis_center_ed_max=E2POOM_ALG105_LASERIMAGEPOS_DIS_CENTER_ED_MAX;
    als105_b_cut_min=E2POOM_ALG105_LASERIMAGEPOS_B_CUT_MIN;
    als105_b_cut_use=E2POOM_ALG105_LASERIMAGEPOS_B_CUT_USE;
    als105_b_cut_max=E2POOM_ALG105_LASERIMAGEPOS_B_CUT_MAX;
    als105_cutleft_min=E2POOM_ALG105_LASERIMAGEPOS_CUTLEFT_MIN;
    als105_cutleft_use=E2POOM_ALG105_LASERIMAGEPOS_CUTLEFT_USE;
    als105_cutleft_max=E2POOM_ALG105_LASERIMAGEPOS_CUTLEFT_MAX;
    als105_cutright_min=E2POOM_ALG105_LASERIMAGEPOS_CUTRIGHT_MIN;
    als105_cutright_use=E2POOM_ALG105_LASERIMAGEPOS_CUTRIGHT_USE;
    als105_cutright_max=E2POOM_ALG105_LASERIMAGEPOS_CUTRIGHT_MAX;
    als105_cuttop_min=E2POOM_ALG105_LASERIMAGEPOS_CUTTOP_MIN;
    als105_cuttop_use=E2POOM_ALG105_LASERIMAGEPOS_CUTTOP_USE;
    als105_cuttop_max=E2POOM_ALG105_LASERIMAGEPOS_CUTTOP_MAX;
    als105_cutdeep_min=E2POOM_ALG105_LASERIMAGEPOS_CUTDEEP_MIN;
    als105_cutdeep_use=E2POOM_ALG105_LASERIMAGEPOS_CUTDEEP_USE;
    als105_cutdeep_max=E2POOM_ALG105_LASERIMAGEPOS_CUTDEEP_MAX;
    als105_guaidianyuzhi_min=E2POOM_ALG105_LASERIMAGEPOS_GUAIDIANYUZHI_MIN;
    als105_guaidianyuzhi_use=E2POOM_ALG105_LASERIMAGEPOS_GUAIDIANYUZHI_USE;
    als105_guaidianyuzhi_max=E2POOM_ALG105_LASERIMAGEPOS_GUAIDIANYUZHI_MAX;
    als105_duandianjuli_min=E2POOM_ALG105_LASERIMAGEPOS_DUANDIANJULI_MIN;
    als105_duandianjuli_use=E2POOM_ALG105_LASERIMAGEPOS_DUANDIANJULI_USE;
    als105_duandianjuli_max=E2POOM_ALG105_LASERIMAGEPOS_DUANDIANJULI_MAX;
    als105_b_dibufaxiangliang_min=E2POOM_ALG105_LASERIMAGEPOS_B_DIBUFAXIANGLIANG_MIN;
    als105_b_dibufaxiangliang_use=E2POOM_ALG105_LASERIMAGEPOS_B_DIBUFAXIANGLIANG_USE;
    als105_b_dibufaxiangliang_max=E2POOM_ALG105_LASERIMAGEPOS_B_DIBUFAXIANGLIANG_MAX;
    als105_answerpoint_min=E2POOM_ALG105_LASERIMAGEPOS_ANSWERPOINT_MIN;
    als105_answerpoint_use=E2POOM_ALG105_LASERIMAGEPOS_ANSWERPOINT_USE;
    als105_answerpoint_max=E2POOM_ALG105_LASERIMAGEPOS_ANSWERPOINT_MAX;
}

void E2proomData::als105_check_para()
{
    if(als105_exposure_time<als105_exposure_time_min||als105_exposure_time>als105_exposure_time_max)
        als105_exposure_time=als105_exposure_time_use;
    if(als105_pingjun<als105_pingjun_min||als105_pingjun>als105_pingjun_max)
        als105_pingjun=als105_pingjun_use;
    if(als105_b_yanmofuzhu<als105_b_yanmofuzhu_min||als105_b_yanmofuzhu>als105_b_yanmofuzhu_max)
        als105_b_yanmofuzhu=als105_b_yanmofuzhu_use;
    if(als105_widthliantongdis<als105_widthliantongdis_min||als105_widthliantongdis>als105_widthliantongdis_max)
        als105_widthliantongdis=als105_widthliantongdis_use;
    if(als105_highliantongdis<als105_highliantongdis_min||als105_highliantongdis>als105_highliantongdis_max)
        als105_highliantongdis=als105_highliantongdis_use;
    if(als105_gujiaerzhi<als105_gujiaerzhi_min||als105_gujiaerzhi>als105_gujiaerzhi_max)
        als105_gujiaerzhi=als105_gujiaerzhi_use;
    if(als105_jiguanghight<als105_jiguanghight_min||als105_jiguanghight>als105_jiguanghight_max)
        als105_jiguanghight=als105_jiguanghight_use;
    if(als105_jiguanglong<als105_jiguanglong_min||als105_jiguanglong>als105_jiguanglong_max)
        als105_jiguanglong=als105_jiguanglong_use;
    if(als105_jiguangkuandu<als105_jiguangkuandu_min||als105_jiguangkuandu>als105_jiguangkuandu_max)
        als105_jiguangkuandu=als105_jiguangkuandu_use;
    if(als105_Updif<als105_Updif_min||als105_Updif>als105_Updif_max)
        als105_Updif=als105_Updif_use;
    if(als105_Updifmin<als105_Updifmin_min||als105_Updifmin>als105_Updifmin_max)
        als105_Updifmin=als105_Updifmin_use;
    if(als105_Uplong<als105_Uplong_min||als105_Uplong>als105_Uplong_max)
        als105_Uplong=als105_Uplong_use;
    if(als105_Downdif<als105_Downdif_min||als105_Downdif>als105_Downdif_max)
        als105_Downdif=als105_Downdif_use;
    if(als105_Downdifmin<als105_Downdifmin_min||als105_Downdifmin>als105_Downdifmin_max)
        als105_Downdifmin=als105_Downdifmin_use;
    if(als105_Downdlong<als105_Downdlong_min||als105_Downdlong>als105_Downdlong_max)
        als105_Downdlong=als105_Downdlong_use;    
    if(als105_dis_center_st<als105_dis_center_st_min||als105_dis_center_st>als105_dis_center_st_max)
        als105_dis_center_st=als105_dis_center_st_use;
    if(als105_dis_center_ed<als105_dis_center_ed_min||als105_dis_center_ed>als105_dis_center_ed_max)
        als105_dis_center_ed=als105_dis_center_ed_use;
    if(als105_b_cut<als105_b_cut_min||als105_b_cut>als105_b_cut_max)
        als105_b_cut=als105_b_cut_use;
    if(als105_cutleft<als105_cutleft_min||als105_cutleft>als105_cutleft_max)
        als105_cutleft=als105_cutleft_use;
    if(als105_cutright<als105_cutright_min||als105_cutright>als105_cutright_max)
        als105_cutright=als105_cutright_use;
    if(als105_cuttop<als105_cuttop_min||als105_cuttop>als105_cuttop_max)
        als105_cuttop=als105_cuttop_use;
    if(als105_cutdeep<als105_cutdeep_min||als105_cutdeep>als105_cutdeep_max)
        als105_cutdeep=als105_cutdeep_use;
    if(als105_guaidianyuzhi<als105_guaidianyuzhi_min||als105_guaidianyuzhi>als105_guaidianyuzhi_max)
        als105_guaidianyuzhi=als105_guaidianyuzhi_use;
    if(als105_duandianjuli<als105_duandianjuli_min||als105_duandianjuli>als105_duandianjuli_max)
        als105_duandianjuli=als105_duandianjuli_use;
    if(als105_b_dibufaxiangliang<als105_b_dibufaxiangliang_min||als105_b_dibufaxiangliang>als105_b_dibufaxiangliang_max)
        als105_b_dibufaxiangliang=als105_b_dibufaxiangliang_use;
    if(als105_answerpoint<als105_answerpoint_min||als105_answerpoint>als105_answerpoint_max)
        als105_answerpoint=als105_answerpoint_use;
}

void E2proomData::als105_read_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_ALG105_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(filename,buff,E2POOM_ALG105_LASERIMAGEPOS_SAVEBUFF))
    {
        init_als105_para();
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
      als105_exposure_time=*ui16_p;
      ui16_p++;
      i16_p = (Int16*)ui16_p;
      als105_pingjun=*i16_p;
      i16_p++;
      als105_b_yanmofuzhu=*i16_p;
      i16_p++;
      als105_widthliantongdis=*i16_p;
      i16_p++;
      als105_highliantongdis=*i16_p;
      i16_p++;
      als105_gujiaerzhi=*i16_p;
      i16_p++;
      als105_jiguanghight=*i16_p;
      i16_p++;
      als105_jiguanglong=*i16_p;
      i16_p++;
      als105_jiguangkuandu=*i16_p;
      i16_p++;
      als105_Updif=*i16_p;
      i16_p++;
      als105_Updifmin=*i16_p;
      i16_p++;
      als105_Uplong=*i16_p;
      i16_p++;
      als105_Downdif=*i16_p;
      i16_p++;
      als105_Downdifmin=*i16_p;
      i16_p++;
      als105_Downdlong=*i16_p;
      i16_p++;
      als105_dis_center_st=*i16_p;
      i16_p++;
      als105_dis_center_ed=*i16_p;
      i16_p++;
      als105_b_cut=*i16_p;
      i16_p++;  
      als105_cutleft=*i16_p;
      i16_p++; 
      als105_cutright=*i16_p;
      i16_p++; 
      als105_cuttop=*i16_p;
      i16_p++; 
      als105_cutdeep=*i16_p;
      i16_p++; 
      als105_guaidianyuzhi=*i16_p;
      i16_p++; 
      als105_duandianjuli=*i16_p;
      i16_p++;
      als105_b_dibufaxiangliang=*i16_p;
      i16_p++;     
      als105_answerpoint=*i16_p;
      i16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

}

void E2proomData::write_als105_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_ALG105_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
      return;

    Uint16 *ui16_p;
    Int16 *i16_p;

    ui16_p = (Uint16*)buff;
    *ui16_p=als105_exposure_time;
    ui16_p++;
    i16_p = (Int16*)ui16_p;
    *i16_p=als105_pingjun;
    i16_p++;
    *i16_p=als105_b_yanmofuzhu;
    i16_p++;
    *i16_p=als105_widthliantongdis;
    i16_p++;
    *i16_p=als105_highliantongdis;
    i16_p++;
    *i16_p=als105_gujiaerzhi;
    i16_p++;
    *i16_p=als105_jiguanghight;
    i16_p++;
    *i16_p=als105_jiguanglong;
    i16_p++;
    *i16_p=als105_jiguangkuandu;
    i16_p++;
    *i16_p=als105_Updif;
    i16_p++;
    *i16_p=als105_Updifmin;
    i16_p++;
    *i16_p=als105_Uplong;
    i16_p++;
    *i16_p=als105_Downdif;
    i16_p++;
    *i16_p=als105_Downdifmin;
    i16_p++;
    *i16_p=als105_Downdlong;
    i16_p++;
    *i16_p=als105_dis_center_st;
    i16_p++;
    *i16_p=als105_dis_center_ed;
    i16_p++;
    *i16_p=als105_b_cut;
    i16_p++;  
    *i16_p=als105_cutleft;
    i16_p++; 
    *i16_p=als105_cutright;
    i16_p++; 
    *i16_p=als105_cuttop;
    i16_p++; 
    *i16_p=als105_cutdeep;
    i16_p++; 
    *i16_p=als105_guaidianyuzhi;
    i16_p++; 
    *i16_p=als105_duandianjuli;
    i16_p++;
    *i16_p=als105_b_dibufaxiangliang;
    i16_p++;   
    *i16_p=als105_answerpoint;
    i16_p++;
    

    fo.WriteFile(filename,buff,E2POOM_ALG105_LASERIMAGEPOS_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_als105_para()
{
    als105_exposure_time=als105_exposure_time_use;
    als105_pingjun=als105_pingjun_use;
    als105_b_yanmofuzhu=als105_b_yanmofuzhu_use;
    als105_widthliantongdis=als105_widthliantongdis_use;
    als105_highliantongdis=als105_highliantongdis_use;
    als105_gujiaerzhi=als105_gujiaerzhi_use;
    als105_jiguanghight=als105_jiguanghight_use;
    als105_jiguanglong=als105_jiguanglong_use;
    als105_jiguangkuandu=als105_jiguangkuandu_use;
    als105_Updif=als105_Updif_use;
    als105_Updifmin=als105_Updifmin_use;
    als105_Uplong=als105_Uplong_use;
    als105_Downdif=als105_Downdif_use;
    als105_Downdifmin=als105_Downdifmin_use;
    als105_Downdlong=als105_Downdlong_use;
    als105_dis_center_st=als105_dis_center_st_use;
    als105_dis_center_ed=als105_dis_center_ed_use;
    als105_b_cut=als105_b_cut_use;
    als105_cutleft=als105_cutleft_use;
    als105_cutright=als105_cutright_use;
    als105_cuttop=als105_cuttop_use;
    als105_cutdeep=als105_cutdeep_use;
    als105_guaidianyuzhi=als105_guaidianyuzhi_use;
    als105_duandianjuli=als105_duandianjuli_use;
    als105_b_dibufaxiangliang=als105_b_dibufaxiangliang_use; 
    als105_answerpoint=als105_answerpoint_use;
}