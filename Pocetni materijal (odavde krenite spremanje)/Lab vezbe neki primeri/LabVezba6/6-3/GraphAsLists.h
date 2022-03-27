#pragma once
#include "Edge.h"
#include "LinkedNode.h"
#include <iostream>

using namespace std;

template <class T>
class GraphAsLists
{
private:
	LinkedNode<T> *start;
	int nodeNum;
public:
	GraphAsLists(void);
	
	void insertNode(T element);
	bool insertEdge(T a, T b);

	LinkedNode<T>* findNode(T element);

	void print();

	LinkedNode<T>** findThatNode(int &num);

	~GraphAsLists(void);
};

template <class T>
GraphAsLists<T>::GraphAsLists(void) {
	start = NULL;
	nodeNum = 0;
}

template <class T>
void GraphAsLists<T>::insertNode(T element) {
	start = new LinkedNode<T>(element, NULL, start, 0);
	nodeNum++;
}

template <class T>
LinkedNode<T>* GraphAsLists<T>::findNode(T element) {
	LinkedNode<T> *temp;

	for (temp = start; temp != NULL && temp->node != element; temp = temp->next);

	return temp;
}

template <class T>
bool GraphAsLists<T>::insertEdge(T a, T b) {
	LinkedNode<T> *pa = findNode(a);
	LinkedNode<T> *pb = findNode(b);

	if (pa == NULL || pb == NULL)
		return false;

	pa->poteg = new Edge<T>(pb, pa->poteg);
	
	return true;
}

template <class T>
LinkedNode<T>** GraphAsLists<T>::findThatNode(int &num) {
	LinkedNode<T>* temp = start;

	LinkedNode<T>** nodes = new LinkedNode<T>*[nodeNum];
	int i = 0;

	while (temp != NULL) {
		if (temp->poteg == NULL) {
			nodes[i++] = temp;
		}

		temp = temp->next;
	}
	
	LinkedNode<T>** newnodes ;
	if (i > 0) {
		num = i;
		newnodes = new LinkedNode<T>*[num];
		
		for (int j = 0; j < num; j++)
			newnodes[j] = nodes[j];
		
		delete [] nodes;
	} else {
		num = 0;
	}

	return newnodes;
}

template <class T>
GraphAsLists<T>::~GraphAsLists(void) {
	LinkedNode<T> *temp = start, *temp2;

	while (temp != NULL) {
		if (temp->poteg != NULL) {
			Edge<T> *tempedge = temp->poteg, *tempedge2;

			while (tempedge != NULL) {
				tempedge2 = tempedge;
				tempedge = tempedge->nextedge;

				delete tempedge2;
			}
		}
		
		temp2 = temp;
		temp = temp->next;

		delete temp2;
	}

	start = NULL;
}

template <class T>
void GraphAsLists<T>::print() {
	LinkedNode<T>* ptr = start;

	while (ptr != NULL) {
		cout << ptr->node << "->";

		Edge<T>* pa = ptr->poteg;

		while (pa != NULL) {
			cout << pa->destination->node << " | ";
			pa = pa->nextedge;
		}

		cout << endl;

		ptr = ptr->next;
	}
}