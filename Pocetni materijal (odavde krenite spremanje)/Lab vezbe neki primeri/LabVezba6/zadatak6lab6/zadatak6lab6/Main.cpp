#include"Edge.h"
#include"LinkedNode.h"
#include"GraphAsLists.h"
#include<iostream>
using namespace std;

void main()
{
	GraphAsLists graph;
	graph.insertNode(5);
	graph.insertNode(4);
	graph.insertNode(6);
	graph.insertNode(2);
	graph.insertNode(1);

	graph.insertEdge(5,1);
	graph.insertEdge(5,2);
	graph.insertEdge(2,1);
	graph.insertEdge(4,6);
	graph.insertEdge(5,1);
	graph.insertEdge(6,4);
	graph.insertEdge(6,5);

	graph.print();
	cout<<endl;
	cout<<"Matrica susedstva:"<<endl;
	graph.printMatrix(graph.AdjecencyMatrix());
}