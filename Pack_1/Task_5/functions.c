#include "functions.h"


int is_valid_filename(const char* filename) {
    if (filename == NULL) {
        return -1; // Ошибка: NULL указатель
    }

    const char *fileTypes[] = {".txt", ".docx", ".doc", ".py", ".csv", ".json", ".rtf", ".html", ".css",".c", ".h", ".cpp", ".hpp", ".java", ".xml",  ".js", ".md", ".log", ".conf", ".config", NULL};
    char *dot_pos = strrchr(filename, '.');
    if (dot_pos == NULL) {
        return 1; // Ошибка: нет расширения
    }

    for (size_t i = 0; fileTypes[i] != NULL; i++) {
        if (strcmp(dot_pos, fileTypes[i]) == 0) {
            return 0; // Валидное расширение
        }
    }
    return 2;
}

int d_function(FILE* input_filename, FILE* output_filename) {
    if (input_filename == NULL || output_filename == NULL) {
        return -1; // Ошибка: NULL указатель
    }
    char ch;
    while ((ch = fgetc(input_filename)) != EOF) {
        if (!isdigit(ch)) {
            if (fputc(ch, output_filename) == EOF) {
                return -2; // Ошибка записи
            }
        }
    }
    return 0;
}

int i_function(FILE* input_filename, FILE* output_filename) {
    if (input_filename == NULL || output_filename == NULL) {
        return -1; // Ошибка: NULL указатель
    }
    int ch;
    unsigned int count = 0;
    while ((ch = fgetc(input_filename)) != EOF) {
        if (ch == '\n') {
            if (fprintf(output_filename, "%d \n", count) <= 0) {
                return -2; // Ошибка записи
            }
            count = 0;
        } else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) count++;
    }
    if (count > 0) {
        if (fprintf(output_filename, "%d \n", count) <= 0) {
            return -2; // Ошибка записи
        }
    }
    return 0;
}


int s_function(FILE* input_filename, FILE* output_filename) {
    if (input_filename == NULL || output_filename == NULL) {
        return -1; // Ошибка: NULL указатель
    }

    int ch;
    unsigned int count = 0;

    while ((ch = fgetc(input_filename)) != EOF) {
        unsigned char c = (unsigned char)ch; 
        if (c == '\n') {
            if (fprintf(output_filename, "%u\n", count) <= 0) {
                return -2; // Ошибка записи
            }
            count = 0;
        } else {
            int is_allowed = 
                (c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9') ||
                (c == ' ');

            if (!is_allowed) {
                count++;
            }
        }
    }
    if (count > 0) {
        if (fprintf(output_filename, "%u\n", count) <= 0) {
            return -2; // Ошибка записи
        }
    }
    return 0;
}

int a_function(FILE* input_filename, FILE* output_filename) {
    if (input_filename == NULL || output_filename == NULL) {
        return -1; // Ошибка: NULL указатель
    }
    int ch;
    while ((ch = fgetc(input_filename)) != EOF) {
        unsigned char c = (unsigned char)ch;

        if (isdigit(c) || c == '\n') {
            fputc(ch, output_filename);
        } else {
            int fdig = c / 16;
            int sdig = c % 16;

            char fchar = (fdig < 10) ? ('0' + fdig) : ('A' + (fdig - 10));
            char schar = (sdig < 10) ? ('0' + sdig) : ('A' + (sdig - 10));

            if (fputc(fchar, output_filename) == EOF || fputc(schar, output_filename) == EOF) {
                return -2; // Ошибка записи
            }
        }
    }
    return 0;
}
