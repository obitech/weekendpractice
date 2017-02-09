// Write a program in C to copy the elements of one array into another array.

#include <stdio.h>

int main() {
	int max, i;

	printf("-- Copy from one array into another --\n");
	printf("How many numbers do you want to use? ");
	scanf("%d", &max);

	int array1[max], array2[max];

	// Filling the array
	printf("\nPlease fill the first array: \n");
	for (i = 0; i < max; i++) {
		printf("Index %d = ", i);
		scanf("%d", &array1[i]);

		array2[i] = array1[i];
	}

	// Printig the arrays
	printf("\nThese are the elements stored: ");
	for (i = 0; i < max; i++) {
		printf("%d ", array1[i]);

	// Line break for good measure
	printf("\n");

	return 0;
}