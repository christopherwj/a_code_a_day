#include "contact.h"
/**
 * @brief      Constructs a new instance.
 */
Contact::Contact(){
	firstName = "";
	lastName = "";
	phoneNumber = 0;
	address = "";
}
/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  mfirstName  The first name
 */
Contact::Contact(std::string mfirstName){
	lastName = "";
	phoneNumber = 0;
	address = "";
	firstName = mfirstName;
}
/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  mfirstName  The first name
 * @param[in]  mlastName   The last name
 */
Contact::Contact(std::string mfirstName, std::string mlastName){
	phoneNumber = 0;
	address = "";
	firstName = mfirstName;
	lastName = mlastName;
}
/**
 * @brief      Constructs a new instance.
 * Creates a complete contact with all the info inside an object that is created.
 *
 * @param[in]  mfirstName    The mfirst name
 * @param[in]  mlastName     The mlast name
 * @param[in]  mphoneNumber  The mphone number
 * @param[in]  maddress      The maddress
 */
Contact::Contact(std::string mfirstName, std::string mlastName, int mphoneNumber, std::string maddress) {
	firstName = mfirstName;
	lastName = mlastName;
	phoneNumber = mphoneNumber;
	address = maddress;
}

