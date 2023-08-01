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
            if((int)num>=(int)e2proomdata.als101_exposure_time_min&&(int)num<=(int)e2proomdata.als101_exposure_time_max)
            {
                e2proomdata.als101_exposure_time=num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_exposure_time", num)});
                return 1;   
            }
        break;
        case ALS101_PINGJUN_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_pingjun_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_pingjun_max)
            {
                e2proomdata.als101_pingjun=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_pingjun", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_B_YANMOFUZHU_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_b_yanmofuzhu_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_b_yanmofuzhu_max)
            {
                e2proomdata.als101_b_yanmofuzhu=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_b_yanmofuzhu", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_B_GUDINGQUYU_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_b_gudingquyu_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_b_gudingquyu_max)
            {
                e2proomdata.als101_b_gudingquyu=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_b_gudingquyu", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_WIDTHLIANTONGDIS_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_widthliantongdis_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_widthliantongdis_max)
            {
                e2proomdata.als101_widthliantongdis=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_widthliantongdis", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_HIGHLIANTONGDIS_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_highliantongdis_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_highliantongdis_max)
            {
                e2proomdata.als101_highliantongdis=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_highliantongdis", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_GUJIAERZHI_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_gujiaerzhi_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_gujiaerzhi_max)
            {
                e2proomdata.als101_gujiaerzhi=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_gujiaerzhi", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_JIGUANGHIGHT_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_jiguanghight_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_jiguanghight_max)
            {
                e2proomdata.als101_jiguanghight=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_jiguanghight", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_JIGUANGLONG_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_jiguanglong_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_jiguanglong_max)
            {
                e2proomdata.als101_jiguanglong=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_jiguanglong", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_JIGUANGKUANDU_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_jiguangkuandu_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_jiguangkuandu_max)
            {
                e2proomdata.als101_jiguangkuandu=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_jiguangkuandu", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_UPDIF_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_Updif_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_Updif_max)
            {
                e2proomdata.als101_Updif=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_Updif", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_UPDIFMIN_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_Updifmin_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_Updifmin_max)
            {
                e2proomdata.als101_Updifmin=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_Updifmin", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_UPLONG_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_Uplong_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_Uplong_max)
            {
                e2proomdata.als101_Uplong=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_Uplong", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_DOWNDIF_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_Downdif_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_Downdif_max)
            {
                e2proomdata.als101_Downdif=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_Downdif", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_DOWNDIFMIN_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_Downdifmin_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_Downdifmin_max)
            {
                e2proomdata.als101_Downdifmin=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_Downdifmin", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_DOWNDLONG_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_Downdlong_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_Downdlong_max)
            {
                e2proomdata.als101_Downdlong=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_Downdlong", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_DUANXIANERZHI_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_duanxianerzhi_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_duanxianerzhi_max)
            {
                e2proomdata.als101_duanxianerzhi=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_duanxianerzhi", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_ERZHISIZE_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_erzhisize_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_erzhisize_max)
            {
                e2proomdata.als101_erzhisize=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_erzhisize", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_ERZHISIZE2_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_erzhisize2_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_erzhisize2_max)
            {
                e2proomdata.als101_erzhisize2=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_erzhisize2", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_SEARCHDECTANCEMAX_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_searchdectancemax_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_searchdectancemax_max)
            {
                e2proomdata.als101_searchdectancemax=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_searchdectancemax", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_SEARCHDECTANCEMIN_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_searchdectancemin_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_searchdectancemin_max)
            {
                e2proomdata.als101_searchdectancemin=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_searchdectancemin", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_DIS_CENTER_ST_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_dis_center_st_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_dis_center_st_max)
            {
                e2proomdata.als101_dis_center_st=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_dis_center_st", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_DIS_CENTER_ED_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_dis_center_ed_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_dis_center_ed_max)
            {
                e2proomdata.als101_dis_center_ed=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_dis_center_ed", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_ANSWERPOINT_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_answerpoint_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_answerpoint_max)
            {
                e2proomdata.als101_answerpoint=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_answerpoint", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_B_KALMANFILTER_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_b_KalmanFilter_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_b_KalmanFilter_max)
            {
                e2proomdata.als101_b_KalmanFilter=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_b_KalmanFilter", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_KALMANQF_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_KalmanQF_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_KalmanQF_max)
            {
                e2proomdata.als101_KalmanQF=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_KalmanQF", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_KALMANRF_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_KalmanRF_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_KalmanRF_max)
            {
                e2proomdata.als101_KalmanRF=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_KalmanRF", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_B_CUT_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_b_cut_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_b_cut_max)
            {
                e2proomdata.als101_b_cut=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_b_cut", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_CUTLEFT_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_cutleft_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_cutleft_max)
            {
                e2proomdata.als101_cutleft=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_cutleft", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_CUTRIGHT_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_cutright_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_cutright_max)
            {
                e2proomdata.als101_cutright=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_cutright", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_CUTTOP_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_cuttop_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_cuttop_max)
            {
                e2proomdata.als101_cuttop=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_cuttop", (int16_t)num)});
                return 1;
            }
        break;
        case ALS101_CUTDEEP_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als101_cutdeep_min&&(int)((int16_t)num)<=(int)e2proomdata.als101_cutdeep_max)
            {
                e2proomdata.als101_cutdeep=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als101_cutdeep", (int16_t)num)});
                return 1;
            }
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
    parameterport_mapping->tab_registers[ALS101_B_KALMANFILTER_REG_ADD]=e2proomdata.als101_b_KalmanFilter;   
    parameterport_mapping->tab_registers[ALS101_KALMANQF_REG_ADD]=e2proomdata.als101_KalmanQF;  
    parameterport_mapping->tab_registers[ALS101_KALMANRF_REG_ADD]=e2proomdata.als101_KalmanRF;  
    parameterport_mapping->tab_registers[ALS101_B_CUT_REG_ADD]=e2proomdata.als101_b_cut;
    parameterport_mapping->tab_registers[ALS101_CUTLEFT_REG_ADD]=e2proomdata.als101_cutleft;
    parameterport_mapping->tab_registers[ALS101_CUTRIGHT_REG_ADD]=e2proomdata.als101_cutright;
    parameterport_mapping->tab_registers[ALS101_CUTTOP_REG_ADD]=e2proomdata.als101_cuttop;
    parameterport_mapping->tab_registers[ALS101_CUTDEEP_REG_ADD]=e2proomdata.als101_cutdeep;
}

}