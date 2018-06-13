#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Graph {
public:
    Graph(const std::string& fileName);
    int getMinCut();
private:
    void combineNodes();
    std::vector<std::vector<int>> _graph;
};
