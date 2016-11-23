// Iain Lee 11-20-16

#ifndef graphClass_h
#define graphClass_h

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <assert.h>

using namespace std;

struct gnode {
	gnode( int i ) {
		id = i;
		parent = -1;
		visited = false;
	}
	int id;
	vector<gnode*> edges;
	bool visited;
	int parent;
};

class graphClass {

private:
	int id;
	vector<gnode*> nodes;
	string key;
	stack<int> mystack;

public:
	graphClass() {
		id = 0;
	};
	~graphClass() {
		clear();
	};

	void importFromFile( string fileName );
	void makeNodes( int amount );
	void makeEdge( int nodeId, int toptr );
	void clear();
	void resetVisit();

	int nodeIndex( string name );
	gnode* nodeat(int index);

	void DFS();
	string POT();
	string traverse( int id );
	string pathOutput( string path );
	string pathOutput();
	graphClass* reverse();
	void SCC();

};


#endif
