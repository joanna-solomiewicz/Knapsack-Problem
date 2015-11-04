#include "BruteforceSolver.h"

#include "../ProblemInstance.h"
#include "../Result.h"
#include <chrono>

using namespace std;

Result* BruteforceSolver::solveProblem(ProblemInstance *problemInstance) {

    int *Table = new int[problemInstance->quantity];
    int best_p_sum = 0;
    for (int j = 0; j < problemInstance->quantity; j++) { Table[j] = 0; }

    Result* result = new Result();

    chrono::time_point<chrono::system_clock> start, stop;

    start = chrono::system_clock::now();

    while( binaryIncrement(Table, problemInstance->quantity)) {
        Result* pickedObjects = new Result();
        pickedObjects->valueSum = 0;
        pickedObjects->weightSum;

        list<Object*>::iterator tmp = problemInstance->objectsList.begin();
        for (int i = (problemInstance->quantity)-1; i >= 0; i--){
            if(Table[i] == 1){
                pickedObjects->chosenObjectsList.push_back(*tmp);
                pickedObjects->valueSum += (*tmp)->value; pickedObjects->weightSum += (*tmp)->weight;
                if(pickedObjects->weightSum > problemInstance->capacity) break;
            }
            tmp++;
        }
        if(pickedObjects->weightSum > problemInstance->capacity) continue;

        if(pickedObjects->valueSum > best_p_sum){
            best_p_sum = pickedObjects->valueSum;
            result = pickedObjects;
        }
    }

    stop = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = stop-start;

    delete[] Table;

    return result;
}

bool BruteforceSolver::binaryIncrement(int T[], int size) {
    T[size - 1]++;
    for (int i = size - 1; i > 0; i--) {
        if (T[i] == 2) {T[i]=0; T[i - 1]++;}
        else break;
    }
    if (T[0] == 2) return 0;
    return 1;
}
