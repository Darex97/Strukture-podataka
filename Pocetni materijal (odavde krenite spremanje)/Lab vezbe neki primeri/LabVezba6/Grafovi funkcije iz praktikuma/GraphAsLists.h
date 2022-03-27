#include "LinkedNode.h"
#include "QueueAsArray.h"
#include "StackAsArray.h"
#include <iostream>
using namespace std;

template <class T, class W>
class GraphAsLists
{
protected:
	LinkedNode<T,W>* start;
	long nodeNum;

public:
	inline GraphAsLists() { start = NULL; nodeNum = 0; }
	~GraphAsLists();

	void print();

	bool insertNode(T pod);
	bool deleteNode(T pod);
	bool insertEdge(T a, T b);
	bool deleteEdge(T a, T b);

	long breadthTrav(T a);
	long depthTrav(T a);
	long topologicalOrderTrav();
	
	LinkedNode<T,W>* findNode(T pod);
	Edge<T,W>* findEdge(T a, T b);

protected:
	void deleteEdgeToNode(LinkedNode<T,W>* ptr);
};

template <class T, class W>
GraphAsLists<T,W>::~GraphAsLists()
{
	LinkedNode<T,W> *ptr = start;
	while(ptr != NULL)
	{
		LinkedNode<T,W> *ptr2 = ptr->next;
		deleteNode(ptr->node);
		ptr = ptr2;
	}
	start = NULL;
}

