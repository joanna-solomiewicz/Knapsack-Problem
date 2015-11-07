#include <iostream>
#include "ProblemInstance.h"
#include "Object.h"

using namespace std;

ProblemInstance::ProblemInstance() {
	capacity = 0;
	quantity = 0;
	objectsList.clear();
}

void ProblemInstance::print() {
	int objectsLeft = (int) objectsList.size();

	list<Object*>::iterator tmp = objectsList.begin();
	cout << endl;
	while(objectsLeft) {
		cout << (*tmp)->ordinal << "\t";
		cout << "Value: " << (*tmp)->value << "\t";
		cout << "Weight: " << (*tmp)->weight << "\t";
		cout << endl;
		tmp++;
		objectsLeft--;
	}
	cout << "Capacity: " << capacity << endl;
	cout << "Quantity: " << quantity << endl;
}
