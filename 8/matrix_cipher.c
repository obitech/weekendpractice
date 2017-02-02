#include "matrix_cipher.h"

// Get an integer input
int get_int() {
   int z;
   scanf("%d", &z);
   return z;
}

// Transforming all chars in a string to upper case
void str_to_upper(char *str, int len) {
   for (int i = 0; i < len; i++) {
      str[i] = toupper(str[i]);
   }
}

// Allocating & return pointer to custom sized 2D matrix
int** create_custom_2D_matrix(int n, int m) {
   int** array = malloc(n * sizeof(int*));

   for (int i = 0; i < n; i++) {
      array[i] = malloc(m * sizeof(int));
   }

   if (!array) {
      printf("Error while allocating memory. NULL pointer returned\n");
      return NULL;      
   }
   else {
      //printf("%dx%d matrix created.\n", n, m);
      return array;
   }
}

// Returning position of c in alphabet
int char_to_int(char c) {
   if (c <= 90 && c >= 65) {
      return c - 64;
   }

   else {
      return 27;
   }
}

// Printing an array
void print_array(int* array, int size) {
   printf("[");
   for (int i = 0; i < size; i++) {
      printf("%d", array[i]);

      if (i != size - 1) {
         printf(",");
      }
   }
   printf("]\n");
}

// Create an array with position of chars in alphabet
int *transformed_chars(char* str, int len) {
   int *output = malloc(len * sizeof(int));

   for (int i = 0; i < len; i++) {
      output[i] = char_to_int(str[i]);
   }

   return output;
}

// Filling a matrix with 27 (Space)
void zero_matrix(int** matrix, int cols, int rows) {
   for (int i = 0; i < cols; i++) {
      for (int j = 0; j < rows; j++) {
         matrix[i][j] = 27;
      }
   }
}

// Printing a 2D matrix
void print_custom_2D_matrix(int** matrix, int n, int m) {
   printf("\n");
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         //printf("%d/%d: %d\t", i, j, matrix[i][j]);
         printf("%d\t", matrix[i][j]);        
      }
      printf("\n");
   }  
}

// Translating an array into a matrix, returning pointer to matrix
void fill_matrix_with_array(int** matrix, int* array, int cols, int rows, int len) {
   int m = 0;
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         matrix[j][i] = array[m];
         m++;
         if (m >= len) {
            return;
         }
      }
   }

   return;
}

/**
 * Multiplies m1 and m2 and saves new values in m3
 * The reason why I don't allocate/return a new matrix in this function is because
 * we need to fill up m3 with 27's beforehand
 * */
void multiply_matrices(int** m3, int** m1, int** m2, int cols, int rows) {
   int sum = 0;
   for (int i = 0; i < cols; i++) {
      for (int j = 0; j < rows; j++) {
         for (int k = 0; k < 3; k++) {
            sum += m2[i][k] * m1[k][j];
         }
         m3[i][j] = sum;
         sum = 0;
      }
   }
}

// Fills 2D matrix with values
void fill_custom_2D_matrix(int **matrix, int cols, int rows) {
   for (int i = 0; i < cols; i++) {
      for (int j = 0; j < rows; j++) {
         printf("(%d/%d): ", i + 1, j + 1);
         matrix[i][j] = get_int();
      }
   }
}

int **encode(char *start_str, int **cipher_matrix, int n) {
   int str_len, rows;
   int *transformed_char_array, **numbers_matrix, **encoded_matrix;

   str_len = strlen(start_str);

   // Converting all chars to upper case
   str_to_upper(start_str, str_len);

   // Convert chars to numbers and fill array with them
   transformed_char_array = transformed_chars(start_str, str_len);
 
   // Number of rows in our output matrix
   rows = ceil(str_len / (double)n);

   // Allocating memory for numbers matrix, rest will be filled up with 27 (SPACE)
   numbers_matrix = create_custom_2D_matrix(n, rows);
   zero_matrix(numbers_matrix, n, rows);
   fill_matrix_with_array(numbers_matrix, transformed_char_array, n, rows, str_len);

   // Allocating memory for output matrix
   encoded_matrix = create_custom_2D_matrix(n, rows);
   zero_matrix(encoded_matrix, n, rows);

   // Multiplying numbers matrix with cipher matrix
   multiply_matrices(encoded_matrix, numbers_matrix, cipher_matrix, n, rows);

   free(numbers_matrix);
   free(transformed_char_array);

   return encoded_matrix;
}

