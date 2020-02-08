#include <iostream>
#include <cmath>

int main() {
	
	//normal times table
	for (int i = 1; i < 16; i++) {
		if (i < 10) {
			std::cout << " ";
		}
		for (int j = 1; j < 16; j++) {
			if (j < 16) {
				std::cout << "  ";
			}
			std::cout << i * j << "   ";
			//std::cout << std::endl;
		}
		std::cout <<"  " <<std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;
	
	//times tablesquared values 
	for (int i = 1; i < 16; i++) {
		if (i < 10) {
			std::cout << " ";
		}
		for (int j = 1; j < 16; j++) {
			if (j < 16) {
				std::cout << "  ";
			}
			double a = 0;
			a = i * j;
			double b;
			b = exp2(a);

			std::cout << b << "   ";
			//std::cout << std::endl;
		}
		std::cout << "  " << std::endl;
	}

}
