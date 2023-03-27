#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <Eigen/Core>
#include <Eigen/Dense>
#include <opencv2/opencv.hpp>

typedef enum CAL_POSTURE_MODEL_ID          //机器人姿态角含义模式
{
    CAL_ROBOT_YASKAWA=0,        //安川、ABB姿态标准 内旋 RX-RY-RZ
    CAL_ROBOT_KUKA=1,           //库卡姿态标准 外旋 RZ-RY-RX
    CAL_ROBOT_PANASONIC=2,      //松下姿态标准 内旋 RX-"RY"-RZ
}CAL_POSTURE;

typedef enum EYE_HAND_CALIBRATIONMODE_ID
{
    HAND_IN_EYE=0,      //眼在手上
    HAND_OUT_EYE=1,     //眼在手外
}Eye_Hand_calibrationmode;

class Calibration
{
public:
    Calibration();
    ~Calibration();
};

#endif