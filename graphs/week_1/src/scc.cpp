#include "scc.h"

Graph::Graph(int n) {
    _graph = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
}

int Graph::operator () (int i, int j) {
    return _graph[i-1][j-1]; 
}

void Graph::addEdge (int i, int j){
    _graph[i-1][j-1] = 1;
}

Graph loadFromFile(const std::string& fileName, int n) {
    Graph graph(n);
    std::fstream input(fileName);
    std::string line;
    while(!input.eof()) {
        getline(input, line);
        std::istringstream buffer(line);
        int i;
        buffer >> i;
        int j;
        buffer >> j;
        graph.addEdge(i,j);
    }
    return graph;
}

