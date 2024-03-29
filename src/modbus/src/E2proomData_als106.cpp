#include "fileout/E2proomData.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>  
#include <unistd.h>

void E2proomData::Init_als106_E2proomData()
{
    als106_exposure_time_min=E2POOM_ALG106_LASERIMAGEPOS_EXPOSURE_TIME_MIN;
    als106_exposure_time_max=E2POOM_ALG106_LASERIMAGEPOS_EXPOSURE_TIME_MAX;
    als106_exposure_time_use=E2POOM_ALG106_LASERIMAGEPOS_EXPOSURE_TIME_USE;
    als106_pingjun_min=E2POOM_ALG106_LASERIMAGEPOS_PINGJUN_MIN;
    als106_pingjun_use=E2POOM_ALG106_LASERIMAGEPOS_PINGJUN_USE;
    als106_pingjun_max=E2POOM_ALG106_LASERIMAGEPOS_PINGJUN_MAX;
    als106_b_yanmofuzhu_min=E2POOM_ALG106_LASERIMAGEPOS_B_YANMOFUZHU_MIN;
    als106_b_yanmofuzhu_use=E2POOM_ALG106_LASERIMAGEPOS_B_YANMOFUZHU_USE;
    als106_b_yanmofuzhu_max=E2POOM_ALG106_LASERIMAGEPOS_B_YANMOFUZHU_MAX;
    als106_b_gudingquyu_min=E2POOM_ALG106_LASERIMAGEPOS_B_GUDINGQUYU_MIN;
    als106_b_gudingquyu_use=E2POOM_ALG106_LASERIMAGEPOS_B_GUDINGQUYU_USE;
    als106_b_gudingquyu_max=E2POOM_ALG106_LASERIMAGEPOS_B_GUDINGQUYU_MAX;
    als106_widthliantongdis_min=E2POOM_ALG106_LASERIMAGEPOS_WIDTHLIANTONGDIS_MIN;
    als106_widthliantongdis_use=E2POOM_ALG106_LASERIMAGEPOS_WIDTHLIANTONGDIS_USE;
    als106_widthliantongdis_max=E2POOM_ALG106_LASERIMAGEPOS_WIDTHLIANTONGDIS_MAX;
    als106_highliantongdis_min=E2POOM_ALG106_LASERIMAGEPOS_HIGHLIANTONGDIS_MIN;
    als106_highliantongdis_use=E2POOM_ALG106_LASERIMAGEPOS_HIGHLIANTONGDIS_USE;
    als106_highliantongdis_max=E2POOM_ALG106_LASERIMAGEPOS_HIGHLIANTONGDIS_MAX;
    als106_gujiaerzhi_min=E2POOM_ALG106_LASERIMAGEPOS_GUJIAERZHI_MIN;
    als106_gujiaerzhi_use=E2POOM_ALG106_LASERIMAGEPOS_GUJIAERZHI_USE;
    als106_gujiaerzhi_max=E2POOM_ALG106_LASERIMAGEPOS_GUJIAERZHI_MAX;
    als106_jiguanghight_min=E2POOM_ALG106_LASERIMAGEPOS_JIGUANGHIGHT_MIN;
    als106_jiguanghight_use=E2POOM_ALG106_LASERIMAGEPOS_JIGUANGHIGHT_USE;
    als106_jiguanghight_max=E2POOM_ALG106_LASERIMAGEPOS_JIGUANGHIGHT_MAX;
    als106_jiguanglong_min=E2POOM_ALG106_LASERIMAGEPOS_JIGUANGLONG_MIN;
    als106_jiguanglong_use=E2POOM_ALG106_LASERIMAGEPOS_JIGUANGLONG_USE;
    als106_jiguanglong_max=E2POOM_ALG106_LASERIMAGEPOS_JIGUANGLONG_MAX;
    als106_jiguangkuandu_min=E2POOM_ALG106_LASERIMAGEPOS_JIGUANGKUANDU_MIN;
    als106_jiguangkuandu_use=E2POOM_ALG106_LASERIMAGEPOS_JIGUANGKUANDU_USE;
    als106_jiguangkuandu_max=E2POOM_ALG106_LASERIMAGEPOS_JIGUANGKUANDU_MAX;
    als106_b_cut_min=E2POOM_ALG106_LASERIMAGEPOS_B_CUT_MIN;
    als106_b_cut_use=E2POOM_ALG106_LASERIMAGEPOS_B_CUT_USE;
    als106_b_cut_max=E2POOM_ALG106_LASERIMAGEPOS_B_CUT_MAX;
    als106_cutleft_min=E2POOM_ALG106_LASERIMAGEPOS_CUTLEFT_MIN;
    als106_cutleft_use=E2POOM_ALG106_LASERIMAGEPOS_CUTLEFT_USE;
    als106_cutleft_max=E2POOM_ALG106_LASERIMAGEPOS_CUTLEFT_MAX;
    als106_cutright_min=E2POOM_ALG106_LASERIMAGEPOS_CUTRIGHT_MIN;
    als106_cutright_use=E2POOM_ALG106_LASERIMAGEPOS_CUTRIGHT_USE;
    als106_cutright_max=E2POOM_ALG106_LASERIMAGEPOS_CUTRIGHT_MAX;
    als106_cuttop_min=E2POOM_ALG106_LASERIMAGEPOS_CUTTOP_MIN;
    als106_cuttop_use=E2POOM_ALG106_LASERIMAGEPOS_CUTTOP_USE;
    als106_cuttop_max=E2POOM_ALG106_LASERIMAGEPOS_CUTTOP_MAX;
    als106_cutdeep_min=E2POOM_ALG106_LASERIMAGEPOS_CUTDEEP_MIN;
    als106_cutdeep_use=E2POOM_ALG106_LASERIMAGEPOS_CUTDEEP_USE;
    als106_cutdeep_max=E2POOM_ALG106_LASERIMAGEPOS_CUTDEEP_MAX;
    als106_difmin_min=E2POOM_ALG106_LASERIMAGEPOS_DIFMIN_MIN;
    als106_difmin_use=E2POOM_ALG106_LASERIMAGEPOS_DIFMIN_USE;
    als106_difmin_max=E2POOM_ALG106_LASERIMAGEPOS_DIFMIN_MAX;
    als106_Sidelong_min=E2POOM_ALG106_LASERIMAGEPOS_SIDELONG_MIN;
    als106_Sidelong_use=E2POOM_ALG106_LASERIMAGEPOS_SIDELONG_USE;
    als106_Sidelong_max=E2POOM_ALG106_LASERIMAGEPOS_SIDELONG_MAX;
    als106_Upback_st_min=E2POOM_ALG106_LASERIMAGEPOS_UPBACK_ST_MIN;
    als106_Upback_st_use=E2POOM_ALG106_LASERIMAGEPOS_UPBACK_ST_USE;
    als106_Upback_st_max=E2POOM_ALG106_LASERIMAGEPOS_UPBACK_ST_MAX;
    als106_Upback_ed_min=E2POOM_ALG106_LASERIMAGEPOS_UPBACK_ED_MIN;
    als106_Upback_ed_use=E2POOM_ALG106_LASERIMAGEPOS_UPBACK_ED_USE;
    als106_Upback_ed_max=E2POOM_ALG106_LASERIMAGEPOS_UPBACK_ED_MAX;
    als106_Downback_st_min=E2POOM_ALG106_LASERIMAGEPOS_DOWNBACK_ST_MIN;
    als106_Downback_st_use=E2POOM_ALG106_LASERIMAGEPOS_DOWNBACK_ST_USE;
    als106_Downback_st_max=E2POOM_ALG106_LASERIMAGEPOS_DOWNBACK_ST_MAX;
    als106_Downback_ed_min=E2POOM_ALG106_LASERIMAGEPOS_DOWNBACK_ED_MIN;
    als106_Downback_ed_use=E2POOM_ALG106_LASERIMAGEPOS_DOWNBACK_ED_USE;
    als106_Downback_ed_max=E2POOM_ALG106_LASERIMAGEPOS_DOWNBACK_ED_MAX;
    als106_Upmindis_min=E2POOM_ALG106_LASERIMAGEPOS_UPMINDIS_MIN;
    als106_Upmindis_use=E2POOM_ALG106_LASERIMAGEPOS_UPMINDIS_USE;
    als106_Upmindis_max=E2POOM_ALG106_LASERIMAGEPOS_UPMINDIS_MAX;
    als106_Downmindis_min=E2POOM_ALG106_LASERIMAGEPOS_DOWNMINDIS_MIN;
    als106_Downmindis_use=E2POOM_ALG106_LASERIMAGEPOS_DOWNMINDIS_USE;
    als106_Downmindis_max=E2POOM_ALG106_LASERIMAGEPOS_DOWNMINDIS_MAX;
    als106_Uplong_min=E2POOM_ALG106_LASERIMAGEPOS_UPLONG_MIN;
    als106_Uplong_use=E2POOM_ALG106_LASERIMAGEPOS_UPLONG_USE;
    als106_Uplong_max=E2POOM_ALG106_LASERIMAGEPOS_UPLONG_MAX;
    als106_Downdlong_min=E2POOM_ALG106_LASERIMAGEPOS_DOWNDLONG_MIN;
    als106_Downdlong_use=E2POOM_ALG106_LASERIMAGEPOS_DOWNDLONG_USE;
    als106_Downdlong_max=E2POOM_ALG106_LASERIMAGEPOS_DOWNDLONG_MAX;
    als106_dis_center_ed_min=E2POOM_ALG106_LASERIMAGEPOS_DISCENTER_ED_MIN;
    als106_dis_center_ed_use=E2POOM_ALG106_LASERIMAGEPOS_DISCENTER_ED_USE;
    als106_dis_center_ed_max=E2POOM_ALG106_LASERIMAGEPOS_DISCENTER_ED_MAX;
    als106_duandianjuli_min=E2POOM_ALG106_LASERIMAGEPOS_DUANDIANJULI_MIN;
    als106_duandianjuli_use=E2POOM_ALG106_LASERIMAGEPOS_DUANDIANJULI_USE;
    als106_duandianjuli_max=E2POOM_ALG106_LASERIMAGEPOS_DUANDIANJULI_MAX;
    als106_pokoumod_min=E2POOM_ALG106_LASERIMAGEPOS_POKOUMOD_MIN;
    als106_pokoumod_use=E2POOM_ALG106_LASERIMAGEPOS_POKOUMOD_USE;
    als106_pokoumod_max=E2POOM_ALG106_LASERIMAGEPOS_POKOUMOD_MAX;
    als106_pokouUpdif_min=E2POOM_ALG106_LASERIMAGEPOS_POKOUUPDIF_MIN;
    als106_pokouUpdif_use=E2POOM_ALG106_LASERIMAGEPOS_POKOUUPDIF_USE;
    als106_pokouUpdif_max=E2POOM_ALG106_LASERIMAGEPOS_POKOUUPDIF_MAX;
    als106_pokouUpdifmin_min=E2POOM_ALG106_LASERIMAGEPOS_POKOUUPDIFMIN_MIN;
    als106_pokouUpdifmin_use=E2POOM_ALG106_LASERIMAGEPOS_POKOUUPDIFMIN_USE;
    als106_pokouUpdifmin_max=E2POOM_ALG106_LASERIMAGEPOS_POKOUUPDIFMIN_MAX;
    als106_pokouUpback_st_min=E2POOM_ALG106_LASERIMAGEPOS_POKOUUPBACK_ST_MIN;
    als106_pokouUpback_st_use=E2POOM_ALG106_LASERIMAGEPOS_POKOUUPBACK_ST_USE;
    als106_pokouUpback_st_max=E2POOM_ALG106_LASERIMAGEPOS_POKOUUPBACK_ST_MAX;
    als106_pokouUpback_ed_min=E2POOM_ALG106_LASERIMAGEPOS_POKOUUPBACK_ED_MIN;
    als106_pokouUpback_ed_use=E2POOM_ALG106_LASERIMAGEPOS_POKOUUPBACK_ED_USE;
    als106_pokouUpback_ed_max=E2POOM_ALG106_LASERIMAGEPOS_POKOUUPBACK_ED_MAX;
    als106_pokouDowndif_min=E2POOM_ALG106_LASERIMAGEPOS_POKOUDOWNDIF_MIN;
    als106_pokouDowndif_use=E2POOM_ALG106_LASERIMAGEPOS_POKOUDOWNDIF_USE;
    als106_pokouDowndif_max=E2POOM_ALG106_LASERIMAGEPOS_POKOUDOWNDIF_MAX;
    als106_pokouDowndifmin_min=E2POOM_ALG106_LASERIMAGEPOS_POKOUDOWNDIFMIN_MIN;
    als106_pokouDowndifmin_use=E2POOM_ALG106_LASERIMAGEPOS_POKOUDOWNDIFMIN_USE;
    als106_pokouDowndifmin_max=E2POOM_ALG106_LASERIMAGEPOS_POKOUDOWNDIFMIN_MAX;
    als106_pokouDownback_st_min=E2POOM_ALG106_LASERIMAGEPOS_POKOUDOWNBACK_ST_MIN;
    als106_pokouDownback_st_use=E2POOM_ALG106_LASERIMAGEPOS_POKOUDOWNBACK_ST_USE;
    als106_pokouDownback_st_max=E2POOM_ALG106_LASERIMAGEPOS_POKOUDOWNBACK_ST_MAX;
    als106_pokouDownback_ed_min=E2POOM_ALG106_LASERIMAGEPOS_POKOUDOWNBACK_ED_MIN;
    als106_pokouDownback_ed_use=E2POOM_ALG106_LASERIMAGEPOS_POKOUDOWNBACK_ED_USE;
    als106_pokouDownback_ed_max=E2POOM_ALG106_LASERIMAGEPOS_POKOUDOWNBACK_ED_MAX;
    als106_pokouUplong_min=E2POOM_ALG106_LASERIMAGEPOS_POKOUUPLONG_MIN;
    als106_pokouUplong_use=E2POOM_ALG106_LASERIMAGEPOS_POKOUUPLONG_USE;
    als106_pokouUplong_max=E2POOM_ALG106_LASERIMAGEPOS_POKOUUPLONG_MAX;
    als106_pokouDownlong_min=E2POOM_ALG106_LASERIMAGEPOS_POKOUDOWNLONG_MIN;
    als106_pokouDownlong_use=E2POOM_ALG106_LASERIMAGEPOS_POKOUDOWNLONG_USE;
    als106_pokouDownlong_max=E2POOM_ALG106_LASERIMAGEPOS_POKOUDOWNLONG_MAX;
    als106_b_pokouyaobian_min=E2POOM_ALG106_LASERIMAGEPOS_B_POKOUYAOBIAN_MIN;
    als106_b_pokouyaobian_use=E2POOM_ALG106_LASERIMAGEPOS_B_POKOUYAOBIAN_USE;
    als106_b_pokouyaobian_max=E2POOM_ALG106_LASERIMAGEPOS_B_POKOUYAOBIAN_MAX;
    als106_pokouyaobianHsize_min=E2POOM_ALG106_LASERIMAGEPOS_POKOUYAOBIANHSIZE_MIN;
    als106_pokouyaobianHsize_use=E2POOM_ALG106_LASERIMAGEPOS_POKOUYAOBIANHSIZE_USE;
    als106_pokouyaobianHsize_max=E2POOM_ALG106_LASERIMAGEPOS_POKOUYAOBIANHSIZE_MAX;
    als106_pokouduanxianerzhi_min=E2POOM_ALG106_LASERIMAGEPOS_POKOUDUANXIANERZHI_MIN;
    als106_pokouduanxianerzhi_use=E2POOM_ALG106_LASERIMAGEPOS_POKOUDUANXIANERZHI_USE;
    als106_pokouduanxianerzhi_max=E2POOM_ALG106_LASERIMAGEPOS_POKOUDUANXIANERZHI_MAX;
    als106_pokousearchdectancemax_min=E2POOM_ALG106_LASERIMAGEPOS_POKOUSEARCHDECTANCEMAX_MIN;
    als106_pokousearchdectancemax_use=E2POOM_ALG106_LASERIMAGEPOS_POKOUSEARCHDECTANCEMAX_USE;
    als106_pokousearchdectancemax_max=E2POOM_ALG106_LASERIMAGEPOS_POKOUSEARCHDECTANCEMAX_MAX;
    als106_pokousearchdectancemin_min=E2POOM_ALG106_LASERIMAGEPOS_POKOUSEARCHDECTANCEMIN_MIN;
    als106_pokousearchdectancemin_use=E2POOM_ALG106_LASERIMAGEPOS_POKOUSEARCHDECTANCEMIN_USE;
    als106_pokousearchdectancemin_max=E2POOM_ALG106_LASERIMAGEPOS_POKOUSEARCHDECTANCEMIN_MAX;   
    als106_answerpoint_min=E2POOM_ALG106_LASERIMAGEPOS_ANSWERPOINT_MIN;
    als106_answerpoint_use=E2POOM_ALG106_LASERIMAGEPOS_ANSWERPOINT_USE;
    als106_answerpoint_max=E2POOM_ALG106_LASERIMAGEPOS_ANSWERPOINT_MAX;
    als106_b_KalmanFilter_min=E2POOM_ALG106_LASERIMAGEPOS_B_KALMANFILTER_MIN;
    als106_b_KalmanFilter_max=E2POOM_ALG106_LASERIMAGEPOS_B_KALMANFILTER_MAX;
    als106_b_KalmanFilter_use=E2POOM_ALG106_LASERIMAGEPOS_B_KALMANFILTER_USE;
    als106_KalmanQF_min=E2POOM_ALG106_LASERIMAGEPOS_KALMANQF_MIN;
    als106_KalmanQF_max=E2POOM_ALG106_LASERIMAGEPOS_KALMANQF_MAX;
    als106_KalmanQF_use=E2POOM_ALG106_LASERIMAGEPOS_KALMANQF_USE;
    als106_KalmanRF_min=E2POOM_ALG106_LASERIMAGEPOS_KALMANRF_MIN;
    als106_KalmanRF_max=E2POOM_ALG106_LASERIMAGEPOS_KALMANRF_MAX;
    als106_KalmanRF_use=E2POOM_ALG106_LASERIMAGEPOS_KALMANRF_USE;
}

