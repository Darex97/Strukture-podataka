// Node.cpp: implementation of the Node class.
//
//////////////////////////////////////////////////////////////////////

#include "Node.h"
#include <iostream>
using namespace std;


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Node::Node(){
	i = 0;
	j = 0;
	info = -1;
	linkk = NULL;
	linkv = NULL;
}

Node::Node(int x, int y, int z, Node *kol, Node *vrs){
	i = x;
	j = y;
	info = z;
	linkk = kol;
	linkv = vrs;
}

Node::~Node(){
}

void Node::print(){
	cout<<"["<<i<<","<<j<<"]"<<"="<<info<<"  ";
}

bool Node::isEqual(int x){ return info == x;}