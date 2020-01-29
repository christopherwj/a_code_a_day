#include <iostream>
#include <string>

using namespace std;

int main() {
	string str = " Hello, my name is chris.";
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	cout << str.length() << endl;
	cout << str.empty() << endl;
	cout << str << endl;
	str.push_back('Y');
	cout << str << endl;
	str.pop_back();
	cout << str << endl;
	str.append("NO");
	cout << str << endl;
	str.resize(6);
	cout << str << endl;
}
