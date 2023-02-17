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

    task_num_min=E2POOM_TASK_NUM_MIN;
    task_num_use=E2POOM_TASK_NUM_USE;
    task_num_max=E2POOM_TASK_NUM_MAX;

    robot_port_min=E2POOM_ROBOT_PORT_MIN;
    robot_port_max=E2POOM_ROBOT_PORT_MAX;
    robot_port_use=E2POOM_ROBOT_PORT_USE;
 
    
    Init_als100_E2proomData();
    Init_als101_E2proomData();
    Init_als102_E2proomData();
    Init_als103_E2proomData();
    Init_als104_E2proomData();
    Init_als105_E2proomData();
    Init_als106_E2proomData();
    Init_als108_E2proomData();

    read_para();

    write_task_num_para();
    write_robot_para();
    write();

    taskfilename.clear();
    findtaskfile(&taskfilename);
}

E2proomData::~E2proomData()
{

}

void E2proomData::check_para()
{
    if(task_num<task_num_min||task_num_min>task_num_max)
      task_num=task_num_use;

    if(robot_mod!=E2POOM_ROBOT_MOD_NULL&&
       robot_mod!=E2POOM_ROBOT_MOD_ZHICHANG&&
       robot_mod!=E2POOM_ROBOT_MOD_ZHICHANG_KAWASAKI&&
       robot_mod!=E2POOM_ROBOT_MOD_MOKA_NABOTE&&
       robot_mod!=E2POOM_ROBOT_MOD_GANGSHANG&&
       robot_mod!=E2POOM_ROBOT_MOD_EFORT&&
       robot_mod!=E2POOM_ROBOT_MOD_MOKA&&
       robot_mod!=E2POOM_ROBOT_MOD_ZEGE_2
      )
      robot_mod=E2POOM_ROBOT_MOD_NULL;

    if(robot_port<robot_port_min||robot_port>robot_port_max)
        robot_port=robot_port_use;

    als100_check_para();
    als101_check_para();
    als102_check_para();
    als103_check_para();
    als104_check_para();
    als105_check_para();
    als106_check_para();
    als108_check_para();
}

void E2proomData::read_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_TASK_NUM_SAVEBUFF];    
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(E2POOM_TASK_NUM_SYSPATH_MOTO,buff,E2POOM_TASK_NUM_SAVEBUFF))
    {
        init_task_num_para();
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
      task_num=*u16_p;
      u16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }


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

    als100_read_para(E2POOM_ALG100_LASERIMAGEPOS_SYSPATH_MOTO);
    als101_read_para(E2POOM_ALG101_LASERIMAGEPOS_SYSPATH_MOTO);
    als102_read_para(E2POOM_ALG102_LASERIMAGEPOS_SYSPATH_MOTO);
    als103_read_para(E2POOM_ALG103_LASERIMAGEPOS_SYSPATH_MOTO);
    als104_read_para(E2POOM_ALG104_LASERIMAGEPOS_SYSPATH_MOTO);
    als105_read_para(E2POOM_ALG105_LASERIMAGEPOS_SYSPATH_MOTO);
    als106_read_para(E2POOM_ALG106_LASERIMAGEPOS_SYSPATH_MOTO);
    als108_read_para(E2POOM_ALG108_LASERIMAGEPOS_SYSPATH_MOTO);
    
    check_para();

}

