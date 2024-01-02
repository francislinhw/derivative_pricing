#include <stdio.h>

long long factorial(unsigned int n) {
    if (n <= 1) return 1; // Base case
    return (long long)n * factorial(n - 1); // Recursive call
}

int main() {
    unsigned int number = 6;
    printf("Factorial of %u is %lld\n", number, factorial(number));
    return 0;
}
