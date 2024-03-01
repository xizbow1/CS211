//    CS 211 Spring 2024 - Week 08 Lab
//    Hash Tables in C++
//
//    David C. Tuttle
//    Last Modified: 20 Mar 2023

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "HashTable.h"

using namespace std;

int main() {
    cout << boolalpha;
    
    // CREATE NEW HASH TABLE
    
    HashTable *myTable;
    myTable = new HashTable();
    
    int tableSize = myTable->getSize();

    // TESTS FOR HASH TABLE METHODS

    // Print the empty hash table
    
    // cout << "*** Printing the empty hash table \n";
    // myTable->printTable();    
    
    // Completely fill the hash table with pseudorandom values
    
    cout << "*** Filling the hash table \n";
    for (int i=1; i <= tableSize; i++) {
        cout << myTable->insertValue((103 * i) % 41) << " ";
    }
    cout << endl;
    
    // Print out the hash table
    
    cout << "*** Printing out the filled hash table \n";;
    myTable->printTable();
    cout << endl;
    
    // Try to enter a value into the full hash table
    
    cout << "*** Should print false: "
         << myTable->insertValue(99999) << endl;
    
    // Remove some values in the hash table
    
    cout << "*** Removing half the values in the table \n";
    for (int i=1; i <= tableSize; i += 2) {
        cout << myTable->deleteValue((103 * i) % 41) << " ";
    }
    cout << endl;
    
    // Attempt to delete a value not in the hash table
    
    cout << "*** Removing a value not in the table \n";
    
    cout << myTable->deleteValue(99998) << endl;
    
    cout << "*** Printing out the half-filled hash table \n";
    myTable->printTable();
    cout << endl;
    
    cout << "*** Inserting a few new values into the table \n";
    for (int i=1; i <= 4; i++) {
        cout << myTable->insertValue(101 * i) << " ";
    }
    cout << endl;
    
    cout << "Search for the new values and one that isn't there \n";
    for (int i=1; i <= 5; i++) {
        cout << myTable->searchValue(101 * i) << " ";
    }
    cout << endl;
    
    cout << "*** Printing out the final hash table \n";
    myTable->printTable();
    cout << endl;
    
    return EXIT_SUCCESS;
}

