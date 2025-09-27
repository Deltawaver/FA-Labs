#include "functions.h"

bool is_valid_number(const char *str) {
    if (str == NULL || *str == '\0') return false;

    int i = 0;
    if (str[i] == '+' || str[i] == '-') {
        i++;
        if (str[i] == '\0') return false; 
    }

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
        i++;
    }
    return true;
}

void h_function(const int x){
	if (x == 0) {
		printf("Кратные нулю, серъезно?\n");
        return;
	}
	bool flag = 0;
	for (int i = 1; i <= 100; i++) {
		if (i % x == 0 && i != x){
			flag = 1;
			printf("%d\n", i);
		}
	}
	if (!flag){
		printf("Кратных нет\n");
	}
	return;
}

void p_function(const int x){
	if (x <= 0) {
		printf("Простое/составное число - это натуральное число. Значения 0 и меньше не подходят под определение 'натуральное число'\n");
        return;
	}
    if (x == 1) {
        printf("1 не простое и не составное\n");
        return;
    }
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0){
			printf("Число составное\n");
            return;
		}
	}
	printf("Число простое\n");
    return;
}

void s_function(const int x){
	if (x == 0) {
		printf("0\n");
		return;
	}
    unsigned int n = (unsigned int)x;
	char *stack = malloc(4 * sizeof(char));
	if (stack == NULL) return;

	int capacity = 4;
	int count = 0;

	while (n != 0) {

		if (count == capacity) {
			capacity *= 2;
			char *tmp = realloc(stack, capacity * sizeof(char));
			if (tmp == NULL) {
				free(stack);
				return;
			}
			stack = tmp;
		}

		int ch = n % 16;
		if (ch < 10){
			stack[count] = '0' + ch; 
		} else {
			stack[count] = 'a' + (ch - 10);
		}
		count++;
		n /= 16;
	}

	for (int i = count - 1; i >= 0; i--) {
		printf("%c ", stack[i]);
	}
	printf("\n");

	free(stack);
	return;
}

long long ipow(const int base, const int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

void e_function(const int x){
	if (x > 10 || x < 1) {
        printf("Функция принимает только натуральные значения от 1 до 10\n");
        return;
    }
	for (int i = 1; i <= x; i++){
		printf("%12d", i);
	}
	printf("\n");
	for (int i = 1; i <= 10; i++){
		for (int j = 1; j <= x; j++){
			printf("%12lld", ipow(i, j));
		}
		printf("\n");
	}
	return;
}

void a_function(const int x){
    if (x < 1) {
        printf("Функция принимает только натуральные значения\n");
        return;
    }
	int summ = 0;
	for (int i = 1; i <= x; i++) summ += i;
	printf("%d\n", summ);
	return;
}


void f_function(const int x){
	if (x < 0) {
		printf("Для отрицательных чисел факториал неопределен\n");
		return;
	}
	long long p = 1;
	for (int i = x; i > 0; i--) {
		if (p * i > LLONG_MAX) {
			printf("Произошло переполнение\n");
			return;
		}
		p *= i;
	}
	printf("%lld\n", p);
	return;
}
