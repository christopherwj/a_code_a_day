#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream myfile("output.txt");
	if (myfile.is_open())
	{
		myfile << "This is an example of writing to a file." << endl;
		myfile << "This should be the second line of the file." << endl;
		myfile.close();
	}
	else cout << "File cannot be openned, please try again.";
	return 0;
}