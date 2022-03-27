#pragma once
#include "Edge.h"
#include <iostream>

using namespace std;

template <class T>
class Edge;

template <class T>
class LinkedNode
{
public:
	T node;
	Edge<T>* poteg;
	LinkedNode<T>* next;
	int status;

	LinkedNode(void);
	LinkedNode(T node);
	LinkedNode(T node, Edge<T> *poteg, LinkedNode<T> *next, int status);
};

template <class T>
LinkedNode<T>::LinkedNode(void) {
	poteg = NULL;
	next = NULL;
	status = 0;
	node = (0)T;
}

template <class T>
LinkedNode<T>::LinkedNode(T node) {
	this->node = node;
	poteg = NULL;
	next = NULL;
	status = 0;
}

template <class T>
LinkedNode<T>::LinkedNode(T node, Edge<T> *poteg, LinkedNode<T> *next, int status) {
	this->node = node;
	this->poteg = poteg;
	this->next = next;
	this->status = status;
}

template <class T>
class Edge
{
public:
	LinkedNode<T>* destination;
	Edge<T>* nextedge;

	Edge(void);
	Edge(LinkedNode<T>* destination, Edge<T>* nextedge);
};

template <class T>
Edge<T>::Edge(void) {
	destination = NULL;
	nextedge = NULL;
}

template <class T>
Edge<T>::Edge(LinkedNode<T> *destination, Edge<T> *nextedge) {
	this->destination = destination;
	this->nextedge = nextedge;
}