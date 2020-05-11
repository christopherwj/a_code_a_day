#ifndef sphere_H
#define sphere_H

#include <iostream> //needed for displaying info on the screen



/**
 * @class sphere sphere.h 
 * @brief      Class to manage spheres
 * This class has an overload function that allows a sphere to be passed, 
 * and then reads out the values for that sphere like radious, 
 * diameter and volume.
 */
class Sphere  //initializing class Sphere	
{
public:  
	Sphere();
	Sphere(double); 
	double getRadius() const; 
	double getDiameter() const; 
	double getCircumference() const; 
	double getArea() const; 
	double getVolume() const; 
	void setRadius(double); 
	std::ostream& display(std::ostream&); 
private: 
	double radius;  
};



#endif 
