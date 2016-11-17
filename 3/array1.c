// Write a program in C to store elements in an array and print it.

#include <stdio.h>

int main() {
	int max = 5;
	int array[max], i, input;

	// Filling the array
	printf("Please fill the array: \n");
	for (i = 0; i < max; i++) {
		printf("Index %d = ", i);
		scanf("%d", &array[i]);
	}

	// Printig the array
	printf("Elements in the array are: ");
	for (i = 0; i < max; i++) {
		printf("%d ", array[i]);
	}
	
	// Line break for good measure
	printf("\n");

	return 0;
}