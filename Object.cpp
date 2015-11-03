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
