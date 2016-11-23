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
		"./tests/graph1.txt"
};

int main (int argc, char *argv[]) {

	graphClass* graph = new graphClass();
	for (int i = 0; i < TESTS.size(); i++) {
		graph->importFromFile( TESTS[i] );
		graph->clear();
	}

	return 0;
}
