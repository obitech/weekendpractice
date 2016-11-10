#include <iostream>
using namespace std;

float alk_masse(float, float);

int main() {
	int m, v;
	float bak, e;

	cout << "-- Berechnung der Blutalkoholkonzentration --" << endl;
	cout << "Volumen des Getränks in ml: ";
	cin >> v;
	cout << "Alkoholvolumenanteil in Prozent: ";
	cin >> e;
	cout << "Masse der Person in kg: ";
	cin >> m;

	// Berechnen der Blutalkoholkonzentration
	// m = Masse der Person	
	bak = alk_masse(e, v) / (m * 0.62);

	cout << "Blutalkoholkonzentration = " << bak << endl;

	return 0;
}

// Berechnen der aufgenommen Masse des Alkohols
// e = Alkoholvolumenanteil
// v = Volumen des Getränks
float alk_masse(float e, float v) {
	return (v * (e / 100) * 0.8);
}


