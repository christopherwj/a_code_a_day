#include "account.h"

//constructor
Account::Account()
{
	balance = 0;
	rate = .05;
}
/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  startingBalance  The starting balance of the account.
 */
Account::Account(double startingBalance)
{
	balance = startingBalance;
	rate = .05;	
}
/**
 * @brief      Gets the balance.
 *
 * @return     The balance.
 */
double Account::getBalance() 
{	
	return balance;
}

/**
 * @brief      Gets the rate.
 *
 * @return     The rate.
 */
double Account::getRate() 
{
	return rate;
}
/**
 * @brief      deposits money into the account
 *
 * @param[in]  input  The input to deposit
 *
 * @return     true for success and false for failure
 */
bool Account::deposit(double input){
	if (input < 0.00) {
		return false;
	}
	
	balance += input;
	return true;
}
/**
 * @brief      Withdrawls money from account
 *
 * @param[in]  input  The amount to withdrawl
 *
 * @return     returns true for success and false for failure
 */
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
/**
 * @brief      accrues interest over time
 *
 * @param[in]  input  The time in months to accrue interest
 *
 * @return     true if interest can be accrued, false if not
 */
bool Account::accrueInterest(int input) {
	if (input < 0) {
		return false;
	}
	for (int i = 0; i < input; i++) {
		balance += ((balance * 0.05) / 12);
	}
	return true;
}	