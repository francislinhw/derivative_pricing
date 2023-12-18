#include <stdio.h>

long factorial(int n) {
    if (n <= 1) return 1; // Base case
    return n * factorial(n - 1); // Recursive call
}

int main() {
    int number = 6;
    printf("Factorial of %d is %ld\n", number, factorial(number));
    return 0;
}
