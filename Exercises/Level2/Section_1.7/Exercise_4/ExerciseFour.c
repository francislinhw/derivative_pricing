// Create a C-program that has a function DayName()which can print the day of a given
// day-number. For example:
// 7 gives: Day 7 is a Saturday.
// The day-name (1-7) should be written "hard-coded” into the program using an array of
// strings.

#include <stdio.h>

const char* DayName(int dayNum) {
    // The use of char* for arrays in C is specific to points to the first character of each string literal. 
    const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    if (dayNum < 1 || dayNum > 7) {
        return "Invalid day number";
    }
    return days[dayNum - 1];
}

int main() {
    for (int dayNum = 1; dayNum <= 8; dayNum++) {
        printf("Day %d is a %s.\n", dayNum, DayName(dayNum));
    }
    return 0;
}
