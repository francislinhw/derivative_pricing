// Defs.h
// Objective: Write a C-program that contains two print macro calls. The first prints the variable a, the
// second prints the variables a and b. Printing happens by the use of the PRINT1 and
// PRINT2 macros that accept arguments. These macros must be defined in an include-file.
// The variables a and b gets their value in the function main().
// Name the program “Macro.c” and the include-file “Defs.h”. Don’t forget to implement
// the mechanism to avoid multiple inclusion of the header file.

#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>

// Macro for printing one variable
#define PRINT1(a) printf(#a " = %d\n", a)

// Macro for printing two variables
#define PRINT2(a, b) printf(#a " = %d, " #b " = %d\n", a, b)

#endif // DEFS_H
