#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_string(const char* str) {
   /*
    * Please be advised, the call to strlen(str), being placed in the condition block
    * of the for-loop, will be evaluated on each iteration. 
    *
    * This will produce an O(n^2) complexity for the function. Recommended changes:
    *
    * for (size_t i = 0, len = strlen(str); i < len; ++i) { 
    *    // ...
    * }
    *
    * Here the O(n) strlen(str) will only be called once and will fix the O(n^2)
    * complexity.
    *
    * Sorry, didn't mean to look bossy, but that mistake can be quite subtle and
    * a bugger to find in code.
    */
   int len = strlen(str)
   for (int i = 0; i < len; i++) {
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
