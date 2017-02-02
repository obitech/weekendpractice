#include "matrix_cipher.h"

/**
 * Encryption Works with the following:
 * String: penguins are one to one
 * Cipher matrix: -3 -3 -4 0 1 1 4 3 4
 * Encoded message:
 *    [-119 -120 -207 -77 -182 -176 -186 -166]
 *    |  19   30   46  23   29   47   42   32|
 *    [ 135  127  221  78  209  181  201  179]
 */

int main() {
   int choice, n;
   char *string = malloc(100 * sizeof(char));
   int **encoded_message, **cipher_matrix;

   printf("-- Matrix Encryption --\n");
   printf("1 - Encrypt\n2 - Decrypt\n\n0 - Exit\n>");
   choice = get_int();
 
   // Encrypting
   if (choice == 1) {
      printf("\nPlease enter plain text string to encode (finish with ENTER):\n");

      // Had to add a ' ' because somehow \n remained in buffer...
      scanf(" %[^\n]%*c", string);
      
      printf("\nPlease enter size (n-by-n) of cipher matrix:\nn = ");
      n = get_int();
      cipher_matrix = create_custom_2D_matrix(n, n);
      fill_custom_2D_matrix(cipher_matrix, n, n);

      printf("\nEntered cipher matrix:\n");
      print_custom_2D_matrix(cipher_matrix, n, n);

      // Returns pointer to 2D array with encrypted text
      encoded_message = encode(string, cipher_matrix, n);
      printf("\nEncrypted message:\n");
      print_custom_2D_matrix(encoded_message, n, ceil(strlen(string) / (double)n));
   } 

   // Decrypting not implemented yet
   else if (choice == 2) {
      return 0;
   } 

   else {
      return 0;
   }

   return 0;
}
