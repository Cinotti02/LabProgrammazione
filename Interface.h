//
// Created by francesco on 19/03/2025.
//

#ifndef INTERFACE_H
#define INTERFACE_H

#include <list>
#include "Task.h"


class Interface {
public:
    static int menu();  //funzione per stampare il menu e restituire la scelta dell'utente

    bool choice(int c);  //funzione per eseguire l'azione corrispondente alla scelta dell'utente

    void printCalendar(int year) const;  //funzione per stampare il calendario dell'anno corrente

    void todayTasks() const;  //funzione per stampare le attività da svolgere oggi

    void showIncompleteTasks();  //funzione per stampare le attività da svolgere

    void searchByDate();  //funzione per cercare le attività da svolgere in una data specifica

    void addTask();  //funzione per aggiungere una nuova attività

    void setTaskCompleted();  //funzione per segnare un'attività come completata

    void showCompletedTasks();  //funzione per stampare le attività completate

    void removeTask();  //funzione per rimuovere un'attività dalla lista

    static void reinsertName(string nome, bool &a);  //funzione per reinserire il nome dell'attività

    string getFilePath() const {
        return filePath;
    }

    list<Task>& getTaskList() {
        return tasks;
    }

    list<Task>& getCompletedTaskList() {
        return completed;
    }

private:
    list<Task> tasks;
    list<Task> completed;
    const string filePath = "./todo list.json";


};



#endif //INTERFACE_H
