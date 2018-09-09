CXX = g++
CXXFLAGS = -Wall -g -std=c++11
LDFLAGS = /usr/lib/libgtest_main.so -lgtest -lpthread

test: scc.h scc.cpp test_scc.cpp
	$(CXX) $(CXXFLAGS) -g -o test test_scc.cpp scc.cpp $(LDFLAGS)
