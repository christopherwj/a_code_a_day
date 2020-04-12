#include <iostream>
#include "Stack.h"
#include <cstdio>
using namespace std;
/**
 * @brief      Main function is rain here for stack
 *
 * @return 	   returns a zero upon completion of given code
 */
int main(void) {
	Stack s;
	s.push(54);
	s.push(650);
	s.push(-34);
	s.push('a');
	s.push('15');
	s.push('A');
	s.push('a');
	s.push(000);

	cout << "\n\n\n\ "; 
	cout << "The current stack is:" << endl;
	s.display(cout);
	cout << endl;
	cout << "The top element is:" << s.top() << endl;
	s.pop();
	cout << endl;
	cout << "The current top element has been popped, the stack is now:" << endl;
	s.display(cout);
	return 0;
}

/* possibly use typedef to allow for char to store more than one character in stack
* stacks are LIFO, thus first entered are last to print
* Coding project idea: use a stack and recursive algorithmn as a means to store movements for solving a maze, pop when solved.
*	will help to demonstrate O(n) efficiency through maze solve times. 
* On another day make destructor recursive?
* destructors should never be explicitly called use 'delete' for freeing or deleting a c++ obj
*once main returns a 0 the object s of class Stack will be deallocated through the destructor
*/