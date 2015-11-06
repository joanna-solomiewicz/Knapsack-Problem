#include "BranchAndBoundSolver.h"

#include "../ProblemInstance.h"
#include "../Result.h"
#include <chrono>

using namespace std;

static Result result;
static int capacity;

int getBound(Result* currResult, std::list<Object*>*list, std::list<Object*>::iterator k){
    int b,c;
    b = currResult->valueSum;
    c = currResult->weightSum;
    std::list<Object*>::iterator i;
    for (i=k; i != (*list).end(); i++){
        c+=(*i)->weight;
        if (c < capacity) b+=(*i)->value;
        else return (b + (1 - (c-capacity)/(*i)->weight/(*i)->value));
    }
    return b;
}

void BranchAndBoundSolver::takeNode(std::list<Object*>::iterator i, std::list<Object*>* list, Result tempResult){
    tempResult.add(*i);
    if (tempResult.weightSum <= capacity && getBound(&tempResult,list,i) > result.valueSum ){
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

void BranchAndBoundSolver::dontTakeNode(std::list<Object*>::iterator i, std::list<Object*>* list, Result tempResult){
    if (getBound(&tempResult,list,i) > result.valueSum ) {
        i++;
        if (i == (*list).end()) {
            if (tempResult.valueSum > result.valueSum) result = tempResult;
        }
        else {
            takeNode(i, list, tempResult);
            dontTakeNode(i, list, tempResult);
        }
    }
}

Result *BranchAndBoundSolver::solveProblem(ProblemInstance *problemInstance) {
    capacity = problemInstance->capacity;
    Result tempResult;

    clock_t begin = clock();

    list<Object*> sortedList = problemInstance->objectsList;
    sortedList.sort(Object::comp_decreasing); // Sorting object decreasing: factor is value/weight

    list<Object*>::iterator i = sortedList.begin();

    takeNode(i,&sortedList,tempResult);
    dontTakeNode(i,&sortedList,tempResult);

    clock_t end = clock();
    result.elapsed_sec = double(end - begin) / CLOCKS_PER_SEC;

    return &result;
}





















//Result *BranchAndBoundSolver::solveProblem(ProblemInstance *problemInstance) {
//
//    bool isPutted[problemInstance->capacity] = {0};
//    Result *result = new Result();
//
//    int fw;
//    int fp = -1;
//
//    chrono::time_point<chrono::system_clock> start, stop;
//    start = chrono::system_clock::now();
//
//    list<Object*>sortedList = problemInstance->objectsList;
//    sortedList.sort(Object::comp_decreasing);
//
////    for (auto &i : sortedList){
////        cout<<i->value<<":"<<i->weight<<"::"<<(float)i->value/i->weight<<endl;
////    }
//
//    list<Object*>::iterator k = sortedList.begin();
//
//    while ( k != sortedList.end() && result->weightSum+(*k)->weight < problemInstance->capacity){
//        result->add(*k);
//        isPutted[(*k)->ordinal] = 1;
//        k++;
//    }
//
//    while ( bound(result, sortedList, k, problemInstance->capacity) < fp){
//        while ( k != sortedList.begin() && isPutted[(*k)->ordinal] ) {
//            k--;
//        }
//        if (k == sortedList.begin()) return result;
//        isPutted[(*k)->ordinal] = 0;
//        result->remove(*k);
//    }
//}
