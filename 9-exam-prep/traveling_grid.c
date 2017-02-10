#include <stdio.h>
#include <stdlib.h>

void find_ways(int x1, int y1, int x2, int y2, int *result) {
   if (x1 == x2 && y1 == y2) {
      *result += 1;
      return;
   }

   if (x1 > x2 || y1 > y2) {
      return;
   }

   if (x1 < x2) {
      find_ways(x1 + 1, y1, x2, y2, result);
   }

   if (y1 < y2) {
      find_ways(x1, y1 + 1, x2, y2, result);
   }
}

int main(int argc, char const *argv[])
{
   if (argc != 5) {
      printf("Error: Invalid # of arguments.\n");
      return -1;
   }

   /**
    * x1, y1, x2, y2
    * x1 < x2, y1 < y2 
    */
   int coords[4] = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])};

   if (coords[0] > coords[2] || coords[1] > coords[3]) {
      printf("Error: The following has to be true: x1 < x2, y1 < y2\n");
      return -2;
   }

   int result = 0;

   find_ways(coords[0], coords[1], coords[2], coords[3], &result);

   printf("There are %d ways from %d/%d to %d/%d\n", result, coords[0], coords[1], coords[2], coords[3]);


   return 0;
}