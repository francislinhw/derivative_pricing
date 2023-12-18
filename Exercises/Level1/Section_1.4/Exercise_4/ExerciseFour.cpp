#include <stdio.h>

#define START_FAHRENHEIT 0   // Start temperature in Fahrenheit
#define END_FAHRENHEIT 300   // End temperature in Fahrenheit
#define STEP_SIZE 20         // Step size

int main() {
    float fahrenheit, celsius;

    printf("Fahrenheit  Celsius\n");
    fahrenheit = START_FAHRENHEIT;
    while (fahrenheit <= END_FAHRENHEIT) {
        celsius = (5.0/9.0) * (fahrenheit - 32);
        printf("%10.0f  %10.1f\n", fahrenheit, celsius);
        fahrenheit += STEP_SIZE;
    }

    return 0;
}
