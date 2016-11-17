#include <iostream>
using namespace std;

int main () {
	int ergebnis, i;
	cout <<  "-- Quadrate von 1 bis 20 --"

	while (i < 21) {
	ergebnis = i * i;
	cout << i << " hoch 2" << " = " << ergebnis << endl;
	i = i + 1

	return 0;
}
	/*
	for (i = 1; i < 21; i++) {
		ergebnis = i * i;
		cout << i << " hoch 2" << " = " << ergebnis << endl;
	}
	*/
}