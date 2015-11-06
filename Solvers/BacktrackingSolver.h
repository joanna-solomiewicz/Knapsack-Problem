#pragma once

#include "../Result.h"

class ProblemInstance;

class BacktrackingSolver {
public:
    Result* solveProblem(ProblemInstance* problemInstance);
    Result *solveProblem_weigthSorted(ProblemInstance *problemInstance);
private:
    void takeNode(std::list<Object *>::iterator i, std::list<Object *> *list, Result tempResult);
    void dontTakeNode(std::list<Object *>::iterator i, std::list<Object *> *list, Result tempResult);
};
