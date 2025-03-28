#include "Interface.h"
#include "Utility.h"

int main() {
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|    " SPACE RED "          !!! Disclaimer !!!" RESET SPACE  "                  |"<< endl;
    cout << "|      for the correct operation of the program, please run the following command in the powershell terminal    |" << endl;
    cout << "|             Command:" GREEN "    reg add \"HKCU\\Console\" /v VirtualTerminalLevel /t REG_DWORD /d 1 /f" RESET "                   |" << endl;
    cout << "|                    this command allows the program to display the colored text correctly                      |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    Interface inter;
    try {
        loadTaskFromFile(inter.getFilePath(), inter.getTaskList(), inter.getCompletedTaskList());
    } catch (std::runtime_error& e) {
        cerr << "Fatal error \"" << e.what() << "\" the program can't keep running "<< endl;
        return 1;
    }

    bool running = true;
    int choice = 0;

    inter.todayTasks();
    while (running) {
        try {
            choice = Interface::menu();
            running = inter.choice(choice);

        } catch (std::runtime_error &e) {
            cerr << "Fatal error \"" << e.what() << "\" the program can't keep running "<< endl;
            break;
        }
    }
}
