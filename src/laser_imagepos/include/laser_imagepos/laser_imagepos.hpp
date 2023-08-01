#ifndef LASER_LINE_IMAGEPOS__LASER_LINE_IMAGEPOS_HPP_
#define LASER_LINE_IMAGEPOS__LASER_LINE_IMAGEPOS_HPP_

#include <deque>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "tutorial_interfaces/msg/if_algorhmitmsg.hpp"
#include "tutorial_interfaces/msg/if_algorhmitimage.hpp"
#include "tutorial_interfaces/msg/if_algorhmitrobpos.hpp"
#include "myhalcv2/myhalcv2.h"
#include "unistd.h"
#include <time.h>

//#define DEBUG_ALG       //输出算法步骤
#define QUICK_TRANSMIT    //快速传输

#define E2POOM_ALG102_LASERIMAGEPOS_DIMIANPINGJUNSHUNUM_MAX         500

#define PIC_IMAGE_HEIGHT 1536
#define PIC_IMAGE_WIDTH  1024

class Targetpoint
{
public:
  cv::Point2f pointf;
  std::string name;
};

namespace laser_imagepos
{

using tutorial_interfaces::msg::IfAlgorhmitimage;
using sensor_msgs::msg::PointCloud2;
using tutorial_interfaces::msg::IfAlgorhmitmsg;


const std::vector<std::string> KEYS = {"task_num","show_step","start"};

const std::vector<std::string> KEYS_ALS100 = {"als100_exposure_time",
                                              "als100_pingjun",
                                              "als100_b_yanmofuzhu",
                                              "als100_b_gudingquyu",
                                              "als100_widthliantongdis",
                                              "als100_highliantongdis",
                                              "als100_gujiaerzhi",
                                              "als100_jiguanghight",
                                              "als100_jiguanglong",
                                              "als100_jiguangkuandu",
                                              "als100_Updif",
                                              "als100_Updifmin",
                                              "als100_Uplong",
                                              "als100_Downdif",
                                              "als100_Downdifmin",
                                              "als100_Downdlong",
                                              "als100_duanxianerzhi",
                                              "als100_erzhisize",
                                              "als100_erzhisize2",
                                              "als100_searchdectancemax",
                                              "als100_searchdectancemin",
                                              "als100_dis_center_st",
                                              "als100_dis_center_ed",
                                              "als100_answerpoint",
                                              "als100_b_KalmanFilter",
                                              "als100_KalmanQF",
                                              "als100_KalmanRF",
                                              "als100_b_cut",
                                              "als100_cutleft",
                                              "als100_cutright",
                                              "als100_cuttop",
                                              "als100_cutdeep"};

const std::vector<std::string> KEYS_ALS101 = {"als101_exposure_time",
                                              "als101_pingjun",
                                              "als101_b_yanmofuzhu",
                                              "als101_b_gudingquyu",
                                              "als101_widthliantongdis",
                                              "als101_highliantongdis",
                                              "als101_gujiaerzhi",
                                              "als101_jiguanghight",
                                              "als101_jiguanglong",
                                              "als101_jiguangkuandu",
                                              "als101_Updif",
                                              "als101_Updifmin",
                                              "als101_Uplong",
                                              "als101_Downdif",
                                              "als101_Downdifmin",
                                              "als101_Downdlong",
                                              "als101_duanxianerzhi",
                                              "als101_erzhisize",
                                              "als101_erzhisize2",
                                              "als101_searchdectancemax",
                                              "als101_searchdectancemin",
                                              "als101_dis_center_st",
                                              "als101_dis_center_ed",
                                              "als101_answerpoint",
                                              "als101_b_KalmanFilter",
                                              "als101_KalmanQF",
                                              "als101_KalmanRF",
                                              "als101_b_cut",
                                              "als101_cutleft",
                                              "als101_cutright",
                                              "als101_cuttop",
                                              "als101_cutdeep"};

const std::vector<std::string> KEYS_ALS102 = {"als102_exposure_time",
                                              "als102_pingjun",
                                              "als102_b_yanmofuzhu",
                                              "als102_b_gudingquyu",
                                              "als102_widthliantongdis",
                                              "als102_highliantongdis",
                                              "als102_gujiaerzhi",
                                              "als102_jiguanghight",
                                              "als102_jiguanglong",
                                              "als102_jiguangkuandu",
                                              "als102_Updif",
                                              "als102_Updifmin",
                                              "als102_Uplong",
                                              "als102_Downdif",
                                              "als102_Downdifmin",
                                              "als102_Downdlong",
                                              "als102_St_Down",
                                              "als102_Ed_Down",
                                              "als102_St_Up",
                                              "als102_Ed_Up",
                                              "als102_Updif2",
                                              "als102_Updifmin2",
                                              "als102_dis_center_st",
                                              "als102_dis_center_ed",
                                              "als102_b_opengudingdimian",
                                              "als102_dimianpangdingjuli",
                                              "als102_dimianpingjunshunum",
                                              "als102_dis_center_st2",
                                              "als102_dis_center_ed2",
                                              "als102_dis_center_st3",
                                              "als102_dis_center_ed3",
                                              "als102_xuexijuli",
                                              "als102_b_pingpowending",
                                              "als102_pingpowending_dis",
                                              "als102_b_xielvopen",
                                              "als102_xielvfanwei",
                                              "als102_Uplong2",
                                              "als102_cebankongdongdis",
                                              "als102_qiatouquweijuli",
                                              "als102_answerpoint",
                                              "als102_b_KalmanFilter",
                                              "als102_KalmanQF",
                                              "als102_KalmanRF"};

const std::vector<std::string> KEYS_ALS103 = {"als103_exposure_time",
                                              "als103_pingjun",
                                              "als103_gujiaerzhi",
                                              "als103_widthliantongdis",
                                              "als103_highliantongdis",
                                              "als103_jiguanglong",
                                              "als103_jiguangkuandu",
                                              "als103_jiguangduibidu",
                                              "als103_lvbomod"};

const std::vector<std::string> KEYS_ALS104 = {"als104_exposure_time",
                                              "als104_pingjun",
                                              "als104_b_yanmofuzhu",
                                              "als104_b_gudingquyu",
                                              "als104_widthliantongdis",
                                              "als104_highliantongdis",
                                              "als104_gujiaerzhi",
                                              "als104_jiguanghight",
                                              "als104_jiguanglong",
                                              "als104_jiguangkuandu",
                                              "als104_Updif",
                                              "als104_Updifmin",
                                              "als104_Uplong",
                                              "als104_Downdif",
                                              "als104_Downdifmin",
                                              "als104_Downdlong",
                                              "als104_dis_center_st",
                                              "als104_dis_center_ed",
                                              "als104_b_KalmanFilter",
                                              "als104_KalmanQF",
                                              "als104_KalmanRF"};

const std::vector<std::string> KEYS_ALS105 = {"als105_exposure_time",
                                              "als105_pingjun",
                                              "als105_b_yanmofuzhu",
                                              "als105_widthliantongdis",
                                              "als105_highliantongdis",
                                              "als105_gujiaerzhi",
                                              "als105_jiguanghight",
                                              "als105_jiguanglong",
                                              "als105_jiguangkuandu",
                                              "als105_b_cut",
                                              "als105_cutleft",
                                              "als105_cutright",
                                              "als105_cuttop",
                                              "als105_cutdeep",
                                              "als105_guaidianyuzhi",
                                              "als105_Downdifmin",
                                              "als105_Downdif",
                                              "als105_Updifmin",
                                              "als105_Updif",
                                              "als105_dis_center_st",
                                              "als105_dis_center_ed",
                                              "als105_Uplong",
                                              "als105_Downdlong",
                                              "als105_duandianjuli",
                                              "als105_b_dibufaxiangliang",
                                              "als105_answerpoint",
                                              "als105_usedownliantong",
                                              "als105_b_KalmanFilter",
                                              "als105_KalmanQF",
                                              "als105_KalmanRF",
                                              "als105_cutside_Up",
                                              "als105_cutside_Down",
                                              "als105_b_erjiedao",
                                              "als105_b_quxian"};

const std::vector<std::string> KEYS_ALS106 = {"als106_exposure_time",
                                              "als106_pingjun",
                                              "als106_b_yanmofuzhu",
                                              "als106_widthliantongdis",
                                              "als106_highliantongdis",
                                              "als106_gujiaerzhi",
                                              "als106_jiguanghight",
                                              "als106_jiguanglong",
                                              "als106_jiguangkuandu",
                                              "als106_b_cut",
                                              "als106_cutleft",
                                              "als106_cutright",
                                              "als106_cuttop",
                                              "als106_cutdeep",
                                              "als106_difmin",
                                              "als106_Sidelong",
                                              "als106_Upback_st",
                                              "als106_Upback_ed",
                                              "als106_Downback_st",
                                              "als106_Downback_ed",
                                              "als106_Upmindis",
                                              "als106_Downmindis",
                                              "als106_Uplong",
                                              "als106_Downdlong",
                                              "als106_dis_center_ed",
                                              "als106_duandianjuli",
                                              "als106_pokoumod",
                                              "als106_pokouUpdif",
                                              "als106_pokouUpdifmin",
                                              "als106_pokouUpback_st",
                                              "als106_pokouUpback_ed",
                                              "als106_pokouDowndif",
                                              "als106_pokouDowndifmin",
                                              "als106_pokouDownback_st",
                                              "als106_pokouDownback_ed",
                                              "als106_pokouUplong",
                                              "als106_pokouDownlong",
                                              "als106_b_pokouyaobian",
                                              "als106_pokouyaobianHsize",
                                              "als106_pokouduanxianerzhi",
                                              "als106_pokousearchdectancemax",
                                              "als106_pokousearchdectancemin",
                                              "als106_answerpoint",
                                              "als106_b_KalmanFilter",
                                              "als106_KalmanQF",
                                              "als106_KalmanRF"};

const std::vector<std::string> KEYS_ALS107 = {"als107_exposure_time",
                                              "als107_pingjun",
                                              "als107_b_yanmofuzhu",
                                              "als107_b_gudingquyu",
                                              "als107_widthliantongdis",
                                              "als107_highliantongdis",
                                              "als107_gujiaerzhi",
                                              "als107_jiguanghight",
                                              "als107_jiguanglong",
                                              "als107_jiguangkuandu",
                                              "als107_Updif",
                                              "als107_Updifmin",
                                              "als107_Uplong",
                                              "als107_Downdif",
                                              "als107_Downdifmin",
                                              "als107_Downdlong",
                                              "als107_St_Down",
                                              "als107_Ed_Down",
                                              "als107_St_Up",
                                              "als107_Ed_Up",
                                              "als107_dis_center_st",
                                              "als107_dis_center_st2",
                                              "als107_dis_center_ed2",
                                              "als107_b_KalmanFilter",
                                              "als107_KalmanQF",
                                              "als107_KalmanRF"};

const std::vector<std::string> KEYS_ALS108 = {"als108_exposure_time",
                                              "als108_center_x",
                                              "als108_center_y",  
                                              "als108_search_w",  
                                              "als108_search_h",
                                              "als108_STC_alpha",
                                              "als108_STC_beta",  
                                              "als108_STC_rho",
                                              "als108_STC_sigma"};
                                              
/**
 * @brief To zip related parameters together.
 *
 */
struct Params
{
/********************************/
//算法100参数
  int als100_exposure_time = 10000;//曝光值
  int als100_pingjun = 15;  //二值阈值
  int als100_b_yanmofuzhu=1;//是否使用掩摸辅助
  int als100_b_gudingquyu=0;//是否固定区域
  int als100_widthliantongdis=2;//激光宽度连通距离
  int als100_highliantongdis=15;//激光长度连通距离
  int als100_gujiaerzhi=160;//找骨架二值图
  int als100_jiguanghight=50;//整体激光最短长度
  int als100_jiguanglong=20;//单边激光最短长度
  int als100_jiguangkuandu=4;//激光粗细
  int als100_Updif=0;//上半段倾斜开始斜度10
  int als100_Updifmin=-5;//上半段倾斜终止斜度10
  int als100_Uplong=5;//上半段直线长度
  int als100_Downdif=0;//下半段倾斜开始斜度0
  int als100_Downdifmin=5;//下半段倾斜终止斜度0
  int als100_Downdlong=5;//下半段直线长度
  int als100_duanxianerzhi=180;//找断线的二值阈值
  int als100_erzhisize=150;//断线二值图的上下阈值尺寸
  int als100_erzhisize2=60;//断线二值图的左右阈值尺寸
  int als100_searchdectancemax=160;//搜寻焊缝端点距离中央凹槽最远的距离
  int als100_searchdectancemin=25;//搜寻焊缝端点距离中央凹槽最近的距离
  int als100_dis_center_st=0;//距离中心点此处后开始统计
  int als100_dis_center_ed=500;  //距离中心点此处后停止统计
  int als100_answerpoint=0;//优先采用点序号
  int als100_b_KalmanFilter=1;//是否使用卡尔曼滤波
  int als100_KalmanQF=10;
  int als100_KalmanRF=50;
  int als100_b_cut=0;                  //是否使用搜索区域
  int als100_cutleft=0;                //搜索区域
  int als100_cutright=PIC_IMAGE_WIDTH-1;           //搜索区域
  int als100_cuttop=0;                 //搜索区域
  int als100_cutdeep=PIC_IMAGE_HEIGHT-1;           //搜索区域
/************************************/
//算法101参数
  int als101_exposure_time = 10000;//曝光值
  int als101_pingjun = 15;  //二值阈值
  int als101_b_yanmofuzhu=1;//是否使用掩摸辅助
  int als101_b_gudingquyu=0;//是否固定区域
  int als101_widthliantongdis=2;//激光宽度连通距离
  int als101_highliantongdis=15;//激光长度连通距离
  int als101_gujiaerzhi=160;//找骨架二值图
  int als101_jiguanghight=50;//整体激光最短长度
  int als101_jiguanglong=20;//单边激光最短长度
  int als101_jiguangkuandu=4;//激光粗细
  int als101_Updif=0;//上半段倾斜开始斜度10
  int als101_Updifmin=-5;//上半段倾斜终止斜度10
  int als101_Uplong=5;//上半段直线长度
  int als101_Downdif=0;//下半段倾斜开始斜度0
  int als101_Downdifmin=5;//下半段倾斜终止斜度0
  int als101_Downdlong=5;//下半段直线长度
  int als101_duanxianerzhi=180;//找断线的二值阈值
  int als101_erzhisize=150;//断线二值图的上下阈值尺寸
  int als101_erzhisize2=60;//断线二值图的左右阈值尺寸
  int als101_searchdectancemax=160;//搜寻焊缝端点距离中央凹槽最远的距离
  int als101_searchdectancemin=25;//搜寻焊缝端点距离中央凹槽最近的距离
  int als101_dis_center_st=0;//距离中心点此处后开始统计
  int als101_dis_center_ed=500;  //距离中心点此处后停止统计
  int als101_answerpoint=0;//优先采用点序号
  int als101_b_KalmanFilter=1;//是否使用卡尔曼滤波
  int als101_KalmanQF=10;
  int als101_KalmanRF=50;
  int als101_b_cut=0;                  //是否使用搜索区域
  int als101_cutleft=0;                //搜索区域
  int als101_cutright=PIC_IMAGE_WIDTH-1;           //搜索区域
  int als101_cuttop=0;                 //搜索区域
  int als101_cutdeep=PIC_IMAGE_HEIGHT-1;           //搜索区域
/************************************/
//算法102参数
  int als102_exposure_time=10000;//曝光值
  int als102_pingjun=15;//二值阈值
  int als102_b_yanmofuzhu=1;//是否使用掩摸辅助
  int als102_b_gudingquyu=0;//是否固定区域
  int als102_widthliantongdis=5;//激光宽度连通距离
  int als102_highliantongdis=15;//激光长度连通距离
  int als102_gujiaerzhi=160;//找骨架二值图
  int als102_jiguanghight=50;//整体激光最短长度
  int als102_jiguanglong=20;//单边激光最短长度
  int als102_jiguangkuandu=6;//激光粗细
  int als102_Updif=2000;//上半段倾斜开始斜度10
  int als102_Updifmin=-20;//上半段倾斜终止斜度10
  int als102_Uplong=20;//上半段直线长度
  int als102_Downdif=-2000;//下半段倾斜开始斜度0
  int als102_Downdifmin=5;//下半段倾斜终止斜度0
  int als102_Downdlong=50;//下半段直线长度
  int als102_St_Down=5;//下半段拟合起点
  int als102_Ed_Down=200;//下半段拟合终点
  int als102_St_Up=5;//上半段拟合起点
  int als102_Ed_Up=200;//上半段拟合终点
  int als102_Updif2=160;//上半段倾斜开始斜度10
  int als102_Updifmin2=-5;//上半段倾斜终止斜度10
  int als102_dis_center_st=50;     //距离中心点此处后开始统计
  int als102_dis_center_ed=120;  //距离中心点此处后停止统计
  int als102_b_opengudingdimian=1; //是否固定底面
  int als102_dimianpangdingjuli=30;//两直线平面距离
  int als102_dimianpingjunshunum=30;//底面平均数统计个数//10
  int als102_dis_center_st2=20;//5;//0;     //距离中心点此处后开始统计
  int als102_dis_center_ed2=150;//100;//30;  //距离中心点此处后停止统计
  int als102_dis_center_st3=150;//5;//0;     //距离中心点此处后开始统计
  int als102_dis_center_ed3=500;//500;//30;  //距离中心点此处后停止统计
  int als102_xuexijuli=200;//学习距离
  int als102_b_pingpowending=1;//平坡处稳定焊点
  int als102_pingpowending_dis=4;//平坡处稳定距离
  int als102_b_xielvopen=1;//斜率限制
  int als102_xielvfanwei=10;//斜率范围
  int als102_Uplong2=60;//在坡度时上半段直线检测长度
  int als102_cebankongdongdis=180;//侧板跨孔洞的激光最短距离
  int als102_qiatouquweijuli=0;//恰头去尾距离
  int als102_answerpoint=0;//优先采用点序号
  int als102_b_KalmanFilter=1;//是否使用卡尔曼滤波
  int als102_KalmanQF=10;
  int als102_KalmanRF=50;
/************************************/
//算法103参数
  int als103_exposure_time=10000;//曝光值
  int als103_pingjun=15;
  int als103_gujiaerzhi=160;
  int als103_widthliantongdis=5;
  int als103_highliantongdis=5;
  int als103_jiguanglong=5;//激光长度
  int als103_jiguangkuandu=10;//激光宽度
  int als103_jiguangduibidu=5;//
  int als103_lvbomod=0;
/************************************/
//算法104参数
  int als104_exposure_time = 10000;//曝光值
  int als104_pingjun = 15;  //二值阈值
  int als104_b_yanmofuzhu=1;//是否使用掩摸辅助
  int als104_b_gudingquyu=0;//是否固定区域
  int als104_widthliantongdis=2;//激光宽度连通距离
  int als104_highliantongdis=15;//激光长度连通距离
  int als104_gujiaerzhi=160;//找骨架二值图
  int als104_jiguanghight=50;//整体激光最短长度
  int als104_jiguanglong=20;//单边激光最短长度
  int als104_jiguangkuandu=4;//激光粗细
  int als104_Updif=0;//上半段倾斜开始斜度10
  int als104_Updifmin=-5;//上半段倾斜终止斜度10
  int als104_Uplong=5;//上半段直线长度
  int als104_Downdif=0;//下半段倾斜开始斜度0
  int als104_Downdifmin=5;//下半段倾斜终止斜度0
  int als104_Downdlong=5;//下半段直线长度
  int als104_dis_center_st=0;//距离中心点此处后开始统计
  int als104_dis_center_ed=500;  //距离中心点此处后停止统计
  int als104_b_KalmanFilter=1;//是否使用卡尔曼滤波
  int als104_KalmanQF=10;
  int als104_KalmanRF=50;
/************************************/
//算法105参数
  int als105_exposure_time=10000;//曝光值
  int als105_pingjun=15;//二值阈值
  int als105_b_yanmofuzhu=1;//是否使用掩摸辅助
  int als105_widthliantongdis=5;//激光宽度连通距离
  int als105_highliantongdis=15;//激光长度连通距离
  int als105_gujiaerzhi=160;//找骨架二值图
  int als105_jiguanghight=50;//整体激光最短长度
  int als105_jiguanglong=20;//单边激光最短长度
  int als105_jiguangkuandu=6;//激光粗细
  int als105_b_cut=0;                  //是否使用搜索区域
  int als105_cutleft=0;                //搜索区域
  int als105_cutright=PIC_IMAGE_WIDTH-1;           //搜索区域
  int als105_cuttop=0;                 //搜索区域
  int als105_cutdeep=PIC_IMAGE_HEIGHT-1;           //搜索区域
  int als105_guaidianyuzhi=60;//拐点阈值
  int als105_Downdifmin=-50;       //下半段直线斜率限制最大值
  int als105_Downdif=50;      //下半段直线斜率限制最小值   //Downdif
  int als105_Updifmin=-50;          //上半段直线斜率限制最小值     //Updifmin
  int als105_Updif=50;  //上半段直线斜率限制最大值//Updif
  int als105_dis_center_st=20;     //距离中心点此处后开始统计 //dis_center_st
  int als105_dis_center_ed=120;//距离中心点此处后停止统计 //dis_center_st2
  int als105_Uplong=50;//上半段直线长度   //设为200时将直接用拟合数据跟踪坡顶
  int als105_Downdlong=50;//下半段直线长度
  int als105_duandianjuli=30;  //断点向前搜索距离
  int als105_b_dibufaxiangliang=1;//是否采用底部平面的法向量
  int als105_answerpoint=0;//优先采用点序号
  int als105_usedownliantong=0;//是否使用最底部连通
  int als105_b_KalmanFilter=1;//是否使用卡尔曼滤波
  int als105_KalmanQF=10;
  int als105_KalmanRF=50;
  int als105_cutside_Up=100;
  int als105_cutside_Down=100;
  int als105_b_erjiedao=1;//是否开启二阶导
  int als105_b_quxian=1;

/************************************/
//算法106参数
  int als106_exposure_time=10000;//曝光值
  int als106_pingjun=15;//二值阈值
  int als106_b_yanmofuzhu=1;//是否使用掩摸辅助
  int als106_b_gudingquyu=0;//是否固定区域
  int als106_widthliantongdis=5;//激光宽度连通距离
  int als106_highliantongdis=15;//激光长度连通距离
  int als106_gujiaerzhi=160;//找骨架二值图
  int als106_jiguanghight=50;//整体激光最短长度
  int als106_jiguanglong=20;//单边激光最短长度
  int als106_jiguangkuandu=6;//激光粗细
  int als106_b_cut=0;                  //是否使用搜索区域
  int als106_cutleft=0;                //搜索区域
  int als106_cutright=PIC_IMAGE_WIDTH-1;           //搜索区域
  int als106_cuttop=0;                 //搜索区域
  int als106_cutdeep=PIC_IMAGE_HEIGHT-1;           //搜索区域
  int als106_difmin=150;               //坡口导数判定阈值
  int als106_Sidelong=50;              //坡口两侧直线长度
  int als106_Upback_st=10;             //上半段坡口统计时上端点回退距离
  int als106_Upback_ed=10;             //上半段坡口统计时下端点回退距离
  int als106_Downback_st=10;             //下半段坡口统计时上端点回退距离
  int als106_Downback_ed=10;             //下半段坡口统计时下端点回退距离
  int als106_Upmindis=70;              //上半段拟合最短限制长度b_cut=0时有效
  int als106_Downmindis=70;            //下半段拟合最短限制长度b_cut=0时有效
  int als106_Uplong=50;//上半段直线长度
  int als106_Downdlong=50;//下半段直线长度
  int als106_dis_center_ed=120;  //断点向后搜索距离
  int als106_duandianjuli=30;    //断点向前搜索距离
  int als106_pokoumod=0;           //坡口模式: 0打底,1盖焊
  int als106_pokouUpdif=2000;           //上半段倾斜开始斜度（坡口模式=0时有效）
  int als106_pokouUpdifmin=20;         //上半段倾斜终止斜度（坡口模式=0时有效）
  int als106_pokouUpback_st=10;          //上半段坡口统计时上端点回退距离
  int als106_pokouUpback_ed=10;          //上半段坡口统计时上端点回退距离
  int als106_pokouDowndif=-2000;           //下半段倾斜开始斜度（坡口模式=0时有效）
  int als106_pokouDowndifmin=-20;         //下半段倾斜终止斜度（坡口模式=0时有效）
  int als106_pokouDownback_st=10;          //下半段坡口统计时上端点回退距离
  int als106_pokouDownback_ed=10;          //下半段坡口统计时上端点回退距离
  int als106_pokouUplong=20;             //上坡口长度（坡口模式=0时有效）
  int als106_pokouDownlong=20;             //下坡口长度（坡口模式=0时有效）
  int als106_b_pokouyaobian=1;               //咬边检测（坡口模式=0时有效）
  int als106_pokouyaobianHsize=50;       //咬边高度方向检测尺寸（坡口模式=0时有效）
  int als106_pokouduanxianerzhi=130;       //咬边二值（坡口模式=0时有效）
  int als106_pokousearchdectancemax=25;//搜寻焊缝端点距离中央凹槽最远的距离（坡口模式=0时有效）
  int als106_pokousearchdectancemin=15;//搜寻焊缝端点距离中央凹槽最近的距离（坡口模式=0时有效）
  int als106_answerpoint=0;//优先采用点序号
  int als106_b_KalmanFilter=1;//是否使用卡尔曼滤波
  int als106_KalmanQF=10;
  int als106_KalmanRF=50;
/************************************/
//算法107参数
  int als107_exposure_time=10000;//曝光值
  int als107_pingjun=15;//二值阈值
  int als107_b_yanmofuzhu=1;//是否使用掩摸辅助
  int als107_b_gudingquyu=0;//是否固定区域
  int als107_widthliantongdis=5;//激光宽度连通距离
  int als107_highliantongdis=15;//激光长度连通距离
  int als107_gujiaerzhi=160;//找骨架二值图
  int als107_jiguanghight=50;//整体激光最短长度
  int als107_jiguanglong=20;//单边激光最短长度
  int als107_jiguangkuandu=6;//激光粗细
  int als107_Updif=2000;  //上半段直线斜率限制最大值//Updif
  int als107_Updifmin=0;          //上半段直线斜率限制最小值     //Updifmin
  int als107_Uplong=50;//上半段直线长度   //设为200时将直接用拟合数据跟踪坡顶
  int als107_Downdif=-2000;      //下半段直线斜率限制最小值   //Downdif
  int als107_Downdifmin=-20;       //下半段直线斜率限制最大值
  int als107_Downdlong=50;//下半段直线长度
  int als107_St_Down=5;//下半段拟合起点
  int als107_Ed_Down=500;//下半段拟合终点
  int als107_St_Up=5;//上半段拟合起点
  int als107_Ed_Up=200;//上半段拟合终点
  int als107_dis_center_st=50;     //距离中心点此处后开始统计 //dis_center_st
  int als107_dis_center_st2=20;   //距离中心点此处后开始统计 //dis_center_st2
  int als107_dis_center_ed2=200;//距离中心点此处后停止统计 //dis_center_st2
  int als107_b_KalmanFilter=1;//是否使用卡尔曼滤波
  int als107_KalmanQF=10;
  int als107_KalmanRF=50;
/************************************/
//算法108参数
  int als108_exposure_time=10000;//曝光值
  int als108_center_x=PIC_IMAGE_WIDTH/2;//特征点位置
  int als108_center_y=PIC_IMAGE_HEIGHT/2; //特征点位置
  int als108_search_w=150;//宽度搜索区域
  int als108_search_h=150;//高度搜索区域
  int als108_STC_alpha=2250;//尺度因子，推荐2.25*1000
  int als108_STC_beta=1000;//形状因子，推荐1*1000  
  int als108_STC_rho=75;//学习率,推荐0.075*1000
  int als108_STC_sigma=500;//高斯权重，推荐0.5*1000

/************************************/
  int task_num = 0;
  int show_step = 0;      
};
/*
struct Params_exposure
{
  u_int16_t _0_99_exposure = 1000;
  u_int16_t _200_299_exposure = 0;
  u_int16_t _300_399_exposure = 0;
};
*/
class LaserImagePos : public rclcpp::Node
{
public:
  /**
   * @brief Construct a new Laser Line Center object.
   *
   * Initialize publisher.
   * Create an inner implementation.
   * Initialize subscription.
   * Print success if all done.
   * @param options Encapsulation of options for node initialization.
   */
  explicit LaserImagePos(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

  /**
   * @brief Destroy the Laser Line Center object.
   *
   * Release subscription.
   * Wake up all workers.
   * Wake up the manager.
   * Synchronize with all threads, wait for its return.
   * Release publisher.
   * Print success if all done.
   * Throw no exception.
   */
  virtual ~LaserImagePos();


private:

  /**
   * @brief Parameter client for camera.
   *
   */
  std::shared_ptr<rclcpp::AsyncParametersClient> _param_camera;

//  std::shared_ptr<rclcpp::SyncParametersClient> _param_camera_get;

  /**
   * @brief Publisher name.
   *
   */
  const char * _pub_name = "~/result";

  rclcpp::Publisher<IfAlgorhmitmsg>::SharedPtr _pub;


  /**
   * @brief Subscription name.
   *
   */
  const char * _sub_name = "~/image";

  /**
   * @brief Shared pointer to subscription.
   *
   */
  rclcpp::Subscription<IfAlgorhmitimage>::SharedPtr _sub;

  /**
   * @brief Declare parameters with defaults before usage.
   *
   */
  void _declare_parameters();

  

//Params_exposure _get_nowexposure();

//Params_exposure ps;

  /**
   * @brief Update parameters from ROS.
   *
   * @return Params Zipped parameters
   */
  Params _update_parameters();

  void alg100_declare_parameters();
  void alg101_declare_parameters();
  void alg102_declare_parameters();
  void alg103_declare_parameters();
  void alg104_declare_parameters();
  void alg105_declare_parameters();
  void alg106_declare_parameters();
  void alg107_declare_parameters();
  void alg108_declare_parameters();

  void alg100_update_parameters();
  void alg101_update_parameters();
  void alg102_update_parameters();
  void alg103_update_parameters();
  void alg104_update_parameters();
  void alg105_update_parameters();
  void alg106_update_parameters();
  void alg107_update_parameters();
  void alg108_update_parameters();

  int alg100_getcallbackParameter(const rclcpp::Parameter &p);
  int alg101_getcallbackParameter(const rclcpp::Parameter &p);
  int alg102_getcallbackParameter(const rclcpp::Parameter &p);
  int alg103_getcallbackParameter(const rclcpp::Parameter &p);
  int alg104_getcallbackParameter(const rclcpp::Parameter &p);
  int alg105_getcallbackParameter(const rclcpp::Parameter &p);
  int alg106_getcallbackParameter(const rclcpp::Parameter &p);
  int alg107_getcallbackParameter(const rclcpp::Parameter &p);
  int alg108_getcallbackParameter(const rclcpp::Parameter &p);


  Params pm;

  int _workers;

  void _worker();

  void _manager();

  std::vector<std::thread> _threads;

  OnSetParametersCallbackHandle::SharedPtr _handle;

  std::mutex _images_mut;

  std::mutex _futures_mut;

  std::condition_variable _images_con;
  
  std::condition_variable _futures_con;

  void _push_back_image(IfAlgorhmitimage::UniquePtr ptr);

  void _push_back_future(std::future<IfAlgorhmitmsg::UniquePtr> fut);

  std::deque<std::future<IfAlgorhmitmsg::UniquePtr>> _futures;

  std::deque<IfAlgorhmitimage::UniquePtr> _images;

  int _0_99_exposure_time;

  IfAlgorhmitmsg::UniquePtr execute(IfAlgorhmitimage::UniquePtr ptr, cv::Mat & buf, const Params & pm);

  std::string mat_type2encoding(int mat_type);

  bool updatatask;  //任务切换

  void InitRunImage();//初始化算法
  //返回值1检测失败，0检测成功
  int RunImage(cv::Mat &imageIn,
               std::vector <cv::Point2f> &pointcloud,
               std::vector <Targetpoint> &namepoint,
               bool &solderjoints,//是否焊点
               int step);   //输出结果点信息

  char *cv8uc1_Imagebuff_image;
  char *cv8uc1_Imagebuff1;
  char *cv8uc1_Imagebuff2;
  char *cv8uc1_Imagebuff3;
  char *cv8uc1_Imagebuff4;
  char *cv8uc1_Imagebuff5;
  char *cv8uc1_Imagebuff6;
  char *cv8uc1_Imagebuff7;
  char *cv8uc1_Imagebuff8;

  Int32 *X_line;
  float *f_line;
  Uint8 *X_lineMark;
  Int32 *X_linedif32,*niheX,*niheY;
  Myhalcv2::MyConect ImageConect,ImageConectlong,ImageConectlongPX,Imageheadline;
  Int32 firstsearch;
  Int32 firstsearch_stx,firstsearch_sty,firstsearch_edx,firstsearch_edy;
  Int32 jishuST_x,jishuST_y,jishuED_x,jishuED_y,jishuNum;
  Int32 firstdimian;
  Int32 fuzhuxielv,b_fuzhuxielv,jishuxielv;
  Int32 b_firstKalmanFilter;
  Myhalcv2::MyCountLine linegroup,linegroupout;

  Myhalcv2::L_Point32 fuzhufindST,fuzhufindED;//结果线2拟合区域,(上方)

  int alg100_runimage(cv::Mat &cvimgIn,std::vector <cv::Point2f> &pointcloud,
                      std::vector <Targetpoint> &namepoint,
                      bool &solderjoints,//是否焊点
                      int step);
  int alg101_runimage(cv::Mat &cvimgIn,std::vector <cv::Point2f> &pointcloud,
                      std::vector <Targetpoint> &namepoint,
                      bool &solderjoints,//是否焊点
                      int step);
  int alg102_runimage(cv::Mat &cvimgIn,std::vector <cv::Point2f> &pointcloud,
                      std::vector <Targetpoint> &namepoint,
                      bool &solderjoints,//是否焊点
                      int step);
  int alg103_runimage(cv::Mat &cvimgIn,std::vector <cv::Point2f> &pointcloud,
                      std::vector <Targetpoint> &namepoint,
                      bool &solderjoints,//是否焊点
                      int step);
  int alg104_runimage(cv::Mat &cvimgIn,std::vector <cv::Point2f> &pointcloud,
                      std::vector <Targetpoint> &namepoint,
                      bool &solderjoints,//是否焊点
                      int step);
  int alg105_runimage(cv::Mat &cvimgIn,std::vector <cv::Point2f> &pointcloud,
                      std::vector <Targetpoint> &namepoint,
                      bool &solderjoints,//是否焊点
                      int step);
  int alg106_runimage(cv::Mat &cvimgIn,std::vector <cv::Point2f> &pointcloud,
                      std::vector <Targetpoint> &namepoint,
                      bool &solderjoints,//是否焊点
                      int step);
  int alg107_runimage(cv::Mat &cvimgIn,std::vector <cv::Point2f> &pointcloud,
                      std::vector <Targetpoint> &namepoint,
                      bool &solderjoints,//是否焊点
                      int step);
  int alg108_runimage(cv::Mat &cvimgIn,std::vector <cv::Point2f> &pointcloud,
                      std::vector <Targetpoint> &namepoint,
                      bool &solderjoints,//是否焊点
                      int step);
};

}

#endif