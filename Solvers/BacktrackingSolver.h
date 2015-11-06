#pragma once

#include "../Result.h"

class Result;
class ProblemInstance;

class BacktrackingSolver {
private:
public:
    Result* solveProblem(ProblemInstance* problemInstance);


    void takeNode(std::list<Object *>::iterator i, std::list<Object *> *list, Result tempResult);

    void dontTakeNode(std::list<Object *>::iterator i, std::list<Object *> *list, Result tempResult);
};
