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
            if((int)num>=(int)e2proomdata.als105_exposure_time_min&&(int)num<=(int)e2proomdata.als105_exposure_time_max)
            {
                e2proomdata.als105_exposure_time=num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_exposure_time", num)});
                return 1;
            }
        break;
        case ALS105_PINGJUN_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_pingjun_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_pingjun_max)
            {
                e2proomdata.als105_pingjun=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_pingjun", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_B_YANMOFUZHU_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_b_yanmofuzhu_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_b_yanmofuzhu_max)
            {
                e2proomdata.als105_b_yanmofuzhu=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_b_yanmofuzhu", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_WIDTHLIANTONGDIS_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_widthliantongdis_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_widthliantongdis_max)
            {
                e2proomdata.als105_widthliantongdis=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_widthliantongdis", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_HIGHLIANTONGDIS_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_highliantongdis_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_highliantongdis_max)
            {
                e2proomdata.als105_highliantongdis=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_highliantongdis", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_GUJIAERZHI_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_gujiaerzhi_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_gujiaerzhi_max)
            {
                e2proomdata.als105_gujiaerzhi=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_gujiaerzhi", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_JIGUANGHIGHT_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_jiguanghight_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_jiguanghight_max)
            {
                e2proomdata.als105_jiguanghight=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_jiguanghight", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_JIGUANGLONG_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_jiguanglong_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_jiguanglong_max)
            {
                e2proomdata.als105_jiguanglong=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_jiguanglong", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_JIGUANGKUANDU_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_jiguangkuandu_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_jiguangkuandu_max)
            {
                e2proomdata.als105_jiguangkuandu=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_jiguangkuandu", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_UPDIF_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_Updif_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_Updif_max)
            {
                e2proomdata.als105_Updif=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_Updif", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_UPDIFMIN_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_Updifmin_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_Updifmin_max)
            {
                e2proomdata.als105_Updifmin=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_Updifmin", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_UPLONG_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_Uplong_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_Uplong_max)
            {
                e2proomdata.als105_Uplong=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_Uplong", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_DOWNDIF_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_Downdif_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_Downdif_max)
            {
                e2proomdata.als105_Downdif=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_Downdif", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_DOWNDIFMIN_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_Downdifmin_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_Downdifmin_max)
            {
                e2proomdata.als105_Downdifmin=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_Downdifmin", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_DOWNDLONG_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_Downdlong_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_Downdlong_max)
            {
                e2proomdata.als105_Downdlong=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_Downdlong", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_DIS_CENTER_ST_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_dis_center_st_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_dis_center_st_max)
            {
                e2proomdata.als105_dis_center_st=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_dis_center_st", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_DIS_CENTER_ED_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_dis_center_ed_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_dis_center_ed_max)
            {
                e2proomdata.als105_dis_center_ed=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_dis_center_ed", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_B_CUT_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_b_cut_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_b_cut_max)
            {
                e2proomdata.als105_b_cut=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_b_cut", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_CUTLEFT_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_cutleft_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_cutleft_max)
            {
                e2proomdata.als105_cutleft=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_cutleft", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_CUTRIGHT_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_cutright_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_cutright_max)
            {
                e2proomdata.als105_cutright=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_cutright", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_CUTTOP_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_cuttop_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_cuttop_max)
            {
                e2proomdata.als105_cuttop=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_cuttop", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_CUTDEEP_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_cutdeep_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_cutdeep_max)
            {
                e2proomdata.als105_cutdeep=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_cutdeep", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_GUAIDIANYUZHI_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_guaidianyuzhi_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_guaidianyuzhi_max)
            {
                e2proomdata.als105_guaidianyuzhi=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_guaidianyuzhi", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_DUANDIANJULI_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_duandianjuli_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_duandianjuli_max)
            {
                e2proomdata.als105_duandianjuli=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_duandianjuli", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_B_DIBUFAXIANGLIANG_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_b_dibufaxiangliang_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_b_dibufaxiangliang_max)
            {
                e2proomdata.als105_b_dibufaxiangliang=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_b_dibufaxiangliang", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_ANSWERPOINT_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_answerpoint_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_answerpoint_max)
            {
                e2proomdata.als105_answerpoint=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_answerpoint", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_B_USEDOWNLIANTONG_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_usedownliantong_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_usedownliantong_max)
            {
                e2proomdata.als105_usedownliantong=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_usedownliantong", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_B_KALMANFILTER_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_b_KalmanFilter_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_b_KalmanFilter_max)
            {
                e2proomdata.als105_b_KalmanFilter=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_b_KalmanFilter", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_KALMANQF_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_KalmanQF_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_KalmanQF_max)
            {
                e2proomdata.als105_KalmanQF=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_KalmanQF", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_KALMANRF_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_KalmanRF_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_KalmanRF_max)
            {
                e2proomdata.als105_KalmanRF=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_KalmanRF", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_CUTSIDE_UP_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_cutside_Up_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_cutside_Up_max)
            {
                e2proomdata.als105_cutside_Up=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_cutside_Up", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_CUTSIDE_DOWN_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_cutside_Down_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_cutside_Down_max)
            {
                e2proomdata.als105_cutside_Down=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_cutside_Down", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_B_ERJIEDAO_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_b_erjiedao_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_b_erjiedao_max)
            {
                e2proomdata.als105_b_erjiedao=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_b_erjiedao", (int16_t)num)});
                return 1;
            }
        break;
        case ALS105_B_QUXIAN_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als105_b_quxian_min&&(int)((int16_t)num)<=(int)e2proomdata.als105_b_quxian_max)
            {
                e2proomdata.als105_b_quxian=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als105_b_quxian", (int16_t)num)});
                return 1;
            }
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
    parameterport_mapping->tab_registers[ALS105_B_USEDOWNLIANTONG_REG_ADD]=e2proomdata.als105_usedownliantong;   
    parameterport_mapping->tab_registers[ALS105_B_KALMANFILTER_REG_ADD]=e2proomdata.als105_b_KalmanFilter;   
    parameterport_mapping->tab_registers[ALS105_KALMANQF_REG_ADD]=e2proomdata.als105_KalmanQF;  
    parameterport_mapping->tab_registers[ALS105_KALMANRF_REG_ADD]=e2proomdata.als105_KalmanRF;  
    parameterport_mapping->tab_registers[ALS105_CUTSIDE_UP_REG_ADD]=e2proomdata.als105_cutside_Up;  
    parameterport_mapping->tab_registers[ALS105_CUTSIDE_DOWN_REG_ADD]=e2proomdata.als105_cutside_Down;  
    parameterport_mapping->tab_registers[ALS105_B_ERJIEDAO_REG_ADD]=e2proomdata.als105_b_erjiedao;     
    parameterport_mapping->tab_registers[ALS105_B_QUXIAN_REG_ADD]=e2proomdata.als105_b_quxian;         
}

}