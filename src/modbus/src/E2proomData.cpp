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

    robot_port_min=E2POOM_ROBOT_PORT_MIN;
    robot_port_max=E2POOM_ROBOT_PORT_MAX;
    robot_port_use=E2POOM_ROBOT_PORT_USE;
    als100_threshold_min=E2POOM_ALG100_LASERIMAGEPOS_THRESHOLD_MIN;
    als100_threshold_max=E2POOM_ALG100_LASERIMAGEPOS_THRESHOLD_MAX;
    als100_threshold_use=E2POOM_ALG100_LASERIMAGEPOS_THRESHOLD_USE;

    read_para();
}

E2proomData::~E2proomData()
{

}

void E2proomData::check_para()
{
    if(robot_mod!=E2POOM_ROBOT_MOD_NULL&&
       robot_mod!=E2POOM_ROBOT_MOD_ZHICHANG&&
       robot_mod!=E2POOM_ROBOT_MOD_ZHICHANG_KAWASAKI&&
       robot_mod!=E2POOM_ROBOT_MOD_MOKA_NABOTE
      )
      robot_mod=E2POOM_ROBOT_MOD_NULL;

    if(robot_port<robot_port_min||robot_port>robot_port_max)
        robot_port=robot_port_use;
    if(als100_threshold<als100_threshold_min||als100_threshold>als100_threshold_max)
        als100_threshold=als100_threshold_use;
}

void E2proomData::read_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_ROBOT_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(E2POOM_ROBOT_SYSPATH_MOTO,buff,E2POOM_ROBOT_SAVEBUFF))
    {
        init_robot_para();
        if(buff!=NULL)
        {
          delete []buff;
          buff=NULL;
        }
    }
    else
    {
      Uint16 *u16_p;

      u16_p = (Uint16*)buff;
      robot_mod=*u16_p;
      u16_p++;
      robot_port=*u16_p;
      u16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

    buff=new Uint8[E2POOM_ALG100_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(E2POOM_ALG100_LASERIMAGEPOS_SYSPATH_MOTO,buff,E2POOM_ALG100_LASERIMAGEPOS_SAVEBUFF))
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
      Int16 *i16_p;

      i16_p = (Int16*)buff;
      als100_threshold=*i16_p;
      i16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

    check_para();

}

void E2proomData::write_als100_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_ALG100_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
      return;

    Int16 *i16_p;

    i16_p = (Int16*)buff;
    *i16_p=als100_threshold;
    i16_p++;


    fo.WriteFile(E2POOM_ALG100_LASERIMAGEPOS_SYSPATH_MOTO,buff,E2POOM_ALG100_LASERIMAGEPOS_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_als100_para()
{
    als100_threshold=als100_threshold_use;
}

void E2proomData::write_robot_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_ROBOT_SAVEBUFF];
    if(buff==NULL)
      return;

    Uint16 *u16_p;

    u16_p = (Uint16*)buff;
    *u16_p=robot_mod;
    u16_p++;
    *u16_p=robot_port;
    u16_p++;

    fo.WriteFile(E2POOM_ROBOT_SYSPATH_MOTO,buff,E2POOM_ROBOT_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_robot_para()
{
    robot_mod=E2POOM_ROBOT_MOD_NULL;
    robot_port=E2POOM_ROBOT_PORT_USE;
}

void E2proomData::write()
{
    write_als100_para();
}
