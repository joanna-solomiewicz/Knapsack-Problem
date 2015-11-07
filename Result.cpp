#include "Result.h"

#include <iostream>

using namespace std;

Result::Result() {
    valueSum = 0;
    weightSum = 0;
    elapsed_sec = 0.0;
    chosenObjectsList.clear();
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

void Result::print() {
    cout<<"Objects in Knapsack:\n\n";
    int n=1;
    for( auto &i : this->chosenObjectsList){
        cout<<"Object "<<n<<":\n";
        cout << "Value: " << i->value<< "\n";
        cout << "Weight: " << i->weight << "\n\n";
        n++;
    }
    cout<<"Their value is "<<this->valueSum<<"\n";
    cout<<"Their weight is "<<this->weightSum<<"\n";
    cout << "Problem solved in: " << elapsed_sec << " seconds" << endl;
}

