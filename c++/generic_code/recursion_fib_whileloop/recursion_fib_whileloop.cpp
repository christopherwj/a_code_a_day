#include <iostream>

using namespace std;

int fib(int n) {
	while (n <= 1) {
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}

int main() {
	int a = 42;
	int b = 0;
	b = fib(a);
	cout << b;
	return 0;
}

//able to calculate up to 42nd term which sums to: 267914296, this process took 15.32 seconds to complete used 12% of my CPU with 3 threads. (windows resource monitor)
//from now on the 42nd term will be used to benchmark future code to learn more about writing efficient code.