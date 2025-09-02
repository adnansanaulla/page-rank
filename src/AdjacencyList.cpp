#include <iostream>
#include <sstream>
#include "AdjacencyList.h"
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

// Constructor method
AdjacencyList::AdjacencyList() {}

// Method that adds a page to the graph
void AdjacencyList::AddVertex(string to, string from, int &j)
{
    int to2, find2;
    if (mappar.find(to) == mappar.end())
    {
        to2 = j;
        mappar[to] = j;
        reverse_mappar[j++] = to;
    }
    else
    {
        to2 = mappar[to];
    }
    if (mappar.find(from) == mappar.end())
    {
        find2 = j;
        mappar[from] = j;
        reverse_mappar[j++] = from;
    }
    else
    {
        find2 = mappar[from];
    }
    if (adjacencyList.find(to2) == adjacencyList.end())
    {
        adjacencyList[to2] = {};
    }
    if (adjacencyList.find(find2) == adjacencyList.end())
    {
        adjacencyList[find2] = {};
    }
    if (outdegrees.size() < adjacencyList.size())
    {
        outdegrees.resize(adjacencyList.size(), 0);
    }
    adjacencyList[to2].push_back(find2);
    outdegrees[find2]++;
}
// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
string AdjacencyList::PageRank(int n)
{
    stringstream ss;
    double temp;
    vector<pair<string, int>> websites;
    vector<double> ranks(static_cast<int>(adjacencyList.size()), static_cast<double>(1.0 / adjacencyList.size()));
    while (n > 1)
    {
        vector<double> newRanks(adjacencyList.size(), 0.0);
        for (int i = 0; i < static_cast<int>(adjacencyList.size()); ++i)
        {
            for (int from : adjacencyList[i])
            {
                if (outdegrees[from] == 0)
                    continue;
                newRanks[i] += ranks[from] / outdegrees[from];
            }
        }
        ranks = newRanks;
        n--;
    }
    for (size_t i = 0; i < ranks.size(); i++)
    {
        websites.push_back({reverse_mappar[i], i});
    }
    sort(websites.begin(), websites.end());
    for (size_t i = 0; i < websites.size(); i++)
    {
        temp = ranks[websites[i].second];
        ss << fixed << showpoint;
        ss << setprecision(2);
        ss << websites[i].first << " " << temp;
        if (i != websites.size() - 1)
        {
            ss << endl;
        }
    }
    string output = ss.str();
    cout << output << endl;
    return ss.str();
}