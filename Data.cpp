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

int Data::daysInMonth(int month, int year) {
    if (month==4||month==6||month==9||month==11)
        return 30;
    else if (month==2)
        return (year%4==0 && (year%100!=0 || year%400==0)) ? 29 : 28;
    else
        return 31;
}
