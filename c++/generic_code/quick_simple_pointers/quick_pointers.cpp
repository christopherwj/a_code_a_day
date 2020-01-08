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

	return 0;
}
