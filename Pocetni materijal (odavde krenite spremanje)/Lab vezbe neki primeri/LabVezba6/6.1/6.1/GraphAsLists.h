#pragma once
#include "EL.h";

#include <iosteam>
using namespace std;
template <class T,class W>
class GraphAsLists  
{
protected:
	LinkedNode<T,W>* start;
	long nodeNum;
public:
	inline GraphAsLists(){ start = NULL; nodeNum = 0;}
	~GraphAsLists();
	LinkedNode<T,W>* findNode(T pod);
	Edge<T,W>* findEdge(T a, T b);
	bool insertNode(T pod);
	bool deleteNode(T pod);
	bool insertEdge(T a, T b);
	bool deleteEdge(T a, T b);
	void deleteEdgeToNode(LinkedNode<T,W>* ptr);
	void print();
	void maxOutStepen();
};

template <class T,class W>
GraphAsLists<T,W>::~GraphAsLists(){
	LinkedNode<T,W>* ptr = start;
	while (ptr != NULL){
		LinkedNode<T,W>* ptr2 = ptr->next;
		deleteNode(ptr->node);
		ptr = ptr2;
	}
	start = NULL;
}

template <class T,class W>
void GraphAsLists<T,W>::print(){
	LinkedNode<T,W>* ptr = start;
	while(ptr != NULL){
		cout<<ptr->node<<"->";
		Edge<T,W>* pa = ptr->adj;
		while(pa != NULL){
			cout<<pa->dest->node<<"|";
			pa = pa->link;
		}
		cout<<"\r\n";
		ptr = ptr->next;
	}
}
template <class T,class W>
LinkedNode<T,W>* GraphAsLists<T,W>::findNode(T pod){
	LinkedNode<T,W>* ptr = start;
	while(ptr != NULL && ptr->node != pod)
		ptr = ptr->next;
	return ptr;
}
template <class T,class W>
Edge<T,W>* GraphAsLists::findEdge(T a, T b){
	LinkedNode<T,W>* pa = findNode(a);
	LinkedNode<T,W>* pb = findNode(b);
	if (pa == NULL || pb == NULL) return NULL;
	Edge<T,W>* ptr = pa->adj;
	while (ptr != NULL && ptr->dest != pb)
		ptr = ptr->link;
	return ptr;
}
template <class T,class W>
bool GraphAsLists::insertNode(T pod){
	LinkedNode<T,W>* newNode = new LinkedNode(pod, NULL, start,0);
	if (newNode == NULL) return false;
	start = newNode;
	nodeNum++;
	return true;
}
template <class T,class W>
bool GraphAsLists::insertEdge(T a, T b){
	LinkedNode<T,W>* pa = findNode(a);
	LinkedNode<T,W>* pb = findNode(b);
	if (pa == NULL || pb == NULL) return false;
	Edge<T,W>* ptr = new Edge<T,W>(pb,pa->adj);
	if (ptr == NULL) return false;
	pa->adj = ptr;
	return true;
}
template <class T,class W>
bool GraphAsLists<T,W>::deleteEdge(char a, char b){
	Edge<T,W>* pot = findEdge(a,b);
	if (pot == NULL) return false;
	LinkedNode<T,W>* pa = findNode(a);
	LinkedNode<T,W>* pb = findNode(b);
	if (pot == pa->adj){
		pa->adj = pot.link;
		delete pot;
		return true;
	}
	Edge<T,W>* tpot = pa->adj;
	while (tpot->link != pot)
		tpot = tpot->link;
	tpot->link = pot->link;
	delete pot;
	return true;
}
template <class T,class W>
bool GraphAsLists::deleteNode(T pod){
	LinkedNode<T,W>* ptr;
	if (start == NULL) return false;
	if (start->node == pod){
		ptr = start;
		Edge<T,W>* pot = start->adj;
		while (pot != NULL){
			Edge<T,W>* tpot = pot->link;
			delete pot;
			pot = tpot;
		}
		start->adj = NULL;
		deleteEdgeToNode(start);
		ptr = start;
		start = start->next;
		delete ptr;
		nodeNum--;
		return true;
	}
	else{
		ptr = start->next;
		LinkedNode<T,W>* par = start;
		while (ptr != NULL && ptr->node != pod){
			par = ptr;
			ptr = ptr->next;
		}
		if (ptr == NULL) return false;
		par->next = ptr->next;
		Edge<T,W>* pot = ptr->adj;
		while (pot != NULL){
			Edge<T,W>* tpot = pot->link;
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
template <class T,class W>
void GraphAsLists::maxOutStepen(){
	LinkedNode<T,W>* ptr = start;
	char max = ptr->node;
	int pom = ptr->outs;
	while(ptr != NULL){
		if (ptr->outs > pom){
			pom = ptr->outs;
			max = ptr->node;
		}
		ptr = ptr->next;
	}
	cout<<"Najveci izlazni stepen ima cvor: "<<max<<", i on iznosi: "<<pom<<endl;
}