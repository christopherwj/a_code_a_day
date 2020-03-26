#include "main.h"

int main() {

	int inputMenu = 0; //create menu var
	linked_list a;	//create instance of object to use in menu
	do
	{
		inputMenu = menu();	//take results from menu function options and act on them in switch cases.
		switch (inputMenu)
		{
		case 1: //insert a value into the linked list
			int value;
			int numberToAdd;
			cout << " How many values would you like to add?\n";
			cin >> value;
			for (int i = 0; i < value; i++) {	//for loop for repetitious insertion
				cout << " Please enter a number to add to linked list.\n";
					cin >> numberToAdd;
					a.insert(numberToAdd);
				}
			cout << "Please press enter to return back to main menu.";
			pauseScreen();
			break;

		case 2:  // delete a value from the linked list.
			int numberToDelete;	//create temp var to work with delete function
			a.Display();		//first display to usr what can be deleted
			cout << endl;
			if (a.Empty() == true) {	//make sure there are members to delete, if not break out 
				pauseScreen();
				break;
			}
			cout << "Please enter which number you would like to remove from the list above.\n";
			cin >> numberToDelete;
			a.Delete(numberToDelete);
			cout << "Please press enter to return back to main menu.";
			pauseScreen();
			break;

		case 3: //display all values in the linked list
			a.Display();	//display function already checks to see if values are present
			cout << "Please press enter to return back to main menu.";
			pauseScreen();
			break;

		case 4: // sum all values of the linked list
			int sumToDisplay;
			a.Display();	// show all the values to be summed
			if (a.Empty() == true) {	//if empty leave option
				pauseScreen();
				break;
			}
			cout << "The sum of the items in the list are:\n";
			sumToDisplay = a.Sum();
			cout << sumToDisplay << endl;
			cout << "\n";
			cout << "Please press enter to return back to main menu.";
			pauseScreen();
			break;

		case 5: // average the values in linked list
			int average;
			a.Display(); //show all values to be averaged
			if (a.Empty() == true) {	// if there are no options leave
				pauseScreen();
				break;
			}
			cout << " The average of the values in the list is:";
			average = a.Average();	//store value to return in next line
			cout << average << endl;
			cout << "Please press enter to return back to main menu.";
			pauseScreen();
			break;

		case 6:		//quit
			cout << "Goodbye.";
			pauseScreen();
			return 0;

		default:
			cout << "Goodbye";
			pauseScreen();
		}
		clearScreen();
	} while (inputMenu != 6);

}
int menu()	//menu function used in conjunction with switch case
{
	int inputMenu;			
	printf("Please Press an option to perform that action. \n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Display\n");
	printf("4. Sum\n");
	printf("5. Average\n");
	printf("6. Exit\n");
	printf("Option 1: Insert a new value on the end of the LinkedList.\n");
	printf("Option 2: Delete a number specified by the user from the LinkedList, if the number is in the LinkedList.\n");
	printf("Option 3: Displayed in the LinkedList of numbers.\n");
	printf("Option 4: Compute and return the sum of the values in the LinkedList. If the LinkedList is empty return \n");
	printf("Option 5: Compute and return the average of the values in the LinkedList. If the LinkedList is empty return.\n");
	printf("Option 6: Leaves the Program\n");

	cout << "Enter Choice: ";
	cin >> inputMenu;
	while (inputMenu < 1 or inputMenu > 6)
	{
		cout << "Enter a valid Choice from the menu: ";
		if (std::cin.fail())	//condition for clearing screen so user can enter in a correct value
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		cin >> inputMenu;
	}
	return inputMenu;	//return a value for the switch case
}
void clearScreen()	//clear screen call 
{
	system("CLS");
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
}
void pauseScreen()	//keep things around long enough for user to read results
{
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "\n---Enter to Continue!---\n";
	std::cin.get();
}


