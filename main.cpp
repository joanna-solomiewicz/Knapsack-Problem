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
#include "ProblemInstance.h"
#include "Result.h"
#include "Solvers/BruteforceIterativeSolver.h"
#include "Solvers/BruteforceRecursiveSolver.h"
#include "Solvers/GreedySolver.h"
#include "Solvers/BacktrackingSolver.h"
#include "Solvers/BacktrackingSolver_presorted_by_weight_desc.h"
#include "Solvers/DynamicSolver.h"
#include "Solvers/BranchAndBoundSolver.h"
#include "DataGenerator.h"
using namespace std;

template <class T>
Result* solveProblem(ProblemInstance *instance){
    T solver;
    return solver.solveProblem(instance);
}


int main() {
    srand(time(NULL));

    std::system("clear");
    cout<<"Greetings!\n"
        <<"I will solve 0-1 Knapsack Problem for You :-)\n"
        <<"\n";

    cout<<"Let's generate problem instance:\n";
    ProblemInstance* problemInstance = ProblemGenerator::generateProblem();

    while (1)
    {
        Result* result = NULL;
        std::system("clear");

        cout << "Great! Now, what do You want to do?:\n\n";
        cout << "1. Show me problem instance:\n"
        << "2. Solve problem using 'Bruteforce'algorithm (iterative version)\n"
        << "3. Solve problem using 'Bruteforce' algorithm (recursive version)\n"
        << "4. Solve problem using 'Greedy' algorithm\n"
        << "5. Solve problem using 'Backtracking' algorithm\n"
        << "6. Solve problem using 'Dynamic' algorithm\n"
        << "7. Solve problem using 'Branch and Bound' algorithm\n"
        << "8. Quit\n\n\n"
        << "G. Generate output data.";

        char answer = '0';
        while ( (answer < '1' || answer > '8') && answer !='G')
            cin >> answer;

        switch (answer) {
            case '1':
                problemInstance->print(); break;
            case '2':
                result = solveProblem<BruteforceIterativeSolver>(problemInstance); break;
            case '3':
                result = solveProblem<BruteforceRecursiveSolver>(problemInstance); break;
            case '4':
                result = solveProblem<GreedySolver>(problemInstance); break;
            case '5':
                result = solveProblem<BacktrackingSolver>(problemInstance); break;
            case '6':
                result = solveProblem<BacktrackingSolver_presorted_by_weight_desc>(problemInstance); break;
            case '7':
                result = solveProblem<BranchAndBoundSolver>(problemInstance); break;
            case '8':
                return 111;
            case 'G':
                DataGenerator::generate();
                break;
        }

        if(result != NULL) result->print();
        
        cout<<"\nType anything to continue:\n";
        cin>>answer;

    }
}