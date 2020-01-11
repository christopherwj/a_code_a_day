#include<iostream>

using namespace std;

int change;  //needs random declaration for testing.

/* 
an int is equal to one penny, 100 = 1 dollar
This is done so there aren't any casting or precision problems with 
changing from ints to floats.
*/
void countChange(int change) 
{
	int quarter, dime, nickel, penny;
	
	quarter = change / 25;
	change = change % 25;
	dime = change / 10; 
	change = change % 10;
	nickel = change / 5;
	change %= 5; 
	penny = change;
	cout << quarter << " " << dime << " " << nickel << " " << penny << "\n\n";
	printf("quarters: %d, dimes = %d, nickels: %d, penny: %d\n", quarter, dime, nickel, penny);

}



int main() 
{
	change = 76;
	countChange(change);

	return 0;
} 