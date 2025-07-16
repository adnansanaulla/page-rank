#include <iostream>
#include <unordered_map>
#include <sstream>
#include "AdjacencyList.h"

using namespace std;

int main() {
    int no_of_lines, power_iterations;
    string from, to;
    cin >> no_of_lines;
    cin >> power_iterations;
    AdjacencyList Created_Graph;
    int j = 0;
    for (int i = 0; i < no_of_lines; i++) {
        string line;
        getline(cin, line);
        istringstream in(line);
        cin >> from;
        cin >> to;
        Created_Graph.adjacencyList[to].push_back(from);
        if (Created_Graph.adjacencyList.find(from) == Created_Graph.adjacencyList.end()) {
            Created_Graph.adjacencyList[from] = {};
        }
    }
    //Create a graph
    Created_Graph.PageRank(power_iterations);
}
