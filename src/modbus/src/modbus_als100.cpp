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
            if((int)num>=(int)e2proomdata.als100_exposure_time_min&&(int)num<=(int)e2proomdata.als100_exposure_time_max)
            {
                e2proomdata.als100_exposure_time=num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_exposure_time", num)});
                return 1;
            }
        break;
        case ALS100_PINGJUN_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_pingjun_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_pingjun_max)
            {
                e2proomdata.als100_pingjun=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_pingjun", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_B_YANMOFUZHU_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_b_yanmofuzhu_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_b_yanmofuzhu_max)
            {
                e2proomdata.als100_b_yanmofuzhu=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_b_yanmofuzhu", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_B_GUDINGQUYU_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_b_gudingquyu_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_b_gudingquyu_max)
            {
                e2proomdata.als100_b_gudingquyu=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_b_gudingquyu", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_WIDTHLIANTONGDIS_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_widthliantongdis_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_widthliantongdis_max)
            {
                e2proomdata.als100_widthliantongdis=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_widthliantongdis", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_HIGHLIANTONGDIS_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_highliantongdis_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_highliantongdis_max)
            {
                e2proomdata.als100_highliantongdis=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_highliantongdis", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_GUJIAERZHI_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_gujiaerzhi_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_gujiaerzhi_max)
            {
                e2proomdata.als100_gujiaerzhi=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_gujiaerzhi", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_JIGUANGHIGHT_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_jiguanghight_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_jiguanghight_max)
            {
                e2proomdata.als100_jiguanghight=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_jiguanghight", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_JIGUANGLONG_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_jiguanglong_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_jiguanglong_max)
            {
                e2proomdata.als100_jiguanglong=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_jiguanglong", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_JIGUANGKUANDU_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_jiguangkuandu_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_jiguangkuandu_max)
            {
                e2proomdata.als100_jiguangkuandu=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_jiguangkuandu", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_UPDIF_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_Updif_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_Updif_max)
            {
                e2proomdata.als100_Updif=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Updif", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_UPDIFMIN_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_Updifmin_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_Updifmin_max)
            {
                e2proomdata.als100_Updifmin=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Updifmin", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_UPLONG_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_Uplong_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_Uplong_max)
            {
                e2proomdata.als100_Uplong=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Uplong",(int16_t)num)});
                return 1;
            }
        break;
        case ALS100_DOWNDIF_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_Downdif_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_Downdif_max)
            {
                e2proomdata.als100_Downdif=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Downdif", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_DOWNDIFMIN_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_Downdifmin_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_Downdifmin_max)
            {
                e2proomdata.als100_Downdifmin=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Downdifmin", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_DOWNDLONG_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_Downdlong_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_Downdlong_max)
            {
                e2proomdata.als100_Downdlong=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Downdlong", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_DUANXIANERZHI_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_duanxianerzhi_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_duanxianerzhi_max)
            {
                e2proomdata.als100_duanxianerzhi=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_duanxianerzhi", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_ERZHISIZE_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_erzhisize_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_erzhisize_max)
            {
                e2proomdata.als100_erzhisize=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_erzhisize", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_ERZHISIZE2_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_erzhisize2_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_erzhisize2_max)
            {
                e2proomdata.als100_erzhisize2=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_erzhisize2", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_SEARCHDECTANCEMAX_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_searchdectancemax_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_searchdectancemax_max)
            {
                e2proomdata.als100_searchdectancemax=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_searchdectancemax", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_SEARCHDECTANCEMIN_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_searchdectancemin_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_searchdectancemin_max)
            {
                e2proomdata.als100_searchdectancemin=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_searchdectancemin", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_DIS_CENTER_ST_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_dis_center_st_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_dis_center_st_max)
            {
                e2proomdata.als100_dis_center_st=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_dis_center_st", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_DIS_CENTER_ED_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_dis_center_ed_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_dis_center_ed_max)
            {
                e2proomdata.als100_dis_center_ed=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_dis_center_ed", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_ANSWERPOINT_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_answerpoint_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_answerpoint_max)
            {
                e2proomdata.als100_answerpoint=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_answerpoint", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_B_KALMANFILTER_REG_ADD:   
            if((int)((int16_t)num)>=(int)e2proomdata.als100_b_KalmanFilter_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_b_KalmanFilter_max)
            {
                e2proomdata.als100_b_KalmanFilter=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_b_KalmanFilter", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_KALMANQF_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_KalmanQF_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_KalmanQF_max)
            {
                e2proomdata.als100_KalmanQF=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_KalmanQF", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_KALMANRF_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_KalmanRF_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_KalmanRF_max)
            {
                e2proomdata.als100_KalmanRF=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_KalmanRF", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_B_CUT_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_b_cut_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_b_cut_max)
            {
                e2proomdata.als100_b_cut=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_b_cut", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_CUTLEFT_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_cutleft_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_cutleft_max)
            {
                e2proomdata.als100_cutleft=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_cutleft", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_CUTRIGHT_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_cutright_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_cutright_max)
            {
                e2proomdata.als100_cutright=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_cutright", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_CUTTOP_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_cuttop_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_cuttop_max)
            {
                e2proomdata.als100_cuttop=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_cuttop", (int16_t)num)});
                return 1;
            }
        break;
        case ALS100_CUTDEEP_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als100_cutdeep_min&&(int)((int16_t)num)<=(int)e2proomdata.als100_cutdeep_max)
            {
                e2proomdata.als100_cutdeep=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_cutdeep", (int16_t)num)});
                return 1;
            }
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
    parameterport_mapping->tab_registers[ALS100_B_KALMANFILTER_REG_ADD]=e2proomdata.als100_b_KalmanFilter;   
    parameterport_mapping->tab_registers[ALS100_KALMANQF_REG_ADD]=e2proomdata.als100_KalmanQF;  
    parameterport_mapping->tab_registers[ALS100_KALMANRF_REG_ADD]=e2proomdata.als100_KalmanRF;  
    parameterport_mapping->tab_registers[ALS100_B_CUT_REG_ADD]=e2proomdata.als100_b_cut;
    parameterport_mapping->tab_registers[ALS100_CUTLEFT_REG_ADD]=e2proomdata.als100_cutleft;
    parameterport_mapping->tab_registers[ALS100_CUTRIGHT_REG_ADD]=e2proomdata.als100_cutright;
    parameterport_mapping->tab_registers[ALS100_CUTTOP_REG_ADD]=e2proomdata.als100_cuttop;
    parameterport_mapping->tab_registers[ALS100_CUTDEEP_REG_ADD]=e2proomdata.als100_cutdeep;
}

}