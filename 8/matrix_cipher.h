#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int get_int();
int **encode(char* string, int** cipher_matrix, int n);
int** create_custom_2D_matrix(int rows, int cols);
void fill_custom_2D_matrix(int** matrix, int rows, int cols);
void print_custom_2D_matrix(int** matrix, int rows, int cols);