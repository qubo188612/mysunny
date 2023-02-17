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

int Modbus::als108_task_parameter(int ddr,u_int16_t num)
{
    switch(ddr)
    {
        case ALS108_EXPOSURE_TIME_REG_ADD:
            e2proomdata.als108_exposure_time=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als108_exposure_time", num)});
            return 1;
        break;
        case ALS108_CENTER_X_REG_ADD:
            e2proomdata.als108_center_x=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als108_center_x", num)});
            return 1;
        break;
        case ALS108_CENTER_Y_REG_ADD:
            e2proomdata.als108_center_y=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als108_center_y", num)});
            return 1;
        break;
        case ALS108_SEARCT_W_REG_ADD:
            e2proomdata.als108_search_w=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als108_search_w", num)});
            return 1;
        break;
        case ALS108_SEARCT_H_REG_ADD:
            e2proomdata.als108_search_h=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als108_search_h", num)});
            return 1;
        break;
        case ALS108_STC_ALPHA_REG_ADD:
            e2proomdata.als108_STC_alpha=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als108_STC_alpha", num)});
            return 1;
        break;
        case ALS108_STC_BETA_REG_ADD:
            e2proomdata.als108_STC_beta=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als108_STC_beta", num)});
            return 1;
        break;
        case ALS108_STC_RHO_REG_ADD:
            e2proomdata.als108_STC_rho=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als108_STC_rho", num)});
            return 1;
        break;
        case ALS108_STC_SIGMA_REG_ADD:
            e2proomdata.als108_STC_sigma=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als108_STC_sigma", num)});
            return 1;
        break;

        case ALS108_INIT_REG_ADD:
            if(num==1)
            {
                e2proomdata.init_als108_para();
                init_als108_parameter();
                parameterport_mapping->tab_registers[ALS108_INIT_REG_ADD]=0;
            }
            return 1;
  
        default:
        break;
    }
    return 0;
}

void Modbus::init_als108_parameter()
{
    parameterport_mapping->tab_registers[ALS108_EXPOSURE_TIME_REG_ADD]=e2proomdata.als108_exposure_time;
    parameterport_mapping->tab_registers[ALS108_CENTER_X_REG_ADD]=e2proomdata.als108_center_x;
    parameterport_mapping->tab_registers[ALS108_CENTER_Y_REG_ADD]=e2proomdata.als108_center_y;
    parameterport_mapping->tab_registers[ALS108_SEARCT_W_REG_ADD]=e2proomdata.als108_search_w;
    parameterport_mapping->tab_registers[ALS108_SEARCT_H_REG_ADD]=e2proomdata.als108_search_h;
    parameterport_mapping->tab_registers[ALS108_STC_ALPHA_REG_ADD]=e2proomdata.als108_STC_alpha;
    parameterport_mapping->tab_registers[ALS108_STC_BETA_REG_ADD]=e2proomdata.als108_STC_beta;
    parameterport_mapping->tab_registers[ALS108_STC_RHO_REG_ADD]=e2proomdata.als108_STC_rho;
    parameterport_mapping->tab_registers[ALS108_STC_SIGMA_REG_ADD]=e2proomdata.als108_STC_sigma;
}

}