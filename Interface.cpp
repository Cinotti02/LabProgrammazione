//
// Created by francesco on 19/03/2025.
//

#include "Interface.h"

#include "Utility.h"

int Interface::menu() {
    int scelta;
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------"<<BOLDBLU<<" Menu scelta "<< RESET <<"----------------------------------------------------" << endl;
    cout << endl;
    cout << SPACEM "|0|" RESET "    print calendar" << endl;
    cout << SPACEM "|1|" RESET "    activities to do today" << endl;
    cout << SPACEM "|2|" RESET "    view your to-do list" << endl;
    cout << SPACEM "|3|" RESET "    search for activities whit a specific data" << endl;
    cout << SPACEM "|4|" RESET "    add new activity" << endl;
    cout << SPACEM "|5|" RESET "    mark an activity as completed" << endl;
    cout << SPACEM "|6|" RESET "    view all completed activities" << endl;
    cout << SPACEM "|7|" RESET "    delete an activity from the list" << endl;
    cout << SPACEM "|8|" RESET "    exit the program" << endl;
    cout << endl;
    controlcin(scelta);
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    return scelta;
}

bool Interface::choise(int c){
    switch (c) {
        case 0:
            printCalendar(Data::getCurrentDate().getYear());
            return true;

        case 1:
            todayTasks();
            return true;

        case 2:
            showIncompleteTasks();
            return true;

        case 3:
            searchByDate();
            return true;

        case 4:
            addTask();
            return true;

        case 5:
            setTaskCompleted();
            return true;

        case 6:
            showCompletedTasks();
            return true;

        case 7:
            removeTask();
            return true;

        case 8:
            cout << SPACE "exit the program" << endl;
            loadTaskOnJFile(filePath, tasks, completed);     // Save activities to file
            return false;

        default:
            cout << SPACE RED "Invalid choice!" RESET << endl;
            return true;
    }
}

void Interface::printCalendar(const int year) {
    const int monthPerRow=4;
    for (int i = 1; i <= 12; i +=monthPerRow) {
        printFourMonthly(i, year, monthPerRow, tasks);
        cout << endl;
    }
}

void Interface::todayTasks() {
    Data d = Data::getCurrentDate();
    cout << endl;
    cout << SPACEM "Today is " << d.toString() << RESET << endl;
    cout << endl;
    int i = 1;
    for (auto & it : tasks) {
        if (it.getDate().toString() == d.toString()) {
            if (i == 1)
                cout << SPACE "activities to do today:" RESET << endl;
            cout << SPACEM << i << ". " RESET << it.getName() << endl;
            i++;
        }
    }
    if (i == 1)
        cout << SPACE "no activities to do today" RESET << endl;
    cout << endl;
}


