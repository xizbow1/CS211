//---------------------------------------------------------------
// CS 211 - Data Structures - Spring 2024 - Week 04 Lab Exercise
// A quick look at sorting algorithms
// Bubble Sort vs Insertion Sort vs Selection Sort
//
// by David C. Tuttle - Last modified 09 Feb 2023
//---------------------------------------------------------------

// Spring 2024 CS 211 Lab - Week 4
// Blake Culbertson and Jaztin Marasigan

#include <cstdlib>
#include <iostream>

using namespace std;

//---------------------------------------------------------------
// bubbleSort(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged in sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

void bubbleSort(int data[], int size) {
    int i, j, tmp;
    bool hasSwapped;
    unsigned long int swaps = 0;
    unsigned long int comps = 0;

    for (i = size; i > 0; i--) {
        hasSwapped = false;
        for (j = 0; j < i - 1; j++) {
            comps++;
            if (data[j] > data[j + 1]) {
                swaps++;
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
                hasSwapped = true;
            }
        }
        if (hasSwapped == false)
             break;
    }
    cout << "Total swaps: " << swaps << ", Total comparisons: " << comps << endl;
}

//---------------------------------------------------------------
// insertionSort(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged into sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

void insertionSort(int data[], int size) {
    int i, j, tmp;
    unsigned long int swaps = 0;
    unsigned long int comps = 0;
    
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j > 0; j--) {
            comps++;
            if (data[j] < data[j - 1]) {
                swaps++;
                tmp = data[j];
                data[j] = data[j - 1];
                data [j - 1] = tmp;
            }
            else break;
        }
    }
    cout << "Total swaps: " << swaps << ", Total comparisons: " << comps << endl;
}

//---------------------------------------------------------------
// selectionSort(int[], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged in sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

void selectionSort(int data[], int size) {
    int i, j, tmp, least;
    unsigned long int swaps = 0;
    unsigned long int comps = 0;
    for (i = 0; i < size; i++) {
        least = i;
        for (j = i + 1; j < size; j++) {
            comps++;
            if (data[j] < data[least]) {
                least = j;
            }
        }
        if (least != i) {
            swaps++;
            tmp = data[least];
            data[least] = data[i];
            data[i] = tmp;
        }
    }
    cout << "Total swaps: " << swaps << ", Total comparisons: " << comps << endl;
}
