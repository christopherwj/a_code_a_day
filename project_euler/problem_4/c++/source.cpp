#include <iostream>
#include <vector>

using namespace std;

bool isPlalindrone (int value){ //true is palindrone, false is NOT palindrone

	int n, digit, rev = 0;

	n = value;

 do{
 	digit = value % 10;
 	rev =(rev * 10) + digit;
 	value = value / 10;
 } while (value != 0);

 if (n == rev){
 	return true;
 }
return false;

}



int main(void){

int temp = 0;

for (int i = 999; i > 800; i--){
	for(int j = 999; j > 800; j--){
		temp = (i * j);
		if (isPlalindrone(temp) == true){
			cout << "\n" << temp << endl;;
			return 0;
		}
	}
}


	return 0;
}