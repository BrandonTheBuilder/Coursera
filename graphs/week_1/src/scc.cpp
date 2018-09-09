#include "scc.h"

Graph::Graph(int n) {
    _graph = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
}

int Graph::operator () (int i, int j) {
    return _graph[i][j]; 
}

void Graph::addEdge (int i, int j){
    _graph[i][j] = 1;
}
