#include "fileout/E2centerData.h"
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

    compensation_dx=0;
    compensation_dy=0;
    compensation_dz=0;
    reverse_y=0;
    reverse_z=0;

    read_para();
}

E2proomData::~E2proomData()
{

}

void E2proomData::check_para()
{

}

void E2proomData::read_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_CENTER_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(E2POOM_CENTER_SYSPATH_MOTO,buff,E2POOM_CENTER_SAVEBUFF))
    {
        init_center_para();
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
      compensation_dx=*i16_p;
      i16_p++;
      compensation_dy=*i16_p;
      i16_p++;
      compensation_dz=*i16_p;
      i16_p++;
      reverse_y=*i16_p;
      i16_p++;
      reverse_z=*i16_p;
      i16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
    
    check_para();

}

void E2proomData::write_center_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_CENTER_SAVEBUFF];
    if(buff==NULL)
      return;

    Int16 *i16_p;

    i16_p = (Int16*)buff;
    *i16_p=compensation_dx;
    i16_p++;
    *i16_p=compensation_dy;
    i16_p++;
    *i16_p=compensation_dz;
    i16_p++;
    *i16_p=reverse_y;
    i16_p++;
    *i16_p=reverse_z;
    i16_p++;

    fo.WriteFile(E2POOM_CENTER_SYSPATH_MOTO,buff,E2POOM_CENTER_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_center_para()
{
    compensation_dx=0;
    compensation_dy=0;
    compensation_dz=0;
    reverse_y=0;
    reverse_z=0;
}
