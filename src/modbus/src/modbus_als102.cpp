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

int Modbus::als102_task_parameter(int ddr,u_int16_t num)
{
    switch(ddr)
    {
        case ALS102_EXPOSURE_TIME_REG_ADD:
            e2proomdata.als102_exposure_time=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_exposure_time", num)});
            return 1;
        break;
        case ALS102_PINGJUN_REG_ADD:
            e2proomdata.als102_pingjun=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_pingjun", num)});
            return 1;
        break;
        case ALS102_B_YANMOFUZHU_REG_ADD:
            e2proomdata.als102_b_yanmofuzhu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_b_yanmofuzhu", num)});
            return 1;
        break;
        case ALS102_B_GUDINGQUYU_REG_ADD:
            e2proomdata.als102_b_gudingquyu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_b_gudingquyu", num)});
            return 1;
        break;
        case ALS102_WIDTHLIANTONGDIS_REG_ADD:
            e2proomdata.als102_widthliantongdis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_widthliantongdis", num)});
            return 1;
        break;
        case ALS102_HIGHLIANTONGDIS_REG_ADD:
            e2proomdata.als102_highliantongdis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_highliantongdis", num)});
            return 1;
        break;
        case ALS102_GUJIAERZHI_REG_ADD:
            e2proomdata.als102_gujiaerzhi=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_gujiaerzhi", num)});
            return 1;
        break;
        case ALS102_JIGUANGHIGHT_REG_ADD:
            e2proomdata.als102_jiguanghight=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_jiguanghight", num)});
            return 1;
        break;
        case ALS102_JIGUANGLONG_REG_ADD:
            e2proomdata.als102_jiguanglong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_jiguanglong", num)});
            return 1;
        break;
        case ALS102_JIGUANGKUANDU_REG_ADD:
            e2proomdata.als102_jiguangkuandu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_jiguangkuandu", num)});
            return 1;
        break;
        case ALS102_UPDIF_REG_ADD:
            e2proomdata.als102_Updif=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_Updif", num)});
            return 1;
        break;
        case ALS102_UPDIFMIN_REG_ADD:
            e2proomdata.als102_Updifmin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_Updifmin", num)});
            return 1;
        break;
        case ALS102_UPLONG_REG_ADD:
            e2proomdata.als102_Uplong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_Uplong", num)});
            return 1;
        break;
        case ALS102_DOWNDIF_REG_ADD:
            e2proomdata.als102_Downdif=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_Downdif", num)});
            return 1;
        break;
        case ALS102_DOWNDIFMIN_REG_ADD:
            e2proomdata.als102_Downdifmin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_Downdifmin", num)});
            return 1;
        break;
        case ALS102_DOWNDLONG_REG_ADD:
            e2proomdata.als102_Downdlong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_Downdlong", num)});
            return 1;
        break;
        case ALS102_DUANXIANERZHI_REG_ADD:
            e2proomdata.als102_duanxianerzhi=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_duanxianerzhi", num)});
            return 1;
        break;
        case ALS102_ERZHISIZE_REG_ADD:
            e2proomdata.als102_erzhisize=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_erzhisize", num)});
            return 1;
        break;
        case ALS102_ERZHISIZE2_REG_ADD:
            e2proomdata.als102_erzhisize2=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_erzhisize2", num)});
            return 1;
        break;
        case ALS102_SEARCHDECTANCEMAX_REG_ADD:
            e2proomdata.als102_searchdectancemax=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_searchdectancemax", num)});
            return 1;
        break;
        case ALS102_SEARCHDECTANCEMIN_REG_ADD:
            e2proomdata.als102_searchdectancemin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_searchdectancemin", num)});
            return 1;
        break;
        case ALS102_DIS_CENTER_ST_REG_ADD:
            e2proomdata.als102_dis_center_st=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_dis_center_st", num)});
            return 1;
        break;
        case ALS102_DIS_CENTER_ED_REG_ADD:
            e2proomdata.als102_dis_center_ed=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als102_dis_center_ed", num)});
            return 1;
        break;


        case ALS102_INIT_REG_ADD:
            if(num==1)
            {
                e2proomdata.init_als102_para();
                init_als102_parameter();
                parameterport_mapping->tab_registers[ALS102_INIT_REG_ADD]=0;
            }
            return 1;
  
        default:
        break;
    }
    return 0;
}

