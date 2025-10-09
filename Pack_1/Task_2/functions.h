#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <stdint.h>


bool is_valid_number(const char* str, int* out_value);
int* sieve(const int max_n);
long long limiting(const int n);


#endif