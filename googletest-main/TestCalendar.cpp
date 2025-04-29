//
// Created by francesco on 27/04/2025.
//
#include <gtest/gtest.h>
#include "../Calendar.h"

TEST(CalendarTest, FirstDayOfMonth) {
    int day = firstDayOfMonth(4, 2025); // 1 Aprile 2025
    EXPECT_GE(day, 0);
    EXPECT_LE(day, 6);
}

TEST(CalendarTest, PrintMonthTest) {
    EXPECT_NO_THROW(printMonth(4, 1, 2025));
}

TEST(CalendarTest, PrintDayOfWeekTest) {
    EXPECT_NO_THROW(printDayOfWeek(1, 4));
}

TEST(CalendarTest, PrintFourMonthlyTest) {
    ToDoList list;
    EXPECT_NO_THROW(printFourMonthly(1, 2025, 4, list));
}

TEST(CalendarTest, PrintDaysTest) {
    int day[4] = {31, 28, 31, 30};
    int startDay[4] = {0, 3, 6, 2};
    int prevMonthDay[4] = {31, 31, 28, 31};
    int currentDay[4] = {1, 1, 1, 1};
    std::vector<Task> tasks;
    tasks.emplace_back("Task1", Data(5, 1, 2025));
    EXPECT_NO_THROW(printDays(day, startDay, prevMonthDay, currentDay, 4, 1, 2025, tasks));
}