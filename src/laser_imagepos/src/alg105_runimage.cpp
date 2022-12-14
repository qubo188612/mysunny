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
        if (k < 0 || k > 5000) {
            return -1;}
        else{pm.als105_Updif=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_Updifmin") {
        auto k = p.as_int();
        if (k < -2000 || k > 2000) {
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
        if (k < -5000 || k > 0) {
            return -1;}
        else{pm.als105_Downdif=p.as_int();
            return 1;}}
    else if(p.get_name() == "als105_Downdifmin") {
        auto k = p.as_int();
        if (k < -255 || k > 255) {
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
        if (k < 0 || k >= 2048) {
            return -1;}
        else{pm.als105_cutleft=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als105_cutright") {
        auto k = p.as_int();
        if (k < 0 || k >= 2048) {
            return -1;}
        else{pm.als105_cutright=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als105_cuttop") {
        auto k = p.as_int();
        if (k < 0 || k >= 3072) {
            return -1;}
        else{pm.als105_cuttop=p.as_int();
            return 1;}} 
    else if(p.get_name() == "als105_cutdeep") {
        auto k = p.as_int();
        if (k < 0 || k >= 3072) {
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

    return 0;
}

int LaserImagePos::alg105_runimage( cv::Mat &cvimgIn,
                                    std::vector <cv::Point2f> &pointcloud,
                                    std::vector <cv::Point2f> &namepoint,
                                    bool &solderjoints,
                                    int step)    //?????????????????????
{
    Int32 i,j,n;
    Int32 filenum=0,asfilenum=0;
    Myhalcv2::Mat imageIn,imageGasu,imageGasupain,imageBry,m_tempmatIn,m_matMask;
    Myhalcv2::Mat m_brygujia;
    Int32 nWidth=cvimgIn.cols;	//???????????????
    Int32 nHeight=cvimgIn.rows;	//???????????????
    Uint8 bryvalue;
    Int32 i32_bryvalue;
    Int16 filterdata2[40];

    Myhalcv2::L_Point32 f_center={-1,-1};
    Int32 X_Linestarty=0;
    Int32 X_Lineendy=0;
    Myhalcv2::Mat i32_mXline,m_filter2,m32_filterIma;
    Int32 zhengshunum=0;
    Myhalcv2::L_Point32 stepfindST,stepfindED;//?????????1????????????,(??????)
    Myhalcv2::L_Point32 midfindST,midfindED;//?????????2????????????,(??????)
    Int32 latsj,latsi;
    Int32 nihenum=0;
    Myhalcv2::L_Point32 linepoint32ST,linepoint32ED;
    Myhalcv2::L_line tileline;	//?????????2??????????????????,(??????)
    Myhalcv2::L_line headline;	//?????????1??????????????????,(??????)
    Myhalcv2::L_Point32 resultfocal1,resultfocal,resultfocal2;//??????
    Int32 jiguangTop,jiguangDeep,jiguangLeft,jiguangRight;
    Myhalcv2::MyConect ImageConect,ImageConectlong,ImageConectlongPX;
    Myhalcv2::houghlineinfo headlinehough,tilelinehough;
    cv::Point cv_point_st,cv_point_ed,cv_point;
    Int32 nstarti,nendi,nstartj,nendj;

    Myhalcv2::L_Point32F faxian;

    /*********************/
    //????????????
    Int32 pingjun=pm.als105_pingjun;//????????????
    Int32 b_yanmofuzhu=pm.als105_b_yanmofuzhu;//????????????????????????
    Int32 widthliantongdis=pm.als105_widthliantongdis;//????????????????????????
    Int32 highliantongdis=pm.als105_highliantongdis;//????????????????????????
    Int32 gujiaerzhi=pm.als105_gujiaerzhi;//??????????????????
    Int32 jiguanghight=pm.als105_jiguanghight;//????????????????????????
    Int32 jiguanglong=pm.als105_jiguanglong;//????????????????????????
    Int32 jiguangkuandu=pm.als105_jiguangkuandu;//????????????
    Int32 b_cut=pm.als105_b_cut;                  //????????????????????????
    Int32 cutleft=pm.als105_cutleft;                //????????????
    Int32 cutright=pm.als105_cutright;        //????????????
    Int32 cuttop=pm.als105_cuttop;                 //????????????
    Int32 cutdeep=pm.als105_cutdeep;        //????????????
    Int32 guaidianyuzhi=pm.als105_guaidianyuzhi;//????????????
    Int32 Downdifmin=pm.als105_Downdifmin;       //????????????????????????????????????
    Int32 Downdif=pm.als105_Downdif;      //????????????????????????????????????   //Downdif
    Int32 Updifmin=pm.als105_Updifmin;          //????????????????????????????????????     //Updifmin
    Int32 Updif=pm.als105_Updif;  //????????????????????????????????????//Updif
    Int32 dis_center_st=pm.als105_dis_center_st;     //???????????????????????????????????? //dis_center_st
    Int32 dis_center_ed=pm.als105_dis_center_ed;//???????????????????????????????????? //dis_center_st2
    Int32 Uplong=pm.als105_Uplong;//?????????????????????   //??????200???????????????????????????????????????
    Int32 Downdlong=pm.als105_Downdlong;//?????????????????????
    Int32 duandianjuli=pm.als105_duandianjuli;  //????????????????????????
    Int32 b_dibufaxiangliang=pm.als105_b_dibufaxiangliang;//????????????????????????????????????
    
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
    i32_bryvalue=(Int32)bryvalue+pingjun;//???????????????????????????
    Myhalcv2::Mybinary(imageBry,&imageBry,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
    if(step==5)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    if(b_yanmofuzhu==1)
    {
        m_matMask=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff1);
        Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//??????8????????????ImageConect,????????????120,?????????????????????2??????????????????
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

    if(step==8)
    {
        Myhalcv2::Mymat_to_binself(&imageBry,255);
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }      

    Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//??????8????????????ImageConect,????????????120,?????????????????????2??????????????????
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
    Myhalcv2::MyCutRoi(imageGasu,&m_tempmatIn,Myhalcv2::MHC_CUT_NOTCOPY,jiguangLeft,jiguangTop,jiguangRight-jiguangLeft+1,jiguangDeep-jiguangTop+1);
    Myhalcv2::Mynormalize_lineXY(m_tempmatIn,&imageBry,1);
    if(step==9)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    i32_bryvalue=gujiaerzhi;//???????????????????????????
    Myhalcv2::Mybinary(imageBry,&imageBry,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
    if(step==10)
    {
        Myhalcv2::MatToCvMat(imageBry,&cvimgIn);
        return 0;
    }
    Myhalcv2::Myconnection2(imageBry,&ImageConect,jiguanghight,widthliantongdis,highliantongdis,Myhalcv2::MHC_MORPH_RECT,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//??????8????????????ImageConect,????????????120,?????????????????????2??????????????????
    Myhalcv2::Myselect_shape(&ImageConect,&ImageConectlong,Myhalcv2::MHC_CONNECT_WIDTH_HEIGHT,jiguanglong,MAX(ImageConect.nHeight,ImageConect.nWidth));//???ImageConect????????????????????????50????????????
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
    //???????????????????????????????????????,?????????????????????
    //???????????????????????????
    memset(X_line,0,sizeof(Int32)*nHeight);
    memset(X_lineMark,0,nHeight);

    X_Linestarty=0;
    X_Lineendy=0;

    if(step==13)
    {
        Myhalcv2::MatClone(imageIn,&imageGasupain);
    }
    //?????????
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
                X_Linestarty=j;//????????????
            }
            X_Lineendy=j;//????????????
            X_lineMark[j]=1;

            cv::Point2f point(p,j);
            pointcloud.push_back(point);
        }
        if(step==13)
        {
            if(sum_value!=0)
            {
                imageGasupain.data[j*imageGasupain.nWidth+X_line[j]]=0;
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
    Myhalcv2::Myfixdata(X_line,X_lineMark,nHeight);//???????????????
    if(step==14)
    {
        Myhalcv2::MatClone(imageIn,&imageGasupain);
        for(j=m_tempmatIn.starty;j<m_tempmatIn.starty+m_tempmatIn.height;j++)
        {
            imageGasupain.data[j*imageGasupain.nWidth+(Int32)X_line[j]]=0;
        }
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }

    i32_mXline=Myhalcv2::MatCreat(1,nHeight,Myhalcv2::CCV_32SC1,X_line);//????????????
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
    Myhalcv2::Myfilter(i32_mXline,m_filter2,&m32_filterIma,Myhalcv2::CCV_32SC1,0,f_center);//????????????

    //??????????????????
    zhengshunum=-1;
    latsj=0;
    if(b_cut==0)
    {
        for(j=X_Linestarty+24;j<=X_Lineendy-24;j++)
        {
            if(zhengshunum<abs(m32_filterIma.ptr_int[j]))
            {
                zhengshunum=abs(m32_filterIma.ptr_int[j]);
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
            if(zhengshunum<abs(m32_filterIma.ptr_int[j]))
            {
                zhengshunum=abs(m32_filterIma.ptr_int[j]);
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
    if(step==15)
    {
        Myhalcv2::MatClone(imageIn,&imageGasupain);
        for(j=m_tempmatIn.starty;j<m_tempmatIn.starty+m_tempmatIn.height;j++)
        {
            imageGasupain.data[j*imageGasupain.nWidth+(Int32)X_line[j]]=0;
        }
        linepoint32ST.x=latsi;
        linepoint32ST.y=latsj;
        Myhalcv2::MyCircle(&imageGasupain,linepoint32ST,15,128,Myhalcv2::CV_CLRCLE_UNFILL);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    //????????????
    nstartj=MAX(X_Linestarty+24,latsj-dis_center_ed);
    nendj=MAX(X_Linestarty+24,latsj-dis_center_st);
    nstarti=X_line[nstartj];
    nendi=X_line[nendj];

    m_brygujia=Myhalcv2::MatCreatzero(3,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);  //????????????????????????

    for(j=nstartj;j<=nendj;j++)
    {
        if(m32_filterIma.ptr_int[j]>=Updifmin&&m32_filterIma.ptr_int[j]<=Updif)
        {
            m_brygujia.data[1*m_brygujia.nWidth+j]=255;
        }
    }
    if(step==16)
    {
        Myhalcv2::MatClone(imageIn,&imageGasupain);
        for(j=nstartj;j<=nendj;j++)
        {
            if( m_brygujia.data[1*m_brygujia.nWidth+j]!=0)
            {
                imageGasupain.data[j*imageGasupain.nWidth+X_line[j]]=128;
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
    if(step==17)
    {
        Myhalcv2::MatClone(imageIn,&imageGasupain);
        for(j=nstartj;j<=nendj;j++)
        {
            if( m_brygujia.data[1*m_brygujia.nWidth+j]!=0)
            {
                imageGasupain.data[j*imageGasupain.nWidth+X_line[j]]=128;
            }
        }
        Myhalcv2::MyCircle(&imageGasupain,stepfindST,15,128,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyCircle(&imageGasupain,stepfindED,15,128,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyPoint16to32(headline.st,&linepoint32ST);
        Myhalcv2::MyPoint16to32(headline.ed,&linepoint32ED);
        Myhalcv2::MyLine(&imageGasupain,linepoint32ST,linepoint32ED,255,Myhalcv2::CV_LINE_8LT,1);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    //????????????
    nstartj=MIN(X_Lineendy-24,latsj+dis_center_st);
    nendj=MIN(X_Lineendy-24,latsj+dis_center_ed);
    nstarti=X_line[nstartj];
    nendi=X_line[nendj];

    m_brygujia=Myhalcv2::MatCreatzero(3,nHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);  //????????????????????????

    for(j=nstartj;j<=nendj;j++)
    {
        if(m32_filterIma.ptr_int[j]>=Downdifmin&&m32_filterIma.ptr_int[j]<=Downdif)
        {
            m_brygujia.data[1*m_brygujia.nWidth+j]=255;
        }
    }
    if(step==18)
    {
        Myhalcv2::MatClone(imageIn,&imageGasupain);
        for(j=nstartj;j<=nendj;j++)
        {
            if( m_brygujia.data[1*m_brygujia.nWidth+j]!=0)
            {
                imageGasupain.data[j*imageGasupain.nWidth+X_line[j]]=128;
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
    if(step==19)
    {
        Myhalcv2::MatClone(imageIn,&imageGasupain);
        for(j=nstartj;j<=nendj;j++)
        {
            if( m_brygujia.data[1*m_brygujia.nWidth+j]!=0)
            {
                imageGasupain.data[j*imageGasupain.nWidth+X_line[j]]=128;
            }
        }
        Myhalcv2::MyCircle(&imageGasupain,midfindST,15,128,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyCircle(&imageGasupain,midfindED,15,128,Myhalcv2::CV_CLRCLE_FILL);
        Myhalcv2::MyPoint16to32(tileline.st,&linepoint32ST);
        Myhalcv2::MyPoint16to32(tileline.ed,&linepoint32ED);
        Myhalcv2::MyLine(&imageGasupain,linepoint32ST,linepoint32ED,255,Myhalcv2::CV_LINE_8LT,1);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }

    //??????????????????
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
    if(step==21)
    {
        Myhalcv2::MatClone(imageIn,&imageGasupain);
        Myhalcv2::MyCircle(&imageGasupain,resultfocal1,15,128,Myhalcv2::CV_CLRCLE_UNFILL);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }

    //??????????????????
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
    if(step==23)
    {
        Myhalcv2::MatClone(imageIn,&imageGasupain);
        Myhalcv2::MyCircle(&imageGasupain,resultfocal2,15,128,Myhalcv2::CV_CLRCLE_UNFILL);
        Myhalcv2::MatToCvMat(imageGasupain,&cvimgIn);
        return 0;
    }
    //???????????????????????????
    if(b_dibufaxiangliang==1)
    {
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
    }
    else
    {
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
    }

    resultfocal.x=(resultfocal2.x+resultfocal1.x)/2;
    resultfocal.y=(resultfocal2.y+resultfocal1.y)/2;

    if(step==1)
    {
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
        if(b_cut==1)
        {
            cv::Point p1(cutleft>>2,cuttop>>2);
            cv::Point p2(cutright>>2,cutdeep>>2);
            cv::rectangle(cvimgIn,p1,p2,cv::Scalar(255,255,255));
        }
        faxian.x=faxian.x*1000+resultfocal.x;
        faxian.y=faxian.y*1000+resultfocal.y;
        cv_point_st.x=(resultfocal.x>>2);
        cv_point_st.y=(resultfocal.y>>2);
        cv_point_ed.x=(faxian.x/4);
        cv_point_ed.y=(faxian.y/4);
        cv::line(cvimgIn,cv_point_st,cv_point_ed,cv::Scalar(255,255,0),1);
    }
   
    solderjoints=false;
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