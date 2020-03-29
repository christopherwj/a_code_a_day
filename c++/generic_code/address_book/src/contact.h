#ifndef contact
#define contact

#include <iostream>
#include <string>

/**
 * @class contact contact.h  
 * @brief      This class describes a contact.
 */
class Contact
{
private:
public:
	std::string firstName;
	std::string lastName;
	int phoneNumber;
	std::string address;
	Contact();
	Contact(std::string);
	Contact(std::string, std::string);
	Contact(std::string, std::string, int, std::string);
	Contact *next = nullptr;

};

#endif
