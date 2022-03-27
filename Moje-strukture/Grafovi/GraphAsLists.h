#pragma once
#include"Edge.h"
#include"LinkedNode.h"
#include<iostream>
using namespace std;
class GraphAsLists
{
protected:
	LinkedNode* start;
	long nodeNum;
public:

	inline GraphAsLists() { start = NULL; nodeNum = 0; }
	~GraphAsLists() {};
	LinkedNode* findNode(int p);
	Edge* findEdge(int a, int b);
	bool inserNode(int pod);
	bool deleteNode(int pod);
	bool insertEdge(int a, int b,int w);//modifikovana sa tezinu
	bool deleteEdge(int a, int b);
	long breathTrav(int a);
	long depthTrav(int a);
	long topologicalOrderTrav();
	void print();
	bool Merge(int id1, int id2);//decembar 2020
	int Putavionom(int id1);//oktobar 2020
	int Proslipredmeti(int subjects[]);//septembar 2018
protected:
	void deleteEdgeToNode(LinkedNode* ptr);


};

