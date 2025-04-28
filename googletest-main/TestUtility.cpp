//
// Created by francesco on 27/04/2025.
//
#include <gtest/gtest.h>
#include "../Utility.h"


TEST(UtilityTest, FileReadWrite) {
    const string filename = "testfile.txt";
    const string content = "Hello World";

    writeFile(filename, content);
    string readContent = readFile(filename);

    // Verifica che il contenuto letto corrisponda a quello scritto (ignorando eventuali '\n' aggiunti)
    readContent.erase(remove(readContent.begin(), readContent.end(), '\n'), readContent.end());
    EXPECT_EQ(readContent, content);

    remove(filename.c_str()); // Cleanup
}
TEST(UtilityTest, LoadTaskOnJFile) {
    ToDoList list;
    list.addTask(Task("TaskTest"));

    EXPECT_NO_THROW(loadTaskOnJFile(list));
}

TEST(UtilityTest, ControlCin_ValidInput) {
    istringstream fakeInput("5\n");
    cin.rdbuf(fakeInput.rdbuf());

    int choice;
    EXPECT_NO_THROW(controlCin(choice));
    EXPECT_EQ(choice, 5);
}

TEST(UtilityTest, ControlCinData_ValidInput) {
    istringstream fakeInput("1\n1\n2025\n");
    cin.rdbuf(fakeInput.rdbuf());

    int d, m, y;
    EXPECT_NO_THROW(controlCinData(d, m, y));
    EXPECT_EQ(d, 1);
    EXPECT_EQ(m, 1);
    EXPECT_EQ(y, 2025);
}

TEST(UtilityTest, ControlCin_InvalidInput) {
    istringstream fakeInput("abc\n5\n");
    cin.rdbuf(fakeInput.rdbuf());

    int choice;
    EXPECT_NO_THROW(controlCin(choice));
    EXPECT_EQ(choice, 5);
}

TEST(UtilityTest, LoadTaskFromFile_Robust) {
    // Crea un JSON complesso
    json j;
    j["tasks to complete"] = {
        {
            {"nome", "IncompleteTask"},
            {"description", "Do something"},
            {"priority", true},
            {"data scadenza", "10/12/2025"}
        }
    };
    j["completed tasks"] = {
        {
            {"nome", "CompletedTask"},
            {"description", "Already done"},
            {"priority", false},
            {"data scadenza", "01/01/2025"},
            {"dataCompletamento", "02/01/2025"}
        }
    };

    const string filename = "testfile.json";
    ofstream file(filename);
    file << j.dump(4);
    file.close();

    // Prepara la ToDoList
    ToDoList list;
    list.setFilePath(filename);

    // Carica i task dal file
    EXPECT_NO_THROW(loadTaskFromFile(list));

    // Verifica che i task siano caricati correttamente
    EXPECT_EQ(list.getTasks().size(), 2);
    EXPECT_EQ(list.getUncompletedTasks().size(), 1);
    EXPECT_EQ(list.getCompletedTasks().size(), 1);

    // Verifica i dati del task incompleto
    const Task& uncompleted = list.getUncompletedTasks().front();
    EXPECT_EQ(uncompleted.getName(), "IncompleteTask");
    EXPECT_TRUE(uncompleted.getImportant());
    EXPECT_EQ(uncompleted.getDate().toString(), "10/12/2025");

    // Verifica i dati del task completato
    const Task& completed = list.getCompletedTasks().front();
    EXPECT_EQ(completed.getName(), "CompletedTask");
    EXPECT_FALSE(completed.getImportant());
    EXPECT_EQ(completed.getDate().toString(), "01/01/2025");
    EXPECT_EQ(completed.getCompletionDate().toString(), "02/01/2025");

    // Pulizia
    remove(filename.c_str());
}

TEST(UtilityTest, LoadTaskFromMissingFile) {
    ToDoList list;
    list.setFilePath("nonexistentfile.json");
    EXPECT_NO_THROW(loadTaskFromFile(list));
}

TEST(UtilityTest, LoadTaskFromEmptyFile) {
    const string filename = "emptyfile.json";
    ofstream emptyFile(filename); // Crea file vuoto
    emptyFile.close();

    ToDoList list;
    list.setFilePath(filename);

    EXPECT_NO_THROW(loadTaskFromFile(list));

    remove(filename.c_str());
}

TEST(UtilityTest, LoadTaskFromInvalidJsonFile) {
    const string filename = "invalidfile.json";
    ofstream invalidFile(filename);
    invalidFile << "This is not JSON!";
    invalidFile.close();

    ToDoList list;
    list.setFilePath(filename);

    EXPECT_THROW(loadTaskFromFile(list), runtime_error);

    remove(filename.c_str());
}