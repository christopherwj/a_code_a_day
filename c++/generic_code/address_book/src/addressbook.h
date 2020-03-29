#ifndef addressbook
#define addressbook

#include "contact.h"
/**
 * @class addressbook addressbook.h 
 * @brief      This class describes an address book.
 */
class AddressBook
{
private:
	Contact *head;
	Contact *tail;
	Contact *currentPosition;
public:

	AddressBook();
	void addContact(Contact);
	bool deleteContact(Contact);
	int findContact(std::string firstName);
	int findContact(Contact);
	bool editContact(std::string firstName);
	void getCurrent();
	void makeEmpty();
	void printContact();
	~AddressBook();
};
//astrisks going in dec only
//definition putting something in a datatype (assign) (.cpp)
//declaration: create variable and name it. (.h)

#endif
