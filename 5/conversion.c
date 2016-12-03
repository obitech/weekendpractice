/* conversion.c - Convert between different types and print them as arrays */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
	##################
	#### CONSTANTS ###
	##################
*/ 

// Int array is 32 bits/ints long
#define INTMAX 32

// Hex array is 9 bits/chars long (8 + \0)
#define CHARMAX 9

// Oct array is 10 bits/ints long
#define OCTMAX 10

// Function to set whole array to 0
void null_array(int* array, int max) {
	for (int i = 0; i < max; i++) {
		array[i] = 0;
	}
}

/* 
	##################
	####### I/O ######
	##################
*/ 

// INPUT: integer
int get_int() {
	int z;

	printf("Enter integer value: ");
	scanf("%d", &z);

	return z;
}

// INPUT: hex
int get_hex() {
	int z;

	printf("Enter hex value: 0x");
	scanf("%x", &z);

	return z;
}

// INPUT: oct
int get_oct() {
	int z;

	printf("Enter oct value: 0o");
	scanf("%o", &z);

	return z;
}

// OUTPUT: bin array
void print_bin_array(int* array) {

	printf("Bin:\t");

	for (int i = 0; i < INTMAX; i++) {		

		// Print space every four digits
		if ((i != 0) && i % 4 == 0)
			printf(" ");

		printf("%d", array[i]);
	}

	printf("\n");
}

// OUTPUT: oct array
void print_oct_array(int* array) {
	printf("Oct:\t0o");

	for (int i = 0; i < OCTMAX; i++) {		
		printf("%d", array[i]);
	}

	printf("\n");
}

//OUTPUT: hex_array
void print_hex_array(char* array) {
	printf ("Hex:\t0x%s\n", array);
}

// OUTPUT: single int value
void print_int(int value) {
	printf("Int:\t%d\n", value);
}

// OUTPUT: single hex value
void print_hex(int value) {
	printf("%x\n", value);
}

// OUTPUT: single oct value
void print_oct(int value) {
	printf("%o\n", value);
}

// OUTPUT: single char
void print_char(char value) {
	printf("%c\n", value);
}

/* 
	##################
	### CONVERSIONS ##
	##################
*/ 

// Dec -> Bin
int* dec_bin(int input, int *bin_array) {

	for (int i = INTMAX - 1; i >= 0; i--) {
		*(bin_array + i) = (input & 1);
		input = input >> 1;
	}

	return bin_array;
}

// Bin -> Dec
int bin_dec(int* bin_array, int top_limit, int bot_limit) {
	int evar = 0;

	for (int i = top_limit - 1; i >= bot_limit; i--) {
		evar += *(bin_array + i) * pow(2, (top_limit - (i + 1)));
	}

	return evar;
}

// Bin -> Oct
int* bin_oct(int* bin_array, int* oct_array) {
	int i;
	int max = INTMAX;
	int low = INTMAX - 3;

	// Populating our oct_array with oct values
	for (i = OCTMAX - 1; i >= 0; i--) {

		// Converting every 3 digit block of bin array
		*(oct_array + i) = bin_dec(bin_array, max, low);
		max = low;
		low -= 3;
	}

	return oct_array;
}

// Convert integer between 0 - 16 to its hex symbol
char convert_hex(int input) {
	
	if (input >= 0 && input <= 9)
		return input + 48;
	 	
	else if (input >= 10 && input <= 15) 
		return input + 87;

	else
		return -1;
}

// Bin -> Hex
char* bin_hex(int* bin_array, char *hex_array) {
	int i, tmp;
	int max = INTMAX;
	int low = INTMAX - 4;

	// Looking at every 4 digit block in bin_array
	for (i = CHARMAX - 2; i >= 0; i--) {

		// Converting every 4-block to decimal
		tmp = bin_dec(bin_array, max, low);

		// Converting that decimal value to hex
		*(hex_array + i) = convert_hex(tmp);

		// Moving down another 4-block in the array
		max = low;
		low -= 4;
	}

	// String terminator 
	*(hex_array + CHARMAX) = '\0';

	return hex_array;
}

/* 
	##################
	###### MAIN ######
	##################
*/ 

int main() {

	// Creating arrays & allocating memory 
	int *bin_array = (int*)malloc(INTMAX * sizeof(int));
	int *oct_array = (int*)malloc(OCTMAX * sizeof(int));
	char *hex_array = (char*)malloc(CHARMAX * sizeof(char));

	null_array(bin_array, INTMAX);
	null_array(oct_array, OCTMAX);

	// Overflow sign
	char vz = 0;

	// start var, end var, choice var
	int svar, evar, choice;


	printf("-- Convert between number systems --\n");
STARTMAIN:	
/*	printf("\nSelect a conversion:\n1 - Dec -> Hex\t\t7 - Oct -> Dec\n2 - Dec -> Oct\t\t8 - Oct -> Hex\n3 - Dec -> Bin\t\t9 - Oct -> Bin\n");
	printf("\n4 - Hex -> Dec\t\t10 - Bin -> Dec\n5 - Hex -> Oct\t\t11 - Bin -> Hex\n6 - Hex -> Bin\t\t12 - Bin -> Oct\n\n0 - Exit\n\n> ");*/
	
	printf("\nEnter the corresponding number for your start type:\n");
	printf("1 - Decimal\n2 - Hexadecimal\n3 - Octal\n4 - Binary\n\n0 - Exit\n\n> ");
	scanf("%d", &choice);

	switch(choice) {
		case 0:
			break;

		// Start: Decimal
		case 1: {
			svar = get_int();

			// Convert/print
			dec_bin(svar, bin_array);

			// Convert/print hex
			bin_hex(bin_array, hex_array);
			print_hex_array(hex_array);

			// Convert/print octal
			bin_oct(bin_array, oct_array);
			print_oct_array(oct_array);

			// Print binary
			print_bin_array(bin_array);	

			break;
		}

		// Start: Hexadecimal
		case 2: {
			svar = get_hex();

			// Convert to binary
			dec_bin(svar, bin_array);

			// Convert/print to dec
			evar = bin_dec(bin_array, INTMAX, 0);
			print_int(evar);

			// Convert/print octal
			bin_oct(bin_array, oct_array);
			print_oct_array(oct_array);

			// Print binary
			print_bin_array(bin_array);

			break;
		}

		// Start: Octal
		case 3: {
			svar = get_oct();

			// Convert to binary
			dec_bin(svar, bin_array);

			// Convert/print to dec
			evar = bin_dec(bin_array, INTMAX, 0);
			print_int(evar);

			// Convert/print hex
			bin_hex(bin_array, hex_array);
			print_hex_array(hex_array);

			// Print binary
			print_bin_array(bin_array);

			break;
		}

		// Start: Binary
		case 4: {
			
		}

		default: {
			printf("Invalid input\n");
			goto STARTMAIN;
		}
	}

	// Releasing memory of arrays
	free(hex_array);
	free(bin_array);
	free(oct_array);

	return 0;
}