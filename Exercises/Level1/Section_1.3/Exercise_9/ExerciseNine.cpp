/* Conditional expressions */
#include <stdio.h>

int main() {
    int x=1;
    int y=1;
    int z=1;
    x+=y+=x;
    // First operation: x += y += x
    // This is evaluated as x += (y += x)
    // First, y = y + x = 1 + 1 = 2
    // Then, x = x + y = 1 + 2 = 3
    printf("%d\n\n", (x<y)?y:x); // Prints 3 and change 2 lines
    // The conditional expression (x < y) ? y : x
    // Since x is 3 and y is 2, x < y is false, so x is printed
    printf("%d\n", (x<y)?x++:y++); // Prints 2
    // The conditional expression (x < y) ? x++ : y++
    // Since x is still 3 and y is 2, x < y is false, so y is incremented (post-increment)
    // The value of y before incrementing (2) is printed
    printf("%d\n", x); // Prints 3
   // Prints the current value of x, which is still 3
    printf("%d\n", y); // Prints 3
    // Prints the current value of y, which has been incremented to 3 after y++
    return 0;
    // Output:
    // 3
    // 
    // 2
    // 3
    // 3
}