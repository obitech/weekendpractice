/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* Constants */
#define ALPHABET_CHARS 	26
#define MAX_CIPHERS 		25

/* Functions */
char*		create_string(int length);
int		check_string(char* str);
char*		string_to_upper(char* str, int length);
char 		code_char(char letter, int key);
char*		rotx(char* str, int key);

