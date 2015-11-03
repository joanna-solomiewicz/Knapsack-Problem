#pragma once

#include <list>

class Object;

class ProblemInstance {
public:
	ProblemInstance();

	int capacity;
	int quantity;
	std::list<Object*> objectsList;
};
