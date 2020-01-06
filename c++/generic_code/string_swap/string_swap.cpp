#include <iostream>
#include <string>

//goal: to reverse the string abcdef 
using namespace std;

//here is my attempt

/*
void swap(string *input) {

	
	if (input->length() <= 1) {
		cout << "The string is too little to reverse.";
		return 0;
	}

	int i = input->length();
	int j = 0;
	int k = i;
	string *temp;

	while (j < i) {
		temp = &input[j];
		j++;
		k--;
	}
	return temp;
}
*/

/*
below code is largely reproduced from https://www.educative.io/edpresso/how-to-reverse-a-string-in-cpp
I do not claim credit nor claim it as my own work and it exists purely for reference.
*/


int main() {

	string str = "abcdef";
	cout << str;

	int length = str.length();
	int n = length - 1;

	for (int i = 0; i < (length / 2); i++) {
		swap(str[i], str[n]);  // I didn't know c++ had a built in swap function!!!!!
		n = n - 1;
	}
	
	cout << "\n" << str;
}