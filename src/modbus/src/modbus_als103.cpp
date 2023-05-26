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

int Modbus::als103_task_parameter(int ddr,u_int16_t num)
{
    switch(ddr)
    {
        case ALS103_EXPOSURE_TIME_REG_ADD:
            if((int)num>=(int)e2proomdata.als103_exposure_time_min&&(int)num<=(int)e2proomdata.als103_exposure_time_max)
            {
                e2proomdata.als103_exposure_time=num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als103_exposure_time", num)});
                return 1;
            }
        break;
        case ALS103_PINGJUN_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als103_pingjun_min&&(int)((int16_t)num)<=(int)e2proomdata.als103_pingjun_max)
            {
                e2proomdata.als103_pingjun=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als103_pingjun", (int16_t)num)});
                return 1;
            }
        break;
        case ALS103_GUJIAERZHI_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als103_gujiaerzhi_min&&(int)((int16_t)num)<=(int)e2proomdata.als103_gujiaerzhi_max)
            {
                e2proomdata.als103_gujiaerzhi=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als103_gujiaerzhi", (int16_t)num)});
                return 1;
            }
        break;
        case ALS103_WIDTHLIANTONGDIS_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als103_widthliantongdis_min&&(int)((int16_t)num)<=(int)e2proomdata.als103_widthliantongdis_max)
            {
                e2proomdata.als103_widthliantongdis=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als103_widthliantongdis", (int16_t)num)});
                return 1;
            }
        break;
        case ALS103_HIGHLIANTONGDIS_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als103_highliantongdis_min&&(int)((int16_t)num)<=(int)e2proomdata.als103_highliantongdis_max)
            {
                e2proomdata.als103_highliantongdis=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als103_highliantongdis", (int16_t)num)});
                return 1;
            }
        break;
        case ALS103_JIGUANGLONG_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als103_jiguanglong_min&&(int)((int16_t)num)<=(int)e2proomdata.als103_jiguanglong_max)
            {
                e2proomdata.als103_jiguanglong=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als103_jiguanglong", (int16_t)num)});
                return 1;
            }
        break;
        case ALS103_JIGUANGKUANDU_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als103_jiguangkuandu_min&&(int)((int16_t)num)<=(int)e2proomdata.als103_jiguangkuandu_max)
            {
                e2proomdata.als103_jiguangkuandu=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als103_jiguangkuandu", (int16_t)num)});
                return 1;
            }
        break;
        case ALS103_JIGUANGDUIBIDU_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als103_jiguangduibidu_min&&(int)((int16_t)num)<=(int)e2proomdata.als103_jiguangduibidu_max)
            {
                e2proomdata.als103_jiguangduibidu=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als103_jiguangduibidu", (int16_t)num)});
                return 1;
            }
        break;
        case ALS103_LVBOMOD_REG_ADD:
            if((int)((int16_t)num)>=(int)e2proomdata.als103_lvbomod_min&&(int)((int16_t)num)<=(int)e2proomdata.als103_lvbomod_max)
            {
                e2proomdata.als103_lvbomod=(int16_t)num;
                _param_laserimagepos->set_parameters({rclcpp::Parameter("als103_lvbomod", (int16_t)num)});
                return 1;
            }
        break;

        case ALS103_INIT_REG_ADD:
            if(num==1)
            {
                e2proomdata.init_als103_para();
                init_als103_parameter();
                parameterport_mapping->tab_registers[ALS103_INIT_REG_ADD]=0;
            }
            return 1;
  
        default:
        break;
    }
    return 0;
}

void Modbus::init_als103_parameter()
{
    parameterport_mapping->tab_registers[ALS103_EXPOSURE_TIME_REG_ADD]=e2proomdata.als103_exposure_time;
    parameterport_mapping->tab_registers[ALS103_PINGJUN_REG_ADD]=e2proomdata.als103_pingjun;
    parameterport_mapping->tab_registers[ALS103_GUJIAERZHI_REG_ADD]=e2proomdata.als103_gujiaerzhi;
    parameterport_mapping->tab_registers[ALS103_WIDTHLIANTONGDIS_REG_ADD]=e2proomdata.als103_widthliantongdis;
    parameterport_mapping->tab_registers[ALS103_HIGHLIANTONGDIS_REG_ADD]=e2proomdata.als103_highliantongdis;
    parameterport_mapping->tab_registers[ALS103_JIGUANGLONG_REG_ADD]=e2proomdata.als103_jiguanglong;
    parameterport_mapping->tab_registers[ALS103_JIGUANGKUANDU_REG_ADD]=e2proomdata.als103_jiguangkuandu;
    parameterport_mapping->tab_registers[ALS103_JIGUANGDUIBIDU_REG_ADD]=e2proomdata.als103_jiguangduibidu;
    parameterport_mapping->tab_registers[ALS103_LVBOMOD_REG_ADD]=e2proomdata.als103_lvbomod;
}

}