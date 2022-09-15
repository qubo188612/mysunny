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
    this->declare_parameter("als100_dis_center_st", pm.als100_dis_center_st);
    this->declare_parameter("als100_dis_center_ed", pm.als100_dis_center_ed);
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
    else if (p.get_name() == "als100_dis_center_st") {
      pm.als100_dis_center_st = p.as_int();
    }
    else if (p.get_name() == "als100_dis_center_ed") {
      pm.als100_dis_center_ed = p.as_int();
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
            if(pm.task_num==100){
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
    else if(p.get_name() == "als100_duanxianerzhi") {
        auto k = p.as_int();
        if (k < 0 || k > 255) {
            return -1;}
        else{pm.als100_duanxianerzhi=p.as_int();
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
    else if(p.get_name() == "als100_dis_center_st") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als100_dis_center_st=p.as_int();
            return 1;}}   
    else if(p.get_name() == "als100_dis_center_ed") {
        auto k = p.as_int();
        if (k < 0 || k > 500) {
            return -1;}
        else{pm.als100_dis_center_ed=p.as_int();
            return 1;}}     

    return 0;
}

int LaserImagePos::alg100_runimage( cv::Mat &cvimgIn,
                                    std::vector <cv::Point2f> &pointcloud,
                                    std::vector <cv::Point2f> &namepoint,
                                    bool &solderjoints,
                                    int step)    //输出结果点信息
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
    Int32 linedistance1,linedistance2;
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
    Myhalcv2::houghlineinfo headlinehough,tilelinehough;
    cv::Point cv_point_st,cv_point_ed;
    cv::Point2f cv_point;
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
    Int32 dis_center_st=pm.als100_dis_center_st;//0;     //距离中心点此处后开始统计
    Int32 dis_center_ed=pm.als100_dis_center_ed;//500;  //距离中心点此处后停止统计

#ifdef DEBUG_ALG
    int debug_alg=1;
    RCLCPP_INFO(this->get_logger(), "start alg100");
#endif
    if(step==2)
    {
      return 0;
    }
    imageIn=Myhalcv2::MatCreat(nWidth,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff_image);
    Myhalcv2::CvMatToMat(cvimgIn,&imageIn,cv8uc1_Imagebuff_image);
    imageGasu=Myhalcv2::MatCreat(nWidth,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff5);
    Myhalcv2::Mygausspyramid_2levl(imageIn,&imageGasu);
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif    
    if(step!=0)
    {
      imageGasupain=MatCreatClone(imageGasu,cv8uc1_Imagebuff8);
    }
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==3)
    {
      Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
      return 0;
    }
    imageBry=Myhalcv2::MatCreat(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff4);
    Myhalcv2::Mynormalize(imageGasu,&imageBry);
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==4)
    {
      Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
      return 0;
    }
    Myhalcv2::Mybinaryval(imageBry,&bryvalue,Myhalcv2::MHC_BARINYVAL_MEAN);
    i32_bryvalue=(Int32)bryvalue+pingjun;//求平均值二值化阈值
    Myhalcv2::Mybinary(imageBry,&imageBry,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
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
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==6)
    {
      Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
      return 0;
    }
    i32_bryvalue=gujiaerzhi;
    Myhalcv2::Mybinary(m_brygujia,&m_brygujia,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==7)
    {
      Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
      return 0;
    }

    Myhalcv2::Myintersection(imageBry,m_brygujia,&imageBry);
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==8)
    {
      Myhalcv2::Mymat_to_binself(&imageBry,255);
      Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
      return 0;
    }

    Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
    Myhalcv2::Myselect_shape(&ImageConect,&ImageConect,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,jiguanghight,MAX(ImageConect.nHeight,ImageConect.nWidth));
    Myhalcv2::Mysort_region(&ImageConect,&ImageConectlong,Myhalcv2::MHC_LEFT_LEFTTORIGHT_PAIXU);//在ImageConect中筛选出高度大于50的联通域
    if(ImageConectlong.AllMarkPointCount==0)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    Myhalcv2::Myselect_obj(&ImageConectlong,&ImageConectlongPX,0);
    Myhalcv2::Mysmallest_rectangle(&ImageConectlongPX,&jiguangLeft,&jiguangRight,&jiguangTop,&jiguangDeep);
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
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==9)
    {
      Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
      return 0;
    }
    i32_bryvalue=gujiaerzhi;//求平均值二值化阈值
    Myhalcv2::Mybinary(imageBry,&imageBry,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==10)
    {
      Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
      return 0;
    }
    Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
    Myhalcv2::Myselect_shape(&ImageConect,&ImageConectlong,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,jiguanglong,MAX(ImageConect.nHeight,ImageConect.nWidth));//在ImageConect中筛选出高度大于50的联通域
    if(ImageConectlong.AllMarkPointCount==0)
    {
        return 0;
    }
    Myhalcv2::MyGetthinNoHough(&ImageConectlong,Myhalcv2::THIN_X,jiguangkuandu,&imageBry);
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==11)
    {
      Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
      return 0;
    }
    Myhalcv2::Mydeleteconnection(imageBry,&imageBry,jiguanghight,highliantongdis,Myhalcv2::MHC_8LT);
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==12)
    {
      Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
      return 0;
    }
    /***********************/
    //以下的图像几乎都是完美图像,需要检测出结果
    //以下对高斯图做卷积
    m16_filterIma=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_16UC1,cv8uc1_Imagebuff6);
    m_filter=Myhalcv2::MatCreat(5,5,Myhalcv2::CCV_8UC1,filterdata);
    Myhalcv2::Myfilter(imageGasu,m_filter,&m16_filterIma,Myhalcv2::CCV_16UC1,0,f_center);
    memset(X_line,0,sizeof(Int32)*nHeight/4);
    memset(X_lineMark,0,nHeight/4);
    X_Linestarty=0;
    X_Lineendy=0;
    //以下取出二值图结果中每行卷积最大值
    m_brygujia=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    for(j=m16_filterIma.starty;j<m16_filterIma.starty+m16_filterIma.height;j++)
    {
        Uint16 max=0;
        Uint16 maxX=m16_filterIma.startx;
        Uint16 maxXn=0;
        for(i=m16_filterIma.startx;i<m16_filterIma.startx+m16_filterIma.width;i++)
        {
            if(imageBry.ptr_uchar[j*imageBry.nWidth+i]!=0)
            {
                if(max<m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                {
                    max=m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i];
                    maxXn=1;
                    maxX=i;
                }
                else if(max==m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                {
                    maxXn++;
                    maxX=i+maxX;
                }
            }
        }
        if(maxXn!=0)
        {
            X_line[j]=(maxX<<1)/maxXn;
            if(X_Linestarty==0)
            {
                X_Linestarty=j;//骨架起点
            }
            X_Lineendy=j;//骨架终点
            m_brygujia.data[j*imageGasu.nWidth+(X_line[j]>>1)]=255;
        }
        if(step==12)
        {
          if(X_line[j]!=0&&maxX!=imageBry.startx)
          {
              imageGasupain.data[j*imageGasu.nWidth+(X_line[j]>>1)]=0;
          }
        }
    }
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==13)
    {
      Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
      return 0;
    }
    if(X_Lineendy==0)//没找到骨架
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    Myhalcv2::Myconnection(m_brygujia,&ImageConect,5,1,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//先去掉离散点
    Myhalcv2::Myregion_to_bin(&ImageConect,&m_brygujia,255);
    Myhalcv2::Myconnection(m_brygujia,&ImageConect,15,1,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//求联通大于100的区域,联通距离10
    if(ImageConect.AllMarkPointCount==0)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    for(j=0;j<ImageConect.AllMarkPointCount;j++)
    {
        for(i=0;i<ImageConect.AllMarkPoint[j].PointArea;i++)
        {
            Int32 y=ImageConect.AllMarkPoint[j].point[i].y;
            X_lineMark[y]=1;
        }
    }
    Myhalcv2::Myfixdata(X_line,X_lineMark,nHeight/4);//修复空的线
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==14)
    {
      for(j=X_Linestarty;j<=X_Lineendy;j++)
      {
          imageGasupain.data[j*imageGasupain.nWidth+(X_line[j]>>1)]=30;
      }
      Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
      return 0;
    }

    mini=RANDOM_MAX;
    for(j=X_Linestarty;j<=X_Lineendy;j++)
    {
        if(mini>X_line[j])
        {
            mini=X_line[j];
            minj=j;
        }
    }
    i32_mXline=Myhalcv2::MatCreat(1,nHeight/4,Myhalcv2::CCV_32SC1,X_line);//把线横摆
    m_filter2=Myhalcv2::MatCreat(1,10,Myhalcv2::CCV_16SC1,filterdata2);
    m32_filterIma=Myhalcv2::MatCreatzero(1,nHeight/4,Myhalcv2::CCV_32SC1,X_linedif32);
    Myhalcv2::Myfilter(i32_mXline,m_filter2,&m32_filterIma,Myhalcv2::CCV_32SC1,0,f_center);//卷积得到
    //找上半段
    zhengshunum=0;
    stepfind=0;
    for(j=X_Linestarty+6;j<=X_Lineendy-6;j++)
    {
        //如果找到连续3个正数,可以确定起点
        if(stepfind==0)
        {
            if(m32_filterIma.ptr_int[j]>=Updif)
            {
                zhengshunum++;
            }
            else if(m32_filterIma.ptr_int[j]<Updif)
            {
                zhengshunum=0;
            }
            if(zhengshunum==3)
            {
                stepfind=1;
                stepfindST.x=(X_line[j]>>1);	//直线起点
                stepfindST.y=j;
                latsj=j;
            }
        }
        if(stepfind==1)
        {
            if(m32_filterIma.ptr_int[j]>Updif)//定位到最后个大于0的地方
            {
                latsj=j;
            }
            if(m32_filterIma.ptr_int[j]<Updifmin)
            {
                int end=latsj;
                stepfind=2;
                stepfindED.x=(X_line[end]>>1);	//直线终点
                stepfindED.y=end;
            }
        }
        if(stepfind==2)
        {
            //再判断下长度
            if(stepfindED.y-stepfindST.y<Uplong)
            {
                stepfind=0;
                zhengshunum=0;
            }
            else
            {
                break;
            }
        }
    }
    if(stepfind!=2)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }

    /************************************/
        //人工辅助限制
    stepfindED.y=MIN(stepfindED.y,minj-dis_center_st);
    if(stepfindED.y<(Int32)X_Linestarty+6)
        stepfindED.y=X_Linestarty+6;
    stepfindED.x=X_line[stepfindED.y]>>1;
    stepfindST.y=MAX(stepfindST.y,minj-dis_center_ed);
    stepfindST.x=X_line[stepfindST.y]>>1;
    if(stepfindED.y-stepfindST.y<Uplong)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    /**************************************/

    linedistance1=sqrt((double)(stepfindED.x-stepfindST.x)*(stepfindED.x-stepfindST.x)+(stepfindED.y-stepfindST.y)*(stepfindED.y-stepfindST.y));
    if(linedistance1<Uplong)//线太短寻找失败了
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }

    //找下半段
    zhengshunum=0;
    stepfind=0;
    for(j=X_Lineendy-6;j>=X_Linestarty+6;j--)
    {
        //如果找到连续3个负数,可以确定起点
        if(stepfind==0)
        {
            if(m32_filterIma.ptr_int[j]<=Downdif)
            {
                zhengshunum++;
            }
            else if(m32_filterIma.ptr_int[j]>Downdif)
            {
                zhengshunum=0;
            }
            if(zhengshunum==3)
            {
                stepfind=1;
                midfindED.x=(X_line[j]>>1);	//直线起点
                midfindED.y=j;
                latsj=j;
            }
        }
        if(stepfind==1)
        {
            if(m32_filterIma.ptr_int[j]<Downdif)//定位到最后个大于0的地方
            {
                latsj=j;
            }
            if(m32_filterIma.ptr_int[j]>Downdifmin)
            {
                int st=latsj;
                stepfind=2;
                midfindST.x=(X_line[st]>>1);	//直线终点
                midfindST.y=st;
            }
        }
        if(stepfind==2)
        {
            //再判断下长度
            if(midfindED.y-midfindST.y<Downdlong)
            {
                stepfind=0;
                zhengshunum=0;
            }
            else
            {
                break;
            }
        }
    }
    if(stepfind!=2)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }

    /************************************/
    //人工辅助限制
    midfindST.y=MAX(midfindST.y,minj+dis_center_st);
    if(midfindST.y>(Int32)(X_Lineendy-6))
        midfindST.y=X_Lineendy-6;
    midfindST.x=X_line[midfindST.y]>>1;
    midfindED.y=MIN(midfindED.y,minj+dis_center_ed);
    midfindED.x=X_line[midfindED.y]>>1;
    if(midfindED.y-midfindST.y<Downdlong)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    /**************************************/

    linedistance2=sqrt((double)(midfindED.x-midfindST.x)*(midfindED.x-midfindST.x)+(midfindED.y-midfindST.y)*(midfindED.y-midfindST.y));
    if(linedistance2<Downdlong)//线太短寻找失败了
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }

    nihenum=0;
    for(j=stepfindST.y;j<=stepfindED.y;j++)
    {
        if(X_lineMark[j]==1)
        {
            niheX[nihenum]=(X_line[j]>>1);
            niheY[nihenum++]=j;
        }
    }
    if(nihenum==0)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,imageGasu.nWidth,imageGasu.nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&headline,&headlinehough);
    nihenum=0;
    for(j=midfindST.y;j<=midfindED.y;j++)
    {
        if(X_lineMark[j]==1)
        {
            niheX[nihenum]=(X_line[j]>>1);
            niheY[nihenum++]=j;
        }
    }
    if(nihenum==0)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
    #endif
        return 1;
    }
    Myhalcv2::MyData_sqare_line(niheX,niheY,nihenum,imageGasu.nWidth,imageGasu.nHeight,Myhalcv2::MHC_MIXDIS_SQARE,&tileline,&tilelinehough);
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==15)
    {
      Myhalcv2::MatClone(imageGasu,&imageGasupain);
      Myhalcv2::MyPoint16to32(headline.st,&linepoint32ST);
      Myhalcv2::MyPoint16to32(headline.ed,&linepoint32ED);
      Myhalcv2::MyLine(&imageGasupain,linepoint32ST,linepoint32ED,255,Myhalcv2::CV_LINE_8LT,1);
      Myhalcv2::MyPoint16to32(tileline.st,&linepoint32ST);
      Myhalcv2::MyPoint16to32(tileline.ed,&linepoint32ED);
      Myhalcv2::MyLine(&imageGasupain,linepoint32ST,linepoint32ED,255,Myhalcv2::CV_LINE_8LT,1);
      Myhalcv2::MyCircle(&imageGasupain,stepfindST,5,128,Myhalcv2::CV_CLRCLE_FILL);
      Myhalcv2::MyCircle(&imageGasupain,stepfindED,5,128,Myhalcv2::CV_CLRCLE_FILL);
      Myhalcv2::MyCircle(&imageGasupain,midfindST,5,128,Myhalcv2::CV_CLRCLE_FILL);
      Myhalcv2::MyCircle(&imageGasupain,midfindED,5,128,Myhalcv2::CV_CLRCLE_FILL);
      Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
      return 0;
    }
    /***********************/
    if(step!=0)
    {
        Myhalcv2::MatClone(imageGasu,&imageGasupain);
    }

    //在大图上拟合
    imageGasu=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff5);
    for(j=X_Linestarty;j<=X_Lineendy;j++)
    {
        imageGasu.data[j*imageGasu.nWidth+(X_line[j]>>1)]=255;
    }


    headline.ed.x=headline.ed.x*4;
    headline.ed.y=headline.ed.y*4;
    headline.st.x=headline.st.x*4;
    headline.st.y=headline.st.y*4;
    tileline.ed.x=tileline.ed.x*4;
    tileline.ed.y=tileline.ed.y*4;
    tileline.st.x=tileline.st.x*4;
    tileline.st.y=tileline.st.y*4;
    stepfindST.x=stepfindST.x*4;
    stepfindST.y=stepfindST.y*4;
    stepfindED.x=stepfindED.x*4;
    stepfindED.y=stepfindED.y*4;
    midfindST.x=midfindST.x*4;
    midfindST.y=midfindST.y*4;
    midfindED.x=midfindED.x*4;
    midfindED.y=midfindED.y*4;

    memset(X_line,0,sizeof(Int32)*nHeight);

    nstartj=MIN(stepfindST.y,stepfindED.y);
    nendj=MAX(stepfindST.y,stepfindED.y);
    nstarti=MIN(stepfindST.x,stepfindED.x)-30;
    nendi=MAX(stepfindST.x,stepfindED.x)+30;
    if(nstarti<0)
    {
        nstarti=0;
    }
    if(nendi>nWidth-1)
    {
        nendi=nWidth-1;
    }
    Myhalcv2::MyCutRoi(imageIn,&m_tempmatIn,Myhalcv2::MHC_CUT_NOTCOPY,nstarti,nstartj,nendi-nstarti+1,nendj-nstartj+1);
    Myhalcv2::Myfilter(m_tempmatIn,m_filter,&m16_filterIma,Myhalcv2::CCV_16UC1,0,f_center);

    MyPoint16to32(headline.ed,&linepoint32ED);
    MyPoint16to32(headline.st,&linepoint32ST);

    linepoint32ST.x=((linepoint32ST.x)>>2);
    linepoint32ST.y=((linepoint32ST.y)>>2);
    linepoint32ED.x=((linepoint32ED.x)>>2);
    linepoint32ED.y=((linepoint32ED.y)>>2);

    imageBry=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff4);
    Myhalcv2::MyLine(&imageBry,linepoint32ST,linepoint32ED,255,Myhalcv2::CV_LINE_8LT,7);

    m_brygujia=Myhalcv2::MatCreatzero(nHeight,nWidth,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    for(j=nstartj;j<=nendj;j++)
    {
        Uint16 max=0;
        Uint16 maxX=nstarti;
        Uint16 maxXn=0;
        for(i=nstarti;i<=nendi;i++)
        {
            Int32 dj=(j>>2);
            Int32 di=(i>>2);
            if(imageBry.ptr_uchar[dj*imageBry.nWidth+di]!=0&&imageGasu.data[dj*imageGasu.nWidth+di]!=0)
            {
                if(max<m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                {
                    max=m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i];
                    maxXn=1;
                    maxX=i;
                }
                else if(max==m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                {
                    maxXn++;
                    maxX=i+maxX;
                }
            }
        }
        if(maxXn!=0)
        {
            m_brygujia.ptr_uchar[j*m_brygujia.nWidth+(((maxX<<1)/maxXn)>>1)]=255;
        }
    }

    Myhalcv2::MyCutminRoi(m_brygujia,&m_brygujia,Myhalcv2::MHC_CUTMIN_32,nstarti,nstartj,nendi-nstarti+1,nendj-nstartj+1);
    if(linedistance1<5)
        Myhalcv2::Myconnection2(m_brygujia,&ImageConect,10,2,3,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
    else
        Myhalcv2::Myconnection2(m_brygujia,&ImageConect,15,2,3,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
    if(ImageConect.AllMarkPointCount==0)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;
    }
    Myhalcv2::Myhom_conect2d_translate(&ImageConect,&ImageConectlong,nstarti,nstartj,Myhalcv2::MHC_TRANS_OUTIMAGE);
    ImageConectlong.nHeight=imageIn.nHeight;
    ImageConectlong.nWidth=imageIn.nWidth;
    ImageConectlong.startx=imageIn.startx;
    ImageConectlong.starty=imageIn.starty;
    ImageConectlong.height=imageIn.height;
    ImageConectlong.width=imageIn.width;

    for(j=0;j<ImageConectlong.AllMarkPointCount;j++)
    {
      for(i=0;i<ImageConectlong.AllMarkPoint[j].PointArea;i++)
      {
          cv::Point2f point(ImageConectlong.AllMarkPoint[j].point[i].x,ImageConectlong.AllMarkPoint[j].point[i].y);
          pointcloud.push_back(point);
      }
    }

    if(0!=Myhalcv2::MyConect_sqare_line(&ImageConectlong,Myhalcv2::MHC_MIXDIS_SQARE,&headline,&headlinehough))
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;
    }
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==16)
    {
      Myhalcv2::MatClone(imageIn,&m_brygujia);
      Myhalcv2::Myregion_to_add(&ImageConectlong,&m_brygujia,0);
      Myhalcv2::MyPoint16to32(headline.ed,&linepoint32ED);
      Myhalcv2::MyPoint16to32(headline.st,&linepoint32ST);
      Myhalcv2::MyLine(&m_brygujia,linepoint32ST,linepoint32ED,128,Myhalcv2::CV_LINE_8LT,3);
      Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
      return 0;
    }
    nstartj=MIN(midfindST.y,midfindED.y);
    nendj=MAX(midfindST.y,midfindED.y);
    nstarti=MIN(midfindST.x,midfindED.x)-30;
    nendi=MAX(midfindST.x,midfindED.x)+30;
    if(nstarti<0)
    {
        nstarti=0;
    }
    if(nendi>nWidth-1)
    {
        nendi=nWidth-1;
    }

    Myhalcv2::MyCutRoi(imageIn,&m_tempmatIn,Myhalcv2::MHC_CUT_NOTCOPY,nstarti,nstartj,nendi-nstarti+1,nendj-nstartj+1);
    Myhalcv2::Myfilter(m_tempmatIn,m_filter,&m16_filterIma,Myhalcv2::CCV_16UC1,0,f_center);
    Myhalcv2::MyPoint16to32(tileline.ed,&linepoint32ED);
    Myhalcv2::MyPoint16to32(tileline.st,&linepoint32ST);

    linepoint32ST.x=(linepoint32ST.x>>2);
    linepoint32ST.y=(linepoint32ST.y>>2);
    linepoint32ED.x=(linepoint32ED.x>>2);
    linepoint32ED.y=(linepoint32ED.y>>2);
    imageBry=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff4);
    MyLine(&imageBry,linepoint32ST,linepoint32ED,255,Myhalcv2::CV_LINE_8LT,7);
    m_brygujia=Myhalcv2::MatCreatzero(nHeight,nWidth,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    for(j=nstartj;j<=nendj;j++)
    {
        Uint16 max=0;
        Uint16 maxX=nstarti;
        Uint16 maxXn=0;
        for(i=nstarti;i<=nendi;i++)
        {
            Int32 dj=(j>>2);
            Int32 di=(i>>2);
            if(imageBry.ptr_uchar[dj*imageBry.nWidth+di]!=0&&imageGasu.data[dj*imageGasu.nWidth+di]!=0)
            {
                if(max<m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                {
                    max=m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i];
                    maxXn=1;
                    maxX=i;
                }
                else if(max==m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                {
                    maxXn++;
                    maxX=i+maxX;
                }
            }
        }
        if(maxXn!=0)
        {
            m_brygujia.ptr_uchar[j*m_brygujia.nWidth+(((maxX<<1)/maxXn)>>1)]=255;
        }
    }
    Myhalcv2::MyCutminRoi(m_brygujia,&m_brygujia,Myhalcv2::MHC_CUTMIN_32,nstarti,nstartj,nendi-nstarti+1,nendj-nstartj+1);
    if(linedistance2<5)
        Myhalcv2::Myconnection2(m_brygujia,&ImageConect,10,2,3,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
    else
        Myhalcv2::Myconnection2(m_brygujia,&ImageConect,15,2,3,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
    if(ImageConect.AllMarkPointCount==0)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;
    }
    Myhalcv2::Myhom_conect2d_translate(&ImageConect,&ImageConectlong,nstarti,nstartj,Myhalcv2::MHC_TRANS_OUTIMAGE);
    ImageConectlong.nHeight=imageIn.nHeight;
    ImageConectlong.nWidth=imageIn.nWidth;
    ImageConectlong.startx=imageIn.startx;
    ImageConectlong.starty=imageIn.starty;
    ImageConectlong.height=imageIn.height;
    ImageConectlong.width=imageIn.width;

    for(j=0;j<ImageConectlong.AllMarkPointCount;j++)
    {
      for(i=0;i<ImageConectlong.AllMarkPoint[j].PointArea;i++)
      {
          cv::Point2f point(ImageConectlong.AllMarkPoint[j].point[i].x,ImageConectlong.AllMarkPoint[j].point[i].y);
          pointcloud.push_back(point);
      }
    }

    if(0!=Myhalcv2::MyConect_sqare_line(&ImageConectlong,Myhalcv2::MHC_MIXDIS_SQARE,&tileline,&tilelinehough))
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;
    }
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==17)
    {
      Myhalcv2::MatClone(imageIn,&m_brygujia);
      Myhalcv2::Myregion_to_add(&ImageConectlong,&m_brygujia,0);
      Myhalcv2::MyPoint16to32(tileline.ed,&linepoint32ED);
      Myhalcv2::MyPoint16to32(tileline.st,&linepoint32ST);
      Myhalcv2::MyLine(&m_brygujia,linepoint32ST,linepoint32ED,128,Myhalcv2::CV_LINE_8LT,3);
      Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
      return 0;
    }

    //求得两直线交点
    if(0!=Myhalcv2::MyGetLinefocal(headline,tileline,&resultfocal))
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;
    }
    //下面开始求缝宽
    i32_bryvalue=duanxianerzhi;
    centerj=resultfocal.y;
    centeri=resultfocal.x;
    nstartj=centerj-erzhisize;
    nendj=centerj+erzhisize;
    Myhalcv2::MyGetLineXpos(tileline,nstartj,&tempi);
    nstarti=MIN(tempi,centeri);
    nendi=MAX(tempi,centeri);
    nstarti=nstarti-erzhisize2;
    nendi=nendi+erzhisize2;
    if(centerj<0||centerj>=nHeight||centeri<0||centeri>=nWidth)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;
    }
    if(nstarti<1)
    {
        nstarti=1;
    }
    if(nendi>nWidth-2)
    {
        nendi=nWidth-2;
    }
    if(nstartj<1)
    {
        nstartj=1;
    }
    if(nendj>nHeight-2)
    {
        nendj=nHeight-2;
    }

    Myhalcv2::MyCutminRoi(imageIn,&imageGasu,Myhalcv2::MHC_CUTMIN_32,nstarti-1,nstartj-1,nendi-nstarti+3,nendj-nstartj+3);
    Myhalcv2::Mymedian(imageGasu,&imageGasu);
    Myhalcv2::MyCutselfRoi(&imageGasu,1,1,imageGasu.width-2,imageGasu.height-2);
    Myhalcv2::Mynormalize_lineXY_downvalue(imageGasu,&imageGasu,15,255);
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==18)
    {
      Myhalcv2::MatToCvMat(imageGasu,&cvimgIn);
      return 0;
    }

    /**********/
