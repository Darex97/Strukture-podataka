#pragma once

#include <iostream>

using namespace std;

#include "LinkedNode.h"
#include "Edge.h"
#include "StaticQueue.h"

template <class T1, class T2>
class DynamicGraph
{
private:
	LinkedNode<T1, T2>* start;
	unsigned int numberOfNodes;

public:
	DynamicGraph();

	~DynamicGraph();

	bool deleteNode(T1 element);

	void deleteEdgeToNode(LinkedNode<T1, T2>* node) const;

	bool isEmpty() const { return this->start == nullptr; }

	void insertNode(T1 element);

	LinkedNode<T1, T2>* findNode(T1 element) const;
	bool insertEdge(T1 source, T1 destination, T2 weight) const;
	Edge<T1, T2>* findEdge(T1 source, T1 destination) const;
	void print() const;
	int breadthTraversal(T1 element) const;
	bool deleteEdgeWithMaxWeight() const;
	int minLengthCycle() const;
};

template <class T1, class T2>
DynamicGraph<T1, T2>::DynamicGraph()
{
	this->start = nullptr;
	this->numberOfNodes = 0;
}

template <class T1, class T2>
DynamicGraph<T1, T2>::~DynamicGraph()
{
	while (!this->isEmpty())
	{
		LinkedNode<T1, T2>* tempNode = this->start->next;

		this->deleteNode(this->start->info);

		this->start = tempNode;
	}
}

template <class T1, class T2>
bool DynamicGraph<T1, T2>::deleteNode(T1 element)
{
	if (this->isEmpty())
	{
		return false;
	}

	LinkedNode<T1, T2>* currentNode = this->start;

	if (this->start->info == element)
	{
		while (currentNode->adjacent != nullptr)
		{
			Edge<T1, T2>* tempEdge = currentNode->adjacent->link;

			delete currentNode->adjacent;

			currentNode->adjacent = tempEdge;
		}

		this->deleteEdgeToNode(this->start);

		this->start = this->start->next;

		delete currentNode;
	}
	else
	{
		while (currentNode->next != nullptr && currentNode->next->info != element)
		{
			currentNode = currentNode->next;
		}

		if (currentNode->next == nullptr)
		{
			return false;
		}

		while (currentNode->next->adjacent != nullptr)
		{
			Edge<T1, T2>* tempEdge = currentNode->next->adjacent->link;

			delete currentNode->next->adjacent;

			currentNode->next->adjacent = tempEdge;
		}

		this->deleteEdgeToNode(currentNode->next);

		delete currentNode->next;
	}

	this->numberOfNodes--;

	return true;
}

template <class T1, class T2>
void DynamicGraph<T1, T2>::deleteEdgeToNode(LinkedNode<T1, T2>* node) const
{
	LinkedNode<T1, T2>* currentNode = this->start;

	while (currentNode != nullptr)
	{
		Edge<T1, T2>* previousEdge = nullptr;
		Edge<T1, T2>* currentEdge = currentNode->adjacent;

		while (currentEdge != nullptr)
		{
			if (currentEdge->destination == node)
			{
				if (currentNode->adjacent == currentEdge)
				{
					currentNode->adjacent = currentEdge->link;

					delete currentEdge;

					currentEdge = currentNode->adjacent;
				}
				else
				{
					previousEdge->link = currentEdge->link;

					delete currentEdge;

					currentEdge = previousEdge->link;
				}
			}
			else
			{
				previousEdge = currentEdge;
				currentEdge = currentEdge->link;
			}
		}

		currentNode = currentNode->next;
	}
}

template <class T1, class T2>
void DynamicGraph<T1, T2>::insertNode(T1 element)
{
	this->start = new LinkedNode<T1, T2>(element, nullptr, this->start, 0);

	this->numberOfNodes++;
}

template <class T1, class T2>
LinkedNode<T1, T2>* DynamicGraph<T1, T2>::findNode(T1 element) const
{
	LinkedNode<T1, T2>* currentNode = this->start;

	while (currentNode != nullptr && currentNode->info != element)
	{
		currentNode = currentNode->next;
	}

	return currentNode;
}

template <class T1, class T2>
bool DynamicGraph<T1, T2>::insertEdge(T1 source, T1 destination, T2 weight) const
{
	if (this->isEmpty())
	{
		return false;
	}

	LinkedNode<T1, T2>* sourceNode = this->findNode(source);

	if (sourceNode == nullptr)
	{
		return false;
	}

	LinkedNode<T1, T2>* destinationNode = this->findNode(destination);

	if (destinationNode == nullptr)
	{
		return false;
	}

	sourceNode->adjacent = new Edge<T1, T2>(destinationNode, sourceNode->adjacent, weight);

	return true;
}

template <class T1, class T2>
Edge<T1, T2>* DynamicGraph<T1, T2>::findEdge(T1 source, T1 destination) const
{
	if (this->isEmpty())
	{
		return nullptr;
	}

	LinkedNode<T1, T2>* sourceNode = this->findNode(source);

	if (sourceNode == nullptr)
	{
		return nullptr;
	}

	Edge<T1, T2>* sourceEdge = sourceNode->adjacent;

	while (sourceEdge != nullptr && sourceEdge->destination->info != destination)
	{
		sourceEdge = sourceEdge->link;
	}

	return sourceEdge;
}

