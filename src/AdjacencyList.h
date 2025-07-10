#pragma once

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class AdjacencyList {
    private:
    int powerIterations;
    public:
    //Think about what helper functions you will need in the algorithm
    unordered_map<string, vector<string>> adjacencyList;
    AdjacencyList();
    int GetVertices();
    int GetEdges();
    void PageRank(int n);
};

// This class and method are optional.
