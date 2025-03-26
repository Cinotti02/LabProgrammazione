#include "Interface.h"

int main() {
    Interface inter;
    bool running = true;
    int choice = 0;

    inter.todayTasks();
    while (running) {
        choice = inter.menu();
        running = inter.choice(choice);
    }
}