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

int Modbus::als105_task_parameter(int ddr,u_int16_t num)
{
    switch(ddr)
    {
        case ALS105_EXPOSURE_TIME_REG_ADD:
            e2proomdata.als105_exposure_time=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_exposure_time", num)});
            return 1;
        break;
        case ALS105_PINGJUN_REG_ADD:
            e2proomdata.als105_pingjun=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_pingjun", (int16_t)num)});
            return 1;
        break;
        case ALS105_B_YANMOFUZHU_REG_ADD:
            e2proomdata.als105_b_yanmofuzhu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_b_yanmofuzhu", (int16_t)num)});
            return 1;
        break;
        case ALS105_WIDTHLIANTONGDIS_REG_ADD:
            e2proomdata.als105_widthliantongdis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_widthliantongdis", (int16_t)num)});
            return 1;
        break;
        case ALS105_HIGHLIANTONGDIS_REG_ADD:
            e2proomdata.als105_highliantongdis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_highliantongdis", (int16_t)num)});
            return 1;
        break;
        case ALS105_GUJIAERZHI_REG_ADD:
            e2proomdata.als105_gujiaerzhi=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_gujiaerzhi", (int16_t)num)});
            return 1;
        break;
        case ALS105_JIGUANGHIGHT_REG_ADD:
            e2proomdata.als105_jiguanghight=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_jiguanghight", (int16_t)num)});
            return 1;
        break;
        case ALS105_JIGUANGLONG_REG_ADD:
            e2proomdata.als105_jiguanglong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_jiguanglong", (int16_t)num)});
            return 1;
        break;
        case ALS105_JIGUANGKUANDU_REG_ADD:
            e2proomdata.als105_jiguangkuandu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_jiguangkuandu", (int16_t)num)});
            return 1;
        break;
        case ALS105_UPDIF_REG_ADD:
            e2proomdata.als105_Updif=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_Updif", (int16_t)num)});
            return 1;
        break;
        case ALS105_UPDIFMIN_REG_ADD:
            e2proomdata.als105_Updifmin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_Updifmin", (int16_t)num)});
            return 1;
        break;
        case ALS105_UPLONG_REG_ADD:
            e2proomdata.als105_Uplong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_Uplong", (int16_t)num)});
            return 1;
        break;
        case ALS105_DOWNDIF_REG_ADD:
            e2proomdata.als105_Downdif=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_Downdif", (int16_t)num)});
            return 1;
        break;
        case ALS105_DOWNDIFMIN_REG_ADD:
            e2proomdata.als105_Downdifmin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_Downdifmin", (int16_t)num)});
            return 1;
        break;
        case ALS105_DOWNDLONG_REG_ADD:
            e2proomdata.als105_Downdlong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_Downdlong", (int16_t)num)});
            return 1;
        break;
        case ALS105_DIS_CENTER_ST_REG_ADD:
            e2proomdata.als105_dis_center_st=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_dis_center_st", (int16_t)num)});
            return 1;
        break;
        case ALS105_DIS_CENTER_ED_REG_ADD:
            e2proomdata.als105_dis_center_ed=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_dis_center_ed", (int16_t)num)});
            return 1;
        break;
        case ALS105_B_CUT_REG_ADD:
            e2proomdata.als105_b_cut=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_b_cut", (int16_t)num)});
            return 1;
        break;
        case ALS105_CUTLEFT_REG_ADD:
            e2proomdata.als105_cutleft=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_cutleft", (int16_t)num)});
            return 1;
        break;
        case ALS105_CUTRIGHT_REG_ADD:
            e2proomdata.als105_cutright=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_cutright", (int16_t)num)});
            return 1;
        break;
        case ALS105_CUTTOP_REG_ADD:
            e2proomdata.als105_cuttop=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_cuttop", (int16_t)num)});
            return 1;
        break;
        case ALS105_CUTDEEP_REG_ADD:
            e2proomdata.als105_cutdeep=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_cutdeep", (int16_t)num)});
            return 1;
        break;
        case ALS105_GUAIDIANYUZHI_REG_ADD:
            e2proomdata.als105_guaidianyuzhi=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_guaidianyuzhi", (int16_t)num)});
            return 1;
        break;
        case ALS105_DUANDIANJULI_REG_ADD:
            e2proomdata.als105_duandianjuli=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_duandianjuli", (int16_t)num)});
            return 1;
        break;
        case ALS105_B_DIBUFAXIANGLIANG_REG_ADD:
            e2proomdata.als105_b_dibufaxiangliang=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_b_dibufaxiangliang", (int16_t)num)});
            return 1;
        break;
        case ALS105_ANSWERPOINT_REG_ADD:
            e2proomdata.als105_answerpoint=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_answerpoint", (int16_t)num)});
            return 1;
        break;

        case ALS105_INIT_REG_ADD:
            if(num==1)
            {
                e2proomdata.init_als105_para();
                init_als105_parameter();
                parameterport_mapping->tab_registers[ALS105_INIT_REG_ADD]=0;
            }
            return 1;
  
        default:
        break;
    }
    return 0;
}

