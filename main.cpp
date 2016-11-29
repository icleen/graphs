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
		"./tests/graph1.txt", "./tests/graph2.txt", "./tests/graph3.txt", "./tests/graph4.txt", "./tests/graph5.txt", "./tests/graph6.txt",
		"./tests/graph7.txt", "./tests/graph8.txt", "./tests/graph9.txt", "./tests/graph10.txt", "./tests/graph11.txt", "./tests/graph12.txt",
		"./tests/graph13.txt"
};

int main (int argc, char *argv[]) {

	graphClass* graph;
	for (int i = 0; i < TESTS.size(); i++) {
		cout << "Test " << i + 1 << ":\n";
		graph = new graphClass();
		graph->importFromFile( TESTS.at(i) );
		cout << graph->SCC();
		delete graph;
		graph = NULL;
	}

//	graph = new graphClass();
//	graph->importFromFile( "./tests/graph10.txt" );
//	graphClass* reverse = new graphClass();
//	reverse->importFromFile( "./tests/graph11.txt" );
//	cout << graph->pathOutput( graph->traverse( 0 ) ) << endl;
//	graph->traverse( 0 );
//	cout << graph->pathOutput( graph->stackOut() ) << endl;
////	cout << reverse->pathOutput( reverse->traverse( 0 ) ) << endl;
//	reverse->traverse( 0 );
//	cout << reverse->pathOutput( reverse->stackOut() ) << endl;
////	cout << graph->size() << endl;
////	cout << reverse->size() << endl;
////	cout << graph->size( 0 ) << endl;
////	cout << reverse->size( 0 ) << endl;
//	cout << graph->pathOutput( graph->POT() ) << endl;
//	cout << reverse->pathOutput( reverse->POT() ) << endl;
//	reverse->resetVisit();
//	graph->resetVisit();
//	graph->clearStack();
//	reverse->resetVisit();
//	cout << graph->DFSOutput( graph->DFS( reverse->POT() ) );

	return 0;
}
