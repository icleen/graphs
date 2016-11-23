// Iain Lee 11-20-16

#ifndef graphClass_h
#define graphClass_h

#include <iostream>
#include <vector>
#include <fstream>
#include <assert.h>

using namespace std;

struct gnode {
	int id;
	vector<gnode*> edges;
	gnode( int i ) {
		id = i;
	}
};

class graphClass {

private:
	int id;
	vector<gnode*> nodes;
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

	int nodeIndex( string name );
	gnode* nodeat(int index);

	void DFS();
	void POT();
	graphClass* reverse();
	void SCC();

};


#endif
