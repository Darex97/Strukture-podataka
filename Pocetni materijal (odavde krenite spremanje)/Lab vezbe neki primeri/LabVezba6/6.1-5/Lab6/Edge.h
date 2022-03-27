#pragma once
//#include"LinkedNode.h"
#include<iostream>

class LinkedNode;
class Edge
{
public:
	LinkedNode* dest;
	Edge* link;
	int weight;

	Edge();
	Edge(LinkedNode *dest,Edge *link);
	Edge(LinkedNode *dest,Edge *link,int weight);
	~Edge(void);
};

