#include "main.h"

int main(){
	int input;

	do{
		input = menu();
		int n;
		char *word;
		char *def;
		char **result;

		switch (input){
		case 1: /* add node */
			std::cout << "Please enter a word:\n";
			std::cin >> word;
			std::cout << "Please enter a definition:\n";
			std::cin >> def;
			n = myTree.addLeaf(word, def, myTree.getRoot());
			if (n == -1){
				std::cout << "Word already exists\n";
			} else {
				std::cout << "Word added\n";
			}
			pauseScreen();
			break;
		case 2: /* search node */
			std::cout << "Enter a word to search for:\n";
			std::cin >> word;
			result = myTree.findLeaf(word, myTree.getRoot());
			if (result == NULL){
				std::cout << "Word not found\n";
				pauseScreen();
				break;
			}
			std::cout << "The definition of " << result[0] << \
				" is:\n" << result[1] << "\n";
			pauseScreen();
			break;
		case 3: /* print all nodes */
			myTree.printInOrder(myTree.getRoot());
			pauseScreen();
			break;
		default:
			std::cout << "Goodbye";
			pauseScreen();
		}
		clearScreen();
	} while (input != 4);

}
int menu()
{
	int input;
	std::cout << "Enter the number for the operation you wish to perform from the menu.\n"
		"1. Add Word\n"
		"2. Find Word\n"
		"3. Dump all values\n"
		"4. Exit program\n\n"
		"Enter Choice: \n";
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
