#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>

// Macro for printing one variable
#define PRINT1(a) printf(#a " = %d\n", a)

// Macro for printing two variables
#define PRINT2(a, b) printf(#a " = %d, " #b " = %d\n", a, b)

// Macro to find the maximum of two values
#define MAX2(x, y) ((x) > (y) ? (x) : (y))

// Macro to find the maximum of three values using MAX2
#define MAX3(x, y, z) MAX2(MAX2(x, y), z)

#endif // DEFS_H
