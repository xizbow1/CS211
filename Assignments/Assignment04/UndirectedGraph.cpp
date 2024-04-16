#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include "UndirectedGraph.h"

using namespace std;

// Blake Culbertson

// Going to use the "upper triangle" strategy.

UndirectedGraph::UndirectedGraph(){
    for(int i = DEFAULTSIZE; i > 0; i--){
        vector<bool> temp(i, false);
        graph.push_back(temp);
    }
}

UndirectedGraph::UndirectedGraph(int numVertices){
    for(int i = numVertices; i > 0; i--){
        vector<bool> temp(i, false);
        graph.push_back(temp);
    }
}

int UndirectedGraph::vertexCount(){
    return graph.size();
}

bool UndirectedGraph::edgeExists(int vert1, int vert2){
    if(vert1 >= graph.size() || vert2 >= graph.size()){ // Immediately returns false if either number is higher than the number of vertices
        return false;
    }
    if(vert2 < bool UndirectedGraph::edgeExists(int vert1, int vert2)){
        if(vert1 >= graph.size() || vert2 >= graph.size() || vert2 >= graph[vert1].size()){ 
            return false;
        }
        if(vert2 < vert1){ 
            swap(vert1, vert2);
        }
    }
    return graph.at(vert1).at(vert2);
}

bool UndirectedGraph::addEdge(int vert1, int vert2){
    if(vert1 >= graph.size() || vert2 >= graph.size() || vert2 >= graph[vert1].size()){ 
        return false;
    }
    if(vert2 < vert1){ 
        swap(vert1, vert2);
    }
    graph.at(vert1).at(vert2) = true;
    return true;
}vert1){ // Make sure vert2 is always bigger, because we're using an upper triangle
        swap(vert1, vert2);
    }
    return graph.at(vert1).at(vert2);
}

bool UndirectedGraph::addEdge(int vert1, int vert2){
    if(vert1 >= graph.size() || vert2 >= graph.size()){ // Immediately returns false if either number is higher than the number of vertices 
        return false;
    }
    if(vert2 < vert1){ // Make sure vert2 is always bigger, because we're using an upper triangle
        swap(vert1, vert2);
    }
    if(graph.at(vert1).at(vert2) == true){
        return false;
    } else {
        graph.at(vert1).at(vert2) = true;
        return true;
    }
}

bool UndirectedGraph::removeEdge(int vert1, int vert2){
    if(vert1 >= graph.size() || vert2 >= graph.size()){ // Immediately returns false if either number is higher than the number of vertices 
        return false;
    }
    if(vert2 < vert1){ // Make sure vert2 is always bigger, because we're using an upper triangle
        swap(vert1, vert2);
    }
    if(graph.at(vert1).at(vert2) == false){
        return false;
    } else {
        graph.at(vert1).at(vert2) = false;
        return true;
    }
}