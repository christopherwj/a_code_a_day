#include <stdio.h>
#include <stdbool.h>

bool isPlalindrone (int value){ 

	int n, digit, rev = 0;

	n = value;

 do{
 	digit = value % 10;
 	rev =(rev * 10) + digit;
 	value = value / 10;
 } while (value != 0);

 if (n == rev){
 	return true; // is palindrone
 }
return false;

}

int main(void){

int temp = 0;

for (int i = 999; i > 800; i--){
	for(int j = 999; j > 800; j--){
		temp = (i * j);
		if (isPlalindrone(temp) == true){
			printf("%d", temp);
			return 0;
		}
	}
}


	return 0;
}
