#pragma once

#include <list>
#include "Object.h"


class Result {
public:
    Result();
    void print();
    int valueSum;
    int weightSum;
    double elapsed_seconds;
    std::list<Object*> chosenObjectsList;
};
