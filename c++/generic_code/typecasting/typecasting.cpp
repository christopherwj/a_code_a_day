#include <iostream>

//Typecasting is making a data structure act like another data structure for a single operation. It is typically used in such a manner where precision isn't lost.


//printing the ASCII table to know equivalent 


int main() {

	for (int i = 0; i < 128; i++) {
		std::cout << i << " " << (char)i << std::endl;
	}
	return 0;
}