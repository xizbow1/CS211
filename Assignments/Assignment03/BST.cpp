//    CS 211 Spring 2024 - Programming Assignment 03
//    Binary Search Trees in C++
//
//    David C. Tuttle
//    Last Modified: 23 Mar 2023

//----------------------------------------------------
// File: BST.cpp
// Purpose: Implementation file for a demonstration
// of a basic binary tree
//
//----------------------------------------------------

// Blake Culbertson

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
#include "BST.h"

using namespace std;

//--------------------------------------------
// Function: insert(T)
// Purpose: insert a node into a binary tree
// Returns: void
//--------------------------------------------

bool BST::insert(T el) {
    // Pointers to keep track of where we are in descending
    // through the tree to find an insertion point
    BSTNode *p = root;
    BSTNode *prev = NULL;
    T currVal;

    // If tree is empty, then insert the first node

    if (this->isEmpty()) {
        root = new BSTNode(el);
        return true;
    }

    // Descend the tree for a proper place to put the input value
    // The input value will become a new leaf on the tree
    // NOTE: This does NOT perform any tree balancing!

    while (p != NULL) {
        // prev remembers where we were, so when ptr becomes
        // NULL, prev will point to the node where we will
        // attach the new value as a child
        prev = p;

        // Descend the tree until we hit a leaf - go left if value
        // is less than current node, go right if greater
        currVal = p->getEl();
        if (el < currVal)
            p = p->getLeftChild();
        else if (el > currVal)
            p = p->getRightChild();
        else {
            // If the value matches one already in the tree, we
            // DON'T add it to the tree and simply return
            cout << "Value NOT inserted - already in the tree! \n";
            return false;
        }
    }

    // If we get here, we've found the place to attach the new node
    // Create the new node and attach it to the node that prev
    // is pointing to

    if (el < prev->getEl()) {
        prev->setLeftChild(new BSTNode(el));
    }
    else {
        prev->setRightChild(new BSTNode(el));
    }
    return true;
}

//--------------------------------------------
// Function: isEmpty()
// Purpose: determine whether a BST has no nodes
// Returns: a boolean - true if empty
//--------------------------------------------

bool BST::isEmpty() const {
    return (root == NULL);
}

//--------------------------------------------
// Function: search(T)
// Purpose: search for a value in a binary tree
// Returns: a boolean - true is found, false if not
//--------------------------------------------

bool BST::search(int el) const {

    // Set ptr to root of tree (if tree is empty, ptr becomes NULL)
    BSTNode *p = root;
    T currVal;

    // Descend the tree to search for the given input value
    while (p != NULL) {

        // Descend the tree until we find a node with the given value
        // If we hit a leaf before finding the value, it's not in the tree
        currVal = p->getEl();
        if (el < currVal)
            p = p->getLeftChild();
        else if (el > currVal)
            p = p->getRightChild();
        else
            // Value found!  Return true
            return true;
    }

    // If we reach this point, then we fell out of the search loop
    // without finding anything.  Return false
    return false;
}

//--------------------------------------------
// Function: isLeaf(T)
// Purpose: search for a value in a leaf of a
// binary tree
// Returns: a boolean - true is found, false if not
//--------------------------------------------

bool BST::isLeaf(int el) const {

    // Set ptr to root of tree (if tree is empty, ptr becomes NULL)
    BSTNode *p = root;
    T currVal;

    // Descend the tree to search for the given input value
    while (p != NULL) {

        // Descend the tree until we find a node with the given value
        // If we hit a leaf before finding the value, it's not in the tree
        currVal = p->getEl();
        if (el < currVal)
            p = p->getLeftChild();
        else if (el > currVal)
            p = p->getRightChild();
        // if el == currVal, then we found the value!
        // If it's a leaf, return true, else return false
        else if (p->getLeftChild() == NULL &&
                 p->getRightChild() == NULL)
            return true;
        else
            return false;
    }

    // If we reach this point, then we fell out of the search loop
    // without finding the value at all.  This means it wasn't in the
    // tree, so we return false
    return false;
}

