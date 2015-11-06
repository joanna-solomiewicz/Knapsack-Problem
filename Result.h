#pragma once

#include <list>
#include <ctime>
#include "Object.h"


class Result {
public:
    Result();
    void add(Object *object);
    void remove(Object *object);
    void print();
    bool isEqual(Result* result2);

    int valueSum;
    int weightSum;
    double elapsed_sec;
    std::list<Object*> chosenObjectsList;

};
