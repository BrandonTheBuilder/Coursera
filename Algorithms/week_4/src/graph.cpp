#include "graph.h"

Graph::Graph(const std::string& fileName){
    std::fstream input(fileName);
    std::string line;
    while(!input.eof()) {
        getline(input, line);
        std::istringstream buffer(line);
        std::vector<int> data = {};
        int num;
        while(buffer >> num){
            data.push_back(num);
        }
        _graph.push_back(data);
    }
}

int Graph::getMinCut() {

}

void Graph::combineNodes() {

}
