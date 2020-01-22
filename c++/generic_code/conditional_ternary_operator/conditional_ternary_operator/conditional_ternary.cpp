#include <iostream>	

using namespace std;


int main() {
	int i = 3, j = 4, k = 5;
	int largest, middle, smallest;

	smallest = i < j < k ? i : j;
	middle = i < j < k ? j : NULL;
	largest = i < j < k ? k : j;
	

	cout << "The smallest is:" << smallest << endl;
	cout << "The middle value is:" << middle << endl;
	cout << "The largest value is:" << largest << endl;
	return 0;
}



/*
Example of a ternerary operator:

variable = expression_1 ? expression_2 : expression_3;

is equivalent to:

if  (expression_1) {
variable = expression_2
}
else 
{
variable = expression_3;
}

*/