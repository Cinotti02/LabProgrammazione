//
// Created by francesco on 12/03/2025.
//

#include "Data.h"

void Data::setCurrentDate() {
    const auto now = chrono::system_clock::now();
    const time_t nowTime = chrono::system_clock::to_time_t(now);
    tm localTime{};
    localtime_s(&localTime, &nowTime);

    day = localTime.tm_mday;
    month = localTime.tm_mon + 1;
    year = localTime.tm_year + 1900;
}

Data Data::getCurrentDate() {
    auto now = chrono::system_clock::now();
    time_t nowTime = chrono::system_clock::to_time_t(now);
    struct tm localTime;
    localtime_s(&localTime, &nowTime);

    return Data(localTime.tm_mday, localTime.tm_mon + 1, localTime.tm_year + 1900);
}

string Data::toString() const {
    ostringstream oss;
    oss << setw(2) <<  setfill('0') << day << "/"
        << setw(2) << setfill('0') << month << "/"
        << year;
    return oss.str();
}

Data Data::fromString(const string &s) {
    int d, m, y;
    char sep;
    stringstream ss(s);
    ss >> d >> sep >> m >> sep >> y;
    return Data(d, m, y);
}

