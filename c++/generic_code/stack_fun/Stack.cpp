#include "stack.h"
#include <new>
#include <iostream>

using namespace std;

//define the default constructor for Stack
Stack::Stack() : myTop(0) {};

//define stack copy constructor
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

//definition for Stack Destructor

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

//definition for assignment operator
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

//defintion of empty()

bool Stack::empty() const
{
	return (myTop == 0);
}

//defintion of push or insert for LL
void Stack::push(const StackElement& value)
{
	myTop = new Stack::Node(value, myTop);
}

//defintion of display 

void Stack::display(ostream& out) const
{
	Stack::NodePointer ptr;
	for (ptr = myTop; ptr != 0; ptr = ptr->next)
		cout << ptr->data << endl;
}

//definition for top()
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

//definition of pop()
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
