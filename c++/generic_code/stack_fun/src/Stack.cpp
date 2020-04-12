#include "stack.h"
#include <new>
#include <iostream>


/*
* DISCLAIMER: This code is sourced from my data strcutures class as such I claim no ownership, credit, or
* merit that could be gained from this code all rights, privledges, and credit is credited to professor M. SARKAR.
*/

using namespace std;

/**
 * @brief      Constructs a new instance.
 */
Stack::Stack() : myTop(0) {};

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  original  The value to add to the stack
 */
Stack::Stack(const Stack& original)
{
	myTop = 0;
	if (!original.empty()) {
		//copy first node
		myTop = new Stack::Node(original.top());
		//set pointers to run through the stacks linked lists
		Stack::NodePointer lastPtr = myTop, origPtr = original.myTop->next;

		while (origPtr != 0)
		{
			lastPtr->next = new Stack::Node(origPtr->data);
			lastPtr = lastPtr->next;
			origPtr = origPtr->next;
		}
	}
}

/**
 * @brief      Destroys the object.
 */
Stack::~Stack()
{
	//set pointers to run through the stack
	Stack::NodePointer currPtr = myTop, nextPtr;

	while (currPtr != 0)
	{
		nextPtr = currPtr->next;
		delete currPtr;
		currPtr = nextPtr;
	}
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  rightHandSide  The right hand side
 *
 * @return     The result of the assignment
 */
const Stack& Stack::operator=(const Stack& rightHandSide)
{
	if (this != &rightHandSide) //check if st = st
	{
		this -> ~Stack(); //destroy current linked list 
		if (rightHandSide.empty()) //empty stack
			myTop = 0;
		else   //copy rightHandSide's list
		{
			//copy the first node
			myTop = new Stack::Node(rightHandSide.top());
			//set pointers to run through the stacks' linked list
			Stack::NodePointer lastPtr = myTop, rhsPtr = rightHandSide.myTop->next;
			while (rhsPtr != 0)
			{
				lastPtr->next = new Stack::Node(rhsPtr->data);
				lastPtr = lastPtr->next;
				rhsPtr = rhsPtr->next;
			}
		}
	}
	return *this;
}


/**
 * @brief      Check to see if the stack is empty
 *
 * @return     true if empty, false if it contains elements 
 */
bool Stack::empty() const
{
	return (myTop == 0);
}

/**
 * @brief      Push an object onto the stack
 *
 * @param[in]  value  The value to add to the stack
 */
void Stack::push(const StackElement& value)
{
	myTop = new Stack::Node(value, myTop);
}


/**
 * @brief      Displays the stack
 *
 * @param      out   stdio object to chain to cout
 */
void Stack::display(ostream& out) const
{
	Stack::NodePointer ptr;
	for (ptr = myTop; ptr != 0; ptr = ptr->next)
		cout << ptr->data << endl;
}

/**
 * @brief      returns the top element of the stack
 *
 * @return     The stack element at top
 */
StackElement Stack::top() const
{
	if (!empty())
		return (myTop->data);
	else
	{
		cerr << "*** Stack is empty"
			"---returning garbage ***";
		StackElement* temp = new(StackElement);
		StackElement garbage = *temp;
		delete temp;
		return garbage;
	}

}

/**
 * @brief      Pops the object off the stack.
 * Removes the object on the top of the stack.
 */
void Stack::pop()
{
	if (!empty()) //check to make sure stack has elements
	{
		Stack::NodePointer ptr = myTop;
		myTop = myTop->next;
		delete ptr;
	}
	else
		cerr << "*** Stack is empty  -- can't remove a value.";
}

