#include "Interface.h"
#include "Utility.h"

int main() {
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|    " SPACE RED "          !!! Disclaimer !!!" RESET SPACE  "                 |"<< endl;
    cout << "|      for the correct operation of the program, please run the following command in the powershell terminal    |" << endl;
    cout << "|             Command:" GREEN "    reg add \"HKCU\\Console\" /v VirtualTerminalLevel /t REG_DWORD /d 1 /f" RESET "                   |" << endl;
    cout << "|                    this command allows the program to display the colored text correctly                      |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    ToDoList list;
    try {
        loadTaskFromFile(list);
    } catch (std::runtime_error& e) {
        cerr << "Fatal error \"" << e.what() << "\" the program can't keep running "<< endl;
        return 1;
    }

    bool running = true;
    int c = 0;

    while (running) {
        try {
            c = menu();
            running = choice(c, list);

        } catch (std::runtime_error &e) {
            cerr << "Fatal error \"" << e.what() << "\" the program can't keep running "<< endl;
            break;
        }
    }
}
