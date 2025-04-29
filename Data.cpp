//
// Created by francesco on 12/03/2025.
//

#include "Data.h"
#include <iomanip>

void Data::setCurrentDate() {
    const auto now = chrono::system_clock::now();
    const time_t nowTime = chrono::system_clock::to_time_t(now);
    tm localTime{};
    localtime_s(&localTime, &nowTime);

    day = localTime.tm_mday;
    month = localTime.tm_mon + 1;
    year = localTime.tm_year + 1900;
}

bool Data::operator==(const Data &data) const {
    if (day == data.day && month == data.month && year == data.year)
        return true;
    return false ;
}

Data Data::getCurrentDate() {
    const auto now = chrono::system_clock::now();
    const time_t nowTime = chrono::system_clock::to_time_t(now);
    tm localTime{};
    localtime_s(&localTime, &nowTime);

    Data today;
    today.day = localTime.tm_mday;
    today.month = localTime.tm_mon + 1;
    today.year = localTime.tm_year + 1900;
    return today;
}

string Data::toString() const {
    ostringstream oss;
    oss << setw(2) <<  setfill('0') << day << "/"
        << setw(2) << setfill('0') << month << "/"
        << setw(4) << setfill('0') << year;
    return oss.str();
}

Data Data::fromString(const string &s) {
    int d, m, y;
    char sep;
    stringstream ss(s);
    ss >> d >> sep >> m >> sep >> y;
    return {d, m, y};
}

int Data::daysInMonth(const int month, const int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    if (month == 2)
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) ? 29 : 28;
    return 31;
}

bool Data::isValid(int d, int m, int y) {
    // Validazione normale
    if (y < getCurrentDate().getYear() || m < 1 || m > 12)
        return false;
    if (d < 1 || d > daysInMonth(m, y))
        return false;
    return true;
}
