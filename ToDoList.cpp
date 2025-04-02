//
// Created by francesco on 29/03/2025.
//

#include "ToDoList.h"


// CRUD
// Create, Read, Update, Delete

void ToDoList::addTask(Task &task) {
// TODO implemetare controllo che la nuova task non abbia un nome che già esiste
    // restituire booleano che rappresenta lo stato di creazione della task
    tasks.push_back(task);
}

// TODO metodi di update delle task

bool ToDoList::removeTask(Task &task) {
    auto it = find(tasks.begin(), tasks.end(), task);
    if (it != tasks.end()) {
        tasks.erase(it);
        return true;
    }
    return false;
}

void ToDoList::removeAllUncompletedTasks() {
    for (auto it : tasks){
    if ( it.getCompleted() == 0)
        tasks.remove(it);
    };
}

list<Task> ToDoList::getTasks() const {
    return tasks;
}

list<Task> ToDoList::getImportantTasks() const {
    std::list<Task> importantTasks;

    for (const auto& task : tasks) {
        if (task.getDate().getDay() == 1) { // Assuming the first day of the month is important
            importantTasks.push_back(task);
        }
    }

    return importantTasks;
}

list<Task> ToDoList::getCompletedTasks() const {
    list<Task> completedTasks;
    for (const auto& task : tasks) {
        if (task.getCompletionDate().getDay() != 0) { // Assuming a non-zero day indicates completion
            completedTasks.push_back(task);
        }
    }
    return completedTasks;
}

list<Task> ToDoList::getUncompletedTasks() const {
    list<Task> uncompletedTasks;
    for (const auto& task : tasks) {
        if (task.getCompletionDate().getDay() == 0) { // Assuming a zero day indicates incompletion
            uncompletedTasks.push_back(task);
        }
    }
    return uncompletedTasks;
}