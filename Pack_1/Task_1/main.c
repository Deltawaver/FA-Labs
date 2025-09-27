#include "functions.h"	


int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("Error\n");
		return 0;
	}
	
	if (!is_valid_number(argv[1])) {
    	printf("Error\n");
    	return 1;
	}
	long x_long = strtol(argv[1], NULL, 10);
	if (x_long > INT_MAX || x_long < INT_MIN) {
		printf("Переполнение\n");
		return 1;
	}
	int x = (int)x_long;

	for (int i = 2; i < argc; i++) {
		if ((argv[i][0] == '-' || argv[i][0] == '/') && argv[i][1] != '\0' && argv[i][2] == '\0') { 
			switch (argv[i][1]) {
				case 'h':
					h_function(x);
					break;
				case 'p':
					p_function(x);
					break;
				case 's':
					s_function(x);
					break;
				case 'e':
					e_function(x);
					break;
				case 'a':
					a_function(x);
					break;
				case 'f':
					f_function(x);
					break;
				default:
					printf("Error: неизвестный флаг '%c'\n", argv[i][1]);
			}
		} else {
			printf("Error: некорректный флаг '%s'\n", argv[i]);
		}
	}
	return 0;
}