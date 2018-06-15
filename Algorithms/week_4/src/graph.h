#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Graph {
public:
    Graph(const std::string& fileName);
    int getMinCut();
    std::vector<int> operator[](int i){return _graph[i];}
private:
    void combineNodes();
    std::vector<std::vector<int>> _graph = {};
};
