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

int Modbus::craft_task_parameter(int ddr,u_int16_t num)
{
    switch(ddr)
    {
        case CRAFT_ID_REG_ADD:
            e2proomdata.craft_Id=(int16_t)num;
            _param_pclout_set->set_parameters({rclcpp::Parameter("craft_Id", num)});
            return 1;
        break;
        case CRAFT_ALS1_REG_ADD:
            e2proomdata.craft_als1=(int16_t)num;
            _param_pclout_set->set_parameters({rclcpp::Parameter("craft_als1", num)});
            return 1;
        break;
        case CRAFT_ALS2_REG_ADD:
            e2proomdata.craft_als1=(int16_t)num;
            _param_pclout_set->set_parameters({rclcpp::Parameter("craft_als2", num)});
            return 1;
        break;
        case CRAFT_ALS3_REG_ADD:
            e2proomdata.craft_als1=(int16_t)num;
            _param_pclout_set->set_parameters({rclcpp::Parameter("craft_als3", num)});
            return 1;
        break;
        case CRAFT_ALS4_REG_ADD:
            e2proomdata.craft_als1=(int16_t)num;
            _param_pclout_set->set_parameters({rclcpp::Parameter("craft_als4", num)});
            return 1;
        break;
        case CRAFT_ALS5_REG_ADD:
            e2proomdata.craft_als1=(int16_t)num;
            _param_pclout_set->set_parameters({rclcpp::Parameter("craft_als5", num)});
            return 1;
        break;
        case CRAFT_ALS6_REG_ADD:
            e2proomdata.craft_als1=(int16_t)num;
            _param_pclout_set->set_parameters({rclcpp::Parameter("craft_als6", num)});
            return 1;
        break;
        case CRAFT_ALS7_REG_ADD:
            e2proomdata.craft_als1=(int16_t)num;
            _param_pclout_set->set_parameters({rclcpp::Parameter("craft_als7", num)});
            return 1;
        break;
        case CRAFT_ALS8_REG_ADD:
            e2proomdata.craft_als1=(int16_t)num;
            _param_pclout_set->set_parameters({rclcpp::Parameter("craft_als8", num)});
            return 1;
        break;
        case CRAFT_ALS9_REG_ADD:
            e2proomdata.craft_als1=(int16_t)num;
            _param_pclout_set->set_parameters({rclcpp::Parameter("craft_als9", num)});
            return 1;
        break;
        case CRAFT_ALS10_REG_ADD:
            e2proomdata.craft_als1=(int16_t)num;
            _param_pclout_set->set_parameters({rclcpp::Parameter("craft_als10", num)});
            return 1;
        break;
  
        default:
        break;
    }
    return 0;
}

void Modbus::init_craft_parameter()
{
    mb_mapping->tab_registers[CRAFT_ID_REG_ADD]=e2proomdata.craft_Id;
    mb_mapping->tab_registers[CRAFT_ALS1_REG_ADD]=e2proomdata.craft_als1;
    mb_mapping->tab_registers[CRAFT_ALS2_REG_ADD]=e2proomdata.craft_als2;
    mb_mapping->tab_registers[CRAFT_ALS3_REG_ADD]=e2proomdata.craft_als3;
    mb_mapping->tab_registers[CRAFT_ALS4_REG_ADD]=e2proomdata.craft_als4;
    mb_mapping->tab_registers[CRAFT_ALS6_REG_ADD]=e2proomdata.craft_als5;
    mb_mapping->tab_registers[CRAFT_ALS7_REG_ADD]=e2proomdata.craft_als6;
    mb_mapping->tab_registers[CRAFT_ALS8_REG_ADD]=e2proomdata.craft_als7;
    mb_mapping->tab_registers[CRAFT_ALS9_REG_ADD]=e2proomdata.craft_als8;
    mb_mapping->tab_registers[CRAFT_ALS10_REG_ADD]=e2proomdata.craft_als9;
}

}