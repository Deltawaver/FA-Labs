#include "functions.h"

int main(int argc, char* argv[]) {
    short int base;

    printf("Введите основание счисления (2-36):\n");
    if (scanf("%hd", &base) != 1 || base < 2 || base > 36) {
        printf("Ошибка: неверное основание счисления.\n");
        return 1;
    }
    if (is_line_clear()) {
        printf("Ошибка: неверный ввод. \n");
        return 1;
    }
    printf("Ввод чисел:\n");

    const size_t BUFFER = 8096;
    char buff[BUFFER];
    bool any_nums = false;
    long long max_num = 0;
    
    while(1) {
        if (fgets(buff, BUFFER - 1, stdin) == NULL) {
            printf("Ошибка при чтении строки.\n");
            return 1;
        }
        if (!strcmp(buff, "Stop\n") || !strcmp(buff, "Stop")) {
            if (!any_nums) {
                printf("На момент завершения программы ни одно число не было введено.\n");
                return 1;
            }
            break;
        }
        any_nums = true;

        switch(convertation(buff, base, &max_num)) {
            case -1:
                printf("Ошибка: NULL указатель.\n");
                break;
            case 1:
                printf("Ошибка: пустая строка.\n");
                break;
            case 2:
                printf("Ошибка: некорректный ввод\n");
                break;
            case 3:
                printf("Ошибка: переполнение\n");
                break;
            case 0:
                break;
        }
    }
    int bases[] = {base, 9, 18, 27, 36, 0};
    char num[BUFFER];

    for (size_t i = 0; bases[i] != 0; i++) {
        switch (base_change(max_num, bases[i], num, BUFFER)) {
        case -1:
            printf("Ошибка: NULL указатель.\n");
            break;
        case 1:
            printf("Ошибка: некорректое значение системы счисления\n");
            break;
        case 0:
            break;
        }
        printf("Максимальное по модулю число в осовании %d: %s\n", bases[i], num);
    }
    return 0;
}   
