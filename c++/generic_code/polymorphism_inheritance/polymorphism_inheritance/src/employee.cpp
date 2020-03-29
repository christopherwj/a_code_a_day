#include<string>
#include <iostream>


using namespace std;


//base class
class Employee {
	//create a base or parent class to later use in my other classes
public:
	string name;  
	int employeeID = 0;                 
	string employeeType;		
	int baseSalary = 0;	                                                                                                              double salary = 0;		
	int restaurantProfit = 0;

	void virtual print() {
		printf("name	 employeeID     employee-type	 base-salary	 Salary	    Cuisine	 Tips-earned	 years-worked   \n");
	}	// use this to show that virtual is needed for the compiler to choose the object's print()
private:

};




//derived class 
class Owner : public Employee {			
public:
	Owner() {
		baseSalary = 15000;		
		employeeType = "Owner";		
	}

	Owner(string n, int id, int profit) {    
		name = n;			 
		employeeID = id;
		baseSalary = 15000;
		employeeType = "Owner";
		restaurantProfit = profit;
	}


	void print() {
		salary = baseSalary + (0.6 * restaurantProfit);  // salary calculation for all objects from Owner class
		cout << "name:" << name << "	employeeID:" << employeeID << "	employee-type:" << employeeType << "	base-salary:" << baseSalary << "	Salary:" << salary << "	restuarant-total-profit:" << restaurantProfit << "    Cuisine: N/A" << "	Tips-earned:N/A" << "      years-worked:N/A" << endl;
	} 

private:

};



class Chef : public Employee {			//child class Chef inherits access to all of Employees public members
public:						

	string cuisine;

	Chef() {
		baseSalary = 10000;
		employeeType = "Chef";
	}

	Chef(string nameOfEmployee, int id, string food, int profit) {
		name = nameOfEmployee;
		employeeID = id;
		employeeType = "Chef";
		cuisine = food;
		baseSalary = 10000;
		restaurantProfit = profit;


	}


	void print() {
		salary = baseSalary + 0.2 * restaurantProfit;		
		cout << "name:" << name << "	employeeID:" << employeeID << "	employee-type:" << employeeType << "	base-salary:" << baseSalary << "	Salary:" << salary << "	restaurant-total-profit:" << restaurantProfit << "	Cuisine:" << cuisine << "	Tips-earned:N/A" << "      years-worked:N/A" << endl;
	}
private:

};


class Waiter : public Employee {
public:

	int tips;				
	int experience;				

	Waiter() {
		baseSalary = 3000;
		employeeType = "Waiter";        
	}

	Waiter(string nameOfEmployee, int id, int monthlyTips, int yearsWorked) {
		name = nameOfEmployee;
		employeeID = id;
		employeeType = "Waiter";
		tips = monthlyTips;
		baseSalary = 3000;
		experience = yearsWorked;
		salary = baseSalary + tips;

	}

	void print() {
		salary = baseSalary + tips;    
		cout << "name:" << name << "	employeeID:" << employeeID << "	employee-type:" << employeeType << "	base-salary:" << baseSalary << "	Salary:" << salary << "	Cuisine: N/A" << "	Tips-earned:" << tips << "      years-worked:" << experience << endl;
		
	}

private:

};
