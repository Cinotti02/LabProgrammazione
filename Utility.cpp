//
// Created by francesco on 19/03/2025.
//

#include "Utility.h"

string readFile(const string &nameFile) {
    ifstream file(nameFile);
    if (!file) {
        cerr << "Errore: impossibile aprire il file!\n";
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
        cerr << "Errore: impossibile creare il file!\n";
        return;
    }

    file << content;
    file.close();
}