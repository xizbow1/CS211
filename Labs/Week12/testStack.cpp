/*---
    CS 211 Spring 2024 - Week 12 Lab

    Written by: David C. Tuttle
    Last Modified: 03 Oct 2022
---*/

// Blake Culbertson, Dylan Westigard, Orlando Trujillo-Ortiz

//---------------------------------------------------------------
// File: testStack.cpp
// Purpose: Main file with tests for a demonstration of an unsorted  
//          stack implemented as an array.
//
// Adapted from code written and posted by Dr. Rick Coleman,
//          University of Alabama-Huntsville, 2002
//---------------------------------------------------------------


#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "ArrayStack.h"

using namespace std;

int main() {
    cout << boolalpha;
    
    // generic variable to hold an index value as needed
    int i;
    // "el" is short for "element" - a place to store pushed or popped value
    T el;

    cout << "Simple Stack Demonstration\n";
    cout << "(Stack implemented as Array - Element data type is double.)\n\n";
    cout << "Creating a stack\n";

    ArrayStack *theStack = new ArrayStack(); // Create a stack object

    cout << "Stack created...\n";

    // Test pushing and popping a single item on the stack

    el = 100.0;
    cout << "Testing push and pop of single item.\n";
    cout << "Pushing a single double value of " << el << "\n";
    theStack->push(el);
    cout << "Popped: " << theStack->pop() << "\n";
    cout << "...done\n\n";
    
    // Let's try popping a value off an empty stack
    
    cout << "Testing pop of an empty stack.  Should print -99999\n";
    cout << "Popped: " << theStack->pop() << "\n";
    cout << "...done\n\n";

    // Test stack by reversing the order of numbers pushed onto stack
    cout << "Enter a list of numbers to be reversed (-1 to end):\n\n";

    // Push numbers on the stack
    i = 0;
    cout << "Enter the first number: ";
    cin >> el;
    while (el != -1 && i < CAPACITY) {
        theStack->push(el);
        i++;
        
        if (i == CAPACITY) {
	        cout << "Your stack is full!\n";
        }
        else {
            cout << "Enter the next number: ";
            cin >> el;
        }
    }

    // Pop letters and print in reverse
    cout << "Your numbers printed in reverse is...\n";
    while(theStack->isEmpty() == false) {
        el = theStack->pop();
        cout << el << " ";
    }

    cout << "\n\n...done.\n";

    cout << "Testing clearStack function...";
    theStack->clearStack();
    assert(theStack->getSize() == 0);
    cout << "Success!" << endl << endl;

    cout << "Deleting the stack...";
    delete theStack;
    cout << "Success!" << endl;

    cout << "Testing = operator...";
    ArrayStack * newStack = new ArrayStack();
    newStack = theStack;
    assert(newStack->getSize() == theStack->getSize());
    cout << "Success!" << endl;

    return EXIT_SUCCESS;
}