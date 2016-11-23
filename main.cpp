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
#include "graphClass.h";

using namespace std;

const int TEST_NUM = 1;
const int TESTS[] = {
		"graph1.txt"
};

int main (int argc, char *argv[]) {

	graphClass* graph = new graphClass();
	for (int i = 0; i < TEST_NUM; i++) {
		graph->importFromFile( TESTS[i] );
		graph->clear();
	}

	return 0;
}
