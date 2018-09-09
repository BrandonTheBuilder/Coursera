#include <stdlib.h>
#include <vector>

class Graph{
// This class holds an adjcency list representation of a graph
public:
    Graph(int n);
    void addEdge(int i, int j);
private:
    std::vector<std::vector<int>> _graph;
};
