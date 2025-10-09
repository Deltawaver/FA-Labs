#include "functions.h"



bool is_valid_number(int *t) {
    char buffer[100];

    if (!fgets(buffer, sizeof(buffer), stdin)) {
        printf("Ошибка: не удалось прочитать ввод.\n");
        return false;
    }

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        len--;
    }

    if (len == 0) {
        printf("Ошибка: пустой ввод.\n");
        return false;
    }

    for (size_t i = 0; i < len; i++) {
        if (!isdigit((unsigned char)buffer[i])) {
            printf("Ошибка: ввод содержит недопустимые символы.\n");
            return false;
        }
    }

    if (buffer[0] == '0' && len == 1) {
        printf("Ошибка: число должно быть положительным.\n");
        return false;
    }

    if (len > 10) {
        printf("Ошибка: число слишком большое.\n");
        return false;
    }

    if (len == 10 && strcmp(buffer, "2147483647") > 0) {
        printf("Ошибка: число превышает допустимый максимум (%d).\n", INT_MAX);
        return false;
    }

    int t_local = atoi(buffer);

    if (t_local <= 0) {
        printf("Ошибка: число должно быть положительным.\n");
        return false;
    }

    *t = t_local;
    return true;
}

long long limiting(const int n){
    if (n <= 6) return 12;
    double ln_n = log(n);
    double ln_ln_n = log(ln_n);
    long long limit = (long long)(n * (ln_n + ln_ln_n)) + 10; //формула розенберга
    return limit;
}

int* sieve(const int max_n){
    if (max_n > 1000000) return NULL; // настоящий лимит примерно n_max = 100 600 000, но тогда программа будет выполняться долго и займет 2+ гб
    long long limit = limiting(max_n);

    int* primes = malloc(max_n * sizeof(int));
    if (!primes) return NULL;

    if (limit > SIZE_MAX) {
        return NULL;
    }
    bool* flag_numbers = calloc(limit, sizeof(bool));
    if (!flag_numbers) {
        free(primes);
        return NULL;
    }

    int count = 0;
    for (int number = 2; number < limit && count < max_n; number++){
        if (!flag_numbers[number]) {
            primes[count] = number;
            count += 1;
            flag_numbers[number] = 1;
            for (long long l = (long long)number * number; l < limit; l += number) flag_numbers[l] = 1;
        }
    }
    free(flag_numbers);
    return primes;
}
