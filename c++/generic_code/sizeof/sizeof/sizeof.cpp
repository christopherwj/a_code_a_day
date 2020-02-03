#include <iostream>
#include <string>

using namespace std;

class Chris
{
private:
	string thoughts = "My name is chris.";
public:
	int height = 173; //cm
};



int main() {
	int a;
	int *ptr;	
	ptr = &a;	//pointers must point to the same data type

	cout << " The size of an int pointer is:" << sizeof(&a) << endl;	// should be 4 since that is the size of an int
	cout << " The size of the chris class is:" << sizeof(Chris) << endl;
	cout << " The size of int is:" << sizeof(int) << endl;
	cout << " The size of float is:" << sizeof(float) << endl;
	cout << " The size of char is:" << sizeof(char) << endl;
	cout << " The size of bool is:" << sizeof(bool) << endl;
	cout << " The size of short int is:" << sizeof(short int) << endl;
	cout << " The size of long int is:" << sizeof(long int) << endl;
	cout << " The size of signed long int is:" << sizeof(signed long int) << endl;
	cout << " The size of unsigned long int is:" << sizeof(unsigned long int) << endl;
	cout << " The size of double is:" << sizeof(double) << endl;
	cout << " The size of wchar_t is:" << sizeof(wchar_t) << endl;
}