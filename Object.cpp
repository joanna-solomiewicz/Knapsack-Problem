#include "Object.h"

#include <cstdlib>

Object::Object(int ordinal) {
	this->ordinal = ordinal;
	value = 1 + rand() % 10;
	weight = 1 + rand() % 10;
}

Object::Object(int ordinal, int value, int weight) {
	this->ordinal = ordinal;
	this->value = value;
	this->weight = weight;
}

bool Object::comp(const Object *object1, const Object *object2) {
	float ratio1 = (float)object1->value/object1->weight;
	float ratio2 = (float)object2->value/object2->weight;
	return (ratio1 < ratio2);
}
