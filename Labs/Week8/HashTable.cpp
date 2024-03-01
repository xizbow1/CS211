
//----------------------------------------------------
// File: HashTable.cpp
// Purpose: Implementation file for a hash table class
//----------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "HashTable.h"

using namespace std;

//--------------------------------------------
// Constructors
//--------------------------------------------

HashTable::HashTable() {
    tableSize = DEFAULT_TABLE_SIZE;
    tableValues = new T[DEFAULT_TABLE_SIZE]{EMPTY_VALUE};
    isDeleted = new bool[DEFAULT_TABLE_SIZE]{false};
}

HashTable::HashTable(int size) {
    tableSize = size;
    tableValues = new T[size]{EMPTY_VALUE};
    isDeleted = new bool[size]{false};
}

//--------------------------------------------
// Destructor
//--------------------------------------------

HashTable::~HashTable() {
    // INSERT CODE HERE
    delete tableValues;
}

//--------------------------------------------
// Accessors
//--------------------------------------------

//--------------------------------------------
// Function: getSize()
// Purpose: get the size of the Hash Table
// Returns: size of table
//--------------------------------------------

int HashTable::getSize() const {
    return tableSize;
}

//--------------------------------------------
// Function: searchValue(int value)
// Purpose: searchs for a value in the hash table
// Returns: true is value is found
//--------------------------------------------

bool HashTable::searchValue(T value) {
    T attemptedIndex = hashFunc(value);
    T startingIndex = attemptedIndex;
    while(!(tableValues[attemptedIndex] == value && isDeleted[attemptedIndex] == false)){
        nextIndex(attemptedIndex);
        if(attemptedIndex == startingIndex){
            return false;
        }
    }
    return true;
}

//--------------------------------------------
// Function: printTable()
// Purpose: prints the contents of the hash table
// Returns: nothing
//--------------------------------------------

void HashTable::printTable() const {
    cout << "Table size = " << tableSize;
    cout << ", contents = ";
    if(tableSize == 0){
        return;
    }
    for(T i = 0; i < tableSize; i++){
        if(tableValues[i] == 0 || isDeleted[i] == true){
            cout << "X ";
        } else {
            cout << tableValues[i] << " ";
        }
    }
}

//--------------------------------------------
// Mutators
//--------------------------------------------

//--------------------------------------------
// Function: insertValue(int value)
// Purpose: insert a value into the hash table
// Returns: true if successful insert
//--------------------------------------------

bool HashTable::insertValue(T value) {
    T attemptedIndex = hashFunc(value);
    T startingValue = attemptedIndex;
    if (value == EMPTY_VALUE) {
        cout << "*** CANNOT INSERT EMPTY_VAL VALUE! ***\n";
        return false;
    } else {
        while(!(tableValues[attemptedIndex] == 0 && isDeleted[attemptedIndex] == false)){
            nextIndex(attemptedIndex);
            if(attemptedIndex == startingValue){
                return false;
            }
        }
    }
    tableValues[attemptedIndex] = value;
    return true;
}

//--------------------------------------------
// Function: deleteValue(int value)
// Purpose: delete a value from the hash table
// Returns: true if successful deletion
//--------------------------------------------

bool HashTable::deleteValue(T value) {
    T attemptedIndex = hashFunc(value);
    T startingValue = attemptedIndex;
    while(!(tableValues[attemptedIndex] == value && isDeleted[attemptedIndex] == false)){
        nextIndex(attemptedIndex);
        if(startingValue == attemptedIndex){
            return false;
        }
    }
    isDeleted[hashFunc(value)] = true;
    return true;
}

//--------------------------------------------
// Private method hashFunc
//--------------------------------------------

int HashTable::hashFunc(T value) const{
    return (value * value) % tableSize;
}

//--------------------------------------------
// Private method nextIndex - get index of next bucket
//--------------------------------------------

void HashTable::nextIndex(T& index) {
    // NOTE - this is a method that will mutate the value
    // of the argument sent to it!
    
    // To update the value of a variable to the next
    // index, simply use the statement:
    
    //      myTable->nextIndex(index_variable);
    
    // where index_variable is your local variable for
    // the index in the table.
    
    // Putting this method here allows the programmer
    // to change the probing sequence by just changing
    // this method!
    
    // If we reached end of table, wrap around to 0
    if (index ==  tableSize - 1)
        index = 0;
    else
        index++;
}

//--------------------------------------------
// Private method bucketAvailable
//--------------------------------------------

bool HashTable::bucketAvailable(int index) const {
    // This function returns true if a bucket is available to
    // be filled during an insert.  Do NOT use for search or
    // deletion!
    // If the bucket contains EMPTY_VALUE, it's never been used
    // If the isDeleted is true, then it's available
    return (tableValues[index] == EMPTY_VALUE) || isDeleted[index];
}

