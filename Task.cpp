//
// Created by francesco on 12/03/2025.
//

#include "Task.h"
#include "Utility.h"

Task::Task(const string &n, const string &desc, bool important, bool complete): name(n), description(desc), date(), completionDate(), important(important), completed(complete) {}

Task::Task(const string &n, const Data &d, const string &desc, bool important, bool complete): name(n), description(desc), date(d), completionDate(), important(important), completed(complete) {}

Task::Task(const Data &c, const string &n, const string &desc, bool important, bool complete): name(n), description(desc), date(), completionDate(c), important(important), completed(complete) {}

Task::Task(const string &n, const Data &d, const Data &c, const string &desc, bool important, bool complete): name(n), description(desc), date(d), completionDate(c), important(important), completed(complete) {}

void Task::taskCompleted() {
    completed = true;
    completionDate = Data::getCurrentDate();
}

Task Task::fromJson(const json &json) {
    if (!json.contains("nome")) {
        throw runtime_error("JSON non valido: campo nome mancante");
    }

    const string name = json["nome"];
    const string description = json["description"];
    const bool priority = json["priority"];

    Data dataCompletamento;
    if (json.contains("dataCompletamento")) {
        dataCompletamento = Data::fromString(json["dataCompletamento"]);
    } else {
        dataCompletamento = Data();
    }

    Data dataScadenza;
    if (json.contains("data scadenza")) {
        dataScadenza = Data::fromString(json["data scadenza"]);
    } else {
        dataScadenza = Data();
    }

    Task t(name, dataScadenza, dataCompletamento, description, priority);
    return t;
}

json Task::toJson() const{
    json obj;
    obj["nome"] = name;
    obj["description"] = description;
    obj["priority"] = important;
    if (date.toString() != "00/00/0000") {
        obj["data scadenza"] = date.toString();
        obj["dataCompletamento"] = completionDate.toString();
    }
    return obj;
}