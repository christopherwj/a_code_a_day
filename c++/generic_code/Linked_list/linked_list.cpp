#include "linked_list.h"
#include "node.h"



using namespace std;	// I do this so I dont have to specifiy std:: for all my print statements

linked_list::linked_list()	//default constructor when linked list object "a" is created this function creates these attributes and assigns it.
{
	head = NULL;	//If our list is empty then we will not have a head node
	tail = NULL;	//If our list is empty then we will not have a tail node
	this->length = 0;	//initialize our list size to zero since it has no members
}

void linked_list::insert(int x)		//here is my insert function, it automatically inserts at end, it takes a data value as input
{
	Node* temp = new Node;		// call up the node class and create a node with two values, one being data, and one being the address of the next node (next pointer)
	temp->data = x;		// take the argument x and pass it into the temp node's data field.
	temp->next = NULL;	// set next pointer to null since it is by default the end of the list

	if (head == NULL) {	//conditioning for if there are no elements in the linked list
		head = temp;
		tail = temp;
	}
	else {				//condition for if there are elements in the linked list
		tail->next = temp;	
		tail = tail->next;
	}
	this->length++;		//everytime I insert a node increment that specific linked list's length variable
}

bool linked_list::Empty()	//checks if linked list is empty, if empty return true, else false. Print statements were for prototyping.
{
	if (this->length == 0) {
		//cout << "There are no members in the link list \n";
		return true;
	}
	//cout << "There are members in the list." << endl;
	return false;
}

void linked_list::InsertAtEnd(int x)	//lab specifies we need this, yet the menu doesn't show this as an option. It does the same as the insert function. Included just in case.
{
	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;

	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = tail->next;
	}
	this->length++;
}

void linked_list::Delete(int x)		// input a data type to look for and delete it
{
	if (this->Empty() == true) {	//first check there are elements to delete.
		cout << "Display: There are no members inside the list.\n";
		return;
	}

	Node* temp = new Node;		//create a "walking stick" node to help us navigate list
	temp = head;			// start temp node at beginng of list
	Node* input = new Node;		// generate a new node to compare. Could've also just used data value entered as identifier for node to delete instead of creating a node
	input->data = x;		// take data we want to delete and put it in a node to go through list and compare for the node we'd like to delete.
	
	if (temp->next->data != input->data) {		// cycle through list until we find the one we want to delete
		temp = temp->next;			//move walking stick along
	}
	
	if (temp->next->data == input->data) {		//stop our temp node one node before the one we wish to delete
		input->next = temp->next->next;		// breaking links around node we wish to delete
		temp->next = input->next;		// route around unwanted node
		this->length = this->length - 1;	// each time we do this take a 1 off of ou
		return;
	}
	else        //notify user operation failed.
	{
		cout << "The item doesn't exist in the list.";
		return;
	}
}

void linked_list::Display()	//create a function to go through and print each node in order of list implementation
{
	if (this->Empty() == true) {	//check to see if there is anything to display
		cout << "There are no members inside the list.\n";
		return;
	}
	Node* head = this->head;	//set head node equal to linked list's head value. Start from beginning.
	int i = 1;			// create a counter variable to increment
	cout << " ";
	while (head) {		//while head has something print it, increment it and repeat until there are no more nodes
		cout << head->data << "  ";
		head = head->next;
		i++;
	}
	cout << "\n";
}

int linked_list::Sum()	//sums all values in list
{	
	int sum = 0;	//create an int to return
	if (this->Empty() == true) {		//check if list has values
		cout << "Sum: There are no members inside the list.\n";
		return 0;
	}
	Node* head = this->head;	//start at beginning 
	int i = 1;
	while (head) {			//cycle through successively adding values
		sum += head->data;
		head = head->next;
		i++;
	}
	//cout << " The sum is: " << sum;
	return sum;			// return sum to be printed in main
}

int linked_list::Average()
{
	if (this->Empty() == true) {	//check if list has members
		cout << "Average : There are no members inside the list.\n";
		return 0;
	}
	int a = this->Sum();	//take result from sum and store if for use later
	int average = a / this->length;		// create a value to return that is the sum / number of nodes
	//cout << " The average is: " << average;
	return average;
}

linked_list::~linked_list()	//deconstructor 
{
}

