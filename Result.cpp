#include "Result.h"

#include <iostream>

using namespace std;

Result::Result() {
    valueSum = 0;
    weightSum = 0;
//    elapsed_seconds = 0;
    chosenObjectsList.clear();
}

void Result::print() {
    int objectsLeft = chosenObjectsList.size();

    while(objectsLeft) {
        Object* resultObject = chosenObjectsList.front();
        cout << "value: " << (*resultObject).value << "\t";
        cout << "weight: " << (*resultObject).weight << "\t";
        cout << endl;
        chosenObjectsList.pop_front();
        objectsLeft--;
    }
    cout << "Time: " << elapsed_seconds.count() << endl;
}
