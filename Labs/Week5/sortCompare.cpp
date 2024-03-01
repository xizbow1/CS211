//---------------------------------------------------------------
// CS 211 - Data Structures - Spring 2024 - Week 05 Lab Exercise
// A quick look at several sorting algorithms
// Inserstion Sort, Selection Sort, Bubble Sort
// Merge Sort, Quicksort
//
// by David C. Tuttle - Last modified 16 Feb 2023
//---------------------------------------------------------------

// Blake Culbertson, Jaztin Marasigan, Ryan Dube

#include <cstdlib>
#include <iostream>

using namespace std;

// GLOBAL SCOPE variables to keep stats

unsigned long long int comps, moves, calls;

// Helper function swap
// Swaps two int values (using pass by reference)

void swap(int& a, int& b) {
    // A swap "costs" three moves - count them here!
    moves += 3;
    int temp = a;
    a = b;
    b = temp;
}

// Helper function sortConfirm
// Expects an array and its size
// Returns true if the array is sorted, false otherwise
// Useful for debugging the code below :-)
// DON'T COUNT THESE COMPARISONS!  This is just for
// verification, not for the actual sorting itself
// (In other words, I wrote this for debugging :-)

bool sortConfirm(int array[], int size) {
    bool isSorted = true;

    for (int i=0; i<size-1; i++)
        if (array[i] > array[i+1])
            isSorted = false;

    return isSorted;
}

// Helper function sortReport
// Expects an array, its size, and string describing sort type
// Returns nothing
// Side effect: confirms sort and prints sort stats to the screen

void sortReport(int array[], int size, string sortType) {
    if (! sortConfirm(array, size)) {
        cout << "*** " << sortType << " SORT ERROR ***" << endl;
    }

    cout << sortType << " SORT REPORT: "
         << comps << " comps, " << moves << " moves, "
         << calls << " calls" << endl;

}

//*********************************************************************
//*** BUBBLE SORT
//*********************************************************************

//---------------------------------------------------------------
// bubbleSort(int [], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged in sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

void bubbleSort(int array[], int size) {
    comps = moves = calls = 0;
    bool hasSwapped;

    for (int i=size; i>0; i--) {
        hasSwapped = false;
        for (int j=0; j<i-1; j++) {
            comps++;
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
                hasSwapped = true;
         }
      }
      if (hasSwapped == false)
          break;
   }

    sortReport(array, size, "BUBBLE");
}

//*********************************************************************
//*** INSERTION SORT
//*********************************************************************

//---------------------------------------------------------------
// insertionSort(int [], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged in sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

void insertionSort(int array[], int size) {;
    comps = moves = calls = 0;

    for (int i=0; i<size-1; i++) {
        for (int j=i+1; j>0; j--) {
            comps++;
            if (array[j] < array[j-1]) {
                swap(array[j-1], array[j]);
            }
            else break;
        }
    }

    sortReport(array, size, "INSERTION");
}

//*********************************************************************
//*** SELECTION SORT
//*********************************************************************

//---------------------------------------------------------------
// selectionSort(int [], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged in sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

void selectionSort(int array[], int size) {
    comps = moves = calls = 0;
    int least;

    for (int i=0; i<size; i++) {
        least = i;
        for (int j=i+1; j<size; j++) {
            comps++;
            if (array[j] < array[least]) {
                least = j;
            }
        }
        if (i != least) {
            swap(array[i], array[least]);
        }
    }

    sortReport(array, size, "SELECTION");
}

//*********************************************************************
//*** MERGE SORT
//*********************************************************************

// Helper function mergeSortedArrays
// Merge two sorted parts of an array to maintain sorted property

void mergeSortedArrays(int array[], int left, int mid, int right) {

    // NOTE: array[mid] will be part of the left half
    int sizeLeftArray = mid - left + 1;  // Size of left half
    int sizeRightArray = right - mid;    // Size of right half

    // Create temporary storage to hold left and right halves
    int *leftArray = new int[sizeLeftArray];
    int *rightArray = new int[sizeRightArray];

    // Copy data from array[] into leftArray[] and rightArray[]
    // This way, when we merge, we can copy sorted data back into array[]

    for (int i = 0; i < sizeLeftArray; i++) {
        leftArray[i] = array[left+i];
    }
    for (int i = 0; i < sizeRightArray; i++) {
        rightArray[i] = array[mid+1+i];
    }

    int indexOfLeftArray = 0;      // Initial relative index in left array
    int indexOfRightArray = 0;     // Initial relative index in right array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfLeftArray < sizeLeftArray &&
           indexOfRightArray < sizeRightArray) {

        // If smaller value is in left array, copy it to array[]
        comps++;
        if (leftArray[indexOfLeftArray] <= rightArray[indexOfRightArray]) {
            array[indexOfMergedArray] = leftArray[indexOfLeftArray];
	        indexOfLeftArray++;
    	}

        // If smaller value is in right array, copy it to array[]
    	else {
            array[indexOfMergedArray] = rightArray[indexOfRightArray];
            indexOfRightArray++;
    	}

        indexOfMergedArray++;
    }

    // At this point, one of the arrays (either left or right) is done
    // Copy the remaining elements of whichever array is not done yet

    while (indexOfLeftArray < sizeLeftArray) {
        array[indexOfMergedArray] = leftArray[indexOfLeftArray];
	    indexOfLeftArray++;
	    indexOfMergedArray++;
    }

    while (indexOfRightArray < sizeRightArray) {
        array[indexOfMergedArray] = rightArray[indexOfRightArray];
    	indexOfRightArray++;
	    indexOfMergedArray++;
    }
}

