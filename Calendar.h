//
// Created by francesco on 17/03/2025.
//

#ifndef CALENDAR_H
#define CALENDAR_H

#include <list>
#include "Task.h"

using namespace std;

// Funzione per ottenere il numero di giorni in un mese
int daysInMonth(int month, int year);

// Funzione per ottenere il giorno della settimana del primo giorno del mese
int firstDayOfMonth(int month, int year);

// Funzione per stampare il mese
void printMonth(int monthPerRow,int startMonth, int year);

// Funzione per stampare il nome dei giorni della settimana
void printDayOfWeek(int startMonth, int numMonths);

// Funzione per stampare la settimana dei quattro mesi
void printDays(const int day[],const int startDay[], int prevMonthDay[],int currentDay[], int numMonths, int startMonth, int year, const list<Task>& task);

// Funzione per stampare il quadrimestre
void printFourMonthly(int startMonth, int year,int monthPerRow, const list<Task> &task);



#endif //CALENDAR_H
