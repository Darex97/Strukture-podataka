#pragma once
#include<iostream>
using namespace std;
class Edge;
class LinkedNode
{
public:
	int node;
	Edge* adj;
	LinkedNode* next;
	int status;
	inline LinkedNode() { adj = NULL; next = NULL; status = 0; node = 0; }
	inline LinkedNode(int NodeN) 
	{
		node = NodeN;
		adj = NULL; next = NULL; status = 0;
	}
	inline LinkedNode(int NodeN, Edge* a, LinkedNode* n, int statusN) { node = NodeN; adj = a; next = n; status = statusN; }
	inline void Visit() { cout << node << endl; }



};