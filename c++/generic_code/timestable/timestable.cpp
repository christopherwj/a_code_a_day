#include <iostream>

int main() {
	

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
}
