#include "GreedySolver.h"

#include "../ProblemInstance.h"
#include "../Result.h"

using namespace std;

Result *GreedySolver::solveProblem(ProblemInstance *problemInstance) {
    Result *result = new Result();

    clock_t begin = clock();

    list<Object*> pickedObjects = problemInstance->objectsList;
    int remainingCapacity = problemInstance->capacity;

    pickedObjects.sort(Object::comp_decreasing);
    for(auto &i : pickedObjects) {
        if(i->weight <= remainingCapacity) {
            result->add(i);
            remainingCapacity -= i->weight;
            if(remainingCapacity == 0) break; // SPRAWDZIĆ !!
        }
    }

    clock_t end = clock();
    result->elapsed_sec = double(end - begin) / CLOCKS_PER_SEC;

    pickedObjects.clear();

    return result;
}
