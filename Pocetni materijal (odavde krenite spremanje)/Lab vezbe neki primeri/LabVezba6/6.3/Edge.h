#ifndef EDGE_H_
#define EDGE_H_

#include "LinkNode.h"

template <class T,class W>
class LinkNode;
template <class T,class W>
class Edge
{
public:
	LinkNode<T,W> *dest;
	Edge<T,W>* link;
	W weigth;

	inline Edge()
	{
		dest = NULL;
		link = NULL;
	}
	
	inline Edge(LinkNode<T,W>* destN, Edge<T,W> * linkN)
	{
		dest = destN;
		link = linkN;
	}
};

#endif /*EDGE_H_*/
