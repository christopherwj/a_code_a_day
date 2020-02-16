#include <iostream>
#include <limits>


//Typecasting is making a data structure act like another data structure for a single operation. It is typically used in such a manner where precision isn't lost.


//printing the ASCII table to know equivalent 


int main() {
//std::cout.precision(10);

	for (int i = 1; i < 128; i++) {
		 std::cout << "double:" << i <<"  " << "char:" << (char)i<<"  " <<  std::endl;
	}
	
	return 0;
}