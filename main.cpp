#include "Interface.h"
#include "Utility.h"

int main() {
    Interface inter;
    loadTaskFromFile(inter.getFilePath(), inter.getTaskList(), inter.getCompletedTaskList());
    bool running = true;
    int choice = 0;

    inter.todayTasks();
    while (running) {
        choice = inter.menu();
        running = inter.choice(choice);
    }
}
