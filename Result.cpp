#include "Result.h"

#include <iostream>

using namespace std;

Result::Result() {
    valueSum = 0;
    weightSum = 0;
    elapsed_sec = 0.0;
    chosenObjectsList.clear();
}

void Result::print() {
    int objectsLeft = (int) chosenObjectsList.size();

    while(objectsLeft) {
        Object* resultObject = chosenObjectsList.front();
        cout << "value: " << (*resultObject).value << "\t";
        cout << "weight: " << (*resultObject).weight << "\t";
        cout << endl;
        chosenObjectsList.pop_front();
        objectsLeft--;
    }
    cout << "Time: " << elapsed_sec << " seconds" << endl;
}

void Result::add(Object *object) {
    valueSum += object->value;
    weightSum += object->weight;
    chosenObjectsList.push_back(object);
}

void Result::remove(Object *object) {
    valueSum -= object->value;
    weightSum -= object->weight;
    chosenObjectsList.remove(object);
}

bool Result::isEqual(Result *result2) {
    if (this->valueSum != result2->valueSum) return false;
//    if (this->weightSum != result2->weightSum) return false; -> to nie ma znaczenia (?)
//    for (auto &i : this->chosenObjectsList){  // to chyba też
//        bool isFound = false;
//        for (auto &j : result2->chosenObjectsList){
//            if(i->ordinal == j->ordinal) { isFound=true; break; }
//        }
//        if (!isFound) return false;
//    }
    return true;
}
