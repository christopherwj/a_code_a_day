#include "sphere.h" //included so that all of the declarations are passed to compiler before getting changed below. for memory reasons

/**
 * created to add more precision to pi for calculations
 */
#define M_PI 3.14159265 //had to define this number instead of using math.h


/**
 * @brief      Constructs a new instance.
 */
Sphere::Sphere()  // default constructor for making object sphere initialized with radius as 1
{
	radius = 1;
}
/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  r     radius of sphere being created
 */
Sphere::Sphere(double r) // explicit value constructor takes input type double and creates object with a certain radius passed to function
{
	radius = r;
}
/**
 * @brief      Gets the radius.
 *
 * @return     The radius.
 */
 double Sphere::getRadius() const  //accessor fuction to retrieve radius value to requestor, const used to throw flag if data is attempted to be changed in private
{
	return radius;
}
/**
 * @brief      Gets the diameter.
 *
 * @return     The diameter.
 */
double Sphere::getDiameter() const  //accessor fuction to do the math for diameter and return the value to requestor
{
	double diameter = 0;
	diameter = 2 * radius;
	return diameter;
}
/**
 * @brief      Gets the circumference.
 *
 * @return     The circumference.
 */
double Sphere::getCircumference() const // accessor function for circumference
{
	double circumference;
	circumference = 2 * M_PI * radius;
	return circumference;
}
/**
 * @brief      Gets the area.
 *
 * @return     The area.
 */
double Sphere::getArea() const //accessor function for area
{
	double area;
	area = 4 * M_PI * radius * radius;
	return area;
}
/**
 * @brief      Gets the volume.
 *
 * @return     The volume.
 */
double Sphere::getVolume() const  //accessor function for volume
{
	double volume;
	volume = 4.0 / 3.0 * M_PI * radius * radius * radius;
	return volume;
}
/**
 * @brief      Sets the radius.
 *
 * @param[in]  r     The new value to change the radius to.
 */
void Sphere::setRadius(double r) //mutator when called with a certain object goes into private and changes radius
{
	radius = r;
}
/**
 * @brief      Displays the given out.
 *
 * @param      out   The output to pass along
 *
 * @return     an ostream item to be chained/linked to cout for passing to stdio
 */
std::ostream& Sphere::display(std::ostream &out) 
//overloading helper function this allows the programmer to overload cout and by chaining a object with cout out instead of printing the memory address will print the line below
{
	return out << "The radius is " << getRadius() << "\nThe diameter is " << getDiameter() << "\nThe volume is " << getVolume() << "\nThe area is " << getArea() << "\n" << std::endl;  
	//when sphere object "s" is chained it will print this statement as it is returned and passed to cout through "<<" operator
} 


