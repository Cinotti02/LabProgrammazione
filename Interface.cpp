//
// Created by francesco on 19/03/2025.
//

#include "Interface.h"

int menu() {
    int choice;
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------"<<BOLDBLU<<" Menu "<< RESET <<"----------------------------------------------------" << endl;
    cout << endl;
    cout << SPACEM "|0|" RESET "    print calendar" << endl;
    cout << SPACEM "|1|" RESET "    Show tasks for today" << endl;
    cout << SPACEM "|2|" RESET "    View all uncompleted tasks" << endl;
    cout << SPACEM "|3|" RESET "    Search tasks by date" << endl;
    cout << SPACEM "|4|" RESET "    Add a new task" << endl;
    cout << SPACEM "|5|" RESET "    Complete a task" << endl;
    cout << SPACEM "|6|" RESET "    View completed tasks" << endl;
    cout << SPACEM "|7|" RESET "    Remove a task" << endl;
    cout << SPACEM "|8|" RESET "    Exit the program" << endl;
    cout << endl;
    controlCin(choice);
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    return choice;
}

bool choice(const int c, ToDoList& list){
    switch (c) {
        case 0:
            printCalendar(Data::getCurrentDate().getYear(), list);
            return true;

        case 1:
            todayTasks(list);
            return true;

        case 2:
            showUncompletedTask(list);
            return true;

        case 3:
            searchByDate(list);
            return true;

        case 4:
            createTasks(list);
            return true;

        case 5:
            setTaskCompleted(list);
            return true;

        case 6:
            showCompletedTasks(list);
            return true;

        case 7:
            removeTask(list);
            return true;

        case 8:
            try {
                cout << SPACE "exit the program..." << endl;
                loadTaskOnJFile(list);     // Save activities to file
            }
            catch (std::runtime_error &e) {
                cerr << "Fatal error \"" << e.what() << "\" the program can't keep running "<< endl;
            }
            return false;

        default:
            cout << SPACE RED "Invalid choice!" RESET << endl;
            return true;
    }
}

void printCalendar(const int year, ToDoList& list) {
    constexpr int monthPerRow=4;
    for (int i = 1; i <= 12; i +=monthPerRow) {
        printFourMonthly(i, year, monthPerRow, list);
        cout << endl;
    }
}

