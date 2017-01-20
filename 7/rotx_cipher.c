#include "rotx_header.h"

// Creates new string with set length, +1 for \0 at the end
char* create_string(int length) {
	char* str = malloc((length + 1)* sizeof(char));

	return str;
}

// Convert string to uppercase
char* string_to_upper(char* str, int length) {
	for (int i = 0; i < length; i++) {
		str[i] = toupper((unsigned char) str[i]);
	}

	return str;
}

// Return encoded/decoded char
char code_char(char letter, int key) {
	if (letter < 65 || letter > 90) {
		return letter;
	}

	if ((letter + key) > 90) {
		return letter - ALPHABET_CHARS + key;
	}

	else {
		return letter + key;
	}
}

// Return encoded/decoded string
char* rotx(char* str, int key) {
	int length = strlen(str);
	char* output;

	// Creating empty output string
	output = create_string(length);
	output[length] = '\0';

	for (int i = 0; i < length; i++) {
		output[i] = code_char(str[i], key);
	}

	return output;
}


