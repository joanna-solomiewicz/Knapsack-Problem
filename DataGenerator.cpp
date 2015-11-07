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

    int sampling = 100;

    int maxQuantity = 0;
    int minQuantity = 0;
    int maxCapacity = 0;
    int minCapacity = 0;
    int step = 0;



    file.open("./Data/Bruteforce_const_capacity.txt");
    minQuantity = 1;
    maxQuantity = 28;
    for (int i=minQuantity; i<=maxQuantity; i++){
        ProblemInstance* problemInstance = new ProblemInstance(10,i);

        system("clear");
        cout<<"Brutforce iteratively & Bruteforce recurively:\n"
            <<"Capacity: "<<problemInstance->capacity<<"\n";
        cout<<"Quantity: "<<problemInstance->quantity<<"\n";
        cout<<(int)((float)i/maxQuantity*100)<<"%"<<std::flush;

        file<<problemInstance->capacity<<" "<<problemInstance->quantity<<" ";
        result = solveProblem<BruteforceIterativeSolver>(problemInstance);
        file<<result->elapsed_sec<<" ";
        result = solveProblem<BruteforceRecursiveSolver>(problemInstance);
        file<<result->elapsed_sec<<"\n";
    }
    file.close();

    file.open("./Data/Bruteforce_const_quantity.txt");
    minCapacity=100;
    maxCapacity=5000;
    step = (maxCapacity-minCapacity)/sampling;
    for (int i=minCapacity; i<=maxCapacity; i+=step){
        ProblemInstance* problemInstance = new ProblemInstance(10,i);

        system("clear");
        cout<<"Brutforce iteratively & Bruteforce recurively:\n"
        <<"Capacity: "<<problemInstance->capacity<<"\n";
        cout<<"Quantity: "<<problemInstance->quantity<<"\n";
        cout<<(int)((float)i/maxQuantity*100)<<"%"<<std::flush;

        file<<problemInstance->capacity<<" "<<problemInstance->quantity<<" ";
        result = solveProblem<BruteforceIterativeSolver>(problemInstance);
        file<<result->elapsed_sec<<" ";
        result = solveProblem<BruteforceRecursiveSolver>(problemInstance);
        file<<result->elapsed_sec<<"\n";
    }
    file.close();

    file.open("./Data/Const_capacity.txt");
    minQuantity = 10;
    maxQuantity = 5000;
    step = (maxQuantity-minQuantity)/sampling;
    for (int i=minQuantity; i<=maxQuantity; i+=step){
        ProblemInstance* problemInstance = new ProblemInstance(100,i);

        system("clear");
        cout<<"Greedy & Backtracking & Dynamic & Branch and Bound:\n"
        <<"Capacity: "<<problemInstance->capacity<<"\n";
        cout<<"Quantity: "<<problemInstance->quantity<<"\n";
        cout<<(int)((float)i/maxQuantity*100)<<"%"<<std::flush;

        file<<problemInstance->capacity<<" "<<problemInstance->quantity<<" ";

        result = solveProblem<GreedySolver>(problemInstance);
        file<<result->elapsed_sec<<" ";
        result = solveProblem<BacktrackingSolver>(problemInstance);
        file<<result->elapsed_sec<<" ";
        result = solveProblem<DynamicSolver>(problemInstance);
        file<<result->elapsed_sec<<" ";
        result = solveProblem<BranchAndBoundSolver>(problemInstance);
        file<<result->elapsed_sec<<"\n";
    }
    file.close();

    file.open("./Data/Const_quantity.txt");
    minCapacity = 5;
    maxCapacity = 500;
    step = (maxCapacity-minCapacity)/sampling;
    for (int i=minCapacity; i<=maxCapacity; i+=step){
        ProblemInstance* problemInstance = new ProblemInstance(i,50);

        system("clear");
        cout<<"Greedy & Backtracking & Dynamic & Branch and Bound:\n"
        <<"Capacity: "<<problemInstance->capacity<<"\n";
        cout<<"Quantity: "<<problemInstance->quantity<<"\n";
        cout<<(int)((float)i/maxQuantity*100)<<"%"<<std::flush;

        result = solveProblem<GreedySolver>(problemInstance);
        file<<result->elapsed_sec<<" ";
        result = solveProblem<BacktrackingSolver>(problemInstance);
        file<<result->elapsed_sec<<" ";
        result = solveProblem<DynamicSolver>(problemInstance);
        file<<result->elapsed_sec<<" ";
        result = solveProblem<BranchAndBoundSolver>(problemInstance);
        file<<result->elapsed_sec<<"\n";
    }
    file.close();


    file.open("./Data/Backtracking_const_capacity.txt");
    minQuantity = 10;
    maxQuantity = 100;
    step = (maxQuantity-minQuantity)/sampling;
    for (int i=minQuantity; i<=maxQuantity; i+=step){
        ProblemInstance* problemInstance = new ProblemInstance(40,i);

        system("clear");
        cout<<"Backtracking & Backtracking with presorting - decreasing by weight:\n"
        <<"Capacity: "<<problemInstance->capacity<<"\n";
        cout<<"Quantity: "<<problemInstance->quantity<<"\n";
        cout<<(int)((float)i/maxQuantity*100)<<"%"<<std::flush;

        result = solveProblem<BacktrackingSolver>(problemInstance);
        file<<result->elapsed_sec<<" ";
        result = solveProblem<BacktrackingSolver_presorted_by_weight_desc>(problemInstance);
        file<<result->elapsed_sec<<"\n";
    }
    file.close();

}
