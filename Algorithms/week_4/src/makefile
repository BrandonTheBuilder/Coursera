CXX = g++
CXXFLAGS = -Wall -g -std=c++11
LDFLAGS =  /usr/lib/libgtest_main.so -lgtest -lpthread

test: graph.h
	$(CXX) $(CXXFLAGS) -o test test_graph.cpp graph.cpp $(LDFLAGS)

