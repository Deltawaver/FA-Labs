#include "functions.h"


long long gcd(long long a, long long b){
    while (b != 0){
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool is_finit(const double num, const int base){
    long long denom = 1000000000000LL; 
    long long numer = (long long)(num * denom + 0.5);
    if (numer == 0) return true;
    long long dn_divisor = gcd(numer, denom);    
    numer /= dn_divisor;
    denom /= dn_divisor;

    long long denom_copy = denom;
    int base_copy = base;
    for (long long i = 2; i * i <= base_copy; i++){
        while (base_copy % i == 0){
            while (denom_copy % i == 0){
                denom_copy /= i;
            }
            base_copy /= i;
        }
    }
    if (base_copy > 1){
        while (denom_copy % base_copy == 0){
            denom_copy /= base_copy;
        }
    }
    return denom_copy == 1;
}


ErrorCode checker(const int num_of_nums, const int base, bool* result, ...){
    if (base < 2) return 1;
    if (num_of_nums < 1) return 2;

    va_list args;
    va_start(args, result);

    
    for (int i = 0; i < num_of_nums; i++){
        double num = va_arg(args, double);
        if (num <= 0.0 || num >= 1.0){
            va_end(args);
            return 3;
        }
        if (is_finit(num, base)) result[i] = true;
        else result[i] = false;
    }

    va_end(args);
    return 0;
}