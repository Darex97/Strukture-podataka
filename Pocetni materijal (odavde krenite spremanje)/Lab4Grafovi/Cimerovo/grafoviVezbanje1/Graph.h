#include "Node.h"

class Graph
{
private:
	Node* start;
	int brCvorova;
	int** mat;
public:
	Graph() {brCvorova = 0; start = NULL;}
	~Graph();
	void addNode(int a);
	void addEdge(int a, int b, int w);
	Node* findNode(int a)
	{
		Node* pom = start;
		while (pom != NULL && pom->info != a)
			pom = pom->nextNode;
		return pom;
	}
	void printGraph();
	void printBFS(Node* n);
	void traverseDFS(Node* n);
	void DFS(Node* n1);
	void traverseBFS(Node* n);
	void BFS(Node* n1);
	void dijikstrin(Node* n);
	void flojdov();
	void topolosko();//vraca false ako postoji ciklus
};