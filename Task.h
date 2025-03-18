//
// Created by francesco on 12/03/2025.
//

#ifndef TASK_H
#define TASK_H
#include <iostream>
#include "Data.h"
using namespace std;

class Task {
public:
    Task();                       //TODO da migliorare gli spazi tra le righe nel terminale
    Task(string n, Data d): name(n), date(d),completionDate()  {};
    Task(string n, Data d, Data c): name(n), date(d), completionDate(c) {};

    void taskCompleted() {
        completionDate = Data::getCurrentDate();
    }

    string getName() const{
        return name;
    }

    Data getDate() const {
        return date;
    }

    Data getCompletionDate() const {
        return completionDate;
    }

private:
    string name;
    Data date;
    Data completionDate;
};



#endif //TASK_H
