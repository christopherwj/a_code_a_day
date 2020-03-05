#pragma once
class Account
{
private:
	double balance;
	double rate;

public:
	Account(); //void due to no data type before (default constructor)
	Account(double);//alternate constructor
	double getBalance(void); //function
	double getRate();	//function
	bool deposit(double);
	bool withdrawl(double);
	bool accrueInterest(int);
};