#pragma once
class Edge;

class LinkedNode
{
public:
	LinkedNode* next;
	Edge* adj;
	int node;
	int status;
	int indeg,outdeg;


	LinkedNode(int node,Edge* adjx,LinkedNode* nextx,int status);

	~LinkedNode(void);
};

