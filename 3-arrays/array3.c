// Write a program in C to find the sum of all elements in an array.

#include <stdio.h>

int main() {
	int max, i;

	printf("-- Find the sum of a series of numbers --\n");
	printf("How many numbers do you want to use? ");
	scanf("%d", &max);

	int array[max], sum;

	// Filling the array
	printf("\nPlease fill the array: \n");
	for (i = 0; i < max; i++) {
		printf("Index %d = ", i);
		scanf("%d", &array[i]);
		
		sum += array[i];
	}

	// Printig the array
	printf("\nThese are the elements stored: ");
	for (i = max - 1; i >= 0; --i) {
		printf("%d ", array[i]);
	}
	
	printf("\nThe sum of all elements is: %d\n", sum);

	return 0;
}