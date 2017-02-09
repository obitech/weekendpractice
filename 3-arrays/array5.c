// Write a program in C to count the total number of duplicate elements in an array.

#include <stdio.h>

int main() {
	int max, i, j, duplicate;

	printf("-- Find duplicate numbers in an array --\n");
	printf("How many numbers do you want to use? ");
	scanf("%d", &max);

	// Defining arrays, creating a pointer to its first element
	int array[max], *ptr_dup;
	ptr_dup =  &array[0];

	// Filling the array
	printf("\nPlease fill the first array: \n");
	for (i = 0; i < max; i++) {
		printf("Index %d = ", i);
		scanf("%d", &array[i]);
	}

	duplicate = 0;
	// Checking for duplicates
	for (i = 0; i < max; i++) {
		if (*(ptr_dup + i) == *(ptr_dup + i + 1)) 
			duplicate += 1;
	}

	// Printig the arrays
	printf("\nThese are the elements stored: ");
	for (i = 0; i < max; i++) {
		printf("%d ", array[i]);
	}

	printf("\nTotal number of duplicates: %d\n", duplicate);

	// Line break for good measure
	printf("\n");

	return 0;
}

/*
Without pointers:
for (i = 0; i < max; i++) {
	if (array[i] == array[i + 1])
		duplicate += 1;
}
*/