//
// Created by francesco on 19/03/2025.
//

#include "Utility.h"


string readFile(const string &nameFile) {
    ifstream file(nameFile, ios::in);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file " + nameFile);
    }

    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

//bool al posto di void
void writeFile(const string &nameFile, const string &content) {
    ofstream file(nameFile, ios::out | ios::trunc);
    if (!file) {
        throw runtime_error(SPACE RED "Unable to open file for writing" RESET);
    }
    file << content;
}

void loadTaskOnJFile(const ToDoList &todo) {
    json j;
    auto array = json::array();
    auto arrayC = json::array();

    for (const auto &task : todo.getTasks()) {
        (task.getCompleted() ? arrayC : array).push_back(task.toJson());
    }
    j["tasks to complete"] = array;
    j["completed tasks"] = arrayC;

    writeFile(todo.getFilePath(), j.dump(4));

    cout << SPACE "       Tasks saved successfully!" <<endl;
}

void loadTaskFromFile(ToDoList &todo) {
    using namespace std::filesystem;
    if (!exists(todo.getFilePath())) {
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
        const json j = json::parse(contentFile);

        todo.clearTasks();

        for (const auto& taskJson : j["tasks to complete"]) {
            todo.createAndAddTask(taskJson["nome"], taskJson["description"], taskJson.contains("data scadenza") ? Data::fromString(taskJson["data scadenza"]) : Data(), taskJson["priority"]);
        }

        for (const auto& taskJson : j["completed tasks"]) {
            todo.createAndAddTask(taskJson["nome"], taskJson["description"], taskJson.contains("data scadenza") ? Data::fromString(taskJson["data scadenza"]) : Data(), taskJson["priority"], true,Data::fromString(taskJson["dataCompletamento"]));
        }
    }
    catch (const std::exception& e) {
        cerr << SPACE RED "Error parsing file: " << e.what() << RESET << endl;
        throw runtime_error("Invalid JSON structure!");
    }
}


void controlCin(int &choice) {
    while (true) {
        cout << SPACEM "choice: " RESET;
        cin >> choice;
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
        if (cin.fail()) {
            cinFile();
            continue;
        }
        cout << SPACE "month: "; cin >> m;
        if (cin.fail()) {
            cinFile();
            continue;
        }
        cout << SPACE "year: "; cin >> y;
        if (cin.fail()) {
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