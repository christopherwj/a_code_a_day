#include <iostream>
#include <vector>

using namespace std;


int main() {
	vector<int> myVector;

	myVector.push_back(12); // resizes and add a component to end of vector
	myVector.push_back(19);
	myVector.push_back(3);
	myVector.push_back(12);
	myVector.push_back(55);

	cout << "vector:";

	myVector.insert(myVector.begin(), 5);
	myVector.insert(myVector.begin() + 2, 0);

	for (unsigned int i = 0; i < myVector.size(); i++) {  //tried doing this in earlier code, needed unsigned int!!!!
		cout << myVector[i] << " ";
	}

	// myVector.at(index) -- returns a value at a specified index
	// myVector.size()    -- returns an unsigned int of amount of elements
	// myVector.begin()   -- reads vector from first element (index 0)
	// myVector.insert(myVector.begin() + integer, new value) -- adds elements before specified number

	cout << endl << myVector.at(2);
	cout << endl << myVector.size();

	return 0;
}