//断线分割膨胀法
    Myhalcv2::Mybinary(imageGasu,&m_brygujia,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==19)
    {
      Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
      return 0;
    }
    Myhalcv2::Myconnection2(m_brygujia,&ImageConect,50,0,0,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
    Myhalcv2::Myselect_shape(&ImageConect,&ImageConectlong,Myhalcv2::MHC_CONNECT_HEIGHT,20,ImageConect.nHeight);
    if(ImageConectlong.AllMarkPointCount==0)
    {
    #ifdef QUICK_TRANSMIT
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
    #endif
        return 1;
    }
    Myhalcv2::Myregion_to_bin(&ImageConectlong,&m_brygujia,255);
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==20)
    {
      Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
      return 0;
    }

    Myhalcv2::Mydilation_circle2(m_brygujia,&m_brygujia,4,0,Myhalcv2::MHC_MORPH_RECT);
    Myhalcv2::Myconnection(m_brygujia,&ImageConect,1,0,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);
    Myhalcv2::Myregion_to_label(&ImageConect,&m_brygujia);
    imageBry=Myhalcv2::MatCreatzero(nHeight,nWidth,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff4);
    Myhalcv2::MyAddminRoi(imageBry,m_brygujia,&imageGasu,nstarti-1,nstartj-1);
#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "start alg100=%d",debug_alg++);
#endif 
    if(step==21)
    {
      Myhalcv2::Mymat_to_bin(imageGasu,&m_brygujia,255);
      Myhalcv2::MatToCvMat(m_brygujia,&cvimgIn);
      return 0;
    }
    if(b_duanxianmoshi==0)
    {
        Myhalcv2::MyPoint16to32(tileline.ed,&linepoint32ED);
        Myhalcv2::MyPoint16to32(tileline.st,&linepoint32ST);
        Myhalcv2::MyLinetoPoint(imageGasu.nHeight,imageGasu.nWidth,linepoint32ST,linepoint32ED,Myhalcv2::CV_LINE_8LT,1,&Imageheadline,cv8uc1_Imagebuff3);
        resultfocal1.x=resultfocal.x;
        resultfocal1.y=resultfocal.y;
        leijiwrite=0;
        for(t=0;t<Imageheadline.AllMarkPoint[0].PointArea;t++)
        {
            Int32 i=Imageheadline.AllMarkPoint[0].point[t].x;
            Int32 j=Imageheadline.AllMarkPoint[0].point[t].y;
            if(j>resultfocal.y)
            {
                if(imageGasu.data[j*imageGasu.nWidth+i]==0)
                {
                    //开始检测
                    resultfocal1.x=i;
                    resultfocal1.y=j;
                }
                else
                {
                    leijiwrite++;
                }
            }
            if(j>=resultfocal.y+searchdectancemax||leijiwrite>=searchdectancemin)
            {
                break;
            }
        }

        temp_resultfocal1=resultfocal1;
        for(t=0;t<Imageheadline.AllMarkPoint[0].PointArea;t++)
        {
            Int32 i=Imageheadline.AllMarkPoint[0].point[t].x;
            Int32 j=Imageheadline.AllMarkPoint[0].point[t].y;
            if(j>resultfocal1.y)
            {
                temp_resultfocal1.x=i;
                temp_resultfocal1.y=j;
                break;
            }
        }
    }
    else
    {
        Myhalcv2::MyPoint16to32(headline.st,&linepoint32ED);
        Myhalcv2::MyPoint16to32(headline.ed,&linepoint32ST);
        Myhalcv2::MyLinetoPoint(imageGasu.nHeight,imageGasu.nWidth,linepoint32ST,linepoint32ED,Myhalcv2::CV_LINE_8LT,1,&Imageheadline,cv8uc1_Imagebuff3);
        resultfocal1.x=resultfocal.x;
        resultfocal1.y=resultfocal.y;
        leijiwrite=0;
        for(t=0;t<Imageheadline.AllMarkPoint[0].PointArea;t++)
        {
            Int32 i=Imageheadline.AllMarkPoint[0].point[t].x;
            Int32 j=Imageheadline.AllMarkPoint[0].point[t].y;
            if(j<resultfocal.y)
            {
                if(imageGasu.data[j*imageGasu.nWidth+i]==0)
                {
                    //开始检测
                    resultfocal1.x=i;
                    resultfocal1.y=j;
                }
                else
                {
                    leijiwrite++;
                }
            }
            if(j<=resultfocal.y-searchdectancemax||leijiwrite>=searchdectancemin)
            {
                break;
            }
        }
        temp_resultfocal1=resultfocal1;
        for(t=0;t<Imageheadline.AllMarkPoint[0].PointArea;t++)
        {
            Int32 i=Imageheadline.AllMarkPoint[0].point[t].x;
            Int32 j=Imageheadline.AllMarkPoint[0].point[t].y;
            if(j<resultfocal1.y)
            {
                temp_resultfocal1.x=i;
                temp_resultfocal1.y=j;
                break;
            }
        }
    }
    if(b_duanxianmoshi==0)
    {
        Myhalcv2::MyPoint16to32(headline.st,&linepoint32ED);
        Myhalcv2::MyPoint16to32(headline.ed,&linepoint32ST);
        Myhalcv2::MyLinetoPoint(imageGasu.nHeight,imageGasu.nWidth,linepoint32ST,linepoint32ED,Myhalcv2::CV_LINE_8LT,1,&Imageheadline,cv8uc1_Imagebuff3);
        resultfocal2.x=resultfocal.x;
        resultfocal2.y=resultfocal.y;
        leijiwrite=0;
        for(t=0;t<Imageheadline.AllMarkPoint[0].PointArea;t++)
        {
            Int32 i=Imageheadline.AllMarkPoint[0].point[t].x;
            Int32 j=Imageheadline.AllMarkPoint[0].point[t].y;
            if(j<resultfocal.y)
            {
                if(imageGasu.data[j*imageGasu.nWidth+i]==0)
                {
                    //开始检测
                    resultfocal2.x=i;
                    resultfocal2.y=j;
                }
                else
                {
                    leijiwrite++;
                }
            }
            if(j<=resultfocal.y-searchdectancemax||leijiwrite>=searchdectancemin)
            {
                break;
            }
        }
        temp_resultfocal2=resultfocal2;
        for(t=0;t<Imageheadline.AllMarkPoint[0].PointArea;t++)
        {
            Int32 i=Imageheadline.AllMarkPoint[0].point[t].x;
            Int32 j=Imageheadline.AllMarkPoint[0].point[t].y;
            if(j<resultfocal2.y)
            {
                temp_resultfocal2.x=i;
                temp_resultfocal2.y=j;
                break;
            }
        }
    }
    else
    {
        Myhalcv2::MyPoint16to32(tileline.ed,&linepoint32ED);
        Myhalcv2::MyPoint16to32(tileline.st,&linepoint32ST);
        Myhalcv2::MyLinetoPoint(imageGasu.nHeight,imageGasu.nWidth,linepoint32ST,linepoint32ED,Myhalcv2::CV_LINE_8LT,1,&Imageheadline,cv8uc1_Imagebuff3);
        resultfocal2.x=resultfocal.x;
        resultfocal2.y=resultfocal.y;
        leijiwrite=0;
        for(t=0;t<Imageheadline.AllMarkPoint[0].PointArea;t++)
        {
            Int32 i=Imageheadline.AllMarkPoint[0].point[t].x;
            Int32 j=Imageheadline.AllMarkPoint[0].point[t].y;
            if(j>resultfocal.y)
            {
                if(imageGasu.data[j*imageGasu.nWidth+i]==0)
                {
                    //开始检测
                    resultfocal2.x=i;
                    resultfocal2.y=j;
                }
                else
                {
                    leijiwrite++;
                }
            }
            if(j>=resultfocal.y+searchdectancemax||leijiwrite>=searchdectancemin)
            {
                break;
            }
        }
        temp_resultfocal2=resultfocal2;
        for(t=0;t<Imageheadline.AllMarkPoint[0].PointArea;t++)
        {
            Int32 i=Imageheadline.AllMarkPoint[0].point[t].x;
            Int32 j=Imageheadline.AllMarkPoint[0].point[t].y;
            if(j>resultfocal2.y)
            {
                temp_resultfocal2.x=i;
                temp_resultfocal2.y=j;
                break;
            }
        }
    }
    handianEn=1;
    if((resultfocal1.x==resultfocal.x&&resultfocal1.y==resultfocal.y)||
        (resultfocal2.x==resultfocal.x&&resultfocal2.y==resultfocal.y))
    {
        handianEn=0;	//不是焊点
    }
    if(imageGasu.data[temp_resultfocal1.y*imageGasu.nWidth+temp_resultfocal1.x]!=imageGasu.data[temp_resultfocal2.y*imageGasu.nWidth+temp_resultfocal2.x])
    {
        handianEn=0;	//不是焊点
    }
    if(handianEn==0)
    {
        solderjoints=false;
    }
    else
    {
        solderjoints=true;
    }
    Myline16to32(tileline,&tileline32);
    Myline16to32(headline,&headline32);
    if(step==1)
    {
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        if(cvimgIn.type()==CV_8UC1)
        cv::cvtColor(cvimgIn,cvimgIn,cv::COLOR_GRAY2BGR);
        cv_point_st.x=(headline32.st.x>>2);
        cv_point_st.y=(headline32.st.y>>2);
        cv_point_ed.x=(headline32.ed.x>>2);
        cv_point_ed.y=(headline32.ed.y>>2);
        cv::line(cvimgIn,cv_point_st,cv_point_ed,cv::Scalar(255,0,0),1);
        cv_point_st.x=(tileline32.st.x>>2);
        cv_point_st.y=(tileline32.st.y>>2);
        cv_point_ed.x=(tileline32.ed.x>>2);
        cv_point_ed.y=(tileline32.ed.y>>2);
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
    }
    cv_point.x=resultfocal.x;
    cv_point.y=resultfocal.y;
    namepoint.push_back(cv_point);
    cv_point.x=resultfocal1.x;
    cv_point.y=resultfocal1.y;
    namepoint.push_back(cv_point);
    cv_point.x=resultfocal2.x;
    cv_point.y=resultfocal2.y;
    namepoint.push_back(cv_point);

#ifdef DEBUG_ALG;
    RCLCPP_INFO(this->get_logger(), "finish alg100");
#endif 
    
    return 0;
}

}