#ifndef TIMEFUNCTION_H
#define TIMEFUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string>

class TimeFunction
{
public:
    TimeFunction();
    ~TimeFunction();

    void get_time_ms(std::string *timeOut);  //获取系统的字符串格式时间
    void get_time_ms(u_int16_t &Y,u_int16_t &m,u_int16_t &d,u_int16_t &H,u_int16_t &M,u_int16_t &S,u_int16_t &ms);
};
#endif // TIMEFUNCTION_H