#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 
 */



bool isPrime(unsigned int number) {
    if (number <= 1) return false; // zero and one are not prime
    unsigned int i;
    for (i=2; i*i<=number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}



int main(void) {

int N; //  number we want to find the largest evenly divisible by
int k = 20;  //end of range for numbers that go into finding largest number N

int primes[9];
int pos = 10;


for (int i = 0; i < k; i++){
	for ( int j = 1; j < pos; j++){
		if (isPrime(i) == true){
			primes[j] = i;
			j++;
		}
	}
i++;
}

for (int a = 0; a < pos; a++) 
        printf("%d ", primes[a]); 
    printf("\n"); 

	return 0;
}