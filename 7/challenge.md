# rotx.c

One of the simplest forms of encryption is the __Caesar Cipher__. From [Wikipedia](https://en.wikipedia.org/wiki/Caesar_cipher):

> It is a type of substitution cipher in which each letter in the plaintext is replaced by a letter some fixed number of positions down the alphabet. For example, with a left shift of 3, D would be replaced by A, E would become B, and so on. The method is named after Julius Caesar, who used it in his private correspondence.

A common example of this cipher is [ROT-13](https://en.wikipedia.org/wiki/ROT13) (rotate-by-13), where every letter is replaced by its 13th letter ahead in the alphabet:

![ROT-13 Example Picture](https://31.media.tumblr.com/dcb651380cf87d279db109dd3a4d0ba4/tumblr_inline_n513r2Ptlo1sduyz6.png "ROT-13 Example Picture")

This can also be done with different keys from 0 - 25 where the value stands for the correspondent letter x-times ahead in the alphabet (so ROT-24 means rotate by 24 letters).

## Task

__Write a program in C which takes a string and a positive integer value from 0 - 25 as input and returns an encrypted/decrypted string.__

### I/O
The initial string and the key should be entered from the command line and your program should print the new string to the terminal:
```
./rotx "Alex" 13
Cipher: ROT-13 
Input String: "Hello"
Output String: "URYYB"
```
It's probably better to convert all letters to uppercase first. Unicode characters such as ```ä, ö, ü, etc.``` will not be rotated and remain as such. Bonus points if your program can read/write from/to a file.

### Structure
Your program should have the following structure:
* __rotx_header.h__ -- including libraries, defining constants, declaring functions
```
// Example:
#include <stdlib.h>
#include <stdio.h>
/* ... */

#define MAX_CIPHERS 25
/* ... */

const char* rot(const char* str, unsigned int key);
/* ... */

```
* __rotx_main.c__ -- taking only command line arguments, calling functions and printing output. 
```
// Example:
#include "rotx_header.h"

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
```
* __rotx_cipher.c__ -- defintions of your algorithm & supporting functions
```
// Example:

const char* rot(const char* str, unsigned int key) {
	/* code */
}
/* ... */
```
__The  final product needs to have this structure!__ It is strongly recommend to set it up like this from the beginning and test if it's working/compiling before writing any logic. If you decide to write your code in a single file first, make sure to create the structure at the end. 

Creating a special ```Makefile``` for this project is advised. A quick tutorial for this can be found [here](http://mrbook.org/blog/tutorials/make/ "MrBook's Makefile Tutorial") and [here](http://gribblelab.org/CBootcamp/12_Compiling_linking_Makefile_header_files.html "gribblelab.org - Compiling, Linking, Makefile, Headers").
