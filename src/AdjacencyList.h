#pragma once

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
//header file
class AdjacencyList {
    public:
    // adjacency list that contains the indegrees
    unordered_map<int, vector<int>> adjacencyList;
    // vector that has the amount of outdegrees
    vector<int> outdegrees;
    // map that maps websites to numbers
    unordered_map<string, int> mappar;
    // map that reverses that
    unordered_map<int, string> reverse_mappar;
    // constructor
    AdjacencyList();
    // adds vertex
    void AddVertex(string to, string from, int& j);
    // outputs pages ranked
    string PageRank(int n);
};