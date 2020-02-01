#include <iostream>
#include <fstream>
#include <string>

// reading a file
// this code is directly adapted from: http://www.cplusplus.com/doc/tutorial/files/
using namespace std;

int main() {
	string line;
	ifstream myfile("chris.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}
	else cout << "Cannot read file." << endl;
	
	return 0;
}