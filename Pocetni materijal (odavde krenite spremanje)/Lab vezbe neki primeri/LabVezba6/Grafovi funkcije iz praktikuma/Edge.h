#include "LinkedNode.h"

template <class T, class W>
class Edge
{
public:
	LinkedNode<T,W> *dest;
	Edge<T,W> *link;
	W weigth;
	inline Edge() { dest = NULL; link = NULL; }
	inline Edge(LinkedNode<T,W> *destN, Edge<T,W> *linkN) { dest = destN; link = linkN; }
};