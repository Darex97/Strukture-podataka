#pragma once
#include <iostream>
using namespace std;
class Edge;
class LinkedNode
{
public:
	int node;
	Edge * adj;
	LinkedNode *next;
	int status;
	int ulazniStepen;

	LinkedNode()
	{
		ulazniStepen = status = 0;
		adj = NULL;
		next = NULL;
	}
	LinkedNode(int elem)
	{
		node = elem;
		ulazniStepen = status = 0;
		adj = NULL;
		next = NULL;
	}
	LinkedNode(int elem, Edge *poteg, LinkedNode *cvor, int status)
	{
		ulazniStepen = 0;
		node = elem;
		adj = poteg;
		next = cvor;
		this->status = status;
	}
	void visit()
	{
		cout << node << endl;
	}
};