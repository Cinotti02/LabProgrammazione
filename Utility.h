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

string readFile(const string &nameFile);

void writeFile(const string &nameFile, const string &content);

void loadTaskOnJFile(const string &nomeFile, list<Task> &tasks, list<Task> &completed);

void loadTaskFromFile(const string &nameFile, list<Task> &tasks, list<Task> &completed);

void controlCin(int &choice);

void controlCinData(int &d, int &m, int &y);

static void cinFile();

#endif //UTILITY_H
