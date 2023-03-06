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

int Modbus::als104_task_parameter(int ddr,u_int16_t num)
{
    switch(ddr)
    {
        case ALS104_EXPOSURE_TIME_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_exposure_time_min&&(int)num<=(int)e2proomdata.als104_exposure_time_max)
            {
                e2proomdata.als104_exposure_time=num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_exposure_time", num)});
                return 1;
            }
        break;
        case ALS104_PINGJUN_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_pingjun_min&&(int)num<=(int)e2proomdata.als104_pingjun_max)
            {
                e2proomdata.als104_pingjun=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_pingjun", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_B_YANMOFUZHU_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_b_yanmofuzhu_min&&(int)num<=(int)e2proomdata.als104_b_yanmofuzhu_max)
            {
                e2proomdata.als104_b_yanmofuzhu=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_b_yanmofuzhu", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_B_GUDINGQUYU_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_b_gudingquyu_min&&(int)num<=(int)e2proomdata.als104_b_gudingquyu_max)
            {
                e2proomdata.als104_b_gudingquyu=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_b_gudingquyu", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_WIDTHLIANTONGDIS_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_widthliantongdis_min&&(int)num<=(int)e2proomdata.als104_widthliantongdis_max)
            {
                e2proomdata.als104_widthliantongdis=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_widthliantongdis", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_HIGHLIANTONGDIS_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_highliantongdis_min&&(int)num<=(int)e2proomdata.als104_highliantongdis_max)
            {
                e2proomdata.als104_highliantongdis=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_highliantongdis", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_GUJIAERZHI_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_gujiaerzhi_min&&(int)num<=(int)e2proomdata.als104_gujiaerzhi_max)
            {
                e2proomdata.als104_gujiaerzhi=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_gujiaerzhi", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_JIGUANGHIGHT_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_jiguanghight_min&&(int)num<=(int)e2proomdata.als104_jiguanghight_max)
            {
                e2proomdata.als104_jiguanghight=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_jiguanghight", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_JIGUANGLONG_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_jiguanglong_min&&(int)num<=(int)e2proomdata.als104_jiguanglong_max)
            {
                e2proomdata.als104_jiguanglong=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_jiguanglong", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_JIGUANGKUANDU_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_jiguangkuandu_min&&(int)num<=(int)e2proomdata.als104_jiguangkuandu_max)
            {
                e2proomdata.als104_jiguangkuandu=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_jiguangkuandu", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_UPDIF_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_Updif_min&&(int)num<=(int)e2proomdata.als104_Updif_max)
            {
                e2proomdata.als104_Updif=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Updif", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_UPDIFMIN_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_Updifmin_min&&(int)num<=(int)e2proomdata.als104_Updifmin_max)
            {
                e2proomdata.als104_Updifmin=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Updifmin", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_UPLONG_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_Uplong_min&&(int)num<=(int)e2proomdata.als104_Uplong_max)
            {
                e2proomdata.als104_Uplong=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Uplong", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_DOWNDIF_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_Downdif_min&&(int)num<=(int)e2proomdata.als104_Downdif_max)
            {
                e2proomdata.als104_Downdif=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Downdif", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_DOWNDIFMIN_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_Downdifmin_min&&(int)num<=(int)e2proomdata.als104_Downdifmin_max)
            {
                e2proomdata.als104_Downdifmin=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Downdifmin", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_DOWNDLONG_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_Downdlong_min&&(int)num<=(int)e2proomdata.als104_Downdlong_max)
            {
                e2proomdata.als104_Downdlong=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_Downdlong", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_DIS_CENTER_ST_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_dis_center_st_min&&(int)num<=(int)e2proomdata.als104_dis_center_st_max)
            {
                e2proomdata.als104_dis_center_st=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_dis_center_st", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_DIS_CENTER_ED_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_dis_center_ed_min&&(int)num<=(int)e2proomdata.als104_dis_center_ed_max)
            {
                e2proomdata.als104_dis_center_ed=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_dis_center_ed", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_B_KALMANFILTER_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_b_KalmanFilter_min&&(int)num<=(int)e2proomdata.als104_b_KalmanFilter_max)
            {
                e2proomdata.als104_b_KalmanFilter=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_b_KalmanFilter", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_KALMANQF_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_KalmanQF_min&&(int)num<=(int)e2proomdata.als104_KalmanQF_max)
            {
                e2proomdata.als104_KalmanQF=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_KalmanQF", (int16_t)num)});
                return 1;
            }
        break;
        case ALS104_KALMANRF_REG_ADD:
            if((int)num>=(int)e2proomdata.als104_KalmanRF_min&&(int)num<=(int)e2proomdata.als104_KalmanRF_max)
            {
                e2proomdata.als104_KalmanRF=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als104_KalmanRF", (int16_t)num)});
                return 1;
            }
        break;



        case ALS104_INIT_REG_ADD:
            if(num==1)
            {
                e2proomdata.init_als104_para();
                init_als104_parameter();
                parameterport_mapping->tab_registers[ALS104_INIT_REG_ADD]=0;
            }
            return 1;
  
        default:
        break;
    }
    return 0;
}

void Modbus::init_als104_parameter()
{
    parameterport_mapping->tab_registers[ALS104_EXPOSURE_TIME_REG_ADD]=e2proomdata.als104_exposure_time;
    parameterport_mapping->tab_registers[ALS104_PINGJUN_REG_ADD]=e2proomdata.als104_pingjun;
    parameterport_mapping->tab_registers[ALS104_B_YANMOFUZHU_REG_ADD]=e2proomdata.als104_b_yanmofuzhu;
    parameterport_mapping->tab_registers[ALS104_B_GUDINGQUYU_REG_ADD]=e2proomdata.als104_b_gudingquyu;
    parameterport_mapping->tab_registers[ALS104_WIDTHLIANTONGDIS_REG_ADD]=e2proomdata.als104_widthliantongdis;
    parameterport_mapping->tab_registers[ALS104_HIGHLIANTONGDIS_REG_ADD]=e2proomdata.als104_highliantongdis;
    parameterport_mapping->tab_registers[ALS104_GUJIAERZHI_REG_ADD]=e2proomdata.als104_gujiaerzhi;
    parameterport_mapping->tab_registers[ALS104_JIGUANGHIGHT_REG_ADD]=e2proomdata.als104_jiguanghight;
    parameterport_mapping->tab_registers[ALS104_JIGUANGLONG_REG_ADD]=e2proomdata.als104_jiguanglong;
    parameterport_mapping->tab_registers[ALS104_JIGUANGKUANDU_REG_ADD]=e2proomdata.als104_jiguangkuandu;
    parameterport_mapping->tab_registers[ALS104_UPDIF_REG_ADD]=e2proomdata.als104_Updif;
    parameterport_mapping->tab_registers[ALS104_UPDIFMIN_REG_ADD]=e2proomdata.als104_Updifmin;
    parameterport_mapping->tab_registers[ALS104_UPLONG_REG_ADD]=e2proomdata.als104_Uplong;
    parameterport_mapping->tab_registers[ALS104_DOWNDIF_REG_ADD]=e2proomdata.als104_Downdif;
    parameterport_mapping->tab_registers[ALS104_DOWNDIFMIN_REG_ADD]=e2proomdata.als104_Downdifmin;
    parameterport_mapping->tab_registers[ALS104_DOWNDLONG_REG_ADD]=e2proomdata.als104_Downdlong;
    parameterport_mapping->tab_registers[ALS104_DIS_CENTER_ST_REG_ADD]=e2proomdata.als104_dis_center_st;
    parameterport_mapping->tab_registers[ALS104_DIS_CENTER_ED_REG_ADD]=e2proomdata.als104_dis_center_ed;
    parameterport_mapping->tab_registers[ALS104_B_KALMANFILTER_REG_ADD]=e2proomdata.als104_b_KalmanFilter;   
    parameterport_mapping->tab_registers[ALS104_KALMANQF_REG_ADD]=e2proomdata.als104_KalmanQF;  
    parameterport_mapping->tab_registers[ALS104_KALMANRF_REG_ADD]=e2proomdata.als104_KalmanRF;  
}

}