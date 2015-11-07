#include "DataGenerator.h"

#include <fstream>
#include <iostream>
#include "ProblemInstance.h"
#include "Result.h"

#include "Solvers/BruteforceIterativeSolver.h"
#include "Solvers/BruteforceRecursiveSolver.h"
#include "Solvers/GreedySolver.h"
#include "Solvers/BacktrackingSolver.h"
#include "Solvers/BacktrackingSolver_presorted_by_weight_desc.h"
#include "Solvers/DynamicSolver.h"
#include "Solvers/BranchAndBoundSolver.h"
using namespace std;

template <class T>
Result* solveProblem(ProblemInstance *instance){
    T solver;
    return solver.solveProblem(instance);
}

void DataGenerator::generate() {
    Result* result;
    ofstream file;
    file.open("./Data/Bruteforce.txt");

    const int maxQuantity = 28;
    for (int i=1; i<=maxQuantity; i++){
        ProblemInstance* problemInstance = new ProblemInstance(10,i);

        system("clear");
        cout<<"BRUTEFORCE:\n"
            <<"Constant capacity\n";
        cout<<"Quantity: "<<problemInstance->quantity<<"\n";
        cout<<(int)((float)i/maxQuantity*100)<<"%"<<std::flush;

        file<<problemInstance->capacity<<" "<<problemInstance->quantity<<" ";
        result = solveProblem<BruteforceIterativeSolver>(problemInstance);
        file<<result->elapsed_sec<<" ";
        result = solveProblem<BruteforceRecursiveSolver>(problemInstance);
        file<<result->elapsed_sec<<"\n";
    }







    file.close();
}
