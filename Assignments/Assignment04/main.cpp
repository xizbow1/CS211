#include <cstdlib>
#include <string>
#include <iostream>
#include <cassert>
#include "UndirectedGraph.h"

using namespace std;

int main(){
    UndirectedGraph myGraph = UndirectedGraph();
    myGraph.addEdge(1, 3);
    myGraph.addEdge(2, 4);
    myGraph.addEdge(5, 3);
    assert(myGraph.edgeExists(3, 1)); // True
    assert(!myGraph.edgeExists(3, 2)); // False
    assert(!myGraph.edgeExists(4, 5)); // False
    assert(myGraph.edgeExists(3, 5)); // True
    assert(myGraph.edgeExists(4, 2)); // True
    cout << "addEdge tests complete!" << endl;
}