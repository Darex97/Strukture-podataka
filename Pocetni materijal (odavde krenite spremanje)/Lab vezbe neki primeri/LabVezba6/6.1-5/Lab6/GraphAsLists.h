#pragma once
#include"LinkedNode.h"
#include"Edge.h"
#include<iostream>
using namespace std;

class GraphAsLists
{
protected:
	LinkedNode *start;
	int nodeNum;
public:
	GraphAsLists()
	{
		this->start=NULL;
		this->nodeNum=0;
	}
	LinkedNode* findNode(int el);
	Edge* findEdge(int el1,int el2);
	bool insertNode(int el);
	bool deleteNode(int el);
	bool insertEdge(int el1,int el2);
	bool deleteEdge(int el1,int el2);
	int breadthTrav(int el);
	int depthTrav(int el);
	int topologicalOrderTrav();
	void print();
	LinkedNode* indegMax();
	LinkedNode* outdegMax();
	LinkedNode* zeroOutdeg();
	LinkedNode* zeroIndeg();
	int** AdjecencyMatrix();
	void printMatrix(int** matrix);
	~GraphAsLists(void);
};

