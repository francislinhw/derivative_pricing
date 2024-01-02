#include <stdio.h>

// Macro for subtraction
#define MINUS(a, b) ((a) - (b))

/**
 * int minus(int a, int b) {
 *     return a - b;
 * }
*/

int main() {
    int x = 15, y = 10;
    // Using the macro with different data types
    int x_int = 15, y_int = 10;
    double x_double = 15.5, y_double = 10.5;
    float x_float = 15.5f, y_float = 10.5f;
    long x_long = 15L, y_long = 10L;

    // Results using the macro
    int result_int = MINUS(x_int, y_int);
    double result_double = MINUS(x_double, y_double);
    float result_float = MINUS(x_float, y_float);
    long result_long = MINUS(x_long, y_long);

    // Printing the results
    printf("Int difference: %d\n", result_int);
    printf("Double difference: %lf\n", result_double);
    printf("Float difference: %f\n", result_float);
    printf("Long difference: %ld\n", result_long);
    return 0;
}
