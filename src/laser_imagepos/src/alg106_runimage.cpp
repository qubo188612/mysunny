#include "laser_imagepos/laser_imagepos.hpp"

#include "opencv2/opencv.hpp"
namespace laser_imagepos
{

using rcl_interfaces::msg::SetParametersResult;

void LaserImagePos::alg106_declare_parameters()
{
    this->declare_parameter("als106_exposure_time", pm.als106_exposure_time);
    this->declare_parameter("als106_pingjun", pm.als106_pingjun);
    this->declare_parameter("als106_b_yanmofuzhu", pm.als106_b_yanmofuzhu);
    this->declare_parameter("als106_b_gudingquyu", pm.als106_b_gudingquyu);
    this->declare_parameter("als106_widthliantongdis", pm.als106_widthliantongdis);
    this->declare_parameter("als106_highliantongdis", pm.als106_highliantongdis);
    this->declare_parameter("als106_gujiaerzhi", pm.als106_gujiaerzhi);
    this->declare_parameter("als106_jiguanghight", pm.als106_jiguanghight);
    this->declare_parameter("als106_jiguanglong", pm.als106_jiguanglong);
    this->declare_parameter("als106_jiguangkuandu", pm.als106_jiguangkuandu);
    this->declare_parameter("als106_b_cut", pm.als106_b_cut);
    this->declare_parameter("als106_cutleft", pm.als106_cutleft);
    this->declare_parameter("als106_cutright", pm.als106_cutright);
    this->declare_parameter("als106_cuttop", pm.als106_cuttop);
    this->declare_parameter("als106_cutdeep", pm.als106_cutdeep);
    this->declare_parameter("als106_difmin", pm.als106_difmin);
    this->declare_parameter("als106_Sidelong", pm.als106_Sidelong);
    this->declare_parameter("als106_Upback_st", pm.als106_Upback_st);
    this->declare_parameter("als106_Upback_ed", pm.als106_Upback_ed);
    this->declare_parameter("als106_Downback_st", pm.als106_Downback_st);
    this->declare_parameter("als106_Downback_ed", pm.als106_Downback_ed);
    this->declare_parameter("als106_Upmindis", pm.als106_Upmindis);
    this->declare_parameter("als106_Downmindis", pm.als106_Downmindis);
    this->declare_parameter("als106_Uplong", pm.als106_Uplong);
    this->declare_parameter("als106_Downdlong", pm.als106_Downdlong);
    this->declare_parameter("als106_dis_center_ed", pm.als106_dis_center_ed);
    this->declare_parameter("als106_duandianjuli", pm.als106_duandianjuli);
    this->declare_parameter("als106_pokoumod", pm.als106_pokoumod);
    this->declare_parameter("als106_pokouUpdif", pm.als106_pokouUpdif);
    this->declare_parameter("als106_pokouUpdifmin", pm.als106_pokouUpdifmin);
    this->declare_parameter("als106_pokouUpback_st", pm.als106_pokouUpback_st);
    this->declare_parameter("als106_pokouUpback_ed", pm.als106_pokouUpback_ed);
    this->declare_parameter("als106_pokouDowndif", pm.als106_pokouDowndif);
    this->declare_parameter("als106_pokouDowndifmin", pm.als106_pokouDowndifmin);
    this->declare_parameter("als106_pokouDownback_st", pm.als106_pokouDownback_st);
    this->declare_parameter("als106_pokouDownback_ed", pm.als106_pokouDownback_ed);
    this->declare_parameter("als106_pokouUplong", pm.als106_pokouUplong);
    this->declare_parameter("als106_pokouDownlong", pm.als106_pokouDownlong);
    this->declare_parameter("als106_b_pokouyaobian", pm.als106_b_pokouyaobian);
    this->declare_parameter("als106_pokouyaobianHsize", pm.als106_pokouyaobianHsize);
    this->declare_parameter("als106_pokouduanxianerzhi", pm.als106_pokouduanxianerzhi);
    this->declare_parameter("als106_pokousearchdectancemax", pm.als106_pokousearchdectancemax);
    this->declare_parameter("als106_pokousearchdectancemin", pm.als106_pokousearchdectancemin);
    this->declare_parameter("als106_answerpoint", pm.als106_answerpoint);
}

void LaserImagePos::alg106_update_parameters()
{
  const auto & vp = this->get_parameters(KEYS_ALS106);
  for (const auto & p : vp) {
    if (p.get_name() == "als106_exposure_time") {
      pm.als106_exposure_time = p.as_int();
    } else if (p.get_name() == "als106_pingjun") {
      pm.als106_pingjun = p.as_int();
    } else if (p.get_name() == "als106_b_yanmofuzhu") {
      pm.als106_b_yanmofuzhu = p.as_int();
    } else if (p.get_name() == "als106_b_gudingquyu") {
      pm.als106_b_gudingquyu = p.as_int();
    } else if (p.get_name() == "als106_widthliantongdis") {
      pm.als106_widthliantongdis = p.as_int();
    } else if (p.get_name() == "als106_highliantongdis") {
      pm.als106_highliantongdis = p.as_int();
    } else if (p.get_name() == "als106_gujiaerzhi") {
      pm.als106_gujiaerzhi = p.as_int();
    } else if (p.get_name() == "als106_jiguanghight") {
      pm.als106_jiguanghight = p.as_int();
    } else if (p.get_name() == "als106_jiguanglong") {
      pm.als106_jiguanglong = p.as_int();
    } else if (p.get_name() == "als106_jiguangkuandu") {
      pm.als106_jiguangkuandu = p.as_int();
    } else if (p.get_name() == "als106_b_cut") {
      pm.als106_b_cut = p.as_int();
    } else if (p.get_name() == "als106_cutleft") {
      pm.als106_cutleft = p.as_int();
    } else if (p.get_name() == "als106_cutright") {
      pm.als106_cutright = p.as_int();
    } else if (p.get_name() == "als106_cuttop") {
      pm.als106_cuttop = p.as_int();
    } else if (p.get_name() == "als106_cutdeep") {
      pm.als106_cutdeep = p.as_int();
    } else if (p.get_name() == "als106_difmin") {
      pm.als106_difmin = p.as_int();
    } else if (p.get_name() == "als106_Sidelong") {
      pm.als106_Sidelong = p.as_int();
    } else if (p.get_name() == "als106_Upback_st") {
      pm.als106_Upback_st = p.as_int();
    } else if (p.get_name() == "als106_Upback_ed") {
      pm.als106_Upback_ed = p.as_int();
    } else if (p.get_name() == "als106_Downback_st") {
      pm.als106_Downback_st = p.as_int();
    } else if (p.get_name() == "als106_Downback_ed") {
      pm.als106_Downback_ed = p.as_int();
    } else if (p.get_name() == "als106_Upmindis") {
      pm.als106_Upmindis = p.as_int();
    } else if (p.get_name() == "als106_Downmindis") {
      pm.als106_Downmindis = p.as_int();
    } else if (p.get_name() == "als106_Uplong") {
      pm.als106_Uplong = p.as_int();
    } else if (p.get_name() == "als106_Downdlong") {
      pm.als106_Downdlong = p.as_int();
    } else if (p.get_name() == "als106_dis_center_ed") {
      pm.als106_dis_center_ed = p.as_int();
    } else if (p.get_name() == "als106_duandianjuli") {
      pm.als106_duandianjuli = p.as_int();
    } else if (p.get_name() == "als106_pokoumod") {
      pm.als106_pokoumod = p.as_int();
    } else if (p.get_name() == "als106_pokouUpdif") {
      pm.als106_pokouUpdif = p.as_int();
    } else if (p.get_name() == "als106_pokouUpdifmin") {
      pm.als106_pokouUpdifmin = p.as_int();
    } else if (p.get_name() == "als106_pokouUpback_st") {
      pm.als106_pokouUpback_st = p.as_int();
    } else if (p.get_name() == "als106_pokouUpback_ed") {
      pm.als106_pokouUpback_ed = p.as_int();
    } else if (p.get_name() == "als106_pokouDowndif") {
      pm.als106_pokouDowndif = p.as_int();
    } else if (p.get_name() == "als106_pokouDowndifmin") {
      pm.als106_pokouDowndifmin = p.as_int();
    } else if (p.get_name() == "als106_pokouDownback_st") {
      pm.als106_pokouDownback_st = p.as_int();
    } else if (p.get_name() == "als106_pokouDownback_ed") {
      pm.als106_pokouDownback_ed = p.as_int();
    } else if (p.get_name() == "als106_pokouUplong") {
      pm.als106_pokouUplong = p.as_int();
    } else if (p.get_name() == "als106_pokouDownlong") {
      pm.als106_pokouDownlong = p.as_int();
    } else if (p.get_name() == "als106_b_pokouyaobian") {
      pm.als106_b_pokouyaobian = p.as_int();
    } else if (p.get_name() == "als106_pokouyaobianHsize") {
      pm.als106_pokouyaobianHsize = p.as_int();
    } else if (p.get_name() == "als106_pokouduanxianerzhi") {
      pm.als106_pokouduanxianerzhi = p.as_int();
    } else if (p.get_name() == "als106_pokousearchdectancemax") {
      pm.als106_pokousearchdectancemax = p.as_int();
    } else if (p.get_name() == "als106_pokousearchdectancemin") {
      pm.als106_pokousearchdectancemin = p.as_int();
    } else if (p.get_name() == "als106_answerpoint") {
      pm.als106_answerpoint = p.as_int();
    }   
  }
}

int LaserImagePos::alg106_getcallbackParameter(const rclcpp::Parameter &p)
{
    if (p.get_name() == "als106_exposure_time") {
        auto k = p.as_int();
        if (k <20 || k>65535) {
            return -1;}
        else{pm.als106_exposure_time=k;
            if(pm.task_num==106){
                _param_camera->set_parameters({rclcpp::Parameter("exposure_time", pm.als106_exposure_time)});}
            return 1;}}
    else if(p.get_name() == "als106_pingjun") {
        auto k = p.as_int();
        if (k <0 || k>255) {
            return -1;}
        else{pm.als106_pingjun=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_b_yanmofuzhu") {
        auto k = p.as_int();
        if (k != 0 && k!=1) {
            return -1;}
        else{pm.als106_b_yanmofuzhu=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_b_gudingquyu") {
        auto k = p.as_int();
        if (k != 0 && k!=1) {
            return -1;}
        else{pm.als106_b_gudingquyu=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_widthliantongdis") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als106_widthliantongdis=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_highliantongdis") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als106_highliantongdis=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_gujiaerzhi") {
        auto k = p.as_int();
        if (k < 0 || k > 255) {
            return -1;}
        else{pm.als106_gujiaerzhi=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_jiguanghight") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als106_jiguanghight=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_jiguanglong") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als106_jiguanglong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_jiguangkuandu") {
        auto k = p.as_int();
        if (k < 0 || k > 20) {
            return -1;}
        else{pm.als106_jiguangkuandu=p.as_int();
            return 1;}}  
    else if(p.get_name() == "als106_b_cut") {
        auto k = p.as_int();
        if (k < 0 || k > 1) {
            return -1;}
        else{pm.als106_b_cut=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_cutleft") {
        auto k = p.as_int();
        if (k < 0 || k >= 1544) {
            return -1;}
        else{pm.als106_cutleft=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_cutright") {
        auto k = p.as_int();
        if (k < 0 || k >= 1544) {
            return -1;}
        else{pm.als106_cutright=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_cuttop") {
        auto k = p.as_int();
        if (k < 0 || k >= 2064) {
            return -1;}
        else{pm.als106_cuttop=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_cutdeep") {
        auto k = p.as_int();
        if (k < 0 || k >= 2064) {
            return -1;}
        else{pm.als106_cutdeep=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_difmin") {
        auto k = p.as_int();
        if (k < 0 || k > 5000) {
            return -1;}
        else{pm.als106_difmin=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_Sidelong") {
        auto k = p.as_int();
        if (k < 0 || k > 2000) {
            return -1;}
        else{pm.als106_Sidelong=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_Upback_st") {
        auto k = p.as_int();
        if (k < 0 || k > 200) {
            return -1;}
        else{pm.als106_Upback_st=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_Upback_ed") {
        auto k = p.as_int();
        if (k < 0 || k > 200) {
            return -1;}
        else{pm.als106_Upback_ed=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_Downback_st") {
        auto k = p.as_int();
        if (k < 0 || k > 200) {
            return -1;}
        else{pm.als106_Downback_st=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_Downback_ed") {
        auto k = p.as_int();
        if (k < 0 || k > 200) {
            return -1;}
        else{pm.als106_Downback_ed=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_Upmindis") {
        auto k = p.as_int();
        if (k < 0 || k > 2000) {
            return -1;}
        else{pm.als106_Upmindis=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_Downmindis") {
        auto k = p.as_int();
        if (k < 0 || k > 2000) {
            return -1;}
        else{pm.als106_Downmindis=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_Uplong") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als106_Uplong=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_Downdlong") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als106_Downdlong=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_dis_center_ed") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als106_dis_center_ed=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_duandianjuli") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als106_duandianjuli=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_pokoumod") {
        auto k = p.as_int();
        if (k < 0 || k > 1) {
            return -1;}
        else{pm.als106_pokoumod=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_pokouUpdif") {
        auto k = p.as_int();
        if (k < 0 || k > 5000) {
            return -1;}
        else{pm.als106_pokouUpdif=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als106_pokouUpdifmin") {
        auto k = p.as_int();
        if (k < 0 || k > 5000) {
            return -1;}
        else{pm.als106_pokouUpdifmin=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_pokouUpback_st") {
        auto k = p.as_int();
        if (k < 0 || k > 200) {
            return -1;}
        else{pm.als106_pokouUpback_st=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_pokouUpback_ed") {
        auto k = p.as_int();
        if (k < 0 || k > 200) {
            return -1;}
        else{pm.als106_pokouUpback_ed=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_pokouDowndif") {
        auto k = p.as_int();
        if (k < -5000 || k > 0) {
            return -1;}
        else{pm.als106_pokouDowndif=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_pokouDowndifmin") {
        auto k = p.as_int();
        if (k < -5000 || k > 0) {
            return -1;}
        else{pm.als106_pokouDowndifmin=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_pokouDownback_st") {
        auto k = p.as_int();
        if (k < 0 || k > 200) {
            return -1;}
        else{pm.als106_pokouDownback_st=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_pokouDownback_ed") {
        auto k = p.as_int();
        if (k < 0 || k > 200) {
            return -1;}
        else{pm.als106_pokouDownback_ed=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_pokouUplong") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als106_pokouUplong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_pokouDownlong") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als106_pokouDownlong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_b_pokouyaobian") {
        auto k = p.as_int();
        if (k < 0 || k > 1) {
            return -1;}
        else{pm.als106_b_pokouyaobian=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_pokouyaobianHsize") {
        auto k = p.as_int();
        if (k < 0 || k > 200) {
            return -1;}
        else{pm.als106_pokouyaobianHsize=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_pokouduanxianerzhi") {
        auto k = p.as_int();
        if (k < 0 || k > 255) {
            return -1;}
        else{pm.als106_pokouduanxianerzhi=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_pokousearchdectancemax") {
        auto k = p.as_int();
        if (k < 0 || k > 200) {
            return -1;}
        else{pm.als106_pokousearchdectancemax=p.as_int();
            return 1;}}
    else if(p.get_name() == "als106_pokousearchdectancemin") {
        auto k = p.as_int();
        if (k < 0 || k > 200) {
            return -1;}
        else{pm.als106_pokousearchdectancemin=p.as_int();
            return 1;}}    
    else if(p.get_name() == "als106_answerpoint") {
        auto k = p.as_int();
        if (k < 0 || k > 20) {
            return -1;}
        else{pm.als106_answerpoint=p.as_int();
            return 1;}}                   
    return 0;
}

int LaserImagePos::alg106_runimage( cv::Mat &cvimgIn,
                                    std::vector <cv::Point2f> &pointcloud,
                                    std::vector <cv::Point2f> &namepoint,
                                    bool &solderjoints,
                                    int step)    //输出结果点信息
{
    Int32 i,j,t,n;
    Myhalcv2::Mat imageIn,imageGasu,imageGasupain,imageBry,m_tempmatIn,m_matMask;
    Myhalcv2::Mat m_brygujia;
    Int32 nWidth=cvimgIn.cols;	//输入图像宽
    Int32 nHeight=cvimgIn.rows;	//输入图像高
    Uint8 bryvalue;
    Int32 i32_bryvalue;

    Int16 filterdata2[40];

    Myhalcv2::L_Point32 f_center={-1,-1};
    Int32 X_Linestarty=0;
    Int32 X_Lineendy=0;
    Myhalcv2::Mat i32_mXline,m_filter2,m32_filterIma;
    Myhalcv2::L_Point32 stepfindST,stepfindED;//结果线1拟合区域,(下方)
    Myhalcv2::L_Point32 midfindST,midfindED;//结果线2拟合区域,(上方)
    Myhalcv2::L_Point32 pokoustepfindST,pokoustepfindED;//结果线1拟合区域,(下方)
    Myhalcv2::L_Point32 pokoumidfindST,pokoumidfindED;//结果线2拟合区域,(上方)
    Int32 nihenum=0;
    Int32 nstarti,nendi,nstartj,nendj;
    Myhalcv2::L_Point32 linepoint32ST,linepoint32ED;
    Myhalcv2::L_Point32 linepoint32ST2,linepoint32ED2;
    Myhalcv2::L_line tileline;	//结果线2以及原图的线,(短的)
    Myhalcv2::L_line headline;	//结果线1以及原图的线,(短的)
    Myhalcv2::L_line upline,downline;
    Myhalcv2::L_Point32 resultfocal1,resultfocal2,resultfocal;//交点
    Int32 jiguangTop,jiguangDeep,jiguangLeft,jiguangRight;
    Myhalcv2::MyConect ImageConect,ImageConectlong;
    Myhalcv2::houghlineinfo headlinehough,tilelinehough;
    cv::Point cv_point_st,cv_point_ed,cv_point;
    Myhalcv2::L_Point32F faxian,faxian1,faxian2;

    /*********************/
    //算法参数
    Int32 pingjun=pm.als106_pingjun;//15;//二值阈值
    Int32 b_yanmofuzhu=pm.als106_b_yanmofuzhu;//1;//是否使用掩摸辅助
    Int32 b_gudingquyu=pm.als106_b_gudingquyu;//0;//是否固定区域
    Int32 widthliantongdis=pm.als106_widthliantongdis;//5;//激光宽度连通距离
    Int32 highliantongdis=pm.als106_highliantongdis;//15;//激光长度连通距离
    Int32 gujiaerzhi=pm.als106_gujiaerzhi;//160;//找骨架二值图
    Int32 jiguanghight=pm.als106_jiguanghight;//50;//整体激光最短长度
    Int32 jiguanglong=pm.als106_jiguanglong;//20;//单边激光最短长度
    Int32 jiguangkuandu=pm.als106_jiguangkuandu;//6;//激光粗细
    Int32 b_cut=pm.als106_b_cut;//0;                  //是否使用搜索区域
    Int32 cutleft=pm.als106_cutleft;//0;                //搜索区域
    Int32 cutright=pm.als106_cutright;//;        //搜索区域
    Int32 cuttop=pm.als106_cuttop;                 //搜索区域
    Int32 cutdeep=pm.als106_cutdeep;        //搜索区域
    Int32 difmin=pm.als106_difmin;//150;               //坡口导数判定阈值
    Int32 Sidelong=pm.als106_Sidelong;//50;              //坡口两侧直线长度
    Int32 Upback_st=pm.als106_Upback_st;//10;             //上半段坡口统计时上端点回退距离
    Int32 Upback_ed=pm.als106_Upback_ed;//10;             //上半段坡口统计时下端点回退距离
    Int32 Downback_st=pm.als106_Downback_st;//10;             //下半段坡口统计时上端点回退距离
    Int32 Downback_ed=pm.als106_Downback_ed;//10;             //下半段坡口统计时下端点回退距离
    Int32 Upmindis=pm.als106_Upmindis;//70;              //上半段拟合最短限制长度b_cut=0时有效
    Int32 Downmindis=pm.als106_Downmindis;//70;            //下半段拟合最短限制长度b_cut=0时有效
    Int32 Uplong=pm.als106_Uplong;//50;//上半段直线长度
    Int32 Downdlong=pm.als106_Downdlong;//50;//下半段直线长度
    Int32 dis_center_ed=pm.als106_dis_center_ed;//120;  //断点向后搜索距离
    Int32 duandianjuli=pm.als106_duandianjuli;//30;    //断点向前搜索距离
    Int32 pokoumod=pm.als106_pokoumod;//0;           //坡口模式: 0打底,1盖焊
    Int32 pokouUpdif=pm.als106_pokouUpdif;//2000;           //上半段倾斜开始斜度（坡口模式=0时有效）
    Int32 pokouUpdifmin=pm.als106_pokouUpdifmin;//20;         //上半段倾斜终止斜度（坡口模式=0时有效）
    Int32 pokouUpback_st=pm.als106_pokouUpback_st;//10;          //上半段坡口统计时上端点回退距离
    Int32 pokouUpback_ed=pm.als106_pokouUpback_ed;//10;          //上半段坡口统计时上端点回退距离
    Int32 pokouDowndif=pm.als106_pokouDowndif;//-2000;           //下半段倾斜开始斜度（坡口模式=0时有效）
    Int32 pokouDowndifmin=pm.als106_pokouDowndifmin;//-20;         //下半段倾斜终止斜度（坡口模式=0时有效）
    Int32 pokouDownback_st=pm.als106_pokouDownback_st;//10;          //下半段坡口统计时上端点回退距离
    Int32 pokouDownback_ed=pm.als106_pokouDownback_ed;//10;          //下半段坡口统计时上端点回退距离
    Int32 pokouUplong=pm.als106_pokouUplong;//20;             //上坡口长度（坡口模式=0时有效）
    Int32 pokouDownlong=pm.als106_pokouDownlong;//20;             //下坡口长度（坡口模式=0时有效）
    Int32 b_pokouyaobian=pm.als106_b_pokouyaobian;//1;               //咬边检测（坡口模式=0时有效）
    Int32 pokouyaobianHsize=pm.als106_pokouyaobianHsize;//50;       //咬边高度方向检测尺寸（坡口模式=0时有效）
    Int32 pokouduanxianerzhi=pm.als106_pokouduanxianerzhi;//130;       //咬边二值（坡口模式=0时有效）
    Int32 pokousearchdectancemax=pm.als106_pokousearchdectancemax;//25;//搜寻焊缝端点距离中央凹槽最远的距离（坡口模式=0时有效）
    Int32 pokousearchdectancemin=pm.als106_pokousearchdectancemin;//15;//搜寻焊缝端点距离中央凹槽最近的距离（坡口模式=0时有效）
    Int32 answerpoint=pm.als106_answerpoint;
    
    if(step==2)
    {
        return 0;
    }
    imageIn=Myhalcv2::MatCreat(nWidth,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff_image);
    Myhalcv2::CvMatToMat(cvimgIn,&imageIn,cv8uc1_Imagebuff_image);
    imageGasu=Myhalcv2::MatCreat(nWidth,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff5);
//  Myhalcv2::Mygausspyramid_2levl(imageIn,&imageGasu);  
    Myhalcv2::Myrescale(imageIn,&imageGasu,0.125);
    if(step!=0)
    {
        imageGasupain=Myhalcv2::MatCreat(nHeight,nWidth,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff8);
    }
    if(step==3)
    {
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        return 0;
    }
    imageBry=Myhalcv2::MatCreat(nHeight>>3,nWidth>>3,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff4);
    Myhalcv2::Mynormalize(imageGasu,&imageBry);
    if(step==4)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    Myhalcv2::Mybinaryval(imageBry,&bryvalue,Myhalcv2::MHC_BARINYVAL_MEAN);
    i32_bryvalue=(Int32)bryvalue+pingjun;//求平均值二值化阈值
    Myhalcv2::Mybinary(imageBry,&imageBry,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
    if(step==5)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    if(b_yanmofuzhu==1)
    {
        m_matMask=Myhalcv2::MatCreatzero(nHeight>>3,nWidth>>3,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff1);
        Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
        Myhalcv2::Myselect_shape(&ImageConect,&ImageConectlong,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,jiguanghight,MAX(ImageConect.nHeight,ImageConect.nWidth));
        Myhalcv2::Myregion_to_bin(&ImageConectlong,&m_matMask,255);
        Myhalcv2::Mydilation_circle2(m_matMask,&m_matMask,10,0,Myhalcv2::MHC_MORPH_RECT);
    }
    m_brygujia=Myhalcv2::MatCreatzero(nHeight>>3,nWidth>>3,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    if(b_gudingquyu==1)
    {
        if(firstsearch==1)
        {
            Myhalcv2::MyCutselfRoi(&imageGasu,firstsearch_stx,firstsearch_sty,firstsearch_edx-firstsearch_stx+1,firstsearch_edy-firstsearch_sty+1);
        }
    }
    if(b_yanmofuzhu==1)
    {
        Myhalcv2::Mynormalize_lineXY_mask(imageGasu,&m_brygujia,m_matMask,5);
    }
    else
    {
        Myhalcv2::Mynormalize_lineXY(imageGasu,&m_brygujia,5);
    }
    if(step==6)
    {
        Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
        return 0;
    }
    i32_bryvalue=gujiaerzhi;
    Myhalcv2::Mybinary(m_brygujia,&m_brygujia,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
    if(step==7)
    {
        Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
        return 0;
    }
    Myhalcv2::Myintersection(imageBry,m_brygujia,&imageBry);
    if(step==8)
    {
        Myhalcv2::Mymat_to_binself(&imageBry,255);
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
    Myhalcv2::Myselect_shape(&ImageConect,&ImageConectlong,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,jiguanghight,MAX(ImageConect.nHeight,ImageConect.nWidth));
    if(ImageConectlong.AllMarkPointCount==0)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    Myhalcv2::Mysmallest_rectangle(&ImageConectlong,&jiguangLeft,&jiguangRight,&jiguangTop,&jiguangDeep);
    if(b_gudingquyu==1)
    {
        if(firstsearch==0)
        {
            firstsearch_stx=jiguangLeft-30;
            firstsearch_edx=jiguangRight+30;
            firstsearch_sty=jiguangTop-30;
            firstsearch_edy=jiguangDeep+50;
            if(firstsearch_stx<(Int32)imageGasu.startx)
            {
                firstsearch_stx=imageGasu.startx;
            }
            if(firstsearch_edx>(Int32)imageGasu.startx+imageGasu.width-1)
            {
                firstsearch_edx=imageGasu.startx+imageGasu.width-1;
            }
            if(firstsearch_sty<(Int32)imageGasu.starty)
            {
                firstsearch_sty=imageGasu.starty;
            }
            if(firstsearch_edy>(Int32)imageGasu.starty+imageGasu.height-1)
            {
                firstsearch_edy=imageGasu.starty+imageGasu.height-1;
            }
            firstsearch=1;
        }
        else
        {
            Int32 realstx,realsty,realedx,realedy;
            realstx=firstsearch_stx;
            realsty=firstsearch_sty;
            realedx=firstsearch_edx;
            realedy=firstsearch_edy;
            if(jiguangLeft>firstsearch_stx&&jiguangLeft<firstsearch_edx)
            {
                realstx=jiguangLeft;
            }
            if(jiguangRight>firstsearch_stx&&jiguangRight<firstsearch_edx)
            {
                realedx=jiguangRight;
            }
            if(jiguangTop>firstsearch_sty&&jiguangTop<firstsearch_edy)
            {
                realsty=jiguangTop;
            }
            if(jiguangDeep>firstsearch_sty&&jiguangDeep<firstsearch_edy)
            {
                realedy=jiguangDeep;
            }
            jiguangLeft=realstx;
            jiguangRight=realedx;
            jiguangTop=realsty;
            jiguangDeep=realedy;
        }
    }
    Myhalcv2::MyCutRoi(imageGasu,&m_tempmatIn,Myhalcv2::MHC_CUT_NOTCOPY,jiguangLeft,jiguangTop,jiguangRight-jiguangLeft+1,jiguangDeep-jiguangTop+1);
    Myhalcv2::Mynormalize_lineXY(m_tempmatIn,&imageBry,1);
    if(step==9)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    i32_bryvalue=gujiaerzhi;//求平均值二值化阈值
    Myhalcv2::Mybinary(imageBry,&imageBry,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
    if(step==10)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
    Myhalcv2::Myselect_shape(&ImageConect,&ImageConectlong,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,jiguanglong,MAX(ImageConect.nHeight,ImageConect.nWidth));//在ImageConect中筛选出高度大于50的联通域
    if(ImageConectlong.AllMarkPointCount==0)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    Myhalcv2::MyGetthinNoHough(&ImageConectlong,Myhalcv2::THIN_X,jiguangkuandu,&imageBry);
    if(step==11)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    Myhalcv2::Mydeleteconnection(imageBry,&imageBry,jiguanghight,highliantongdis,Myhalcv2::MHC_8LT);
    if(step==12)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    /***********************/
    //以下的图像几乎都是完美图像,需要检测出结果
    //以下对高斯图做卷积
    memset(X_line,0,sizeof(Int32)*nHeight);
    memset(X_lineMark,0,nHeight);

    X_Linestarty=0;
    X_Lineendy=0;

    if(step==13)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
    }
    //膨胀做
    Myhalcv2::Mydilation_circle2(imageBry,&imageBry,2,0,Myhalcv2::MHC_MORPH_RECT);
    Myhalcv2::MyCutRoi(imageIn,&m_tempmatIn,Myhalcv2::MHC_CUT_NOTCOPY,jiguangLeft*8,jiguangTop*8,jiguangRight*8-jiguangLeft*8+1,jiguangDeep*8-jiguangTop*8+1);
    for(j=m_tempmatIn.starty;j<m_tempmatIn.starty+m_tempmatIn.height;j++)
    {
        Int32 sum_valuecoor=0;
        Int32 sum_value=0;

        for(i=m_tempmatIn.startx;i<m_tempmatIn.startx+m_tempmatIn.width;i++)
        {
            Int32 di=i>>3;
            Int32 dj=j>>3;
            if(imageBry.data[dj*imageBry.nWidth+di]!=0)
            {
                sum_valuecoor=sum_valuecoor+(Int32)m_tempmatIn.data[j*m_tempmatIn.nWidth+i]*i;
                sum_value=sum_value+m_tempmatIn.data[j*m_tempmatIn.nWidth+i];
            }
        }
        if(sum_value!=0)
        {
            float p=(float)sum_valuecoor/sum_value;
            X_line[j]=p+0.5;
            if(X_Linestarty==0)
            {
                X_Linestarty=j;//骨架起点
            }
            X_Lineendy=j;//骨架终点
            X_lineMark[j]=1;

            cv::Point2f point(p,j);
            pointcloud.push_back(point);
        }
        if(step==13)
        {
            if(sum_value!=0)
            {
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data1=255;
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data2=0;
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data3=0;
            }
        }
    }
    if(step==13)
    {
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    if(X_Lineendy-X_Linestarty<50)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    Myhalcv2::Myfixdata(X_line,X_lineMark,nHeight);//修复空的线
    if(step==14)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
        for(j=m_tempmatIn.starty;j<m_tempmatIn.starty+m_tempmatIn.height;j++)
        {
            imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data1=255;
            imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data2=0;
            imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data3=0;
        }
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }

    i32_mXline=Myhalcv2::MatCreat(1,nHeight,Myhalcv2::CCV_32SC1,X_line);//把线横摆
    for(i=0;i<20;i++)
    {
        filterdata2[i]=1;
    }
    for(i=20;i<40;i++)
    {
        filterdata2[i]=-1;
    }
    m_filter2=Myhalcv2::MatCreat(1,40,Myhalcv2::CCV_16SC1,filterdata2);
    m32_filterIma=Myhalcv2::MatCreatzero(1,nHeight,Myhalcv2::CCV_32SC1,X_linedif32);
    Myhalcv2::Myfilter(i32_mXline,m_filter2,&m32_filterIma,Myhalcv2::CCV_32SC1,0,f_center);//卷积得到

    if(b_cut==0)
    {
        nstartj=X_Linestarty+24;
        nendj=X_Lineendy-24;
    }
    else
    {
        nstartj=MAX(X_Linestarty+24,cuttop);
        nendj=MIN(X_Lineendy-24,cutdeep);
    }

    m_brygujia=Myhalcv2::MatCreatzero(3,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);  //创建上半截连通图
    for(j=nstartj;j<=nendj;j++)
    {
        if(abs(m32_filterIma.ptr_int[j])<difmin)
        {
            m_brygujia.data[1*m_brygujia.nWidth+j]=255;
        }
    }
    if(step==15)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
        for(j=nstartj;j<=nendj;j++)
        {
            if( m_brygujia.data[1*m_brygujia.nWidth+j]!=0)
            {
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data1=255;
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data2=0;
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data3=0;
            }
        }
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    Myhalcv2::Myconnection(m_brygujia,&ImageConect,Sidelong,0,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
    if(ImageConect.AllMarkPointCount<2)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    Myhalcv2::Mysort_region(&ImageConect,&ImageConectlong,Myhalcv2::MHC_LEFT_LEFTTORIGHT_PAIXU);
    //创建上半截连通图
    m_brygujia=Myhalcv2::MatCreatzero(3,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    if(b_cut==1)
    {
        stepfindST.y=ImageConectlong.AllMarkPoint[0].left;
        stepfindST.x=X_line[stepfindST.y];
        stepfindED.y=ImageConectlong.AllMarkPoint[0].right;
        stepfindED.x=X_line[stepfindED.y];
        if(stepfindST.x<cutleft||stepfindST.x>cutright||stepfindED.x<cutleft||stepfindED.x>cutright)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        for(i=0;i<ImageConectlong.AllMarkPoint[0].PointArea;i++)
        {
            m_brygujia.data[ImageConectlong.AllMarkPoint[0].point[i].y*m_brygujia.nWidth+ImageConectlong.AllMarkPoint[0].point[i].x]=255;
        }
    }
    else
    {
        int have=0;
        Int32 centj=MIN(X_Lineendy-24,X_Linestarty+24+Upmindis);
        for(j=0;j<ImageConectlong.AllMarkPointCount;j++)
        {
            if(centj<ImageConectlong.AllMarkPoint[j].right)
            {
                stepfindST.y=ImageConectlong.AllMarkPoint[j].left;
                stepfindST.x=X_line[stepfindST.y];
                stepfindED.y=ImageConectlong.AllMarkPoint[j].right;
                stepfindED.x=X_line[stepfindED.y];
                for(i=0;i<ImageConectlong.AllMarkPoint[j].PointArea;i++)
                {
                    m_brygujia.data[ImageConectlong.AllMarkPoint[j].point[i].y*m_brygujia.nWidth+ImageConectlong.AllMarkPoint[j].point[i].x]=255;
                }
                have=1;
                break;
            }
        }
        if(have==0)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
    }
    if(step==16)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
        for(j=nstartj;j<=nendj;j++)
        {
            if( m_brygujia.data[1*m_brygujia.nWidth+j]!=0)
            {
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data1=255;
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data2=0;
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data3=0;
            }
        }
        linepoint32ST.y=MIN(X_Lineendy-24,X_Linestarty+24+Upmindis);
        linepoint32ST.x=X_line[MIN(X_Lineendy-24,X_Linestarty+24+Upmindis)];
        linepoint32ST.x=(linepoint32ST.x>>3);
        linepoint32ST.y=(linepoint32ST.y>>3);
        Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    stepfindST.y=MIN(stepfindST.y+Upback_st,stepfindED.y);
    stepfindED.y=MAX(stepfindST.y,stepfindED.y-Upback_ed);
    stepfindST.x=X_line[stepfindST.y];
    stepfindED.x=X_line[stepfindED.y];
    nihenum=0;
    for(j=stepfindST.y;j<=stepfindED.y;j++)
    {
        if(m_brygujia.data[1*m_brygujia.nWidth+j]!=0)
        {
            niheX[nihenum]=X_line[j];
            niheY[nihenum++]=j;
        }
    }
    if(nihenum<Uplong)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,nWidth,nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&headline,&headlinehough);
    if(step==17)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
        for(j=stepfindST.y;j<=stepfindED.y;j++)
        {
            if(m_brygujia.data[1*m_brygujia.nWidth+j]!=0)
            {
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data1=255;
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data2=0;
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data3=0;
            }
        }
        linepoint32ST.x=(stepfindST.x>>3);
        linepoint32ST.y=(stepfindST.y>>3);
        linepoint32ED.x=(stepfindED.x>>3);
        linepoint32ED.y=(stepfindED.y>>3);
        Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ED,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyPoint16to32(headline.st,&linepoint32ST);
        Myhalcv2::MyPoint16to32(headline.ed,&linepoint32ED);
        linepoint32ST.x=(linepoint32ST.x>>3);
        linepoint32ST.y=(linepoint32ST.y>>3);
        linepoint32ED.x=(linepoint32ED.x>>3);
        linepoint32ED.y=(linepoint32ED.y>>3);
        Myhalcv2::MyLine3col(&imageGasupain,linepoint32ST,linepoint32ED,0,0,255,Myhalcv2::CV_LINE_8LT,1);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    //创建下半截连通图
    m_brygujia=Myhalcv2::MatCreatzero(3,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    if(b_cut==1)
    {
        midfindST.y=ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-1].left;
        midfindST.x=X_line[midfindST.y];
        midfindED.y=ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-1].right;
        midfindED.x=X_line[midfindED.y];
        if(midfindST.x<cutleft||midfindST.x>cutright||midfindED.x<cutleft||midfindED.x>cutright)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        for(i=0;i<ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-1].PointArea;i++)
        {
            m_brygujia.data[ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-1].point[i].y*m_brygujia.nWidth+ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-1].point[i].x]=255;
        }
    }
    else
    {
        int have=0;
        Int32 centj=MAX(X_Linestarty+24,X_Lineendy-24-Downmindis);
        for(j=ImageConectlong.AllMarkPointCount-1;j>=0;j--)
        {
            if(centj>ImageConectlong.AllMarkPoint[j].left)
            {
                midfindST.y=ImageConectlong.AllMarkPoint[j].left;
                midfindST.x=X_line[midfindST.y];
                midfindED.y=ImageConectlong.AllMarkPoint[j].right;
                midfindED.x=X_line[midfindED.y];
                for(i=0;i<ImageConectlong.AllMarkPoint[j].PointArea;i++)
                {
                    m_brygujia.data[ImageConectlong.AllMarkPoint[j].point[i].y*m_brygujia.nWidth+ImageConectlong.AllMarkPoint[j].point[i].x]=255;
                }
                have=1;
                break;
            }
        }
        if(have==0)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
    }
    if(step==18)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
        for(j=nstartj;j<=nendj;j++)
        {
            if( m_brygujia.data[1*m_brygujia.nWidth+j]!=0)
            {
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data1=255;
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data2=0;
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data3=0;
            }
        }
        linepoint32ED.y=MAX(X_Linestarty+24,X_Lineendy-24-Downmindis);
        linepoint32ED.x=X_line[MAX(X_Linestarty+24,X_Lineendy-24-Downmindis)];
        linepoint32ED.x=(linepoint32ED.x>>3);
        linepoint32ED.y=(linepoint32ED.y>>3);
        Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ED,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    midfindST.y=MIN(midfindST.y+Downback_st,midfindED.y);
    midfindED.y=MAX(midfindST.y,midfindED.y-Downback_ed);
    midfindST.x=X_line[midfindST.y];
    midfindED.x=X_line[midfindED.y];
    nihenum=0;
    for(j=midfindST.y;j<=midfindED.y;j++)
    {
        if(m_brygujia.data[1*m_brygujia.nWidth+j]!=0)
        {
            niheX[nihenum]=X_line[j];
            niheY[nihenum++]=j;
        }
    }
    if(nihenum<Downdlong)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,nWidth,nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&tileline,&tilelinehough);
    if(step==19)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
        for(j=nstartj;j<=nendj;j++)
        {
            if( m_brygujia.data[1*m_brygujia.nWidth+j]!=0)
            {
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data1=255;
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data2=0;
                imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data3=0;
            }
        }
        linepoint32ST.x=(midfindST.x>>3);
        linepoint32ST.y=(midfindST.y>>3);
        linepoint32ED.x=(midfindED.x>>3);
        linepoint32ED.y=(midfindED.y>>3);
        Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ED,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyPoint16to32(tileline.st,&linepoint32ST);
        Myhalcv2::MyPoint16to32(tileline.ed,&linepoint32ED);
        linepoint32ST.x=(linepoint32ST.x>>3);
        linepoint32ST.y=(linepoint32ST.y>>3);
        linepoint32ED.x=(linepoint32ED.x>>3);
        linepoint32ED.y=(linepoint32ED.y>>3);
        Myhalcv2::MyLine3col(&imageGasupain,linepoint32ST,linepoint32ED,0,0,255,Myhalcv2::CV_LINE_8LT,1);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    if(midfindST.y<stepfindED.y)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }

    //找上半段端点
    nstartj=MAX(stepfindST.y,stepfindED.y-dis_center_ed);
    nendj=MIN(midfindST.y,stepfindED.y+duandianjuli);
    nstarti=MAX((jiguangLeft<<3)-30,0);
    nendi=MIN((jiguangRight<<3)+30,nWidth-1);
    if(nendj-nstartj<Uplong)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    m_brygujia=Myhalcv2::MatCreatzero(nendj-nstartj+1,nendi-nstarti+1,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    imageBry=Myhalcv2::MatCreatzero(nendj-nstartj+1,nendi-nstarti+1,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff4);
    if(0!=Myhalcv2::MyGetLineXpos(headline,nstartj,&linepoint32ST.x))
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    linepoint32ST.y=nstartj;
    if(0!=Myhalcv2::MyGetLineXpos(headline,nendj,&linepoint32ED.x))
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    linepoint32ED.y=nendj;
    linepoint32ST.x=linepoint32ST.x-nstarti;
    linepoint32ST.y=linepoint32ST.y-nstartj;
    linepoint32ED.x=linepoint32ED.x-nstarti;
    linepoint32ED.y=linepoint32ED.y-nstartj;
    Myhalcv2::MyLine(&m_brygujia,linepoint32ST,linepoint32ED,255,Myhalcv2::CV_LINE_8LT,5);
    for(j=nstartj;j<=nendj;j++)
    {
        if(m_brygujia.data[(j-nstartj)*m_brygujia.nWidth+X_line[j]-nstarti]!=0)
        {
            imageBry.data[(j-nstartj)*imageBry.nWidth+X_line[j]-nstarti]=255;
        }
    }
    if(step==20)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    Myhalcv2::Myconnection(imageBry,&ImageConect,Uplong,1,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
    if(ImageConect.AllMarkPointCount!=1)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    resultfocal1.y=ImageConect.AllMarkPoint[0].bottom+nstartj;
    if(0!=MyGetLineXpos(headline,resultfocal1.y,&resultfocal1.x))
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    if(step==21)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
        linepoint32ST.x=(resultfocal1.x>>3);
        linepoint32ST.y=(resultfocal1.y>>3);
        Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,255,0,0,Myhalcv2::CV_CLRCLE_UNFILL);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }

    //找下半段端点
    nendj=MIN(midfindED.y,midfindST.y+dis_center_ed);
    nstartj=MAX(stepfindED.y,midfindST.y-duandianjuli);
    nstarti=MAX((jiguangLeft<<3)-30,0);
    nendi=MIN((jiguangRight<<3)+30,nWidth-1);

    if(nendj-nstartj<Downdlong)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    m_brygujia=Myhalcv2::MatCreatzero(nendj-nstartj+1,nendi-nstarti+1,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    imageBry=Myhalcv2::MatCreatzero(nendj-nstartj+1,nendi-nstarti+1,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff4);
    if(0!=Myhalcv2::MyGetLineXpos(tileline,nstartj,&linepoint32ST.x))
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    linepoint32ST.y=nstartj;
    if(0!=Myhalcv2::MyGetLineXpos(tileline,nendj,&linepoint32ED.x))
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    linepoint32ED.y=nendj;
    linepoint32ST.x=linepoint32ST.x-nstarti;
    linepoint32ST.y=linepoint32ST.y-nstartj;
    linepoint32ED.x=linepoint32ED.x-nstarti;
    linepoint32ED.y=linepoint32ED.y-nstartj;
    Myhalcv2::MyLine(&m_brygujia,linepoint32ST,linepoint32ED,255,Myhalcv2::CV_LINE_8LT,5);
    for(j=nstartj;j<=nendj;j++)
    {
        if(m_brygujia.data[(j-nstartj)*m_brygujia.nWidth+X_line[j]-nstarti]!=0)
        {
            imageBry.data[(j-nstartj)*imageBry.nWidth+X_line[j]-nstarti]=255;
        }
    }
    if(step==22)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }

    Myhalcv2::Myconnection(imageBry,&ImageConect,Downdlong,1,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
    if(ImageConect.AllMarkPointCount!=1)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    resultfocal2.y=ImageConect.AllMarkPoint[0].top+nstartj;
    if(0!=MyGetLineXpos(tileline,resultfocal2.y,&resultfocal2.x))
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    if(step==23)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
        linepoint32ED.x=(resultfocal2.x>>3);
        linepoint32ED.y=(resultfocal2.y>>3);
        Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ED,4,255,0,0,Myhalcv2::CV_CLRCLE_UNFILL);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    //法线垂直于坡口上表面
    Myhalcv2::MyGetLinefocalRight(resultfocal1,resultfocal2,&faxian);


    if(pokoumod==0) //打底,求坡底焊缝
    {
        Int32 center=(resultfocal1.y+resultfocal2.y)>>1;
        if(center-resultfocal1.y<pokouUplong)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        m_brygujia=Myhalcv2::MatCreatzero(3,center-resultfocal1.y+1,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
        for(j=resultfocal1.y;j<center;j++)
        {
            if(m32_filterIma.ptr_int[j]>=pokouUpdifmin&&m32_filterIma.ptr_int[j]<=pokouUpdif)
            {
                m_brygujia.data[1*m_brygujia.nWidth+j-resultfocal1.y]=255;
            }
        }
        if(step==24)
        {
            Myhalcv2::MatClone(imageGasu,&imageGasupain);
            Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
            for(j=resultfocal1.y;j<center;j++)
            {
                if( m_brygujia.data[1*m_brygujia.nWidth+j-resultfocal1.y]!=0)
                {
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data1=255;
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data2=0;
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data3=0;
                }
            }
            Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
            return 0;
        }
        Myhalcv2::Myconnection(m_brygujia,&ImageConect,pokouUplong,0,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
        Myhalcv2::Mysort_region(&ImageConect,&ImageConectlong,Myhalcv2::MHC_WIDTH_PAIXU);
        if(ImageConectlong.AllMarkPointCount==0)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        pokoustepfindST.y=ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-1].left+resultfocal1.y;
        pokoustepfindED.y=ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-1].right+resultfocal1.y;
        pokoustepfindST.y=MIN(pokoustepfindST.y+pokouUpback_st,center-1);
        pokoustepfindST.x=X_line[pokoustepfindST.y];
        pokoustepfindED.y=MAX(pokoustepfindST.y,pokoustepfindED.y-pokouUpback_ed);
        pokoustepfindED.x=X_line[pokoustepfindED.y];
        if(step==25)
        {
            Myhalcv2::MatClone(imageGasu,&imageGasupain);
            Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
            linepoint32ST.x=(pokoustepfindST.x>>3);
            linepoint32ST.y=(pokoustepfindST.y>>3);
            linepoint32ED.x=(pokoustepfindED.x>>3);
            linepoint32ED.y=(pokoustepfindED.y>>3);
            Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
            Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ED,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
            for(j=resultfocal1.y;j<center;j++)
            {
                if( m_brygujia.data[1*m_brygujia.nWidth+j-resultfocal1.y]!=0)
                {
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data1=255;
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data2=0;
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data3=0;
                }
            }
            Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
            return 0;
        }
        nihenum=0;
        for(j=pokoustepfindST.y;j<=pokoustepfindED.y;j++)
        {
            if(m_brygujia.data[1*m_brygujia.nWidth+j-resultfocal1.y]!=0)
            {
                niheX[nihenum]=X_line[j];
                niheY[nihenum++]=j;
            }
        }
        if(nihenum<pokouUplong)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,nWidth,nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&upline,&headlinehough);
        if(step==26)
        {
            Myhalcv2::MatClone(imageGasu,&imageGasupain);
            Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
            linepoint32ST.x=(pokoustepfindST.x>>3);
            linepoint32ST.y=(pokoustepfindST.y>>3);
            linepoint32ED.x=(pokoustepfindED.x>>3);
            linepoint32ED.y=(pokoustepfindED.y>>3);
            Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
            Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ED,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
            for(j=pokoustepfindST.y;j<=pokoustepfindED.y;j++)
            {
                if( m_brygujia.data[1*m_brygujia.nWidth+j-resultfocal1.y]!=0)
                {
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data1=255;
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data2=0;
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data3=0;
                }
            }
            Myhalcv2::MyPoint16to32(upline.st,&linepoint32ST);
            Myhalcv2::MyPoint16to32(upline.ed,&linepoint32ED);
            linepoint32ST.x=(linepoint32ST.x>>3);
            linepoint32ST.y=(linepoint32ST.y>>3);
            linepoint32ED.x=(linepoint32ED.x>>3);
            linepoint32ED.y=(linepoint32ED.y>>3);
            Myhalcv2::MyLine3col(&imageGasupain,linepoint32ST,linepoint32ED,0,0,255,Myhalcv2::CV_LINE_8LT,1);
            Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
            return 0;
        }
        if(resultfocal2.y-center<pokouDownlong)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        m_brygujia=Myhalcv2::MatCreatzero(3,resultfocal2.y-center+1,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
        for(j=center+1;j<=resultfocal2.y;j++)
        {
            if(m32_filterIma.ptr_int[j]<=pokouDowndifmin&&m32_filterIma.ptr_int[j]>=pokouDowndif)
            {
                m_brygujia.data[1*m_brygujia.nWidth+j-(center+1)]=255;
            }
        }
        if(step==27)
        {
            Myhalcv2::MatClone(imageGasu,&imageGasupain);
            Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
            for(j=center+1;j<=resultfocal2.y;j++)
            {
                if( m_brygujia.data[1*m_brygujia.nWidth+j-(center+1)]!=0)
                {
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data1=255;
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data2=0;
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data3=0;
                }
            }
            Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
            return 0;
        }
        Myhalcv2::Myconnection(m_brygujia,&ImageConect,pokouDownlong,0,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
        Myhalcv2::Mysort_region(&ImageConect,&ImageConectlong,Myhalcv2::MHC_WIDTH_PAIXU);
        if(ImageConectlong.AllMarkPointCount==0)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        pokoumidfindST.y=ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-1].left+center+1;
        pokoumidfindED.y=ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-1].right+center+1;
        pokoumidfindST.y=MIN(pokoumidfindST.y+pokouDownback_st,pokoumidfindED.y);
        pokoumidfindST.x=X_line[pokoumidfindST.y];   
        pokoumidfindED.y=MAX(pokoumidfindST.y,pokoumidfindED.y-pokouDownback_ed);
        pokoumidfindED.x=X_line[pokoumidfindED.y];
        if(step==28)
        {
            Myhalcv2::MatClone(imageGasu,&imageGasupain);
            Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
            linepoint32ST.x=(pokoumidfindST.x>>3);
            linepoint32ST.y=(pokoumidfindST.y>>3);
            linepoint32ED.x=(pokoumidfindED.x>>3);
            linepoint32ED.y=(pokoumidfindED.y>>3);
            Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
            Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ED,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
            for(j=center+1;j<=resultfocal2.y;j++)
            {
                if( m_brygujia.data[1*m_brygujia.nWidth+j-(center+1)]!=0)
                {
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data1=255;
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data2=0;
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data3=0;
                }
            }
            Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
            return 0;
        }
        nihenum=0;
        for(j=pokoumidfindST.y;j<=pokoumidfindED.y;j++)
        {
            if(m_brygujia.data[1*m_brygujia.nWidth+j-(center+1)]!=0)
            {
                niheX[nihenum]=X_line[j];
                niheY[nihenum++]=j;
            }
        }
        if(nihenum<pokouUplong)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,nWidth,nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&downline,&tilelinehough);
        if(step==29)
        {
            Myhalcv2::MatClone(imageGasu,&imageGasupain);
            Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
            linepoint32ST.x=(pokoumidfindST.x>>3);
            linepoint32ST.y=(pokoumidfindST.y>>3);
            linepoint32ED.x=(pokoumidfindED.x>>3);
            linepoint32ED.y=(pokoumidfindED.y>>3);
            Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
            Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ED,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
            for(j=pokoumidfindST.y;j<=pokoumidfindED.y;j++)
            {
                if( m_brygujia.data[1*m_brygujia.nWidth+j-(center+1)]!=0)
                {
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data1=255;
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data2=0;
                    imageGasupain.ptr_Vec3b[(j>>3)*imageGasupain.nWidth+(X_line[j]>>3)].data3=0;
                }
            }
            Myhalcv2::MyPoint16to32(downline.st,&linepoint32ST);
            Myhalcv2::MyPoint16to32(downline.ed,&linepoint32ED);
            linepoint32ST.x=(linepoint32ST.x>>3);
            linepoint32ST.y=(linepoint32ST.y>>3);
            linepoint32ED.x=(linepoint32ED.x>>3);
            linepoint32ED.y=(linepoint32ED.y>>3);
            Myhalcv2::MyLine3col(&imageGasupain,linepoint32ST,linepoint32ED,0,0,255,Myhalcv2::CV_LINE_8LT,1);
            Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
            return 0;
        }
        
        //求得两直线交点
        if(0!=MyGetLinefocal(upline,downline,&resultfocal))
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        if(resultfocal.x<0||resultfocal.x>=nWidth||resultfocal.y<0||resultfocal.y>nHeight)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;    
        }
        if(resultfocal.y<resultfocal1.y||resultfocal.y>resultfocal2.y)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        if(headlinehough.theta<(MHC_TETARANGE>>3)||tilelinehough.theta>(MHC_TETARANGE>>3))
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        if(b_pokouyaobian==1)
        {
            Int32 upx1,upx2,downx1,downx2;
            Int32 upxl,upxr,downxl,downxr;
            nstartj=MAX(0,resultfocal.y-pokouyaobianHsize);
            nendj=MIN(nHeight,resultfocal.y+pokouyaobianHsize);
            Myhalcv2::MyGetLineXpos(upline,nstartj,&upx1);
            Myhalcv2::MyGetLineXpos(downline,nstartj,&upx2);
            upxl=MIN(upx1,upx2);
            upxl=MAX(0,upxl-30);
            upxl=MIN(nWidth-1,upxl);
            upxr=MAX(upx1,upx2);
            upxr=MIN(nWidth-1,upxr+30);
            upxr=MAX(0,upxr);
            if(upxr<=upxl)
            {
            #ifdef QUICK_TRANSMIT
                Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
                if(b_cut==1)
                {
                    cv::Point p1(cutleft>>3,cuttop>>3);
                    cv::Point p2(cutright>>3,cutdeep>>3);
                    cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
                }
            #endif
                return 1;
            }
            Myhalcv2::MyGetLineXpos(upline,nendj,&downx1);
            Myhalcv2::MyGetLineXpos(downline,nendj,&downx2);
            downxl=MIN(downx1,downx2);
            downxl=MAX(0,downxl-30);
            downxl=MIN(nWidth-1,downxl);
            downxr=MAX(downx1,downx2);
            downxr=MIN(nWidth-1,downxr+30);
            downxr=MAX(0,downxr);
            if(downxr<=downxl)
            {
            #ifdef QUICK_TRANSMIT
                Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
                if(b_cut==1)
                {
                    cv::Point p1(cutleft>>3,cuttop>>3);
                    cv::Point p2(cutright>>3,cutdeep>>3);
                    cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
                }
            #endif
                return 1;
            }
            nstarti=MIN(upxl,downxl);
            nendi=MAX(upxr,upxl);
            Myhalcv2::MyCutminRoi(imageIn,&imageBry,Myhalcv2::MHC_CUTMIN_1,nstarti,nstartj,nendi-nstarti+1,nendj-nstartj+1);
            m_brygujia=Myhalcv2::MatCreatzero(imageBry.nHeight,imageBry.nWidth,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
            linepoint32ST.x=upx1-nstarti;
            linepoint32ST.y=0;
            linepoint32ED.x=downx1-nstarti;
            linepoint32ED.y=imageBry.nHeight-1;
            Myhalcv2::MyLine(&m_brygujia,linepoint32ST,linepoint32ED,255,Myhalcv2::CV_LINE_8LT,30);
            linepoint32ST2.x=upx2-nstarti;
            linepoint32ST2.y=0;
            linepoint32ED2.x=downx2-nstarti;
            linepoint32ED2.y=imageBry.nHeight-1;
            Myhalcv2::MyLine(&m_brygujia,linepoint32ST2,linepoint32ED2,255,Myhalcv2::CV_LINE_8LT,30);
            Myhalcv2::Mynormalize_lineXY_mask(imageBry,&imageBry,m_brygujia,1);
            if(step==30)
            {
                Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
                return 0;
            }
            Myhalcv2::Mybinary(imageBry,&m_brygujia,Myhalcv2::MHC_BARINY_VALUE_IMG,255,pokouduanxianerzhi,0);
            if(step==31)
            {
                Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
                return 0;
            }
            Myhalcv2::Mydeleteconnection(m_brygujia,&m_brygujia,50,0,Myhalcv2::MHC_8LT);
            Myhalcv2::Mydilation_circle2(m_brygujia,&m_brygujia,0,4,Myhalcv2::MHC_MORPH_RECT);
            if(step==32)
            {
                Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
                return 0;
            }
            Myhalcv2::Myconnection(m_brygujia,&ImageConect,50,0,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
            Myhalcv2::Myregion_to_label(&ImageConect,&imageBry);
            if(imageBry.data[(resultfocal.y-nstartj)*imageBry.nWidth+(resultfocal.x-nstarti)]!=0)//说明有交点，且不是焊点
            {
                Int32 leijiwrite;
                Uint8 color=imageBry.data[(resultfocal.y-nstartj)*imageBry.nWidth+(resultfocal.x-nstarti)];
                Uint8 upfind=0,downfind=0;
                Myhalcv2::L_Point32 upfindpoint,downfindpoint;
                //检测上边
                leijiwrite=0;
                Myhalcv2::MyLinetoPoint(imageBry.nHeight,imageBry.nWidth,linepoint32ED,linepoint32ST,Myhalcv2::CV_LINE_8LT,1,&ImageConect,cv8uc1_Imagebuff3);
                for(t=0;t<ImageConect.AllMarkPoint[0].PointArea;t++)
                {
                    Int32 i=ImageConect.AllMarkPoint[0].point[t].x;
                    Int32 j=ImageConect.AllMarkPoint[0].point[t].y;
                    if(j<=resultfocal.y-nstartj)
                    {
                        if(imageBry.data[j*imageBry.nWidth+i]==0)
                        {
                            upfindpoint.y=j;
                            upfindpoint.x=i;
                            upfind=1;
                        }
                        if(imageBry.data[j*imageBry.nWidth+i]!=0)
                            leijiwrite++;
                    }
                    if(j<=resultfocal.y-nstartj-pokousearchdectancemax||leijiwrite>=pokousearchdectancemin)
                    {
                        break;
                    }
                }

                //检测下边
                leijiwrite=0;
                Myhalcv2::MyLinetoPoint(imageBry.nHeight,imageBry.nWidth,linepoint32ST2,linepoint32ED2,Myhalcv2::CV_LINE_8LT,1,&ImageConect,cv8uc1_Imagebuff3);
                for(t=0;t<ImageConect.AllMarkPoint[0].PointArea;t++)
                {
                    Int32 i=ImageConect.AllMarkPoint[0].point[t].x;
                    Int32 j=ImageConect.AllMarkPoint[0].point[t].y;
                    if(j>=resultfocal.y-nstartj)
                    {
                        if(imageBry.data[j*imageBry.nWidth+i]==0/*&&imageBry.data[j*imageBry.nWidth+i]!=color*/)
                        {
                            downfindpoint.y=j;
                            downfindpoint.x=i;
                            downfind=1;
                        }
                        if(imageBry.data[j*imageBry.nWidth+i]!=0)
                            leijiwrite++;
                    }
                    if(j<=resultfocal.y-nstartj-pokousearchdectancemax||leijiwrite>=pokousearchdectancemin)
                    {
                        break;
                    }
                }
                if(upfind==1&&downfind==0)
                {
                    MyGetLineXpos(downline,upfindpoint.y+nstartj,&resultfocal.x);
                    resultfocal.y=upfindpoint.y+nstartj;
                }
                else if(upfind==0&&downfind==1)
                {
                    MyGetLineXpos(upline,downfindpoint.y+nstartj,&resultfocal.x);
                    resultfocal.y=downfindpoint.y+nstartj;
                }
                solderjoints=false;
            }
            else if(imageBry.data[(resultfocal.y-nstartj)*imageBry.nWidth+(resultfocal.x-nstarti)]==0
                &&ImageConect.AllMarkPointCount==1)
            {
                solderjoints=true;
            }
            else
            {
                solderjoints=false;
            }
        }
        faxian1=faxian;
        faxian2=faxian;

        if(answerpoint==2)
        {
            Myhalcv2::L_Point32F f_temp;
            Myhalcv2::L_Point32 p_temp;
            f_temp=faxian;
            faxian=faxian1;
            faxian1=f_temp;
            p_temp=resultfocal;
            resultfocal=resultfocal1;
            resultfocal1=p_temp;
        }
        else if(answerpoint==3)
        {
            Myhalcv2::L_Point32F f_temp;
            Myhalcv2::L_Point32 p_temp;
            f_temp=faxian;
            faxian=faxian2;
            faxian2=f_temp;
            p_temp=resultfocal;
            resultfocal=resultfocal2;
            resultfocal2=p_temp;
        }
        if(step==1)
        {
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(cvimgIn.type()==CV_8UC1)
                cv::cvtColor(cvimgIn,cvimgIn,cv::COLOR_GRAY2BGR);
            cv_point_st.x=(resultfocal1.x>>3);
            cv_point_st.y=(resultfocal1.y>>3);
            cv::circle(cvimgIn,cv_point_st,5,cv::Scalar(0,0,255),1);
            cv_point_ed.x=(resultfocal2.x>>3);
            cv_point_ed.y=(resultfocal2.y>>3);
            cv::circle(cvimgIn,cv_point_ed,5,cv::Scalar(0,255,0),1);
            cv_point.x=(resultfocal.x>>3);
            cv_point.y=(resultfocal.y>>3);
            cv::circle(cvimgIn,cv_point,5,cv::Scalar(255,0,0),1);
        //  cv::line(cvimgIn,cv_point_st,cv_point_ed,cv::Scalar(255,0,255),1);
            faxian.x=faxian.x*1000+resultfocal.x;
            faxian.y=faxian.y*1000+resultfocal.y;
            cv_point_st.x=(resultfocal.x>>3);
            cv_point_st.y=(resultfocal.y>>3);
            cv_point_ed.x=(faxian.x/8);
            cv_point_ed.y=(faxian.y/8);
            cv::line(cvimgIn,cv_point_st,cv_point_ed,cv::Scalar(255,255,0),1);
            cv_point_st.x=(upline.st.x>>3);
            cv_point_st.y=(upline.st.y>>3);
            cv_point_ed.x=(upline.ed.x>>3);
            cv_point_ed.y=(upline.ed.y>>3);
            cv::line(cvimgIn,cv_point_st,cv_point_ed,cv::Scalar(255,0,255),1);
            cv_point_st.x=(downline.st.x>>3);
            cv_point_st.y=(downline.st.y>>3);
            cv_point_ed.x=(downline.ed.x>>3);
            cv_point_ed.y=(downline.ed.y>>3);
            cv::line(cvimgIn,cv_point_st,cv_point_ed,cv::Scalar(255,0,255),1);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        }
    }
    else if(pokoumod==1) //盖焊坡口，求中心线与坡口底面交点
    {
        Myhalcv2::L_Point32 center;
        center.x=(resultfocal1.x+resultfocal2.x)>>1;
        center.y=(resultfocal1.y+resultfocal2.y)>>1;
        if(center.y<X_Linestarty||center.y>X_Lineendy)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        resultfocal.x=X_line[center.y];
        resultfocal.y=center.y;
        solderjoints=true;

        faxian1=faxian;
        faxian2=faxian;

        if(answerpoint==2)
        {
            Myhalcv2::L_Point32F f_temp;
            Myhalcv2::L_Point32 p_temp;
            f_temp=faxian;
            faxian=faxian1;
            faxian1=f_temp;
            p_temp=resultfocal;
            resultfocal=resultfocal1;
            resultfocal1=p_temp;
        }
        else if(answerpoint==3)
        {
            Myhalcv2::L_Point32F f_temp;
            Myhalcv2::L_Point32 p_temp;
            f_temp=faxian;
            faxian=faxian2;
            faxian2=f_temp;
            p_temp=resultfocal;
            resultfocal=resultfocal2;
            resultfocal2=p_temp;
        }
        if(step==1)
        {
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(cvimgIn.type()==CV_8UC1)
                cv::cvtColor(cvimgIn,cvimgIn,cv::COLOR_GRAY2BGR);
            cv_point_st.x=(resultfocal1.x>>3);
            cv_point_st.y=(resultfocal1.y>>3);
            cv::circle(cvimgIn,cv_point_st,5,cv::Scalar(0,0,255),1);
            cv_point_ed.x=(resultfocal2.x>>3);
            cv_point_ed.y=(resultfocal2.y>>3);
            cv::circle(cvimgIn,cv_point_ed,5,cv::Scalar(0,255,0),1);
            cv_point.x=(resultfocal.x>>3);
            cv_point.y=(resultfocal.y>>3);
            cv::circle(cvimgIn,cv_point,5,cv::Scalar(255,0,0),1);
        //  cv::line(cvimgIn,cv_point_st,cv_point_ed,cv::Scalar(255,0,255),1);
            faxian.x=faxian.x*1000+resultfocal.x;
            faxian.y=faxian.y*1000+resultfocal.y;
            cv_point_st.x=(resultfocal.x>>3);
            cv_point_st.y=(resultfocal.y>>3);
            cv_point_ed.x=(faxian.x/8);
            cv_point_ed.y=(faxian.y/8);
            cv::line(cvimgIn,cv_point_st,cv_point_ed,cv::Scalar(255,255,0),1);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>3,cuttop>>3);
                cv::Point p2(cutright>>3,cutdeep>>3);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        }
    }
    else
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>3,cuttop>>3);
            cv::Point p2(cutright>>3,cutdeep>>3);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
   
    cv_point.x=resultfocal.x;
    cv_point.y=resultfocal.y;
    namepoint.push_back(cv_point); 
    cv_point.x=faxian.x;
    cv_point.y=faxian.y;
    namepoint.push_back(cv_point); 
    cv_point.x=resultfocal1.x;
    cv_point.y=resultfocal1.y;
    namepoint.push_back(cv_point);  
    cv_point.x=resultfocal2.x;
    cv_point.y=resultfocal2.y;
    namepoint.push_back(cv_point);  
    
    return 0;
}

}