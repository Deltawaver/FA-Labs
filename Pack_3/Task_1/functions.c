#include "functions.h"

const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void convertToBase(unsigned int num, int r, char* result) {
    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';
        return;
    }
    
    char buffer[33];
    int pos = 0;
    unsigned int mask = ~(~0 << r);

    while (num != 0) {
        unsigned int digit = num & mask;  
        buffer[pos] = digits[digit];     
        pos++;
        num = num >> r;                  
    }

    int j = 0;
    for (int i = pos - 1; i >= 0; i--) {
        result[j] = buffer[i];
        j++;
    }
    result[j] = '\0';
}