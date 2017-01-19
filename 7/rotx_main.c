#include "rotx_header.h"

int main(int argc, char const *argv[])
{
	// Checking for number of arguments
	if (argc != 3) {
		printf("Wrong number of arguments.\n");
		return -1;
	}

	// Getting key
	int key = atoi(argv[2]);

	// Getting string
	int strLen = strlen(argv[1]);
	char* str = create_string(strLen);
	strcpy(str, argv[1]);

	// Converting to uppercase
	str = string_to_upper(str, strLen);

	// Checking for number of arguments
	if (argc != 3) {
		printf("Wrong number of arguments.\n");
		return -1;
	}

	else if (!argv[1]) {
		printf("Empty string invalid.");
		return -1;
	}

	else if (key <= 0 || key > MAX_CIPHERS) {
		printf("Entered key (%d) invalid.\n", key);
	}

	else {
		printf("Char value of 3: %d", '3');
		printf("Cipher: ROT-%d\n", key);
		printf("Input string: %s\n", str);
		printf("Output string: %s\n", rotx(str, key));
	}

	free(str);
	return 0; 
}