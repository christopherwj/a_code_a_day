#include <string>
#include <iostream>
#include "Employee.cpp"


using namespace std;




int main(void) {
	int input;
	int choice;


	do {

		cout << "Enter the number for th eoperation you wish to perform from the menu." << endl;
		cout << "1. Please press one to run employee wages with restaurant profit of $6000 and waiter wages of $1000/$1500/$1700 respectively." << endl;
		cout << "2. Please press two to run employee wages with restaurant profit of -$6000 and waiter wages of $1000/$1000/$1000 respectively." << endl;
		cout << "3. Please press 3 to enter in custom values for restaurant profit and waiter wages." << endl;
		cout << "4. The size of Owner class is:" << sizeof(Owner) << endl;
		cout << "5. The size of Chef class is:" << sizeof(Chef) << endl;
		cout << "6. The size of Waiter class is:" << sizeof(Waiter) << endl;
		cout << "6. The size of Employee class is:" << sizeof(Employee) << endl;
		cout << "Not pressing a choice above will exit the program." << endl;

		cout << "Enter Choice: ";
		cin >> input;

		if (input == 1) {					//case for specific values that are asked for
			Owner O = Owner("Bob", 1, 6000);
			O.print();

			Chef C1 = Chef("Eric", 12, "Italian", 6000);
			Chef C2 = Chef("Sheila", 16, "French", 6000);
			C1.print();
			C2.print();

			Waiter W1 = Waiter("Danny", 19, 1000, 2);
			Waiter W2 = Waiter("Rebecca", 20, 1500, 3);
			Waiter W3 = Waiter("Tom", 24, 1700, 4);
			W1.print();
			W2.print();
			W3.print();
			cout << "Please press one to return to the menu." << endl;
			cin >> choice;
			if (choice == 1)
				exit;
			system("CLS");
		}
		else if (input == 2) {					//case for negative values and different tip values for waiters
			Owner O = Owner("Bob", 1, -6000);
			O.print();

			Chef C1 = Chef("Eric", 12, "Italian", -6000);
			Chef C2 = Chef("Sheila", 16, "French", -6000);
			C1.print();
			C2.print();

			Waiter W1 = Waiter("Danny", 19, 1000, 2);
			Waiter W2 = Waiter("Rebecca", 20, 1000, 3);
			Waiter W3 = Waiter("Tom", 24, 1000, 4);
			W1.print();
			W2.print();
			W3.print();
			cout << "Please press one to return to the menu." << endl;
			cin >> choice;
			if (choice == 1)
				exit;
			system("CLS");
		}
		else if (input == 3) {						//case where certain values can be entered for each waiter's tip value as per the prompt
			int restaurantIncome;
			int waiterWage1;
			int waiterWage2;
			int waiterWage3;
			cout << "Please enter a number in for the total monthly profit of the restaurant." << endl;
			cin >> restaurantIncome;
			cout << "Please enter a number in for the tips of waiter Danny." << endl;
			cin >> waiterWage1;
			cout << "Please enter a number in for the tips of waiter Rebecca." << endl;
			cin >> waiterWage2;
			cout << "Please enter a number in for the tips of waiter Tom." << endl;
			cin >> waiterWage3;

			Owner O = Owner("Bob", 1, restaurantIncome);
			O.print();

			Chef C1 = Chef("Eric", 12, "Italian", restaurantIncome);
			Chef C2 = Chef("Sheila", 16, "French", restaurantIncome);
			C1.print();
			C2.print();

			Waiter W1 = Waiter("Danny", 19, waiterWage1, 2);
			Waiter W2 = Waiter("Rebecca", 20, waiterWage2, 3);
			Waiter W3 = Waiter("Tom", 24, waiterWage3, 4);
			W1.print();
			W2.print();
			W3.print();

			cout << "Please press 1 to return back to main menu and reset selected values." << endl;
			cin >> choice;
			if (choice == 1)
				exit;
			system("CLS");
		}
		else if (input > 3 or input < 1) {
			cout << "Goodbye";
			break;
		}
	} while (input > 1 or input < 3);

	return 0;
}
