// Macro.c
// Objective: This is the main program file that includes Defs.h and uses the defined macros.
#include "Defs.h"

int main() {
    int s = 10;
    int e = 20;

    // Use PRINT1 and PRINT2 macros
    PRINT1(s);
    PRINT2(s, e);

    return 0;
}
