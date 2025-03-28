//
// Created by francesco on 12/03/2025.
//

#include "Task.h"
#include "Utility.h"

Task::Task(): completionDate() {
    string n; int d; int m; int y = 0;
    cout << SPACEM "- insert name of task: ";
    getline(cin >>ws, n);
    controlCinData(d, m, y);
    name = n;
    bool dataValida = false;
    do {
        try {
            controlCinData(d, m, y);
            date = Data(d, m, y);
            if (!date.isValid()) {
                throw runtime_error("created successfully");
            }
            dataValida = true;
            cout << SPACE << "Task " << n << " created successfully"<< endl;
        } catch (const runtime_error& e) {
            cout << SPACE << e.what() << " - Please enter a new date" RESET << endl;
        }
    } while (!dataValida);
}

Task::Task(string n, const Data d): name(std::move(n)), date(d),completionDate() {}

Task::Task(string n, const Data d, const Data c): name(std::move(n)), date(d), completionDate(c) {}

void Task::taskCompleted() {
    if (completionDate.toString() == "00/00/0000") {
        completionDate = Data::getCurrentDate();
    }
}

Task Task::fromJson(const json &json) {
    if (!json.contains("nome") || !json.contains("data") || !json.contains("dataCompletamento")) {
        throw runtime_error("JSON non valido: campi mancanti");
    }

    const string name = json["nome"];
    const Data data = Data::fromString(json["data"]);
    const Data dataCompletamento = Data::fromString(json["dataCompletamento"]);

    if (!data.isValid() || (dataCompletamento.toString() != "00/00/0000" && !dataCompletamento.isValid())) {
        throw runtime_error("Date non valide nel JSON");
    }

    return Task(name, data, dataCompletamento);
}

json Task::toJason() {
    json obj;
    obj["nome"] = name;
    obj["data"] = date.toString();
    obj["dataCompletamento"] = completionDate.toString();
    return obj;
}