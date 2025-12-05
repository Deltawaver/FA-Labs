#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int is_valid_filename(const char* filename);
int d_function(FILE* input_filename, FILE* output_filename);
int i_functin(FILE* input_filename, FILE* output_filename);
int s_function(FILE* input_filename, FILE* output_filename);
int a_function(FILE* input_filename, FILE* output_filename);

#endif
