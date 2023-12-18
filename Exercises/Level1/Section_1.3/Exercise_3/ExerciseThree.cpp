/* Operators */
#include <stdio.h>

int main() {
    int x;
    x=-3+4*5-6;
    // First operation: -3 + 4 * 5 - 6
    // The multiplication is performed first (4 * 5 = 20), then addition and subtraction in order.
    // Result: -3 + 20 - 6 = 17 - 6 = 11
    printf("x=%d\n", x); // This will print: x=11
    x=3+4%5-6;
    // Second operation: 3 + 4 % 5 - 6
    // The modulo is performed first (4 % 5 = 4, since 4 divided by 5 leaves a remainder of 4),
    // then addition and subtraction.
    // Result: 3 + 4 - 6 = 7 - 6 = 1
    printf("x=%d\n", x); // This will print: x=1
    x=-3*4%-6/5;
    // Third operation: -3 * 4 % -6 / 5
    // The multiplication is performed first (-3 * 4 = -12),
    // then modulo (-12 % -6 = 0, as -12 is exactly divisible by -6),
    // and finally division (0 / 5 = 0).
    // Result: 0
    printf("x=%d\n", x); // This will print: x=0
    x=(7+6)%5/2;
    // Fourth operation: (7 + 6) % 5 / 2
    // The parentheses force the addition to be performed first (7 + 6 = 13),
    // then modulo (13 % 5 = 3, since 13 divided by 5 leaves a remainder of 3),
    // and finally division (3 / 2 = 1, because in integer division 3 divided by 2 is 1).
    // Result: 1
    printf("x=%d\n", x); // This will print: x=1
    return 0;
}