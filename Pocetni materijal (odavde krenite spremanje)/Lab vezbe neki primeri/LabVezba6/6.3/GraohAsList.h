#ifndef GRAOHASLIST_H_
#define GRAOHASLIST_H_

#include "LinkNode.h"
#include "Edge.h"
#include <iostream>
using namespace std;

template <class T,class W>
class GraphAsList
{
protected:
	LinkNode<T,W>* start;
	long nodeNum;
public:
	inline GraphAsList()
	{
		start = NULL;
		nodeNum = 0;
	}

	bool inserNode( T pod)
	{
		LinkNode<T,W>* newNode = new LinkNode<T,W>(pod,NULL,start,0);
		if(newNode == NULL)
			return false;
		start = newNode;
		nodeNum++;
		return true;
	}

	void print()
	{
		LinkNode<T,W> *ptr = start;
		while(ptr != NULL)
		{
			cout << ptr->node << "->";
			Edge<T,W>* pa = ptr->adj;
			while(pa != NULL)
			{
				cout << pa->dest->node << "|";
				pa = pa->link;
			}
			cout << "\r\n";
			ptr = ptr->next;
		}
	}
	
	LinkNode<T,W>* find_Null_Output() // metoda za nalzenje cvora koji ima izlazni stepen 0
	{
		LinkNode<T,W>* ptr = start;
		while(ptr != NULL && ptr->adj != NULL)
			ptr = ptr->next;
		if(ptr->adj == NULL)
			return ptr;
		else
			return NULL;
	}
	
	LinkNode<T,W>* findNode(T pod)
	{
		LinkNode<T,W>* ptr = start;
		while(ptr != NULL && ptr->node != pod)
			ptr = ptr->next;
		return ptr;
	}

	Edge<T,W>* findEdge(T a, T b)
	{
		LinkNode<T,W>* pa = findNode(a);
		LinkNode<T,W>* pb = findNode(b);
		
		if(pa == NULL || pb == NULL)
			return NULL;
		Edge<T,W>* ptr = pa->next;
		while(ptr != NULL && ptr->dest != pb)
			ptr = ptr->link;
	
		return ptr;
	}
	
	bool insertEdge(T a, T b)
	{
		LinkNode<T,W> *pa = findNode(a);
		LinkNode<T,W> *pb = findNode(b);

		if(pa == NULL || pb == NULL)
			return false;
		Edge<T,W> *ptr = new Edge<T,W>(pb, pa->adj);
		if(ptr == NULL)
			return false;
		pa->adj = ptr;
		return true;
	}

	bool deleteEdge(T a, T b)
	{
		Edge<T,W> * pot = findEdge(a,b);
		if(pot == NULL)
			return false;
		LinkNode<T,W>* pa = findNode(a);
		if(pot == pa->adj)
		{
			pa->adj = pot->link;
			delete pot;
			return true;
		}

		Edge<T,W> *tpot = pa->adj;
		while(tpot->link != pot)
			tpot = tpot->link;
		tpot->link = pot->link;
		delete pot;
		return true;
	}

	void deleteEdgeToNode(LinkNode<T,W>* ptr)
	{

		LinkNode<T,W>* pa = start;
		while(pa != NULL)
		{
			Edge<T,W> *prev,*pot = pa->adj;
			while(pot != NULL)
			{
				if(pot->dest == ptr)
				{
					if(pa->adj == pot)
					{
						pa->adj = pot->link;
						delete pot;
						pot = pa->adj;
					}
					else
					{
						prev->link = pot->link;
						delete pot;
						pot = prev->link;
					}
				}
				else
				{
					prev = pot;
					pot = pot->link;
				}
			}
			pa = pa->next;
		}
	}
	
	~GraphAsList() {}
};

#endif /*GRAOHASLIST_H_*/
