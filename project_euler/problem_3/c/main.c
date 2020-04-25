#include <stdio.h>	
#include <math.h>
#include <stdbool.h>

//#define ll long long

bool IsPrime(unsigned int number) {
    if (number <= 1) return false; // zero and one are not prime
    unsigned int i;
    for (i=2; i*i<=number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

int main(void) {

	unsigned long int number = 600851475143;
	int i = 2;
	int largestPrime;
	
	while ( i < (sqrt(number) + 1)){
		if (IsPrime(i) == true && number % i == 0){
			printf("%d\n", i);
			largestPrime = i;
		}
		//printf("%d\n", i);
		i++;
	}
	printf("%d", largestPrime);

	return 0;
}