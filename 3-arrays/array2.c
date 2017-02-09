// Write a program in C to read n number of values in an array 
// and display it in reverse order.

#include <stdio.h>

int main() {
	int max = 5;
	int array[max], i;

	// Filling the array
	printf("Please fill the array: \n");
	for (i = 0; i < max; i++) {
		printf("Index %d = ", i);
		scanf("%d", &array[i]);
	}

	// Printig the array
	printf("These are the elements reversed: ");
	for (i = max - 1; i >= 0; --i) {
		printf("%d ", array[i]);
	}
	
	// Line break for good measure
	printf("\n");

	return 0;
}