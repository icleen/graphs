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
		"./tests/graph1.txt", "./tests/graph2.txt"
};

int main (int argc, char *argv[]) {

	graphClass* graph;
	for (int i = 0; i < TESTS.size(); i++) {
		graph = new graphClass();
		graph->importFromFile( TESTS[i] );
		cout << graph->pathOutput( graph->POT() )  << endl;
		graph->resetVisit();
		cout << graph->pathOutput( graph->traverse(0) ) << endl;
		cout << graph->pathOutput( graph->traverse(6) ) << endl;
		cout << graph->DFSOutput( graph->DFS( graph->POT() ) );
		delete graph;
		graph = NULL;
	}

	return 0;
}
