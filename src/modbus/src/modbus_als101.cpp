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

int Modbus::als101_task_parameter(int ddr,u_int16_t num)
{
    switch(ddr)
    {
        case ALS101_EXPOSURE_TIME_REG_ADD:
            e2proomdata.als101_exposure_time=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_exposure_time", num)});
            return 1;
        break;
        case ALS101_PINGJUN_REG_ADD:
            e2proomdata.als101_pingjun=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_pingjun", (int16_t)num)});
            return 1;
        break;
        case ALS101_B_YANMOFUZHU_REG_ADD:
            e2proomdata.als101_b_yanmofuzhu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_b_yanmofuzhu", (int16_t)num)});
            return 1;
        break;
        case ALS101_B_GUDINGQUYU_REG_ADD:
            e2proomdata.als101_b_gudingquyu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_b_gudingquyu", (int16_t)num)});
            return 1;
        break;
        case ALS101_WIDTHLIANTONGDIS_REG_ADD:
            e2proomdata.als101_widthliantongdis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_widthliantongdis", (int16_t)num)});
            return 1;
        break;
        case ALS101_HIGHLIANTONGDIS_REG_ADD:
            e2proomdata.als101_highliantongdis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_highliantongdis", (int16_t)num)});
            return 1;
        break;
        case ALS101_GUJIAERZHI_REG_ADD:
            e2proomdata.als101_gujiaerzhi=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_gujiaerzhi", (int16_t)num)});
            return 1;
        break;
        case ALS101_JIGUANGHIGHT_REG_ADD:
            e2proomdata.als101_jiguanghight=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_jiguanghight", (int16_t)num)});
            return 1;
        break;
        case ALS101_JIGUANGLONG_REG_ADD:
            e2proomdata.als101_jiguanglong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_jiguanglong", (int16_t)num)});
            return 1;
        break;
        case ALS101_JIGUANGKUANDU_REG_ADD:
            e2proomdata.als101_jiguangkuandu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_jiguangkuandu", (int16_t)num)});
            return 1;
        break;
        case ALS101_UPDIF_REG_ADD:
            e2proomdata.als101_Updif=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_Updif", (int16_t)num)});
            return 1;
        break;
        case ALS101_UPDIFMIN_REG_ADD:
            e2proomdata.als101_Updifmin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_Updifmin", (int16_t)num)});
            return 1;
        break;
        case ALS101_UPLONG_REG_ADD:
            e2proomdata.als101_Uplong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_Uplong", (int16_t)num)});
            return 1;
        break;
        case ALS101_DOWNDIF_REG_ADD:
            e2proomdata.als101_Downdif=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_Downdif", (int16_t)num)});
            return 1;
        break;
        case ALS101_DOWNDIFMIN_REG_ADD:
            e2proomdata.als101_Downdifmin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_Downdifmin", (int16_t)num)});
            return 1;
        break;
        case ALS101_DOWNDLONG_REG_ADD:
            e2proomdata.als101_Downdlong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_Downdlong", (int16_t)num)});
            return 1;
        break;
        case ALS101_DUANXIANERZHI_REG_ADD:
            e2proomdata.als101_duanxianerzhi=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_duanxianerzhi", (int16_t)num)});
            return 1;
        break;
        case ALS101_ERZHISIZE_REG_ADD:
            e2proomdata.als101_erzhisize=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_erzhisize", (int16_t)num)});
            return 1;
        break;
        case ALS101_ERZHISIZE2_REG_ADD:
            e2proomdata.als101_erzhisize2=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_erzhisize2", (int16_t)num)});
            return 1;
        break;
        case ALS101_SEARCHDECTANCEMAX_REG_ADD:
            e2proomdata.als101_searchdectancemax=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_searchdectancemax", (int16_t)num)});
            return 1;
        break;
        case ALS101_SEARCHDECTANCEMIN_REG_ADD:
            e2proomdata.als101_searchdectancemin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_searchdectancemin", (int16_t)num)});
            return 1;
        break;
        case ALS101_DIS_CENTER_ST_REG_ADD:
            e2proomdata.als101_dis_center_st=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_dis_center_st", (int16_t)num)});
            return 1;
        break;
        case ALS101_DIS_CENTER_ED_REG_ADD:
            e2proomdata.als101_dis_center_ed=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_dis_center_ed", (int16_t)num)});
            return 1;
        break;
        case ALS101_ANSWERPOINT_REG_ADD:
            e2proomdata.als101_answerpoint=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_answerpoint", (int16_t)num)});
            return 1;
        break;


        case ALS101_INIT_REG_ADD:
            if(num==1)
            {
                e2proomdata.init_als101_para();
                init_als101_parameter();
                parameterport_mapping->tab_registers[ALS101_INIT_REG_ADD]=0;
            }
            return 1;
  
        default:
        break;
    }
    return 0;
}

