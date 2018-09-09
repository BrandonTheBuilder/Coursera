#include "scc.h"

Graph::Graph(int n) {
    _graph = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
}
