#include "functions.h"	


int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Ошибка: нет аргументов\n");
		return 1;
	}
	
	int i = 1;
	while (i < argc) {

        //====================================================//
		if(strcmp(argv[i], "-q") == 0 || strcmp(argv[i], "/q") == 0) {
			if (i + 4 >= argc) {
                printf("Ошибка: для флага -q требуется 4 числа (epsilon, a, b, c)\n");
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

        Equation perms[6] = {
            {a, b, c},
            {a, c, b},
            {b, a, c},
            {b, c, a},
            {c, a, b},
            {c, b, a}
        };
                
        for (int i = 0; i < 6; i++) {
            bool is_duplicate = false;
            for (int j = 0; j < i; j++) {
                if (eq_equations(&perms[i], &perms[j], epsilon)) {
                    is_duplicate = true;
                    break;
                }
            }
            if (!is_duplicate) {
                double x1, x2;
                int res = q_function(epsilon, perms[i].A, perms[i].B, perms[i].C, &x1, &x2);
                
                printf("For equation (%g) * x^2 + (%g) * x + (%g) * 1 = 0: ", perms[i].A, perms[i].B, perms[i].C);
                switch (res) {
                    case 1:
                        printf("x = %g\n", x1);
                        break;
                    case 2:
                        printf("x1 = %g, x2 = %g\n", x1, x2);
                        break;
                    case 0:
                        printf("nothin at all\n");
                        break;
                    case -1:
                        printf("Бесконечное число решений\n");
                        break;
                }
            }
        }
		i += 5;
		continue;
        }

        //====================================================//

        else if(strcmp(argv[i], "-m") == 0 || strcmp(argv[i], "/m") == 0) {
			if (i + 2 >= argc) {
                printf("Ошибка: для флага -m требуется 2 числа (a, b)\n");
                return 1;
            }
		for (int j = 1; j <= 2; j++) {
            if (is_valid_int(argv[i + j])) {
                printf("Ошибка: '%s' не является корректным числом\n", argv[i + j]);
                return 1;
            }
		}
		
        int a = (int)strtol(argv[i + 1], NULL, 10);
        int b = (int)strtol(argv[i + 2], NULL, 10);

        if (a == 0 || b == 0) {
            printf("Ошибка: числа должны быть ненулевыми\n");
            return 1;
        }
	
		int res = m_function(a, b);
        switch (res) {
            case 1:
                printf("Число %d кратно %d\n", a, b);
                break;
            case 0:
                printf("Число %d не кратно( %d\n", a, b);
                break;
                }
		i += 3;
		continue;
        }

        // //====================================================//

        else if(strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "/t") == 0) {
			if (i + 4 >= argc) {
                printf("Ошибка: для флага -t требуется 4 числа (epsilon, a, b, c)\n");
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

        int res = t_function(epsilon, a, b, c);
        switch (res) {
            case 1:
                printf("Треугольник является прямоугольным\n");
                break;
            case 0:
                printf("Треугольник не является прямоугольным\n");
                break;
            case -1:
                printf("Треугольник с такими сторонами не существует\n");
                break;
        }

		i += 5;
		continue;
        }
        //====================================================//

        else {
            printf("Ошибка: неизвестный флаг '%s'\n", argv[i]);
            return 1;
        }
	
    }
    

	
}
