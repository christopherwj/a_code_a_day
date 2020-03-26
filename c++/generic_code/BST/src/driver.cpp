#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;


#include <iostream>

	using namespace std;
	int menu();
	void clearScreen();
	void pauseScreen();
	//declaring forward declarations to initialize before calling
	int main()
	{
		int input = 0;
		BST myTree;
		do
		{
			input = menu();
			switch (input)
			{
			case 1:
				int temp;
				char node;
				
				cout << " Please enter the amount of nodes you wish to add.";
				cin >> temp;
				for (int i = 0; i < temp; i++) {
					cout << "Please enter the node you wish to add.";
					cin >> node;
					myTree.addLeaf(node);
				}
				pauseScreen();
				break;
			case 2:
				myTree.printPreOrder();
				pauseScreen();
				break;
			case 3:
				char tempnode;
				cout << "Please enter the char you wish to find.";
				cin >> tempnode;
				myTree.searchKey(tempnode);
				pauseScreen();
				break;
			case 4:
				char tempdelete;
				cout << "Enter item you want to delete:";
				cin >> tempdelete;
				myTree.removeNode(tempdelete);
				pauseScreen();
				break;
			case 5:
				int numberLeafs;
				int count;
				numberLeafs = myTree.count();
				cout << numberLeafs << endl;
				pauseScreen();
				break;
			case 6:		// sibling of a node
				char temp1;
				cout << "Enter the item and it will display the sibling of that item.";
				cin >> temp1;
				myTree.find(temp1);
				pauseScreen();
				break;
			case 7:		// quit
				cout << "Goodbye";
				pauseScreen();
			default:
				cout << "Goodbye";
				pauseScreen();
			}
			clearScreen();
		} while (input != 6);

	}
	int menu()
	{
		int input;
		cout << "-----------------MENU-----------------" << endl;
		cout << " Please enter the number for the operation you wish to perform from the menu." << endl;
		cout << "1. Insert node(s)" << endl;
		cout << "2. Traverse Preorder and print" << endl;
		cout << "3. Search BST" << endl;
		cout << "4. Delete node" << endl;
		cout << "5. Leaf Count" << endl;
		cout << "6. Sibling of a node " << endl;
		cout << "7. Quit " << endl;
		cout << "Not pressing a choice above will exit the program." << endl;

		cout << "Enter Choice: ";
		cin >> input;
		while (input < 1 or input > 7)
		{
			cout << "Enter a valid Choice from the menu: ";
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			cin >> input;
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