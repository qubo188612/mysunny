#include <cstdio>
#include <modbus/modbus.hpp>
#include <modbus.h>
#include <unistd.h>
#include <fileout/FileOut.h>
#include <fileout/E2proomData.h>
#include <memory>
#include <set>

namespace modbus
{

int Modbus::als100_task_parameter(int ddr,u_int16_t num)
{
    switch(ddr)
    {
        case ALS100_EXPOSURE_TIME_REG_ADD:
            e2proomdata.als100_exposure_time=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_exposure_time", num)});
            return 1;
        break;
        case ALS100_PINGJUN_REG_ADD:
            e2proomdata.als100_pingjun=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_pingjun", (int16_t)num)});
            return 1;
        break;
        case ALS100_B_YANMOFUZHU_REG_ADD:
            e2proomdata.als100_b_yanmofuzhu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_b_yanmofuzhu", (int16_t)num)});
            return 1;
        break;
        case ALS100_B_GUDINGQUYU_REG_ADD:
            e2proomdata.als100_b_gudingquyu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_b_gudingquyu", (int16_t)num)});
            return 1;
        break;
        case ALS100_WIDTHLIANTONGDIS_REG_ADD:
            e2proomdata.als100_widthliantongdis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_widthliantongdis", (int16_t)num)});
            return 1;
        break;
        case ALS100_HIGHLIANTONGDIS_REG_ADD:
            e2proomdata.als100_highliantongdis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_highliantongdis", (int16_t)num)});
            return 1;
        break;
        case ALS100_GUJIAERZHI_REG_ADD:
            e2proomdata.als100_gujiaerzhi=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_gujiaerzhi", (int16_t)num)});
            return 1;
        break;
        case ALS100_JIGUANGHIGHT_REG_ADD:
            e2proomdata.als100_jiguanghight=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_jiguanghight", (int16_t)num)});
            return 1;
        break;
        case ALS100_JIGUANGLONG_REG_ADD:
            e2proomdata.als100_jiguanglong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_jiguanglong", (int16_t)num)});
            return 1;
        break;
        case ALS100_JIGUANGKUANDU_REG_ADD:
            e2proomdata.als100_jiguangkuandu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_jiguangkuandu", (int16_t)num)});
            return 1;
        break;
        case ALS100_UPDIF_REG_ADD:
            e2proomdata.als100_Updif=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Updif", (int16_t)num)});
            return 1;
        break;
        case ALS100_UPDIFMIN_REG_ADD:
            e2proomdata.als100_Updifmin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Updifmin", (int16_t)num)});
            return 1;
        break;
        case ALS100_UPLONG_REG_ADD:
            e2proomdata.als100_Uplong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Uplong",(int16_t)num)});
            return 1;
        break;
        case ALS100_DOWNDIF_REG_ADD:
            e2proomdata.als100_Downdif=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Downdif", (int16_t)num)});
            return 1;
        break;
        case ALS100_DOWNDIFMIN_REG_ADD:
            e2proomdata.als100_Downdifmin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Downdifmin", (int16_t)num)});
            return 1;
        break;
        case ALS100_DOWNDLONG_REG_ADD:
            e2proomdata.als100_Downdlong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Downdlong", (int16_t)num)});
            return 1;
        break;
        case ALS100_DUANXIANERZHI_REG_ADD:
            e2proomdata.als100_duanxianerzhi=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_duanxianerzhi", (int16_t)num)});
            return 1;
        break;
        case ALS100_ERZHISIZE_REG_ADD:
            e2proomdata.als100_erzhisize=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_erzhisize", (int16_t)num)});
            return 1;
        break;
        case ALS100_ERZHISIZE2_REG_ADD:
            e2proomdata.als100_erzhisize2=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_erzhisize2", (int16_t)num)});
            return 1;
        break;
        case ALS100_SEARCHDECTANCEMAX_REG_ADD:
            e2proomdata.als100_searchdectancemax=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_searchdectancemax", (int16_t)num)});
            return 1;
        break;
        case ALS100_SEARCHDECTANCEMIN_REG_ADD:
            e2proomdata.als100_searchdectancemin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_searchdectancemin", (int16_t)num)});
            return 1;
        break;
        case ALS100_DIS_CENTER_ST_REG_ADD:
            e2proomdata.als100_dis_center_st=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_dis_center_st", (int16_t)num)});
            return 1;
        break;
        case ALS100_DIS_CENTER_ED_REG_ADD:
            e2proomdata.als100_dis_center_ed=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_dis_center_ed", (int16_t)num)});
            return 1;
        break;
        case ALS100_ANSWERPOINT_REG_ADD:
            e2proomdata.als100_answerpoint=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_answerpoint", (int16_t)num)});
            return 1;
        break;

        case ALS100_INIT_REG_ADD:
            if(num==1)
            {
                e2proomdata.init_als100_para();
                init_als100_parameter();
                parameterport_mapping->tab_registers[ALS100_INIT_REG_ADD]=0;
            }
            return 1;
  
        default:
        break;
    }
    return 0;
}

void Modbus::init_als100_parameter()
{
    parameterport_mapping->tab_registers[ALS100_EXPOSURE_TIME_REG_ADD]=e2proomdata.als100_exposure_time;
    parameterport_mapping->tab_registers[ALS100_PINGJUN_REG_ADD]=e2proomdata.als100_pingjun;
    parameterport_mapping->tab_registers[ALS100_B_YANMOFUZHU_REG_ADD]=e2proomdata.als100_b_yanmofuzhu;
    parameterport_mapping->tab_registers[ALS100_B_GUDINGQUYU_REG_ADD]=e2proomdata.als100_b_gudingquyu;
    parameterport_mapping->tab_registers[ALS100_WIDTHLIANTONGDIS_REG_ADD]=e2proomdata.als100_widthliantongdis;
    parameterport_mapping->tab_registers[ALS100_HIGHLIANTONGDIS_REG_ADD]=e2proomdata.als100_highliantongdis;
    parameterport_mapping->tab_registers[ALS100_GUJIAERZHI_REG_ADD]=e2proomdata.als100_gujiaerzhi;
    parameterport_mapping->tab_registers[ALS100_JIGUANGHIGHT_REG_ADD]=e2proomdata.als100_jiguanghight;
    parameterport_mapping->tab_registers[ALS100_JIGUANGLONG_REG_ADD]=e2proomdata.als100_jiguanglong;
    parameterport_mapping->tab_registers[ALS100_JIGUANGKUANDU_REG_ADD]=e2proomdata.als100_jiguangkuandu;
    parameterport_mapping->tab_registers[ALS100_UPDIF_REG_ADD]=e2proomdata.als100_Updif;
    parameterport_mapping->tab_registers[ALS100_UPDIFMIN_REG_ADD]=e2proomdata.als100_Updifmin;
    parameterport_mapping->tab_registers[ALS100_UPLONG_REG_ADD]=e2proomdata.als100_Uplong;
    parameterport_mapping->tab_registers[ALS100_DOWNDIF_REG_ADD]=e2proomdata.als100_Downdif;
    parameterport_mapping->tab_registers[ALS100_DOWNDIFMIN_REG_ADD]=e2proomdata.als100_Downdifmin;
    parameterport_mapping->tab_registers[ALS100_DOWNDLONG_REG_ADD]=e2proomdata.als100_Downdlong;
    parameterport_mapping->tab_registers[ALS100_DUANXIANERZHI_REG_ADD]=e2proomdata.als100_duanxianerzhi;
    parameterport_mapping->tab_registers[ALS100_ERZHISIZE_REG_ADD]=e2proomdata.als100_erzhisize;
    parameterport_mapping->tab_registers[ALS100_ERZHISIZE2_REG_ADD]=e2proomdata.als100_erzhisize2;
    parameterport_mapping->tab_registers[ALS100_SEARCHDECTANCEMAX_REG_ADD]=e2proomdata.als100_searchdectancemax;
    parameterport_mapping->tab_registers[ALS100_SEARCHDECTANCEMIN_REG_ADD]=e2proomdata.als100_searchdectancemin;
    parameterport_mapping->tab_registers[ALS100_DIS_CENTER_ST_REG_ADD]=e2proomdata.als100_dis_center_st;
    parameterport_mapping->tab_registers[ALS100_DIS_CENTER_ED_REG_ADD]=e2proomdata.als100_dis_center_ed;
    parameterport_mapping->tab_registers[ALS100_ANSWERPOINT_REG_ADD]=e2proomdata.als100_answerpoint;
}

}