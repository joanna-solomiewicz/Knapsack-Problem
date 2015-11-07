#pragma once

#include <list>

class Object;

class ProblemInstance {
public:
	int capacity;
	int quantity;
	std::list<Object*> objectsList;

public:
	ProblemInstance();
	ProblemInstance(int capacity, int quantity);
	void print();
};
