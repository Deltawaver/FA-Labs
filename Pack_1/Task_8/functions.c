#include "functions.h"

int is_line_clear() {
    char c;
    while ((c = getchar()) != '\n' && c != '\0')
    {
        if (c != ' ') {
            return 1;
        }
    }
    return 0;
}

int convertation(char* line, const size_t base, long long* max_num) {
    if (line == NULL || max_num == NULL) {
        return -1;
    }
    long long ans = 0;
    const char* cur_char = line;

    while (*cur_char == ' ' || *cur_char == '\t') cur_char++;

    if (*cur_char == '\0' || *cur_char == '\n') {
        return 1; //Ошибка: пустая строка
    }

    bool is_negative = 0;
    if (*cur_char == '-') {
        is_negative = true;
        cur_char++;
        if (*cur_char == '\0' || *cur_char == '\n' || *cur_char == ' ' || *cur_char == '\t') {
            return 1; //Ошибка: пустая строка
        }
    }
    while (*cur_char != '\n' && *cur_char != '\0') {
        char ch = *cur_char;
        int d;
        if (isdigit(ch)) {
            d = ch - '0';
        } else if (isalpha(ch)) {
            char upper_ch = (ch >= 'a' && ch <= 'z') ? ch - 32 : ch;
            d = 10 + upper_ch - 'A';
        } else {
            return 2; //Ошибка: некорректный ввод
        }
        if (d >= base) {
            return 2; //Ошибка: некорректный ввод
        }

        if (ans > ((LLONG_MAX - d) / base)) {
            return 3; //Ошибка: переполнение
        }
        ans = ans * base + d;
        cur_char++;
    }

    ans *= (is_negative) ? -1 : 1;
    if (llabs(ans) > llabs(*max_num)) {
        *max_num = ans;
    }
    return 0;
}

int base_change(const long long num, const short int base, char* ans, const short int max_size) {
    if (ans == NULL) {
        return -1;
    }
    if (base < 0 || base > 36) {
        return 1; //Ошибка: некорректое значение системы счисления
    }

    long long abs_num = (num < 0) ? -num : num;
    size_t i = 0;

    if (abs_num == 0) {
        ans[i++] = '0';
        ans[i] = '\0';
        return 0; 
    }

    while (abs_num > 0 && i < max_size) {
        short int d = abs_num % base;
        abs_num /= base;
        ans[i++] = (d > 9) ? 'A' + d  - 10 : '0' + d;
    }

    if (abs_num > 0) return 2; //Ошибка: переполнение
    if (num < 0) ans[i++] = '-';

    for (size_t j = 0; j < i / 2; j++) {
        char c = ans[j];
        ans[j] = ans[i - j - 1];
        ans[i - j - 1] = c;
    }
    ans[i] = '\0';
    return 0;
}
