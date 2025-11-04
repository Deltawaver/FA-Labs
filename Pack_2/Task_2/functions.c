#include "functions.h"

#if defined(__linux__)
    static const char *const ERROR_MESSAGES[] = {
        "Success",                          // 0
        "Operation not permitted",          // 1 = EPERM
        "No such file or directory",        // 2 = ENOENT
        "No such process",                  // 3 = ESRCH  
        "Interrupted system call",          // 4 = EINTR
        "I/O error",                        // 5 = EIO
        "No such device or address",        // 6 = ENXIO
        "Argument list too long",           // 7 = E2BIG
        "Exec format error",                // 8 = ENOEXEC
        "Bad file descriptor",              // 9 = EBADF
        "No child processes",               // 10 = ECHILD
        "Resource temporarily unavailable", // 11 = EAGAIN
        "Cannot allocate memory",           // 12 = ENOMEM
        "Permission denied",                // 13 = EACCES
        "Bad address",                      // 14 = EFAULT
        "Device or resource busy"           // 15 = EBUSY
    };
    #define MAX_ERRNO 16

#elif defined(__APPLE__)
    static const char *const ERROR_MESSAGES[] = {
        "Undefined error: 0",               // 0  
        "Operation not permitted",          // 1 = EPERM
        "No such file or directory",        // 2 = ENOENT
        "No such process",                  // 3 = ESRCH
        "Interrupted system call",          // 4 = EINTR
        "Input/output error",               // 5 = EIO
        "Device not configured",            // 6 = ENXIO
        "Argument list too long",           // 7 = E2BIG
        "Exec format error",                // 8 = ENOEXEC
        "Bad file number",                  // 9 = EBADF
        "No child processes",               // 10 = ECHILD
        "Resource deadlock avoided",        // 11 = EDEADLK
        "Cannot allocate memory",           // 12 = ENOMEM
        "Permission denied",                // 13 = EACCES
        "Bad address",                      // 14 = EFAULT
        "Device / Resource busy"            // 15 = EBUSY
    };
    #define MAX_ERRNO 16
#else
    static const char *const ERROR_MESSAGES[] = {
        "Success",
        "Operation not permitted", 
        "No such file or directory",
        "No such process",
        "Interrupted system call",
        "I/O error"
    };
    #define MAX_ERRNO 6
#endif

//Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах строки, на которую указывает аргумент str.
void *memchr(const void *str, int c, size_t n){
    if (str == NULL) return NULL;

    unsigned char *ptr = (unsigned char *)str;
    unsigned char uc = (unsigned char)c;

    for (size_t i = 0; i < n; i++) {
        if (*ptr == uc) {
            return (void *)ptr;
        } else {
            ptr++;  
        } 
    }
    return NULL;    
}

// Сравнивает первые n байтов str1 и str2
// 2 - одно из слов пустое, -1 - первое меньше второго, 1 - первое больше второго, 0 - одинаковые
int memcmp(const void *str1, const void *str2, size_t n){
    if (str1 == NULL || str2 == NULL) return 2;

    unsigned char *ptr1 = (unsigned char *)str1;
    unsigned char *ptr2 = (unsigned char *)str2;

    for (size_t i = 0; i < n; i++) {
        if (*ptr1 < *ptr2) {
            return -1;
        }
        if (*ptr1 > *ptr2) {
            return 1;
        }
        ptr1++;
        ptr2++;
    }
    return 0;
}

// Копирует n символов из src в dest
void *memcpy(void *dest, const void *src, size_t n){
    if (dest == NULL || src == NULL) return NULL;

    unsigned char *ptr_d = (unsigned char *)dest;
    unsigned char *ptr_s = (unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        *ptr_d = *ptr_s;
        ptr_d++;
        ptr_s++;
    }
    return dest; 
}

//Копирует символ c (беззнаковый тип) в первые n символов строки, на которую указывает аргумент str.
void *memset(void *str, int c, size_t n){
    if (str == NULL ) return NULL;

    unsigned char *ptr = (unsigned char *)str;
    unsigned char uc = (unsigned char)c;

    for (size_t i = 0; i < n; i++) {
        *ptr = uc;
        ptr++;
    }
    return str;
}

//Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest, длиной до n символов.
char *strncat(char *dest, const char *src, size_t n){
    if (dest == NULL || src == NULL) return NULL;

    unsigned char *ptr_d = (unsigned char *)dest;
    unsigned char *ptr_s = (unsigned char *)src;

    while(*ptr_d != '\0') {
        ptr_d++;
    }
    while (n != 0 && *ptr_s != '\0') {
        *ptr_d = *ptr_s;
        ptr_d++;
        ptr_s++;
        n--;
    }
    *ptr_d = '\0';
    return dest; 
}

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.
char *strchr(const char *str, int c){
    if (str == NULL) return NULL;

    unsigned char *ptr = (unsigned char *)str;
    unsigned char uc = (unsigned char)c;

    while (*ptr != '\0') {
        if (*ptr == uc) {
            return (char *)ptr;
        } else {
            ptr++;  
        } 
    }
    if (uc == '\0') {
        return (char *)ptr;
    }
    
    return NULL;  
}


