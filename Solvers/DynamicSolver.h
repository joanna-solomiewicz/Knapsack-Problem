#pragma once

class Result;
class ProblemInstance;

class DynamicSolver {
public:
    Result* solveProblem(ProblemInstance* problemInstance);
};

