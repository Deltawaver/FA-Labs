#include "functions.h"	


int is_valid_float(const char *str) {
    if (str == NULL || *str == '\0') {
        return 1;
    }
    
    int i = 0;
    if (str[i] == '-') {
        i++;
        if (str[i] == '\0') {
            return 1;
        }
    }
    if (str[i] == '+') {
        return 1;
    }

    int digits = 0;
    int dots = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            digits++;
        } else if (str[i] == '.') {
            dots++;
            if (dots > 1) {
                return 1; 
            }
        } else {
            return 1; 
        }
        i++;
    }
    if (digits == 0) {
        return 1;
    }

    return 0;
}

double abs_for_double(const double n){
    return (n < 0) ? -n : n;
}

bool is_equals (const double a, const double b, const double epsilon){
    return abs_for_double(a - b) <= epsilon;
}

int q_function(const double a, const double b, const double c, const double epsilon, double* x1, double* x2) {
    double d = b * b - 4 * a * c;
    if (!is_equals(d, 0.0, epsilon)) {
        *x1 = *x2 = -b / (2 * a);
        return 1;
    }
    else if (d > 0) {
        *x1 = (-b - sqrt(d)) / (2 * a);
        *x2 = (-b + sqrt(d)) / (2 * a);
        return 2;
    }
    else return 0;
}