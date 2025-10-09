#include "functions.h"

int main(){
    int t;
    if (!is_valid_number(&t)) {
        return 1;
    }

    int* query = malloc(t * sizeof(int)); 
    if (!query) {
        printf("ошибка выделения памяти\n");
        return 1;
    }

    int max_n = 0; 

    for (int i = 0; i < t; i++) {
        if (!is_valid_number(&query[i])) {
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