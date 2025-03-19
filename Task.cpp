//
// Created by francesco on 12/03/2025.
//

#include "Task.h"

Task::Task() {
    string n; int d; int m; int y = 0;
    cout << "insert name of task: ";
    cin >> n;
    int a = 0;
    while (y < 2025 || (d < 1 || d > Data::daysInMonth(m, y)) || m < 1 || m > 12) {
        switch (a) {
            case 0:                                            //TODO fix problem of insert string
                cout << "insert date " << endl;

                cout << "day: "<< flush;
                cin >> d;
                cout << "month: " << flush;
                cin >> m;
                cout << "year: " << flush;
                cin >> y;

                a = 1;
                break;
            case 1:
                cout << "error data please rewrite" << endl;
                a = 0;
            break;
        }
    }
    name = n;
    date = Data(d, m, y);
} //TODO add controll "cin not string"

Task Task::fromJson(const json &json) {
    string name = json["nome"];
    Data data = Data::fromString(json["data"]);
    Data dataCompletamento = Data::fromString(json["dataCompletamento"]);

    return Task(name, data, dataCompletamento);
}

json Task::toJason() {
    json obj;
    obj["nome"] = name;
    obj["data"] = date.toString();
    obj["dataCompletamento"] = completionDate.toString();
    return obj;
}