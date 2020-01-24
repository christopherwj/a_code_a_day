#include "main.h"

//declaring forward declarations to initialize before calling
int main(){
		 //create instance of contact
	int input;

	do
	{
		std::string firstName, lastName, address;
		int phoneNumber;
		input = menu();
		Contact c;

		switch (input){
		case 1:
			std::cout << "Please enter your first name.\n";
			std::cin >> firstName;
			std::cout << "Please enter the last name\n";
			std::cin >> lastName;
			std::cout << "Please enter a phone number to associate with the contact.\n";
			std::cin >> phoneNumber;
			std::cout << "Please input an address to associate.\n";
			std::cin >> address;
			std::cout << "You have entered in all fields of a contact!\n";
			c = Contact(firstName, lastName, phoneNumber, address);
			a.addContact(c);
			pauseScreen();
			break;
		case 2:
			std::cout << "Please enter the contact first name you wish to find.\n";
			std::cin >> firstName;
  			c = Contact(firstName);
			if (a.findContact(c)){
				std::cout << "Contact not found please try again\n";
				pauseScreen();
				break;
			}
			std::cout << "The contact has been found and consists of the following info.\n";
			a.printContact();
			pauseScreen();
			break;
		case 3:
			std::cout << "Please enter the contact's first name you wish to edit.\n";
			std::cin >> firstName;
			if (!a.editContact(firstName)) {
				std::cout << "Contact change failed. Please try again.\n";
				pauseScreen();
				break;
			}
			pauseScreen();
			break;
		case 4:
		std::cout << "Please enter your first name.\n";
		std::cin >> firstName;
		std::cout << "Please enter the last name\n";
		std::cin >> lastName;
		c = Contact(firstName, lastName);
		a.deleteContact(c);
			pauseScreen();
			break;
		case 5:
			a.getCurrent();
			pauseScreen();
			break;
		default:
			std::cout << "Goodbye";
			pauseScreen();
		}
		clearScreen();
	} while (input != 6);

}
int menu()
{
	int input;
	std::cout << "Enter the number for the operation you wish to perform from the menu.\n";
	std::cout << "1. Add Contact\n";
	std::cout << "2. Find Contact\n";
	std::cout << "3. Edit Contact\n";
	std::cout << "4. Delete Contact\n";
	std::cout << "5. Display Current Contact\n";
	std::cout << "6. Exit program\n\n";
	std::cout << "Enter Choice: ";
	std::cin >> input;
	while (input < 1 or input > 6)
	{
		std::cout << "Enter a valid Choice from the menu: ";
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		std::cin >> input;
	}
	return input;
}
void clearScreen()
{
	system("CLS");
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
}
void pauseScreen()
{
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "\n---Enter to Continue!---\n";
	std::cin.get();
}
