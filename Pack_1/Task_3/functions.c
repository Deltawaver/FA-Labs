#include "functions.h"	


bool eq_equations(const Equation* e1, const Equation* e2, double eps) {
    return is_equals(e1->A, e2->A, eps) &&
           is_equals(e1->B, e2->B, eps) &&
           is_equals(e1->C, e2->C, eps);
}

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

int is_valid_int(const char *str) {
    if (str == NULL || *str == '\0') {
        return 1;
    }

    int i = 0;
    int is_negative = 0;

    if (str[i] == '-') {
        is_negative = 1;
        i++;
        if (str[i] == '\0') {
            return 1; 
        }
    }
    if (str[i] == '+') {
        return 1;
    }
    int has_digits = 0;
    long long value = 0; 

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            has_digits = 1;
            int digit = str[i] - '0';
            if (value > (LLONG_MAX - digit) / 10) {
                return 1;
            }
            value = value * 10 + digit;
        } else {
            return 1;
        }
        i++;
    }
    if (!has_digits) {
        return 1;
    }
    if (is_negative) {
        value = -value;
    }
    if (value < INT_MIN || value > INT_MAX) {
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

int q_function(const double epsilon, const double a, const double b, const double c, double* x1, double* x2) {
    if (x1 == NULL || x2 == NULL) {
        return -1;
    }
    if (is_equals(a, 0.0, epsilon)) {
        if (is_equals(b, 0.0, epsilon)) {
            if (is_equals(c, 0.0, epsilon)) {
                return -1;
            }
            return 0;
        }
        *x1 = *x2 = -c / b;
        return 1;
    }

    double d = b * b - 4 * a * c;
    if (is_equals(d, 0.0, epsilon)) {
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

int m_function(const int a, const int b) {
    if (a % b == 0) return 1;
    else return 0;
}

int t_function(const double epsilon, const double a, const double b, const double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return -1;
    }

    if (is_equals(a * a + b * b, c * c, epsilon) || is_equals(a * a + c * c, b * b, epsilon) || is_equals(b * b + c * c, a * a, epsilon)) {
        return 1;
    }
    else return 0; 
}
