//
// Created by francesco on 29/03/2025.
//

#ifndef TODOLIST_H
#define TODOLIST_H

#include <list>
#include "Task.h"


class ToDoList {
    void addTask(const Task &task);

    bool removeTask(const Task &task);

    void removeAllUncompletedTasks();

    void setNameList(const string &name);

    void setFilePath(const string &path);

    list<Task> getTasks() const;

    list<Task> getImportantTasks() const;

    list<Task> getCompletedTasks() const;

    list<Task> getUncompletedTasks() const;


private:
    string nameList;  // Nome della lista
    list<Task> tasks;  // Lista delle attività
    string filePath = "./todo list.json";  // Percorso del file JSON
};



#endif //TODOLIST_H
