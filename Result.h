#pragma once

#include <list>
#include <ctime>
#include "Object.h"


class Result {
public:
    int valueSum;
    int weightSum;
    double elapsed_sec;
    std::list<Object*> chosenObjectsList;

public:
    Result();
    void add(Object *object);
    void remove(Object *object);
    void clear();
    void print();
};
