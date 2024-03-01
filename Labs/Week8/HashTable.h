//  class: HashTable
//
//  purpose: To implement a hash table of int values

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

// We'll set a typedef statement here
// The type T represents the data type stored in the hash table
// For the data type stored in the hash table buckets,
// it'd be great if you used T instead of int in your code :-)

typedef unsigned int T;

using namespace std;

class HashTable {
public:

    // For the zero-argument constructor, use this
    // constant for the size of the table

    const int DEFAULT_TABLE_SIZE = 17;

    // Value to initialize the empty buckets

    const unsigned int EMPTY_VALUE = 0;

    // Constructors
    //    Create an "empty" hash table and
    //    initialize its values

    HashTable();
    HashTable(int table_size);

    // Destructor
    ~HashTable();

    // Accessors
    int getSize() const;
    bool searchValue(T value);
    void printTable() const;

    // Mutators
    bool insertValue(T value);
    bool deleteValue(T value);

private:
    int hashFunc(T value) const;
    void nextIndex(T& index);
    bool bucketAvailable(int index) const;

    T tableSize;   // size of hash table
    T* tableValues;  // pointer to array
    bool* isDeleted; // pointer to array
};

#endif /* HASHTABLE_H */