void Modbus::init_als101_parameter()
{
    parameterport_mapping->tab_registers[ALS101_EXPOSURE_TIME_REG_ADD]=e2proomdata.als101_exposure_time;
    parameterport_mapping->tab_registers[ALS101_PINGJUN_REG_ADD]=e2proomdata.als101_pingjun;
    parameterport_mapping->tab_registers[ALS101_B_YANMOFUZHU_REG_ADD]=e2proomdata.als101_b_yanmofuzhu;
    parameterport_mapping->tab_registers[ALS101_B_GUDINGQUYU_REG_ADD]=e2proomdata.als101_b_gudingquyu;
    parameterport_mapping->tab_registers[ALS101_WIDTHLIANTONGDIS_REG_ADD]=e2proomdata.als101_widthliantongdis;
    parameterport_mapping->tab_registers[ALS101_HIGHLIANTONGDIS_REG_ADD]=e2proomdata.als101_highliantongdis;
    parameterport_mapping->tab_registers[ALS101_GUJIAERZHI_REG_ADD]=e2proomdata.als101_gujiaerzhi;
    parameterport_mapping->tab_registers[ALS101_JIGUANGHIGHT_REG_ADD]=e2proomdata.als101_jiguanghight;
    parameterport_mapping->tab_registers[ALS101_JIGUANGLONG_REG_ADD]=e2proomdata.als101_jiguanglong;
    parameterport_mapping->tab_registers[ALS101_JIGUANGKUANDU_REG_ADD]=e2proomdata.als101_jiguangkuandu;
    parameterport_mapping->tab_registers[ALS101_UPDIF_REG_ADD]=e2proomdata.als101_Updif;
    parameterport_mapping->tab_registers[ALS101_UPDIFMIN_REG_ADD]=e2proomdata.als101_Updifmin;
    parameterport_mapping->tab_registers[ALS101_UPLONG_REG_ADD]=e2proomdata.als101_Uplong;
    parameterport_mapping->tab_registers[ALS101_DOWNDIF_REG_ADD]=e2proomdata.als101_Downdif;
    parameterport_mapping->tab_registers[ALS101_DOWNDIFMIN_REG_ADD]=e2proomdata.als101_Downdifmin;
    parameterport_mapping->tab_registers[ALS101_DOWNDLONG_REG_ADD]=e2proomdata.als101_Downdlong;
    parameterport_mapping->tab_registers[ALS101_DUANXIANERZHI_REG_ADD]=e2proomdata.als101_duanxianerzhi;
    parameterport_mapping->tab_registers[ALS101_ERZHISIZE_REG_ADD]=e2proomdata.als101_erzhisize;
    parameterport_mapping->tab_registers[ALS101_ERZHISIZE2_REG_ADD]=e2proomdata.als101_erzhisize2;
    parameterport_mapping->tab_registers[ALS101_SEARCHDECTANCEMAX_REG_ADD]=e2proomdata.als101_searchdectancemax;
    parameterport_mapping->tab_registers[ALS101_SEARCHDECTANCEMIN_REG_ADD]=e2proomdata.als101_searchdectancemin;
    parameterport_mapping->tab_registers[ALS101_DIS_CENTER_ST_REG_ADD]=e2proomdata.als101_dis_center_st;
    parameterport_mapping->tab_registers[ALS101_DIS_CENTER_ED_REG_ADD]=e2proomdata.als101_dis_center_ed;
    parameterport_mapping->tab_registers[ALS101_ANSWERPOINT_REG_ADD]=e2proomdata.als101_answerpoint;
}

}