#include "fileout/E2proomData.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>  
#include <unistd.h>
#include <json/jsonfuction.h>

rob_pinfo::rob_pinfo()
{
  x=0;
  y=0;
  z=0;
  rx=0;
  ry=0;
  rz=0;
  out1=0;
  out2=0;
  out3=0;
  tool=0;
  tcp=0;
  usertcp=0;
  uy=0;
  vz=0;
}

E2proomData::E2proomData()
{
    std::string dir = "./SAVE";
    if (access(dir.c_str(), 0) == -1)
    {
      mkdir("./SAVE",S_IRWXU);
    }

    dir = "./SAVE/DATA";
    if (access(dir.c_str(), 0) == -1)
    {
      mkdir("./SAVE/DATA",S_IRWXU);
    }

    matrix_camera2plane=cv::Mat::zeros(3,3,CV_64F);
    matrix_plane2robot=cv::Mat::zeros(3,3,CV_64F);

    task_num_min=E2POOM_TASK_NUM_MIN;
    task_num_use=E2POOM_TASK_NUM_USE;
    task_num_max=E2POOM_TASK_NUM_MAX;

    robot_port_min=E2POOM_ROBOT_PORT_MIN;
    robot_port_max=E2POOM_ROBOT_PORT_MAX;
    robot_port_use=E2POOM_ROBOT_PORT_USE;

    zero_pointX_use=E2POOM_ZEROPOINT_X_USE;
    zero_pointY_use=E2POOM_ZEROPOINT_Y_USE;
    zero_pointZ_use=E2POOM_ZEROPOINT_Z_USE;

    P_data_En_min=E2POOM_P_DATA_EN_MIN;
    P_data_En_max=E2POOM_P_DATA_EN_MAX;
    P_data_En_use=E2POOM_P_DATA_EN_USE;
    
    Init_als100_E2proomData();
    Init_als101_E2proomData();
    Init_als102_E2proomData();
    Init_als103_E2proomData();
    Init_als104_E2proomData();
    Init_als105_E2proomData();
    Init_als106_E2proomData();
    Init_als107_E2proomData();
    Init_als108_E2proomData();

    read_para();

    write_task_num_para();
    write_robot_para();
    write_P_data_set_para();
    write_P_data_para();
    write_demdlg_para();
    write_craftdlg_para();
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
       robot_mod!=E2POOM_ROBOT_MOD_ZEGE_2&&
       robot_mod!=E2POOM_ROBOT_MOD_HUACHENG&&
       robot_mod!=E2POOM_ROBOT_MOD_STEP
      )
      robot_mod=E2POOM_ROBOT_MOD_NULL;

    if(robot_port<robot_port_min||robot_port>robot_port_max)
        robot_port=robot_port_use;

    if(P_data_En<P_data_En_min||P_data_En>P_data_En_max)
        P_data_En=P_data_En_use;

    als100_check_para();
    als101_check_para();
    als102_check_para();
    als103_check_para();
    als104_check_para();
    als105_check_para();
    als106_check_para();
    als107_check_para();
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

    buff=new Uint8[E2POOM_ZEROPOINT_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(E2POOM_ZEROPOINT_SYSPATH_MOTO,buff,E2POOM_ZEROPOINT_SAVEBUFF))
    {
        init_zeropoint_para();
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
      zero_pointX=*i16_p;
      i16_p++;
      zero_pointY=*i16_p;
      i16_p++;
      zero_pointZ=*i16_p;
      i16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

    buff=new Uint8[E2POOM_P_DATA_SET_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(E2POOM_P_DATA_SET_SYSPATH_MOTO,buff,E2POOM_P_DATA_SET_SAVEBUFF))
    {
        init_P_data_set_para();
        if(buff!=NULL)
        {
          delete []buff;
          buff=NULL;
        }
    }
    else
    {
      Int8 *i8_p;
      
      i8_p = (Int8*)buff;
      P_data_En=*i8_p;
      i8_p++;
      P_data_cal_posture=(CAL_POSTURE)*i8_p;
      i8_p++;
      P_data_eye_hand_calibrationmode=(Eye_Hand_calibrationmode)*i8_p;
      i8_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

    buff=new Uint8[E2POOM_CRAFT_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(E2POOM_CRAFT_SYSPATH_MOTO,buff,E2POOM_CRAFT_SAVEBUFF))
    {
        init_craftdlg_para();
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
      craft_Id=*i16_p;
      i16_p++;
      craft_als1=*i16_p;
      i16_p++;
      craft_als2=*i16_p;
      i16_p++;
      craft_als3=*i16_p;
      i16_p++;
      craft_als4=*i16_p;
      i16_p++;
      craft_als5=*i16_p;
      i16_p++;
      craft_als6=*i16_p;
      i16_p++;
      craft_als7=*i16_p;
      i16_p++;
      craft_als8=*i16_p;
      i16_p++;
      craft_als9=*i16_p;
      i16_p++;
      craft_als10=*i16_p;
      i16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

    read_P_data();
    read_demdlg_para();

    als100_read_para(E2POOM_ALG100_LASERIMAGEPOS_SYSPATH_MOTO);
    als101_read_para(E2POOM_ALG101_LASERIMAGEPOS_SYSPATH_MOTO);
    als102_read_para(E2POOM_ALG102_LASERIMAGEPOS_SYSPATH_MOTO);
    als103_read_para(E2POOM_ALG103_LASERIMAGEPOS_SYSPATH_MOTO);
    als104_read_para(E2POOM_ALG104_LASERIMAGEPOS_SYSPATH_MOTO);
    als105_read_para(E2POOM_ALG105_LASERIMAGEPOS_SYSPATH_MOTO);
    als106_read_para(E2POOM_ALG106_LASERIMAGEPOS_SYSPATH_MOTO);
    als107_read_para(E2POOM_ALG107_LASERIMAGEPOS_SYSPATH_MOTO);
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

void E2proomData::write_zeropoint_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_ZEROPOINT_SAVEBUFF];
    if(buff==NULL)
      return;

    Int16 *i16_p;

    i16_p = (Int16*)buff;
    *i16_p=zero_pointX;
    i16_p++;
    *i16_p=zero_pointY;
    i16_p++;
    *i16_p=zero_pointZ;
    i16_p++;

    fo.WriteFile(E2POOM_ZEROPOINT_SYSPATH_MOTO,buff,E2POOM_ZEROPOINT_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_zeropoint_para()
{
    zero_pointX=zero_pointX_use;
    zero_pointY=zero_pointY_use;
    zero_pointZ=zero_pointZ_use;
}

void E2proomData::write_P_data_set_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_P_DATA_SET_SAVEBUFF];
    if(buff==NULL)
      return;

    Int8 *i8_p;

    i8_p = (Int8*)buff;
    *i8_p=P_data_En;
    i8_p++;
    *i8_p=P_data_cal_posture;
    i8_p++;
    *i8_p=P_data_eye_hand_calibrationmode;
    i8_p++;

    fo.WriteFile(E2POOM_P_DATA_SET_SYSPATH_MOTO,buff,E2POOM_P_DATA_SET_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_P_data_set_para()
{
  P_data_En=P_data_En_use;
  P_data_cal_posture=CAL_ROBOT_YASKAWA;
  P_data_eye_hand_calibrationmode=HAND_IN_EYE;
}

void E2proomData::init_P_data()
{
  rob_pinfo pos;
  rob_group singl;
  /*******/
  P_data.clear();
  //这里添加存储的标定点
  singl.pos.clear();
  singl.pos.resize(1);
  singl.pID=0;
  P_data.push_back(singl);
  
  singl.pos.clear();
  singl.pos.resize(1);
  singl.pID=1;
  P_data.push_back(singl);

  singl.pos.clear();
  singl.pos.resize(1);
  singl.pID=3;
  P_data.push_back(singl);

  singl.pos.clear();
  singl.pos.resize(1);
  singl.pID=11;
  P_data.push_back(singl);

  singl.pos.clear();
  singl.pos.resize(1);
  singl.pID=1001;
  P_data.push_back(singl);

  singl.pos.clear();
  singl.pos.resize(1);
  singl.pID=1002;
  P_data.push_back(singl);
}

//把P变量初始化
void E2proomData::read_P_data()
{
  jsonfuction jsonf;
  Json::Value root;
  Json::Value j_Pdata;
  Json::Value temp;
  if(0!=jsonf.readJsonFile(E2POOM_P_DATA_SYSPATH_MOTO,&root))
  {
    init_P_data();
    return;
  }
  /**************************/
  //读取P点
  j_Pdata=root.get("P_data","NULL"); 
  if(j_Pdata=="NULL")
  {
    init_P_data();
    return;
  }
  P_data.resize(j_Pdata.size());
  for(int i=0;i<j_Pdata.size();i++)
  {
    rob_pinfo pos;
    rob_group singl;
    Json::Value j_pos=j_Pdata[i].get("pos","NULL");
    if(j_pos=="NULL")
    {
      init_P_data();
      return;
    }
    temp=j_Pdata[i].get("pID","NULL");
    if(temp=="NULL")
    {
      init_P_data();
      return;
    }
    P_data[i].pID=temp.asInt();
    P_data[i].pos.resize(j_pos.size());
    for(int j=0;j<j_pos.size();j++)
    {
      temp=j_pos[j].get("x","NULL");
      if(temp!="NULL")
      {
        P_data[i].pos[j].x=temp.asFloat();
      }
      temp=j_pos[j].get("y","NULL");
      if(temp!="NULL")
      {
        P_data[i].pos[j].y=temp.asFloat();
      }
      temp=j_pos[j].get("z","NULL");
      if(temp!="NULL")
      {
        P_data[i].pos[j].z=temp.asFloat();
      }
      temp=j_pos[j].get("rx","NULL");
      if(temp!="NULL")
      {
        P_data[i].pos[j].rx=temp.asFloat();
      }
      temp=j_pos[j].get("ry","NULL");
      if(temp!="NULL")
      {
        P_data[i].pos[j].ry=temp.asFloat();
      }
      temp=j_pos[j].get("rz","NULL");
      if(temp!="NULL")
      {
        P_data[i].pos[j].rz=temp.asFloat();
      }
      temp=j_pos[j].get("out1","NULL");
      if(temp!="NULL")
      {
        P_data[i].pos[j].out1=temp.asInt();
      }
      temp=j_pos[j].get("out2","NULL");
      if(temp!="NULL")
      {
        P_data[i].pos[j].out2=temp.asInt();
      }
      temp=j_pos[j].get("out3","NULL");
      if(temp!="NULL")
      {
        P_data[i].pos[j].out3=temp.asInt();
      }
      temp=j_pos[j].get("tcp","NULL");
      if(temp!="NULL")
      {
        P_data[i].pos[j].tcp=temp.asFloat();
      }
      temp=j_pos[j].get("tool","NULL");
      if(temp!="NULL")
      {
        P_data[i].pos[j].tool=temp.asFloat();
      }
      temp=j_pos[j].get("usertcp","NULL");
      if(temp!="NULL")
      {
        P_data[i].pos[j].usertcp=temp.asFloat();
      }
      temp=j_pos[j].get("uy","NULL");
      if(temp!="NULL")
      {
        P_data[i].pos[j].uy=temp.asFloat();
      }
      temp=j_pos[j].get("vz","NULL");
      if(temp!="NULL")
      {
        P_data[i].pos[j].vz=temp.asFloat();
      }
    }
  }
  /***************************/
}

void E2proomData::write_P_data_para()
{
  jsonfuction jsonf;
  Json::Value root;
  for(int i=0;i<P_data.size();i++)
  {
    Json::Value j_sing;
    j_sing["pID"]=P_data[i].pID;
    for(int j=0;j<P_data[i].pos.size();j++)
    {
      Json::Value j_sing_data;
      j_sing_data["x"]=P_data[i].pos[j].x;
      j_sing_data["y"]=P_data[i].pos[j].y;
      j_sing_data["z"]=P_data[i].pos[j].z;
      j_sing_data["rx"]=P_data[i].pos[j].rx;
      j_sing_data["ry"]=P_data[i].pos[j].ry;
      j_sing_data["rz"]=P_data[i].pos[j].rz;
      j_sing_data["out1"]=P_data[i].pos[j].out1;
      j_sing_data["out2"]=P_data[i].pos[j].out2;
      j_sing_data["out3"]=P_data[i].pos[j].out3;
      j_sing_data["tool"]=P_data[i].pos[j].tool;
      j_sing_data["tcp"]=P_data[i].pos[j].tcp;
      j_sing_data["usertcp"]=P_data[i].pos[j].usertcp;
      j_sing_data["uy"]=P_data[i].pos[j].uy;
      j_sing_data["vz"]=P_data[i].pos[j].vz;
      j_sing["pos"].append(j_sing_data);
    } 
    root["P_data"].append(j_sing);
  }

  jsonf.writeJsonFile(E2POOM_P_DATA_SYSPATH_MOTO,root);
}

void E2proomData::read_demdlg_para()
{
  jsonfuction jsonf;
  Json::Value root;
  Json::Value arrData1;
  Json::Value arrData2;
  Json::Value arrData3;
  Json::Value arrData4;
  if(0!=jsonf.readJsonFile(E2POOM_DEMDLG_SYSPATH_MOTO,&root))
  {
    return;
  } 

  arrData1=root.get("demdlg_R","NULL"); 
  if(arrData1!="NULL")
  {
    if(arrData1.size()==9)
    {
      int n=0;
      for(int j=0;j<3;j++)
      {
        for(int i=0;i<3;i++)
        {
            demdlg_R(j,i)=arrData1[n++].asDouble();
        }
      }
    }
  }

  arrData2=root.get("demdlg_T","NULL"); 
  if(arrData2.size()==3)
  {
    for(int i=0;i<3;i++)
    {
        demdlg_T(i)=arrData2[i].asDouble();
    }
  }
  
  arrData3=root.get("matrix_camera2plane","NULL"); 
  if(arrData3.size()==9)
  {
    int n=0;
    for(int j=0;j<3;j++)
    {
        double *d= matrix_camera2plane.ptr<double>(j);
        for(int i=0;i<3;i++)
        {
          d[i]=arrData3[n++].asDouble();
        }
    }
  }
  
  arrData4=root.get("matrix_plane2robot","NULL"); 
  if(arrData4.size()==9)
  {
    int n=0;
    for(int j=0;j<3;j++)
    {
        double *d= matrix_plane2robot.ptr<double>(j);
        for(int i=0;i<3;i++)
        {
          d[i]=arrData4[n++].asDouble();
        }
    }
  }
}

void E2proomData::write_demdlg_para()
{
  jsonfuction jsonf;
  Json::Value root;
  Json::Value arrData1;

  for (int j=0;j<3;j++)
    for(int i=0;i<3;i++)
      arrData1.append(demdlg_R(j,i));
  root["demdlg_R"]=arrData1;

  Json::Value arrData2;
    for (int i=0;i<3;i++)
        arrData2.append(demdlg_T(i));
  root["demdlg_T"]=arrData2;

  Json::Value arrData3;
  for (int j=0;j<3;j++)
  {
      double *d= matrix_camera2plane.ptr<double>(j);
      for (int i=0;i<3;i++)
      {
          arrData3.append(d[i]);
      }
  }
  root["matrix_camera2plane"]=arrData3;

  Json::Value arrData4;
  for (int j=0;j<3;j++)
  {
      double *d= matrix_plane2robot.ptr<double>(j);
      for (int i=0;i<3;i++)
      {
          arrData4.append(d[i]);
      }
  }
  root["matrix_plane2robot"]=arrData4;

  jsonf.writeJsonFile(E2POOM_DEMDLG_SYSPATH_MOTO,root);
}

void E2proomData::init_craftdlg_para()
{
    craft_Id=0;
    craft_als1=0;
    craft_als2=0;
    craft_als3=0;
    craft_als4=0;
    craft_als5=0;
    craft_als6=0;
    craft_als7=0;
    craft_als8=0;
    craft_als9=0;
    craft_als10=0;
}

void E2proomData::write_craftdlg_para()
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_CRAFT_SAVEBUFF];
    if(buff==NULL)
      return;

    Int16 *i16_p;

    i16_p = (Int16*)buff;
    *i16_p=craft_Id;
    i16_p++;
    *i16_p=craft_als1;
    i16_p++;
    *i16_p=craft_als2;
    i16_p++;
    *i16_p=craft_als3;
    i16_p++;
    *i16_p=craft_als4;
    i16_p++;
    *i16_p=craft_als5;
    i16_p++;
    *i16_p=craft_als6;
    i16_p++;
    *i16_p=craft_als7;
    i16_p++;
    *i16_p=craft_als8;
    i16_p++;
    *i16_p=craft_als9;
    i16_p++;
    *i16_p=craft_als10;
    i16_p++;

    fo.WriteFile(E2POOM_CRAFT_SYSPATH_MOTO,buff,E2POOM_CRAFT_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
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
    write_als107_para(E2POOM_ALG107_LASERIMAGEPOS_SYSPATH_MOTO);
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
    case 107:
      write_als107_para(filename);
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
        case 107:
          als107_read_para(filename);
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