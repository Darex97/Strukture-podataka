#include "Edge.h"


Edge::Edge(LinkedNode *dest,Edge* link)
{
	this->dest=dest;
	this->link=link;
}


Edge::~Edge(void)
{
}
