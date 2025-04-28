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
    explicit Task(const string &n,const string &desc = "", bool important = false, bool complete = false); //Costruttore per la scrittura su file

    Task(const string &n, const Data &d ,const string &desc = "", bool important = false, bool complete = false);

    Task(const Data &c, const string &n, const string &desc = "", bool important = false, bool complete = false); //Costruttore per la scrittura su file

    Task(const string &n, const Data &d, const Data &c, const string &desc = "", bool important = false, bool complete = false); //Costruttore per la scrittura su file

    void taskCompleted();  //funzione per segnare un'attività come completata

    static Task fromJson(const json &json);  //funzione per creare un'attività da un oggetto JSON

    json toJson() const;  //funzione per convertire un'attività in un oggetto JSON

    string getName() const{
        return name;
    }

    Data getDate() const {
        return date;
    }

    Data getCompletionDate() const {
        return completionDate;
    }
    bool getCompleted() const {
        return completed;
    }

    bool getImportant() const {
        return important;
    }

    bool operator==(const Task& other) const {
        return name == other.name && date == other.date && description == other.description;
    }
private:
    string name;
    string description;
    bool completed;
    bool important;
    Data date;
    Data completionDate;
};



#endif //TASK_H
