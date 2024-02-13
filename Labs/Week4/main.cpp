//---------------------------------------------------------------
// CS 211 - Data Structures - Spring 2024 - Week 04 Lab Exercise
// A quick look at "slow" sorting algorithms
// Bubble Sort vs Insertion Sort vs Selection Sort
//
// by David C. Tuttle - Last modified 09 Feb 2023
//---------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include <vector>
#include "sortCompare.h"

using namespace std;

// NOTE:  ARRAY_SIZE needs to be a multiple of 100

const int ARRAY_SIZE=10000; // Size of the array to be sorted
const int MAX_VALUE=100000; // Values range from 0 to MAX_VALUE-1

int main() {

    int bubbleSortArray[ARRAY_SIZE];
    int insertionSortArray[ARRAY_SIZE];
    int selectionSortArray[ARRAY_SIZE];
    int i, j, tmp, offset;

    // Seed the pseudo-random number generator
    // NOTE: This is written for CS50 - other IDEs may require
    //       that this code be changed in some way
    srand(time(NULL));

    // ******************************************************
    // Call sorts with RANDOM data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE; i++) {
        bubbleSortArray[i] = rand() % MAX_VALUE;
        insertionSortArray[i] = bubbleSortArray[i];
        selectionSortArray[i] = insertionSortArray[i];
    }
    cout << "\n";

    cout << "*** Bubble sort on random array...\n";
    bubbleSort(bubbleSortArray, ARRAY_SIZE);
    cout << "*** Insertion sort on random array...\n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "*** Selection sort on random array...\n";
    selectionSort(selectionSortArray, ARRAY_SIZE);

    // ******************************************************
    // Call sorts with ALREADY SORTED data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE; i++) {
        // insert sorted data into array[i]
        bubbleSortArray[i] = i * 5;
        insertionSortArray[i] = bubbleSortArray[i];
        selectionSortArray[i] = insertionSortArray[i];
    }
    cout << "\n";

    cout << "*** Bubble sort on sorted array...\n";
    bubbleSort(bubbleSortArray, ARRAY_SIZE);
    cout << "*** Insertion sort on sorted array...\n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "*** Selection sort on sorted array...\n";
    selectionSort(selectionSortArray, ARRAY_SIZE);

    // ******************************************************
    // Call sorts with MOSTLY SORTED data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE; i++) {
        // insert sorted data into array[i]
        bubbleSortArray[i] = i * 5;
    }
    // Swap every 10th value up to +/- 5 positions in array
    for (i = 10; i <= ARRAY_SIZE - 10; i += 10) {
            offset = (rand() % 11) - 5;
            tmp = bubbleSortArray[i];
            bubbleSortArray[i] = bubbleSortArray[i+offset];
            bubbleSortArray[i+offset] = tmp;
    }
    for (i = 0; i < ARRAY_SIZE; i++) {
        insertionSortArray[i] = bubbleSortArray[i];
        selectionSortArray[i] = insertionSortArray[i];
    }
    cout << "\n";

    cout << "*** Bubble sort on nearly sorted array...\n";
    bubbleSort(bubbleSortArray, ARRAY_SIZE);
    cout << "*** Insertion sort on nearly sorted array...\n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "*** Selection sort on nearly sorted array...\n";
    selectionSort(selectionSortArray, ARRAY_SIZE);

    // ******************************************************
    // Call sorts with REVERSE SORTED data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE; i++) {
        bubbleSortArray[i] = (ARRAY_SIZE - i) * 5;
        insertionSortArray[i] = bubbleSortArray[i];
        selectionSortArray[i] = insertionSortArray[i];
    }
    cout << "\n";

    cout << "*** Bubble sort on reverse array...\n";
    bubbleSort(bubbleSortArray, ARRAY_SIZE);
    cout << "*** Insertion sort on reverse array...\n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "*** Selection sort on reverse array...\n";
    selectionSort(selectionSortArray, ARRAY_SIZE);

    // ******************************************************
    // Call sorts with RANDOM, MOSTLY DUPLICATES data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE / 100; i++) {
        tmp = rand() % MAX_VALUE;
        for (j = 0; j < 100; j++) {
            if ((i*100) + j < ARRAY_SIZE) {
                bubbleSortArray[i*100 + j] = tmp;
                insertionSortArray[i*100 + j] = bubbleSortArray[i*100 + j];
                selectionSortArray[i*100 + j] = insertionSortArray[i*100 + j];
           }
        }
    }
    cout << "\n";

    cout << "*** Bubble sort on duplicates array...\n";
    bubbleSort(bubbleSortArray, ARRAY_SIZE);
    cout << "*** Insertion sort on duplicates array...\n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "*** Selection sort on duplicates array...\n";
    selectionSort(selectionSortArray, ARRAY_SIZE);

    return EXIT_SUCCESS;
}
