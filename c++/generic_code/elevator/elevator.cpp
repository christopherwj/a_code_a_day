#include <iostream>
#define FLOORS 10

using namespace std;

struct elevator {
	int floorSelected;
	int floorNumber;
	int getFloor();
	void initialize();
	void selectFloor(int floor);
	void go();

};

int elevator::getFloor() {
	return floorNumber;
}

void elevator::initialize() {
	floorSelected = 0;
	floorNumber = 0;
}

void elevator::selectFloor(int floor) {
	if (floor < 0 || floor >= FLOORS)
		return;
	floorSelected = floor;

}

void elevator::go() {
	if (floorNumber < floorSelected)
		while (++floorNumber < floorSelected)
			cout << "floor:" << floorNumber << " going up!" << endl;
	else if (floorNumber > floorSelected)
		while (--floorNumber > floorSelected)
			cout << "floor: " << floorNumber << " going down!" << endl;
	cout << "floor:" << floorNumber << " stopping." << endl;

}

int main() {
	elevator arr[3];
	
	int floors[] = { 8, 3, 5 };

	for (int i = 0; i < 3; i++) {
		arr[i].initialize();
		arr[i].selectFloor(floors[i]);
		arr[i].go();
		cout << "Elevator " << i << " is at floor " << arr[i].getFloor() << "\n";
	}

	elevator *eptr = &arr[1];
	eptr->selectFloor(4);
	eptr->go();
}
