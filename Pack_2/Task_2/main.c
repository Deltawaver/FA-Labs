#include "functions.h"

int main() {
    // ---------------------- функция a -----------------------------------
    printf("----- Фукнция a -----\n");
    char str_a[] = "Hello world!";
    char *a_result = memchr(str_a, 'l', strlen(str_a));

    if (a_result != NULL) {
        // Выводим адрес, который нам вернула функция
        printf("Адрес найденного символа: %p\n", (void*)a_result);
        
        // Выводим сам символ по этому адресу, чтобы убедиться, что это 'o'
        printf("Символ по этому адресу: %c\n", *a_result);
        
        // Для наглядности выведем часть строки, начиная с найденного символа
        printf("Строка начиная с найденного символа: %s\n", a_result);
    } else {
        printf("Символ не найден.\n");
    }

    printf("\n");

    // ---------------------- функция b -----------------------------------
    printf("----- Фукнция b -----\n");
    char str_b1[] = "Hello world!";
    char str_b2[] = "Hello!";
    int n_b = 6;
    int b_result = memcmp(str_b1, str_b2, n_b);
    switch (b_result)
    {
    case 2:
        printf("Вы скормили пустую(-ые) строку(-и)\n");
        break;
    case 0:
        printf("Первые %d символов одинаковы\n", n_b);
        break;
    case -1:
        printf("Строка 1 меньше строки 2\n");
        break;
    case 1:
        printf("Строка 1 больше строки 2\n");
        break;
    }

    printf("\n");

    // ---------------------- функция c -----------------------------------
    printf("----- Функция c -----\n");

    // 1. Копирование строки
    char src_c[] = "Hello, World!";
    char dest_c[20];

    void *c_result = memcpy(dest_c, src_c, strlen(src_c) + 1); 
    if (c_result != NULL) {
        printf("Копирование успешно:\n");
        printf("Источник:      '%s'\n", src_c);
        printf("Назначение:    '%s'\n", dest_c);
        printf("Возвращённый указатель: %p\n", c_result);
    } else {
        printf("Ошибка копирования!\n");
    }

    printf("\n");

    // 2. Частичное копирование
    char dest2[20] = "xxxxxxxxxxxxxxx";
    void *c_result2 = memcpy(dest2, src_c, 5); 
    if (c_result2 != NULL) {
        printf("Частичное копирование:\n");
        printf("Результат:     '%s'\n", dest2); 
    } else {
        printf("Ошибка частичного копирования!\n");
    }

    printf("\n");

    // 3. NULL (должен вернуть NULL)
    void *c_result3 = memcpy(NULL, src_c, 5);
    if (c_result3 == NULL) {
        printf("Проверка на NULL работает: передали NULL - получили NULL\n");
    } else {
        printf("Ошибка: ожидали NULL, но получили указатель\n");
    }

    printf("\n");

    // ---------------------- функция d -----------------------------------
    printf("----- Функция d -----\n");

    char line_d[30];
    void *d_result = memset(line_d, '=', 29); 
    line_d[29] = '\0'; 

    if (d_result != NULL) {
        printf("Создана линия: %s\n", line_d);
        printf("Указатель возвращён: %p\n", d_result);
    } else {
        printf("Ошибка!\n");
    }

    printf("\n");

    // ---------------------- функция e -----------------------------------
    printf("----- Функция e -----\n");

    char dest_e[50] = "Hello";
    char src_e[] = ", World!";

    char *e_result = strncat(dest_e, src_e, 4); 
    printf("Результат: '%s'\n", dest_e);

    printf("\n");
    
    // ---------------------- функция f -----------------------------------
    printf("----- Функция f -----\n");

    char str_f[] = "Hello, World!";
    char *f_result = strchr(str_f, 'W');

    if (f_result != NULL) {
        printf("Символ 'W' найден: %s\n", f_result);  
        printf("Адрес символа: %p\n", (void*)f_result);
        printf("Сам символ: '%c'\n", *f_result);       
    } else {
        printf("Символ не найден\n");
    }

    // Поиск нулевого символа
    char *null_result = strchr(str_f, '\0');
    if (null_result != NULL) {  
        printf("Нулевой символ найден по адресу: %p\n", (void*)null_result);
    }

    printf("\n");

    // ---------------------- функция g -----------------------------------
    printf("----- Функция g -----\n");

    char str_g1[] = "Hello, World!";
    char str_g2[] = "Hello, MAI!";
    int n_g = 7;
    int g_result = strncmp(str_g1, str_g2, n_g); 

    switch (g_result) {
        case 0:
            printf("Первые %d символов идентичны\n", n_g);
            break;
        case -1:
            printf("str1 меньше str2 в первых %d символах\n", n_g);
            break;
        case 1:
            printf("str1 больше str2 в первых %d символах\n", n_g);
            break;
        case 2:
            printf("Ошибка: NULL аргумент\n");
            break;
    }

    printf("\n");

    // ---------------------- функция h -----------------------------------
    printf("----- Функция h -----\n");

    char dest_h[20] = "Hello, World!";  
    char src_h[] = "ABC";

    printf("До strncpy:   '%s'\n", dest_h);
    char *h_result = strncpy(dest_h, src_h, 2);  

    if (h_result != NULL) {
        printf("После strncpy: '%s'\n", dest_h);  
        printf("Указатель: %p\n", (void*)h_result);
    } else {
        printf("Ошибка!\n");
    }   

    printf("\n");

    // ---------------------- функция i -----------------------------------
    printf("----- Функция i -----\n");

    char str_i1[] = "Hello, World!";
    char str_i2[] = "d";  
    size_t i_result = strcspn(str_i1, str_i2);
    printf("Строка: '%s'\n", str_i1);
    printf("Разделители: '%s'\n", str_i2);
    printf("Длина начального сегмента: %zu\n", i_result);
    printf("Начальный сегмент: '%.*s'\n", (int)i_result, str_i1);

    printf("\n");

    // ---------------------- функция i -----------------------------------
    printf("----- Функция j -----\n");
    printf("Error 2: %s\n", strerror(2));    
    printf("Error 13: %s\n", strerror(13));  
    printf("Error 99: %s\n", strerror(99));  

    printf("\n");

    // ---------------------- функция k -----------------------------------
    printf("----- Функция k -----\n");

    // Дополнительные тесты:
    printf("Пустая строка: %zu\n", strlen(""));
    printf("Один символ: %zu\n", strlen("A"));
    printf("Много символов: %zu\n", strlen("Hello world!"));

    printf("\n");

    // ---------------------- функция l -----------------------------------
    printf("----- Функция l -----\n");

    char str_l1[] = "Hello, World!";
    char str_l2[] = "ro?";

    char *l_result = strpbrk(str_l1, str_l2);

    if (l_result != NULL) {
        printf("Найден символ: '%c'\n", *l_result);    
        printf("Указатель: %p\n", (void*)l_result);      
        printf("Остаток строки: '%s'\n", l_result);      
    } else {
        printf("Символы не найдены\n");
    }

    printf("\n");

    // ---------------------- функция m -----------------------------------
    printf("----- Функция m -----\n");

    char str_m[] = "Hello, World!";
    char searching = 'l';
    char *m_result = strrchr(str_m, searching);

    if (m_result != NULL) {
        printf("Последний %c найден: '%s'\n", searching, m_result);  
        printf("Символ: '%c'\n", *m_result);              
        printf("Адрес: %p\n", (void*)m_result);
    } else {
        printf("Символ не найден\n");
    }

    printf("\n");

    // ---------------------- функция n -----------------------------------
    printf("----- Функция n -----\n");

    char haystack[] = "ABABDABACDABABCABAB";
    char needle1[] = "ABABC";
    char needle2[] = "XYZ";
    char needle3[] = "";

    char *n_result1 = strstr(haystack, needle1);
    if (n_result1 != NULL) {
        printf("Найдено '%s' в '%s'\n", needle1, n_result1); 
        printf("Позиция: %zu\n", n_result1 - haystack);      
    } else {
        printf("'%s' не найдено\n", needle1);
    }

    char *n_result2 = strstr(haystack, needle2);
    if (n_result2 == NULL) {
        printf("'%s' не найдено\n", needle2);
    }

    char *n_result3 = strstr(haystack, needle3);
    if (n_result3 != NULL) {
        printf("Для пустой строки: '%s'\n", n_result3); 
    }

     printf("\n");

    // ---------------------- функция o -----------------------------------
    printf("----- Функция o -----\n");

    // Тест 1: Простое разделение
    char str1[] = "Hello,World,This,is,test";
    printf("Исходная строка: '%s'\n", str1);

    char *token = strtok(str1, ",");
    printf("Токены:\n");
    while (token != NULL) {
        printf("  '%s'\n", token);
        token = strtok(NULL, ",");
    }

    printf("\n");

    // Тест 2: Разные разделители
    char str2[] = "apple-banana;cherry|date";
    printf("Разные разделители: '%s'\n", str2);

    token = strtok(str2, "-;|");
    while (token != NULL) {
        printf("  '%s'\n", token);
        token = strtok(NULL, "-;|");
    }

    printf("\n");

    // Тест 3: Разделители в начале и конце
    char str3[] = ",,start,middle,end,,";
    printf("Разделители по краям: '%s'\n", str3);

    token = strtok(str3, ",");
    while (token != NULL) {
        printf("  '%s'\n", token);
        token = strtok(NULL, ",");
    }

    return 0;
}


