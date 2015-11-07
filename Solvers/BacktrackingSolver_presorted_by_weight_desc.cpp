#include "BacktrackingSolver_presorted_by_weight_desc.h"

#include "../ProblemInstance.h"
#include "../Result.h"
#include <chrono>

#include <iostream>

using namespace std;


static Result result;
static int capacity;

Result *BacktrackingSolver_presorted_by_weight_desc::solveProblem(ProblemInstance *problemInstance) {
    capacity = problemInstance->capacity;
    Result tempResult;

    clock_t begin = clock();

    list<Object*> sortedList = problemInstance->objectsList;
    sortedList.sort(Object::comp_weight_decreasing); // test if better to sort or not

    list<Object*>::iterator i = sortedList.begin();

    takeNode(i,&sortedList,tempResult);
    dontTakeNode(i,&sortedList,tempResult);

    clock_t end = clock();
    result.elapsed_sec = double(end - begin) / CLOCKS_PER_SEC;

    return &result;
}

void BacktrackingSolver_presorted_by_weight_desc::takeNode(std::list<Object*>::iterator i, std::list<Object*>* list, Result tempResult){
    tempResult.add(*i);
    if (tempResult.weightSum <= capacity){
        i++;
        if(i == (*list).end()){
            if(tempResult.valueSum > result.valueSum) result = tempResult;
        }
        else{
            takeNode(i,list,tempResult);
            dontTakeNode(i,list,tempResult);
        }
    }
}

void BacktrackingSolver_presorted_by_weight_desc::dontTakeNode(std::list<Object*>::iterator i, std::list<Object*>* list, Result tempResult){
    i++;
    if(i == (*list).end()){
        if(tempResult.valueSum > result.valueSum) result = tempResult;
    }
    else{
        takeNode(i,list,tempResult);
        dontTakeNode(i,list,tempResult);
    }
}
