#include <stdio.h>

int main() {
    int married = 5; // Indicate 'married'
    int notMarried = 0; // Indicate 'not married'
    // Using the ?: operator to choose the string to print
    // If 'married' is non-zero (true), it prints "Married", otherwise "Not Married"
    printf("Person is %s\n", married ? "Married" : "Not Married");
    printf("Person is %s\n", notMarried ? "Married" : "Not Married");

    return 0;
}
