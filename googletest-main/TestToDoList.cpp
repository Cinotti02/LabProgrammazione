//
// Created by francesco on 27/04/2025.
//
#include <gtest/gtest.h>
#include "../ToDoList.h"


TEST(ToDoListTest, AddTask) {
    ToDoList list;
    Task t("Task", "desc");
    list.addTask(t);
    EXPECT_EQ(list.getTasks().size(), 1);
    EXPECT_EQ(list.getTasks().front().getName(), "Task");
}

TEST(ToDoListTest, RemoveTask) {
    ToDoList list;
    Task t("Task", "desc");
    list.addTask(t);
    EXPECT_TRUE(list.removeTask(t));
    EXPECT_TRUE(list.getTasks().empty());
}

TEST(ToDoListTest, RemoveAllUncompletedTasks) {
    ToDoList list;
    list.addTask(Task("Task1"));
    list.addTask(Task("Task2"));
    list.removeAllUncompletedTasks();
    EXPECT_TRUE(list.getTasks().empty());
}

TEST(ToDoListTest, SetAndGetFilePath) {
    ToDoList list;
    list.setFilePath("./newpath.json");
    EXPECT_EQ(list.getFilePath(), "./newpath.json");
}

TEST(ToDoListTest, GetImportantTasks) {
    ToDoList list;
    Task importantTask("Task1", "desc", true);
    list.addTask(importantTask);
    EXPECT_EQ(list.getImportantTasks().size(), 1);
    EXPECT_TRUE(list.getImportantTasks().front().getImportant());
}

TEST(ToDoListTest, GetCompletedAndUncompletedTasks) {
    ToDoList list;
    Task t("Task", "desc");
    list.addTask(t);

    auto tasks = list.getTasks();
    auto it = tasks.begin();
    Task modifiedTask = *it;
    modifiedTask.taskCompleted();
    list.removeTask(*it);
    list.addTask(modifiedTask);

    EXPECT_EQ(list.getCompletedTasks().size(), 1);
    EXPECT_EQ(list.getUncompletedTasks().size(), 0);
}

TEST(ToDoListTest, GetTasksByDate) {
    ToDoList list;
    Data date1(20, 5, 2025);
    Data date2(21, 5, 2025);

    list.createAndAddTask("Task1", "TestDesc", date1);
    list.createAndAddTask("Task2", "TestDesc", date2);

    auto tasksOnDate1 = list.getTasksByDate(date1);
    auto tasksOnDate2 = list.getTasksByDate(date2);

    EXPECT_EQ(tasksOnDate1.size(), 1);
    EXPECT_EQ(tasksOnDate1.front().getName(), "Task1");

    EXPECT_EQ(tasksOnDate2.size(), 1);
    EXPECT_EQ(tasksOnDate2.front().getName(), "Task2");
}

TEST(ToDoListTest, CreateAndAddTask) {
    ToDoList list;
    Data d(10, 10, 2025);

    // Crea e aggiungi direttamente
    list.createAndAddTask("Test", "desc", d);

    // Verifica che sia stato aggiunto
    EXPECT_EQ(list.getTasks().size(), 1);

    const Task& t = list.getTasks().front();
    EXPECT_EQ(t.getName(), "Test");
    EXPECT_EQ(t.getDate(), d);
    EXPECT_FALSE(t.getImportant());
    EXPECT_FALSE(t.getCompleted());
}

TEST(ToDoListTest, CreateAndAddTaskDuplicate) {
    ToDoList list;
    Data d(10, 10, 2025);

    list.createAndAddTask("Test", "desc", d);  // Primo inserimento: OK

    EXPECT_THROW(
        list.createAndAddTask("Test", "another desc", d),  // Secondo inserimento: BOOM! Deve lanciare
        runtime_error
    );
}

TEST(ToDoListTest, CompleteTaskByName) {
    ToDoList list;
    list.createAndAddTask("CompleteMe", "TestDesc", Data(12, 5, 2025));

    bool completed = list.completeTaskByName("CompleteMe");
    EXPECT_TRUE(completed);
    EXPECT_TRUE(list.getTasks().front().getCompleted());
    EXPECT_NE(list.getTasks().front().getCompletionDate().toString(), "00/00/0000");
}

TEST(ToDoListTest, CompleteTaskByName_Fail) {
    ToDoList list;
    bool result = list.completeTaskByName("NonExistingTask");
    EXPECT_FALSE(result);
}


TEST(ToDoListTest, RemoveTaskByName) {
    ToDoList list;
    list.createAndAddTask("DeleteMe", "TestDesc", Data(15, 5, 2025));

    bool removed = list.removeTaskByName("DeleteMe");
    EXPECT_TRUE(removed);
    EXPECT_TRUE(list.getTasks().empty());
}

TEST(ToDoListTest, RemoveTaskByName_Fail) {
    ToDoList list;
    bool result = list.removeTaskByName("NonExistingTask");
    EXPECT_FALSE(result);
}

TEST(ToDoListTest, ClearTasks) {
    ToDoList list;

    // Aggiungiamo qualche task
    list.addTask(Task("Task1"));
    list.addTask(Task("Task2"));
    list.addTask(Task("Task3"));

    // Verifichiamo che i task siano stati aggiunti
    ASSERT_EQ(list.getTasks().size(), 3);

    // Chiamiamo clearTasks
    list.clearTasks();

    // Ora la lista deve essere vuota
    EXPECT_TRUE(list.getTasks().empty());
}