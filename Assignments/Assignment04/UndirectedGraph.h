
// Blake Culbertson
// CS211 Assignment 4

#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define DEFAULTSIZE 5

class UndirectedGraph {
    public:
        UndirectedGraph();
        UndirectedGraph(int);
        int vertexCount();
        bool edgeExists(int, int);
        bool addEdge(int, int);
        bool removeEdge(int, int);
        bool graphConnected();
    private:
        vector<vector<bool>> graph;
};

#endif