#include "functions.h"	


int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Ошибка: нет аргументов\n");
		return 1;
	}
	
	int i = 1;
	while (i < argc) {

        //====================================================//
		if(strcmp(argv[i], "-q") == 0) {
			if (i + 4 >= argc) {
                printf("Ошибка: для флага -q требуется 4 числа (эпсилон + a, b, c)\n");
                return 1;
            }
		for (int j = 1; j <= 4; j++) {
            if (is_valid_float(argv[i + j])) {
                printf("Ошибка: '%s' не является корректным числом\n", argv[i + j]);
                return 1;
            }
		}
		
		double epsilon = strtod(argv[i + 1], NULL);
        if (epsilon < 0) {
            printf("Ошибка: епсилон не может быть отрицательным\n");
            return 1;
        }

        double a = strtod(argv[i + 2], NULL);
        double b = strtod(argv[i + 3], NULL);
        double c = strtod(argv[i + 4], NULL);
        double x1, x2;
        
		int res = q_function(epsilon, a, b, c, &x1, &x2);
        switch (res) {
            case 1:
                printf("x = %f\n", x1);
            case 2:
                printf("x1 = %f, x2 = %f\n", x1, x2);
            case 0:
                printf("nothin at all\n");
        }
        
		i += 5;
		continue;
        }

        //====================================================//

        // else if(strcmp(argv[i], "-m") == 0) {
		// 	if (i + 3 >= argc) {
        //         printf("Ошибка: для флага -m требуется 4 числа (эпсилон + a, b)\n");
        //         return 1;
        //     }
		// for (int j = 1; j <= 3; j++) {
        //     if (!is_valid_float(argv[i + j])) {
        //         printf("Ошибка: '%s' не является корректным числом\n", argv[i + j]);
        //         return 1;
        //     }
		// }
		
		// double epsilon = strtod(argv[i + 1], NULL);
        // double a = strtod(argv[i + 2], NULL);
        // double b = strtod(argv[i + 3], NULL);
	
		// m_function(epsilon, a, b);
		// i += 4;
		// continue;
        // }

        // //====================================================//

        // else if(strcmp(argv[i], "-t") == 0) {
		// 	if (i + 4 >= argc) {
        //         printf("Ошибка: для флага -t требуется 4 числа (эпсилон + a, b, c)\n");
        //         return 1;
        //     }
		// for (int j = 1; j <= 4; j++) {
        //     if (!is_valid_float(argv[i + j])) {
        //         printf("Ошибка: '%s' не является корректным числом\n", argv[i + j]);
        //         return 1;
        //     }
		// }
		
		// double epsilon = strtod(argv[i + 1], NULL);
        // double a = strtod(argv[i + 2], NULL);
        // double b = strtod(argv[i + 3], NULL);
        // double c = strtod(argv[i + 4], NULL);
	
		// q_function(epsilon, a, b, c);
		// i += 5;
		// continue;
        // }

        //====================================================//

        else {
            printf("Ошибка: неизвестный флаг '%s'\n", argv[i]);
            return 1;
        }
	
    }
    

	
}