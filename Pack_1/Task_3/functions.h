#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h> 

typedef struct {
    double A, B, C;
} Equation;

int is_valid_float(const char *str);
int q_function(const double epsilon, const double a, const double b, const double c, double* x1, double* x2);
bool is_equals (const double a, const double b, const double epsilon);
double abs_for_double(const double n);
bool eq_equations(const Equation* e1, const Equation* e2, double eps);
int is_valid_int(const char *str);
int m_function(const int a, const int b);
int t_function(const double epsilon, const double a, const double b, const double c);

#endif
