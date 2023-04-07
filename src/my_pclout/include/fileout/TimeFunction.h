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
};
#endif // TIMEFUNCTION_H