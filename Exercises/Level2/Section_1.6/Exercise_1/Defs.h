#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>

// Macro for printing one variable
#define PRINT1(a) printf(#a " = %d\n", a)

// Macro for printing two variables
#define PRINT2(a, b) printf(#a " = %d, " #b " = %d\n", a, b)

#endif // DEFS_H
