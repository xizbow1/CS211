/*---
    CS 211 Spring 2024 - Assignment 02

    David C. Tuttle
    Last Modified: 08 Feb 2023
---*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "DoublyLinkedList.h"
#include "gcd.h"
#include "addCommas.h"

using namespace std;

int main() {
    cout << boolalpha;

    // UNCOMMENT the following code when you're ready to
    // run tests

    cout << endl << "*** TESTING addCommas ***" << endl;

    unsigned long long int initial_n;
    cout << "Please enter a non-negative integer value: ";
    cin >> initial_n;
    cout << "The number with commas is: ";
    addCommas(initial_n);
    cout << " \n";

    cout << endl << "*** TESTING gcd ***" << endl;

    int m,n;
    cout << "Please enter the two non-negative integer values: ";
    cin >> m >> n;
    cout << "The Greatest Common Divisor is: " << gcd(m, n);
    cout << " \n";


    cout << "*** TESTING Class DoublyLinkedList ***" << endl;
    double el;   // Place to hold a node's value

    cout << "Simple DLL Demonstration\n";
    cout << "Creating a DLL\n";

    DoublyLinkedList *theDLL = new DoublyLinkedList(); // Create a DLL object

    cout << "DLL created...\n";

    // Test Insert and Delete methods

    el = 100;
    cout << "Inserting value " << el << " at end of DLL\n";
    theDLL->addToDLLTail(el);
    el = 200;
    cout << "Inserting value " << el << " at end of DLL\n";
    theDLL->addToDLLTail(el);
    el = 300;
    cout << "Inserting value " << el << " at end of DLL\n";
    theDLL->addToDLLTail(el);
    el = 400;
    cout << "Inserting value " << el << " at end of DLL\n";
    theDLL->addToDLLTail(el);
    el = 500;
    cout << "Inserting value " << el << " at end of DLL\n";
    theDLL->addToDLLTail(el);

    cout << "Deleting from tail of DLL \n";
    el = theDLL->deleteFromDLLTail();
    cout << "Got back value " << el << "\n";
    cout << "Deleting from tail of DLL \n";
    el = theDLL->deleteFromDLLTail();
    cout << "Got back value " << el << "\n";

    // Insert inputted numbers into the DLL
    cout << "Enter the first number (-1 stops input): ";
    cin >> el;
    while (el != -1)
    {
        theDLL->addToDLLTail(el);
        cout << "Enter the next number (-1 stops input): ";
        cin >> el;
    }

    // Delete DLLNodes and print their values
    cout << "Time to delete some DLLNodes!  \n";
    el = theDLL->deleteFromDLLTail();
    cout << "Deleted " << el << " from DLL \n";
    el = theDLL->deleteFromDLLTail();
    cout << "Deleted " << el << " from DLL \n";
    el = theDLL->deleteFromDLLTail();
    cout << "Deleted " << el << " from DLL \n";

    // UNCOMMENT the following code when you're ready to
    // run tests

    cout << endl
         << "*** TESTING addToDLLHead, deleteFromDLLHead ***"
         << endl;

    el = 1000;
    cout << "Inserting value " << el << " at head of DLL\n";
    theDLL->addToDLLHead(el);
    el = 2000;
    cout << "Inserting value " << el << " at head of DLL\n";
    theDLL->addToDLLHead(el);
    el = 3000;
    cout << "Inserting value " << el << " at head of DLL\n";
    theDLL->addToDLLHead(el);

    // Delete DLLNodes from head and print their values
    cout << "Time to delete some DLLNodes!  \n";
    el = theDLL->deleteFromDLLHead();
    cout << "Deleted " << el << " from DLL \n";
    el = theDLL->deleteFromDLLHead();
    cout << "Deleted " << el << " from DLL \n";
    el = theDLL->deleteFromDLLHead();
    cout << "Deleted " << el << " from DLL \n";


    cout << "...done.\n";

    return EXIT_SUCCESS;
}