// Helper function mergeSortRecursive
// Sort left half, Sort right half, Merge the two halves
// For each call, begin and end define which part of the array to sort

void mergeSortRecursive(int array[], int begin, int end) {

    calls++;

    // Base case - just return, nothing to be sorted here!
    if (begin >= end)
        return;

    // Find index of midway point between begin and end

    int mid = begin + (end - begin) / 2;

    // Recursively sort left half of array
    moves++;
    mergeSortRecursive(array, begin, mid);

    // Recursively sort right half of array
    moves++;
    mergeSortRecursive(array, mid+1, end);

    // The two halves are now sorted, so it's time to merge them!
    moves++;
    mergeSortedArrays(array, begin, mid, end);
}

//---------------------------------------------------------------
// mergeSort(int [], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged in sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

void mergeSort(int array[], int size) {
    comps = moves = calls = 0;

    mergeSortRecursive(array, 0, size-1);

    sortReport(array, size, "MERGE");
}

//*********************************************************************

// Helper function findPivot
// Given three indexes in the array, determines which is best for pivot
// Sets pivotIndex in calling statement to the appropriate index
// Calculating the number of comparisons is tricky, so it's been done
// for you :-).  It's 2 or 3 total each time findPivot is called

void findPivot(int array[], int l, int m, int r, int& pivotIndex) {
    // NOTE that if we simply used a strategy of choosing one index,
    // this function can simply set pivotIndex to one of l, m, or r
    // Uncomment the next two lines to choose the left value as pivot
    
    // pivotIndex = l;
    // return;
    
    // However, since we're employing a "best of 3" strategy,
    // we'll instead make a few comparisons to find the "best" pivot

    comps++;
    if (array[l] > array[m]) {
        comps++;
        if (array[m] > array[r]) {
            pivotIndex = m;
        }
        else if (array[l] > array[r]) {
            comps++;
            pivotIndex = r;
        }
        else {
            comps++;
            pivotIndex = l;
        }
    }
    else {
        comps++;
        if (array[l] > array[r]) {
            pivotIndex = l;
        }
        else if (array[m] > array[r]) {
            comps++;
            pivotIndex = r;
        }
        else {
            comps++;
            pivotIndex = m;
        }
    }
}

// Helper function quickSortPartition
// Chooses a pivot, performs partition, returns index where
// pivot value is when done

int quickSortPartition(int array[], int start, int end) {

    calls++;

    // Pre-condition: there are at least three elements to partition

    // We'll use a "best of 3" strategy to select a pivot value
    // using a helper function to determine which value is best
    int mid = (start + end) / 2;
    int pivotIndex;

    // Select pivot - findPivot will be set to the best index
    // and the comps will be counted in tne findPivot function
    findPivot(array, start, mid, end, pivotIndex);

    // Swap pivot value to be the first item temporarily
    // (it'll be moved back after other values are partitioned)
    swap(array[pivotIndex], array[start]);

    // Now that the pivot value is at array[start], let's partition!
    int i = start;
    for (int j=start+1; j<=end; j++) {
        comps++;
        if (array[j] < array[start]) {
            i++;
            // swap smaller value to left part
            swap(array[i], array[j]);
        }
    }

    // Now swap pivot value back into correct position
    swap(array[start], array[i]);
    return i;
}

//*********************************************************************

// Helper function quickSortRecursive
// Handle base cases, use partition function, make recursive calls
// For each call, start and end define which part of the array to sort

void quickSortRecursive(int array[], int start, int end) {

    calls++;

    // Base cases - array of size 0 or 1
    if (end - start < 1) {
        return;
    }

    // Base case - array of size 2 - swap items if needed
    comps++;
    if (end - start == 1) {
        comps++;
        if (array[end] < array[start]) {
            swap(array[start], array[end]);
        }
        return;
    }

    // Call partition to perform partitioning and return index
    // NOTE: *Not* a recursive call, so don't count it as one!

    int partitionIndex = quickSortPartition(array, start, end);

    // At this point, we have, in order, from left to right:
    //    * All values <= pivot value
    //    * The pivot value itself (at partitionIndex)
    //    * All values >= pivot value

    // Now we recursively apply this sort to those 2 partitioned parts
    // (Not including pivot value, as it doesn't need to be moved now!)

    quickSortRecursive(array, start, partitionIndex-1);
    quickSortRecursive(array, partitionIndex+1, end);

    // After these calls recurse all the way to the base cases, we're sorted!
}

//---------------------------------------------------------------
// quickSort(int [], int)
// Expects an integer array and its size
// Returns nothing
// Side Effect is array elements are arranged in sorted order
// Side Effect is output to screen number of comparisons and swaps
//---------------------------------------------------------------

void quickSort(int array[], int size) {
    comps = moves = calls = 0;

    quickSortRecursive(array, 0, size-1);

    sortReport(array, size, "QUICK");

}