void Modbus::init_als102_parameter()
{
    parameterport_mapping->tab_registers[ALS102_EXPOSURE_TIME_REG_ADD]=e2proomdata.als102_exposure_time;
    parameterport_mapping->tab_registers[ALS102_PINGJUN_REG_ADD]=e2proomdata.als102_pingjun;
    parameterport_mapping->tab_registers[ALS102_B_YANMOFUZHU_REG_ADD]=e2proomdata.als102_b_yanmofuzhu;
    parameterport_mapping->tab_registers[ALS102_B_GUDINGQUYU_REG_ADD]=e2proomdata.als102_b_gudingquyu;
    parameterport_mapping->tab_registers[ALS102_WIDTHLIANTONGDIS_REG_ADD]=e2proomdata.als102_widthliantongdis;
    parameterport_mapping->tab_registers[ALS102_HIGHLIANTONGDIS_REG_ADD]=e2proomdata.als102_highliantongdis;
    parameterport_mapping->tab_registers[ALS102_GUJIAERZHI_REG_ADD]=e2proomdata.als102_gujiaerzhi;
    parameterport_mapping->tab_registers[ALS102_JIGUANGHIGHT_REG_ADD]=e2proomdata.als102_jiguanghight;
    parameterport_mapping->tab_registers[ALS102_JIGUANGLONG_REG_ADD]=e2proomdata.als102_jiguanglong;
    parameterport_mapping->tab_registers[ALS102_JIGUANGKUANDU_REG_ADD]=e2proomdata.als102_jiguangkuandu;
    parameterport_mapping->tab_registers[ALS102_UPDIF_REG_ADD]=e2proomdata.als102_Updif;
    parameterport_mapping->tab_registers[ALS102_UPDIFMIN_REG_ADD]=e2proomdata.als102_Updifmin;
    parameterport_mapping->tab_registers[ALS102_UPLONG_REG_ADD]=e2proomdata.als102_Uplong;
    parameterport_mapping->tab_registers[ALS102_DOWNDIF_REG_ADD]=e2proomdata.als102_Downdif;
    parameterport_mapping->tab_registers[ALS102_DOWNDIFMIN_REG_ADD]=e2proomdata.als102_Downdifmin;
    parameterport_mapping->tab_registers[ALS102_DOWNDLONG_REG_ADD]=e2proomdata.als102_Downdlong;
    parameterport_mapping->tab_registers[ALS102_DUANXIANERZHI_REG_ADD]=e2proomdata.als102_duanxianerzhi;
    parameterport_mapping->tab_registers[ALS102_ERZHISIZE_REG_ADD]=e2proomdata.als102_erzhisize;
    parameterport_mapping->tab_registers[ALS102_ERZHISIZE2_REG_ADD]=e2proomdata.als102_erzhisize2;
    parameterport_mapping->tab_registers[ALS102_SEARCHDECTANCEMAX_REG_ADD]=e2proomdata.als102_searchdectancemax;
    parameterport_mapping->tab_registers[ALS102_SEARCHDECTANCEMIN_REG_ADD]=e2proomdata.als102_searchdectancemin;
    parameterport_mapping->tab_registers[ALS102_DIS_CENTER_ST_REG_ADD]=e2proomdata.als102_dis_center_st;
    parameterport_mapping->tab_registers[ALS102_DIS_CENTER_ED_REG_ADD]=e2proomdata.als102_dis_center_ed;
}

}