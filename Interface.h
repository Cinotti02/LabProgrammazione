//
// Created by francesco on 19/03/2025.
//

#ifndef INTERFACE_H
#define INTERFACE_H
#include <list>
#include "Calendar.h"

#include "Task.h"


class Interface {
public:
    int menu();

    bool choise(int c);

    void printCalendar(int year);

    void todayTasks();

    void showIncompleteTasks();

    void searchByDate();

    void addTask();

    void setTaskCompleted();

    void showCompletedTasks();

    void removeTask();

    void reinsertName(string nome, bool &a);

    int controlcin(int &scelta);

    int controlCinData(int &d, int &m, int &y);







private:
    list<Task> tasks;
    list<Task> completed;
    const string filePath;


};



#endif //INTERFACE_H
