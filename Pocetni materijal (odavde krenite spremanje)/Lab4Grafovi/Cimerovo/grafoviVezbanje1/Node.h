#include "Edge.h"
class Node
{
public:
	int status;
	int info;
	Edge* firstEdge;
	Node* nextNode;
	int rastojanje;
	bool obradjen;
	Node(Node* x, int i)
	{
		info = i;
		firstEdge = NULL;
		nextNode = x;
	}
	~Node()
	{
		Edge* pom;
		while (firstEdge != NULL)
		{
			pom = firstEdge;
			firstEdge = firstEdge->nextEdge;
			delete pom;
		}
	}
};