#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdarg.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int overfprintf(FILE *stream, const char *format, ...);
int oversprintf(char *buffer, const char *format, ...);

typedef enum {
    FLAG_STANDARD,  // обычные %d, %s и т.д.
    FLAG_ROMAN,     // %Ro
    FLAG_ZECKENDORF,// %Zr 
    FLAG_CV_LOWER,  // %Cv
    FLAG_CV_UPPER,  // %CV
    FLAG_TO_LOWER,  // %to
    FLAG_TO_UPPER,  // %TO
    FLAG_MEM_INT,   // %mi
    FLAG_MEM_UINT,  // %mu
    FLAG_MEM_DOUBLE,// %md
    FLAG_MEM_FLOAT  // %mf
} FlagType;

#endif