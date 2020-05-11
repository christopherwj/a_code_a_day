#include "sphere.h" 

/**
 * created to add more precision to pi for calculations
 */
#define M_PI 3.14159265 


/**
 * @brief      Constructs a new instance.
 */
Sphere::Sphere()  
{
	radius = 1;
}
/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  r     radius of sphere being created
 */
Sphere::Sphere(double r) 
{
	radius = r;
}
/**
 * @brief      Gets the radius.
 *
 * @return     The radius.
 */
 double Sphere::getRadius() const 
{
	return radius;
}
/**
 * @brief      Gets the diameter.
 *
 * @return     The diameter.
 */
double Sphere::getDiameter() const  
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
double Sphere::getCircumference() const 
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
double Sphere::getArea() const 
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
double Sphere::getVolume() const  
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
void Sphere::setRadius(double r) 
{
	radius = r;
}
/**
 * @brief      Displays the given out.
 *
 * @param      out   The output to pass along
 *
 * @return     an ostream item to be chained/linked to cout 
 */
std::ostream& Sphere::display(std::ostream &out) 
{
	return out << "The radius is " << getRadius() 
		<< "\nThe diameter is " << getDiameter() << "\nThe volume is " 
			<< getVolume() << "\nThe area is " << getArea() << "\n" 
				<< std::endl;  
	
} 


