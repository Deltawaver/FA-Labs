#include "functions.h"

static int increment(int x) {
    int mask = 1;
    while (x & mask) {
        x = x & ~mask;
        mask = mask << 1;
    }
    return x | mask;
}

static int decrement(int x) {
    if (x == 0) return -1;
    int minus_one = ~0;
    while (minus_one != 0) {
        int temp = x & minus_one;
        x = x ^ minus_one;
        minus_one = temp << 1;
    }
    return x;
}

const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

TypeError convertToBase(int number, int r, char* result) {
    if (r < 1 || r > 5) {
        return BASE_OUT_OF_RANGE;
    }
    if (result == NULL) {
        return NULL_OUTPUT;
    }

    if (number == 0) {
        result[0] = '0';
        result[1] = '\0';
        return SUCCESS;
    }

    int is_negative = (number & (1 << 31)) != 0;
    unsigned int num;
    if (is_negative) {
        num = (unsigned int)increment(~number);
    } else {
        num = (unsigned int)number;
    }

    char buffer[33];
    int pos = 0;

    unsigned int mask = ~(~0U << r);
    while (num != 0) {
        unsigned int digit = num & mask;
        buffer[pos] = digits[digit];
        pos = increment(pos);
        num = num >> r;
    }

    int j = 0;
    if (is_negative) {
        result[j] = '-';
        j = increment(j);
    }
    int i = decrement(pos);
    while (1) {
        result[j] = buffer[i];
        j = increment(j);
        if (i == 0) break;
        i = decrement(i);
    }
    result[j] = '\0';

    return SUCCESS;
}
