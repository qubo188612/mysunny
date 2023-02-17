#include "fileout/E2proomData.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>  
#include <unistd.h>

void E2proomData::Init_als108_E2proomData()
{
    als108_exposure_time_min=E2POOM_ALG108_LASERIMAGEPOS_EXPOSURE_TIME_MIN;
    als108_exposure_time_max=E2POOM_ALG108_LASERIMAGEPOS_EXPOSURE_TIME_MAX;
    als108_exposure_time_use=E2POOM_ALG108_LASERIMAGEPOS_EXPOSURE_TIME_USE;
    als108_center_x_min=E2POOM_ALG108_LASERIMAGEPOS_CENTER_X_MIN;
    als108_center_x_use=E2POOM_ALG108_LASERIMAGEPOS_CENTER_X_USE;
    als108_center_x_max=E2POOM_ALG108_LASERIMAGEPOS_CENTER_X_MAX;
    als108_center_y_min=E2POOM_ALG108_LASERIMAGEPOS_CENTER_Y_MIN;
    als108_center_y_use=E2POOM_ALG108_LASERIMAGEPOS_CENTER_Y_USE;
    als108_center_y_max=E2POOM_ALG108_LASERIMAGEPOS_CENTER_Y_MAX;
    als108_search_w_min=E2POOM_ALG108_LASERIMAGEPOS_SEARCT_W_MIN;
    als108_search_w_use=E2POOM_ALG108_LASERIMAGEPOS_SEARCT_W_USE;
    als108_search_w_max=E2POOM_ALG108_LASERIMAGEPOS_SEARCT_W_MAX;
    als108_search_h_min=E2POOM_ALG108_LASERIMAGEPOS_SEARCT_H_MIN;
    als108_search_h_use=E2POOM_ALG108_LASERIMAGEPOS_SEARCT_H_USE;
    als108_search_h_max=E2POOM_ALG108_LASERIMAGEPOS_SEARCT_H_MAX;
    als108_STC_alpha_min=E2POOM_ALG108_LASERIMAGEPOS_STC_ALPHA_MIN;
    als108_STC_alpha_use=E2POOM_ALG108_LASERIMAGEPOS_STC_ALPHA_USE;
    als108_STC_alpha_max=E2POOM_ALG108_LASERIMAGEPOS_STC_ALPHA_MAX;
    als108_STC_beta_min=E2POOM_ALG108_LASERIMAGEPOS_STC_BETA_MIN;
    als108_STC_beta_use=E2POOM_ALG108_LASERIMAGEPOS_STC_BETA_USE; 
    als108_STC_beta_max=E2POOM_ALG108_LASERIMAGEPOS_STC_BETA_MAX;
    als108_STC_rho_min=E2POOM_ALG108_LASERIMAGEPOS_STC_RHO_MIN;
    als108_STC_rho_use=E2POOM_ALG108_LASERIMAGEPOS_STC_RHO_USE;
    als108_STC_rho_max=E2POOM_ALG108_LASERIMAGEPOS_STC_RHO_MAX;
    als108_STC_sigma_min=E2POOM_ALG108_LASERIMAGEPOS_STC_SIGMA_MIN;
    als108_STC_sigma_use=E2POOM_ALG108_LASERIMAGEPOS_STC_SIGMA_USE;
    als108_STC_sigma_max=E2POOM_ALG108_LASERIMAGEPOS_STC_SIGMA_MAX;
}

void E2proomData::als108_check_para()
{
    if(als108_exposure_time<als108_exposure_time_min||als108_exposure_time>als108_exposure_time_max)
        als108_exposure_time=als108_exposure_time_use;
    if(als108_center_x<als108_center_x_min||als108_center_x>als108_center_x_max)
        als108_center_x=als108_center_x_use;
    if(als108_center_y<als108_center_y_min||als108_center_y>als108_center_y_max)
        als108_center_y=als108_center_y_use;
    if(als108_search_w<als108_search_w_min||als108_search_w>als108_search_w_max)
        als108_search_w=als108_search_w_use;
    if(als108_search_h<als108_search_h_min||als108_search_h>als108_search_h_max)
        als108_search_h=als108_search_h_use;
    if(als108_STC_alpha<als108_STC_alpha_min||als108_STC_alpha>als108_STC_alpha_max)
        als108_STC_alpha=als108_STC_alpha_use;
    if(als108_STC_beta<als108_STC_beta_min||als108_STC_beta>als108_STC_beta_max)
        als108_STC_beta=als108_STC_beta_use;
    if(als108_STC_rho<als108_STC_rho_min||als108_STC_rho>als108_STC_rho_max)
        als108_STC_rho=als108_STC_rho_use;
    if(als108_STC_sigma<als108_STC_sigma_min||als108_STC_sigma>als108_STC_sigma_max)
        als108_STC_sigma=als108_STC_sigma_use;
}

void E2proomData::als108_read_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_ALG108_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(filename,buff,E2POOM_ALG108_LASERIMAGEPOS_SAVEBUFF))
    {
        init_als108_para();
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
      als108_exposure_time=*ui16_p;
      ui16_p++;
      i16_p = (Int16*)ui16_p;
      als108_center_x=*i16_p;
      i16_p++;
      als108_center_y=*i16_p;
      i16_p++;
      als108_search_w=*i16_p;
      i16_p++;
      als108_search_h=*i16_p;
      i16_p++;
      als108_STC_alpha=*i16_p;
      i16_p++;
      als108_STC_beta=*i16_p;
      i16_p++;
      als108_STC_rho=*i16_p;
      i16_p++;
      als108_STC_sigma=*i16_p;
      i16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

}

void E2proomData::write_als108_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_ALG108_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
      return;

    Uint16 *ui16_p;
    Int16 *i16_p;

    ui16_p = (Uint16*)buff;
    *ui16_p=als108_exposure_time;
    ui16_p++;
    i16_p = (Int16*)ui16_p;
    *i16_p=als108_center_x;
    i16_p++;
    *i16_p=als108_center_y;
    i16_p++;
    *i16_p=als108_search_w;
    i16_p++;
    *i16_p=als108_search_h;
    i16_p++;
    *i16_p=als108_STC_alpha;
    i16_p++;
    *i16_p=als108_STC_beta;
    i16_p++;
    *i16_p=als108_STC_rho;
    i16_p++;
    *i16_p=als108_STC_sigma;
    i16_p++;
    fo.WriteFile(filename,buff,E2POOM_ALG108_LASERIMAGEPOS_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_als108_para()
{
    als108_exposure_time=als108_exposure_time_use;
    als108_center_x=als108_center_x_use;//特征点位置
    als108_center_y=als108_center_y_use; //特征点位置
    als108_search_w=als108_search_w_use;//宽度搜索区域
    als108_search_h=als108_search_h_use;//高度搜索区域
    als108_STC_alpha=als108_STC_alpha_use;//尺度因子，推荐2.25*1000
    als108_STC_beta=als108_STC_beta_use;//形状因子，推荐1*1000  
    als108_STC_rho=als108_STC_rho_use;//学习率,推荐0.075*1000
    als108_STC_sigma=als108_STC_sigma_use;//高斯权重，推荐0.5*1000
}