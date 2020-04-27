#include <iostream>
#include <vector>


using namespace std;

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++){
		std::cout << input.at(i) << ' ';
	}
}


bool isPrime(unsigned int number) {
    if (number <= 1) return false; // zero and one are not prime
    unsigned int i;
    for (i=2; i*i<=number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}


int main(void){

	vector<int> primes;
	vector<int> prime_roots;

	//create a list of primes from 1 to 20
	for (int i = 1; i < 21; i++){
		if (isPrime(i) == true){
			primes.push_back(i);
		}
	}

	cout << endl;
	print(primes);

	for (int j = 0; j < primes.size(); j++){
		if (j * j > 20){
			prime_roots.push_back(j);
		}
		do {
			j *= j;
		} while (j < 20);
		prime_roots.push_back(j);
	}

	return 0;
}