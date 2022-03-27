#include "GraphAsLists.h"

#include "EL.h"
#include <iostream>
using namespace std;
int main(){
	GraphAsLists obj;
	obj.insertNode('a');
	obj.insertNode('b');
	obj.insertNode('c');
	obj.insertNode('d');
	obj.insertEdge('a','b');
	obj.insertEdge('a','c');
	obj.insertEdge('a','d');
	obj.insertEdge('b','d');
	obj.insertEdge('c','d');
	obj.print();
	obj.maxOutStepen();

	return 0;
}