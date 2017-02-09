#include "matrix_cipher.h"

// Get cofactor at position matrix[cur_row][cur_col]
void cofactor(int **temp, int **matrix, int cur_row, int cur_col) {
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (j == cur_col) {
            temp[i][j] = matrix[i + 1][j + 1];
         }
         else {
            if (cur_col == 0) {
               temp[i][j] = matrix[i + 1][j + 1];
            } 
            else {
               temp[i][j] = matrix[i + 1][j];
            }
         }
      }
   }
}

int determinant(int **matrix, int n) {
   int **temp, prod, sign;

   if (n == 1) {
      return matrix[0][0];
   }

   else {
      // Cofactor matrix
      temp = create_custom_2D_matrix(n - 1, n - 1);
      prod = 0;
      sign = 1;

      for (int i = 0; i < n; i++) {
         cofactor(temp, matrix, n - 1, 0, i);

         prod += sign * matrix[0][i] * determinant(temp, n - 1);

         sign = -sign;
      }

      free(temp);
      
      return prod;
   }
}

int **matrix_of_minors(int **matrix, int rows) {
   int **temp, **output;

   temp = create_custom_2D_matrix(rows, rows);
   output = create_custom_2D_matrix(rows, rows);

   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < rows; j++) {
         cofactor(temp, matrix, i, j);

         output[i][j] = determinant(temp, rows - 1)
      }
   }

   free(temp);
}