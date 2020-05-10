#include "account.h"
#include <iostream>

using namespace std;
int menu();
void clearScreen();
void pauseScreen();
//declaring forward declarations to initialize before calling
int main()
{
	int input = 0;
	Account acct(100.00); //create instance of account
	do
	{
		input = menu();
		switch (input)
		{
		case 1:
			cout << acct.getBalance();
			pauseScreen();
			break;
		case 2: 
			cout << acct.getRate();
			pauseScreen();
			break;
		case 3: 
			cout << "Please enter the number you wish to deposit.\n";
			double deposit;
			cin >> deposit;
			if (acct.deposit(deposit) == false) {
				cout<<"negative number is bad\n";
			}
			pauseScreen();
			break;
		case 4: 
			cout << "Please enter the number you wish to withdrawl.\n";
			double withdrawl;
			cin >> withdrawl;
			if (acct.withdrawl(withdrawl) == false) {
				cout << "You cannot do that\n";
			}
			pauseScreen();
			break;
		case 5: 
			cout << "Please enter the months that to accrue interest\n";
			int accrue;
			cin >> accrue;
			if (acct.accrueInterest(accrue)== false){
				cout << "You cannot do that, please try again.\n";
			}
			pauseScreen();
			break;
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
	cout << "Enter a number to perform an action from the menu." << endl;
	cout << "1. Check Balance" << endl;
	cout << "2. Check Current Rate" << endl;
	cout << "3. Deposit to Account" << endl;
	cout << "4. Withdraw from Account" << endl;
	cout << "5. Accrue Interest" << endl;
	cout << "6. Exit program" << endl << endl;
	cout << "Enter Choice: ";
	cin >> input;
	while (input < 1 or input > 6)
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