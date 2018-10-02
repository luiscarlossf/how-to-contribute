// simpletest.cpp : Defines the entry point for the console application.
//


#include <iostream>
using namespace std;

//simple calculator
int main()

{
	start:
	float a,b;
	cout << "Enter the first number" << endl;
	cin >> a;
	cout << "Enter the second number" << endl;
	cin >> b;
	cout << "Enter 1 for addition, 2 for subtraction, 3 for multiplication, and 4 for division" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		cout << a + b;
	}
	else if (choice == 2) {
		cout << a - b;
	}
	else if (choice == 3) {
		cout << a * b;
	}
	else if (choice == 4) {
		cout << a / b;
	}
	cout << endl << "Type 1 to return to start, otherwise press any key" << endl;
	cin >> choice;
	if (choice == 1) { goto start; }
	
	
	return 0;
}

