#include "BruteforceIterativeSolver.h"

#include "../ProblemInstance.h"
#include "../Result.h"

using namespace std;

static Result result;

Result* BruteforceIterativeSolver::solveProblem(ProblemInstance *problemInstance) {
    int *Table = new int[problemInstance->quantity];
    int best_p_sum = 0;
    for (int j = 0; j < problemInstance->quantity; j++) { Table[j] = 0; }

    clock_t begin = clock();

    while( binaryIncrement(Table, problemInstance->quantity)) {
        Result pickedObjects;
        for (auto &i : problemInstance->objectsList){
            if(Table[i->ordinal - 1] == 1){
                pickedObjects.add(i);
            }
        }
        if(pickedObjects.weightSum > problemInstance->capacity) continue;
        if(pickedObjects.valueSum > best_p_sum){
            best_p_sum = pickedObjects.valueSum;
            result = pickedObjects;
        }
    }

    clock_t end = clock();
    result.elapsed_sec = double(end - begin) / CLOCKS_PER_SEC;

    delete[] Table;

    return &result;
}

bool BruteforceIterativeSolver::binaryIncrement(int T[], int size) {
    T[size - 1]++;
    for (int i = size - 1; i > 0; i--) {
        if (T[i] == 2) {T[i]=0; T[i - 1]++;}
        else break;
    }
    if (T[0] == 2) return 0;
    return 1;
}
