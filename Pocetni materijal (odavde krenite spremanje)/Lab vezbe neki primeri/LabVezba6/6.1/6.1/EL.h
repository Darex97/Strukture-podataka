
#include <iostream>
using namespace std;
template<class T,class W>
class LinkedNode;
template<class T,class W>
class Edge  
{
public:
	LinkedNode<T,W>* dest;
	Edge<T,W>* link;
	W weigth;
	inline Edge() {dest=NULL; link=NULL;}
	inline Edge(LinkedNode<T,W>* destN, Edge<T,W>* linkN) { dest=destN; link=linkN;}
	

};


template<class T,class W>
class LinkedNode
{
public:
	T node;
	Edge<T,W> *adj;
	LinkedNode<T,W>* next;
	int status;
	inline LinkedNode() {adj=NULL; next=NULL; status=0; }
	inline LinkedNode(T nodeN) {node=nodeN; adj=NULL; next=NULL; status=0; }
	inline LinkedNode(T nodeN, Edge<T,W>* adjN, LinkedNode<T,W>* nextN, int statusN)
	{
		node = nodeN; adj = adjN; next = nextN; status = statusN;
	}
	inline void Visit() {cout<< node << endl; }
};
