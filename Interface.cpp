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

void Interface::showIncompleteTasks() {
    if (tasks.begin() == tasks.end()) {
        cout <<SPACEM "you have no activities to do" RESET << endl;
    }
    else {
        cout << SPACEM "           activities to do:" RESET << endl;
        int i = 1;
        for (auto & it : tasks) {
            cout << SPACEM << i << ". " RESET << it.getName()<< " " << it.getDate().toString()<< endl;
            i++;
        }
    }
}

void Interface::searchByDate() {
    if (tasks.begin() == tasks.end()) {
        cout << SPACEM "you have no activities to do on this date" RESET<< endl;
    }
    else {
        int d, m, y;
        controlCinData(d, m, y);
        int i = 1;
        for(auto & it : tasks) {
            if (d == it.getDate().getDay() && m == it.getDate().getMonth() && y == it.getDate().getYear()) {
                if (i == 1)
                    cout << SPACEM "Activities present on the date: " RESET << it.getDate().toString() << endl;
                cout << SPACEM << i << ". " RESET << it.getName() << endl;
                cout << endl;
                i++;
            }
        }
        if (i == 1){
            cout << SPACE RED "          there are no activities on this date" RESET << endl;
        }
    }
}

void Interface::addTask() {
    cout << SPACEM "Create new activity: " RESET << endl;
    cout << endl;
    Task task;
    tasks.push_back(task);
    cout << SPACEM "added " << task.getName() <<" to your list successfully" << RESET << endl;
}

void Interface::setTaskCompleted() {
    if (tasks.empty()) {
        cout << SPACE "No activities to complete!";
    }
    else{
        bool a = true;
        while (a) {
            int i = 1;
            cout << SPACEM "Activities present in the list:" RESET << endl;
            for (auto & it : tasks) {
                cout << SPACEM << i << ". " RESET << it.getName()<< " " << endl;
                i++;
            }
            cout << SPACEM "Enter the name of the completed activity: ";
            string name;
            getline(cin >> ws, name);

            for (auto it = tasks.begin(); it != tasks.end(); ++it) {
                if (it->getName() == name) {
                    cout << SPACEM "Complete the activity: " << it->getName() << endl;
                    it->taskCompleted();
                    completed.push_back(*it);
                    tasks.erase(it);
                    cout << SPACEM "Activity completed at: " << completed.back().getCompletionDate().toString() << endl;
                    return;
                }
            }
            cout << SPACEM RED"!!! activity name incorrect or not present in the list !!!" RESET << endl;
            cout << endl;
            reinsertName(name, a);
        }
    }
}

void Interface::showCompletedTasks() {
    if (completed.begin() == completed.end()) {
        cout << SPACEM "you have no completed activities" RESET << endl;
    }
    else {
        cout << SPACEM "           completed activities:" RESET << endl;
        int i = 1;
        for (auto & it : completed) {
            cout << SPACEM << i << ". " RESET << it.getName()<< " " << it.getDate().toString()<< " " << it.getCompletionDate().toString() << endl;
            i++;
        }
    }
}

void Interface::removeTask() {
    bool a = true;
    if (tasks.empty()) {
        cout << SPACE "No activities in the list!";
    }
    else {
        while (a) {
            int i = 1;
            cout << SPACE "Activities present in the list:" << endl;
            for (auto & it : tasks) {
                cout << SPACE << i << ". " << it.getName()<< " " << endl;
                i++;
            }
            cout << SPACE "Enter the name of the activity to be removed: ";
            string name;
            cin >> name;
            for (auto it = tasks.begin(); it != tasks.end(); ++it) {
                if (it->getName() == name) {
                    cout << SPACE "activity removed successfully: " << tasks.front().getName() << endl;
                    tasks.erase(it);
                    return;
                }
            }
            cout << SPACE RED"!!! activity name incorrect or not present in the list !!!" RESET << endl;
            cout << endl;
            reinsertName(name, a);
        }
    }
}

void Interface::reinsertName(string nome, bool &a) {
    cout << SPACE "do you want to enter a different name? Y/N" << endl;
    while (true) {
        cout << SPACE "choice:";cin >> nome;
        if (nome == "N" || nome == "n" || nome == "no" || nome == "No") {
            a = false;
            return;
        }
        if (nome == "Y" || nome == "y" || nome == "yes" || nome == "Yes")
            return;
        cout <<SPACE RED"        !!! invalid choice !!!" << endl;
        cout << endl;
    }
}

int Interface::controlcin(int &scelta) {
    while (true) {
        cout << SPACEM "choice: " RESET ;cin >> scelta;
        if (cin.fail()) {
            cout <<SPACE RED " !!! Error: Enter a valid number !!! " RESET << endl;
            cin.clear();                                      // Reset error state
            cin.ignore(1000, '\n');                   // Clear the buffer until a new input
            cout << endl;
            continue;
        }
        break;
    }
}