void Modbus::init_als105_parameter()
{
    parameterport_mapping->tab_registers[ALS105_EXPOSURE_TIME_REG_ADD]=e2proomdata.als105_exposure_time;
    parameterport_mapping->tab_registers[ALS105_PINGJUN_REG_ADD]=e2proomdata.als105_pingjun;
    parameterport_mapping->tab_registers[ALS105_B_YANMOFUZHU_REG_ADD]=e2proomdata.als105_b_yanmofuzhu;
    parameterport_mapping->tab_registers[ALS105_WIDTHLIANTONGDIS_REG_ADD]=e2proomdata.als105_widthliantongdis;
    parameterport_mapping->tab_registers[ALS105_HIGHLIANTONGDIS_REG_ADD]=e2proomdata.als105_highliantongdis;
    parameterport_mapping->tab_registers[ALS105_GUJIAERZHI_REG_ADD]=e2proomdata.als105_gujiaerzhi;
    parameterport_mapping->tab_registers[ALS105_JIGUANGHIGHT_REG_ADD]=e2proomdata.als105_jiguanghight;
    parameterport_mapping->tab_registers[ALS105_JIGUANGLONG_REG_ADD]=e2proomdata.als105_jiguanglong;
    parameterport_mapping->tab_registers[ALS105_JIGUANGKUANDU_REG_ADD]=e2proomdata.als105_jiguangkuandu;
    parameterport_mapping->tab_registers[ALS105_UPDIF_REG_ADD]=e2proomdata.als105_Updif;
    parameterport_mapping->tab_registers[ALS105_UPDIFMIN_REG_ADD]=e2proomdata.als105_Updifmin;
    parameterport_mapping->tab_registers[ALS105_UPLONG_REG_ADD]=e2proomdata.als105_Uplong;
    parameterport_mapping->tab_registers[ALS105_DOWNDIF_REG_ADD]=e2proomdata.als105_Downdif;
    parameterport_mapping->tab_registers[ALS105_DOWNDIFMIN_REG_ADD]=e2proomdata.als105_Downdifmin;
    parameterport_mapping->tab_registers[ALS105_DOWNDLONG_REG_ADD]=e2proomdata.als105_Downdlong;
    parameterport_mapping->tab_registers[ALS105_DIS_CENTER_ST_REG_ADD]=e2proomdata.als105_dis_center_st;
    parameterport_mapping->tab_registers[ALS105_DIS_CENTER_ED_REG_ADD]=e2proomdata.als105_dis_center_ed;
    parameterport_mapping->tab_registers[ALS105_B_CUT_REG_ADD]=e2proomdata.als105_b_cut;
    parameterport_mapping->tab_registers[ALS105_CUTLEFT_REG_ADD]=e2proomdata.als105_cutleft;
    parameterport_mapping->tab_registers[ALS105_CUTRIGHT_REG_ADD]=e2proomdata.als105_cutright;
    parameterport_mapping->tab_registers[ALS105_CUTTOP_REG_ADD]=e2proomdata.als105_cuttop;
    parameterport_mapping->tab_registers[ALS105_CUTDEEP_REG_ADD]=e2proomdata.als105_cutdeep;
    parameterport_mapping->tab_registers[ALS105_GUAIDIANYUZHI_REG_ADD]=e2proomdata.als105_guaidianyuzhi;
    parameterport_mapping->tab_registers[ALS105_DUANDIANJULI_REG_ADD]=e2proomdata.als105_duandianjuli;
    parameterport_mapping->tab_registers[ALS105_B_DIBUFAXIANGLIANG_REG_ADD]=e2proomdata.als105_b_dibufaxiangliang;
    parameterport_mapping->tab_registers[ALS105_ANSWERPOINT_REG_ADD]=e2proomdata.als105_answerpoint;
}

}