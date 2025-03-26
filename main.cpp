#include "Interface.h"
#include "Utility.h"

int main() {
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|    " SPACE RED "              Disclamer !!!" RESET SPACE  "                  |"<< endl;
    cout << "|      for the correct operation of the program, please run the following command in the powershell terminal    |" << endl;
    cout << "|             Command:" GREEN "    reg add \"HKCU\\Console\" /v VirtualTerminalLevel /t REG_DWORD /d 1 /f" RESET "                   |" << endl;
    cout << "|                    this command allows the program to display the colored text correctly                      |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

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
