#pragma once

class LinkedNode;
class Edge
{
public:
	Edge* link;
	LinkedNode* dest;
	Edge(LinkedNode* dest,Edge* link);
	~Edge(void);
};

