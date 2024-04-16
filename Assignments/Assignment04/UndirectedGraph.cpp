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
        vector<bool> temp(DEFAULTSIZE, false);
        graph.push_back(temp);
    }
}

UndirectedGraph::UndirectedGraph(int numVertices){
    for(int i = numVertices; i > 0; i--){
        vector<bool> temp(numVertices, false);
        graph.push_back(temp);
    }
}

int UndirectedGraph::vertexCount(){
    return graph.size();
}

bool UndirectedGraph::edgeExists(int vert1, int vert2){
    vert1--; // Off by one :)
    vert2--;
    if(vert1 >= graph.size() || vert2 >= graph.size() || vert2 >= graph[vert1].size()){ // Immediately returns false if either number is higher than the number of vertices
        return false;
    }
    if(vert2 < vert1){
        swap(vert1, vert2);
    }
    return graph.at(vert1).at(vert2);
}

bool UndirectedGraph::addEdge(int vert1, int vert2){
    vert1--; // Off by one :)
    vert2--;
    if(vert1 >= graph.size() || vert2 >= graph.size() || vert2 >= graph[vert1].size()){ 
        return false;
    }
    if(vert2 < vert1){ 
        swap(vert1, vert2);
    }
    if(graph.at(vert1).at(vert2) == true){
        return false;
    }
    graph.at(vert1).at(vert2) = true;
    return true;
}

bool UndirectedGraph::removeEdge(int vert1, int vert2){
    vert1--; // Off by one :)
    vert2--;
    if(vert1 >= graph.size() || vert2 >= graph.size() || vert2 >= graph.at(vert1).size()){ 
        return false;
    }
    if(vert2 < vert1){ 
        swap(vert1, vert2);
    }
    if(graph.at(vert1).at(vert2) == false){
        return false;
    }
    graph.at(vert1).at(vert2) = false;
    return true;
}

bool UndirectedGraph::graphConnected(){
    vector<bool> visited(graph.size(), false);
    vector<int> stack;
    stack.push_back(0);
    while(!stack.empty()){
        int current = stack.back();
        stack.pop_back();
        if(visited.at(current) == false){
            visited.at(current) = true;
            for(int i = 0; i < graph.at(current).size(); i++){
                if(graph.at(current).at(i) == true){
                    stack.push_back(i);
                }
            }
        }
    }
    for(int i = 0; i < visited.size(); i++){
        if(visited.at(i) == false){
            return false;
        }
    }
    return true;
}