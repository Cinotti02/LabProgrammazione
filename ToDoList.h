//
// Created by francesco on 29/03/2025.
//

#ifndef TODOLIST_H
#define TODOLIST_H

#include <list>
#include "Task.h"


class ToDoList {
public:

    void addTask(const Task &task);

    bool removeTask(const Task &task);

    void clearTasks();

    void removeAllUncompletedTasks();

    void setNameList(const string &name);

    void setFilePath(const string &path);

    void createAndAddTask(const string& name, const string& description, const Data& date, bool important = false, bool completed = false, const Data& completionDate = Data());

    bool completeTaskByName(const string& name);

    bool removeTaskByName(const string& name);

    list<Task>& getTasks();

    const list<Task>& getTasks() const;

    string getFilePath() const;

    vector<Task> getImportantTasks() const;

    vector<Task> getCompletedTasks() const;

    vector<Task> getUncompletedTasks() const;

    vector<Task> getTasksByDate(const Data& date) const;

private:
    string nameList;  // Nome della lista
    list<Task> tasks;  // Lista delle attività
    string filePath = "C:/Users/francesco/CLionProjects/LabProgrammazione/todo list.json";

    bool existsTaskWithNameAndDate(const string &name, const Data &date) const;
};



#endif //TODOLIST_H
