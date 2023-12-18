/* Assignment operators */
#include <stdio.h>
int main() {
    int x=2;
    int y; int z;
    x*=3+2;
    // First operation: x *= 3 + 2
    // This is equivalent to x = x * (3 + 2)
    // The addition is performed first due to operator precedence
    // Result: x = 2 * 5 = 10
    printf("x=%d\n", x); // This will print: x=10
    x*=y=z=4;
    // Second operation: x *= y = z = 4
    // Assignments are right-associative, so z is assigned 4, then y is assigned the value of z
    // Result: y = z = 4, then x = x * y = 10 * 4 = 40
    printf("x=%d\n", x);
    x=y==z;
    // Third operation: x = y == z
    // The equality comparison y == z is evaluated first (resulting in true, or 1 in C)
    // Result: x = 1 (since y == z is true)
    printf("x=%d\n", x); // This will print: x=1

    return 0;
}