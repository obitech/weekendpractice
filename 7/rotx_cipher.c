#include "rotx_header.h"

// Creates new string with set length, +1 for \0 at the end
char* create_string(int length) {
	char* str = malloc((length + 1)* sizeof(char));

	return str;
}

// Check for valid string

// Convert string to uppercase
char* string_to_upper(char* str, int length) {
	for (int i = 0; i < length; i++) {
		str[i] = toupper((unsigned char) str[i]);
	}

	return str;
}

// Cipher
char* rotx(char* str, int key) {
	int length = strlen(str);
	char* output;

	// Creating empty output string
	output = malloc((length + 1) * sizeof(char));
	output[length] = '\0';

	// Standard alphabet
	char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	// Cipher alphabet = rotated alphabet
	char* cipher_alphabet = malloc((length + 1) * sizeof(char));
	for (int i = 0; i < ALPHABET_CHARS; i++) {
		if (alphabet[i] + key <= 90) {
			cipher_alphabet[i] = alphabet[i] + key;
		}
		else {
			cipher_alphabet[i] = (alphabet[i] - ALPHABET_CHARS) + key;
		}
	}

	// Checking alphabet against cipher_alphabet; deciding if decrypting or encypting
	// Encrypting
	if (cipher_alphabet[0] > alphabet[0]) {
		for (int i = 0; i < length; i++) {
			if ((str[i] + key) <= 90) {
				output[i] = str[i] + key;	
			}
			else {
				output[i] = (str[i] - ALPHABET_CHARS) + key;
			}
		}
	}

	// Decrypting
	else {
		for (int i = 0; i < length; i++) {
			if ((str[i] - key) >= 65) {
				output[i] = str[i] - key;	
			}
			else {
				output[i] = str[i] + key;
			}
		}
	}

	return output;
}



//free();

