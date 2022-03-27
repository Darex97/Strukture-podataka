#include "Edge.h"
#include <iostream>
using namespace std;

template <class T, class W>
class LinkedNode
{
public:
	T node;
	Edge<T,W> *adj;
	int status;
	LinkedNode<T,W> *next;
	inline LinkedNode() { adj = NULL; next = NULL; status = 0; }
		
	inline LinkedNode(T nodeN)
	{
		adj = NULL;
		node = nodeN;
		next = NULL;
		status = 0;
	}
		
	inline LinedkNode(T nodeN, Edge<T,W> *adjN, LinkedNode<T,W> *nextN, int statusN)
	{
		adj = adjN;
		node = nodeN;
		next = nextN;
		status = statusN;
	}

	inline void Visit() { cout << node << endl; }
};