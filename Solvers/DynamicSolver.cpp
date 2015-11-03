#include "DynamicSolver.h"

#include "../ProblemInstance.h"
#include "../Result.h"
#include <chrono>

using namespace std;

Result* DynamicSolver::solveProblem(ProblemInstance *problemInstance) {

    int **Table = new int* [problemInstance->quantity + 1];
    for(int i = 0; i < problemInstance->quantity + 1; i++) { Table[i] = new int[problemInstance->capacity + 1]; };

    Result *result = new Result();

    chrono::time_point<chrono::system_clock> start, stop;

    start = chrono::system_clock::now();

    for(int i = 0; i < problemInstance->quantity + 1; i++) { Table[i][0] = 0; };
    for(int i = 0; i < problemInstance->capacity + 1; i++) { Table[0][i] = 0; };

    list<Object*>::iterator tmp = problemInstance->objectsList.begin();
    for(int i = 1; i < problemInstance->quantity + 1; i++) {
        for(int j = 1; j < problemInstance->capacity + 1; j++) {
            if(j < (*tmp)->weight ) Table[i][j] = Table[i-1][j];
            else {
                if (Table[i - 1][j] > Table[i - 1][j - (*tmp)->weight] + (*tmp)->value) Table[i][j] = Table[i - 1][j];
                else Table[i][j] = Table[i - 1][j - (*tmp)->weight] + (*tmp)->value;
            }
        }
        tmp++;
    }

    int i = problemInstance->quantity;
    int j = problemInstance->capacity;
    while(true) {
        while(i > 0 && j > 0 && Table[i][j] == Table[i-1][j]) i--;
        if(i == 0 || j == 0) break;
        list<Object*>::iterator tmp_res = problemInstance->objectsList.begin();
        int shift = 1;
        while(shift < i) {
            tmp_res++;
            shift++;
        }
        result->chosenObjectsList.push_front(*tmp_res);
        i--;
        j -= (*tmp_res)->weight;
    }


    stop = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = stop-start;

    for(int m = 0; m < problemInstance->quantity + 1; m++) delete[] Table[m];
    delete[] Table;

    return result;
}

