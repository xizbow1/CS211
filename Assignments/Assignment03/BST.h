//    CS 211 Spring 2024 - Programming Assignment 03
//    Binary Search Trees in C++
//
//    David C. Tuttle
//    Last Modified: 23 Mar 2023

#ifndef BST_H
#define BST_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>

using namespace std;

// Set data type of node contents
typedef int T;

/*-----
  class: BSTNode

  purpose: To create a BSTNode for use in for a binary tree
  NOTE: All code for the class is in this .h file
  Do NOT alter this class's clode in any way!

  by: David Tuttle
  last modified: 23 Mar 2023
-----*/

// Blake Culbertson

class BSTNode {
public:
    // Two constructors:
    //    BSTNode() creates an "empty" node with no value for el
    //    BSTNode() crates a node with the given el value and
    //              (optionally) two pointers to "children"
    BSTNode() { leftChild = NULL; rightChild = NULL; }
    BSTNode(T e, BSTNode *l = NULL, BSTNode *r = NULL) {
        el = e; leftChild = l; rightChild = r; }
    
    // Destructor not written - write one if you need to :-)
    // ~BSTNode();
    
    // Accessors    
    T getEl() { return el; }
    BSTNode *getLeftChild() { return leftChild; }
    BSTNode *getRightChild() { return rightChild; }
    
    // Mutators    
    void setEl(T newEl) { el = newEl; }
    void setLeftChild(BSTNode *p) { leftChild = p; }
    void setRightChild(BSTNode *p) { rightChild = p; }

    // Helpers

    
private:
    T el;
    BSTNode *leftChild;
    BSTNode *rightChild;
};

/*-----
  class: BST

  purpose: To implement a binary search tree
  using the given BSTNode class

  constructors:
           *   BST creates a new stack object
           *   isEmpty returns TRUE if the tree is empty
	   *   search returns TRUE is value is found in tree
	   *   insert places a node into tree


  by: David Tuttle
  last modified: 23 Mar 2023
-----*/

class BST {
public:
    // Constructor
    BST() {
        // Create an empty binary tree
        // The first insertion will place a Node at the root
        root = NULL;
    }
    
    // Destructor commented out (see BSTNode destructor above)
    // ~BST();

    // Accessors
    bool search(T el) const; 
    bool isLeaf(T el) const;
    BSTNode* getRoot() const;
    bool isEmpty() const;
    void breadthFirstTraversal() const;

    // Mutators
    bool insert(T el);
    bool deleteLeaf(T el);

    // *****************************************************
    // UNCOMMENT THESE AS YOU WRITE THEM!
    // *****************************************************

    void preorderTraversal() const;
    void preorderTraversal(BSTNode*) const;
    void inorderTraversal() const;
    void inorderTraversal(BSTNode*) const;
    void postorderTraversal() const;
    void postorderTraversal(BSTNode*) const;

    int countNodes() const;
    int countNodes(BSTNode*) const;
    int countLeaves() const;
    int countLeaves(BSTNode*) const;
    int countInterior() const;
    int countInterior(BSTNode*) const;
    int treeHeight() const;
    int treeHeight(BSTNode*) const;

    void deleteAllNodes();
    void deleteAllNodes(BSTNode*);
    bool deleteNode(T el);
    bool deleteNode(BSTNode*, T el);
    void leftRotation(BSTNode& gr, BSTNode& par, BSTNode& ch);
    void rightRotation(BSTNode& gr, BSTNode& par, BSTNode& ch);

    BSTNode* getSuccessor(BSTNode*);
    
private:
    BSTNode *root;
    
};

#endif /* BST_H */

