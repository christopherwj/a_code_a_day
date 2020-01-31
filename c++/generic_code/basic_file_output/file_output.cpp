#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream fileOne("output_one.txt");
	ofstream fileTwo("output_two.txt");
	if (fileOne.is_open())
	{
		fileOne << "This is an example of writing to a file." << endl;
		fileOne << "This should be the second line of the file." << endl;
	}
	else cout << "File cannot be openned, please try again.";
	
	fileOne.swap(fileTwo); // this switches "swap" ostream output to other file
			       // Here I pass things to file two and they write to file one
	fileTwo << "This originated in file two." << endl;

	fileOne.close();
	fileTwo.close();
	return 0;
}