//--------------------------------------------
// Function: deleteLeaf(T)
// Purpose: delete node from tree if it's a leaf
// Returns: a boolean - true is deleted, false if not
//--------------------------------------------
bool BST::deleteLeaf(int el) {

    // Set ptr to root of tree (if tree is empty, ptr becomes NULL)
    // Also keep track of the previous (parent) node of the current node
    BSTNode *p = root;
    BSTNode *prev = NULL;
    T currVal;

    // Descend the tree to search for the given input value
    while (p != NULL) {
        // Descend the tree until we find a node with the given value
        // If we hit a leaf before finding the value, it's not in the tree
        currVal = p->getEl();
        if (el < currVal) {
            prev = p;
            p = p->getLeftChild();
        }
        else if (el > currVal) {
            prev = p;
            p = p->getRightChild();
        }
        // If el == currVal, then we found the value!
        // If it's a leaf, we can delete node and return true
        else if (isLeaf(el)) {
            // FIRST, check: is this the only node in the tree?
            // If so, we have to handle this special case!
            if (prev == NULL)
                root = NULL;
            // Don't forget to reset pointer on parent node!
            // But which way did we go to get here?
            else if (currVal < prev->getEl())
                // current node is the left child of prev
                prev->setLeftChild(NULL);
            else
                // current node is the right child of prev
                prev->setRightChild(NULL);
            // We've "chopped" the leaf off the tree - OK to delete
            delete p;
            return true;
        }
        else {
            // We found the value, but it's not a leaf, so it stays
            return false;
        }
    }

    // If we reach this point, then we fell out of the search loop
    // without finding the value at all.  This means it wasn't in the
    // tree, so we return false
    return false;
}

// An accessor method to get the BST's root pointer

BSTNode* BST::getRoot() const {
    return root;
}

//--------------------------------------------
// Function: breadthFirstTraversal()
// Purpose: Expects nothing, returns nothing
// Side Effects: prints values in breadth-first order
//--------------------------------------------

void BST::breadthFirstTraversal() const {
    const int QUEUE_SIZE = 50;
    BSTNode *queue[QUEUE_SIZE];
    int headIndex = 0;
    int tailIndex = 0;

    if (root == NULL) {
        cout << "*** Tree is empty ***" << endl;
        return;
    }

    queue[tailIndex] = root;

    while (headIndex != tailIndex + 1) {
        if (queue[headIndex]->getLeftChild() != NULL) {
           tailIndex = (tailIndex + 1) % QUEUE_SIZE;
           queue[tailIndex] = queue[headIndex]->getLeftChild();
        }
        if (queue[headIndex]->getRightChild() != NULL) {
           tailIndex = (tailIndex + 1) % QUEUE_SIZE;
           queue[tailIndex] = queue[headIndex]->getRightChild();
        }
        cout << queue[headIndex]->getEl() << " ";
        headIndex = (headIndex + 1) % QUEUE_SIZE;
    }
    cout << endl;
    return;
}

// **********************************************************
// ADD NEW METHODS HERE
// **********************************************************

void BST::preorderTraversal() const {
    if(root == NULL){
        cout << "Tree is empty!" << endl;
        return;
    }
    preorderTraversal(root);
    cout << endl;
}

void BST::preorderTraversal(BSTNode* node) const {
    if (node == NULL) {
        return;
    }

    // Visit the root node (current node)
    cout << node->getEl() << " ";

    // Recurse on the left subtree
    preorderTraversal(node->getLeftChild());

    // Recurse on the right subtree
    preorderTraversal(node->getRightChild());
}

void BST::inorderTraversal() const {
    if(root == NULL){
        cout << "Tree is empty!" << endl;
        return;
    }
    inorderTraversal(root);
    cout << endl;
}

void BST::inorderTraversal(BSTNode* node) const {
    if (node == NULL) {
        return;
    }

    // Recurse on the left subtree
    inorderTraversal(node->getLeftChild());

    // Visit the root node (current node)
    cout << node->getEl() << " ";

    // Recurse on the right subtree
    inorderTraversal(node->getRightChild());
}

void BST::postorderTraversal() const {
    if(root == NULL){
        cout << "Tree is empty!" << endl;
        return;
    }
    postorderTraversal(root);
    cout << endl;
}

void BST::postorderTraversal(BSTNode* node) const {
    if (node == NULL) {
        return;
    }

    // Recurse on the left subtree
    postorderTraversal(node->getLeftChild());

    // Recurse on the right subtree
    postorderTraversal(node->getRightChild());

    // Visit the root node (current node)
    cout << node->getEl() << " ";
}

int BST::countNodes() const {
    return countNodes(root);
}

int BST::countNodes(BSTNode* node) const {
    if (node == NULL) {
        return 0;
    }

    // Count the current node
    int count = 1;

    // Recurse on the left subtree
    count += countNodes(node->getLeftChild());

    // Recurse on the right subtree
    count += countNodes(node->getRightChild());

    return count;
}

int BST::countLeaves() const {
    return countLeaves(root);
}

int BST::countLeaves(BSTNode* node) const {
    if (node == NULL) {
        return 0;
    }

    // If the current node is a leaf, return 1
    if (node->getLeftChild() == NULL && node->getRightChild() == NULL) {
        return 1;
    }

    // Recurse on the left subtree
    int count = countLeaves(node->getLeftChild());

    // Recurse on the right subtree
    count += countLeaves(node->getRightChild());

    return count;
}

int BST::countInterior() const {
    return countInterior(root);
}

