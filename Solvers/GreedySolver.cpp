#include "GreedySolver.h"

#include "../ProblemInstance.h"
#include "../Result.h"

using namespace std;

Result *GreedySolver::solveProblem(ProblemInstance *problemInstance) {
    Result *result = new Result();

    clock_t begin = clock();

    list<Object*> sortedList = problemInstance->objectsList;
    int remainingCapacity = problemInstance->capacity;

    sortedList.sort(Object::comp_decreasing);
    for(auto &i : sortedList) {
        if(i->weight <= remainingCapacity) {
            result->add(i);
            remainingCapacity -= i->weight;
            if(remainingCapacity == 0) break;
        }
    }

    clock_t end = clock();
    result->elapsed_sec = double(end - begin) / CLOCKS_PER_SEC;

    sortedList.clear();

    return result;
}
