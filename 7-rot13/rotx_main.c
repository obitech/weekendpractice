#include "rotx_header.h"

int main(int argc, char const *argv[])
{
	int key, length;
	char *input, *output;

	// Getting key
	key = atoi(argv[2]);

	// Checking for number of arguments
	if (argc != 3) {
		printf("Wrong number of arguments.\n");
		return -1;
	}

	else if (key <= 0 || key > MAX_CIPHERS) {
		printf("Entered key (%d) invalid.\n", key);
		return -1;
	}

	// Getting string
	length = strlen(argv[1]);
	input = create_string(length);
	strcpy(input, argv[1]);

	// Converting to uppercase
	input = string_to_upper(input, length);

	// Applying ROT
	output = rotx(input, key);

	// Output to terminal
	printf("Cipher: ROT-%d\n", key);
	printf("Input string: \"%s\"\n", input);
	printf("Output string: \"%s\"\n", output);

	free(input);
	free(output);
	return 0; 
}