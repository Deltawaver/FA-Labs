#include "functions.h"


int checkResult(TypeError result) {
    switch (result) {
        case SUCCESS:
            return 0;
        case BASE_OUT_OF_RANGE:
            printf("Ошибка: основание 2^r требует r от 1 до 5.\n");
            return 1;
        case NULL_OUTPUT:
            printf("Ошибка: буфер для результата не выделен (NULL).\n");
            return 1;
        default:
            printf("Неизвестная ошибка.\n");
            return 1;
    }
}

int main() {
    char result[50];

    printf("Число 25 в разных системах:\n");
    for (int r = 1; r <= 5; r++) {
        printf("r=%d: ", r);
        if (checkResult(convertToBase(25, r, result)) == 0) {
            printf("%s\n", result);
        } else {
            return 1;
        }
    }
    
    printf("\nПроверка отрицательного числа:\n");
    if (checkResult(convertToBase(-10, 4, result)) == 0) {
        printf("r=4, -10 -> %s\n", result);
    } else {
        return 1;
    }

    printf("\nТесты обработки ошибок:\n");
    checkResult(convertToBase(10, 6, result));
    checkResult(convertToBase(10, 0, result));
    checkResult(convertToBase(10, 3, NULL));

    return 0;
}
