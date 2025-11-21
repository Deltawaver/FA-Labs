#include "functions.h"

int main() {
    char result[33];

    printf("Число 25 в разных системах:\n");
    
    convertToBase(10, 1, result);
    printf("r=1 (двоичная): %s\n", result);
    
    convertToBase(10, 2, result);
    printf("r=2 (четверичная): %s\n", result);
    
    convertToBase(10, 3, result);
    printf("r=3 (восьмеричная): %s\n", result);
    
    convertToBase(10, 4, result);
    printf("r=4 (шестнадцатеричная): %s\n", result);
    
    convertToBase(10, 5, result);
    printf("r=5 (32-ричная): %s\n", result);
    
    return 0;
}