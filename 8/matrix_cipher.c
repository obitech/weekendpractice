#include "matrix_cipher.h"

// Input integer
int get_int() {
   int z;
   scanf("%d", &z);
   return z;
}

int get_string(char *s, int maxlen) {
   int len;

   s = fgets(s, maxlen , stdin); 
      if(s == NULL)
         return 0;
   len = strlen(s);
   if (s[len - 1] == '\n')
      s[--len] = '\0'; // remove line break

   return len; 
} 

void str_to_upper(char *str, int len) {
   for (int i = 0; i < len; i++) {
      str[i] = toupper(str[i]);
   }
}

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

int char_to_int(char c) {
   if (c <= 90 && c >= 65) {
      return c - 64;
   }

   else {
      return 27;
   }
}

// Print array
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

int *transformed_chars(char* str, int len) {
   int *output = malloc(len * sizeof(int));

   for (int i = 0; i < len; i++) {
      output[i] = char_to_int(str[i]);
   }

   return output;
}

void zero_matrix(int** matrix, int m, int n) {
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
         matrix[i][j] = 27;
      }
   }
}

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

void fill_matrix_with_array(int** matrix, int* array, int rows, int cols, int len) {
   int m = 0;
   for (int i = 0; i < cols; i++) {
      for (int j = 0; j < rows; j++) {
         matrix[j][i] = array[m];
         m++;
         if (m >= len) {
            return;
         }
      }
   }
}

int sum_of_values_matrices(int **m1, int **m2, int row, int col, int n) {
   int sum = 0;

   for (int i = 0; i < n; i++) {
      sum += m1[row][i] * m2[i][col];
   }

   return sum;
}

void multiply_matrices(int** m3, int** m1, int** m2, int cols, int rows) {
   int sum = 0;
   for (int i = 0; i < cols; i++) {
      for (int j = 0; j < rows; j++) {
         for (int k = 0; k < 3; k++) {
            printf("%d * %d = %d\n",m2[i][k], m1[k][j], m2[i][k] * m1[k][j]);
            sum += m2[i][k] * m1[k][j];
         }
         printf("sum = %d\n", sum);
         m3[i][j] = sum;
         sum = 0;
      }
   }
}

void fill_custom_2d_matrix(int **matrix, int cols, int rows) {
   for (int i = 0; i < cols; i++) {
      for (int j = 0; j < rows; j++) {
         printf("(%d/%d): ", i, j);
         matrix[i][j] = get_int();
      }
   }
}

char *encode() {
   int max_len, str_len, rows;
   int *transformed_char_array, **encoded_matrix, **cipher_matrix, **encoded_matrix_final;
   char *start_str;

   printf("String:\n");
   max_len = 100;
   start_str = malloc(max_len * sizeof(char));
   scanf("%[^\n]%*c", start_str);
   str_len = strlen(start_str);
   str_to_upper(start_str, str_len);

   printf("Enter cipher matrix:\n");
   cipher_matrix = create_custom_2D_matrix(3, 3);
   fill_custom_2d_matrix(cipher_matrix, 3, 3);
   print_custom_2D_matrix(cipher_matrix, 3, 3);

   transformed_char_array = transformed_chars(start_str, str_len);

   rows = ceil(str_len / 3.0);

   encoded_matrix = create_custom_2D_matrix(3, rows);
   zero_matrix(encoded_matrix, 3, rows);

   encoded_matrix_final = create_custom_2D_matrix(3, rows);
   zero_matrix(encoded_matrix_final, 3, rows);

   fill_matrix_with_array(encoded_matrix, transformed_char_array, 3, rows, str_len);
   print_custom_2D_matrix(encoded_matrix, 3, 3);

   multiply_matrices(encoded_matrix_final, encoded_matrix, cipher_matrix, 3, rows);

   print_custom_2D_matrix(encoded_matrix_final, 3, rows);

   free(encoded_matrix);
   free(cipher_matrix);
   free(transformed_char_array);
   return start_str;
}

//PENGUINS ARE ONE TO ONE