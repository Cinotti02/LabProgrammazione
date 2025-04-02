//
// Created by francesco on 29/03/2025.
//

#include "ToDoList.h"


// CRUD
// Create, Read, Update, Delete

void ToDoList::addTask(const Task &task) {
    for (auto & it : tasks) {
        if (it.getName() == task.getName()) {
            if (it.getDate() == task.getDate()) {
                throw runtime_error("Task already exists with the same name and date");
            }
        }
    }
    tasks.push_back(task);
}

bool ToDoList::removeTask(const Task &task) {
    if (auto it = find(tasks.begin(), tasks.end(), task); it != tasks.end()) {
        tasks.erase(it);
        return true;
    }
    return false;
}

void ToDoList::removeAllUncompletedTasks() {
    for (const auto& it : tasks){
    if ( it.getCompleted() == 0)
        tasks.remove(it);
    };
}

void ToDoList::setNameList(const string &name) {
    nameList = name;
}

void ToDoList::setFilePath(const string &path) {
    filePath = path;
}

list<Task> ToDoList::getTasks() const {
    return tasks;
}

list<Task> ToDoList::getImportantTasks() const {
    std::list<Task> importantTasks;

    for (const auto& task : tasks) {
        if (task.getImportant == 0) {
            importantTasks.push_back(task);
        }
    }

    return importantTasks;
}

list<Task> ToDoList::getCompletedTasks() const {
    list<Task> completedTasks;
    for (const auto& task : tasks) {
        if (task.getCompleted() == 1) {
            completedTasks.push_back(task);
        }
    }
    return completedTasks;
}

list<Task> ToDoList::getUncompletedTasks() const {
    list<Task> uncompletedTasks;
    for (const auto& task : tasks) {
        if (task.getCompleted() == 0) {
            uncompletedTasks.push_back(task);
        }
    }
    return uncompletedTasks;
}