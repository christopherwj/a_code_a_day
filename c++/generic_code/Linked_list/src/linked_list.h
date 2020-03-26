#pragma once
#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include "node.h"




class linked_list	//this class helps to build a linked list with the helper/supprting class node
{

private:

	Node* head = NULL; // used to keep track of the head (first node) of the linked list
	Node* tail = NULL;  //used for being able to tell the end of the list
	Node* temp = NULL;	//used as a walking stick to traverse the list
	int length = 0;

public:
	linked_list(void); //creates an empty LinkedList
	void insert(int x); // insert a node into the linked list
	bool Empty(); // return true if the LinkedList is empty, otherwise return false 
	void InsertAtEnd(int x); //insert a value x on the end of the LinkedList 
	void Delete(int x); //if value x is in the LinkedList, remove x 
	void Display(); //Display the data values in the LinkedList in the order inserted 
	int Sum(); // Compute and return the sum of the values in the LinkedList
	int Average(); // Compute and return the average of the values in the LinkedList 
	~linked_list(); // destructor to remove all elements from the LinkedList.
};
