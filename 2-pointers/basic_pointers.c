#include <stdio.h>

int main() {
	int m = 29;

	printf("Address of m: %p\n", &m);
	printf("Value of m: %d\n\n", m);

	int *ab;
	// Pointer ab zeigt auf m
	ab = &m // &m = 0x5234ffsafsdf

	printf("Now ab is assigned with the address of m.\n");
	printf("Pointer ab points to address: %p\n", ab);
	printf("(Pointer ab has own address: %p)\n", &ab);
	printf("Content of pointer ab: %d\n\n", *ab);
	// Change value of m;
	*ab = 45;  // 
	printf("Content of m = %d\n", m);


	*ab = 34;
	printf("The value of m is assigned to 34 now.\n");
	printf("Address of pointer ab: %p\n", ab);
	printf("Content of pointer ab: %d\n", *ab);

	*ab = 7;
	printf("The pointer variable ab is assigned with the value 7 now.\n");
	printf("Address of m: %p\n", &m);
	printf("Value of m: %d\n", m);
}

