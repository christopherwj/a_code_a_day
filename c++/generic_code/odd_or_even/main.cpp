#include <stdio.h>
#include <iostream>

using namespace std;



int main() {
	float a; 

	cout << "Please enter a number to decide if it is odd or even." << endl;
	cin >> a;

	if (fmod(a, 2) != 0) {
		cout << " The number is odd" << endl;
	}
	else
	cout << "The number is even.";
}


//a is double, thus you cannot use the modulo operator %.