template <class T, class W>
void GraphAsLists<T,W>::print()
{
	LinkedNode<T,W> *ptr = start;
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

template <class T, class W>
LinkedNode<T,W>* GraphAsLists<T,W>::findNode(T pod)
{
	LinkedNode<T,W>* ptr = start;
	while(ptr != NULL && ptr->node != pod)
		ptr = ptr->next;
	return ptr;
}

template <class T, class W>
Edge<T,W>* GraphAsLists<T,W>::findEdge(T a, T b)
{
	LinkedNode<T,W>* pa = findNode(a);
	LinkedNode<T,W>* pb = findNode(b);
		
	if(pa == NULL || pb == NULL) return NULL;
	Edge<T,W>* ptr = pa->adj;
	while(ptr != NULL && ptr->dest != pb)
		ptr = ptr->link;
	return ptr;
}

template <class T, class W>
bool GraphAsLists<T,W>::insertNode(T pod)
{
	LinkedNode<T,W>* newNode = new LinkedNode<T,W>(pod,NULL,start,0);
	if(newNode == NULL) return false;
	start = newNode;
	nodeNum++;
	return true;
}

template <class T, class W>
bool GraphAsLists<T,W>::insertEdge(T a, T b)
{
	LinkedNode<T,W> *pa = findNode(a);
	LinkedNode<T,W> *pb = findNode(b);

	if(pa == NULL || pb == NULL) return false;
	Edge<T,W> *ptr = new Edge<T,W>(pb, pa->adj);
	if(ptr == NULL) return false;
	pa->adj = ptr;
	return true;
}

template <class T, class W>
bool GraphAsLists<T,W>::deleteEdge(T a, T b)
{
	Edge<T,W> *pot = findEdge(a,b);
	if(pot == NULL) return false;
	LinkedNode<T,W> *pa = findNode(a);
	if(pot == pa->adj)
	{
		pa->adj = pot.link;
		delete pot;
		return true;
	}

	Edge<T,W> *tpot = pa->adj;
	while(tpot.link != pot)
		tpot = tpot->link;
	tpot->link = pot->link;
	delete pot;
	return true;
}

template <class T, class W>
bool GraphAsLists<T,W>::deleteNode(T pod)
{
	LinkedNode<T,W> *ptr;
	if(start == NULL) return false;
	if(start->node == pod)
	{
		ptr = start;
		Edge<T,W> *pot = start->adj;
		while(pot != NULL)
		{
			Edge<T,W> *tpot = pot->link;
			delete pot;
			pot = tpot;
		}
		deleteEdgeToNode(start);
		ptr = start;
		start = start->next;
		delete ptr;
		nodeNum--;
		return true;
	}
	else
	{
		ptr = start->next;
		LinkedNode<T,W> *par = start;
		while(ptr != NULL && ptr->node !=pod)
		{
			par = ptr;
			ptr = ptr->next;
		}
		if(ptr ==NULL) return false;
		par->next = ptr->next;
		Edge<T,W> *pot = ptr->adj;
		while(pot != NULL)
		{
			Edge<T,W> *tpot = pot->link;
			delete pot;
			pot = tpot;
		}
		ptr->adj = NULL;
		deleteEdgeToNode(ptr);
		delete ptr;
		nodeNum--;
		return true;
	}
}

template <class T, class W>
void GraphAsLists<T,W>::deleteEdgeToNode(LinkedNode<T,W> *ptr)
{
	LinkedNode<T,W> *pa = start;
	while(pa != NULL)
	{
		Edge<T,W> *prev, *pot = pa->adj;
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

template <class T, class W>
long GraphAsLists<T,W>::breadthTrav(T a)
{
	int retVal = 0;
	LinkedNode<T,W> *ptr = start;
	QueueAsArray<LinkedNode<T,W>*> que(nodeNum);
	while(ptr != NULL)
	{
		ptr->status = 1;
		ptr = ptr->next;
	}
	ptr = findNode(a);
	if(ptr == NULL) return 0;
	que->enqueue(ptr);
	ptr->status = 2;
	while(!que->isEmpty())
	{
		ptr = que->dequeue();
		ptr->status = 3;
		ptr->Visit();
		retVal += 1;
		Edge<T,W> *pot = ptr->adj;
		while(pot != NULL)
		{
			if(pot->dest->status == 1)
			{
				pot->dest->status = 2;
				que->enqueue(pot->dest);
			}
			pot = pot->link;
		}
	}
	return retVal;
}

template <class T, class W>
long GraphAsLists<T,W>::depthTrav(T a)
{
	int retVal = 0;
	LinkedNode<T,W> *ptr = start;
	StackAsArray<LinkedNode<T,W>*> stack(nodeNum);
	while(ptr != NULL)
	{
		ptr->status = 1;
		ptr = ptr->next;
	}
	ptr = findNode(a);
	if(ptr == NULL) return 0;
	stack->push(ptr);
	ptr->status = 2;

	while(!stack->isEmpty())
	{
		ptr = stack->pop();
		ptr->status = 3;
		ptr->Visit();
		retVal += 1;
		Edge<T,W> *pot = ptr->adj;
		while(pot != NULL)
		{
			if(pot->dest->status == 1)
			{
				pot->dest->status = 2;
				stack->push(pot->dest);
			}
			pot = pot->link;
		}
	}
	return retVal;
}

template <class T, class W>
long GraphAsLists<T,W>::topologicalOrderTrav()
{
	int retVal = 0;
	LinkedNode<T,W> *ptr;
	ptr = start;
	while(ptr != NULL)
	{
		ptr->status = 0;
		ptr = ptr->next;
	}
	ptr = start;
	while(ptr != NULL)
	{
		Edge<T,W> *pot = ptr->adj;
		while(pot != NULL)
		{
			pot->dest->status += 1;
			pot = pot->link;
		}
		ptr = ptr->next;
	}

	QueueAsArray<LinkedNode<T,W>*> que(nodeNum);
	ptr = start;
	while(ptr != NULL)
	{
		if(ptr->status == 0)
			que->enqueue(ptr);
		ptr = ptr->next;
	}
	while(!que->isEmpty())
	{
		ptr = que->dequeue();
		ptr->Visit();
		retVal += 1;
		Edge<T,W> *pot = ptr->adj;
		while(pot != NULL)
		{
			pot->dest->status -= 1;
			if(pot->dest->status == 0)
				que->enqueue(pot->dest);
			pot = pot->link;
		}
	}
	return retVal;
}