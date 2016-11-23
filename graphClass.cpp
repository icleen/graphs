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
	key = inodes;
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
//	cout << id << endl;
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

string graphClass::traverse( int id ) {
	nodes.at(id)->visited = true;
	stringstream value;
	int returned = 0;
	for (int i = 0; i < nodes.at(id)->edges.size(); i++) {
		if ( !nodes.at(id)->edges.at(i)->visited ) {
			value << traverse( nodes.at(id)->edges.at(i)->id );
			returned++;
		}
	}
	mystack.push( nodes.at(id)->id );
	value << nodes.at(id)->id;
	return value.str();
}

string graphClass::pathOutput( string path ) {
	stringstream output;
	stringstream ss;
	int index = -1;
	for (int i = path.size() - 1; i >= 0; i--) {
		ss.clear();
		ss << path.at(i);
		ss >> index;
		output << key.at( index );
	}
	return output.str();
}

string graphClass::pathOutput() {
	stringstream output;
	while ( !mystack.empty() ) {
		output << key.at( mystack.top() );
		mystack.pop();
	}
	return output.str();
}

string graphClass::POT() {
	stringstream output;
	for (int i = 0; i < nodes.size(); i++) {
		if ( !nodes.at(id)->visited ) {
			output << traverse( nodes.at(id)->edges.at(i)->id );
		}
	}
	return output.str();
}












