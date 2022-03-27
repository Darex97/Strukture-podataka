#pragma once
#include "GraphNode.h"

class GraphNode;
class GraphEdge {
private:
	GraphEdge* next;
	GraphNode* destination;
public:
	GraphEdge() { next = nullptr; destination = nullptr; }
	GraphEdge(GraphNode* dest) {
		destination = dest;
		next = nullptr;
	}
	GraphEdge(GraphEdge* link) { next = link; destination = nullptr; }
	GraphEdge(GraphNode* dest,GraphEdge* link) { next = link; destination = dest; }
	GraphEdge(GraphEdge* link, GraphNode* dest) :GraphEdge(dest, link) { ; }
	//~GraphEdge() { delete next, destination; next = destination = nullptr; }
	GraphEdge* getNext() { return next; }
	GraphNode* getDestination() { return destination; }
};