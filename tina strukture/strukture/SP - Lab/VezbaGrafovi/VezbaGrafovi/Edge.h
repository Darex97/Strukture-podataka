#pragma once

template <class T1, class T2>
class LinkedNode;

template <class T1, class T2>
class Edge
{
public:
	LinkedNode<T1, T2>* destination;
	Edge<T1, T2>* link;
	T2 weight;

public:
	Edge();
	Edge(LinkedNode<T1, T2>* destination, Edge<T1, T2>* link);
	Edge(LinkedNode<T1, T2>* destination, Edge<T1, T2>* link, T2 weight);

	~Edge() { }
};

template <class T1, class T2>
Edge<T1, T2>::Edge()
{
	this->destination = nullptr;
	this->link = nullptr;
	this->weight = (T2)0;
}

template <class T1, class T2>
Edge<T1, T2>::Edge(LinkedNode<T1, T2>* destination, Edge<T1, T2>* link)
{
	this->destination = destination;
	this->link = link;
	this->weight = (T2)0;
}

template <class T1, class T2>
Edge<T1, T2>::Edge(LinkedNode<T1, T2>* destination, Edge<T1, T2>* link, T2 weight)
{
	this->destination = destination;
	this->link = link;
	this->weight = weight;
}