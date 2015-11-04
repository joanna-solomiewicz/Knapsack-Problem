#pragma once

#include <list>
#include <chrono>
#include "Object.h"


class Result {
public:
    Result();
    void print();
    int valueSum;
    int weightSum;
    std::chrono::duration<double> elapsed_seconds;
    std::list<Object*> chosenObjectsList;
};
