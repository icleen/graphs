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
	string iedge;
	vector<string> iedges;
	while( getline( file, iedge ) ) {
		iedges.push_back(iedge);
	}
	makeNodes( inodes.size() );
	int a, b = 0;
	for (int i = 0; i < iedges.size(); i++) {
		assert( iedges.at(i).size() == 3);
		for (int j = 0; j < inodes.size(); j++) {
			if ( iedges.at(i).at(0) == inodes.at(j) ) {
				a = j;
			}
			if ( iedges.at(i).at(2) == inodes.at(j) ) {
				b = j;
			}
		}
		makeEdge( a, b );
	}
}

void graphClass::makeNodes( int amount ) {
	for (int i = 0; i < amount; i++) {
		gnode* gn = new gnode( id );
		gn->id = id++;
	}
}

void graphClass::makeEdge( int nodeId, int toptr ) {
	gnode* gn = nodes.at(toptr);
	nodes.at(nodeId)->edges.push_back(gn);
}