void E2proomData::als106_check_para()
{
    if(als106_exposure_time<als106_exposure_time_min||als106_exposure_time>als106_exposure_time_max)
        als106_exposure_time=als106_exposure_time_use;
    if(als106_pingjun<als106_pingjun_min||als106_pingjun>als106_pingjun_max)
        als106_pingjun=als106_pingjun_use;
    if(als106_b_yanmofuzhu<als106_b_yanmofuzhu_min||als106_b_yanmofuzhu>als106_b_yanmofuzhu_max)
        als106_b_yanmofuzhu=als106_b_yanmofuzhu_use;
    if(als106_b_gudingquyu<als106_b_gudingquyu_min||als106_b_gudingquyu>als106_b_gudingquyu_max)
        als106_b_gudingquyu=als106_b_gudingquyu_use;    
    if(als106_widthliantongdis<als106_widthliantongdis_min||als106_widthliantongdis>als106_widthliantongdis_max)
        als106_widthliantongdis=als106_widthliantongdis_use;
    if(als106_highliantongdis<als106_highliantongdis_min||als106_highliantongdis>als106_highliantongdis_max)
        als106_highliantongdis=als106_highliantongdis_use;
    if(als106_gujiaerzhi<als106_gujiaerzhi_min||als106_gujiaerzhi>als106_gujiaerzhi_max)
        als106_gujiaerzhi=als106_gujiaerzhi_use;
    if(als106_jiguanghight<als106_jiguanghight_min||als106_jiguanghight>als106_jiguanghight_max)
        als106_jiguanghight=als106_jiguanghight_use;
    if(als106_jiguanglong<als106_jiguanglong_min||als106_jiguanglong>als106_jiguanglong_max)
        als106_jiguanglong=als106_jiguanglong_use;
    if(als106_jiguangkuandu<als106_jiguangkuandu_min||als106_jiguangkuandu>als106_jiguangkuandu_max)
        als106_jiguangkuandu=als106_jiguangkuandu_use;
    if(als106_b_cut<als106_b_cut_min||als106_b_cut>als106_b_cut_max)
        als106_b_cut=als106_b_cut_use;
    if(als106_cutleft<als106_cutleft_min||als106_cutleft>als106_cutleft_max)
        als106_cutleft=als106_cutleft_use;
    if(als106_cutright<als106_cutright_min||als106_cutright>als106_cutright_max)
        als106_cutright=als106_cutright_use;
    if(als106_cuttop<als106_cuttop_min||als106_cuttop>als106_cuttop_max)
        als106_cuttop=als106_cuttop_use;
    if(als106_cutdeep<als106_cutdeep_min||als106_cutdeep>als106_cutdeep_max)
        als106_cutdeep=als106_cutdeep_use;
    if(als106_difmin<als106_difmin_min||als106_difmin>als106_difmin_max)
        als106_difmin=als106_difmin_use;
    if(als106_Sidelong<als106_Sidelong_min||als106_Sidelong>als106_Sidelong_max)
        als106_Sidelong=als106_Sidelong_use;
    if(als106_Upback_st<als106_Upback_st_min||als106_Upback_st>als106_Upback_st_max)
        als106_Upback_st=als106_Upback_st_use;  
    if(als106_Upback_ed<als106_Upback_ed_min||als106_Upback_ed>als106_Upback_ed_max)
        als106_Upback_ed=als106_Upback_ed_use;  
    if(als106_Downback_st<als106_Downback_st_min||als106_Downback_st>als106_Downback_st_max)
        als106_Downback_st=als106_Downback_st_use;
    if(als106_Downback_ed<als106_Downback_ed_min||als106_Downback_ed>als106_Downback_ed_max)
        als106_Downback_ed=als106_Downback_ed_use;
    if(als106_Upmindis<als106_Upmindis_min||als106_Upmindis>als106_Upmindis_max)
        als106_Upmindis=als106_Upmindis_use;
    if(als106_Downmindis<als106_Downmindis_min||als106_Downmindis>als106_Downmindis_max)
        als106_Downmindis=als106_Downmindis_use;
    if(als106_Uplong<als106_Uplong_min||als106_Uplong>als106_Uplong_max)
        als106_Uplong=als106_Uplong_use;
    if(als106_Downdlong<als106_Downdlong_min||als106_Downdlong>als106_Downdlong_max)
        als106_Downdlong=als106_Downdlong_use;
    if(als106_dis_center_ed<als106_dis_center_ed_min||als106_dis_center_ed>als106_dis_center_ed_max)
        als106_dis_center_ed=als106_dis_center_ed_use;
    if(als106_duandianjuli<als106_duandianjuli_min||als106_duandianjuli>als106_duandianjuli_max)
        als106_duandianjuli=als106_duandianjuli_use;
    if(als106_pokoumod<als106_pokoumod_min||als106_pokoumod>als106_pokoumod_max)
        als106_pokoumod=als106_pokoumod_use;
    if(als106_pokouUpdif<als106_pokouUpdif_min||als106_pokouUpdif>als106_pokouUpdif_max)
        als106_pokouUpdif=als106_pokouUpdif_use;
    if(als106_pokouUpdifmin<als106_pokouUpdifmin_min||als106_pokouUpdifmin>als106_pokouUpdifmin_max)
        als106_pokouUpdifmin=als106_pokouUpdifmin_use;
    if(als106_pokouUpback_st<als106_pokouUpback_st_min||als106_pokouUpback_st>als106_pokouUpback_st_max)
        als106_pokouUpback_st=als106_pokouUpback_st_use;
    if(als106_pokouUpback_ed<als106_pokouUpback_ed_min||als106_pokouUpback_ed>als106_pokouUpback_ed_max)
        als106_pokouUpback_ed=als106_pokouUpback_ed_use;
    if(als106_pokouDowndif<als106_pokouDowndif_min||als106_pokouDowndif>als106_pokouDowndif_max)
        als106_pokouDowndif=als106_pokouDowndif_use;
    if(als106_pokouDowndifmin<als106_pokouDowndifmin_min||als106_pokouDowndifmin>als106_pokouDowndifmin_max)
        als106_pokouDowndifmin=als106_pokouDowndifmin_use;
    if(als106_pokouDownback_st<als106_pokouDownback_st_min||als106_pokouDownback_st>als106_pokouDownback_st_max)
        als106_pokouDownback_st=als106_pokouDownback_st_use;
    if(als106_pokouDownback_ed<als106_pokouDownback_ed_min||als106_pokouDownback_ed>als106_pokouDownback_ed_max)
        als106_pokouDownback_ed=als106_pokouDownback_ed_use;
    if(als106_pokouUplong<als106_pokouUplong_min||als106_pokouUplong>als106_pokouUplong_max)
        als106_pokouUplong=als106_pokouUplong_use;
    if(als106_pokouDownlong<als106_pokouDownlong_min||als106_pokouDownlong>als106_pokouDownlong_max)
        als106_pokouDownlong=als106_pokouDownlong_use;
    if(als106_b_pokouyaobian<als106_b_pokouyaobian_min||als106_b_pokouyaobian>als106_b_pokouyaobian_max)
        als106_b_pokouyaobian=als106_b_pokouyaobian_use;
    if(als106_pokouyaobianHsize<als106_pokouyaobianHsize_min||als106_pokouyaobianHsize>als106_pokouyaobianHsize_max)
        als106_pokouyaobianHsize=als106_pokouyaobianHsize_use;
    if(als106_pokouduanxianerzhi<als106_pokouduanxianerzhi_min||als106_pokouduanxianerzhi>als106_pokouduanxianerzhi_max)
        als106_pokouduanxianerzhi=als106_pokouduanxianerzhi_use;
    if(als106_pokousearchdectancemax<als106_pokousearchdectancemax_min||als106_pokousearchdectancemax>als106_pokousearchdectancemax_max)
        als106_pokousearchdectancemax=als106_pokousearchdectancemax_use;
    if(als106_pokousearchdectancemin<als106_pokousearchdectancemin_min||als106_pokousearchdectancemin>als106_pokousearchdectancemin_max)
        als106_pokousearchdectancemin=als106_pokousearchdectancemin_use;
    if(als106_answerpoint<als106_answerpoint_min||als106_answerpoint>als106_answerpoint_max)
        als106_answerpoint=als106_answerpoint_use;
    if(als106_b_KalmanFilter<als106_b_KalmanFilter_min||als106_b_KalmanFilter>als106_b_KalmanFilter_max)
        als106_b_KalmanFilter=als106_b_KalmanFilter_use;
    if(als106_KalmanQF<als106_KalmanQF_min||als106_KalmanQF>als106_KalmanQF_max)
        als106_KalmanQF=als106_KalmanQF_use;
    if(als106_KalmanRF<als106_KalmanRF_min||als106_KalmanRF>als106_KalmanRF_max)
        als106_KalmanRF=als106_KalmanRF_use;
}

