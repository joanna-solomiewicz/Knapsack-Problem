/*
 * Oto proponowane założenia:
- Instancja problemu może być ustalana przez użytkownika,
 który może podać:
 pojemność plecaka, ilość elementów, ich wagi i ceny (możliwość generacji losowej).
- Na wyjściu program podaje dla każdego zaimplementowanego algorytmu znalezione rozwiązanie
 w postaci wypisanej zawartości plecaka, wspólnej wagi i ceny tych elementów.h
 */

#include <iostream>
#include "ProblemGenerator.h"
#include "Result.h"
#include "Solvers/DynamicSolver.h"
#include "Solvers/BruteforceSolver.h"
#include "Solvers/GreedySolver.h"

using namespace std;

int main() {
    srand(time(NULL));

    ProblemInstance* problemInstance = ProblemGenerator::generateProblem();
    DynamicSolver dynamic;
    Result* dynamicRes;
    dynamicRes = dynamic.solveProblem(problemInstance);
    dynamicRes->print();

    BruteforceSolver bruteforce;
    Result* bruteforceRes;
    bruteforceRes = bruteforce.solveProblem(problemInstance);
    bruteforceRes->print();

    GreedySolver greedy;
    Result* greedyRes;
    greedyRes = greedy.solveProblem(problemInstance);
    greedyRes->print();


    return 111;
}