//
// Created by francesco on 27/04/2025.
//
#include <gtest/gtest.h>
#include "../Interface.h"
class InterfaceTest : public ::testing::Test {
protected:
    std::streambuf*origCin = nullptr;
    std::streambuf*origCout = nullptr;
    std::ostringstream output;

    void SetUp() override {
        origCin = std::cin.rdbuf();
        origCout = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());
    }

    void TearDown() override {
        std::cin.rdbuf(origCin);
        std::cout.rdbuf(origCout);
    }
};

TEST_F(InterfaceTest, MenuTest) {
    std::istringstream fakeInput("2\n");
    std::cin.rdbuf(fakeInput.rdbuf());
    int choiceValue = menu();
    EXPECT_EQ(choiceValue, 2);
}

TEST_F(InterfaceTest, PrintCalendarTest) {
    ToDoList list;
    EXPECT_NO_THROW(printCalendar(2025, list));
}

TEST_F(InterfaceTest, TodayTasksTest) {
    ToDoList list;
    EXPECT_NO_THROW(todayTasks(list));
    std::string result = output.str();
    EXPECT_NE(result.find("Today is"), std::string::npos);
}

TEST_F(InterfaceTest, ShowUncompletedTaskTest) {
    ToDoList list;
    EXPECT_NO_THROW(showUncompletedTask(list));
    std::string result = output.str();
    EXPECT_NE(result.find("activities to do"), std::string::npos);
}

TEST_F(InterfaceTest, SearchByDateTest) {
    ToDoList list;
    std::istringstream fakeInput("01\n01\n2025\n");
    std::cin.rdbuf(fakeInput.rdbuf());
    EXPECT_NO_THROW(searchByDate(list));
    std::string result = output.str();
    EXPECT_TRUE(result.find("Activities present on:") != std::string::npos || result.find("There are no activities on this date.") != std::string::npos || result.find("you have no activities to do on this date") != std::string::npos);
}

TEST_F(InterfaceTest, SetTaskCompletedTest) {
    ToDoList list;
    Task task("Task1", Data(1,1,2025));
    list.addTask(task);
    std::istringstream fakeInput("Task1\n");
    std::cin.rdbuf(fakeInput.rdbuf());
    EXPECT_NO_THROW(setTaskCompleted(list));
}

TEST_F(InterfaceTest, ShowCompletedTasksTest) {
    ToDoList list;
    EXPECT_NO_THROW(showCompletedTasks(list));
    std::string result = output.str();
    EXPECT_NE(result.find("completed activities"), std::string::npos);
}

TEST_F(InterfaceTest, RemoveTaskTest) {
    ToDoList list;
    Task task("TaskToRemove", Data(1,1,2025));
    list.addTask(task);
    std::istringstream fakeInput("TaskToRemove\n");
    std::cin.rdbuf(fakeInput.rdbuf());
    EXPECT_NO_THROW(removeTask(list));
    std::string result = output.str();
    EXPECT_NE(result.find("Activity removed successfully"), std::string::npos);
}

TEST_F(InterfaceTest, CreateTasksTest) {
    ToDoList list;
    std::istringstream fakeInput("TaskName\nY\nDescription\nY\nY\n1\n1\n2025\n");
    std::cin.rdbuf(fakeInput.rdbuf());
    EXPECT_NO_THROW(createTasks(list));
    std::string result = output.str();
    EXPECT_NE(result.find("added successfully"), std::string::npos);
}

TEST_F(InterfaceTest, ChoiceBTest) {
    std::istringstream fakeInputYes("y\n");
    std::cin.rdbuf(fakeInputYes.rdbuf());
    EXPECT_TRUE(choiceB());

    std::istringstream fakeInputNo("n\n");
    std::cin.rdbuf(fakeInputNo.rdbuf());
    EXPECT_FALSE(choiceB());
}