void E2proomData::write_task_num_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_TASK_NUM_SAVEBUFF];
    if(buff==NULL)
      return;

    Uint16 *u16_p;

    u16_p = (Uint16*)buff;
    *u16_p=task_num;
    u16_p++;

    fo.WriteFile(E2POOM_TASK_NUM_SYSPATH_MOTO,buff,E2POOM_TASK_NUM_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_task_num_para()
{
    task_num=E2POOM_TASK_NUM_USE;
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
    Int16 *i16_p;

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
    write_als100_para(E2POOM_ALG100_LASERIMAGEPOS_SYSPATH_MOTO);
    write_als101_para(E2POOM_ALG101_LASERIMAGEPOS_SYSPATH_MOTO);
    write_als102_para(E2POOM_ALG102_LASERIMAGEPOS_SYSPATH_MOTO);
    write_als103_para(E2POOM_ALG103_LASERIMAGEPOS_SYSPATH_MOTO);
    write_als104_para(E2POOM_ALG104_LASERIMAGEPOS_SYSPATH_MOTO);
    write_als105_para(E2POOM_ALG105_LASERIMAGEPOS_SYSPATH_MOTO);
    write_als106_para(E2POOM_ALG106_LASERIMAGEPOS_SYSPATH_MOTO);
    write_als108_para(E2POOM_ALG108_LASERIMAGEPOS_SYSPATH_MOTO);
}

void E2proomData::findtaskfile(std::vector<taskinfo> *filename)
{
  taskinfo sing;
  DIR *dir = opendir(E2POOM_ALG_LASERIMAGEPOS_SYSPATH);
	if(dir == NULL) {
		return;
	}
  struct dirent *ent;
	while((ent = readdir(dir)) != NULL)
	{
    if(strcmp(".", ent->d_name) ==0 || strcmp("..", ent->d_name) == 0)
    {
      continue;
    }
		//在指定的目录下去找APROM开头的文件
    if (ent->d_type == DT_REG)
    {
      //默认任务号
      if(strncmp(ent->d_name,E2POOM_ALG_LASERIMAGEPOS_SYSPATH_MOTO,strlen(E2POOM_ALG_LASERIMAGEPOS_SYSPATH_MOTO)) == 0)
      {
        int lenth=strlen(E2POOM_ALG_LASERIMAGEPOS_SYSPATH_MOTO);
        char src[50];
        char *end=strchr(ent->d_name,'.');
        memcpy(src,ent->d_name+lenth,end-(ent->d_name)-lenth);
        src[end-(ent->d_name)-lenth]='\0';
        char *end2=strchr(src,'_');
        if(end2==NULL)
        {
          sing.taskname=atoi(src);
          sing.alsnum=atoi(src);
        }
        else
        {
          char src1[50];
          char alg1[50];
          memcpy(src1,src,end2-src);
          src1[end2-src]='\0';
          memcpy(alg1,end2+1,strlen(src)-(end2-src)-1);
          alg1[strlen(src)-(end2-src)-1]='\0';
          sing.taskname=atoi(src1);
          sing.alsnum=atoi(alg1);
        }
        
        filename->push_back(sing);
      }
    }
	}
  closedir(dir);
}

void E2proomData::savetaskfile(uint16_t tasknum,uint16_t alsnum)
{
  char filename[50]=E2POOM_ALG_LASERIMAGEPOS_SYSPATH_MOTOF;
  char filename2[50];
  
  if(tasknum<200&&tasknum>=100)//自定义任务号不能在100-200之间
  {
    return;
  }
  if(alsnum<200&&alsnum>=100)
  {
    //删除掉这个任务号
    char filename3[50]=E2POOM_ALG_LASERIMAGEPOS_SYSPATH_MOTO;
    char filename4[50];
    sprintf(filename4,"%d_",tasknum);
    strcat(filename3,filename4);
    DIR *dir = opendir(E2POOM_ALG_LASERIMAGEPOS_SYSPATH);
    if(dir == NULL) {
      return;
    }
    struct dirent *ent;
    while((ent = readdir(dir)) != NULL)
    {
      if(strcmp(".", ent->d_name) ==0 || strcmp("..", ent->d_name) == 0)
      {
        continue;
      }
      //在指定的目录下去找APROM开头的文件
      if (ent->d_type == DT_REG)
      {
        if(strncmp(ent->d_name,filename3,strlen(filename3)) == 0)
        {
          char filename5[50]=E2POOM_ALG_LASERIMAGEPOS_SYSPATH;
          char filename6[50];
          sprintf(filename6,"/%s",ent->d_name);
          strcat(filename5,filename6);
          remove(filename5);
        }
      }
    }

    sprintf(filename2,"%d_%d.bsd",tasknum,alsnum);
    strcat(filename,filename2);
    switch (alsnum)
    {
    case 100:
      write_als100_para(filename);
      break;
    case 101:
      write_als101_para(filename);
      break;
    case 102:
      write_als102_para(filename);
      break;  
    case 103:
      write_als103_para(filename);
      break;
    case 104:
      write_als104_para(filename);
      break;
    case 105:
      write_als105_para(filename);
      break;
    case 106:
      write_als106_para(filename);
      break;
    case 108:
      write_als108_para(filename);
      break;
    default:
      break;
    }
    
  }
}

void E2proomData::rmalltaskfile()
{
  taskinfo sing;
  DIR *dir = opendir(E2POOM_ALG_LASERIMAGEPOS_SYSPATH);
	if(dir == NULL) {
		return;
	}
  struct dirent *ent;
	while((ent = readdir(dir)) != NULL)
	{
    if(strcmp(".", ent->d_name) ==0 || strcmp("..", ent->d_name) == 0)
    {
      continue;
    }
		//在指定的目录下去找APROM开头的文件
    if (ent->d_type == DT_REG)
    {
      //默认任务号
      if(strncmp(ent->d_name,E2POOM_ALG_LASERIMAGEPOS_SYSPATH_MOTO,strlen(E2POOM_ALG_LASERIMAGEPOS_SYSPATH_MOTO)) == 0)
      {
        int lenth=strlen(E2POOM_ALG_LASERIMAGEPOS_SYSPATH_MOTO);
        char src[50];
        char *end=strchr(ent->d_name,'.');
        memcpy(src,ent->d_name+lenth,end-(ent->d_name)-lenth);
        src[end-(ent->d_name)-lenth]='\0';
        char *end2=strchr(src,'_');
        if(end2!=NULL)
        {
          char filename5[50]=E2POOM_ALG_LASERIMAGEPOS_SYSPATH;
          char filename6[50];
          sprintf(filename6,"/%s",ent->d_name);
          strcat(filename5,filename6);
          remove(filename5);
        }
      }
    }
	}
  closedir(dir);
}

void E2proomData::rmtaskfile(uint16_t tasknum)
{
  if(tasknum<200&&tasknum>=100)//自定义任务号不能在100-200之间
  {
    return;
  }
    //删除掉这个任务号
  char filename3[50]=E2POOM_ALG_LASERIMAGEPOS_SYSPATH_MOTO;
  char filename4[50];
  sprintf(filename4,"%d_",tasknum);
  strcat(filename3,filename4);
  DIR *dir = opendir(E2POOM_ALG_LASERIMAGEPOS_SYSPATH);
  if(dir == NULL) {
    return;
  }
  struct dirent *ent;
  while((ent = readdir(dir)) != NULL)
  {
    if(strcmp(".", ent->d_name) ==0 || strcmp("..", ent->d_name) == 0)
    {
      continue;
    }
    //在指定的目录下去找APROM开头的文件
    if (ent->d_type == DT_REG)
    {
      if(strncmp(ent->d_name,filename3,strlen(filename3)) == 0)
      {
        char filename5[50]=E2POOM_ALG_LASERIMAGEPOS_SYSPATH;
        char filename6[50];
        sprintf(filename6,"/%s",ent->d_name);
        strcat(filename5,filename6);
        remove(filename5);
      }
    }
  }  
  closedir(dir);  
}

int E2proomData::loadtaskfile(uint16_t tasknum)
{
  bool find=false;
  int als=tasknum;
  char filename[50]=E2POOM_ALG_LASERIMAGEPOS_SYSPATH_MOTOF;
  taskfilename.clear();
  findtaskfile(&taskfilename);
  for(int i=0;i<taskfilename.size();i++)
  {
    if(taskfilename[i].taskname==tasknum)
    {
      find=true;
      als=taskfilename[i].alsnum;
      if(tasknum<200&&tasknum>=100)
      {
        char filename1[50];
        sprintf(filename1,"%d.bsd",tasknum);
        strcat(filename,filename1);
      }
      else  //在自定义任务号里
      {
        char filename1[50];
        sprintf(filename1,"%d_%d.bsd",tasknum,als);
        strcat(filename,filename1);
      }
      switch (als)
      {
        case 100:
          als100_read_para(filename);
          break;
        case 101:
          als101_read_para(filename);
          break;
        case 102:
          als102_read_para(filename);
          break;  
        case 103:
          als103_read_para(filename);
          break;
        case 104:
          als104_read_para(filename);
          break;
        case 105:
          als105_read_para(filename);
          break;
        case 106:
          als106_read_para(filename);
          break;
        case 108:
          als108_read_para(filename);
          break;
        default:
          break;
      }
      break;
    }
  }  
  if(find==false)
  {
    als=tasknum;
  }
  return als;
}