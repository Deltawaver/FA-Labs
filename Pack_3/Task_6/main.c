#include "functions.h"

int main() {
    char input[1000];
    
    printf("Введите строку для проверки скобок: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Удаляем символ новой строки, если он есть
        size_t len = strlen(input);
        if (len > 0 && input[len-1] == '\n') {
            input[len-1] = '\0';
        }
        
        int result = check_brackets(input);
        
        if (result == 2) {
            printf("Ошибка: NULL строка или ошибка выделения памяти\n");
        } else if (result == 1) {
            printf("Скобки расставлены корректно\n");
        } else {
            printf("Скобки расставлены некорректно\n");
        }
    }
    
    return 0;
}