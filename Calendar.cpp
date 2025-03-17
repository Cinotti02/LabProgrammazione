//
// Created by francesco on 17/03/2025.
//

#include "Calendar.h"


int daysInMonth(int month, int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2)
        return(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
    else
        return 31;
}