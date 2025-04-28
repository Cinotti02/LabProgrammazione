//
// Created by francesco on 27/04/2025.
//
#include <gtest/gtest.h>
#include "../Task.h"

TEST(TaskTest, ConstructorAndGetters) {
    Task t("TaskName", "TaskDescription", true, false);
    EXPECT_EQ(t.getName(), "TaskName");
    EXPECT_EQ(t.getDate().toString(), "00/00/0000");
    EXPECT_EQ(t.getCompletionDate().toString(), "00/00/0000");
    EXPECT_TRUE(t.getImportant());
    EXPECT_FALSE(t.getCompleted());
}

TEST(TaskTest, TaskCompletedTest) {
    Task t("TaskName");
    t.taskCompleted();
    EXPECT_TRUE(t.getCompleted());
}

TEST(TaskTest, FromJsonTest) {
    json j;
    j["nome"] = "SampleTask";
    j["description"] = "SampleDesc";
    j["priority"] = true;
    Task t = Task::fromJson(j);
    EXPECT_EQ(t.getName(), "SampleTask");
    EXPECT_TRUE(t.getImportant());
}

TEST(TaskTest, ToJsonTest) {
    Task t("SampleTask", "SampleDesc", true);
    json j = t.toJson();
    EXPECT_EQ(j["nome"], "SampleTask");
    EXPECT_EQ(j["description"], "SampleDesc");
    EXPECT_TRUE(j["priority"]);
}

TEST(TaskTest, EqualityOperatorTest) {
    Task t1("TaskName", Data(1, 1, 2025), "Desc", true);
    Task t2("TaskName", Data(1, 1, 2025), "Desc", true);
    EXPECT_TRUE(t1 == t2);
}
