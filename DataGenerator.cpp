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

    while(1){
        std::system("clear");
        cout<< "What data do You want to generate?:\n\n";
        cout<< "1. Bruteforce with constant capacity: iterative vs recursive\n"
        << "2. Bruteforce with constant quantity: iterative vs recursive\n"
        << "3. Constant capacity: Greedy vs Dynamic vs BranchAndBound\n"
        << "4. Constant quantity: Greedy vs Dynamic vs BranchAndBound \n"
        << "5. Backtracking with constant capacity: without and with presorting descending by weight\n"
        << "6. Backtracking with constant quantity: without and with presorting descending by weight\n"
        << "7. Quit\n";

        char answer = '0';
        while (answer < '1' || answer > '7')
            cin >> answer;

        switch(answer){
            case '1':
                file.open("./Data/Bruteforce_const_capacity.txt");
                minQuantity = 1;
                maxQuantity = 28;
                for (int i=minQuantity; i<=maxQuantity; i++){
                    ProblemInstance* problemInstance = new ProblemInstance(10,i);

                    system("clear");
                    cout<<"Brutforce iteratively & Bruteforce recurively:\n"
                    <<"Capacity: "<<problemInstance->capacity<<"\n";
                    cout<<"Quantity: "<<problemInstance->quantity<<"\n";
                    DataGenerator::loadingBar(maxQuantity, i);

                    file<<problemInstance->capacity<<" "<<problemInstance->quantity<<" ";
                    result = solveProblem<BruteforceIterativeSolver>(problemInstance);
                    file<<result->elapsed_sec<<" ";
                    result = solveProblem<BruteforceRecursiveSolver>(problemInstance);
                    file<<result->elapsed_sec<<"\n";
                }
                file.close();
                break;
            case '2':
                file.open("./Data/Bruteforce_const_quantity.txt");
                minCapacity=100;
                maxCapacity=400;
                step = (maxCapacity-minCapacity)/sampling;
                for (int i=minCapacity; i<=maxCapacity; i+=step){
                    ProblemInstance* problemInstance = new ProblemInstance(i,20);

                    system("clear");
                    cout<<"Brutforce iteratively & Bruteforce recurively:\n"
                    <<"Capacity: "<<problemInstance->capacity<<"\n";
                    cout<<"Quantity: "<<problemInstance->quantity<<"\n";
                    DataGenerator::loadingBar(maxCapacity, i);

                    file<<problemInstance->capacity<<" "<<problemInstance->quantity<<" ";
                    result = solveProblem<BruteforceIterativeSolver>(problemInstance);
                    file<<result->elapsed_sec<<" ";
                    result = solveProblem<BruteforceRecursiveSolver>(problemInstance);
                    file<<result->elapsed_sec<<"\n";
                }
                file.close();
                break;
            case '3':
                file.open("./Data/Const_capacity.txt");
                minQuantity = 10;
                maxQuantity = 50000;
                step = (maxQuantity-minQuantity)/sampling;
                for (int i=minQuantity; i<=maxQuantity; i+=step){
                    ProblemInstance* problemInstance = new ProblemInstance(200,i);

                    system("clear");
                    cout<<"Greedy & Dynamic & Branch and Bound:\n"
                    <<"Capacity: "<<problemInstance->capacity<<"\n";
                    cout<<"Quantity: "<<problemInstance->quantity<<"\n";
                    DataGenerator::loadingBar(maxQuantity, i);

                    file<<problemInstance->capacity<<" "<<problemInstance->quantity<<" ";
                    result = solveProblem<GreedySolver>(problemInstance);
                    file<<result->elapsed_sec<<" ";
                    result = solveProblem<DynamicSolver>(problemInstance);
                    file<<result->elapsed_sec<<" ";
                    result = solveProblem<BranchAndBoundSolver>(problemInstance);
                    file<<result->elapsed_sec<<"\n";
                }
                file.close();
                break;
            case '4':
                file.open("./Data/Const_quantity.txt");
                minCapacity = 100;
                maxCapacity = 50000;
                step = (maxCapacity-minCapacity)/sampling;
                for (int i=minCapacity; i<=maxCapacity; i+=step){
                    ProblemInstance* problemInstance = new ProblemInstance(i,500);

                    system("clear");
                    cout<<"Greedy & Dynamic & Branch and Bound:\n"
                    <<"Capacity: "<<problemInstance->capacity<<"\n";
                    cout<<"Quantity: "<<problemInstance->quantity<<"\n";
                    DataGenerator::loadingBar(maxCapacity, i);

                    file<<problemInstance->capacity<<" "<<problemInstance->quantity<<" ";
                    result = solveProblem<GreedySolver>(problemInstance);
                    file<<result->elapsed_sec<<" ";
                    result = solveProblem<DynamicSolver>(problemInstance);
                    file<<result->elapsed_sec<<" ";
                    result = solveProblem<BranchAndBoundSolver>(problemInstance);
                    file<<result->elapsed_sec<<"\n";
                }
                file.close();
                break;
            case '5':
                file.open("./Data/Backtracking_const_capacity.txt");
                minQuantity = 1;
                maxQuantity = 50;
                for (int i=minQuantity; i<=maxQuantity; i++){
                    ProblemInstance* problemInstance = new ProblemInstance(100,i);

                    system("clear");
                    cout<<"Backtracking & Backtracking with presorting - decreasing by weight:\n"
                    <<"Capacity: "<<problemInstance->capacity<<"\n";
                    cout<<"Quantity: "<<problemInstance->quantity<<"\n";
                    DataGenerator::loadingBar(maxQuantity, i);

                    file<<problemInstance->capacity<<" "<<problemInstance->quantity<<" ";
                    result = solveProblem<BacktrackingSolver>(problemInstance);
                    file<<result->elapsed_sec<<" ";
                    result = solveProblem<BacktrackingSolver_presorted_by_weight_desc>(problemInstance);
                    file<<result->elapsed_sec<<"\n";
                }
                file.close();
                break;
            case '6':
                file.open("./Data/Backtracking_const_quantity.txt");
                minCapacity = 10;
                maxCapacity = 5000;
                step = (maxCapacity-minCapacity)/sampling;
                for (int i=minCapacity; i<=maxCapacity; i+=step){
                    ProblemInstance* problemInstance = new ProblemInstance(i,50);

                    system("clear");
                    cout<<"Backtracking & Backtracking with presorting - decreasing by weight:\n"
                    <<"Capacity: "<<problemInstance->capacity<<"\n";
                    cout<<"Quantity: "<<problemInstance->quantity<<"\n";
                    DataGenerator::loadingBar(maxCapacity, i);

                    file<<problemInstance->capacity<<" "<<problemInstance->quantity<<" ";
                    result = solveProblem<BacktrackingSolver>(problemInstance);
                    file<<result->elapsed_sec<<" ";
                    result = solveProblem<BacktrackingSolver_presorted_by_weight_desc>(problemInstance);
                    file<<result->elapsed_sec<<"\n";
                }
                file.close();
                break;
            case '7':
                return;
        }
    }
}

void DataGenerator::loadingBar(int max, int tmp) {
    int hash = (int)((float)tmp/max*100);
    int dot = 100 - hash;
    cout << "[";
    for(int i = 0; i < hash; i++) { cout << "#"; }
    for(int i = 0; i < dot; i++) { cout << "."; }
    cout << "]";
    cout << "\t" << (int)((float)tmp/max*100) << "%" << std::flush;
}
