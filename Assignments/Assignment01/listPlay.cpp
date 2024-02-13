// CS211 Spring 2024 Assignment 1
// Blake Culbertson

#include <cstdlib>
#include <string>
#include <iostream>
#include "Node.h"

using namespace std;

int main(){
    int userInput;
    Node* lastNode = nullptr;
    Node* headNode = nullptr;
    cout << "Input a value to add to your linked list, or -1 to quit:" << endl;
    cin >> userInput;
    if(userInput != -1){
        headNode = new Node(userInput);
        lastNode = headNode;
    }
    while(userInput != -1){
        cin >> userInput;
        if(userInput == -1){
            break;
        }
        else{
            Node* newNode = new Node(userInput);
            lastNode->setLink(newNode);
            lastNode = newNode;
        }
    }
    cout << "The list will now be walked through, one element per line." << endl;
    Node* currNode = headNode;
    while(currNode != NULL){
        cout << currNode->getData() << endl;
        currNode = currNode->getLink();
    }
    cout << "The list will now be deleted." << endl;
    Node* nextNode = headNode;
    while(nextNode != NULL){
        currNode = nextNode;
        nextNode = currNode->getLink();
        delete currNode;
    }
    return 0;
}