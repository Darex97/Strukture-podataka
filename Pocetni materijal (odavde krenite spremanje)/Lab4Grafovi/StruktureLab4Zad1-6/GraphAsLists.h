#pragma once
#include"Edge.h"
#include"LinkedNode.h"
class GraphAsLists 
{
protected:
	LinkedNode* start;//head za ll. cvorova
	int nodeNum;//broj cvorova
public:
	GraphAsLists() { start = NULL;nodeNum = 0; }//KK
	//~GraphAsLists();

	void insertNode(int pod);
	LinkedNode* findNode(int pod);
	//bool deleteNode(int pod);

	Edge* findEdge(int a, int b);
	bool insertEdge(int a, int b);
	bool insertEdge(int a, int b, int w);
	bool deleteEdge(int a, int b);

	void BFS(int);
	void print();
	void visit(LinkedNode*);

	//zad. 1
	void maxInDeg();
	//zad. 2
	void maxOutDeg();
	//zad. 3
	void outZero();
	//zad. 4
	void inZero();
	//zad. 5
	//postoji put izmedju svaka 2 cvora u grafu
	bool stronglyConnencted();
	//zad. 6
	void adjescentMatrix();

	//2016
	void getReachable(int, int);
};