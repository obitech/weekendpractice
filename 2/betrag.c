// Ausgabe des absoluten Betrages einer Zahl

#include <stdio.h>

int max(int, int, int);

int main() {
	int n = -235;
	unsigned int betrag;

	// Wenn n kleiner null, mache positiv
	if (n < 0) {
		betrag = n * -1;
	}
	// Ansonsten gib Zahl aus
	else
		betrag = n;

	printf("Der Betrag von %d ist %d.\n",n, betrag);

	return 0;
}