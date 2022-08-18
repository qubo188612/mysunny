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
            e2proomdata.als100_exposure_time=num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_exposure_time", num)});
            return 1;
        break;
        case ALS100_B_YANMOFUZHU_REG_ADD:
            e2proomdata.als100_b_yanmofuzhu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_b_yanmofuzhu", num)});
            return 1;
        break;
        case ALS100_B_GUDINGQUYU_REG_ADD:
            e2proomdata.als100_b_gudingquyu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_b_gudingquyu", num)});
            return 1;
        break;
        case ALS100_WIDTHLIANTONGDIS_REG_ADD:
            e2proomdata.als100_widthliantongdis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_widthliantongdis", num)});
            return 1;
        break;
        case ALS100_HIGHLIANTONGDIS_REG_ADD:
            e2proomdata.als100_highliantongdis=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_highliantongdis", num)});
            return 1;
        break;
        case ALS100_GUJIAERZHI_REG_ADD:
            e2proomdata.als100_gujiaerzhi=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_gujiaerzhi", num)});
            return 1;
        break;
        case ALS100_IGUANGHIGHT_REG_ADD:
            e2proomdata.als100_jiguanghight=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_jiguanghight", num)});
            return 1;
        break;
        case ALS100_JIGUANGLONG_REG_ADD:
            e2proomdata.als100_jiguanglong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_jiguanglong", num)});
            return 1;
        break;
        case ALS100_JIGUANGKUANDU_REG_ADD:
            e2proomdata.als100_jiguangkuandu=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_jiguangkuandu", num)});
            return 1;
        break;
        case ALS100_UPDIF_REG_ADD:
            e2proomdata.als100_Updif=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Updif", num)});
            return 1;
        break;
        case ALS100_UPDIFMIN_REG_ADD:
            e2proomdata.als100_Updifmin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Updifmin", num)});
            return 1;
        break;
        case ALS100_UPLONG_REG_ADD:
            e2proomdata.als100_Uplong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Uplong", num)});
            return 1;
        break;
        case ALS100_DOWNDIF_REG_ADD:
            e2proomdata.als100_Downdif=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Downdif", num)});
            return 1;
        break;
        case ALS100_DOWNDIFMIN_REG_ADD:
            e2proomdata.als100_Downdifmin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Downdifmin", num)});
            return 1;
        break;
        case ALS100_DOWNDLONG_REG_ADD:
            e2proomdata.als100_Downdlong=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_Downdlong", num)});
            return 1;
        break;
        case ALS100_DUANXIANERZHI_REG_ADD:
            e2proomdata.als100_duanxianerzhi=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_duanxianerzhi", num)});
            return 1;
        break;
        case ALS100_ERZHISIZE_REG_ADD:
            e2proomdata.als100_erzhisize=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_erzhisize", num)});
            return 1;
        break;
        case ALS100_ERZHISIZE2_REG_ADD:
            e2proomdata.als100_erzhisize2=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_erzhisize2", num)});
            return 1;
        break;
        case ALS100_SEARCHDECTANCEMAX_REG_ADD:
            e2proomdata.als100_searchdectancemax=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_searchdectancemax", num)});
            return 1;
        break;
        case ALS100_SEARCHDECTANCEMIN_REG_ADD:
            e2proomdata.als100_searchdectancemin=(int16_t)num;
            _param_laserimagepos->set_parameters({rclcpp::Parameter("als100_searchdectancemin", num)});
            return 1;
        break;
        default:
        break;
    }
    return 0;
}

}