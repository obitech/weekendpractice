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
   int choice, n, rows;
   char *string;
   encrypted encoded_message;
   int **cipher_matrix = NULL;

   encoded_message.message = NULL;
   encoded_message.encoded = 0;

   printf("-- Matrix Encryption --\n");

   while (1) {
START:

      printf("Please choose:\n1 - Encrypt\n2 - Decrypt\n\n0 - Exit\n> ");
      choice = get_int();

      if (choice == 1) {
ENCRYPTING:         

         string = malloc(100 * sizeof(char));
         printf("\nPlease enter plain text string to encode (100 chars max, finish with ENTER):\n");

         // Had to add a ' ' because somehow \n remained in buffer...
         scanf(" %[^\n]%*c", string);
         
         // Only implemented 3-by-3 matrix operations
         printf("Enter dimension of cipher matrix (n by n):\nn = ");
         n = get_int();

         cipher_matrix = create_custom_2D_matrix(n, n);
         fill_custom_2D_matrix(cipher_matrix, n, n);

         if (determinant(cipher_matrix, n) == 0) {
            printf("Error, cipher matrix is not invertible.\n");
            free(cipher_matrix);
            goto ENCRYPTING;
         }

         printf("\nEntered cipher matrix:\n");
         print_custom_2D_matrix(cipher_matrix, n, n);

         // Returns pointer to 2D array with encrypted text
         encoded_message.rows = n;
         encoded_message.cols = ceil(strlen(string) / (double)n);
         encoded_message = encode(string, cipher_matrix, n);
         printf("\nEncrypted message:\n");
         print_custom_2D_matrix(encoded_message.message, encoded_message.cols, encoded_message.rows);

         printf("\nPlease choose:\n");
         printf("1 - Encrypt again\n2 - Decrypt a message\n0 - Exit\n> ");
         choice = get_int();
         switch(choice) {
            case 1:
               overwrite_matrix(encoded_message.message, encoded_message.cols, encoded_message.rows);
               encoded_message.encoded = 0;
               goto ENCRYPTING;
               break;
            case 2:
               goto DECRYPTING;
               break;
            default:
               overwrite_matrix(encoded_message.message, encoded_message.cols, encoded_message.rows);
               return 0;
               break;
         }
      } 

      else if (choice == 2) {
DECRYPTING:

         if (encoded_message.encoded) {
            printf("Encrypted message found, do you want to decrypt?\n");
            printf("1 - Yes\n2 - No, use different encrypted message\n3 - Delete\n0 - Exit\n> ");
            choice = get_int();

            switch(choice) {
               case 1:
                  // Decrypting
                  overwrite_matrix(encoded_message.message, encoded_message.cols, encoded_message.rows);
                  break;
               case 2:
                  overwrite_matrix(encoded_message.message, encoded_message.cols, encoded_message.rows);
                  encoded_message.encoded = 0;
                  break;
               case 3:
                  overwrite_matrix(encoded_message.message, encoded_message.cols, encoded_message.rows);
                  encoded_message.encoded = 0;
                  break;
               default:
                  overwrite_matrix(encoded_message.message, encoded_message.cols, encoded_message.rows);
                  encoded_message.encoded = 0;
                  return 0;
            }
         }
      } 

      else {
         return 0;
      }

   }

   return 0;
}
