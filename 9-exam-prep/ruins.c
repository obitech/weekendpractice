#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_string(const char* str) {
   for (int i = 0; i < strlen(str); i++) {
      if (str[i] ==  '?') {
         if (str[i + 1]  ==  'a' || str[i - 1] == 'a') {
            printf("b");
         }
         else {
            printf("a");
         }
      }
      else {
         printf("%c", str[i]);
      }
   }
   printf("\n");
}

int main(int argc, char const *argv[])
{
   if (argc != 2) {
      printf("Invalid number of parameters.\n");
      return 1;
   }

   if (strlen(argv[1]) > 50) {
      printf("String too long.\n");
      return 1;
   }

   print_string(argv[1]);

   return 0;
}