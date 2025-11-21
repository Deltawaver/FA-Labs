#include "functions.h"

// определитель флага
FlagType what_flagtype(const char* str) {
    if (str[0] == 'R' && str[1] == 'o') return FLAG_ROMAN;
    if (str[0] == 'Z' && str[1] == 'r') return FLAG_ZECKENDORF;
    if (str[0] == 't' && str[1] == 'o') return FLAG_TO_LOWER;
    if (str[0] == 'T' && str[1] == 'O') return FLAG_TO_UPPER;
    if (str[0] == 'm' && str[1] == 'i') return FLAG_MEM_INT;
    if (str[0] == 'm' && str[1] == 'u') return FLAG_MEM_UINT;
    if (str[0] == 'm' && str[1] == 'd') return FLAG_MEM_DOUBLE;
    if (str[0] == 'm' && str[1] == 'f') return FLAG_MEM_FLOAT;
    if (str[0] == 'C') {
        if (str[1] == 'v') return FLAG_CV_LOWER;
        if (str[1] == 'V') return FLAG_CV_UPPER;
    }
    return FLAG_STANDARD;
}

//печать в поток вывода целого числа типа int, записанного римскими цифрами
int flag_Ro(const char** format, va_list args, char* output) {
    *format += 2;
    int n = va_arg(args, int);


    return vsnprintf(output, 256, flag_buff, args);
}

// стандартные флаги
int based_flag(const char** format, va_list args, char* output) {
    char flag_buff[32];
    const char* curr_cp = *format;
    char* flag_str = flag_buff;
    *flag_str++ = '%';
    
    while (*curr_cp && strchr("diuoxXfFeEgGaAcspn", *curr_cp) == NULL) {
        *flag_str++ = *curr_cp++;
    }
    
    if (*curr_cp) {
        *flag_str++ = *curr_cp++;
    }
    
    *flag_str = '\0'; 
    *format = curr_cp;
    return vsnprintf(output, 256, flag_buff, args);
}

// кастомные флаги (пока заглушка)
int special_flags(FlagType flag_type, const char** format, va_list args, char* output) {
    strcpy(output, "[CUSTOM]");
    *format += 2;  // Пропускаем два символа кастомного флага
    return strlen(output);
}

int oversprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    char* start = str;
    const char* curr = format;
    
    while (*curr) {
        if (*curr == '%') {
            curr++; 
            if (*curr == '%') {
                *str++ = '%';
                curr++;
            } else {
                FlagType flag_type = what_flagtype(curr);

                if (flag_type == FLAG_STANDARD) {
                    char buffer[256];
                    int written = based_flag(&curr, args, buffer);
                    
                    if (written > 0) {
                        strcpy(str, buffer);
                        str += written;
                    }
                } else {
                    char buffer[256];
                    // ПЕРЕДАЁМ flag_type и &curr
                    int written = special_flags(flag_type, &curr, args, buffer);
                    
                    if (written > 0) {
                        strcpy(str, buffer);
                        str += written;
                    }
                }
            }
        } else {
            *str++ = *curr++;
        }
    }
    
    *str = '\0';
    va_end(args);
    return str - start;
}