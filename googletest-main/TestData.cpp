//
// Created by francesco on 27/04/2025.
//
#include <gtest/gtest.h>
#include "../Data.h"

TEST(DataTest, ConstructorAndToString) {
    Data d(5, 4, 2025);
    EXPECT_EQ(d.toString(), "05/04/2025");
}

TEST(DataTest, ConstructorAndGetters) {
    Data d(5, 4, 2025);
    EXPECT_EQ(d.getDay(), 5);
    EXPECT_EQ(d.getMonth(), 4);
    EXPECT_EQ(d.getYear(), 2025);
}

TEST(DataTest, DaysInMonth) {
    EXPECT_EQ(Data::daysInMonth(2, 2024), 29); // Anno bisestile
    EXPECT_EQ(Data::daysInMonth(2, 2025), 28);
    EXPECT_EQ(Data::daysInMonth(4, 2025), 30);
    EXPECT_EQ(Data::daysInMonth(1, 2025), 31);
}

TEST(DataTest, IsValidDate) {
    EXPECT_NO_THROW(Data(31, 1, 2025)); // Data valida
    EXPECT_THROW(Data(31, 2, 2025), std::runtime_error); // Data non valida
}


TEST(DataTest, EqualityOperator) {
    Data d1(1, 1, 2025);
    Data d2(1, 1, 2025);
    EXPECT_TRUE(d1 == d2);
}

TEST(DataTest, FromString) {
    Data d = Data::fromString("12/05/2025");
    EXPECT_EQ(d.getDay(), 12);
    EXPECT_EQ(d.getMonth(), 5);
    EXPECT_EQ(d.getYear(), 2025);
}

TEST(DataTest, ToString) {
    Data d(9, 12, 2025);
    EXPECT_EQ(d.toString(), "09/12/2025");
}

TEST(DataTest, GetCurrentDate) {
    Data today = Data::getCurrentDate();
    EXPECT_GE(today.getYear(), 2025); // Deve essere almeno 2024 o più avanti
}

TEST(DataTest, SetCurrentDate) {
    Data d;
    d.setCurrentDate();
    EXPECT_GE(d.getYear(), 2025);
}
