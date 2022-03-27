#include "GraphAsLists.h"
#include <iostream>
using namespace std;

void main()
{
	GraphAsLists<int,double> graph;
	
	graph.inserNode(1);
	graph.inserNode(2);
	graph.inserNode(3);
	graph.inserNode(4);
	
	graph.insertEdge(1,3);
	graph.insertEdge(2,3);
	graph.insertEdge(1,2);
	graph.insertEdge(3,1);
	graph.insertEdge(1,4);
	graph.insertEdge(4,2);

	graph.print();
	long i = graph.breadthTrav(1);
	cout << "Polazeci od cvora 1 poseceno je " << i << " cvorova." << endl;
}