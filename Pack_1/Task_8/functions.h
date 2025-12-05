#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

int is_line_clear();
int convertation(char* line, const size_t base, long long* max_num);
int base_change(const long long num, const short int base, char* ans, const short int max_size);

#endif
