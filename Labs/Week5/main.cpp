//---------------------------------------------------------------
// CS 211 - Data Structures - Spring 2024 - Week 05 Lab Exercise
// A comparison of "fast" sorting algorithms
//
// by David C. Tuttle - Last modified 16 Feb 2023
//---------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "sortCompare.h"

using namespace std;

const int ARRAY_SIZE=5000; // Size of the array to be sorted
const int MAX_VALUE=100000; // Values range from 0 to MAX_VALUE-1

int main() {

    int bubbleSortArray[ARRAY_SIZE];
    int insertionSortArray[ARRAY_SIZE];
    int selectionSortArray[ARRAY_SIZE];
    int mergeSortArray[ARRAY_SIZE];
    int quickSortArray[ARRAY_SIZE];
    int i, j, tmp, offset;

    // Call all the sorts with RANDOM data

    // Seed the pseudo-random number generator
    // NOTE: This is written for CS50 - other IDEs may require
    //       that this code be changed in some way
    srand(time(NULL));

    // ******************************************************
    // Call sorts with RANDOM data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE; i++) {
        bubbleSortArray[i] = rand() % MAX_VALUE;

        insertionSortArray[i] = selectionSortArray[i] =
        mergeSortArray[i] = quickSortArray[i] = bubbleSortArray[i];
    }

    cout << "\n"
         << "************************************************** \n"
         << "*** RANDOM ARRAY OF SIZE " << ARRAY_SIZE << "\n"
         << "************************************************** \n";
    cout << "*** Bubble sort on random array...\n";
    bubbleSort(bubbleSortArray, ARRAY_SIZE);
    cout << "*** Insertion sort on random array...\n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "*** Selection sort on random array...\n";
    selectionSort(selectionSortArray, ARRAY_SIZE);
    cout << "*** Merge sort on random array...\n";
    mergeSort(mergeSortArray, ARRAY_SIZE);
    cout << "*** Quicksort on random array...\n";
    quickSort(quickSortArray, ARRAY_SIZE);

    // ******************************************************
    // Call sorts with ALREADY SORTED data
    // ******************************************************

    for (int i = 0; i < ARRAY_SIZE; i++) {
        bubbleSortArray[i] = i * 5;

        insertionSortArray[i] = selectionSortArray[i] =
        mergeSortArray[i] = quickSortArray[i] = bubbleSortArray[i];
    }

    cout << "\n"
         << "************************************************** \n"
         << "*** ALREADY SORTED ARRAY OF SIZE " << ARRAY_SIZE << "\n"
         << "************************************************** \n";
    cout << "*** Bubble sort on sorted array...\n";
    bubbleSort(bubbleSortArray, ARRAY_SIZE);
    cout << "*** Insertion sort on sorted array...\n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "*** Selection sort on sorted array...\n";
    selectionSort(selectionSortArray, ARRAY_SIZE);
    cout << "*** Merge sort on sorted array...\n";
    mergeSort(mergeSortArray, ARRAY_SIZE);
    cout << "*** Quicksort on sorted array...\n";
    quickSort(quickSortArray, ARRAY_SIZE);

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
        insertionSortArray[i] = selectionSortArray[i] =
        mergeSortArray[i] = quickSortArray[i] = bubbleSortArray[i];
    }

    cout << "\n"
         << "************************************************** \n"
         << "*** NEARLY SORTED ARRAY OF SIZE " << ARRAY_SIZE << "\n"
         << "************************************************** \n";
    cout << "*** Bubble sort on nearly sorted array...\n";
    bubbleSort(bubbleSortArray, ARRAY_SIZE);
    cout << "*** Insertion sort on nearly sorted array...\n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "*** Selection sort on nearly sorted array...\n";
    selectionSort(selectionSortArray, ARRAY_SIZE);
    cout << "*** Merge sort on nearly sorted array...\n";
    mergeSort(mergeSortArray, ARRAY_SIZE);
    cout << "*** Quicksort on nearly sorted array...\n";
    quickSort(quickSortArray, ARRAY_SIZE);

    // ******************************************************
    // Call sorts with REVERSE SORTED data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE; i++) {
        bubbleSortArray[i] = (ARRAY_SIZE - i) * 5;

        insertionSortArray[i] = selectionSortArray[i] =
        mergeSortArray[i] = quickSortArray[i] = bubbleSortArray[i];
    }
    cout << "\n";

    cout << "\n"
         << "************************************************** \n"
         << "*** REVERSE SORTED ARRAY OF SIZE " << ARRAY_SIZE << "\n"
         << "************************************************** \n";
    cout << "*** Bubble sort on reverse sorted array...\n";
    bubbleSort(bubbleSortArray, ARRAY_SIZE);
    cout << "*** Insertion sort on reverse sorted array...\n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "*** Selection sort on reverse sorted array...\n";
    selectionSort(selectionSortArray, ARRAY_SIZE);
    cout << "*** Merge sort on reverse sorted array...\n";
    mergeSort(mergeSortArray, ARRAY_SIZE);
    cout << "*** Quicksort on reverse sorted array...\n";
    quickSort(quickSortArray, ARRAY_SIZE);

    // ******************************************************
    // Call sorts with RANDOM, MOSTLY DUPLICATES data
    // ******************************************************

    for (i = 0; i < ARRAY_SIZE / 100; i++) {
        tmp = rand() % MAX_VALUE;
        for (j = 0; j < 100; j++) {
            if ((i*100) + j < ARRAY_SIZE) {
                bubbleSortArray[i*100 + j] = tmp;
           }
        }
    }
    for (int i = 0; i < ARRAY_SIZE; i++) {
        insertionSortArray[i] = selectionSortArray[i] =
        mergeSortArray[i] = quickSortArray[i] = bubbleSortArray[i];
    }

    cout << "\n"
         << "************************************************** \n"
         << "*** MANY DUPLICATES ARRAY OF SIZE " << ARRAY_SIZE << "\n"
         << "************************************************** \n";
    cout << "*** Bubble sort on many duplicates array...\n";
    bubbleSort(bubbleSortArray, ARRAY_SIZE);
    cout << "*** Insertion sort on many duplicates array...\n";
    insertionSort(insertionSortArray, ARRAY_SIZE);
    cout << "*** Selection sort on many duplicates array...\n";
    selectionSort(selectionSortArray, ARRAY_SIZE);
    cout << "*** Merge sort on many duplicates array...\n";
    mergeSort(mergeSortArray, ARRAY_SIZE);
    cout << "*** Quicksort on many duplicates array...\n";
    quickSort(quickSortArray, ARRAY_SIZE);

    return EXIT_SUCCESS;
}
