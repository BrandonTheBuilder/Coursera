#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Graph{
// This class holds an adjcency list representation of a graph
public:
    Graph(int n);
    void addEdge(int i, int j);
    int operator () (int i, int j);
private:
    std::vector<std::vector<int>> _graph;
};

Graph loadFromFile(const std::string& fileName, int n);

