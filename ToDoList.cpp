//
// Created by francesco on 29/03/2025.
//

#include "ToDoList.h"


// CRUD
// Create, Read, Update, Delete

bool ToDoList::existsTaskWithNameAndDate(const string &name, const Data &date) const {
    for (auto &it : tasks) {
        if (it.getName() == name && it.getDate() == date) {
            return true;
        }
    }
    return false;
}

void ToDoList::addTask(const Task &task) {
    tasks.push_back(task);
}

bool ToDoList::removeTask(const Task &t) {
    for (const auto &it: tasks) {
        if (it.getName() == t.getName() &&it.getCompleted() == 0) {
            tasks.remove(it);
            return true;
        }
    }
    return false;
}

void ToDoList::clearTasks() {
    tasks.clear();
}

void ToDoList::removeAllUncompletedTasks() {
    tasks.remove_if([](const Task& t){
        return !t.getCompleted();
    });
}

void ToDoList::setNameList(const string &name) {
    nameList = name;
}

void ToDoList::setFilePath(const string &path) {
    filePath = path;
}

void ToDoList::createAndAddTask(const string& name, const string& description, const Data& date, bool important, bool completed, const Data& completionDate) {
    if (existsTaskWithNameAndDate(name, date))
        throw runtime_error("Task already exists with the same name and date");

    Task task(name, date, completionDate, description, important, completed);
    addTask(task);
}

bool ToDoList::completeTaskByName(const string& name) {
    for (auto& task : tasks) {
        if (task.getName() == name && !task.getCompleted()) {
            task.taskCompleted();
            return true;
        }
    }
    return false;
}

bool ToDoList::removeTaskByName(const string& name) {
    for (const auto& task : tasks) {
        if (task.getName() == name && !task.getCompleted()) {
            tasks.remove(task);
            return true;
        }
    }
    return false;
}

list<Task> ToDoList::getTasksByDate(const Data& date) const {
    list<Task> result;
    for (const auto& task : tasks) {
        if (task.getDate() == date && !task.getCompleted()) {
            result.push_back(task);
        }
    }
    return result;
}

list<Task>& ToDoList::getTasks(){
    return tasks;
}

const list<Task>& ToDoList::getTasks() const {
    return tasks;
}

string ToDoList::getFilePath() const {
    return filePath;
}

list<Task> ToDoList::getImportantTasks() const {
    std::list<Task> importantTasks;

    for (const auto& task : tasks) {
        if (task.getImportant() == 1) {
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