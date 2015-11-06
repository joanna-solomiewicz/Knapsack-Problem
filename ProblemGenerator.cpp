#include "ProblemGenerator.h"
#include "ProblemInstance.h"
#include "Object.h"

#include <iostream>

using namespace std;

ProblemInstance *ProblemGenerator::generateProblem() {
    ProblemInstance* problemInstance = new ProblemInstance();
    problemInstance -> capacity = getCapacity();
    problemInstance -> quantity = getObjectsQuantity();
    generateObjectsList(problemInstance);

    return problemInstance;
}

int ProblemGenerator::getCapacity() {
    int capacity;
    cout<<"Type knapsack capacity: ";
    cin>>capacity;
    return capacity;
}

int ProblemGenerator::getObjectsQuantity() {
    int quantity;
    cout<<"Type objects quantity: ";
    cin>>quantity;
    return quantity;
}

void ProblemGenerator::generateObjectsList(ProblemInstance *problemInstance) {
    string answer;
    bool isDrawEnabled = false;
    int objectsLeft = problemInstance->quantity;

    while(1) {
        cout << "Do You want to draw objects' weights and values? [Y/n] ";
        cin >> answer;
        if (answer == "Y" || answer == "y" || answer == "Yes" || answer == "yes"){ isDrawEnabled = true; break; }
        else if (answer == "N" || answer == "n" || answer == "No" || answer == "no"){ isDrawEnabled = false; break; }
    }

    while(objectsLeft){
        if(isDrawEnabled){
            Object* object = new Object(objectsLeft);
            objectsLeft--;
            problemInstance->objectsList.push_front(object);
        }
        else{
            int weigth, value;
            cout<<"Object "<<objectsLeft<<":\n";
            cout<<"Type weight: ";
            cin>>weigth;
            cout<<"Type value: ";
            cin>>value;
            Object* object = new Object(objectsLeft,value,weigth);
            objectsLeft--;
            problemInstance->objectsList.push_front(object);
//            while(1) {
//                cout << "Do You want to draw remaining objects' weights and values? [Y/n] ";
//                cin >> answer;
//                if (answer == "Y" || answer == "y" || answer == "Yes" || answer == "yes"){ isDrawEnabled = true; break; }
//                else if (answer == "N" || answer == "n" || answer == "No" || answer == "no"){ isDrawEnabled = false; break; }
//            }
        }
    }
}

