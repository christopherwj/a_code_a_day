#include<string>
#include <iostream>


using namespace std;


//base class
class Employee {
	//create a base or parent class to later use in my other classes
public:
	string name; //these are all variables that everyone downstream from 
	int employeeID = 0;             // declared for everychild class    
	string employeeType;		// used for print out dipslay
	int baseSalary = 0;		// used for print out dipslay
	double salary = 0;		// declared for all subsequent classes
	int restaurantProfit = 0;	// decalred for Owner and Chefs

	void virtual print() {
		printf("name	 employeeID     employee-type	 base-salary	 Salary	    Cuisine	 Tips-earned	 years-worked   \n");
	}	// use this to show that virtual is needed for the compiler to choose the object's print()
private:

};




//derived class 
class Owner : public Employee {			//child class Owner inherits access to all of Employees public members
public:
	Owner() {
		baseSalary = 15000;		//hard-coded due to true for all instances of any object created of type Owner
		employeeType = "Owner";		//hard-coded due to true for all instances of any object created of type Owner
	}

	Owner(string n, int id, int profit) {    //explicit value constructor for the objects I wish to create
		name = n;			 // takes in values to create an object, these values are combined with those from Employee
		employeeID = id;
		baseSalary = 15000;
		employeeType = "Owner";
		restaurantProfit = profit;
	}


	void print() {
		salary = baseSalary + (0.6 * restaurantProfit);  // salary calculation for all objects from Owner class
		cout << "name:" << name << "	employeeID:" << employeeID << "	employee-type:" << employeeType << "	base-salary:" << baseSalary << "	Salary:" << salary << "	restuarant-total-profit:" << restaurantProfit << "    Cuisine: N/A" << "	Tips-earned:N/A" << "      years-worked:N/A" << endl;
	}//TODO: make a function that shows name, id, employeetype, base salary and salary, and cuisine 

private:

};



class Chef : public Employee {			//child class Chef inherits access to all of Employees public members
public:						//comments from above Owner class apply below, they are also related child and parent classes

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
		salary = baseSalary + 0.2 * restaurantProfit;		// salary compensation calculation for all objects from Chef class
		cout << "name:" << name << "	employeeID:" << employeeID << "	employee-type:" << employeeType << "	base-salary:" << baseSalary << "	Salary:" << salary << "	restaurant-total-profit:" << restaurantProfit << "	Cuisine:" << cuisine << "	Tips-earned:N/A" << "      years-worked:N/A" << endl;
	}
private:

};


class Waiter : public Employee {
public:

	int tips;				//create values that only relate to class and thus objects waiter to be used with scoped operations
	int experience;				//create values that only relate to class and thus objects waiter to be used with scoped operations

	Waiter() {
		baseSalary = 3000;
		employeeType = "Waiter";        // hardcoded due to true for all instances
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
		salary = baseSalary + tips;    // salary calcualtion for all objects waiter
		cout << "name:" << name << "	employeeID:" << employeeID << "	employee-type:" << employeeType << "	base-salary:" << baseSalary << "	Salary:" << salary << "	Cuisine: N/A" << "	Tips-earned:" << tips << "      years-worked:" << experience << endl;
		//TODO: make a function that shows name, id, employeetype, base salary and salary, and tips
	}

private:

};