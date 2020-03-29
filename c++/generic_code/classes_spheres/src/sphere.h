#ifndef sphere_H
#define sphere_H

#include <iostream> //needed for displaying info on the screen

//#include <cmath> originally included to use M_PI to gain 12 decimal places for higher accuracy, but couldn't get it to work
//#pragma warning(disable : 4996) <- was a work around that got me closer to using math.h, but still didn't work 

/**
 * @class sphere sphere.h 
 * @brief      Class to manage spheres
 * This class has an overload function that allows a sphere to be passed, and then 
 * reads out the values for that sphere like radious, diameter and volume.
 */
class Sphere  //initializing class Sphere	
{
public:  //accessibile to anyone who asks for it, need to go through public of class to reach private data
	Sphere(); //default constructor
	Sphere(double); // explicit value constructor for sphere
	double getRadius() const; //accessor to find radius
	double getDiameter() const; // accessor to find
	double getCircumference() const; // accessor to find
	double getArea() const; // accessor to find
	double getVolume() const; // accessor to find
	void setRadius(double); //mutator function to change radius, helps with testing structure of code
	std::ostream& display(std::ostream&); // declaration for the overload function. takes and returns data type ostream&
private: // "hidden" data of object sphere that is generated from class Sphere
	double radius;  // private data of radius
};



#endif // !SPHERE
