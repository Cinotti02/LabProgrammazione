//
// Created by francesco on 12/03/2025.
//

#include "Data.h"

void Data::setCurrentDate() {
    auto now = chrono::system_clock::now();
    time_t nowTime = chrono::system_clock::to_time_t(now);
    tm localTime;
    localtime_s(&localTime, &nowTime);

    day = localTime.tm_mday;
    month = localTime.tm_mon + 1;
    year = localTime.tm_year + 1900;
    
}