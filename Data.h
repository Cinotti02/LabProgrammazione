//
// Created by francesco on 12/03/2025.
//

#ifndef DATA_H
#define DATA_H
#include <chrono>
using namespace std;


class Data {
public:
    Data(int d, int m, int y): day(d), month(m), year(y) {};
    Data()= default;

    void setCurrentDate();  // Imposta la data attuale

    static Data getCurrentDate(); // Ritorna la data attuale

    static int daysInMonth(int month, int year);  //TODO move method in Calendar

    string toString() const;

    Data fromString(const string &s);

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
