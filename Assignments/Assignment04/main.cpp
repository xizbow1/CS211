
// Blake Culbertson
// CS211 Assignment 4

#include <cstdlib>
#include <string>
#include <iostream>
#include <cassert>
#include "UndirectedGraph.h"

using namespace std;

int main(){
    UndirectedGraph myGraph = UndirectedGraph(5);

    myGraph.addEdge(1, 3);
    myGraph.addEdge(4, 2);
    myGraph.addEdge(5, 3);
    assert(myGraph.edgeExists(3, 1));
    assert(!myGraph.edgeExists(3, 2));
    assert(!myGraph.edgeExists(4, 5));
    assert(myGraph.edgeExists(3, 5));
    assert(myGraph.edgeExists(4, 2));
    cout << "addEdge tests complete!" << endl;

    myGraph.removeEdge(3, 5);
    myGraph.removeEdge(4, 2);
    assert(!myGraph.edgeExists(5, 3));
    assert(!myGraph.edgeExists(2, 4));
    cout << "removeEdge tests complete!" << endl;

    assert(myGraph.vertexCount() == 5);
    cout << "vertexCount test complete!" << endl;

    UndirectedGraph newGraph = UndirectedGraph();
    assert(!myGraph.graphConnected());
    myGraph.addEdge(1, 2);
    myGraph.addEdge(2, 4);
    myGraph.addEdge(4, 3);
    myGraph.addEdge(5, 3);
    assert(myGraph.graphConnected());
    myGraph.removeEdge(3, 5);
    assert(!myGraph.graphConnected());
    cout << "graphConnected tests complete!" << endl;
}