void E2proomData::als106_read_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    buff=new Uint8[E2POOM_ALG106_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
        return;
    if(0 > fo.ReadFile(filename,buff,E2POOM_ALG106_LASERIMAGEPOS_SAVEBUFF))
    {
        init_als106_para();
        if(buff!=NULL)
        {
          delete []buff;
          buff=NULL;
        }
    }
    else
    {
      Uint16 *ui16_p;
      Int16 *i16_p;

      ui16_p = (Uint16*)buff;
      als106_exposure_time=*ui16_p;
      ui16_p++;
      i16_p = (Int16*)ui16_p;
      als106_pingjun=*i16_p;
      i16_p++;
      als106_b_yanmofuzhu=*i16_p;
      i16_p++;
      als106_b_gudingquyu=*i16_p;
      i16_p++;
      als106_widthliantongdis=*i16_p;
      i16_p++;
      als106_highliantongdis=*i16_p;
      i16_p++;
      als106_gujiaerzhi=*i16_p;
      i16_p++;
      als106_jiguanghight=*i16_p;
      i16_p++;
      als106_jiguanglong=*i16_p;
      i16_p++;
      als106_jiguangkuandu=*i16_p;
      i16_p++;
      als106_b_cut=*i16_p;
      i16_p++;  
      als106_cutleft=*i16_p;
      i16_p++; 
      als106_cutright=*i16_p;
      i16_p++; 
      als106_cuttop=*i16_p;
      i16_p++; 
      als106_cutdeep=*i16_p;
      i16_p++; 
      als106_difmin=*i16_p;
      i16_p++;
      als106_Sidelong=*i16_p;
      i16_p++;
      als106_Upback_st=*i16_p;
      i16_p++;
      als106_Upback_ed=*i16_p;
      i16_p++;
      als106_Downback_st=*i16_p;
      i16_p++;
      als106_Downback_ed=*i16_p;
      i16_p++;
      als106_Upmindis=*i16_p;
      i16_p++;  
      als106_Downmindis=*i16_p;
      i16_p++; 
      als106_Uplong=*i16_p;
      i16_p++; 
      als106_Downdlong=*i16_p;
      i16_p++; 
      als106_dis_center_ed=*i16_p;
      i16_p++; 
      als106_duandianjuli=*i16_p;
      i16_p++;
      als106_pokoumod=*i16_p;
      i16_p++;
      als106_pokouUpdif=*i16_p;
      i16_p++;
      als106_pokouUpdifmin=*i16_p;
      i16_p++;
      als106_pokouUpback_st=*i16_p;
      i16_p++;
      als106_pokouUpback_ed=*i16_p;
      i16_p++;
      als106_pokouDowndif=*i16_p;
      i16_p++;
      als106_pokouDowndifmin=*i16_p;
      i16_p++;
      als106_pokouDownback_st=*i16_p;
      i16_p++;
      als106_pokouDownback_ed=*i16_p;
      i16_p++;
      als106_pokouUplong=*i16_p;
      i16_p++;
      als106_pokouDownlong=*i16_p;
      i16_p++;
      als106_b_pokouyaobian=*i16_p;
      i16_p++;
      als106_pokouyaobianHsize=*i16_p;
      i16_p++;
      als106_pokouduanxianerzhi=*i16_p;
      i16_p++;
      als106_pokousearchdectancemax=*i16_p;
      i16_p++;
      als106_pokousearchdectancemin=*i16_p;
      i16_p++;
      als106_answerpoint=*i16_p;
      i16_p++;
      als106_b_KalmanFilter=*i16_p;
      i16_p++;
      als106_KalmanQF=*i16_p;
      i16_p++;
      als106_KalmanRF=*i16_p;
      i16_p++;
    }
    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }

}

