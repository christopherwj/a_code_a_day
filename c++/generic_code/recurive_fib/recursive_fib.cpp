#include <iostream>

using namespace std;

//this algorithm is terrribly inefficient for terms 20+, review Big O notation and find a better method with less recursive calls for tomorrow


int fibonacci(int n) {
	if (n <= 1) {
		return n;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);

}


int main() {
	int a = 0;
	int b = 0;
	cout << "Please give me a reasonable term to calculate fib to:";
	cin >> a;
	b = fibonacci(a);
	cout << b;
	return 0;
}