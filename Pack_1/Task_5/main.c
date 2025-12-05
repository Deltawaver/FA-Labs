#include "functions.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Ошибка: недостаточно аргументов.\n");
        return 1;
    }

    char* input_filename = argv[2];

    int res_in = is_valid_filename(input_filename);
    switch(res_in) {
        case -1:
            printf("Ошибка (входной файл): NULL указатель.\n");
            break;
        case 1:
            printf("Ошибка (входной файл): нет расширения файла.\n");
            break;
        case 2:
            printf("Ошибка (входной файл): недопустимое расширение файла.\n");
            break;
    }

    char *flag = argv[1];
    char output_filename[256];

    if (flag[0] == '-' || flag[0] == '/') {
        if (flag[1] == 'n' && argc == 4) {

            strcpy(output_filename, argv[3]);
            int res_out = is_valid_filename(input_filename);
            switch(res_out) {
                case -1:
                    printf("Ошибка (выходной файл): NULL указатель.\n");
                    break;
                case 1:
                    printf("Ошибка (выходной файл): нет расширения файла.\n");
                    break;
                case 2:
                    printf("Ошибка (выходной файл): недопустимое расширение файла.\n");
                    break;
            }
        } else {
            char *last_slash = strrchr(input_filename, '/');
            if (last_slash == NULL) {
                strcpy(output_filename, "out_");
                strcat(output_filename, input_filename);
            } else {
                short int index_slash = last_slash - input_filename + 1;
                strncpy(output_filename, input_filename, index_slash);
                strcat(output_filename, "out_");
                strcat(output_filename, last_slash + 1);
            }
        }
    } else {
        printf("Ошибка: неверный формат ввода флага.\n");
        return 1;
    }

    char* input_name = strchr(input_filename, '/');
    char* output_name = strchr(output_filename, '/');

    input_name = (input_name != NULL) ? input_name + 1 : input_filename;
    output_name = (output_name != NULL) ? output_name + 1 : output_filename;

    if (flag[1] == 'n' && strcmp(input_name, output_name) == 0) {
        printf("Ошибка: входной и выходной файлы не могут быть одинаковыми.\n");
        return 1;
    }

    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Ошибка: не удалось открыть входной файл.\n");
        return 1;
    }

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Ошибка: не удалось открыть выходной файл.\n");
        fclose(input_file);
        return 1;
    }

    if (!((strlen(flag) == 3) && flag[1] == 'n' || (strlen(flag) == 2))) {
        printf("Ошибка: не верный флаг.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    char func = (flag[1] == 'n') ? flag[2] : flag[1];
    bool ok_flag = false;

    switch (func) {
        case 'd':
            switch (d_function(input_file, output_file)) {
                case -1:
                    printf("Ошибка: NULL указатель.\n");
                    break;
                case -2:
                    printf("Ошибка: ошибка записи.\n");
                    break;
            }
            ok_flag = true;
            break;

        case 'i':
            switch (i_function(input_file, output_file)) {
                case -1:
                    printf("Ошибка: NULL указатель.\n");
                    break;
                case -2:
                    printf("Ошибка: ошибка записи.\n");
                    break;
            }
            ok_flag = true;
            break;

        case 's':
            switch (s_function(input_file, output_file)) {
                case -1:
                    printf("Ошибка: NULL указатель.\n");
                    break;
                case -2:
                    printf("Ошибка: ошибка записи.\n");
                    break;
            }
            ok_flag = true; 
            break;
        case 'a':
            switch (a_function(input_file, output_file)) {
                case -1:
                    printf("Ошибка: NULL указатель.\n");
                    break;
                case -2:
                    printf("Ошибка: ошибка записи.\n");
                    break;
            }
            ok_flag = true; 
            break;
    }

    fclose(input_file);
    fclose(output_file);

    if (!ok_flag) {
        return 1;
    }

    printf("Файл был успешно записан.\n");
    return 0;
}
