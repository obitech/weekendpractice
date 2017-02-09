#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	int input, number;
	int count = 0;

	cout << "-- Guessing Game --\n";


	// srand Funktion wird mit seed gefüttert - derzeitige Zeit
	srand(time(NULL));

	// Random number between 1 and 100
	number = rand() % 100 + 1;
	cout << "Guess a number between 1 and 100\n" << endl;

	while(true) {	

		cout << "> ";
		cin >> input;
		count += 1;

		if (input < number)
			cout	<< "Higher!\n";

		else if (input > number)
			cout << "Lower!\n";

		else {
			cout << "You won! The number was " << number << ", you guessed " << count << " times.\n";
			return 0;
		}	
	}
}