//
// Created by francesco on 19/03/2025.
//

#ifndef UTILITY_H
#define UTILITY_H

#include <list>
#include <filesystem>
#include <fstream>
#include "Calendar.h"

using namespace std;

string readFile(const string &nameFile);  //Legge il contenuto di un file e lo restituisce come stringa

void writeFile(const string &nameFile, const string &content);  //Scrive il contenuto di una stringa in un file

void loadTaskOnJFile(const string &nameFile, list<Task> &tasks, list<Task> &completed);  //Carica le attività da una lista di attività e le memorizza in una un file JSON

void loadTaskFromFile(const string &nameFile, list<Task> &tasks, list<Task> &completed);  //Carica le attività da un file JSON e le memorizza in una lista di attività

void controlCin(int &choice);  //Controlla l'input dell'utente e gestisce gli errori

void controlCinData(int &d, int &m, int &y);  //Controlla l'input della data dell'utente e gestisce gli errori

static void cinFile();

#endif //UTILITY_H
