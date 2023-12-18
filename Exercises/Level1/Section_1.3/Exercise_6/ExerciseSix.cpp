#include <stdio.h>

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Performing the right shift
    int shifted = num >> 2;

    // Check if the number is negative (for determining arithmetic shift)
    int isArithmetic = num < 0;

    printf("Original number: %d\n", num);
    printf("Number after shifting two places to the right: %d\n", shifted);
    printf("Shift type: %s\n", isArithmetic ? "Arithmetic Shift" : "Logical Shift");

    return 0;
}
