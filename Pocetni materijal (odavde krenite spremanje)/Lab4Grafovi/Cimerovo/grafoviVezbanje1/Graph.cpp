#include "Graph.h"
#include "magacin.h"
#include "red.h"
Graph::~Graph()
{
	Node* pom;
	while (start != NULL)
	{
		pom = start;
		start = start->nextNode;
		delete pom;
	}
	/*if (mat != NULL)
	{
		for (int i = 0; i < brCvorova; i++)
			delete[] mat[i];
		delete[] mat;
	}*/
}
void Graph::addNode(int a)
{
	start = new Node(start, a);
	brCvorova++;
}
void Graph::addEdge(int a, int b, int w)
{
	Node* x = findNode(a), *y=findNode(b);
	Edge* pom;
	if (x != NULL && y != NULL)
	{
		if (x->firstEdge == NULL || x->firstEdge->endNode->info > b)
		{
			x->firstEdge = new Edge(y, x->firstEdge, w);
		}
		else
		{
			pom = x->firstEdge;
			while (pom->nextEdge != NULL && pom->nextEdge->endNode->info < b)
				pom = pom->nextEdge;
			pom->nextEdge = new Edge(y, pom->nextEdge, w);

		}
		/*if (y->firstEdge == NULL || y->firstEdge->endNode->info > a)
		{
			y->firstEdge = new Edge(x, y->firstEdge, w);
		}
		else
		{
			pom = y->firstEdge;
			while (pom->nextEdge != NULL && pom->nextEdge->endNode->info < a)
				pom = pom->nextEdge;
			pom->nextEdge = new Edge(x, pom->nextEdge, w);
				
		}*/
	}
}
void Graph::printGraph()
{
	Node* pom = start;
	Edge* pom1;
	while (pom != NULL)
	{
		cout << pom->info << " -> ";
		pom1 = pom->firstEdge;
		while (pom1 != NULL)
		{
			cout << pom1->endNode->info << " | ";
			pom1 = pom1->nextEdge;		
		}
		cout << endl;
		pom = pom->nextNode;
	}
}
void Graph::printBFS(Node* n)
{
	Node* pom = start;
	Edge* pom1;
	Red<Node*> R(20);
	while (pom != NULL)
	{
		pom->status = 0;
		pom = pom->nextNode;
	}
	pom = n;
	pom->status = 1;
	R.Push(pom);
	while (!R.isEmpty())
	{
		pom = R.Pop();
		cout << pom->info << " ";
		pom1 = pom->firstEdge;
		while (pom1 != NULL)
		{
			if (pom1->endNode->status == 0)
			{
				R.Push(pom1->endNode);
				pom1->endNode->status = 1;
			}
			pom1 = pom1->nextEdge;
		}
	}
	cout << endl;
}
void Graph::traverseDFS(Node* n)
{
	if (n == NULL)
		return;
	Node* pom = start;
	while (pom != NULL)
	{
		pom->status = 0;
		pom = pom->nextNode;
	}
	cout << n->info<< " ";
	DFS(n);
	cout << endl;
}
void Graph::DFS(Node* n1)
{
	Edge* pom1 = n1->firstEdge;
	n1->status = 1;
	while (pom1 != NULL)
	{
		if (pom1->endNode->status == 0)
		{
			cout << pom1->endNode->info << " ";
			DFS(pom1->endNode);
		}
		pom1=pom1->nextEdge;
	}
}
//void Graph::traverseBFS(Node* n)
//{
//	if (n == NULL)
//		return;
//	Node* pom = start;
//	Edge* pom1;
//	while (pom != NULL)
//	{
//		pom->status = 0;
//		pom = pom->nextNode;
//	}
//	cout << n->info << " ";
//	n->status = 1;
//	BFS(n);
//	cout << endl;
//}
//void Graph::BFS(Node* n1)
//{
//	Edge* pom1 = n1->firstEdge;
//	while(pom1!=NULL)
//		if (pom1->endNode->status == 0)
//		{
//			cout << pom1->endNode->status << " ";
//			pom1->endNode->status = 1;
//		}
//	n1->status = 2;
//}
void Graph::dijikstrin(Node* n)
{
	Node* pom = start,*radni;
	Edge* pom1;
	int i = 0;
	while (pom != NULL)
	{
		pom->rastojanje = 500; //500 je "beskonacno" u odnosu na moje vrednosti 
		pom->obradjen = false;
		pom = pom->nextNode;
	}
	n->rastojanje = 0; //polazni cvor ima rastojanje 0 od samog sebe
	bool flag;
	radni = n;
	do
	{
		radni->obradjen = true;
		pom1 = radni->firstEdge;
		while (pom1 != NULL)
		{
			if (pom1->endNode->rastojanje > (radni->rastojanje + pom1->weight))
				pom1->endNode->rastojanje = radni->rastojanje + pom1->weight;
			pom1 = pom1->nextEdge;
		}
		flag = false;
		pom = start;
		radni = start;
		while (pom != NULL && !flag)
		{
			if (pom->obradjen == false)
			{
				flag = true;
				radni = pom;
			}
			pom = pom->nextNode;
		}
		while (pom != NULL)
		{
			if (pom->obradjen == false && pom->rastojanje < radni->rastojanje)
				radni = pom;
			pom = pom->nextNode;
		}
	} while (flag);
	pom = start;
	while (pom != NULL)
	{
		cout << pom->info << "  " << pom->rastojanje << endl;
		pom = pom->nextNode;
	}
}
void Graph::flojdov()
{
	mat = new int*[brCvorova];
	int i, j;
	for (i = 0; i < brCvorova; i++)
		mat[i] = new int[brCvorova];
	for (i=0;i<brCvorova;i++)
		for (j = 0; j < brCvorova; j++)
		{
			if (i == j)
				mat[i][j] = 0;
			else
				mat[i][j] = 500;
		}
	Node* pom = start;
	Edge* pom1;
	while (pom != NULL)
	{
		pom1 = pom->firstEdge;
		while (pom1 != NULL)
		{
			mat[pom->info][pom1->endNode->info] = pom1->weight;
			pom1 = pom1->nextEdge;
		}
		pom = pom->nextNode;
	}
	for (int k = 0; k < brCvorova; k++)
		for (i = 0; i<brCvorova; i++)
			for (j = 0; j < brCvorova; j++)
			{
				if (mat[i][j] > (mat[i][k] + mat[k][j]))
					mat[i][j] = mat[i][k] + mat[k][j];
			}
	for (i = 0; i < brCvorova; i++)
	{
		for (j = 0; j < brCvorova; j++)
			cout << mat[i][j] << "\t";
		cout << endl;
	}
}
void Graph :: topolosko()
{
	Red<Node*> R(10);
	int* nizUlStepen = new int[brCvorova];
	int* topoloskiNiz = new int[brCvorova];
	int k = 0;
	for (int i = 0; i < brCvorova; i++)
		nizUlStepen[i] = 0;
	Node* pom = start;
	Edge* pom1;
	while (pom != NULL)
	{
		pom1 = pom->firstEdge;
		while (pom1 != NULL)
		{
			nizUlStepen[pom1->endNode->info]++;
			pom1 = pom1->nextEdge;
		}
		pom = pom->nextNode;
	}
	for (int i = 0; i < brCvorova; i++)
		if (nizUlStepen[i] == 0)
			R.Push(findNode(i));
	while (!R.isEmpty())
	{
		pom = R.Pop();
		topoloskiNiz[k++] = pom->info;
		pom1 = pom->firstEdge;
		while (pom1 != NULL)
		{
			nizUlStepen[pom1->endNode->info ]--;
			if (nizUlStepen[pom1->endNode->info ] == 0)
				R.Push(pom1->endNode);
			pom1 = pom1->nextEdge;
		}
	}
	cout << endl;
	bool flag=true;
	for (int i = 0; i < brCvorova && flag; i++)
	{
		if (nizUlStepen[i] != 0)
			flag = false;
	}
	if (flag)
		for (int i = 0; i < brCvorova; i++)
			cout << topoloskiNiz[i] << " ";
	else
		cout << "ne moze da se uredi topoloski!";
	cout << endl;
	delete[] nizUlStepen;
}