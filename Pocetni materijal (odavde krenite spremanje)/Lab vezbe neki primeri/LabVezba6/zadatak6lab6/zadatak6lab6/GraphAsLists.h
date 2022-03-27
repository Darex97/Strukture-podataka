#pragma once
#include"Edge.h"
#include"LinkedNode.h"


class GraphAsLists
{
public:
	LinkedNode *start;
	int numOfNodes;

	bool insertNode(int el);
	bool insertEdge(int el1,int el2);
	LinkedNode* findNode(int el);
	Edge* findEdge(int el1,int el2);
	GraphAsLists();
	int** AdjecencyMatrix();
	void printMatrix(int** matrix);
	void print();
	~GraphAsLists(void);
};

