//    CS 211 Spring 2024 - Week 11 Lab
//    MinHeap in C++

//    David C. Tuttle
//    Last Modified: 05 Apr 2023


#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "MinHeap.h"

using namespace std;

int main() {
    MinHeap *testHeap;
    int size;
    T newValue;
    char response;

    cout << boolalpha;

    cout << "Size of heap?  Enter 0 for default size: ";
    cin >> size;

    if (size <= 0)
        testHeap = new MinHeap();
    else
        testHeap = new MinHeap(size);

    cout << "*** TESTS OF MINHEAP ***" << endl;
    cout << "Enter a value into the heap (99999 to end): ";
    cin >> newValue;

    while (newValue != 99999) {
        testHeap->insertValue(newValue);
        testHeap->display();

        cout << "Enter next value into the heap (99999 to end): ";
        cin >> newValue;
    }

    testHeap->display();

    cout << "Do you want to remove a value (y/n)? ";
    cin >> response;

    while (response == 'y' || response == 'Y') {
        cout << "Value " << testHeap->removeValue()
             << " removed from the heap!" << endl;
        testHeap->display();

        cout << "Remove another value (y/n)? ";
        cin >> response;
    }

    testHeap->display();
    cout << "All done!" << endl;
    delete testHeap;

    return EXIT_SUCCESS;
}

