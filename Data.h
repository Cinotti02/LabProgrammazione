//
// Created by francesco on 12/03/2025.
//

#ifndef DATA_H
#define DATA_H



class Data {
public:
    Data(int y, int m, int d): year(y), month(m), day(d) {};
    Data()= default;

private:
    int year;
    int month;
    int day;
};



#endif //DATA_H
