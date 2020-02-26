#include <iostream>

using namespace std;

int main() {
	int a = 1;
	int b = 2;

	cout << "raw int values" << endl;
	cout << a << endl;
	cout << b << endl;

	int* ptr_1;
	int* ptr_2;

	cout << "dereferenced" << endl;
	cout << &ptr_1 << endl;
	cout << &ptr_2 << endl;

	ptr_1 = &a;
	ptr_2 = &b;

	*ptr_1 = 10;

	cout << "chaining pointers to cout" << endl;
	cout << *ptr_1 << endl;
	cout << *ptr_2 << endl;

	*ptr_2 = *ptr_1;

	cout << *ptr_1 << endl;
	cout << *ptr_2 << endl;

	ptr_1 = ptr_2;
	
	cout << ptr_1 << endl;
	cout << ptr_2 << endl;
	
	//double pointers
	 
	int var = 81;

	int* ptr1;	//pointer for var
	int** ptr2;	//pointer for pointer1
	
	ptr1 = &var;	//storing address in the first pointer

	ptr2 = &ptr1;	//storing address of ptr1 in ptr2

	cout << "The value for var is:" << var << endl;
        cout << "The value for the single pointer is:" << *ptr1 << endl;
	cout << "The value for the double pointer is:" << **ptr2 << endl;	
	
	return 0;
	
	// revisiting this code to make sure I am familar with pointers.
}
