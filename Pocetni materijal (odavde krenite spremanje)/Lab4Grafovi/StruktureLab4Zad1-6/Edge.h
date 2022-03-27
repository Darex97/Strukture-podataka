#pragma once
#include"LinkedNode.h"
class LinkedNode;
class Edge
{
public:
	LinkedNode* dest;
	Edge* link;
	int weight;
public:
	Edge() { dest = NULL;link = NULL; }
	Edge(LinkedNode* destN, Edge* linkN)
	{
		dest = destN;
		link = linkN;
	}
	Edge(LinkedNode* destN, Edge* linkN, int w)
	{
		dest = destN;
		link = linkN;
		weight = w;
	}
};