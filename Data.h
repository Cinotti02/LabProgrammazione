//
// Created by francesco on 12/03/2025.
//

#ifndef DATA_H
#define DATA_H
#include <chrono>
using namespace std;


class Data {
public:
    Data(const int d, const int m, const int y): day(d), month(m), year(y) {};
    Data() = default;

    void setCurrentDate();  // Imposta la data attuale

    static Data getCurrentDate(); // Ritorna la data attuale

    string toString() const;

    static Data fromString(const string &s);

    static int daysInMonth(int month, int year);   // Funzione per ottenere il numero di giorni in un mese

    bool isValid() const;

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
