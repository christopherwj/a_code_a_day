#include "addressbook.h"

AddressBook::AddressBook() {
	head = nullptr;
	tail = nullptr;
	currentPosition = head;
}


void AddressBook::addContact(Contact newContact) {
	Contact *temp = new Contact();
	temp->firstName = newContact.firstName;
	temp->lastName = newContact.lastName;
	temp->phoneNumber = newContact.phoneNumber;
	temp->address = newContact.address;

	if (head == nullptr) {
		head = temp;
		tail = temp;
		return;
	}

	Contact *c = head;
	while (currentPosition->next != nullptr) {
		if (currentPosition->firstName.compare(temp->firstName) == 0)
		{
			temp->next = currentPosition->next;
				currentPosition->next = temp;
				return;
		}
		c = c->next;
	}
}

bool AddressBook::deleteContact(Contact toDelete){
	Contact *temp = head;
	currentPosition = head->next;
	while(currentPosition->next != nullptr){
		if (currentPosition->firstName.compare(toDelete.firstName)!= 0){
			currentPosition = currentPosition->next;
			continue;
		}
		if (currentPosition->lastName.compare(toDelete.lastName)!= 0){
			currentPosition = currentPosition->next;
			continue;
		}
		temp->next = currentPosition->next;
		delete currentPosition;
		currentPosition = temp->next;
	}
	return 0;

}

int AddressBook::findContact(std::string firstName){
	if (head == nullptr) { return 0; }
	currentPosition = head;
	while(currentPosition->next != nullptr){
		if (currentPosition->firstName.compare(firstName) == 0){
			break;
		}
		currentPosition = currentPosition->next;
	}

	return 1;
}

int AddressBook::findContact(Contact compare){
	if (head == nullptr) { return 0; }
	currentPosition = head;
	while(currentPosition->next != nullptr){
		if (!currentPosition->firstName.compare(compare.firstName)){
			return 1;
		}
		currentPosition = currentPosition->next;
	}

	return 0;
}

bool AddressBook::editContact(std::string firstName){
	if (head == nullptr) { return false; }
	currentPosition = head;
	while (currentPosition->next != nullptr) {
		if (currentPosition->firstName.compare(firstName) == 0) {
			break;
		}
		currentPosition = currentPosition->next;
	}
	int a;
	std::cout << "The contact you wish to edit is:\n" ;
	std::cout << currentPosition->firstName << std::endl;
	std::cout << currentPosition->lastName << std::endl;
	std::cout << currentPosition->phoneNumber << std::endl;
	std::cout << currentPosition->address << std::endl;
	std::cout << "proceed? press '1' for yes and '2' for no\n";
	std::cin >> a;
	    if (a == 2 ) { return false; }

	int n;
	std::cout << "Which part of the contact do you want to edit?\n";
	std::cout << "Please press 1 to change the first name.\n";
	std::cout << "Please press 2 to change the last name.\n";
	std::cout << "Please press 3 to change phone number.\n";
	std::cout << "Please press 4 to change the address.\n";
	std::cin >> n;

	std::string tempFname;
	std::string tempLname;
	int tempPhoneNumber;
	std::string tempAddress;
	switch (n)
	{
	case 1:
		std::cout << "Please enter a first name.\n";
		std::cin >> tempFname;
		currentPosition->firstName = tempFname;
		std::cout << "Done.\n";
		break;
	case 2:
		std::cout << "Please enter a last name to edit.\n";
		std::cin >> tempLname;
		currentPosition->lastName = tempLname;
		std::cout << "Done.\n";
		break;
	case 3:
		std::cout << "Please enter a number to replace.\n";
		std::cin >> tempPhoneNumber;
		currentPosition->phoneNumber = tempPhoneNumber;
		std::cout << "Done.\n";
		break;
	case 4:
		std::cout << "Please enter a new address to replace existing.\n";
		std::cin >> tempAddress;
		currentPosition->address = tempAddress;
		std::cout << "Done.\n";
		break;
	default:
	std::cout << "Please enter a valid number and try again.\n";
	}
	std::cout << "Your updated contact is now:\n" ;
	std::cout << currentPosition->firstName << std::endl;
	std::cout << currentPosition->lastName << std::endl;
	std::cout << currentPosition->phoneNumber << std::endl;
	std::cout << currentPosition->address << std::endl;
	return true;
}

void AddressBook::getCurrent() {

	std::cout << currentPosition->firstName << std::endl;
	std::cout << currentPosition->lastName << std::endl;
	std::cout << currentPosition->phoneNumber << std::endl;
	std::cout << currentPosition->address << std::endl;

}

void AddressBook::makeEmpty() {
	Contact *temp = head->next;
	while(true){
		if (temp == nullptr) {
			break;
		}
	head = temp;
	temp = head->next;
	}
}

void AddressBook::printContact() {

	std::cout << currentPosition->firstName << std::endl;
	std::cout << currentPosition->lastName << std::endl;
	std::cout << currentPosition->phoneNumber << std::endl;
	std::cout << currentPosition->address << std::endl;
}

AddressBook::~AddressBook()
{
	makeEmpty();
}
