//
// Created by francesco on 17/03/2025.
//

#ifndef CALENDAR_H
#define CALENDAR_H

#define RED       "\033[31m"            // Testo rosso
#define GRAY      "\033[90m"            // Testo grigio
#define GREEN     "\033[32m"            // Testo verde
#define BOLDBLU   "\033[1m\033[34m"     // Testo blu in grassetto
#define RESET     "\033[0m"             // Reset colori

#include <list>
#include "Task.h"

using namespace std;

// Funzione per ottenere il numero di giorni in un mese
int daysInMonth(int month, int year);

// Funzione per ottenere il giorno della settimana del primo giorno del mese
int firstDayOfMonth(int month, int year);

// Funzione per stampare il mese
void printMonth(int monthPerRow,int startMonth, int year);

void printDayOfWeek(int startMonth, int numMonths);

void printDays(const int day[],const int startDay[], int prevMonthDay[],int currentDay[], int numMonths, int startMonth, int year, list<Task> task);

// Funzione per stampare il quadrimestre
void printFourMonthly(int startMonth, int year,int monthPerRow, const list<Task> &task);



#endif //CALENDAR_H
