#include <stdio.h>

#define START_CELSIUS 0   // Start temperature in Celsius
#define END_CELSIUS 19    // End temperature in Celsius

int main() {
    printf("Celsius  Fahrenheit\n");
    for (int celsius = START_CELSIUS; celsius <= END_CELSIUS; celsius++) {
        float fahrenheit = (celsius * 9.0/5.0) + 32;
        printf("%10d  %10.1f\n", celsius, fahrenheit);
    }

    return 0;
}
