//
// Created by francesco on 12/03/2025.
//

#ifndef TASK_H
#define TASK_H
#include <iostream>
#include "Data.h"
#include "nlohmann/json.hpp"

#define RED       "\033[31m"            // Testo rosso
#define GRAY      "\033[90m"            // Testo grigio
#define GREEN     "\033[32m"            // Testo verde
#define BOLDBLU   "\033[1m\033[34m"     // Testo blu in grassetto
#define RESET     "\033[0m"             // Reset colori
#define SPACEM "                               " BOLDBLU             // Spazio per allineare il testo e colore blu
#define SPACE  "                               "                     // Spazio per allineare il testo

using namespace std;
using namespace nlohmann;

class Task {
public:
    Task();                       //TODO da migliorare gli spazi tra le righe nel terminale
    Task(string n, Data d);;
    Task(string n, Data d, Data c);

    void taskCompleted() {
        completionDate = Data::getCurrentDate();
    }

    static Task fromJson(const json &json);

    json toJason();

    string getName() const{
        return name;
    }

    Data getDate() const {
        return date;
    }

    Data getCompletionDate() const {
        return completionDate;
    }

private:
    string name;
    Data date{};
    Data completionDate;
};



#endif //TASK_H
