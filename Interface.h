//
// Created by francesco on 19/03/2025.
//

#ifndef INTERFACE_H
#define INTERFACE_H

#include <list>
#include "Task.h"


class Interface {
public:
    static int menu();

    bool choice(int c);

    void printCalendar(int year) const;

    void todayTasks() const;

    void showIncompleteTasks();

    void searchByDate();

    void addTask();

    void setTaskCompleted();

    void showCompletedTasks();

    void removeTask();

    string getFilePath() const {
        return filePath;
    }

    list<Task>& getTaskList() {
        return tasks;
    }

    list<Task>& getCompletedTaskList() {
        return completed;
    }

    static void reinsertName(string nome, bool &a);

private:
    list<Task> tasks;
    list<Task> completed;
    const string filePath = "./todo list.json";


};



#endif //INTERFACE_H