void E2proomData::write_als106_para(char *filename)
{
    Uint8 *buff=NULL;
    CFileOut fo;

    check_para();
    buff=new Uint8[E2POOM_ALG106_LASERIMAGEPOS_SAVEBUFF];
    if(buff==NULL)
      return;

    Uint16 *ui16_p;
    Int16 *i16_p;

    ui16_p = (Uint16*)buff;
    *ui16_p=als106_exposure_time;
    ui16_p++;
    i16_p = (Int16*)ui16_p;
    *i16_p=als106_pingjun;
    i16_p++;
    *i16_p=als106_b_yanmofuzhu;
    i16_p++;
    *i16_p=als106_b_gudingquyu;
    i16_p++;
    *i16_p=als106_widthliantongdis;
    i16_p++;
    *i16_p=als106_highliantongdis;
    i16_p++;
    *i16_p=als106_gujiaerzhi;
    i16_p++;
    *i16_p=als106_jiguanghight;
    i16_p++;
    *i16_p=als106_jiguanglong;
    i16_p++;
    *i16_p=als106_jiguangkuandu;
    i16_p++;
    *i16_p=als106_b_cut;
    i16_p++;  
    *i16_p=als106_cutleft;
    i16_p++; 
    *i16_p=als106_cutright;
    i16_p++; 
    *i16_p=als106_cuttop;
    i16_p++; 
    *i16_p=als106_cutdeep;
    i16_p++; 
    *i16_p=als106_difmin;
    i16_p++;
    *i16_p=als106_Sidelong;
    i16_p++;
    *i16_p=als106_Upback_st;
    i16_p++;
    *i16_p=als106_Upback_ed;
    i16_p++;
    *i16_p=als106_Downback_st;
    i16_p++;
    *i16_p=als106_Downback_ed;
    i16_p++;
    *i16_p=als106_Upmindis;
    i16_p++;
    *i16_p=als106_Downmindis;
    i16_p++;
    *i16_p=als106_Uplong;
    i16_p++;
    *i16_p=als106_Downdlong;
    i16_p++;
    *i16_p=als106_dis_center_ed;
    i16_p++;
    *i16_p=als106_duandianjuli;
    i16_p++;
    *i16_p=als106_pokoumod;
    i16_p++;
    *i16_p=als106_pokouUpdif;
    i16_p++;
    *i16_p=als106_pokouUpdifmin;
    i16_p++;
    *i16_p=als106_pokouUpback_st;
    i16_p++;
    *i16_p=als106_pokouUpback_ed;
    i16_p++;
    *i16_p=als106_pokouDowndif;
    i16_p++;
    *i16_p=als106_pokouDowndifmin;
    i16_p++;
    *i16_p=als106_pokouDownback_st;
    i16_p++;
    *i16_p=als106_pokouDownback_ed;
    i16_p++;
    *i16_p=als106_pokouUplong;
    i16_p++;
    *i16_p=als106_pokouDownlong;
    i16_p++;
    *i16_p=als106_b_pokouyaobian;
    i16_p++;
    *i16_p=als106_pokouyaobianHsize;
    i16_p++;
    *i16_p=als106_pokouduanxianerzhi;
    i16_p++;
    *i16_p=als106_pokousearchdectancemax;
    i16_p++;
    *i16_p=als106_pokousearchdectancemin;
    i16_p++;  
    *i16_p=als106_answerpoint;
    i16_p++;
    *i16_p=als106_b_KalmanFilter;
    i16_p++;
    *i16_p=als106_KalmanQF;
    i16_p++;
    *i16_p=als106_KalmanRF;
    i16_p++;

    fo.WriteFile(filename,buff,E2POOM_ALG106_LASERIMAGEPOS_SAVEBUFF);

    if(buff!=NULL)
    {
      delete []buff;
      buff=NULL;
    }
}

