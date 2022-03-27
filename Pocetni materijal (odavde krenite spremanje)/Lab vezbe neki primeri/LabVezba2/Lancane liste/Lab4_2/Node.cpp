// Node.cpp: implementation of the Node class.
//
//////////////////////////////////////////////////////////////////////
#include <iostream.h>
#include "Node.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Node::Node(){
	next = NULL;
}

Node::Node(int el){
	info = el;
	next = NULL;
}

Node::Node(int el, Node* ptr){
	info = el;
	next = ptr;
}

Node::~Node(){
}

bool Node::isEqual(int el){ return info==el;}

int Node::print(){ return info;}
