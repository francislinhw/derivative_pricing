// This is the main program file that includes Defs.h and uses the defined macros.
#include "Defs.h"

int main() {
    int s = 10;
    int e = 20;

    // Use PRINT1 and PRINT2 macros
    PRINT1(s);
    PRINT2(s, e);

    // Use MAX2 and MAX3 macros
    printf("Max of %d and %d is %d\n", s, e, MAX2(s, e));
    int sum = 30;
    printf("Max of %d, %d, and %d is %d\n", s, e, sum, MAX3(s, e, sum));

    return 0;
}
