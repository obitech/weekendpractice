#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int value(int number) {

   if (number > 20 && number < 100) {
      int comp = number;
      switch(comp / 10) {
         case 2: return 6 + value(number % 10);  
         case 3: return 6 + value(number % 10);
         case 4: return 5 + value(number % 10);
         case 5: return 5 + value(number % 10);
         case 6: return 5 + value(number % 10);
         case 7: return 7 + value(number % 10);
         case 8: return 6 + value(number % 10);
         case 9: return 6 + value(number % 10);
         default: return 0;
      }
   }

/*   else if (number % 100 == 0) {
      if (number == 1000) {
         return 8;
      }

      return  8 + value(number / 100);
   }*/

   else if (number > 100 && number < 1000) {
      if (number % 100 == 0) {
         return 7 + value(number / 100) + value(number % 100);
      }
      else {
         return 10 + value(number / 100) + value(number % 100);
      }
   }

   else {
      switch (number) {
         case 0: return 0;
         case 1: return 3;
         case 2: return 3;
         case 3: return 5;
         case 4: return 4;
         case 5: return 4;
         case 6: return 3;
         case 7: return 5;
         case 8: return 5;
         case 9: return 4;
         case 10: return 3;
         case 11: return 6;
         case 12: return 6;
         case 13: return 8;
         case 14: return 8;
         case 15: return 7;
         case 16: return 7;
         case 17: return 9;
         case 18: return 8;
         case 19: return 8;
         case 20: return 6;
         case 100: return 10;
         case 1000: return 11;
         default: return 0;
      }
   }

}

long count1(int number) {
   int count = 0;
   for (int i = 1; i <= number; i++) {
      count += value(i);
   }

   return count;
}

int main(int argc, char const *argv[]) {

   if (argc != 2) {
      printf("Invalid arguments.\n");
      return 1;
   }

   int number = atoi(argv[1]);

   long count = count1(number);
   printf("count = %ld\n", count);

   return 0;
}