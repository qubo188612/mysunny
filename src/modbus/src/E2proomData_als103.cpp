#include "fileout/E2proomData.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>  
#include <unistd.h>

void E2proomData::Init_als103_E2proomData()
{
    als103_exposure_time_min=E2POOM_ALG103_LASERIMAGEPOS_EXPOSURE_TIME_MIN;
    als103_exposure_time_max=E2POOM_ALG103_LASERIMAGEPOS_EXPOSURE_TIME_MAX;
    als103_exposure_time_use=E2POOM_ALG103_LASERIMAGEPOS_EXPOSURE_TIME_USE;
    als103_pingjun_min=E2POOM_ALG103_LASERIMAGEPOS_PINGJUN_MIN;
    als103_pingjun_max=E2POOM_ALG103_LASERIMAGEPOS_PINGJUN_MAX;
    als103_pingjun_use=E2POOM_ALG103_LASERIMAGEPOS_PINGJUN_USE;
    als103_gujiaerzhi_min=E2POOM_ALG103_LASERIMAGEPOS_GUJIAERZHI_MIN;
    als103_gujiaerzhi_max=E2POOM_ALG103_LASERIMAGEPOS_GUJIAERZHI_MAX;
    als103_gujiaerzhi_use=E2POOM_ALG103_LASERIMAGEPOS_GUJIAERZHI_USE;
    als103_widthliantongdis_min=E2POOM_ALG103_LASERIMAGEPOS_WIDTHLIANTONGDIS_MIN;
    als103_widthliantongdis_max=E2POOM_ALG103_LASERIMAGEPOS_WIDTHLIANTONGDIS_MAX;
    als103_widthliantongdis_use=E2POOM_ALG103_LASERIMAGEPOS_WIDTHLIANTONGDIS_USE;
    als103_highliantongdis_min=E2POOM_ALG103_LASERIMAGEPOS_HIGHLIANTONGDIS_MIN;
    als103_highliantongdis_max=E2POOM_ALG103_LASERIMAGEPOS_HIGHLIANTONGDIS_MAX;
    als103_highliantongdis_use=E2POOM_ALG103_LASERIMAGEPOS_HIGHLIANTONGDIS_USE;
    als103_jiguanglong_min=E2POOM_ALG103_LASERIMAGEPOS_JIGUANGLONG_MIN;
    als103_jiguanglong_max=E2POOM_ALG103_LASERIMAGEPOS_JIGUANGLONG_MAX;
    als103_jiguanglong_use=E2POOM_ALG103_LASERIMAGEPOS_JIGUANGLONG_USE;
    als103_jiguangkuandu_min=E2POOM_ALG103_LASERIMAGEPOS_JIGUANGKUANDU_MIN;
    als103_jiguangkuandu_max=E2POOM_ALG103_LASERIMAGEPOS_JIGUANGKUANDU_MAX;
    als103_jiguangkuandu_use=E2POOM_ALG103_LASERIMAGEPOS_JIGUANGKUANDU_USE;
    als103_jiguangduibidu_min=E2POOM_ALG103_LASERIMAGEPOS_JIGUANGDUIBIDU_MIN;
    als103_jiguangduibidu_max=E2POOM_ALG103_LASERIMAGEPOS_JIGUANGDUIBIDU_MAX;
    als103_jiguangduibidu_use=E2POOM_ALG103_LASERIMAGEPOS_JIGUANGDUIBIDU_USE;
}

void E2proomData::als103_check_para()
{
    if(als103_exposure_time<als103_exposure_time_min||als103_exposure_time>als103_exposure_time_max)
        als103_exposure_time=als103_exposure_time_use;
    if(als103_pingjun<als103_pingjun_min||als103_pingjun>als103_pingjun_max)
        als103_pingjun=als103_pingjun_use;
    if(als103_gujiaerzhi<als103_gujiaerzhi_min||als103_gujiaerzhi>als103_gujiaerzhi_max)
        als103_gujiaerzhi=als103_gujiaerzhi_use;
    if(als103_widthliantongdis<als103_widthliantongdis_min||als103_widthliantongdis>als103_widthliantongdis_max)
        als103_widthliantongdis=als103_widthliantongdis_use;
    if(als103_highliantongdis<als103_highliantongdis_min||als103_highliantongdis>als103_highliantongdis_max)
        als103_highliantongdis=als103_highliantongdis_use;
    if(als103_jiguanglong<als103_jiguanglong_min||als103_jiguanglong>als103_jiguanglong_max)
        als103_jiguanglong=als103_jiguanglong_use;    
    if(als103_jiguangkuandu<als103_jiguangkuandu_min||als103_jiguangkuandu>als103_jiguangkuandu_max)
        als103_jiguangkuandu=als103_jiguangkuandu_use;
    if(als103_jiguangduibidu<als103_jiguangduibidu_min||als103_jiguangduibidu>als103_jiguangduibidu_max)
        als103_jiguangduibidu=als103_jiguangduibidu_use;
}

void E2proomData::als103_read_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_ALG103_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(filename,buff,E2POOM_ALG103_LASERIMAGEPOS_SAVEBUFF))
    {
        init_als103_para();
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
      als103_exposure_time=*ui16_p;
      ui16_p++;
      i16_p = (Int16*)ui16_p;
      als103_pingjun=*i16_p;
      i16_p++;
      als103_gujiaerzhi=*i16_p;
      i16_p++;
      als103_widthliantongdis=*i16_p;
      i16_p++;
      als103_highliantongdis=*i16_p;
      i16_p++;
      als103_jiguanglong=*i16_p;
      i16_p++;
      als103_jiguangkuandu=*i16_p;
      i16_p++;
      als103_jiguangduibidu=*i16_p;
      i16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

}

void E2proomData::write_als103_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_ALG103_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
      return;

    Uint16 *ui16_p;
    Int16 *i16_p;

    ui16_p = (Uint16*)buff;
    *ui16_p=als103_exposure_time;
    ui16_p++;
    i16_p = (Int16*)ui16_p;
    *i16_p=als103_pingjun;
    i16_p++;
    *i16_p=als103_gujiaerzhi;
    i16_p++;
    *i16_p=als103_widthliantongdis;
    i16_p++;
    *i16_p=als103_highliantongdis;
    i16_p++;
    *i16_p=als103_jiguanglong;
    i16_p++;
    *i16_p=als103_jiguangkuandu;
    i16_p++;
    *i16_p=als103_jiguangduibidu;
    i16_p++;


    fo.WriteFile(filename,buff,E2POOM_ALG103_LASERIMAGEPOS_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_als103_para()
{
    als103_exposure_time=als103_exposure_time_use;
    als103_pingjun=als103_pingjun_use;
    als103_exposure_time=als103_exposure_time_use;
    als103_pingjun=als103_pingjun_use;
    als103_gujiaerzhi=als103_gujiaerzhi_use;
    als103_widthliantongdis=als103_widthliantongdis_use;
    als103_highliantongdis=als103_highliantongdis_use;
    als103_jiguanglong=als103_jiguanglong_use;
    als103_jiguangkuandu=als103_jiguangkuandu_use;
    als103_jiguangduibidu=als103_jiguangduibidu_use;
}