#pragma once

class Object {
public:
    int ordinal;
    int value;
    int weight;

public:
	Object(int ordinal);
	Object(int ordinal, int value, int weight);

    static bool comp_decreasing(const Object* object1, const Object* object2); // use like this: list<Object*>.sort(comp), created to enable sorting on pointers with list<Object*>.sort()
    static bool comp_increasing(const Object* object1, const Object* object2); // use like this: list<Object*>.sort(comp), created to enable sorting on pointers with list<Object*>.sort()
};

