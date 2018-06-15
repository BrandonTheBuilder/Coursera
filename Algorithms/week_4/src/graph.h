#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <map>

class Graph {
public:
    Graph(const std::string& fileName);
    int getMinCut(int trials);
    int size() {return _graph.size();}
    std::vector<int> operator[](int i){return _graph[i];}
private:
    void combineNodes();
    std::vector<std::vector<int>> _graph = {};
};
