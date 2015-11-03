/*
 * Oto proponowane założenia:
- Instancja problemu może być ustalana przez użytkownika,
 który może podać:
 pojemność plecaka, ilość elementów, ich wagi i ceny (możliwość generacji losowej).
- Na wyjściu program podaje dla każdego zaimplementowanego algorytmu znalezione rozwiązanie
 w postaci wypisanej zawartości plecaka, wspólnej wagi i ceny tych elementów.h
 */

#include <iostream>
#include "Solvers/DynamicSolver.h"
#include "Result.h"

using namespace std;

int main() {
    srand(time(NULL));

    ProblemInstance* problemInstance = ProblemGenerator::generateProblem();
    DynamicSolver dynamic;
    Result* result;
    result = dynamic.solveProblem(problemInstance);
    result->print();


    return 111;
}