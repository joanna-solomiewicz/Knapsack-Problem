#pragma once

#include <list>

class Object;

class ProblemInstance {
public:
	ProblemInstance();

	int capacity;
	int number;
	std::list<Object*> objectList;
};
