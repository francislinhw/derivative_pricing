#include <stdio.h>

const char* DayName(int dayNum) {
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
