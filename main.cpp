/*
 * Oto proponowane założenia:
- Instancja problemu może być ustalana przez użytkownika,
 który może podać:
 pojemność plecaka, ilość elementów, ich wagi i ceny (możliwość generacji losowej).
- Na wyjściu program podaje dla każdego zaimplementowanego algorytmu znalezione rozwiązanie
 w postaci wypisanej zawartości plecaka, wspólnej wagi i ceny tych elementów
 */

#include <iostream>
#include "ProblemGenerator.h"
#include "Result.h"
#include "Solvers/DynamicSolver.h"
#include "Solvers/BruteforceSolver.h"
#include "Solvers/GreedySolver.h"
#include "Solvers/BacktrackingSolver.h"
#include "Solvers/BranchAndBoundSolver.h"

using namespace std;

int main() {
    srand(time(NULL));

    ProblemInstance* problemInstance = ProblemGenerator::generateProblem();

    DynamicSolver dynamic;
    Result* dynamicRes;
    dynamicRes = dynamic.solveProblem(problemInstance);
    dynamicRes->print();

//    BruteforceSolver bruteforce;
//    Result* bruteforceRes;
//    bruteforceRes = bruteforce.solveProblem(problemInstance);
//    bruteforceRes->print();

    GreedySolver greedy;
    Result* greedyRes;
    greedyRes = greedy.solveProblem(problemInstance);
    greedyRes->print();

    BacktrackingSolver backtracking;
    Result *backtrackingRes;
    backtrackingRes = backtracking.solveProblem(problemInstance);
    backtrackingRes->print();

    BranchAndBoundSolver branchAndBound;
    Result *branchAndBoundRes;
    branchAndBoundRes = branchAndBound.solveProblem(problemInstance);
    branchAndBoundRes->print();

    if (backtrackingRes->isEqual(dynamicRes)) cout<<"\n\nbacktracking = dynamic";
    if (branchAndBoundRes->isEqual(dynamicRes) ) cout<<"\n\nbranch = dynamic";


    return 111;
}