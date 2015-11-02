#include "Object.h"

#include <cstdio>
#include <cstdlib>
#include <ctime>

Object::Object(int ordinal) {
	srand(time(NULL));

	object entity;
	entity.ordinal = ordinal;
	entity.value = rand() % 101;
	entity.weight = rand() % 101;
}

Object::Object(int ordinal, int value, int weight) {
	srand(time(NULL));

	object entity;
	entity.ordinal = ordinal;
	entity.value = value;
	entity.weight = weight;
}
