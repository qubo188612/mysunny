#include "laser_imagepos/laser_imagepos.hpp"

#include "opencv2/opencv.hpp"
namespace laser_imagepos
{

using rcl_interfaces::msg::SetParametersResult;

void LaserImagePos::alg100_declare_parameters()
{
    this->declare_parameter("als100_exposure_time", pm.als100_exposure_time);
    this->declare_parameter("als100_pingjun", pm.als100_pingjun);
    this->declare_parameter("als100_b_yanmofuzhu", pm.als100_b_yanmofuzhu);
    this->declare_parameter("als100_b_gudingquyu", pm.als100_b_gudingquyu);
    this->declare_parameter("als100_widthliantongdis", pm.als100_widthliantongdis);
    this->declare_parameter("als100_highliantongdis", pm.als100_highliantongdis);
    this->declare_parameter("als100_gujiaerzhi", pm.als100_gujiaerzhi);
    this->declare_parameter("als100_jiguanghight", pm.als100_jiguanghight);
    this->declare_parameter("als100_jiguanglong", pm.als100_jiguanglong);
    this->declare_parameter("als100_jiguangkuandu", pm.als100_jiguangkuandu);
    this->declare_parameter("als100_Updif", pm.als100_Updif);
    this->declare_parameter("als100_Updifmin", pm.als100_Updifmin);
    this->declare_parameter("als100_Uplong", pm.als100_Uplong);
    this->declare_parameter("als100_Downdif", pm.als100_Downdif);
    this->declare_parameter("als100_Downdifmin", pm.als100_Downdifmin);
    this->declare_parameter("als100_Downdlong", pm.als100_Downdlong);
    this->declare_parameter("als100_duanxianerzhi", pm.als100_duanxianerzhi);
    this->declare_parameter("als100_erzhisize", pm.als100_erzhisize);
    this->declare_parameter("als100_erzhisize2", pm.als100_erzhisize2);
    this->declare_parameter("als100_searchdectancemax", pm.als100_searchdectancemax);
    this->declare_parameter("als100_searchdectancemin", pm.als100_searchdectancemin);
}

void LaserImagePos::alg100_update_parameters()
{
  const auto & vp = this->get_parameters(KEYS_ALS100);
  for (const auto & p : vp) {
    if (p.get_name() == "als100_exposure_time") {
      pm.als100_exposure_time = p.as_int();
    } else if (p.get_name() == "als100_pingjun") {
      pm.als100_pingjun = p.as_int();
    }
    else if (p.get_name() == "als100_b_yanmofuzhu") {
      pm.als100_b_yanmofuzhu = p.as_int();
    }
    else if (p.get_name() == "als100_b_gudingquyu") {
      pm.als100_b_gudingquyu = p.as_int();
    }
    else if (p.get_name() == "als100_widthliantongdis") {
      pm.als100_widthliantongdis = p.as_int();
    }
    else if (p.get_name() == "als100_highliantongdis") {
      pm.als100_highliantongdis = p.as_int();
    }
    else if (p.get_name() == "als100_gujiaerzhi") {
      pm.als100_gujiaerzhi = p.as_int();
    }
    else if (p.get_name() == "als100_jiguanghight") {
      pm.als100_jiguanghight = p.as_int();
    }
    else if (p.get_name() == "als100_jiguanglong") {
      pm.als100_jiguanglong = p.as_int();
    }
    else if (p.get_name() == "als100_jiguangkuandu") {
      pm.als100_jiguangkuandu = p.as_int();
    }
    else if (p.get_name() == "als100_Updif") {
      pm.als100_Updif = p.as_int();
    }
    else if (p.get_name() == "als100_Updifmin") {
      pm.als100_Updifmin = p.as_int();
    }
    else if (p.get_name() == "als100_Uplong") {
      pm.als100_Uplong = p.as_int();
    }
    else if (p.get_name() == "als100_Downdif") {
      pm.als100_Downdif = p.as_int();
    }
    else if (p.get_name() == "als100_Downdifmin") {
      pm.als100_Downdifmin = p.as_int();
    }
    else if (p.get_name() == "als100_Downdlong") {
      pm.als100_Downdlong = p.as_int();
    }
    else if (p.get_name() == "als100_duanxianerzhi") {
      pm.als100_duanxianerzhi = p.as_int();
    }
    else if (p.get_name() == "als100_erzhisize") {
      pm.als100_erzhisize = p.as_int();
    }
    else if (p.get_name() == "als100_erzhisize2") {
      pm.als100_erzhisize2 = p.as_int();
    }
    else if (p.get_name() == "als100_searchdectancemax") {
      pm.als100_searchdectancemax = p.as_int();
    }
    else if (p.get_name() == "als100_searchdectancemin") {
      pm.als100_searchdectancemin = p.as_int();
    }
  }
}

int LaserImagePos::alg100_getcallbackParameter(const rclcpp::Parameter &p)
{
    if (p.get_name() == "als100_exposure_time") {
        auto k = p.as_int();
        if (k <20 || k>65535) {
            return -1;}
        else{pm.als100_exposure_time=k;
            if(pm.task_num>=100&&pm.task_num<200){
                _param_camera->set_parameters({rclcpp::Parameter("exposure_time", pm.als100_exposure_time)});}
            return 1;}}
    else if(p.get_name() == "als100_pingjun") {
        auto k = p.as_int();
        if (k <0 || k>255) {
            return -1;}
        else{pm.als100_pingjun=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_b_yanmofuzhu") {
        auto k = p.as_int();
        if (k != 0 && k!=1) {
            return -1;}
        else{pm.als100_b_yanmofuzhu=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_b_gudingquyu") {
        auto k = p.as_int();
        if (k != 0 && k!=1) {
            return -1;}
        else{pm.als100_b_gudingquyu=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_widthliantongdis") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als100_widthliantongdis=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_highliantongdis") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als100_highliantongdis=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_gujiaerzhi") {
        auto k = p.as_int();
        if (k < 0 || k > 255) {
            return -1;}
        else{pm.als100_gujiaerzhi=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_jiguanghight") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als100_jiguanghight=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_jiguanglong") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als100_jiguanglong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_jiguangkuandu") {
        auto k = p.as_int();
        if (k < 0 || k > 20) {
            return -1;}
        else{pm.als100_jiguangkuandu=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_Updif") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als100_Updif=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_Updifmin") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als100_Updifmin=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_Uplong") {
        auto k = p.as_int();
        if (k < 1 || k > 500) {
            return -1;}
        else{pm.als100_Uplong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_Downdif") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als100_Downdif=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_Downdifmin") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
            return -1;}
        else{pm.als100_Downdifmin=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_Downdlong") {
        auto k = p.as_int();
        if (k < 1 || k > 500) {
            return -1;}
        else{pm.als100_Downdlong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_erzhisize") {
        auto k = p.as_int();
        if (k < 80 || k > 500) {
            return -1;}
        else{pm.als100_erzhisize=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_erzhisize2") {
        auto k = p.as_int();
        if (k < 30 || k > 500) {
            return -1;}
        else{pm.als100_erzhisize2=p.as_int();
            return 1;}}
    else if(p.get_name() == "als100_searchdectancemax") {
        auto k = p.as_int();
        if (k < 30 || k > 500) {
            return -1;}
        else{pm.als100_searchdectancemax=p.as_int();
            return 1;}}   
    else if(p.get_name() == "als100_searchdectancemin") {
        auto k = p.as_int();
        if (k < 1 || k > 500) {
            return -1;}
        else{pm.als100_searchdectancemin=p.as_int();
            return 1;}}        

    return 0;
}

int LaserImagePos::alg100_runimage( cv::Mat &cvimgIn,
                                    std::vector <cv::Point2f> &pointcloud,
                                    std::vector <cv::Point2f> &namepoint)    //输出结果点信息
{
    Int32 i,j;
    Myhalcv2::Mat imageIn,imageGasu,imageGasupain,imageBry,m_tempmatIn,m_matMask;
    Myhalcv2::Mat m16_filterIma,m_filter,m_brygujia;
    Int32 nWidth=cvimgIn.cols;	//输入图像宽
    Int32 nHeight=cvimgIn.rows;	//输入图像高
    Uint8 bryvalue;
    Int32 i32_bryvalue;
    Uint8 filterdata[25]={0,0,0,0,0,
                          0,0,0,0,0,
                          1,1,1,1,1,
                          0,0,0,0,0,
                          0,0,0,0,0};
    Int16 filterdata2[10]={1,1,1,1,1,-1,-1,-1,-1,-1};

    Myhalcv2::L_Point32 f_center={-1,-1};
    Int32 X_Linestarty=0;
    Int32 X_Lineendy=0;
    Myhalcv2::Mat i32_mXline,m_filter2,m32_filterIma;
    Int32 zhengshunum=0;
    Int32 stepfind=0;
    Myhalcv2::L_Point32 stepfindST,stepfindED;//结果线1拟合区域,(下方)
    Myhalcv2::L_Point32 midfindST,midfindED;//结果线2拟合区域,(上方)
    Int32 minj,mini;
    Int32 latsj;
    Int32 linedistance1;
    Int32 nihenum=0;
    Int32 nstarti,nendi,nstartj,nendj;
    Myhalcv2::L_Point32 linepoint32ST,linepoint32ED;
    Myhalcv2::L_line tileline;	//结果线2以及原图的线,(短的)
    Myhalcv2::L_line headline;	//结果线1以及原图的线,(短的)
    Myhalcv2::L_line32 tileline32;
    Myhalcv2::L_line32 headline32;
    Myhalcv2::L_Point32 resultfocal1,resultfocal2,resultfocal;//交点
    Int32 t;
    Int32 jiguangTop,jiguangDeep,jiguangLeft,jiguangRight;
    Int32 leijiwrite;
    Int32 centerj,centeri;
    Int32 tempi;
    Uint8 handianEn;
    Myhalcv2::L_Point32 temp_resultfocal1,temp_resultfocal2;
    Myhalcv2::MyConect ImageConect,ImageConectlong,ImageConectlongPX,Imageheadline;
    Myhalcv2::houghlineinfo headlinehough,tilelinehough;
    cv::Point cv_point_st,cv_point_ed;
    Int32 b_duanxianmoshi=0;//断线模式：1,下方线“压”上方线。0,上方线“压”下方

    /*********************/
    //算法参数
    Int32 pingjun=pm.als100_pingjun;//15;//二值阈值
    Int32 b_yanmofuzhu=pm.als100_b_yanmofuzhu;//1;//是否使用掩摸辅助
    Int32 b_gudingquyu=pm.als100_b_gudingquyu;//0;//是否固定区域
    Int32 widthliantongdis=pm.als100_widthliantongdis;//2;//激光宽度连通距离
    Int32 highliantongdis=pm.als100_highliantongdis;//15;//激光长度连通距离
    Int32 gujiaerzhi=pm.als100_gujiaerzhi;//160;//找骨架二值图
    Int32 jiguanghight=pm.als100_jiguanghight;//50;//整体激光最短长度
    Int32 jiguanglong=pm.als100_jiguanglong;//20;//单边激光最短长度
    Int32 jiguangkuandu=pm.als100_jiguangkuandu;//4;//激光粗细
    Int32 Updif=pm.als100_Updif;//0;//上半段倾斜开始斜度10
    Int32 Updifmin=pm.als100_Updifmin;//-5;//上半段倾斜终止斜度10
    Int32 Uplong=pm.als100_Uplong;//5;//上半段直线长度
    Int32 Downdif=pm.als100_Downdif;//0;//下半段倾斜开始斜度0
    Int32 Downdifmin=pm.als100_Downdifmin;//5;//下半段倾斜终止斜度0
    Int32 Downdlong=pm.als100_Downdlong;//5;//下半段直线长度
    Int32 duanxianerzhi=pm.als100_duanxianerzhi;//180;//找断线的二值阈值
    Int32 erzhisize=pm.als100_erzhisize;//150;//断线二值图的上下阈值尺寸
    Int32 erzhisize2=pm.als100_erzhisize2;//60;//断线二值图的左右阈值尺寸
    Int32 searchdectancemax=pm.als100_searchdectancemax;//160;//搜寻焊缝端点距离中央凹槽最远的距离
    Int32 searchdectancemin=pm.als100_searchdectancemin;//25;//搜寻焊缝端点距离中央凹槽最近的距离
    

    

    return 0;
}

}