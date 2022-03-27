#pragma once

enum LinkedNodeStatus
{
	NotProcessed,
	Located,
	Processed
};

template <class T1, class T2>
class Edge;

template <class T1, class T2>
class LinkedNode
{
public:
	T1 info;
	Edge<T1, T2>* adjacent;
	LinkedNode<T1, T2>* next;
	unsigned int status;
	unsigned int length;

public:
	LinkedNode();
	LinkedNode(T1 info);
	LinkedNode(T1 info, Edge<T1, T2>* adjacent, LinkedNode<T1, T2>* next, unsigned int status);

	~LinkedNode() { }
};

template <class T1, class T2>
LinkedNode<T1, T2>::LinkedNode()
{
	this->info = (T1)0;
	this->adjacent = nullptr;
	this->next = nullptr;
	this->status = NotProcessed;
	this->length = 0;
}

template <class T1, class T2>
LinkedNode<T1, T2>::LinkedNode(T1 info)
{
	this->info = info;
	this->adjacent = nullptr;
	this->next = nullptr;
	this->status = NotProcessed;
	this->length = 0;
}

template <class T1, class T2>
LinkedNode<T1, T2>::LinkedNode(T1 info, Edge<T1, T2>* adjacent, LinkedNode<T1, T2>* next,
	unsigned int status)
{
	this->info = info;
	this->adjacent = adjacent;
	this->next = next;
	this->status = status;
	this->length = 0;
}