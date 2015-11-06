#pragma once

#include "../Result.h"
class ProblemInstance;

class BruteforceIterativeSolver {

public:
    Result *solveProblem(ProblemInstance *problemInstance);
private:
    bool binaryIncrement(int T[], int size);
};

