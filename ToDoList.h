//
// Created by francesco on 29/03/2025.
//

#ifndef TODOLIST_H
#define TODOLIST_H

#include <list>
#include "Task.h"


class ToDoList {

    void addTask(Task &task);

    bool removeTask(Task &task);

    void removeAllUncompletedTasks();

    list<Task> getTasks() const;

    list<Task> getImportantTasks() const;

    list<Task> getCompletedTasks() const;

    list<Task> getUncompletedTasks() const;


private:
    string nameList;  // Nome della lista
    list<Task> tasks;  // Lista delle attività
    const string filePath = "./todo list.json";  // Percorso del file JSON
};



#endif //TODOLIST_H
