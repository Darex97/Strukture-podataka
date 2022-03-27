#pragma once
#include <iostream>
#include "GraphNode.h"
#include "GraphEdge.h"

class Graph {
private:
	GraphNode* start;
	unsigned int numberOfNodes;
public:
	Graph() {
		start = nullptr;
		numberOfNodes = 0;
	}
	void insertNode(int val) {
		GraphNode* newNode = new GraphNode(val, start);
		start = newNode;
		numberOfNodes++;
	}
	GraphNode* findNode(int val) {
		GraphNode* ptr = start;
		while (ptr != nullptr && ptr->getValue() != val)
			ptr = ptr->getNext();
		return ptr;
	}
	void insertEdge(int val1, int val2) {
		GraphNode* ptr = start;
		GraphNode* node1 = nullptr;
		GraphNode* node2 = nullptr;
		while (ptr != nullptr && (node1 == nullptr || node2 == nullptr)) {
			if (ptr->getValue() == val1)
				node1 = ptr;
			if (ptr->getValue() == val2)
				node2 = ptr;
			ptr = ptr->getNext();
		}
		if (node1 != nullptr && node2 != nullptr)
		{
			GraphEdge* tmp = new GraphEdge(node1->getEdges(), node2);
			node1->getEdgesRef() = tmp;
		}
	}
	GraphEdge* findEdge(int val1, int val2) {
		GraphNode* ptr = start;
		GraphNode* node1 = nullptr;
		GraphNode* node2 = nullptr;
		while (ptr != nullptr && (node1 == nullptr || node2 == nullptr)) {
			if (ptr->getValue() == val1)
				node1 = ptr;
			if (ptr->getValue() == val2)
				node2 = ptr;
			ptr = ptr->getNext();
		}
		if (node1 == nullptr || node2 == nullptr)
			return nullptr;
		GraphEdge* grana = node1->getEdges();
		while (grana != nullptr && grana->getDestination() != node2)
			grana = grana->getNext();
		return grana;
	}
	unsigned int numberOfLoops() {
		GraphNode* ptr = start;
		unsigned int num = 0;
		while (ptr != nullptr) {
			GraphEdge* link = ptr->getEdges();
			while (link != nullptr && link->getDestination() != ptr)
				link = link->getNext();
			if (link != nullptr)
				num++;
			ptr = ptr->getNext();
		}
		return num;
	}
	void printGraph() {
		GraphNode* ptr = start;
		while (ptr != nullptr)
		{
			cout << ptr->getValue() << "->";
			GraphEdge* pa = ptr->getEdges();
			while (pa != NULL) {
				cout << pa->getDestination()->getValue() << "|";
				pa = pa->getNext();
			}
			cout << "\r\n";
			ptr = ptr->getNext();
		}
	}

	bool canConnect(int a, int b, int n) {
		GraphNode* ptr = start;
		GraphNode* node1 = nullptr;
		GraphNode* node2 = nullptr;

		while (ptr != nullptr && (node1 == nullptr || node2 == nullptr)) {
			if (ptr->getValue() == a)
				node1 = ptr;
			if (ptr->getValue() == b)
				node2 = ptr;
			ptr = ptr->getNext();
		}

		if (node1 == nullptr || node2 == nullptr)
			return false;

		return canConnect(node1,node2,n);
	}
	bool canConnect(GraphNode* a, GraphNode* b, int n) {
		bool canConnect1 = false;
		GraphEdge* grana = a->getEdges();
		if (n == 0)
			return false;
		while (grana != nullptr && !canConnect1)
		{
			if (grana->getDestination() == b)
				return true;

			canConnect1 = canConnect(grana->getDestination(), b, n - 1);
			grana = grana->getNext();
		}
		return canConnect1;
	}
};