int BST::countInterior(BSTNode* node) const {
    if (node == NULL) {
        return 0;
    }

    // If the current node is a leaf, return 0
    if (node->getLeftChild() == NULL && node->getRightChild() == NULL) {
        return 0;
    }

    // Count the current node
    int count = 1;

    // Recurse on the left subtree
    count += countInterior(node->getLeftChild());

    // Recurse on the right subtree
    count += countInterior(node->getRightChild());

    return count;
}

int BST::treeHeight() const {
    return treeHeight(root);
}

int BST::treeHeight(BSTNode* node) const {
    if (node == NULL) {
        return -1;
    }

    // Recurse on the left subtree
    int leftHeight = treeHeight(node->getLeftChild());

    // Recurse on the right subtree
    int rightHeight = treeHeight(node->getRightChild());

    // Return the height of the tree
    return 1 + max(leftHeight, rightHeight);
}

void BST::deleteAllNodes() {
    deleteAllNodes(root);
    root = NULL;
}

void BST::deleteAllNodes(BSTNode* node) {
    if (node == NULL) {
        return;
    }

    // Recurse on the left subtree
    deleteAllNodes(node->getLeftChild());

    // Recurse on the right subtree
    deleteAllNodes(node->getRightChild());

    // Delete the current node
    delete node;
}

bool BST::deleteNode(T el) {
    BSTNode* parent = nullptr;
    BSTNode* current = root;

    // Search for the node to delete
    while (current != nullptr && current->getEl() != el) {
        parent = current;
        if (el < current->getEl())
            current = current->getLeftChild();
        else
            current = current->getRightChild();
    }

    // If node not found, return false
    if (current == nullptr)
        return false;

    // Case 1: Node to delete is a leaf
    if (current->getLeftChild() == nullptr && current->getRightChild() == nullptr) {
        if (current == root)
            root = nullptr;
        else if (parent->getLeftChild() == current)
            parent->setLeftChild(nullptr);
        else
            parent->setRightChild(nullptr);
        delete current;
    }
    // Case 2: Node to delete has only one child
    else if (current->getLeftChild() == nullptr) {
        if (current == root)
            root = current->getRightChild();
        else if (parent->getLeftChild() == current)
            parent->setLeftChild(current->getRightChild());
        else
            parent->setRightChild(current->getRightChild());
        delete current;
    } else if (current->getRightChild() == nullptr) {
        if (current == root)
            root = current->getLeftChild();
        else if (parent->getLeftChild() == current)
            parent->setLeftChild(current->getLeftChild());
        else
            parent->setRightChild(current->getLeftChild());
        delete current;
    }
    // Case 3: Node to delete has two children
    else {
        BSTNode* successorParent = current;
        BSTNode* successor = current->getRightChild();
        while (successor->getLeftChild() != nullptr) {
            successorParent = successor;
            successor = successor->getLeftChild();
        }

        // Replace current with its successor
        current->setEl(successor->getEl());

        // Delete the successor node
        if (successorParent->getLeftChild() == successor)
            successorParent->setLeftChild(successor->getRightChild());
        else
            successorParent->setRightChild(successor->getRightChild());
        delete successor;
    }

    return true;
}

BSTNode* BST::getSuccessor(BSTNode* node) {
    BSTNode* current = node->getRightChild();
    while (current->getLeftChild() != NULL) {
        current = current->getLeftChild();
    }
    return current;
}

void BST::leftRotation(BSTNode& gr, BSTNode& par, BSTNode& ch) {
    if ((gr.getLeftChild() != &par && gr.getRightChild() != &par) || par.getRightChild() != &ch) {
        std::cout << "Error: Invalid nodes for left rotation" << std::endl;
        return;
    }

    // If the grandparent is the root of the tree
    if (gr.getEl() == root->getEl()) {
        root = &ch;
    }
    // If the grandparent is the left child of the great-grandparent
    else if (gr.getEl() < gr.getEl()) {
        gr.setLeftChild(&ch);
    }
    // If the grandparent is the right child of the great-grandparent
    else {
        gr.setRightChild(&ch);
    }

    par.setRightChild(ch.getLeftChild());
    ch.setLeftChild(&par);
}

void BST::rightRotation(BSTNode& gr, BSTNode& par, BSTNode& ch) {
    if ((gr.getLeftChild() != &par && gr.getRightChild() != &par) || par.getLeftChild() != &ch) {
        std::cout << "Error: Invalid nodes for right rotation" << std::endl;
        return;
    }

    // If the grandparent is the root of the tree
    if (gr.getEl() == root->getEl()) {
        root = &ch;
    }
    // If the grandparent is the left child of the great-grandparent
    else if (gr.getEl() < gr.getEl()) {
        gr.setLeftChild(&ch);
    }
    // If the grandparent is the right child of the great-grandparent
    else {
        gr.setRightChild(&ch);
    }

    par.setLeftChild(ch.getRightChild());
    ch.setRightChild(&par);
}
