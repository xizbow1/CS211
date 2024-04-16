/*
 * File:   ArrayStack.h
 * Author: David
 *
 * Modified on 13 Oct 2021
 */

 // Blake Culbertson, Dylan Westigard, Orlando Trujillo-Ortiz


#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

/*-----
  class: ArrayStack

  purpose: To implement a Stack object using a C++ array

  constructors: has 4 methods:
           *   ArrayStack is a constructor for a new stack object
           *   clearStack resets a stack object to an empty state
           *   isEmpty returns TRUE if the stack is empty
           *   isFull returns TRUE is the stack has reached capacity
                   as defined by MAX_SIZE

  getters: pop - removes topmost item from the stack and returns its value

  setters: push - expects a value of type double,
                     returns a Boolean indicating success or faiure,
                     and has the side-effect of inserting the value
                     at the top of the stack

  by: David Tuttle
  last modified: 13 Oct 2021
  Adapted from code written and posted by Dr. Rick Coleman,
          University of Alabama-Huntsville, 2002
-----*/



#include <iostream>
#include <vector>
using namespace std;

#define CAPACITY 10         // Maximum items the stack can hold
#define ERROR_VALUE -99999  // Value to return if pop operation fails

typedef double T;

class ArrayStack {
public:
    ArrayStack();             // Class constructor
    void clearStack();        // Remove all items from the stack
    bool isEmpty();           // Return true if stack is empty
    bool isFull();            // Return true if stack is full

    bool push(T el);     // Push an item onto the stack,
    T pop();             // Pop an item from the stack

    int getSize();
    ~ArrayStack();

    void operator=(ArrayStack & other);


private:                  // Index to top of stack
    vector<T> theStack;       // The stack itself
    int stackSize;
    

};

#endif /* ARRAYSTACK_H */

