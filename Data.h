//
// Created by francesco on 12/03/2025.
//

#ifndef DATA_H
#define DATA_H
#include <chrono>
#include <iostream>

using namespace std;


class Data {
public:
    Data( int d, int m, int y): day(d), month(m), year(y) {

        if (!isValid(d, m, y)) {
            throw runtime_error("Invalid date");
        }
    };

    Data():day(0), month(0), year(0){}

    void setCurrentDate();  // Imposta la data attuale

    bool operator==(const Data & data) const;

    static Data getCurrentDate();  // Ritorna la data attuale

    string toString() const;  // Ritorna la data in formato stringa "dd/mm/yyyy"

    static Data fromString(const string &s);  // Converte una stringa in un oggetto Data

    static int daysInMonth(int month, int year);   // Funzione per ottenere il numero di giorni in un mese

      // Controlla se la data è valida

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

    static bool isValid(int d, int m, int y);
};



#endif //DATA_H
