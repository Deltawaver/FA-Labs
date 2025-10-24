#include "functions.h"


int main(int argc, char *argv[]){
    if (argc != 1) {
        printf("Реализация рассматривает передачу аргументов в функцию посредством их задания внутри кода\n");
        return 1;
    }

    int num_of_nums = 1;
    int base = 3;

    bool* result = (bool*)calloc(num_of_nums, sizeof(bool));
    if (result == NULL) {
        printf("Error: Не удалось выделить память\n");
        return 1;
    }

    //ErrorCode check_result = checker(num_of_nums, base, result, 0.5, 0.1, 0.3);

    ErrorCode check_result = checker(num_of_nums, base, result, 0.3);

    switch(check_result){
        case ERR_INVALID_BASE:
            printf("Error: Некорректное основание системы счисления\n");
            break;
        case ERR_INVALID_NUM_COUNT:
            printf("Error: Некорректное количество чисел\n");
            break;
        case ERR_INVALID_NUMBER:
            printf("Error: Некорректное число в диапазоне (0, 1)\n");
            break;
        case SUCCESS:
            for (int i = 0; i < num_of_nums; i++){
                printf("Число %d: %sконечная в системе счисления с основанием %d\n", i + 1, result[i] ? "" : "не ", base);
            }
            break;
    }

    free(result);

    return 0;
}