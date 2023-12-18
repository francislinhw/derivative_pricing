#include <stdio.h>

int main() {
    int number, n;

    // Assigning values to 'number' and 'n'
    printf("Enter the number to multiply: ");
    scanf("%d", &number);

    printf("Enter the power of 2 (n) for multiplication: ");
    scanf("%d", &n);

    // Performing the left shift operation
    int result = number << n;

    printf("%d multiplied by 2 to the power %d is %d\n", number, n, result);

    return 0;
}
