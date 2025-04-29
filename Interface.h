//
// Created by francesco on 19/03/2025.
//

#ifndef INTERFACE_H
#define INTERFACE_H


#include "ToDoList.h"
#include "Utility.h"

    int menu();  //funzione per stampare il menu e restituire la scelta dell'utente

    bool choice(int c, ToDoList& list);  //funzione per eseguire l'azione corrispondente alla scelta dell'utente

    void printCalendar(int year, ToDoList &list);  //funzione per stampare il calendario dell'anno corrente

    void todayTasks(ToDoList &list);  //funzione per stampare le attività da svolgere oggi

    void showUncompletedTask(ToDoList &list);  //funzione per stampare le attività da svolgere

    void searchByDate(const ToDoList &list);  //funzione per cercare le attività da svolgere in una data specifica

    //void addTask(ToDoList &list);  //funzione per aggiungere una nuova attività

    void setTaskCompleted(ToDoList &list);  //funzione per segnare un'attività come completata

    void showCompletedTasks(ToDoList &list);  //funzione per stampare le attività completate

    void removeTask(ToDoList &list);  //funzione per rimuovere un'attività dalla lista

    static void reinsertName(string nome, bool &a);  //funzione per reinserire il nome dell'attività

    void createTasks(ToDoList &list);

    bool choiceB();  //funzione per controllare la scelta dell'utente tra due opzioni



#endif //INTERFACE_H
