#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int is_valid_float(const char *str);
int q_function(const double a, const double b, const double c, const double epsilon, double* x1, double* x2);
bool is_equals (const double a, const double b, const double epsilon);
double abs_for_double(const double n);


#endif