//
// Created by francesco on 19/03/2025.
//

#ifndef UTILITY_H
#define UTILITY_H

#include <list>
#include <filesystem>
#include <fstream>
#include "Task.h"

using namespace std;

string readFile(const string &nameFile);

void writeFile(const string &nameFile, const string &content);




#endif //UTILITY_H
