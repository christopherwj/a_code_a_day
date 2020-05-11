#include "sphere.h" 

std::ostream& operator<<(std::ostream& strm, Sphere& a) 

{  
	return a.display(strm); 
}

int main() {
	Sphere s = Sphere(10.0); 
	std::cout << s; 

	s.setRadius(4.0); 
	std::cout << s; 
	return 0; 
}
