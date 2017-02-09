#include <stdio.h>

int max(int, int ,int);
int atoi(const char*);

int main(int argc, char const **varg)
{
	if (argc != 4) {
		printf("Falsche Parameteranzahl.\n");
		return -1;
	}

	int a = atoi(varg[1]);
	int b = atoi(varg[2]);
	int c = atoi(varg[3]);

	printf("Input: %d, %d, %d\n", a, b, c);
	printf("Größte Zahl: %d\n", max(a, b, c));

	return 0;
}

int max(int a, int b, int c) {
	
	if ((a > b) && (a > c))
		return a;
	else if ((b > a) && (b > c))
		return b;
	else 
		return c;
}