//
// Created by francesco on 12/03/2025.
//

#include "Task.h"
#include "Calendar.h"

Task::Task(): completionDate() {
    string n;
    int d;
    int m;
    int y = 0;
    cout << "insert name of task: ";
    cin >> n;
    int a = 0;
    while (y < 2025 || (d < 1 || d > daysInMonth(m, y)) || m < 1 || m > 12) {
        switch (a) {
            case 0: //TODO fix problem of insert string
                cout << "insert date " << endl;

                cout << "day: " << flush;
                cin >> d;
                cout << "month: " << flush;
                cin >> m;
                cout << "year: " << flush;
                cin >> y;

                a = 1;
                break;
            default:
                cout << "error data please rewrite" << endl;
                a = 0;
                break;
        }
    }
    name = n;
    date = Data(d, m, y);
} //TODO add control "cin not string"

Task::Task(string n, const Data d): name(std::move(n)), date(d),completionDate() {}

Task::Task(string n, const Data d, const Data c): name(std::move(n)), date(d), completionDate(c) {}

Task Task::fromJson(const json &json) {
    const string name = json["nome"];
    const Data data = Data::fromString(json["data"]);
    const Data dataCompletamento = Data::fromString(json["dataCompletamento"]);

    return Task(name, data, dataCompletamento);
}

json Task::toJason() {
    json obj;
    obj["nome"] = name;
    obj["data"] = date.toString();
    obj["dataCompletamento"] = completionDate.toString();
    return obj;
}