#pragma once
#include "Graph.h"
void main()
{
	Graph g1;
	g1.addNode(5);
	g1.addNode(4);
	g1.addNode(3);
	g1.addNode(2);
	g1.addNode(1);
	g1.addNode(0);
	g1.addEdge(0,5,14);
	g1.addEdge(0,2,9);
	g1.addEdge(0,1,7);
	g1.addEdge(1,4,15);
	g1.addEdge(1,3,10);
	g1.addEdge(2,4,2);
	g1.addEdge(3,2,11);
	g1.addEdge(3,4,6);
	g1.addEdge(4,2,9);
	g1.printGraph();
	g1.traverseDFS(g1.findNode(0));
	//g1.printBFS(g1.findNode('A'));
	//g1.traverseDFS(g1.findNode('A'));
	//g1.dijikstrin(g1.findNode('A'));
	//g1.flojdov();
	//if (!g1.topolosko())
	//	cout << "Postoji ciklus" << endl;
	//g1.printGraph();
	g1.topolosko();
}