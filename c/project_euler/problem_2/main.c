#include <stdio.h>

/*
*	Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
*	1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
*	By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

int fibonacci(int n) {
	if (n <= 1){
		return n;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}


int main(void){
	
	int i = 1;
	int temp = 0; 
	int total = 0;
	do
	{
		temp = fibonacci(i);
		printf("term fib sequence is at:%d\n", fibonacci(i));
		printf("value of temp:%d\n", temp);
		printf("value of total:%d\n", total);
		printf("---------------------------------\n");	
		if (((temp % 2) == 0)){
			total += temp;
		}

		i++;
	}while (temp<=4000000);

	return 0;
}

//4,613,732