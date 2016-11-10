#include <iostream>
#include <string>
using namespace std;

int main() {
	string name;
	int age;
	long int id;

	cout << "-- Basic I/O --" << endl;

	while (true) {
		cout << "Name: ";
		getline(cin, name);

		// String needs to be between 1 and 20 characters
		if ( (name.length() >= 1) && (name.length() <= 20) )
			break;

		// String shouldn't be empty
		else if (name.compare(""))
			cout << "Invalid entry.\n";
		else
			cout << "Invalid entry.\n";

	}

	while (true) {
		cout << "Age: ";
		cin >> age;
		
		// Age should be between 1 and 150 years
		if ((! cin.fail()) && (age > 0) && (age <= 150) )
			break;
		else
			cout << "Invalid age.\n";	
	}	

	while (true) {
		cout << "ID: ";
		cin >> id;

		if ((id >= 1) && (id <= 999999)) 
			break;

		else 
			cout << "Invalid ID.\n";
	}

	cout << "You are " << name << " aged " << age << ". Next year you will be " << (age + 1) << ", with user id " << id << ", the next user is " << (id + 1) << endl;
}




