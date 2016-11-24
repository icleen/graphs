/*
 * Iain Lee
 * 11-20-16
 * main.cpp
 */

#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <fstream>
#include "graphClass.h"

using namespace std;

const int TEST_NUM = 1;
const vector<string> TESTS = {
		"./tests/graph1.txt", "./tests/graph2.txt", "./tests/graph3.txt", "./tests/graph4.txt", "./tests/graph5.txt", "./tests/graph6.txt"
};

int main (int argc, char *argv[]) {

	graphClass* graph;
	for (int i = 0; i < TESTS.size(); i++) {
		cout << "Test " << i << ":\n";
		graph = new graphClass();
		graph->importFromFile( TESTS.at(i) );
//		graphClass* reverse = graph->reverse();
//		cout << graph->DFSOutput( graph->DFS( reverse->POT() ) );
		cout << graph->SCC();
		delete graph;
		graph = NULL;
	}



	return 0;
}
