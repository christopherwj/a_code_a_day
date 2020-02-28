#include <iostream>

using namespace std;

//declaring forward declarations to initialize before calling
int menu();
void clearScreen();
void pauseScreen();
float add(float* x, float* y);
float sub(float* x, float* y);
float multiply(float* x, float* y);
float divide(float* x, float* y);

int main()
{
	int input = 0; //variable for switch cases
	
	float x;  //declarations for future pointers
	float y;
	float z;  // declaration to store result of math operation


	do
	{
		input = menu();
		switch (input)
		{
		case 1:
			cout << "Please enter in two numbers for calculations." << endl;
			cout << "Enter the first number now." << endl;	
			cin >> x; //take in number from user
			//data validation from user uses cin library to check if proper type is entered
			if (cin.fail()) { 
				cout << "Please enter an integer and try again." << endl; 
				//wrong data type breaks back to main menu to allow for a new correct value.
				pauseScreen(); //waits for user to hit enter so they can read the last output statement
				break;
				}
			cout << "Enter the second number now." << endl;
			cin >> y;	//take in number from user
			// data validation for second number, checks if float
			if (cin.fail()) { 
				cout << "Please enter an integer and try again." << endl;
				pauseScreen();
				break;
			}
			pauseScreen();
			break; //exits having gathered x and y
		case 2:
			z = add(&x, &y); // z gets the result of x and y being ref'ed as pointers
			cout << "The numbers are" << x << " and " << y << " and you choose to add them, the result is " << z << " ." << endl;
			pauseScreen(); // waits to allow user to see cout
			break;
		case 3:
			z = sub(&x, &y); // subtract function call for x and y
			cout << "The numbers are" << x << " and "<< y <<" and you choose to subtract them, the result is "<< z <<" ."<< endl;
			pauseScreen();
			break;
		case 4:
			z = multiply(&x, &y);  // multiply function call for x and y
			cout << "The numbers are" << x << " and " << y << " and you choose to multiply them, the result is " << z << " ." << endl;
			pauseScreen();
			break;
		case 5:
			if (y == 0) 
			{
				cout << "Cannot divide by 0, please enter in new numbers and try again." << endl;
				pauseScreen();
				break;
			}
			z = divide(&x, &y);// divide function call for x and y
			cout << "The numbers are " << x << " and " << y << " and you choose to divide them, the result is " << z << " ." << endl;
			pauseScreen();
			break;
		default:
			cout << "Goodbye";
			pauseScreen();
		}
		clearScreen();
	} while (input != 6);

}
int menu() // menu set up for user
{
	int input;
	cout << "Please first press one to input two numbers to do calculations with by pressing 1. Then choose what you would like to do with those two numbers." << endl;
	cout << "Please press 1 at any time to change the numbers you are calculating. If no new numbers are input the same operation will be applied to the original numbers entered." << endl;
	cout << "Please enter new numbers using 1 after you wish to try different calculations." << endl;
	cout << "1. Enter two numbers." << endl;
	cout << "2. Add the two numbers together." << endl;
	cout << "3. Subtract the first number from the second." << endl;
	cout << "4. Multiply the two numbers." << endl;
	cout << "5. Divide the first number by the second number." << endl;
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
void clearScreen() //clear screen function so that the screen can be refreshed with new info
{
	system("CLS");
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
}
void pauseScreen() //function waits for input to allow user time to read messages
{
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "\n---Enter to Continue!---\n";
	std::cin.get();
}


float add(float* x, float* y)  // add function pass by pointer
{
	float z;
	z = *x + *y;
	return z;
}

float sub(float* x, float* y)  // subtract function pass by pointer
{
	float z;
	z = *x - *y;
	return z;
}

float multiply(float* x, float* y)  // multiply function pass by pointer
{
	float z;
	z = *x * *y;
	return z;
}


float divide(float* x, float* y)  // divide function pass by pointer
{
	return (float)(*x) / (float)(*y);
}