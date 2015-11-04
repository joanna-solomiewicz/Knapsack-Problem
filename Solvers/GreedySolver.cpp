#include "GreedySolver.h"

#include "../ProblemInstance.h"
#include "../Result.h"
#include <chrono>

using namespace std;

Result *GreedySolver::solveProblem(ProblemInstance *problemInstance) {
    Result *result = new Result();

    chrono::time_point<chrono::system_clock> start, stop;

    start = chrono::system_clock::now();

    list<Object*> pickedObjects = problemInstance->objectsList;
    int capacity = problemInstance->capacity;

    pickedObjects.sort(Object::comp_decreasing);
    for(auto &i : pickedObjects) {
        if(i->weight <= capacity) {
            result->chosenObjectsList.push_back(i);
            result->valueSum += i->value;
            result->weightSum += i->weight;
            capacity -= i->weight;
        }
    }

    stop = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = stop-start;

    pickedObjects.clear();

    return result;
}
