#include <iostream>
using namespace std;
class Node;
class Edge
{
public:
	Node* endNode;
	Edge* nextEdge;
	int weight;
public:
	Edge(Node* n, Edge* e, int w)
	{
		endNode = n;
		nextEdge = e;
		weight = w;
	}
};