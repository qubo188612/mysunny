#include "fileout/E2proomData.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>  
#include <unistd.h>

E2proomData::E2proomData()
{
    std::string dir = "./SAVE";
    if (access(dir.c_str(), 0) == -1)
    {
      mkdir("./SAVE",S_IRWXU);
    }

    als1_threshold_min=E2POOM_ALG1_LASERIMAGEPOS_THRESHOLD_MIN;
    als1_threshold_max=E2POOM_ALG1_LASERIMAGEPOS_THRESHOLD_MAX;
    als1_threshold_use=E2POOM_ALG1_LASERIMAGEPOS_THRESHOLD_USE;

    read_para();
}

E2proomData::~E2proomData()
{

}

void E2proomData::check_para()
{
    if(als1_threshold<als1_threshold_min||als1_threshold>als1_threshold_max)
        als1_threshold=als1_threshold_use;
}

void E2proomData::read_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_ALG1_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(E2POOM_ALG1_LASERIMAGEPOS_SYSPATH_MOTO,buff,E2POOM_ALG1_LASERIMAGEPOS_SAVEBUFF))
    {
        init_als1_para();
        if(buff!=NULL)
        {
          delete []buff;
          buff=NULL;
        }
    }
    else
    {
      Int16 *i16_p;

      i16_p = (Int16*)buff;
      als1_threshold=*i16_p;
      i16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }


}

void E2proomData::write_als1_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_ALG1_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
      return;

    Int16 *i16_p;

    i16_p = (Int16*)buff;
    *i16_p=als1_threshold;
    i16_p++;


    fo.WriteFile(E2POOM_ALG1_LASERIMAGEPOS_SYSPATH_MOTO,buff,E2POOM_ALG1_LASERIMAGEPOS_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_als1_para()
{
    als1_threshold=als1_threshold_use;
}

void E2proomData::write()
{
    write_als1_para();
}
