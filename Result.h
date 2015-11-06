#pragma once

#include <list>
#include <ctime>
#include "Object.h"


class Result {
public:
    Result();
    void print();
    int valueSum;
    int weightSum;
    double elapsed_sec;
    std::list<Object*> chosenObjectsList;
};
