#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

typedef enum {
    SUCCESS = 0,
    ERR_INVALID_BASE = 1,
    ERR_INVALID_NUM_COUNT = 2,
    ERR_INVALID_NUMBER = 3
} ErrorCode;

ErrorCode checker(const int num_of_nums, const int base, bool* result, ...);

#endif