void E2proomData::init_als106_para()
{
    als106_exposure_time=als106_exposure_time_use;
    als106_pingjun=als106_pingjun_use;
    als106_b_yanmofuzhu=als106_b_yanmofuzhu_use;
    als106_b_gudingquyu=als106_b_gudingquyu_use;
    als106_widthliantongdis=als106_widthliantongdis_use;
    als106_highliantongdis=als106_highliantongdis_use;
    als106_gujiaerzhi=als106_gujiaerzhi_use;
    als106_jiguanghight=als106_jiguanghight_use;
    als106_jiguanglong=als106_jiguanglong_use;
    als106_jiguangkuandu=als106_jiguangkuandu_use;
    als106_b_cut=als106_b_cut_use;
    als106_cutleft=als106_cutleft_use;
    als106_cutright=als106_cutright_use;
    als106_cuttop=als106_cuttop_use;
    als106_cutdeep=als106_cutdeep_use;
    als106_difmin=als106_difmin_use;
    als106_Sidelong=als106_Sidelong_use;
    als106_Upback_st=als106_Upback_st_use;
    als106_Upback_ed=als106_Upback_ed_use;
    als106_Downback_st=als106_Downback_st_use;
    als106_Downback_ed=als106_Downback_ed_use;
    als106_Upmindis=als106_Upmindis_use;
    als106_Downmindis=als106_Downmindis_use;
    als106_Uplong=als106_Uplong_use;
    als106_Downdlong=als106_Downdlong_use;
    als106_dis_center_ed=als106_dis_center_ed_use;
    als106_duandianjuli=als106_duandianjuli_use;
    als106_pokoumod=als106_pokoumod_use;
    als106_pokouUpdif=als106_pokouUpdif_use;
    als106_pokouUpdifmin=als106_pokouUpdifmin_use;
    als106_pokouUpback_st=als106_pokouUpback_st_use;
    als106_pokouUpback_ed=als106_pokouUpback_ed_use;
    als106_pokouDowndif=als106_pokouDowndif_use;
    als106_pokouDowndifmin=als106_pokouDowndifmin_use;
    als106_pokouDownback_st=als106_pokouDownback_st_use;
    als106_pokouDownback_ed=als106_pokouDownback_ed_use;
    als106_pokouUplong=als106_pokouUplong_use;
    als106_pokouDownlong=als106_pokouDownlong_use;
    als106_b_pokouyaobian=als106_b_pokouyaobian_use;
    als106_pokouyaobianHsize=als106_pokouyaobianHsize_use;
    als106_pokouduanxianerzhi=als106_pokouduanxianerzhi_use;
    als106_pokousearchdectancemax=als106_pokousearchdectancemax_use;
    als106_pokousearchdectancemin=als106_pokousearchdectancemin_use;
    als106_answerpoint=als106_answerpoint_use;
    als106_b_KalmanFilter=als106_b_KalmanFilter_use;
    als106_KalmanQF=als106_KalmanQF_use;
    als106_KalmanRF=als106_KalmanRF_use;
}