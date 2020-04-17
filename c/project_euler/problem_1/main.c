#include <stdio.h>

//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
//The sum of these multiples is 23.

//Find the sum of all the multiples of 3 or 5 below 1000.

/*
 *this could be more cleanly written where the function check() doesn't exist, but 
 * rather it's contents are inside the forloop. 
 * 
 *
 */
int check(int n){

	if (((n % 3) == 0) || ((n % 5) == 0)){
		return n;
	}
	return 0;
}


int main(void){
	int total;

	for(int i=1; i < 1000; i++){
		//printf("%d, ", check(i));
		total += check(i);
	}


	printf("%d\n", total);

	return 0;
}