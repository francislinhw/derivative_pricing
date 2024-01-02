// Try to create a function Swap(). This function must exchange the value of two variables.
// For example: if i=123 and j=456, then i=456 and j=123 after the Swap() function has
// been called. The variables i and j are declared, initialised and printed in the
// function main(). This problem can be solved by using pointers as arguments for
// the Swap()function.

#include <stdio.h>

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int i = 123, j = 456;
    printf("Before swap: i = %d, j = %d\n", i, j);
    Swap(&i, &j);
    printf("After swap: i = %d, j = %d\n", i, j);
    return 0;
}
