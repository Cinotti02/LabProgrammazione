//
// Created by francesco on 19/03/2025.
//

#include "Utility.h"


string readFile(const string &nameFile) { //FIXME passaggio di parametri string o ToDoList list.getFilePath()??
    ifstream file(nameFile);
    if (!file) {
        throw runtime_error("Unable to open file " + nameFile);
    }

    string content;
    string line;

    while (getline(file, line)) {
        content += line + "\n";
    }

    file.close();
    return content;
}
//bool al posto di void
void writeFile(const string &nameFile, const string &content) { //FIXME passaggio di parametri string o ToDoList list.getFilePath()??
    ofstream file(nameFile, ios::out);
    if (!file) {
        throw runtime_error(SPACE RED "Unable to open file for writing" RESET);
    }

    file << content;
    file.close();
}

void loadTaskOnJFile(const ToDoList &todo) {
    json j;
    auto array = json::array();
    auto arrayC = json::array();

    for (auto &task : todo.getTasks()) {
        if (task.getCompleted() == false)
            array.push_back(task.toJson());
        else
            arrayC.push_back(task.toJson());
    }
    j["tasks to complete"] = array;
    j["completed tasks"] = arrayC;

    try {
        writeFile(todo.getFilePath(), j.dump(4));
    }
    catch (std::runtime_error &e) {
        throw runtime_error(e.what());
    }

    cout << SPACE "       Tasks saved successfully!" <<endl;
}

void loadTaskFromFile(ToDoList &todo) {
    ifstream file(todo.getFilePath());
    if (!file) {
        // File non trovato? Lo creiamo automaticamente vuoto
        ofstream newFile(todo.getFilePath());
        newFile << R"({"tasks to complete": [], "completed tasks": []})";
        newFile.close();
        cout << SPACE "No file found, created a new empty task list." << endl;
    }

    string contentFile = readFile(todo.getFilePath());
    if (contentFile.empty()) {
        cout << SPACE "Warning: File is empty. Initializing empty task list." << endl;
        return;
    }

    try {
        json j = json::parse(contentFile);

        todo.removeAllUncompletedTasks();

        json tasks = j["tasks to complete"];
        json completed = j["completed tasks"];

        for (const auto& taskJson : tasks) {
            todo.createAndAddTask(taskJson["nome"], taskJson["description"], taskJson.contains("data scadenza") ? Data::fromString(taskJson["data scadenza"]) : Data(0,0,0,false), taskJson["priority"]);
        }

        for (const auto& taskJson : completed) {
            todo.createAndAddTask(taskJson["nome"], taskJson["description"], taskJson.contains("data scadenza") ? Data::fromString(taskJson["data scadenza"]) : Data(0,0,0,false), taskJson["priority"], true,Data::fromString(taskJson["dataCompletamento"]));
        }
    }
    catch (const std::exception& e) {
        cerr << SPACE RED "Error parsing file: " << e.what() << RESET << endl;
        throw runtime_error("Invalid JSON structure!");
    }
}


void controlCin(int &choice) {
    while (true) {
        cout << SPACEM "choice: " RESET ;cin >> choice;
        if (cin.fail()) {
            cinFile();
            continue;
        }
        break;
    }
}

void controlCinData(int &d, int &m, int &y) {
    while (true) {
        cout << SPACEM "- insert date " RESET << endl;
        cout << SPACE "day: "; cin >> d;
        if (cin.fail() || cin.eof()) {
            cinFile();
            continue;
        }
        cout << SPACE "month: "; cin >> m;
        if (cin.fail() || cin.eof()) {
            cinFile();
            continue;
        }
        cout << SPACE "year: "; cin >> y;
        if (cin.fail() || cin.eof()) {
            cinFile();
            continue;
        }
        break;
    }
}

void cinFile() {
    cout << SPACE RED " !!! Error: Enter a valid number !!! " RESET << endl;
    cin.clear();                                      // Reset error state
    cin.ignore(1000, '\n');                   // Clear the buffer until a new input
    cout << endl;
}