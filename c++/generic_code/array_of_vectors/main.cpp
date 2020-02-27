#include <iostream>
#include <vector>


using namespace std;

vector <int> V[11];
	
void insertArrayOfVectors()
{
	for (int i = 0; i < 12; i++) {
		for (int j = i + 1; j < 12; j++) {
			V[i].push_back(j);
		}
	}
}

int main() {

	insertArrayOfVectors();

	for (int k = 0; k < 12; k++) {
		cout << "Element at index:" << k << ": ";
		
		for (auto it = V[k].begin(); it != V[k].end(); it++) {
			cout << *it << ' ';
		}
		cout << endl;
	}

	return 0;
}


	 
	



