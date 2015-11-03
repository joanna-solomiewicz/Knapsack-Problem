#pragma once

class Result;
class ProblemInstance;

class BruteforceSolver {
private:
    bool binaryIncrement(int T[], int size);
public:
    Result* solveProblem(ProblemInstance* problemInstance);
};

