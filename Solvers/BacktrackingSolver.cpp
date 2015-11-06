#include "BacktrackingSolver.h"

#include "../ProblemInstance.h"
#include "../Result.h"
#include <chrono>

#include <iostream>

using namespace std;


static Result result;
static int capacity;


Result *BacktrackingSolver::solveProblem(ProblemInstance *problemInstance) {
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

void BacktrackingSolver::takeNode(std::list<Object*>::iterator i, std::list<Object*>* list, Result tempResult){
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

void BacktrackingSolver::dontTakeNode(std::list<Object*>::iterator i, std::list<Object*>* list, Result tempResult){
    i++;
    if(i == (*list).end()){
        if(tempResult.valueSum > result.valueSum) result = tempResult;
    }
    else{
        takeNode(i,list,tempResult);
        dontTakeNode(i,list,tempResult);
    }
}

Result *BacktrackingSolver::solveProblem_weigthSorted(ProblemInstance *problemInstance) {
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




















//int bound(Result* currResult, std::list<Object*>list, std::list<Object*>::iterator k, int capacity){
//    int b,c;
//    b = currResult->valueSum;
//    c = currResult->weightSum;
//    std::list<Object*>::iterator i;
//    for (i=k; i != list.end(); i++){
//        c+=(*i)->weight;
//        if (c < capacity) b+=(*i)->value;
//        else return (b + (1 - (c-capacity)/(*i)->weight/(*i)->value));
//    }
//    return b;
//}

//Result *BacktrackingSolver::solveProblem(ProblemInstance *problemInstance) {
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
