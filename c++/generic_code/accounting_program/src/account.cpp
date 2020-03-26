#include "account.h"

//constructor
Account::Account()
{
	balance = 0;
	rate = .05;
}
//
Account::Account(double startingBalance)
{
	balance = startingBalance;
	rate = .05;	
}
//constructor
double Account::getBalance() //void no parameter = void parameter with return as double
{	
	return balance;
}
//function has a return type and is not a constructor

double Account::getRate() //void no parameter = void parameter with return as double
{
	return rate;
}

bool Account::deposit(double input){
	if (input < 0.00) {
		return false;
	}
	
	balance += input;
	return true;
}

bool Account::withdrawl(double input) {
	if (input < 0) {
		return false;
	}
	if (input > balance) {
		return false;
	}
	balance -= input;
	return true;
}

bool Account::accrueInterest(int input) {
	if (input < 0) {
		return false;
	}
	for (int i = 0; i < input; i++) {
		balance += ((balance * 0.05) / 12);
	}
	return true;
}	