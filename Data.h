//
// Created by francesco on 12/03/2025.
//

#ifndef DATA_H
#define DATA_H
#include <chrono>
using namespace std;


class Data {
public:
    Data(int y, int m, int d): year(y), month(m), day(d) {};
    Data()= default;

    void setCurrentDate();  // Imposta la data attuale

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

private:
    int day;
    int month;
    int year;


};



#endif //DATA_H