//Сравнивает не более первых n байтов str1 и str2
int strncmp(const char *str1, const char *str2, size_t n){
    if (str1 == NULL || str2 == NULL) return 2;

    unsigned char *ptr1 = (unsigned char *)str1;
    unsigned char *ptr2 = (unsigned char *)str2;

    while (*ptr1 != '\0' && *ptr2 != '\0' && n != 0) {
        if (*ptr1 < *ptr2) return -1;
        if (*ptr1 > *ptr2) return 1;
        ptr1++;
        ptr2++;
        n--;
    }

    if (n == 0) return 0;
    if (*ptr1 < *ptr2) return -1;
    if (*ptr1 > *ptr2) return 1;
    return 0;
}

//Копирует до n символов из строки, на которую указывает src, в dest.
char *strncpy(char *dest, const char *src, size_t n){
    if (dest == NULL || src == NULL) return NULL;

    unsigned char *ptr_d = (unsigned char *)dest;
    unsigned char *ptr_s = (unsigned char *)src;
    size_t copied = 0;

    while (*ptr_s != '\0' && copied < n) {
        *ptr_d = *ptr_s;
        ptr_d++;
        ptr_s++;
        copied++;
    }

    if (copied < n) {
        *ptr_d = '\0';
    }
    return dest; 
}

//Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2.
size_t strcspn(const char *str1, const char *str2){
    if (str1 == NULL || str2 == NULL) return 0;

    int chars[256] = {0};
    unsigned char *ptr1 = (unsigned char *)str1;
    unsigned char *ptr2 = (unsigned char *)str2;
    size_t count = 0;

    while (*ptr2 != '\0') {
        chars[*ptr2] = 1;
        ptr2++;
    }
    
    while (*ptr1 != '\0') {
        if (chars[*ptr1]) {
            break;  
        }
        count++;
        ptr1++;
    }
    
    return count;
}

//Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает указатель на строку с сообщением об ошибке.
char *strerror(int errnum) {
    if (errnum < 0 || errnum >= MAX_ERRNO) {
        return "Unknown error";
    }
    return ERROR_MESSAGES[errnum];
}

//Вычисляет длину строки str, не включая завершающий нулевой символ
size_t strlen(const char *str){
    unsigned char *ptr = (unsigned char *)str;
    size_t count = 0;

    while (*ptr != '\0') {
        count++;
        ptr++;
    }
    return count;
}

//Находит первый символ в строке str1, который соответствует любому символу, указанному в str2.
char *strpbrk(const char *str1, const char *str2){
    if (str1 == NULL || str2 == NULL) return 0;

    int chars[256] = {0};
    unsigned char *ptr1 = (unsigned char *)str1;
    unsigned char *ptr2 = (unsigned char *)str2;

    while (*ptr2 != '\0') {
        chars[*ptr2] = 1;
        ptr2++;
    }
    
    while (*ptr1 != '\0') {
        if (chars[*ptr1]) {
            return (char*)ptr1;
        }
        ptr1++;
    }
    
    return NULL; 
}

//Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.
char *strrchr(const char *str, int c){
    if (str == NULL) return NULL;

    unsigned char *ptr = (unsigned char *)str;
    unsigned char uc = (unsigned char)c;
    unsigned char *last_found = NULL;

    while (*ptr != '\0') {
        if (*ptr == uc) {
            last_found = (char *)ptr;
        } 
        ptr++;  
    }
    if (uc == '\0') {
        return (char *)ptr;
    }
    
    return (char *)last_found;  
}

// Префикс-функция для KMP
static void compute_lps(const char *needle, int *lps, size_t n) {
    size_t len = 0;  // длина предыдущего longest prefix suffix
    lps[0] = 0;      // lps[0] всегда 0
    
    size_t i = 1;
    while (i < n) {
        if (needle[i] == needle[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  // отступаем назад
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

//Находит первое вхождение всей строки needle (не включая завершающий нулевой символ), которая появляется в строке haystack.
char *strstr(const char *haystack, const char *needle) {
    if (needle[0] == '\0') return (char *)haystack;
    
    size_t n = strlen(needle);
    int lps[n];
    compute_lps(needle, lps, n);
    
    size_t i = 0; // индекс для haystack
    size_t j = 0; // индекс для needle
    
    while (haystack[i] != '\0') {
        if (needle[j] == haystack[i]) {
            i++;
            j++;
        }
        
        if (j == n) {
            return (char *)(haystack + i - j); // Нашли!
        } else if (haystack[i] != '\0' && needle[j] != haystack[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return NULL;
}

//Разбивает строку str на ряд токенов, разделенных delim. При str = NULL продолжаем искать в старой строке, иначе в новой
char *strtok(char *str, const char *delim){
    static char *saved_pos = NULL;
    int chars[256] = {0};

    if (str != NULL){
        saved_pos = str;
    } else if (saved_pos == NULL) {
        return NULL;
    }

    while (*delim != '\0') {
        chars[*delim] = 1;
        delim++;
    }

    while (*saved_pos != '\0'){
        if (chars[*saved_pos]) {
            saved_pos++;
        } else {
            break;
        }
    }

    if (*saved_pos == '\0') {
        saved_pos = NULL; 
        return NULL;
    }

    char *start_token = saved_pos;

    while (*saved_pos != '\0' && !chars[*saved_pos]) {
        saved_pos++;
    }

    if (*saved_pos != '\0') {
        *saved_pos = '\0';
        saved_pos++;
    } else {
        saved_pos = NULL;
    }
    return start_token;
}