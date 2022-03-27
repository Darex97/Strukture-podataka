#pragma once
#include "Edge.h"
#include "LinkedNode.h"

class GraphAsList
{
public:
	LinkedNode *start;
	int noElem;

	GraphAsList()
	{
		start = NULL;
		noElem = 0;
	}

	~GraphAsList()
	{}

	bool insertNode(int el)
	{
		LinkedNode *newNode = new LinkedNode(el, NULL, start, 0);
		if (newNode == NULL) return false;
		start = newNode;
		noElem++;
		return true;
	}
	LinkedNode* findNode(int el)
	{
		LinkedNode* ptr = start;
		while (ptr != NULL && el != ptr->node)
			ptr = ptr->next;
		return ptr;
	}
	Edge * findEdge(int a, int b)
	{
		LinkedNode *pa = findNode(a);
		LinkedNode *pb = findNode(b);
		if (pa == NULL || pb == NULL)
			return NULL;
		Edge *ptr = pa->adj;
		while (ptr != NULL && ptr->dest != pb)
			ptr = ptr->link;
		return ptr;
	}

	bool insertEdge(int a, int b)
	{
		LinkedNode* pa = findNode(a);
		LinkedNode* pb = findNode(b);
		if (pa == NULL || pb == NULL)
			return false;
		Edge *ptr = new Edge(pb, pa->adj);
		if (ptr == NULL) return false;
		pa->adj = ptr;
		return true;
	}
	void print()
	{
		LinkedNode *ptr = start;
		while (ptr != NULL)
		{
			cout << ptr->node << "->";
			Edge *pa = ptr->adj;
			while (pa != NULL)
			{
				cout << pa->dest->node << "|";
				pa = pa->link;
			}
			cout << "\r\n";
			ptr = ptr->next;
		}
	}

	void zeroInDeg()
	{
		if (start == NULL)
			throw "Graf je prazan!";
		LinkedNode* ptr1 = start;
		Edge* ptr2;
		while (ptr1 != NULL)			//ako koristim ponovo funkciju, postavljam ulazniStepen na 0 za svaki cvor
		{
			ptr1->ulazniStepen = 0;
			ptr1 = ptr1->next;
		}
		ptr1 = start;
		while (ptr1 != NULL) // postavljanje ulaznih stepena za svaki cvor
		{
			ptr2 = ptr1->adj;
			while (ptr2 != NULL)
			{
				ptr2->dest->ulazniStepen++;
				ptr2 = ptr2->link;
			}
			ptr1 = ptr1->next;
		}
		ptr1 = start;
		int n = 0;		 // broj trazenih cvorova
		cout << "Cvorovi sa 0 ulaznim stepenom: ";
		while (ptr1 != NULL)
		{
			if (ptr1->ulazniStepen == 0)
			{
				n++;							//ako postoji cvor sa 0 ulaznim step. onda povecavam brojac i stampam taj cvor
				cout << ptr1->node << " ";
			}
			ptr1 = ptr1->next;
		}
		if (n == 0)
			cout << "Ne postoji takav cvor!";
		cout << endl;
	}

	void zeroIndeg(LinkedNode* zaroNodes, int *size)
	{
		if (zaroNodes == NULL)
			throw "Graf je prazan!";
	
		while (size != NULL)
		{
			while (zaroNodes != NULL)
			{
				Edge *ptr2 = zaroNodes->adj;
				while (ptr2 != NULL)
				{
					ptr2->dest->ulazniStepen++;
					ptr2 = ptr2->link;
				}
				zaroNodes = zaroNodes->next;
			}
			zaroNodes = start;
			while (zaroNodes != NULL && zaroNodes->ulazniStepen != 0)
			{
				zaroNodes = zaroNodes->next;
			}
			if (zaroNodes == NULL)
				throw "Ne postoji cvor sa 0 ulaznim stepenom";
		}
	}
};