#pragma once
#include <iostream>

/*
* DISCLAIMER:This code is sourced from my data strcutures class as such I claim no ownership, credit, or
* merit that could be gained from this code all rights, privledges, and credit is credited to professor M. SARKAR.
*/

using namespace std;

#ifndef STACK
#define STACK

typedef int StackElement;

class Stack
{

public:
	Stack();
	Stack(const Stack& original);
	~Stack();
	const Stack& operator=(const Stack& rightHandSide);
	bool empty() const;
	void push(const StackElement& value);
	void display(ostream& out) const;
	StackElement top() const;
	void pop();
private:
	class Node
	{
	public:
		StackElement data;
		Node* next;
		Node(StackElement value, Node* link = 0) :
			data(value), next(link) {};
	};
	typedef Node* NodePointer;
	NodePointer myTop;
};

#endif // !LSTACK

