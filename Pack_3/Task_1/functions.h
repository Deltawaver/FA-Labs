#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

typedef enum {
    SUCCESS,
    BASE_OUT_OF_RANGE,
    NULL_OUTPUT,
} TypeError;

TypeError convertToBase(const int num, int r, char* result);

#endif
