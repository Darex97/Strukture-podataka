#include "Edge.h"



Edge::Edge()
{
	this->dest=NULL;
	this->link=NULL;
}
Edge::Edge(LinkedNode *dest,Edge *link)
{
	this->dest=dest;
	this->link=link;
}
Edge::Edge(LinkedNode *dest,Edge *link,int weight)
{
	this->dest=dest;
	this->link=link;
	this->weight=weight;
}
Edge::~Edge(void)
{
}
