#pragma once
#include "LinkedNode.h"

class Edge
{
public:

	LinkedNode *dest;
	Edge *link;
	int tezina;

	Edge()
	{
		dest = NULL;
		link = NULL;
	}
	Edge(LinkedNode *put, Edge *sledeci)
	{
		dest = put;
		link = sledeci;
	}
};