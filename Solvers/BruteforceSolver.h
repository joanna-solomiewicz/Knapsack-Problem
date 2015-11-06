#pragma once

#include "../Result.h"
class ProblemInstance;

class BruteforceSolver {
public:
    Result *solveProblem_recursively(ProblemInstance *problemInstance);
    Result *solveProblem_iteratively(ProblemInstance *problemInstance);
private:
    bool binaryIncrement(int T[], int size);
    void takeNode(std::list<Object *>::iterator i, std::list<Object *> *list, Result tempResult);
    void dontTakeNode(std::list<Object *>::iterator i, std::list<Object *> *list, Result tempResult);
};

