#ifndef LINKNODE_H_
#define LINKNODE_H_

#include <iostream>
using namespace std;
#include "Edge.h"

template <class T,class W>
class LinkNode
{
	public:
		T node;
		Edge<T,W>* adj;
		int status;
		LinkNode<T,W>* next;
		
		inline LinkNode()
		{

			adj = NULL;
			next = NULL;
			status = 0;
		}
		
		inline LinkNode(T nodeN)
		{
			adj = NULL;
			node = nodeN;
			next = NULL;
			status = 0;
		}

		inline LinkNode(T nodeN,Edge<T,W>* adjN,LinkNode<T,W>* nextN,int statusN)
		{
			adj = adjN;
			node = nodeN;
			next = nextN;
			status = statusN;
		}

		inline void Visit()
		{
			cout << node << endl;
		}
};

#endif /*LINKNODE_H_*/
