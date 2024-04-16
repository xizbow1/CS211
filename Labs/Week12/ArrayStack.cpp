//---------------------------------------------------------------
// File: ArrayStack.cpp
// Purpose: Implementation file for a demonstration of a stack  
//          implemented as an array.    Data type: Double
//
// Modified by David C. Tuttle on 03 Oct 2022
//
// Adapted from code written and posted by Dr. Rick Coleman,
//          University of Alabama-Huntsville, 2002
//---------------------------------------------------------------

// Blake Culbertson, Dylan Westigard, Orlando Trujillo-Ortiz

#include "ArrayStack.h"

//--------------------------------------------
// Function: ArrayStack()
// Purpose: Class constructor
// Returns: void
//--------------------------------------------

ArrayStack::ArrayStack() {
    // top is the index of the array where the top
    // of the stack is; a value of -1 means the
    // stack is empty
    stackSize = 0;
    theStack.reserve(CAPACITY);
}

//--------------------------------------------
// Function: clearStack()
// Purpose: Remove all items from the stack
// Returns: void
//--------------------------------------------

void ArrayStack::clearStack() {
    theStack.clear(); 
    theStack.reserve(CAPACITY);
    stackSize = 0;
}

//--------------------------------------------
// Function: push()
// Purpose: Push an item onto the stack.
// Returns: true if push was successful
//          or false if the push failed.
//--------------------------------------------

bool ArrayStack::push(T el) {
    theStack.push_back(el);
    stackSize++;
    return true;
}

//--------------------------------------------
// Function: pop()
// Purpose: Pop an item from the Stack.
// Returns: value of item popped if pop was successful
//  or -99999.0 if the pop failed (stack empty)
//--------------------------------------------

T ArrayStack::pop() {
    if(stackSize == 0){
        return -99999;
    }
    T temp = theStack.back();   
    theStack.pop_back();
    stackSize--;
    return temp;
}

//--------------------------------------------
// Function: isEmpty()
// Purpose: Return true if the stack is empty
// Returns: true if empty, otherwise false
//--------------------------------------------

bool ArrayStack::isEmpty() {
    // top value is -1 if the stack is empty
    return (stackSize == 0);
}

//--------------------------------------------
// Function: isFull()
// Purpose: Return true if the stack is full
// Returns: true if full, otherwise false
//--------------------------------------------

bool ArrayStack::isFull() {
    return false;
}

int ArrayStack::getSize() {
    return stackSize;
}

ArrayStack::~ArrayStack(){
}

void ArrayStack::operator=(ArrayStack & other){
    this->theStack = other.theStack;
    this->stackSize = other.getSize();
}