#include <iostream>
#include "ProblemInstance.h"
#include "Object.h"

using namespace std;

ProblemInstance::ProblemInstance() {
	capacity = 0;
	quantity = 0;
	objectsList.clear();
}

ProblemInstance::ProblemInstance(int capacity, int quantity) {
	this->capacity = capacity;
	this->quantity = quantity;
	for(int i = 1; i <= quantity; i++) {
		Object* object = new Object(i);
		objectsList.push_back(object);
	}
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

