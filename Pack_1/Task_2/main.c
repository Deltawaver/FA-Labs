#include "functions.h"

int main(){
    char buffer[100];
    int t;

    printf("Введите кол-во запросов: ");
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        printf("Ошибка: не удалось прочитать ввод.\n");
        return 1;
    }

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    if (!is_valid_number(buffer, &t)) {
        printf("Ошибка: неверно задано число запросов.\n");
        return 1;
    }

    int* query = malloc(t * sizeof(int));
    if (!query) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    int max_n = 0;
    for (int i = 0; i < t; i++) {
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Ошибка ввода.\n");
            free(query);
            return 1;
        }

        len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        if (!is_valid_number(buffer, &query[i])) {
            printf("Ошибка: запрос должен быть положительным целым числом.\n");
            free(query);
            return 1;
        }

        if (query[i] > max_n) max_n = query[i];
    }

    int* primes = sieve(max_n);
    if (!primes) {
        printf("Ошибка: не удалось сгенерировать простые числа.\n");
        free(query);
        return 1;
    }

    for (int i = 0; i < t; i++) {
        printf("%d\n", primes[query[i] - 1]);  
    }

    free(primes);
    free(query);

    return 0;
}