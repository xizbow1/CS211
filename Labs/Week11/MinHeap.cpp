//    CS 211 Spring 2024 - Week 11 Lab
//    MinHeap in C++

//    David C. Tuttle
//    Last Modified: 05 Apr 2023

//----------------------------------------------------
// File: MinHeap.cpp
// Purpose: Implementation file for a MinHeap class
//----------------------------------------------------

// Blake Culbertson, Dylan Westigard, Orlando Trujillo-Ortiz

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "MinHeap.h"

using namespace std;

// Constructors and Destructor

MinHeap::MinHeap() {
    heapCapacity = DEFAULT_CAPACITY;
    heapSize = 0;
    heapArray = new int[heapCapacity];

}

MinHeap::MinHeap(int capacity) {
    heapCapacity = capacity;
    heapSize = 0;
    heapArray = new int[heapCapacity];
    
}

MinHeap::~MinHeap() {
    delete []heapArray;
    heapSize = 0;
}

//--------------------------------------------
// Function: getSize()
// Purpose: accessor for size of MinHeap
// Returns: number of values stored in MinHeap
//--------------------------------------------

int MinHeap::getSize() const {
    return heapSize;
}

//--------------------------------------------
// Function: getCapacity()
// Purpose: accessor for capacity of MinHeap
// Returns: total capacity of MinHeap
//--------------------------------------------

int MinHeap::getCapacity() const {
    return heapCapacity;
}

//--------------------------------------------
// Function: display()
// Purpose: prints values stored in MinHeap array
// Returns: nothing
//--------------------------------------------

void MinHeap::display() const {
    cout << "*** ARRAY PRINTED HERE ***" << endl;
    cout << "Size = " << heapSize;
    cout << ", Capacity = " << heapCapacity << ", ";
    cout << "Values are ";
    for(int i = 0; i < heapSize; i++){
        cout << heapArray[i] << " ";
    }
    cout << endl;
    return;
}

//--------------------------------------------
// Function: insertValue()
// Purpose: inserts value in MinHeap array
// Returns: true if insert is successful
//--------------------------------------------

bool MinHeap::insertValue(T newValue) {
    cout << "I AM START FLLAG" << endl;
    if (heapSize >= heapCapacity) {
        cout << "I AM FLAG AGGAIN " << heapSize << endl;
        return false;
    }
    heapArray[heapSize] = newValue;
    heapSize++;
    int childIndex = heapSize - 1;
    int parentIndex = (childIndex - 1) / 2;

    cout << heapArray[heapSize] << endl;

    while (heapArray[childIndex] < heapArray[parentIndex] && parentIndex >= 0) {
        cout << "I AM FLAG" << endl;
        T temp = heapArray[parentIndex];
        heapArray[parentIndex] = heapArray[childIndex];
        heapArray[childIndex] = temp;
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    } 
    cout << heapSize << "\nI AM THIRD FLAG" << endl;

    cout << heapSize << "\nI AM FORTH FLAG" << endl; 
    return true;
}

//--------------------------------------------
// Function: removeValue()
// Purpose: prints values stored in MinHeap array
// Returns: true if insert is successful
//--------------------------------------------

T MinHeap::removeValue() {
    if(heapSize == 0){
        return -99999;
    }
    int removedVal = heapArray[0];
    int valAtEnd = heapArray[heapSize - 1];
    heapArray[0] = valAtEnd;
    heapSize--;
    percolateDown(0);
    return removedVal;
}

void MinHeap::percolateDown(int nodeIndex) {
    int currIndex = nodeIndex;
    while(currIndex <= heapSize - 2){
        T minVal;
        int minValIndex;
        if(heapArray[currIndex] < heapArray[currIndex + 1]){
            minVal = heapArray[currIndex];
            minValIndex = currIndex;
        } else {
            minVal = heapArray[currIndex + 1];
            minValIndex = currIndex + 1;
        }
        if(minVal > heapArray[currIndex + 2]){
            minVal = heapArray[currIndex + 2];
            minValIndex = currIndex + 2;
        }
        if(currIndex != minValIndex){
            T temp = heapArray[currIndex];
            heapArray[currIndex] = heapArray[minValIndex];
            heapArray[minValIndex] = temp;
        } else {
            return;
        }
        currIndex = minValIndex;
    }
}