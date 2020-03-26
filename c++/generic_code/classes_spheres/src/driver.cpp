#include "sphere.h" //used for loading all the necessary declarations for Sphere.cpp

std::ostream& operator<<(std::ostream& strm, Sphere& a) 
// forward declaration of overload function so that all of the << operators used for cout are intrepreated based off of the rules set by this function.
{  
	return a.display(strm); //returns display function so that cout can print them when an object is passed.
}

int main() {
	Sphere s = Sphere(10.0); //here I declare and initialize a sphere object from Sphere class with a radius of 10 in the same line
	std::cout << s; // this is where the << operator is overloaded to return the display function of the object s (from sphere class)

	s.setRadius(4.0); // using the mutator we go into private and change radius 10.0 to radius 4.0
	std::cout << s; // << operator is again overloaded and the object s is printed

	return 0; 
}
