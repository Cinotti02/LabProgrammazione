//
// Created by francesco on 19/03/2025.
//

#ifndef INTERFACE_H
#define INTERFACE_H
#include <list>

#include "Task.h"


class Interface {
public:

private:
    list<Task> tasks;
    list<Task> completed;
    const string filePath;


};



#endif //INTERFACE_H
