#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int size(int w, int h) {
   if (w == h) {
      return 1;
   }

   else {
      if (w > h) {
         return 1 + size(h, w - h);
      }
      else {
         return  1 + size(w, h - w);
      }
   }
}

// Print array
void printArray(int* array, int size) {

   if (!array) {
      printf ("NULL");
   }

   printf("[");
   for (int i = 0; i < size; i++) {
      printf("%d", array[i]);

      if (i != size - 1) {
         printf(",");
      }
   }
   printf("]\n");
}


int *sq_in_rect(int width, int height) {

   if (width == height) {
      return NULL;
   }

   int w = width;
   int h = height;
   int i = 0;

   int size1 = size(w, h);
   int *array;
   array = malloc(size1 * sizeof(int));



   for(int j = 0; j < size1; j++) {
      if (w > h) {
         array[i] = h;
         w -= h;
         i++;
      }

      else if (w < h) {
         array[i] = w;
         h -= w;
         i++;
      }
      else {
         array[i] = w;
         array[i++] = h;
      }
   }

   return array;
}

int main(int argc, char const *argv[])
{
   if (argc != 3) {
      printf("Invalid # of arguments\n");
      return 1;
   }

   int w = atoi(argv[1]);
   int h = atoi(argv[2]);

   int *result;
   int size1 = size(w, h);

   printf("array size: %d\n", size1);

   result = sq_in_rect(w, h);

   printArray(result, size1);

   return 0;
}