void todayTasks(ToDoList &list){
    const Data d = Data::getCurrentDate();
    cout << endl;
    cout << SPACEM "Today is " << d.toString() << RESET << endl;
    cout << endl;
    int i = 1;
    for (auto & it : list.getUncompletedTasks()) {
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

void showUncompletedTask(ToDoList &list) {
    if (list.getUncompletedTasks().begin() == list.getUncompletedTasks().end()) {
        cout <<SPACEM "you have no activities to do" RESET << endl;
    }
    else {
        cout << SPACEM "           activities to do:" RESET << endl;
        int i = 1;
        for (auto & it : list.getUncompletedTasks()) {
            cout << SPACEM << i << ". " RESET << it.getName()<< " " << it.getDate().toString()<< endl;
            i++;
        }
    }
}

void searchByDate(const ToDoList &list) {
    if (list.getUncompletedTasks().begin() == list.getUncompletedTasks().end()) {
        cout << SPACEM "you have no activities to do on this date" RESET<< endl;
        return;
    }

    int d, m, y;
    controlCinData(d, m, y);
    Data date(d, m, y);

    auto tasks = list.getTasksByDate(date);

    if (tasks.empty()) {
        cout << SPACE RED "There are no activities on this date." RESET << endl;
    } else {
        int i = 1;
        cout << SPACEM "Activities present on: " RESET << date.toString() << endl;
        for (const auto& task : tasks) {
            cout << SPACEM << i << ". " RESET << task.getName() << endl;
            i++;
        }
    }
}

void setTaskCompleted(ToDoList &list) {
    if (list.getUncompletedTasks().empty()) {
        cout << SPACE "No activities to complete!";
        return;
    }
    bool a = true;
    while (a) {
        int i = 1;
        cout << SPACEM "Activities present in the list:" RESET << endl;
        for (auto & it : list.getUncompletedTasks()) {
            cout << SPACEM << i << ". " RESET << it.getName()<< " " << endl;
            i++;
        }
        cout << SPACEM "Enter the name of the completed activity: ";
        string name;
        getline(cin >> ws, name);

        try {
            if (list.completeTaskByName(name)) {
                cout << SPACEM "Activity completed successfully: " << name << endl;
                return;
            } else {
                cout << SPACEM RED "!!! Activity name incorrect or not present in the list !!!" RESET << endl;
                cout << endl;
                reinsertName(name, a);
            }
        } catch (const runtime_error& e) {
            cerr << SPACEM RED << e.what() << RESET << endl;
            reinsertName(name, a);
        }
    }
}


void showCompletedTasks(ToDoList &list) {
    if (list.getCompletedTasks().begin() == list.getCompletedTasks().end()) {
        cout << SPACEM "you have no completed activities" RESET << endl;
    }
    else {
        cout << SPACEM "           completed activities:" RESET << endl;
        int i = 1;
        for (auto & it : list.getCompletedTasks()) {
            cout << SPACEM << i << ". " RESET << it.getName()<< " " << it.getDate().toString()<< " " << it.getCompletionDate().toString() << endl;
            i++;
        }
    }
}

void removeTask(ToDoList &list) {
    if (list.getUncompletedTasks().empty()) {
        cout << SPACE "No activities in the list!";
        return;
    }
    bool a = true;
    while (a) {
        int i = 1;
        cout << SPACE "Activities present in the list:" << endl;
        for (auto & it : list.getUncompletedTasks()) {
            cout << SPACE << i << ". " << it.getName()<< " " << endl;
            i++;
        }

        cout << SPACE "Enter the name of the activity to be removed: ";
        string name;
        cin >> name;

        if (list.removeTaskByName(name)) {
            cout << SPACE "Activity removed successfully: " << name << endl;
            return;
        }
        cout << SPACE RED"!!! activity name incorrect or not present in the list !!!" RESET << endl;
        cout << endl;
        reinsertName(name, a);
    }
}

void reinsertName(string nome, bool &a) {
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

void createTasks(ToDoList &list) {
    cout << SPACEM "Create new task: " RESET << endl;
    cout << endl;


    cout << SPACEM "- insert name of task: ";
    string name;
    getline(cin >>ws, name);

    cout << "Do you want to add a description? (Y/N)" << endl;
    bool wantsDescription = choiceB();
    string description;
    if (wantsDescription) {
        cout << SPACEM "- insert description: ";
        getline(cin >> ws, description);
    }

    cout << "Do you want to add a deadline date? (Y/N)" << endl;
    bool wantsDate = choiceB();
    Data deadline(0, 0, 0, false);

    if (wantsDate) {
        while (true) {
            try {
                int d, m, y;
                controlCinData(d, m, y);
                deadline = Data(d, m, y);
                break;
            } catch (const runtime_error& e) {
                cerr << SPACE RED << e.what() << " - Please enter a valid date." RESET << endl;
            }
        }
    }

    try {
        list.createAndAddTask(name, description, deadline);
        cout << SPACEM "Task '" << name << "' added successfully!" RESET << endl;
    } catch (const runtime_error& e) {
        cerr << SPACE RED << e.what() << RESET << endl;
        cout << endl;
    }
}

bool choiceB() {
    string c;
    while (true) {
        cout << SPACE "choice:";cin >> c;
        if (c == "Y" || c == "y" || c == "yes" || c == "Yes") {
            return true;
        }
        if(c == "N" || c == "n" || c == "no" || c == "No")
            return false;
        cout << SPACE RED"        !!! invalid choice !!!" << endl;
    }
}
