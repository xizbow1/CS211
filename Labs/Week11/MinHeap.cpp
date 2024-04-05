//    CS 211 Spring 2024 - Week 11 Lab
//    MinHeap in C++

//    David C. Tuttle
//    Last Modified: 05 Apr 2023

//----------------------------------------------------
// File: MinHeap.cpp
// Purpose: Implementation file for a MinHeap class
//----------------------------------------------------

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
}

MinHeap::MinHeap(int capacity) {
}

MinHeap::~MinHeap() {
}

//--------------------------------------------
// Function: getSize()
// Purpose: accessor for size of MinHeap
// Returns: number of values stored in MinHeap
//--------------------------------------------

int MinHeap::getSize() const {
    return 0;  // REMOVE THIS LINE
}

//--------------------------------------------
// Function: getCapacity()
// Purpose: accessor for capacity of MinHeap
// Returns: total capacity of MinHeap
//--------------------------------------------

int MinHeap::getCapacity() const {
    return 0;  // REMOVE THIS LINE
}

//--------------------------------------------
// Function: display()
// Purpose: prints values stored in MinHeap array
// Returns: nothing
//--------------------------------------------

void MinHeap::display() const {
    // REMOVE THESE LINES
    cout << "*** ARRAY PRINTED HERE ***" << endl;
    return;
}

//--------------------------------------------
// Function: insertValue()
// Purpose: inserts value in MinHeap array
// Returns: true if insert is successful
//--------------------------------------------

bool MinHeap::insertValue(T newValue) {
    return false; // REMOVE THIS LINE
}

//--------------------------------------------
// Function: removeValue()
// Purpose: prints values stored in MinHeap array
// Returns: true if insert is successful
//--------------------------------------------

T MinHeap::removeValue() {
    return -99999; // REMOVE THIS LINE
}

