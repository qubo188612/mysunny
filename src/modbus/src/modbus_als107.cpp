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

int Modbus::als107_task_parameter(int ddr,u_int16_t num)
{
    switch(ddr)
    {
        case ALS107_EXPOSURE_TIME_REG_ADD:
            e2proomdata.als107_exposure_time=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_exposure_time", num)});
            return 1;
        break;
        case ALS107_PINGJUN_REG_ADD:
            e2proomdata.als107_pingjun=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_pingjun", (int16_t)num)});
            return 1;
        break;
        case ALS107_B_YANMOFUZHU_REG_ADD:
            e2proomdata.als107_b_yanmofuzhu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_b_yanmofuzhu", (int16_t)num)});
            return 1;
        break;
        case ALS107_B_GUDINGQUYU_REG_ADD:
            e2proomdata.als107_b_gudingquyu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_b_gudingquyu", (int16_t)num)});
            return 1;
        break;
        case ALS107_WIDTHLIANTONGDIS_REG_ADD:
            e2proomdata.als107_widthliantongdis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_widthliantongdis", (int16_t)num)});
            return 1;
        break;
        case ALS107_HIGHLIANTONGDIS_REG_ADD:
            e2proomdata.als107_highliantongdis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_highliantongdis", (int16_t)num)});
            return 1;
        break;
        case ALS107_GUJIAERZHI_REG_ADD:
            e2proomdata.als107_gujiaerzhi=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_gujiaerzhi", (int16_t)num)});
            return 1;
        break;
        case ALS107_JIGUANGHIGHT_REG_ADD:
            e2proomdata.als107_jiguanghight=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_jiguanghight", (int16_t)num)});
            return 1;
        break;
        case ALS107_JIGUANGLONG_REG_ADD:
            e2proomdata.als107_jiguanglong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_jiguanglong", (int16_t)num)});
            return 1;
        break;
        case ALS107_JIGUANGKUANDU_REG_ADD:
            e2proomdata.als107_jiguangkuandu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_jiguangkuandu", (int16_t)num)});
            return 1;
        break;
        case ALS107_UPDIF_REG_ADD:
            e2proomdata.als107_Updif=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_Updif", (int16_t)num)});
            return 1;
        break;
        case ALS107_UPDIFMIN_REG_ADD:
            e2proomdata.als107_Updifmin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_Updifmin", (int16_t)num)});
            return 1;
        break;
        case ALS107_UPLONG_REG_ADD:
            e2proomdata.als107_Uplong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_Uplong", (int16_t)num)});
            return 1;
        break;
        case ALS107_DOWNDIF_REG_ADD:
            e2proomdata.als107_Downdif=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_Downdif", (int16_t)num)});
            return 1;
        break;
        case ALS107_DOWNDIFMIN_REG_ADD:
            e2proomdata.als107_Downdifmin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_Downdifmin", (int16_t)num)});
            return 1;
        break;
        case ALS107_DOWNDLONG_REG_ADD:
            e2proomdata.als107_Downdlong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_Downdlong", (int16_t)num)});
            return 1;
        break;
        case ALS107_ST_DOWN_REG_ADD:
            e2proomdata.als107_St_Down=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_St_Down", (int16_t)num)});
            return 1;
        break;
        case ALS107_ED_DOWN_REG_ADD:
            e2proomdata.als107_Ed_Down=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_Ed_Down", (int16_t)num)});
            return 1;
        break;
        case ALS107_ST_UP_REG_ADD:
            e2proomdata.als107_St_Up=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_St_Up", (int16_t)num)});
            return 1;
        break;
        case ALS107_ED_UP_REG_ADD:
            e2proomdata.als107_Ed_Up=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_Ed_Up", (int16_t)num)});
            return 1;
        break;
        case ALS107_DIS_CENTER_ST_REG_ADD:
            e2proomdata.als107_dis_center_st=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_dis_center_st", (int16_t)num)});
            return 1;
        break;
        case ALS107_DIS_CENTER_ST2_REG_ADD:
            e2proomdata.als107_dis_center_st2=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_dis_center_st2", (int16_t)num)});
            return 1;
        break;
        case ALS107_DIS_CENTER_ED2_REG_ADD:
            e2proomdata.als107_dis_center_ed2=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_dis_center_ed2", (int16_t)num)});
            return 1;
        break;
        case ALS107_B_KALMANFILTER_REG_ADD:
            e2proomdata.als107_b_KalmanFilter=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_b_KalmanFilter", (int16_t)num)});
            return 1;
        break;

        case ALS107_KALMANQF_REG_ADD:
            e2proomdata.als107_KalmanQF=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_KalmanQF", (int16_t)num)});
            return 1;
        break;

        case ALS107_KALMANRF_REG_ADD:
            e2proomdata.als107_KalmanRF=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als107_KalmanRF", (int16_t)num)});
            return 1;
        break;

        case ALS107_INIT_REG_ADD:
            if(num==1)
            {
                e2proomdata.init_als107_para();
                init_als107_parameter();
                parameterport_mapping->tab_registers[ALS107_INIT_REG_ADD]=0;
            }
            return 1;
  
        default:
        break;
    }
    return 0;
}

