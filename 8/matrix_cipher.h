#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct encrypted {
   int rows;
   int cols;
   int **message;
   int encoded;
} encrypted;

// Prompts an integer value from user. No error handling
int get_int();

/**
 *  Encoding plain text message with entered cipher matrix and size of cipher message
 *  &ext_rows and &ext_cols saves the size of the matrix for outside use
 */
encrypted encode(char* string, int** cipher_matrix, int n);

// Allocates memory for custom sized matrix & returns pointer to start
int** create_custom_2D_matrix(int rows, int cols);

// Fills previously allocated matrix with values (uses get_int())
void fill_custom_2D_matrix(int** matrix, int rows, int cols);

// Prints a custom sized matrix
void print_custom_2D_matrix(int** matrix, int rows, int cols);

// Fills a matrix with 27 (standard encoding for space)
void zero_matrix(int** matrix, int rows, int cols);

// Overwrites and frees a 100 char string
void overwrite_string(char* string);

// Overwrites a matrix with 27 and frees the pointer afterwards
void overwrite_matrix(int** matrix, int cols, int rows);

// Return determinant of n by n matrix
int determinant(int **matrix, int n);