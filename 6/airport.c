/* airport.c
 * Implemnted in C from https://www.codewars.com/kata/airport-arrivals-slash-departures-number-1/
 * The following 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 55 chars with \0
const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ?!@#&()|<>.:=-+*/0123456789";

// Input string and get its length
int getString(char *s, int maxlen) {
	int len;

	s = fgets(s, maxlen , stdin); 
		if(s == NULL)
			return 0;
	len = strlen(s);
	if (s[len - 1] == '\n')
		s[--len] = '\0'; // remove line break
	return len; 
} 

// Get integer
int getInt() {
	int z;
	scanf("%d", &z);
	return z;
}

// Create array and fill with 0
int* createArray(int size) {
	int* array = (int*) malloc(size * sizeof(int));

	for (int i = 0; i < size; i++) {
		array[i] = 0;
	}

	return array;
}

// Print array
void printArray(int* array, int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf("%d", array[i]);

		if (i != size - 1) {
			printf(",");
		}
	}
	printf("]\n");
}

// Rotate a single char
char rotateChar(char letter, int times) {
	int pos_in_alphabet = 0, new_pos = 0;
	char new_char;
	int i = 0;

	// Find current position of letter in alphabet string
	while (alphabet[i] != letter) {
		i++;
		pos_in_alphabet = i;
	}

	// Go forward through array and find letter
	new_pos = pos_in_alphabet + times;
	if (new_pos > 54) {
		new_pos -= 54;
	}

	// Return new letter
	return alphabet[new_pos];	
}

char* flap(char* result, int* rotors) {
	int str_len = strlen(result);

	for (int i = 0; i < str_len; i++) {
		for (int j = i; j < str_len; j++) {
			result[j] = rotateChar(result[j], rotors[i]);
		} 
	}

	return result;
}

int main() {
	char *lines, *result;
	int* rotors;
	int str_len;
	int max_length = 50;

	lines = malloc(max_length * sizeof(char));
	result = malloc(max_length * sizeof(char));

	printf("-- Airport display --\n");

	printf("Start string:\n> ");
	str_len = getString(lines, max_length);

	// Convert string to uppercase
	for (int i = 0; i < str_len; i++) {
		result[i] = (toupper(lines[i]));
	}

	// Create rotors array and get rotation inputs from user
	rotors = createArray(str_len);
	for (int i = 0; i < str_len; i++) {
		printf("Enter value for rotor %d: ", (i + 1));
		rotors[i] = getInt();
	}
	
	printf("\nRotating \"%s\", by ", result);
	printArray(rotors, str_len);
	printf("\n");

	result = flap(lines, rotors);
	printf("Result: \"%s\"\n", result);

	return 0;	
}