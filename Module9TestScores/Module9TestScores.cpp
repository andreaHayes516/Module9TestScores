/************************************************
** Author: Andrea Hayes
** Date: September 6, 2020
** Module 9 - Pointers
*************************************************/

#include <iostream>
#include <iomanip>
using namespace std;
// Function Prototypes
double getInput();
void selectionSort(double[], double);
double getAverage(double[], double);

int main() {
    // Declare Variables
    int numTest;
    double avg;
    // Get Input
    cout << "How many test scores? ";
    numTest = getInput();
    // Dynamically Allocate Memory
    double* results = nullptr;
    results = new double[numTest];
    // Loop to put scores into arrayD
    for (int i = 0; i < numTest; i++) {
        cout << "What is the score for test " << i + 1 << "? ";
        *(results + i) = getInput();
    }
    // Call functions for average and sort
    avg = getAverage(results, numTest);

    selectionSort(results, numTest);
    // Display results
    cout << "----------------" << endl;
    cout << "Scores from lowest to highest: " << endl;
    cout << endl;

    for (int i = 0; i < numTest;i++) {
        cout << right << setw(10) << fixed << setprecision(2) << showpoint;
        cout << *(results+i) << " ";
        cout << endl;
    }

    cout << endl;
    cout << fixed << setprecision(2) << showpoint;
    cout << "The average of all test scores is: " << avg << endl;

    delete results;
}
// Function to get test scores
double getInput(){
    double test;
    do {
        cin >> test;
        if (test < 0) {
            cout << "Enter a number greater than or equal to 0" << endl;
            cout << "Please reenter test number: ";
        }
    } while (test < 0);
    return test;
}
// Function to do assending sort
void selectionSort(double test[], double results) {
    int minIndex;
    double minValue=0;

    for (int start = 0; start < (results - 1); start++) {
        minIndex = start;
        minValue = *(test+start);
        for (int index = start + 1; index < results; index++) {
            if (test[index] < minValue) {
                minValue = *(test+index);
                minIndex = index;
            }
        }
        swap(*(test+minIndex), *(test+start));
    }
}
//Function to figure average
double getAverage(double test[], double results) {
    double total = 0, avg;
    for (int i = 0; i < results; i++) {
        total += *(test+i);
    }
    avg = total / results;
    return avg;
}