void Modbus::init_als107_parameter()
{
    parameterport_mapping->tab_registers[ALS107_EXPOSURE_TIME_REG_ADD]=e2proomdata.als107_exposure_time;
    parameterport_mapping->tab_registers[ALS107_PINGJUN_REG_ADD]=e2proomdata.als107_pingjun;
    parameterport_mapping->tab_registers[ALS107_B_YANMOFUZHU_REG_ADD]=e2proomdata.als107_b_yanmofuzhu;
    parameterport_mapping->tab_registers[ALS107_B_GUDINGQUYU_REG_ADD]=e2proomdata.als107_b_gudingquyu;
    parameterport_mapping->tab_registers[ALS107_WIDTHLIANTONGDIS_REG_ADD]=e2proomdata.als107_widthliantongdis;
    parameterport_mapping->tab_registers[ALS107_HIGHLIANTONGDIS_REG_ADD]=e2proomdata.als107_highliantongdis;
    parameterport_mapping->tab_registers[ALS107_GUJIAERZHI_REG_ADD]=e2proomdata.als107_gujiaerzhi;
    parameterport_mapping->tab_registers[ALS107_JIGUANGHIGHT_REG_ADD]=e2proomdata.als107_jiguanghight;
    parameterport_mapping->tab_registers[ALS107_JIGUANGLONG_REG_ADD]=e2proomdata.als107_jiguanglong;
    parameterport_mapping->tab_registers[ALS107_JIGUANGKUANDU_REG_ADD]=e2proomdata.als107_jiguangkuandu;
    parameterport_mapping->tab_registers[ALS107_UPDIF_REG_ADD]=e2proomdata.als107_Updif;
    parameterport_mapping->tab_registers[ALS107_UPDIFMIN_REG_ADD]=e2proomdata.als107_Updifmin;
    parameterport_mapping->tab_registers[ALS107_UPLONG_REG_ADD]=e2proomdata.als107_Uplong;
    parameterport_mapping->tab_registers[ALS107_DOWNDIF_REG_ADD]=e2proomdata.als107_Downdif;
    parameterport_mapping->tab_registers[ALS107_DOWNDIFMIN_REG_ADD]=e2proomdata.als107_Downdifmin;
    parameterport_mapping->tab_registers[ALS107_DOWNDLONG_REG_ADD]=e2proomdata.als107_Downdlong;
    parameterport_mapping->tab_registers[ALS107_ST_DOWN_REG_ADD]=e2proomdata.als107_St_Down;
    parameterport_mapping->tab_registers[ALS107_ED_DOWN_REG_ADD]=e2proomdata.als107_Ed_Down;
    parameterport_mapping->tab_registers[ALS107_ST_UP_REG_ADD]=e2proomdata.als107_St_Up;
    parameterport_mapping->tab_registers[ALS107_ED_UP_REG_ADD]=e2proomdata.als107_Ed_Up;
    parameterport_mapping->tab_registers[ALS107_DIS_CENTER_ST_REG_ADD]=e2proomdata.als107_dis_center_st;
    parameterport_mapping->tab_registers[ALS107_DIS_CENTER_ST2_REG_ADD]=e2proomdata.als107_dis_center_st2;
    parameterport_mapping->tab_registers[ALS107_DIS_CENTER_ED2_REG_ADD]=e2proomdata.als107_dis_center_ed2;
    parameterport_mapping->tab_registers[ALS107_B_KALMANFILTER_REG_ADD]=e2proomdata.als107_b_KalmanFilter;   
    parameterport_mapping->tab_registers[ALS107_KALMANQF_REG_ADD]=e2proomdata.als107_KalmanQF;  
    parameterport_mapping->tab_registers[ALS107_KALMANRF_REG_ADD]=e2proomdata.als107_KalmanRF;  
}

}