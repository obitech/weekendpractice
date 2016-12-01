/* conversion.c - Convert between different types */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Convert integer between 0 - 16 to hex
char convert_hex(int input) {
	
	if (input >= 0 && input <= 9)
		return input + 48;
	 	
	else if (input >= 10 && input <= 15) 
		return input + 87;

	else
		return -1;
}

// Populatig a  char array with hex values
// 322 = 0x000000142
char* dec_hex_array(int input, char *array) {
	int i, remainder;

	for (i = 8; i >= 0; i--) {
		remainder = input % 16;
		*(array + i) = convert_hex(remainder);
		input = input / 16;
	}

	*(array + 9) = '\0';

	return array;
}

// Read input: integer
int get_int() {
	int z;

	printf("Enter integer value: ");
	scanf("%d", &z);

	return z;
}

// Read input: hex
int get_hex() {
	int z;

	printf("Enter hex value: ");
	scanf("%x", &z);

	return z;
}

/* ########## MAIN ########## */

int main() {
	char *hex_array = (char*)malloc(9 * sizeof(char));
	char vz = 0;
	int svar, evar;
	int value, choice;


	printf("-- Convert between number systems --\n");
STARTMAIN:	
	printf("\nSelect a conversion:\n1 - Dec -> Hex\t\t7 - Oct -> Dec\n2 - Dec -> Oct\t\t8 - Oct -> Hex\n3 - Dec -> Bin\t\t9 - Oct -> Bin\n");
	printf("\n4 - Hex -> Dec\t\t10 - Bin -> Dec\n5 - Hex -> Oct\t\t11 - Bin -> Hex\n6 - Hex -> Bin\t\t12 - Bin -> Oct\n\n0 - Exit\n\n> ");
	scanf("%d", &choice);

	switch(choice) {
		case 0:
			break;

		// Dec -> Hex
		case 1: {
			svar = get_int();

			if (svar < 0) {
				vz = '-';
				svar *= -1;
			}

			// This populates our hex_array
			dec_hex_array(svar, hex_array);
			printf("%d dec = %c0x%s hex\n", svar, vz, hex_array);
			break;
		}

		// Dec -> Oct
		case 3: {
			svar = get_int();
			// evar = dec_to_oct(svar);
			printf("\n");
		}

		default: {
			printf("Not implemented or invalid input (between 0 and 12 required)\n");
			goto STARTMAIN;
		}
	}

	free(hex_array);
	return 0;
}