template <class T1, class T2>
void DynamicGraph<T1, T2>::print() const
{
	LinkedNode<T1, T2>* currentNode = this->start;

	while (currentNode != nullptr)
	{
		cout << currentNode->info << " -> ";

		Edge<T1, T2>* currentEdge = currentNode->adjacent;

		while (currentEdge != nullptr)
		{
			cout << currentEdge->destination->info << " (W: " << currentEdge->weight << ") | ";

			currentEdge = currentEdge->link;
		}

		currentNode = currentNode->next;

		cout << endl;
	}
}

template <class T1, class T2>
int DynamicGraph<T1, T2>::breadthTraversal(T1 element) const
{
	LinkedNode<T1, T2>* currentNode = this->findNode(element);

	if (currentNode == nullptr)
	{
		return -1;
	}

	LinkedNode<T1, T2>* tempNode = this->start;

	while (tempNode != nullptr)
	{
		tempNode->status = NotProcessed;

		tempNode = tempNode->next;
	}

	StaticQueue<LinkedNode<T1, T2>*>* queue =
		new StaticQueue<LinkedNode<T1, T2>*>(this->numberOfNodes);

	queue->enqueue(currentNode);

	currentNode->status = Located;

	unsigned int numberOfVisitedNodes = 0;

	while (!queue->isEmpty())
	{
		currentNode = queue->dequeue();

		currentNode->status = Processed;

		cout << currentNode->info << " ";

		numberOfVisitedNodes++;

		Edge<T1, T2>* currentEdge = currentNode->adjacent;

		while (currentEdge != nullptr)
		{
			if (currentEdge->destination->status == NotProcessed)
			{
				queue->enqueue(currentEdge->destination);

				currentEdge->destination->status = Located;
			}

			currentEdge = currentEdge->link;
		}
	}

	delete queue;

	return numberOfVisitedNodes;
}

template <class T1, class T2>
bool DynamicGraph<T1, T2>::deleteEdgeWithMaxWeight() const
{
	if (this->isEmpty())
	{
		return false;
	}

	LinkedNode<T1, T2>* currentNode = this->start;
	LinkedNode<T1, T2>* nodeWithMaxEdgeWeight = this->start;
	Edge<T1, T2>* previousToMaxEdge = nullptr;

	T2 maxWeight = (T2)0;

	while (currentNode != nullptr)
	{
		Edge<T1, T2>* currentEdge = currentNode->adjacent;
		Edge<T1, T2>* previousEdge = nullptr;

		while (currentEdge != nullptr)
		{
			if (currentEdge->weight > maxWeight)
			{
				nodeWithMaxEdgeWeight = currentNode;
				previousToMaxEdge = previousEdge;
				maxWeight = currentEdge->weight;
			}

			previousEdge = currentEdge;
			currentEdge = currentEdge->link;
		}

		currentNode = currentNode->next;
	}

	if (previousToMaxEdge == nullptr)
	{
		if (nodeWithMaxEdgeWeight->adjacent == nullptr)
		{
			return false; // Ne postoji nijedan poteg.
		}

		Edge<T1, T2>* tempEdge = nodeWithMaxEdgeWeight->adjacent;

		nodeWithMaxEdgeWeight->adjacent = tempEdge->link;

		delete tempEdge;
	}
	else
	{
		Edge<T1, T2>* tempEdge = previousToMaxEdge->link;

		previousToMaxEdge->link = tempEdge->link;

		delete tempEdge;
	}

	return true;
}

template <class T1, class T2>
int DynamicGraph<T1, T2>::minLengthCycle() const
{
	if (this->isEmpty())
	{
		return -1;
	}

	LinkedNode<T1, T2>* currentNode = this->start;

	int minLength = INT_MAX;

	while (currentNode != nullptr)
	{
		LinkedNode<T1, T2>* tempNode = this->start;

		while (tempNode != nullptr)
		{
			tempNode->status = NotProcessed;

			tempNode = tempNode->next;
		}

		currentNode->status = Located;
		currentNode->length = 0;

		StaticQueue<LinkedNode<T1, T2>*>* queue =
			new StaticQueue<LinkedNode<T1, T2>*>(this->numberOfNodes);

		queue->enqueue(currentNode);

		bool isCycle = false;

		while (!queue->isEmpty() && !isCycle)
		{
			tempNode = queue->dequeue();

			tempNode->status = Processed;

			Edge<T1, T2>* currentEdge = tempNode->adjacent;

			while (currentEdge != nullptr && currentEdge->destination != currentNode)
			{
				if (currentEdge->destination->status == NotProcessed)
				{
					currentEdge->destination->status = Located;
					currentEdge->destination->length = tempNode->length + 1;

					queue->enqueue(currentEdge->destination);
				}

				currentEdge = currentEdge->link;
			}

			if (currentEdge != nullptr && currentEdge->destination == currentNode)
			{
				if (minLength > ((int)tempNode->length + 1))
				{
					minLength = tempNode->length + 1;
				}

				isCycle = true;
			}
		}

		delete queue;

		currentNode = currentNode->next;
	}

	if (minLength == INT_MAX)
	{
		return -1; // Ne postoji nijedan poteg/ciklus.
	}

	return minLength;
}