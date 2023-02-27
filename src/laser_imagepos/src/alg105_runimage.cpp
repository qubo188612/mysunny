#include "laser_imagepos/laser_imagepos.hpp"

#include "opencv2/opencv.hpp"
namespace laser_imagepos
{

using rcl_interfaces::msg::SetParametersResult;

void LaserImagePos::alg105_declare_parameters()
{
    this->declare_parameter("als105_exposure_time", pm.als105_exposure_time);
    this->declare_parameter("als105_pingjun", pm.als105_pingjun);
    this->declare_parameter("als105_b_yanmofuzhu", pm.als105_b_yanmofuzhu);
    this->declare_parameter("als105_widthliantongdis", pm.als105_widthliantongdis);
    this->declare_parameter("als105_highliantongdis", pm.als105_highliantongdis);
    this->declare_parameter("als105_gujiaerzhi", pm.als105_gujiaerzhi);
    this->declare_parameter("als105_jiguanghight", pm.als105_jiguanghight);
    this->declare_parameter("als105_jiguanglong", pm.als105_jiguanglong);
    this->declare_parameter("als105_jiguangkuandu", pm.als105_jiguangkuandu);
    this->declare_parameter("als105_Updif", pm.als105_Updif);
    this->declare_parameter("als105_Updifmin", pm.als105_Updifmin);
    this->declare_parameter("als105_Uplong", pm.als105_Uplong);
    this->declare_parameter("als105_Downdif", pm.als105_Downdif);
    this->declare_parameter("als105_Downdifmin", pm.als105_Downdifmin);
    this->declare_parameter("als105_Downdlong", pm.als105_Downdlong);
    this->declare_parameter("als105_dis_center_st", pm.als105_dis_center_st);
    this->declare_parameter("als105_dis_center_ed", pm.als105_dis_center_ed);
    this->declare_parameter("als105_b_cut", pm.als105_b_cut);
    this->declare_parameter("als105_cutleft", pm.als105_cutleft);
    this->declare_parameter("als105_cutright", pm.als105_cutright);
    this->declare_parameter("als105_cuttop", pm.als105_cuttop);
    this->declare_parameter("als105_cutdeep", pm.als105_cutdeep);
    this->declare_parameter("als105_guaidianyuzhi", pm.als105_guaidianyuzhi);
    this->declare_parameter("als105_duandianjuli", pm.als105_duandianjuli);
    this->declare_parameter("als105_b_dibufaxiangliang", pm.als105_b_dibufaxiangliang);
    this->declare_parameter("als105_answerpoint", pm.als105_answerpoint);
    this->declare_parameter("als105_usedownliantong", pm.als105_usedownliantong); 
    this->declare_parameter("als105_b_KalmanFilter", pm.als105_b_KalmanFilter); 
    this->declare_parameter("als105_KalmanQF", pm.als105_KalmanQF);
    this->declare_parameter("als105_KalmanRF", pm.als105_KalmanRF);
    this->declare_parameter("als105_cutside_Up", pm.als105_cutside_Up);
    this->declare_parameter("als105_cutside_Down", pm.als105_cutside_Down);
}

void LaserImagePos::alg105_update_parameters()
{
  const auto & vp = this->get_parameters(KEYS_ALS105);
  for (const auto & p : vp) {
    if (p.get_name() == "als105_exposure_time") {
      pm.als105_exposure_time = p.as_int();
    } else if (p.get_name() == "als105_pingjun") {
      pm.als105_pingjun = p.as_int();
    }
    else if (p.get_name() == "als105_b_yanmofuzhu") {
      pm.als105_b_yanmofuzhu = p.as_int();
    }
    else if (p.get_name() == "als105_widthliantongdis") {
      pm.als105_widthliantongdis = p.as_int();
    }
    else if (p.get_name() == "als105_highliantongdis") {
      pm.als105_highliantongdis = p.as_int();
    }
    else if (p.get_name() == "als105_gujiaerzhi") {
      pm.als105_gujiaerzhi = p.as_int();
    }
    else if (p.get_name() == "als105_jiguanghight") {
      pm.als105_jiguanghight = p.as_int();
    }
    else if (p.get_name() == "als105_jiguanglong") {
      pm.als105_jiguanglong = p.as_int();
    }
    else if (p.get_name() == "als105_jiguangkuandu") {
      pm.als105_jiguangkuandu = p.as_int();
    }
    else if (p.get_name() == "als105_Updif") {
      pm.als105_Updif = p.as_int();
    }
    else if (p.get_name() == "als105_Updifmin") {
      pm.als105_Updifmin = p.as_int();
    }
    else if (p.get_name() == "als105_Uplong") {
      pm.als105_Uplong = p.as_int();
    }
    else if (p.get_name() == "als105_Downdif") {
      pm.als105_Downdif = p.as_int();
    }
    else if (p.get_name() == "als105_Downdifmin") {
      pm.als105_Downdifmin = p.as_int();
    }
    else if (p.get_name() == "als105_Downdlong") {
      pm.als105_Downdlong = p.as_int();
    }
    else if (p.get_name() == "als105_dis_center_st") {
      pm.als105_dis_center_st = p.as_int();
    }
    else if (p.get_name() == "als105_dis_center_ed") {
      pm.als105_dis_center_ed = p.as_int();
    }
    else if (p.get_name() == "als105_b_cut") {
      pm.als105_b_cut = p.as_int();
    }
    else if (p.get_name() == "als105_cutleft") {
      pm.als105_cutleft = p.as_int();
    }
    else if (p.get_name() == "als105_cutright") {
      pm.als105_cutright = p.as_int();
    }
    else if (p.get_name() == "als105_cuttop") {
      pm.als105_cuttop = p.as_int();
    }
    else if (p.get_name() == "als105_cutdeep") {
      pm.als105_cutdeep = p.as_int();
    }
    else if (p.get_name() == "als105_guaidianyuzhi") {
      pm.als105_guaidianyuzhi = p.as_int();
    }
    else if (p.get_name() == "als105_duandianjuli") {
      pm.als105_duandianjuli = p.as_int();
    }
    else if (p.get_name() == "als105_b_dibufaxiangliang") {
      pm.als105_b_dibufaxiangliang = p.as_int();
    }
    else if (p.get_name() == "als105_answerpoint") {
      pm.als105_answerpoint = p.as_int();
    }
    else if (p.get_name() == "als105_usedownliantong") {
      pm.als105_usedownliantong = p.as_int();
    }
    else if (p.get_name() == "als105_b_KalmanFilter") {
      pm.als105_b_KalmanFilter = p.as_int();
    }
    else if (p.get_name() == "als105_KalmanQF") {
      pm.als105_KalmanQF = p.as_int();
    }
    else if (p.get_name() == "als105_KalmanRF") {
      pm.als105_KalmanRF = p.as_int();
    }
    else if (p.get_name() == "als105_cutside_Up") {
      pm.als105_cutside_Up = p.as_int();
    }
    else if (p.get_name() == "als105_cutside_Down") {
      pm.als105_cutside_Down = p.as_int();
    }
  }
}

int LaserImagePos::alg105_getcallbackParameter(const rclcpp::Parameter &p)
{
    if (p.get_name() == "als105_exposure_time") {
        auto k = p.as_int();
        if (k <20 || k>65535) {
            return -1;}
        else{pm.als105_exposure_time=k;
            if(pm.task_num==105){
                _param_camera->set_parameters({rclcpp::Parameter("exposure_time", pm.als105_exposure_time)});}
            return 1;}}
    else if(p.get_name() == "als105_pingjun") {
        auto k = p.as_int();
        if (k <0 || k>255) {
            return -1;}
        else{pm.als105_pingjun=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_b_yanmofuzhu") {
        auto k = p.as_int();
        if (k != 0 && k!=1) {
            return -1;}
        else{pm.als105_b_yanmofuzhu=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_widthliantongdis") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als105_widthliantongdis=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_highliantongdis") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als105_highliantongdis=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_gujiaerzhi") {
        auto k = p.as_int();
        if (k < 0 || k > 255) {
            return -1;}
        else{pm.als105_gujiaerzhi=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_jiguanghight") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als105_jiguanghight=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_jiguanglong") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als105_jiguanglong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_jiguangkuandu") {
        auto k = p.as_int();
        if (k < 0 || k > 20) {
            return -1;}
        else{pm.als105_jiguangkuandu=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_Updif") {
        auto k = p.as_int();
        if (k < -5000 || k > 5000) {
            return -1;}
        else{pm.als105_Updif=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_Updifmin") {
        auto k = p.as_int();
        if (k < -2000 || k > 5000) {
            return -1;}
        else{pm.als105_Updifmin=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_Uplong") {
        auto k = p.as_int();
        if (k < 1 || k > 500) {
            return -1;}
        else{pm.als105_Uplong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_Downdif") {
        auto k = p.as_int();
        if (k < -5000 || k > 5000) {
            return -1;}
        else{pm.als105_Downdif=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_Downdifmin") {
        auto k = p.as_int();
        if (k < -5000 || k > 5000) {
            return -1;}
        else{pm.als105_Downdifmin=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_Downdlong") {
        auto k = p.as_int();
        if (k < 1 || k > 500) {
            return -1;}
        else{pm.als105_Downdlong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_dis_center_st") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als105_dis_center_st=p.as_int();
            return 1;}}   
    else if(p.get_name() == "als105_dis_center_ed") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als105_dis_center_ed=p.as_int();
            return 1;}}     
    else if(p.get_name() == "als105_b_cut") {
        auto k = p.as_int();
        if (k < 0 || k > 1) {
            return -1;}
        else{pm.als105_b_cut=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als105_cutleft") {
        auto k = p.as_int();
        if (k < 0 || k >= PIC_IMAGE_WIDTH) {
            return -1;}
        else{pm.als105_cutleft=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als105_cutright") {
        auto k = p.as_int();
        if (k < 0 || k >= PIC_IMAGE_WIDTH) {
            return -1;}
        else{pm.als105_cutright=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als105_cuttop") {
        auto k = p.as_int();
        if (k < 0 || k >= PIC_IMAGE_HEIGHT) {
            return -1;}
        else{pm.als105_cuttop=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als105_cutdeep") {
        auto k = p.as_int();
        if (k < 0 || k >= PIC_IMAGE_HEIGHT) {
            return -1;}
        else{pm.als105_cutdeep=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als105_guaidianyuzhi") {
        auto k = p.as_int();
        if (k < 0 || k > 5000) {
            return -1;}
        else{pm.als105_guaidianyuzhi=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als105_duandianjuli") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als105_duandianjuli=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_b_dibufaxiangliang") {
        auto k = p.as_int();
        if (k < 0 || k > 1) {
            return -1;}
        else{pm.als105_b_dibufaxiangliang=p.as_int();
            return 1;}}                          
    else if(p.get_name() == "als105_answerpoint") {
        auto k = p.as_int();
        if (k < 0 || k > 20) {
            return -1;}
        else{pm.als105_answerpoint=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_usedownliantong") {
        auto k = p.as_int();
        if (k < 0 || k > 2) {
            return -1;}
        else{pm.als105_usedownliantong=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_b_KalmanFilter") {
        auto k = p.as_int();
        if (k < 0 || k > 1) {
            return -1;}
        else{pm.als105_b_KalmanFilter=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_KalmanQF") {
        auto k = p.as_int();
        if (k < 0 || k > 10000) {
            return -1;}
        else{pm.als105_KalmanQF=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_KalmanRF") {
        auto k = p.as_int();
        if (k < 0 || k > 10000) {
            return -1;}
        else{pm.als105_KalmanRF=p.as_int();
            return 1;}}    
    else if(p.get_name() == "als105_cutside_Up") {
        auto k = p.as_int();
        if (k < 0 || k > 1000) {
            return -1;}
        else{pm.als105_cutside_Up=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_cutside_Down") {
        auto k = p.as_int();
        if (k < 0 || k > 1000) {
            return -1;}
        else{pm.als105_cutside_Down=p.as_int();
            return 1;}}
                
    return 0;
}

int LaserImagePos::alg105_runimage( cv::Mat &cvimgIn,
                                    std::vector <cv::Point2f> &pointcloud,
                                    std::vector <cv::Point2f> &namepoint,
                                    bool &solderjoints,
                                    int step)    //输出结果点信息
{
    Int32 i,j,n;
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
    Myhalcv2::Mat i32_mXline,m_filter2,m32_filterIma,m32_filterIma1;
    Int32 zhengshunum=0;
    Myhalcv2::L_Point32 stepfindST,stepfindED;//结果线1拟合区域,(下方)
    Myhalcv2::L_Point32 midfindST,midfindED;//结果线2拟合区域,(上方)
    Int32 latsj,latsi;
    Int32 nihenum=0;
    Myhalcv2::L_Point32 linepoint32ST,linepoint32ED;
    Myhalcv2::L_line tileline;	//结果线2以及原图的线,(短的)
    Myhalcv2::L_line headline;	//结果线1以及原图的线,(短的)
    Myhalcv2::L_Point32 resultfocal1,resultfocal,resultfocal2,resultfocal3;//交点
    Int32 jiguangTop,jiguangDeep,jiguangLeft,jiguangRight;
    Myhalcv2::MyConect ImageConect,ImageConectlong,ImageConectlongPX;
    Myhalcv2::houghlineinfo headlinehough,tilelinehough;
    cv::Point cv_point_st,cv_point_ed;
    cv::Point2f cv_point;
    Int32 nstarti,nendi,nstartj,nendj;

    Myhalcv2::L_Point32F faxian,faxian1,faxian2,faxian3;

    /*********************/
    //算法参数
    Int32 pingjun=pm.als105_pingjun;//二值阈值
    Int32 b_yanmofuzhu=pm.als105_b_yanmofuzhu;//是否使用掩摸辅助
    Int32 widthliantongdis=pm.als105_widthliantongdis;//激光宽度连通距离
    Int32 highliantongdis=pm.als105_highliantongdis;//激光长度连通距离
    Int32 gujiaerzhi=pm.als105_gujiaerzhi;//找骨架二值图
    Int32 jiguanghight=pm.als105_jiguanghight;//整体激光最短长度
    Int32 jiguanglong=pm.als105_jiguanglong;//单边激光最短长度
    Int32 jiguangkuandu=pm.als105_jiguangkuandu;//激光粗细
    Int32 b_cut=pm.als105_b_cut;                  //是否使用搜索区域
    Int32 cutleft=pm.als105_cutleft;                //搜索区域
    Int32 cutright=pm.als105_cutright;        //搜索区域
    Int32 cuttop=pm.als105_cuttop;                 //搜索区域
    Int32 cutdeep=pm.als105_cutdeep;        //搜索区域
    Int32 guaidianyuzhi=pm.als105_guaidianyuzhi;//拐点阈值
    Int32 Downdifmin=pm.als105_Downdifmin;       //下半段直线斜率限制最大值
    Int32 Downdif=pm.als105_Downdif;      //下半段直线斜率限制最小值   //Downdif
    Int32 Updifmin=pm.als105_Updifmin;          //上半段直线斜率限制最小值     //Updifmin
    Int32 Updif=pm.als105_Updif;  //上半段直线斜率限制最大值//Updif
    Int32 dis_center_st=pm.als105_dis_center_st;     //距离中心点此处后开始统计 //dis_center_st
    Int32 dis_center_ed=pm.als105_dis_center_ed;//距离中心点此处后停止统计 //dis_center_st2
    Int32 Uplong=pm.als105_Uplong;//上半段直线长度   //设为200时将直接用拟合数据跟踪坡顶
    Int32 Downdlong=pm.als105_Downdlong;//下半段直线长度
    Int32 duandianjuli=pm.als105_duandianjuli;  //断点向前搜索距离
    Int32 b_dibufaxiangliang=pm.als105_b_dibufaxiangliang;//是否采用底部平面的法向量
    Int32 answerpoint=pm.als105_answerpoint;
    Int32 b_usedownliantong=pm.als105_usedownliantong;//是否使用最底部连通
    Int32 b_KalmanFilter=pm.als105_b_KalmanFilter;//是否使用卡尔曼滤波
    float KalmanQF=pm.als105_KalmanQF/1000.0;//系统噪声方差矩阵Q 
    float KalmanRF=pm.als105_KalmanRF/1000.0;//系统噪声方差矩阵R 
    Int32 cutside_Up=pm.als105_cutside_Up;//头尾截断距离
    Int32 cutside_Down=pm.als105_cutside_Down;//头尾截断距离
    
    if(step==2)
    {
        return 0;
    }
    imageIn=Myhalcv2::MatCreat(nWidth,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff_image);
    Myhalcv2::CvMatToMat(cvimgIn,&imageIn,cv8uc1_Imagebuff_image);
    imageGasu=Myhalcv2::MatCreat(nWidth,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff5);
    Myhalcv2::Mygausspyramid_2levl(imageIn,&imageGasu);  
    if(step!=0)
    {
        imageGasupain=Myhalcv2::MatCreat(nHeight,nWidth,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff8);
    }
    if(step==3)
    {
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        return 0;
    }
    imageBry=Myhalcv2::MatCreat(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff4);
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
        m_matMask=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff1);
        Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
        Myhalcv2::Myselect_shape(&ImageConect,&ImageConectlong,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,jiguanghight,MAX(ImageConect.nHeight,ImageConect.nWidth));
        Myhalcv2::Myregion_to_bin(&ImageConectlong,&m_matMask,255);
        Myhalcv2::Mydilation_circle2(m_matMask,&m_matMask,10,0,Myhalcv2::MHC_MORPH_RECT);
    }
    m_brygujia=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
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
    Myhalcv2::MyGetlanothinNoHough(imageBry,Myhalcv2::THIN_X,jiguangkuandu,&imageBry);
    Myhalcv2::Myconnection(imageBry,&ImageConect,20,0,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
    Myhalcv2::Myselect_shape(&ImageConect,&ImageConectlong,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,20,MAX(ImageConect.nHeight,ImageConect.nWidth));
    Myhalcv2::Myregion_to_bin(&ImageConectlong,&imageBry,255);

    if(step==8)
    {
        Myhalcv2::Mymat_to_binself(&imageBry,255);
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }      

    if(b_usedownliantong==0)
    {
        Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
        Myhalcv2::Myselect_shape(&ImageConect,&ImageConectlong,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,jiguanghight,MAX(ImageConect.nHeight,ImageConect.nWidth));
        if(ImageConectlong.AllMarkPointCount==0)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>2,cuttop>>2);
                cv::Point p2(cutright>>2,cutdeep>>2);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        Myhalcv2::Mysmallest_rectangle(&ImageConectlong,&jiguangLeft,&jiguangRight,&jiguangTop,&jiguangDeep);
        Myhalcv2::Myselect_obj(&ImageConectlong,&ImageConectlongPX,ImageConectlong.AllMarkPointCount-1);
    }
    else if(b_usedownliantong==1)
    {
        Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
        Myhalcv2::Myselect_shape(&ImageConect,&ImageConect,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,jiguanghight,MAX(ImageConect.nHeight,ImageConect.nWidth));
        Myhalcv2::Mysort_region(&ImageConect,&ImageConectlong,Myhalcv2::MHC_TOPTOBOTTOM_PAIXU);//在ImageConect中筛选出高度大于50的联通域
        if(ImageConectlong.AllMarkPointCount==0)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>2,cuttop>>2);
                cv::Point p2(cutright>>2,cutdeep>>2);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        /*
        Myhalcv2::Mysort_region(&ImageConect,&ImageConectlongPX,Myhalcv2::MHC_HEIGHT_PAIXU);//在ImageConect中筛选出高度大于50的联通域
        if(ImageConectlongPX.AllMarkPoint[ImageConectlongPX.AllMarkPointCount-1].bottom!=
           ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-1].bottom)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>2,cuttop>>2);
                cv::Point p2(cutright>>2,cutdeep>>2);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        */
        Myhalcv2::Myselect_obj(&ImageConectlong,&ImageConectlongPX,ImageConectlong.AllMarkPointCount-1);
        Myhalcv2::Mysmallest_rectangle(&ImageConectlongPX,&jiguangLeft,&jiguangRight,&jiguangTop,&jiguangDeep);
    }
    else if(b_usedownliantong==2)
    {
        Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
        Myhalcv2::Myselect_shape(&ImageConect,&ImageConect,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,jiguanghight,MAX(ImageConect.nHeight,ImageConect.nWidth));
        Myhalcv2::Mysort_region(&ImageConect,&ImageConectlong,Myhalcv2::MHC_TOPTOBOTTOM_PAIXU);//在ImageConect中筛选出高度大于50的联通域
        if(ImageConectlong.AllMarkPointCount==0)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>2,cuttop>>2);
                cv::Point p2(cutright>>2,cutdeep>>2);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        /*
        Myhalcv2::Mysort_region(&ImageConect,&ImageConectlongPX,Myhalcv2::MHC_HEIGHT_PAIXU);//在ImageConect中筛选出高度大于50的联通域
        if(ImageConectlongPX.AllMarkPoint[ImageConectlongPX.AllMarkPointCount-1].bottom!=
           ImageConectlong.AllMarkPoint[0].bottom)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>2,cuttop>>2);
                cv::Point p2(cutright>>2,cutdeep>>2);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        */
        Myhalcv2::Myselect_obj(&ImageConectlong,&ImageConectlongPX,0);
        Myhalcv2::Mysmallest_rectangle(&ImageConectlongPX,&jiguangLeft,&jiguangRight,&jiguangTop,&jiguangDeep);
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
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
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

    nstartj=MAX(jiguangTop*4,0);
    nendj=MIN(jiguangDeep*4,nHeight-1);
    nstarti=MAX(jiguangLeft*4-30,0);
    nendi=MIN(jiguangRight*4+30,nWidth-1);

    Myhalcv2::MyCutRoi(imageIn,&m_tempmatIn,Myhalcv2::MHC_CUT_NOTCOPY,nstarti,nstartj,nendi-nstarti+1,nendj-nstartj+1);
    for(j=m_tempmatIn.starty;j<m_tempmatIn.starty+m_tempmatIn.height;j++)
    {
        Int32 sum_valuecoor=0;
        Int32 sum_value=0;

        for(i=m_tempmatIn.startx;i<m_tempmatIn.startx+m_tempmatIn.width;i++)
        {
            Int32 di=i>>2;
            Int32 dj=j>>2;
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
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data1=255;
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data2=0;
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data3=0;
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
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
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
            imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data1=255;
            imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data2=0;
            imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data3=0;
        }
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }

    i32_mXline=Myhalcv2::MatCreat(1,nHeight,Myhalcv2::CCV_32SC1,X_line);//把线横摆
    for(i=0;i<15;i++)
    {
        filterdata2[i]=1;
    }
    for(i=15;i<25;i++)
    {
        filterdata2[i]=0;
    }
    for(i=25;i<40;i++)
    {
        filterdata2[i]=-1;
    }
    m_filter2=Myhalcv2::MatCreat(1,40,Myhalcv2::CCV_16SC1,filterdata2);
    m32_filterIma=Myhalcv2::MatCreatzero(1,nHeight,Myhalcv2::CCV_32SC1,X_linedif32);
    Myhalcv2::Myfilter(i32_mXline,m_filter2,&m32_filterIma,Myhalcv2::CCV_32SC1,0,f_center);//卷积得到
    if(b_cut==0)
    {
        //找起点
        m_brygujia=Myhalcv2::MatCreatzero(3,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
        for(j=X_Linestarty+24;j<=X_Lineendy-24;j++)
        {
            if(m32_filterIma.ptr_int[j]>=Updifmin&&m32_filterIma.ptr_int[j]<=Updif)
            {
                m_brygujia.data[1*m_brygujia.nWidth+j]=255;
            }
        }
        Myhalcv2::Myconnection(m_brygujia,&ImageConect,Uplong,0,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
        Myhalcv2::Mysort_region(&ImageConect,&ImageConectlong,Myhalcv2::MHC_LEFT_LEFTTORIGHT_PAIXU);
        if(ImageConectlong.AllMarkPointCount==0)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>2,cuttop>>2);
                cv::Point p2(cutright>>2,cutdeep>>2);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        X_Linestarty=ImageConectlong.AllMarkPoint[0].left;
        m_brygujia=Myhalcv2::MatCreatzero(3,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
        for(j=X_Linestarty+24;j<=X_Lineendy-24;j++)
        {
            if(m32_filterIma.ptr_int[j]>=Downdifmin&&m32_filterIma.ptr_int[j]<=Downdif)
            {
                m_brygujia.data[1*m_brygujia.nWidth+j]=255;
            }
        }
        Myhalcv2::Myconnection(m_brygujia,&ImageConect,Downdlong,0,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
        Myhalcv2::Mysort_region(&ImageConect,&ImageConectlong,Myhalcv2::MHC_LEFT_LEFTTORIGHT_PAIXU);
        if(ImageConectlong.AllMarkPointCount==0)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>2,cuttop>>2);
                cv::Point p2(cutright>>2,cutdeep>>2);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        X_Lineendy=ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-1].right;
        if(X_Lineendy-X_Linestarty<24*2+cutside_Down+cutside_Up)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>2,cuttop>>2);
                cv::Point p2(cutright>>2,cutdeep>>2);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        if(step==15)
        {
            Myhalcv2::MatClone(imageGasu,&imageGasupain);
            Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
            for(j=m_tempmatIn.starty;j<m_tempmatIn.starty+m_tempmatIn.height;j++)
            {
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data1=255;
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data2=0;
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data3=0;
            }
            linepoint32ST.x=(X_line[X_Linestarty]>>2);
            linepoint32ST.y=(X_Linestarty>>2);
            Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_UNFILL);
            linepoint32ST.x=(X_line[X_Lineendy]>>2);
            linepoint32ST.y=(X_Lineendy>>2);
            Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_UNFILL);
            Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
            return 0;
        }
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

    m32_filterIma1=Myhalcv2::MatCreatzero(1,nHeight,Myhalcv2::CCV_32SC1,f_line);
    f_center.x=10;
    f_center.y=0;
    Myhalcv2::Myfilter(i32_mXline,m_filter2,&m32_filterIma1,Myhalcv2::CCV_32SC1,0,f_center);//卷积得到

    m_brygujia=Myhalcv2::MatCreatzero(1,nHeight,Myhalcv2::CCV_32SC1,niheX);
    f_center.x=30;
    f_center.y=0;
    Myhalcv2::Myfilter(i32_mXline,m_filter2,&m_brygujia,Myhalcv2::CCV_32SC1,0,f_center);//卷积得到

    for(j=X_Linestarty+24;j<=X_Lineendy-24;j++)
    {
        m32_filterIma1.ptr_int[j]=m32_filterIma1.ptr_int[j]-m_brygujia.ptr_int[j];
    }


    //找最大突变点
    zhengshunum=-1;
    latsj=0;
    if(b_cut==0)
    {
        if(X_Lineendy-X_Linestarty-24*2<=cutside_Down+cutside_Up)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>2,cuttop>>2);
                cv::Point p2(cutright>>2,cutdeep>>2);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        nstartj=MIN(X_Linestarty+24+cutside_Up,X_Lineendy-24);
        nendj=MAX(X_Lineendy-24-cutside_Down,X_Linestarty+24);
        for(j=nstartj;j<=nendj;j++)
        {
            if(zhengshunum<abs(m32_filterIma1.ptr_int[j]))
            {
                zhengshunum=abs(m32_filterIma1.ptr_int[j]);
                latsj=j;
            }
        }
        if(guaidianyuzhi>abs(zhengshunum))
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>2,cuttop>>2);
                cv::Point p2(cutright>>2,cutdeep>>2);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        latsi=X_line[latsj];
    }
    else
    {
        nstartj=MAX(X_Linestarty+24,cuttop);
        nendj=MIN(X_Lineendy-24,cutdeep);
        for(j=nstartj;j<=nendj;j++)
        {
            if(zhengshunum<abs(m32_filterIma1.ptr_int[j]))
            {
                zhengshunum=abs(m32_filterIma1.ptr_int[j]);
                latsj=j;
            }
        }
        if(guaidianyuzhi>abs(zhengshunum))
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>2,cuttop>>2);
                cv::Point p2(cutright>>2,cutdeep>>2);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
        latsi=X_line[latsj];
        if(latsi<cutleft||latsi>cutright)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>2,cuttop>>2);
                cv::Point p2(cutright>>2,cutdeep>>2);
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
        for(j=m_tempmatIn.starty;j<m_tempmatIn.starty+m_tempmatIn.height;j++)
        {
            imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data1=255;
            imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data2=0;
            imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data3=0;
        }
        linepoint32ST.x=(latsi>>2);
        linepoint32ST.y=(latsj>>2);
        Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_UNFILL);
        if(b_cut==0)
        {
            linepoint32ST.x=(X_line[nstartj]>>2);
            linepoint32ST.y=(nstartj>>2);
            Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_UNFILL);
            linepoint32ST.x=(X_line[nendj]>>2);
            linepoint32ST.y=(nendj>>2);
            Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_UNFILL);
        }
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    //找上半段
    nstartj=MAX(X_Linestarty+24,latsj-dis_center_ed);
    nendj=MAX(X_Linestarty+24,latsj-dis_center_st);
    nstarti=X_line[nstartj];
    nendi=X_line[nendj];

    m_brygujia=Myhalcv2::MatCreatzero(3,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);  //创建上半截连通图

    for(j=nstartj;j<=nendj;j++)
    {
        if(m32_filterIma.ptr_int[j]>=Updifmin&&m32_filterIma.ptr_int[j]<=Updif)
        {
            m_brygujia.data[1*m_brygujia.nWidth+j]=255;
        }
    }
    if(step==17)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
        for(j=nstartj;j<=nendj;j++)
        {
            if( m_brygujia.data[1*m_brygujia.nWidth+j]!=0)
            {
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data1=255;
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data2=0;
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data3=0;
            }
        }
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    Myhalcv2::Myconnection(m_brygujia,&ImageConect,Uplong,0,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
    if(ImageConect.AllMarkPointCount!=1)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    stepfindST.y=ImageConect.AllMarkPoint[0].left;
    stepfindST.x=X_line[stepfindST.y];
    stepfindED.y=ImageConect.AllMarkPoint[0].right;
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
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,nWidth,nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&headline,&headlinehough);
    if(step==18)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
        for(j=nstartj;j<=nendj;j++)
        {
            if( m_brygujia.data[1*m_brygujia.nWidth+j]!=0)
            {
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data1=255;
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data2=0;
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data3=0;
            }
        }
        linepoint32ST.x=(stepfindST.x>>2);
        linepoint32ST.y=(stepfindST.y>>2);
        linepoint32ED.x=(stepfindED.x>>2);
        linepoint32ED.y=(stepfindED.y>>2);
        Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ED,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyPoint16to32(headline.st,&linepoint32ST);
        Myhalcv2::MyPoint16to32(headline.ed,&linepoint32ED);
        linepoint32ST.x=(linepoint32ST.x>>2);
        linepoint32ST.y=(linepoint32ST.y>>2);
        linepoint32ED.x=(linepoint32ED.x>>2);
        linepoint32ED.y=(linepoint32ED.y>>2);
        Myhalcv2::MyLine3col(&imageGasupain,linepoint32ST,linepoint32ED,0,0,255,Myhalcv2::CV_LINE_8LT,1);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    //找下半段
    nstartj=MIN(X_Lineendy-24,latsj+dis_center_st);
    nendj=MIN(X_Lineendy-24,latsj+dis_center_ed);
    nstarti=X_line[nstartj];
    nendi=X_line[nendj];

    m_brygujia=Myhalcv2::MatCreatzero(3,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);  //创建下半段连通图

    for(j=nstartj;j<=nendj;j++)
    {
        if(m32_filterIma.ptr_int[j]>=Downdifmin&&m32_filterIma.ptr_int[j]<=Downdif)
        {
            m_brygujia.data[1*m_brygujia.nWidth+j]=255;
        }
    }
    if(step==19)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
        for(j=nstartj;j<=nendj;j++)
        {
            if( m_brygujia.data[1*m_brygujia.nWidth+j]!=0)
            {
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data1=255;
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data2=0;
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data3=0;
            }
        }
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }

    Myhalcv2::Myconnection(m_brygujia,&ImageConect,Downdlong,0,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
    if(ImageConect.AllMarkPointCount!=1)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    midfindST.y=ImageConect.AllMarkPoint[0].left;
    midfindST.x=X_line[midfindST.y];
    midfindED.y=ImageConect.AllMarkPoint[0].right;
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
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,nWidth,nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&tileline,&tilelinehough);
    if(step==20)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
        for(j=nstartj;j<=nendj;j++)
        {
            if( m_brygujia.data[1*m_brygujia.nWidth+j]!=0)
            {
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data1=255;
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data2=0;
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data3=0;
            }
        }
        linepoint32ST.x=(midfindST.x>>2);
        linepoint32ST.y=(midfindST.y>>2);
        linepoint32ED.x=(midfindED.x>>2);
        linepoint32ED.y=(midfindED.y>>2);
        Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ED,4,0,255,0,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyPoint16to32(tileline.st,&linepoint32ST);
        Myhalcv2::MyPoint16to32(tileline.ed,&linepoint32ED);
        linepoint32ST.x=(linepoint32ST.x>>2);
        linepoint32ST.y=(linepoint32ST.y>>2);
        linepoint32ED.x=(linepoint32ED.x>>2);
        linepoint32ED.y=(linepoint32ED.y>>2);
        Myhalcv2::MyLine3col(&imageGasupain,linepoint32ST,linepoint32ED,0,0,255,Myhalcv2::CV_LINE_8LT,1);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }

    //找上半段端点
    nstartj=MAX(X_Linestarty+24,latsj-dis_center_ed);
    nendj=MIN(X_Lineendy-24,latsj+duandianjuli);
    nstarti=MAX(jiguangLeft*4-30,0);
    nendi=MIN(jiguangRight*4+30,nWidth-1);

    if(nendj-nstartj<Uplong)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
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
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
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
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
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
    if(step==21)
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
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
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
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    if(step==22)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
        linepoint32ST.x=(resultfocal1.x>>2);
        linepoint32ST.y=(resultfocal1.y>>2);
        Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_UNFILL);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }

    //找下半段端点
    nendj=MIN(X_Lineendy-24,latsj+dis_center_ed);
    nstartj=MAX(X_Linestarty+24,latsj-duandianjuli);
    nstarti=MAX(jiguangLeft*4-30,0);
    nendi=MIN(jiguangRight*4+30,nWidth-1);

    if(nendj-nstartj<Downdlong)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
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
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
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
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
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
    if(step==23)
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
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
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
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
    #endif
        return 1;
    }
    if(step==24)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
        linepoint32ST.x=(resultfocal2.x>>2);
        linepoint32ST.y=(resultfocal2.y>>2);
        Myhalcv2::MyCircle3col(&imageGasupain,linepoint32ST,4,0,255,0,Myhalcv2::CV_CLRCLE_UNFILL);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    //采用底部平面法向量
    if(b_dibufaxiangliang==1)
    {
        linepoint32ED.x=tileline.ed.x;
        linepoint32ED.y=tileline.ed.y;
        Myhalcv2::MyGetLinefocalRight(resultfocal1,linepoint32ED,&faxian);
        /*
        if(resultfocal1.x<resultfocal2.x)
        {
            linepoint32ST.x=headline.st.x;
            linepoint32ST.y=headline.st.y;
            Myhalcv2::MyGetLinefocalRight(resultfocal1,linepoint32ST,&faxian);
        }
        else
        {
            linepoint32ED.x=tileline.ed.x;
            linepoint32ED.y=tileline.ed.y;
            Myhalcv2::MyGetLinefocalRight(resultfocal1,linepoint32ED,&faxian);
        }
        */
    }
    else
    {
        linepoint32ST.x=headline.st.x;
        linepoint32ST.y=headline.st.y;
        Myhalcv2::MyGetLinefocalRight(resultfocal1,linepoint32ST,&faxian);
        /*
        if(resultfocal1.x<resultfocal2.x)
        {
            linepoint32ED.x=tileline.ed.x;
            linepoint32ED.y=tileline.ed.y;
            Myhalcv2::MyGetLinefocalRight(resultfocal1,linepoint32ED,&faxian);
        }
        else
        {
            linepoint32ST.x=headline.st.x;
            linepoint32ST.y=headline.st.y;
            Myhalcv2::MyGetLinefocalRight(resultfocal1,linepoint32ST,&faxian);
        }
        */
    }

    resultfocal.x=(resultfocal2.x+resultfocal1.x)/2;
    resultfocal.y=(resultfocal2.y+resultfocal1.y)/2;

    //计算最底部点
    nstartj=MIN(resultfocal1.y,resultfocal2.y);
    nendj=MAX(resultfocal1.y,resultfocal2.y);
    nstartj=MAX(X_Linestarty+24,nstartj);
    nendj=MAX(X_Linestarty+24,nendj);
    nstartj=MIN(X_Lineendy-24,nstartj);
    nendj=MIN(X_Lineendy-24,nendj);
    latsi=X_line[nstartj];
    for(j=nstartj;j<=nendj;j++)
    {
        if(latsi>X_line[j])
        {
            latsi=X_line[j];
        }
    }
    m_brygujia=Myhalcv2::MatCreatzero(3,nendj-nstartj+1,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    for(j=nstartj;j<=nendj;j++)
    {
        if(latsi==X_line[j])
        {
            m_brygujia.data[1*m_brygujia.nWidth+(j-nstartj)]=255;
        }
    }
    if(step==25)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
        Myhalcv2::MyBRYtoRGB(imageGasupain,&imageGasupain);
        for(j=nstartj;j<=nendj;j++)
        {
            if( m_brygujia.data[1*m_brygujia.nWidth+(j-nstartj)]==255)
            {
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data1=255;
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data2=0;
                imageGasupain.ptr_Vec3b[(j>>2)*imageGasupain.nWidth+(X_line[j]>>2)].data3=0;
            }
        }
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    Myhalcv2::Myconnection2(m_brygujia,&ImageConect,1,1,0,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
    Myhalcv2::Mysort_region(&ImageConect,&ImageConectlong,Myhalcv2::MHC_WIDTH_PAIXU);
    /*
    if(ImageConectlong.AllMarkPointCount>=2)
    {
        //去掉有两块最大最长的最低区域的
        if(ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-1].right-ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-1].left+1
            ==ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-2].right-ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-2].left+1)
        {
        #ifdef QUICK_TRANSMIT
            Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
            if(b_cut==1)
            {
                cv::Point p1(cutleft>>2,cuttop>>2);
                cv::Point p2(cutright>>2,cutdeep>>2);
                cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
            }
        #endif
            return 1;
        }
    }
    */
    resultfocal3.y=(ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-1].right+ImageConectlong.AllMarkPoint[ImageConectlong.AllMarkPointCount-1].left)/2+nstartj;
    resultfocal3.x=X_line[resultfocal3.y];

    faxian1=faxian;
    faxian2=faxian;
    faxian3=faxian;

    if(answerpoint==2)
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
    else if(answerpoint==4)
    {
        Myhalcv2::L_Point32F f_temp;
        Myhalcv2::L_Point32 p_temp;
        f_temp=faxian;
        faxian=faxian3;
        faxian3=f_temp;
        p_temp=resultfocal;
        resultfocal=resultfocal3;
        resultfocal3=p_temp;
    }


    if(b_KalmanFilter==1)
    {
       if(b_firstKalmanFilter==0)
       {
            b_firstKalmanFilter=1;
            Myhalcv2::MyKalman2D_init(resultfocal.x,resultfocal.y,KalmanQF,KalmanRF);
       } 
       else
       {
            Int32 outx,outy;
            Myhalcv2::MyKalman2D_filter(resultfocal.x,resultfocal.y,&outx,&outy);
            resultfocal.x=outx;
            resultfocal.y=outy;
       }
    }

    if(step==1)
    {
        Myhalcv2::L_POINT32F f_temp;
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
        if(cvimgIn.type()==CV_8UC1)
            cv::cvtColor(cvimgIn,cvimgIn,cv::COLOR_GRAY2BGR);
        linepoint32ST.y=MAX(X_Linestarty+24,resultfocal1.y-dis_center_ed);
        linepoint32ED.y=MIN(X_Lineendy-24,resultfocal1.y);
        MyGetLineXpos(headline,linepoint32ST.y,&linepoint32ST.x);
        MyGetLineXpos(headline,linepoint32ED.y,&linepoint32ED.x);
        cv_point_st.x=(linepoint32ST.x>>2);
        cv_point_st.y=(linepoint32ST.y>>2);
        cv_point_ed.x=(linepoint32ED.x>>2);
        cv_point_ed.y=(linepoint32ED.y>>2);
        cv::line(cvimgIn,cv_point_st,cv_point_ed,cv::Scalar(255,0,0),1);
        linepoint32ST.y=MAX(X_Linestarty+24,resultfocal2.y);
        linepoint32ED.y=MIN(X_Lineendy-24,resultfocal2.y+dis_center_ed);
        MyGetLineXpos(tileline,linepoint32ST.y,&linepoint32ST.x);
        MyGetLineXpos(tileline,linepoint32ED.y,&linepoint32ED.x);
        cv_point_st.x=(linepoint32ST.x>>2);
        cv_point_st.y=(linepoint32ST.y>>2);
        cv_point_ed.x=(linepoint32ED.x>>2);
        cv_point_ed.y=(linepoint32ED.y>>2);
        cv::line(cvimgIn,cv_point_st,cv_point_ed,cv::Scalar(0,255,0),1);
        cv_point_st.x=(resultfocal.x>>2);
        cv_point_st.y=(resultfocal.y>>2);
        cv::circle(cvimgIn,cv_point_st,5,cv::Scalar(0,0,255),1);
        cv_point_st.x=(resultfocal1.x>>2);
        cv_point_st.y=(resultfocal1.y>>2);
        cv::circle(cvimgIn,cv_point_st,5,cv::Scalar(0,255,255),1);
        cv_point_st.x=(resultfocal2.x>>2);
        cv_point_st.y=(resultfocal2.y>>2);
        cv::circle(cvimgIn,cv_point_st,5,cv::Scalar(255,0,255),1);
        cv_point_st.x=(resultfocal3.x>>2);
        cv_point_st.y=(resultfocal3.y>>2);
        cv::circle(cvimgIn,cv_point_st,5,cv::Scalar(128,0,255),1);
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
        f_temp.x=faxian.x*1000+resultfocal.x;
        f_temp.y=faxian.y*1000+resultfocal.y;
        cv_point_st.x=(resultfocal.x>>2);
        cv_point_st.y=(resultfocal.y>>2);
        cv_point_ed.x=(f_temp.x/4);
        cv_point_ed.y=(f_temp.y/4);
        cv::line(cvimgIn,cv_point_st,cv_point_ed,cv::Scalar(255,255,0),1);
    }
   
    solderjoints=false;
    cv_point.x=resultfocal.x;
    cv_point.y=resultfocal.y;
    namepoint.push_back(cv_point); 
    cv_point.x=faxian.x*1000+resultfocal.x;
    cv_point.y=faxian.y*1000+resultfocal.y;
    namepoint.push_back(cv_point); 
    cv_point.x=resultfocal1.x;
    cv_point.y=resultfocal1.y;
    namepoint.push_back(cv_point);  
    cv_point.x=resultfocal2.x;
    cv_point.y=resultfocal2.y;
    namepoint.push_back(cv_point);  
    cv_point.x=resultfocal3.x;
    cv_point.y=resultfocal3.y;
    namepoint.push_back(cv_point);  
    
    return 0;
}

}