#pragma once


#include "../ProblemGenerator.h"
#include "../ProblemInstance.h"

class ProblemInstance;
class Result;

class DynamicSolver {
public:
    Result* solveProblem(ProblemInstance* problemInstance);

};

