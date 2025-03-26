//
// Created by francesco on 19/03/2025.
//

#include "Utility.h"

string readFile(const string &nameFile) {
    ifstream file(nameFile);
    if (!file) {
        cerr << SPACE RED "       Error: Unable to open file!" RESET << endl;
        return "";
    }

    string content;
    string line;

    while (getline(file, line)) {
        content += line + "\n";
    }

    file.close();
    return content;
}

void writeFile(const string &nameFile, const string &content) {
    ofstream file(nameFile, ios::out);
    if (!file) {
        cerr << SPACE RED "       Error: Unable to open file!" RESET << endl;
        return;
    }

    file << content;
    file.close();
}

void loadTaskOnJFile(const string &nameFile, list<Task> &tasksList, list<Task> &completed) {
    json j;
    auto array = json::array();
    auto arrayC = json::array();

    for (auto &task : tasksList) {
        array.push_back(task.toJason());
    }
    j["tasks to complete"] = array;

    for (auto &task : completed) {
        arrayC.push_back(task.toJason());
    }
    j["completed tasks"] = arrayC;

    writeFile(nameFile, j.dump(4));

    cout << SPACE "       Tasks saved successfully!" <<endl;
}

void loadTaskFromFile(const string &nameFile, list<Task> &tasksList, list<Task> &completedList) {
    ifstream file(nameFile);
    if (!file) {
        cerr << SPACE RED "       Error: Unable to open file!" RESET << endl;
        return;
    }
    tasksList.clear();
    completedList.clear();

    string contentFile = readFile(nameFile);
    json j = json::parse(contentFile);

    json tasks = j["tasks to complete"];
    json completed = j["completed tasks"];

    for (const auto& task : tasks) {
        tasksList.push_back(Task::fromJson(task));
    }

    for (const auto& task : completed) {
        completedList.push_back(Task::fromJson(task));
    }
    file.close();
}