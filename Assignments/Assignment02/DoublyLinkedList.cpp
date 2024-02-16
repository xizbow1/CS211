//---------------------------------------------------------------
// File: DoublyLinkedList.cpp
// Purpose: Implementation file for a doubly-linked list
//          Element type: Double
//
// Last modified by David Tuttle on 08 Feb 2023
//
// Adapted from code written and posted by Dr. Rick Coleman,
//          University of Alabama-Huntsville, 2002
//---------------------------------------------------------------

#include <cstdlib>
#include "DoublyLinkedList.h"

//--------------------------------------------
// Function: DoublyLinkedList()
// Purpose: Class constructor
// Returns: void
//--------------------------------------------

DoublyLinkedList::DoublyLinkedList() {
  head = NULL;
  tail = NULL;
}

//--------------------------------------------
// Function: addToDLLTail(double)
// Purpose: Add DLLNode with double value to tail of DLL
// Returns: void
//--------------------------------------------

void DoublyLinkedList::addToDLLTail(double el) {
    if (tail != NULL) {                    // If DLL is non-empty
          tail = new DLLNode(el,0,tail);  // Allocate new DLLNode
          tail->prev->next = tail;        // Link new node to tail of DLL
    }
    else {                                // If DLL is empty
        head = new DLLNode(el);           // Allocate new DLLNode
        tail = head;                      // Node is first in the DLL, so it
                                          // is both head and tail
    }
}

//--------------------------------------------
// Function: deleteFromDLLTail()
// Purpose: Delete DLLNode from tail of DLL
// Returns: void
//--------------------------------------------

double DoublyLinkedList::deleteFromDLLTail() {
    double el = tail->info;               // Get value of node to be deleted

    if (tail == 0)
        throw("EMPTY");                   // Return an error condition

    else if (head == tail) {              // If only DLLNode in the DLL
        delete head;                      // Deallocate DLLNode
        head = 0;                         // Set both head and tail to values for
        tail = 0;                         // a DLL with no nodes
    }

    else {                                // If more than one DLLNode in DLL
        tail = tail->prev;                // Move tail to previous DLLNode
        delete tail->next;                // Deallocate DLLNode
        tail->next = 0;                   // Set next of new last DLLNode to 0
    }
    return el;                            // Return value in deleted DLLNode
}

void DoublyLinkedList::addToDLLHead(double el) {
    
    if (head != NULL) {
        DLLNode* temp = head->next;
        head = new DLLNode(el, temp, 0); 
        temp->prev = head;
    }
    else {                                
        head = new DLLNode(el);          
        tail = head;                                                 
    }
}

double DoublyLinkedList::deleteFromDLLHead() {
    double el = head->info;

    if (head == 0)
        throw("EMPTY");

    else if (head == tail) { 
        delete head;
        head = 0;
        tail = 0;
    }

    else {
        head = head->next;
        delete head->prev;
        head->prev = 0;
    }
    return el;
}