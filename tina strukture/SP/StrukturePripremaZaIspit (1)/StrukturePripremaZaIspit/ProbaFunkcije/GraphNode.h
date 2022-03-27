#pragma once
#include <iostream>
#include "GraphEdge.h"
using namespace std;

class GraphNode {
private:
	GraphNode* next;
	GraphEdge* edges;
	int value;
	int status;
public:
	GraphNode(int val) {
		value = val;
		next = nullptr;
		edges = nullptr;
		status = 0;
	}
	GraphNode(int val,GraphNode* next) {
		value = val;
		this->next = next;
		edges = nullptr;
		status = 0;
	}
	//~GraphNode() { delete next, edges; next = edges = nullptr; }
	int getValue() { return value; }
	GraphNode* getNext() { return next; }
	GraphEdge* getEdges() { return edges; }
	GraphEdge*& getEdgesRef() { return edges; }
};