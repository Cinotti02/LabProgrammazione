//
// Created by francesco on 17/03/2025.
//

#include "Calendar.h"


int daysInMonth(int month, int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2)
        return(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
    else
        return 31;
}

int firstDayOfMonth(int month, int year) {
    tm time_in = {};
    time_in.tm_year = year - 1900;
    time_in.tm_mon = month - 1;
    time_in.tm_mday = 1;
    mktime(&time_in);
    int dayOfWeek = (time_in.tm_wday + 6) % 7; // 0 = Lunedì, 1 = Martedì, ..., 6 = Domenica
    return dayOfWeek;
}

void printMonth(int monthsPerRpw, int startMonth, int year) {
    const string months[] = {"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno",
                             "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"};
    for (int i = 0; i < monthsPerRpw; i++) {
        cout << setw(15) << BOLDBLU << months[startMonth + i - 1] + " " + to_string(year) << RESET << "         ";
    }
    cout << endl;
}
void printDayOfWeek( int startMonth,int numMonths) {
    const string daysOfWeek = "Lu Ma Me Gi Ve Sa Do";
    for (int i = 0; i < numMonths; i++) {
        if (startMonth + i <= 12)
            cout << setw(6) << GREEN << daysOfWeek << RESET << "      ";
    }
    cout << endl;
}
void printDays(const int day[],const int startDay[], int prevMonthDay[], int currentDay[], int numMonths, int startMonth, int year, list<Task> task) {
    for (int i = 0; i < numMonths; i++) {   //        //stampa i mesi
        if (currentDay[i] == 1) {
            for (int j = startDay[i] - 1; j >= 0; j--) {                      // Stampa i giorni del mese precedente
                cout << GRAY << setw(3) << (prevMonthDay[i] - j) << RESET;
            }
        }

        while (true) {
            bool isHighlighted = false;          // Controlla se il giorno è un'attività
            for (auto l : task){
                if (currentDay[i] == l.getDate().getDay() && startMonth + i == l.getDate().getMonth() && year == l.getDate().getYear()) {
                    cout << RED << setw(3) << currentDay[i] << RESET;
                    isHighlighted = true;
                    break;
                }
            }
            if (!isHighlighted && currentDay[i] <= day[i]) {
                cout << setw(3) << currentDay[i];
            }
            if (currentDay[i] > day[i])
                cout << setw(3) << "  ";

            if ((startDay[i] + currentDay[i]) % 7 == 0) {   // Vai a capo alla fine della settimana
                currentDay[i]++;
                break;
            }
            currentDay[i]++;                            // Passa al giorno successivo
        }

        int remainingSpaces = (7 - (startDay[i] + currentDay[i] -2) % 7);  // **Aggiungere spazi extra se l'ultima riga è corta**
        cout << setw(remainingSpaces *  3) << " "; // Riempie la riga

        cout << setw(3) << "  "; // Maggiore distanza tra i mesi
    }
    cout << endl;
}

void printFourMonthly(int startMonth, const int year, const int numMonths, const list<Task> &task) {

    printMonth(numMonths, startMonth, year);

    printDayOfWeek(startMonth, numMonths);

    int day[numMonths];                        // numero di giorni del mese
    int startDay[numMonths];                   // giorno della settimana di inizio mese
    int prevMonthDay[numMonths];               // numero di giorni del mese precedente
    int currentDay[numMonths];                 // giorno corrente per ogni mese

    for (int i = 0; i < numMonths; i++) {
        day[i] = daysInMonth(startMonth + i, year);
        startDay[i] = firstDayOfMonth(startMonth + i, year);
        prevMonthDay[i] = daysInMonth(startMonth + i - 1, year);
        currentDay[i] = 1;
    }

    int maxWeeks = 6;

    for (int row = 0; row < maxWeeks; row++) {
        printDays(day, startDay, prevMonthDay, currentDay, numMonths, startMonth, year, task);
    }
    cout << endl;
}