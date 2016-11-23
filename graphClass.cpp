#include "graphClass.h"

void graphClass::clear() {
	for (int i = 0; i < nodes.size(); i++) {
		delete nodes.at(i);
	}
}

void graphClass::importFromFile( string fileName ) {
	ifstream file;
	file.open( fileName.c_str() );
	if( file.fail() ) {
		cout << "File not found!" << endl;
		return;
	}
	string inodes;
	getline( file, inodes );
	makeNodes( inodes.size() );
	string iedge;
	int a, b;
	while( getline( file, iedge ) ) {
		assert( iedge.size() == 2 );
		a = 0;
		b = 0;
		for (int j = 0; j < inodes.size(); j++) {
			if ( iedge.at(0) == inodes.at(j) ) {
				a = j;
			}
			if ( iedge.at(1) == inodes.at(j) ) {
				b = j;
			}
		}
		makeEdge( a, b );
	}
	cout << id << endl;
	file.close();
}

void graphClass::makeNodes( int amount ) {
	for (int i = 0; i < amount; i++) {
		gnode* gn = new gnode( id++ );
		nodes.push_back(gn);
	}
}

void graphClass::makeEdge( int nodeId, int toptr ) {
	assert( toptr < nodes.size() );
	gnode* gn = nodes.at(toptr);
	nodes.at(nodeId)->edges.push_back(gn);
}

