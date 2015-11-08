#include "BruteforceRecursiveSolver.h"

#include "../ProblemInstance.h"
#include "../Result.h"

using namespace std;

static Result result;
static int capacity;

Result *BruteforceRecursiveSolver::solveProblem(ProblemInstance *problemInstance) {
    result.clear();
    capacity = problemInstance->capacity;
    Result tempResult;

    clock_t begin = clock();

    list<Object*>::iterator i = problemInstance->objectsList.begin();
    takeNode(i,&problemInstance->objectsList,tempResult);
    dontTakeNode(i,&problemInstance->objectsList,tempResult);

    clock_t end = clock();
    result.elapsed_sec = double(end - begin) / CLOCKS_PER_SEC;

    return &result;
}

void BruteforceRecursiveSolver::takeNode(std::list<Object*>::iterator i, std::list<Object*>* list, Result tempResult){
    tempResult.add(*i);
    i++;
    if(i == (*list).end()){
        if (tempResult.weightSum <= capacity) {
            if (tempResult.valueSum > result.valueSum) result = tempResult;
        }
    }
    else{
        takeNode(i,list,tempResult);
        dontTakeNode(i,list,tempResult);
    }
}

void BruteforceRecursiveSolver::dontTakeNode(std::list<Object*>::iterator i, std::list<Object*>* list, Result tempResult){
    i++;
    if(i == (*list).end()){
        if (tempResult.weightSum <= capacity) {
            if (tempResult.valueSum > result.valueSum) result = tempResult;
        }
    }
    else{
        takeNode(i,list,tempResult);
        dontTakeNode(i,list,tempResult);
    }
}



