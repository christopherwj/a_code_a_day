#include "contact.h"

Contact::Contact(){
	firstName = "";
	lastName = "";
	phoneNumber = 0;
	address = "";
}

Contact::Contact(std::string mfirstName){
	lastName = "";
	phoneNumber = 0;
	address = "";
	firstName = mfirstName;
}

Contact::Contact(std::string mfirstName, std::string mlastName){
	phoneNumber = 0;
	address = "";
	firstName = mfirstName;
	lastName = mlastName;
}

Contact::Contact(std::string mfirstName, std::string mlastName, int mphoneNumber, std::string maddress) {
	firstName = mfirstName;
	lastName = mlastName;
	phoneNumber = mphoneNumber;
	address = maddress;
}

//defining node to be used
