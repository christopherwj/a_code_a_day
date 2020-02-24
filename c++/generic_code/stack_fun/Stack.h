#pragma once
#include <iostream>

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

