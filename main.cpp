#include <iostream>

#include "Interface.h"
#include "Task.h"


int main() {
    Interface inter;
    bool running = true;
    int choice;

    inter.todayTasks();
    while (running) {
        choice = inter.menu();
        running = inter.choice(choice);
    }
}