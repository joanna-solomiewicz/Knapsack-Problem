#include "BruteforceSolver.h"

#include "../ProblemInstance.h"
#include "../Result.h"

using namespace std;

static Result result;
static int capacity;

Result *BruteforceSolver::solveProblem_recursively(ProblemInstance *problemInstance) {
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

void BruteforceSolver::takeNode(std::list<Object*>::iterator i, std::list<Object*>* list, Result tempResult){
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

void BruteforceSolver::dontTakeNode(std::list<Object*>::iterator i, std::list<Object*>* list, Result tempResult){
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


Result* BruteforceSolver::solveProblem_iteratively(ProblemInstance *problemInstance) {

    int *Table = new int[problemInstance->quantity];
    int best_p_sum = 0;
    for (int j = 0; j < problemInstance->quantity; j++) { Table[j] = 0; }

    clock_t begin = clock();

    while( binaryIncrement(Table, problemInstance->quantity)) {
        Result pickedObjects;
        for (auto &i : problemInstance->objectsList){
            if(Table[i->ordinal - 1] == 1){
                pickedObjects.add(i);
                if(pickedObjects.weightSum > problemInstance->capacity) break;
            }
        }
        if(pickedObjects.weightSum > problemInstance->capacity) continue;

        if(pickedObjects.valueSum > best_p_sum){
            best_p_sum = pickedObjects.valueSum;
            result = pickedObjects;
        }
    }

    clock_t end = clock();
    result.elapsed_sec = double(end - begin) / CLOCKS_PER_SEC;

    delete[] Table;

    return &result;
}

bool BruteforceSolver::binaryIncrement(int T[], int size) {
    T[size - 1]++;
    for (int i = size - 1; i > 0; i--) {
        if (T[i] == 2) {T[i]=0; T[i - 1]++;}
        else break;
    }
    if (T[0] == 2) return 0;
    return 1;
}

