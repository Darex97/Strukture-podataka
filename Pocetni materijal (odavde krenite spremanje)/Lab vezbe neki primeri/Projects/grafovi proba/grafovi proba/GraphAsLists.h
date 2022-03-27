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
	//1.zadatak
	LinkedNode* maxInDeg()
	{
		if (start == NULL)
			throw "Graf je prazan!";
		LinkedNode* ptr1 = start;
		Edge* ptr2;
		while (ptr1 != NULL)		//ako koristim ponovo funkciju, postavljam ulazniStepen na 0 za svaki cvor
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
		LinkedNode* nodeMax = start; // cvor sa maksimalnim ulaznim stepenom
		int max = 0; // maksimalni ulazni stepen
		ptr1 = start;
		while (ptr1 != NULL)
		{
			if (ptr1->ulazniStepen > max)
			{
				max = ptr1->ulazniStepen;
				nodeMax = ptr1;
			}
			ptr1 = ptr1->next;
		}
		return nodeMax;		//vracam pokazivac na cvor sa max ulaznim stepenom
	}

	//2.zadatak
	LinkedNode* maxOutDeg()
	{
		if (start == NULL)
			throw "Graf je prazan!";
		LinkedNode* nodeMax = start; // cvor sa maksimalnim izlaznim stepenom
		LinkedNode* ptr1 = start;
		Edge* ptr2;
		int max = 0; // maksimalni izlazni stepen
		int t;
		while (ptr1 != NULL)
		{
			ptr2 = ptr1->adj;
			t = 0;
			while (ptr2 != NULL)
			{
				t++;
				ptr2 = ptr2->link;
			}
			if (t>max)
			{
				max = t;
				nodeMax = ptr1;
			}
			ptr1 = ptr1->next;
		}
		return nodeMax;		//vracam pokazivac na cvor sa max izlaznim stepenom
	}

	//3.zadatak
	void zeroOutDeg()
	{
		LinkedNode *ptr1 = start;
		int t=0;			//brojac koliko ima cvorova sa 0 izlaznim stepenom
		while (ptr1 != NULL)
		{
			if (ptr1->adj == NULL)
				ptr1->status = 1;			//ako postoji cvor koji nema Edge postavlja se status 1
			ptr1 = ptr1->next;				// u suprotnom ostaje status za taj cvor na 0 i ide se na sledeci cvor
		}
		ptr1 = start;
			cout << "Cvorovi sa 0 izlaznim stepenom: ";
		while (ptr1 != NULL)
		{
			if (ptr1->status == 1)
			{
				t++;		//ako ima neki cvor koji nema nijedan Edge onda se uvecava brojac
				cout << ptr1->node << " ";
			}
			ptr1 = ptr1->next;
		}
		if (t == 0)			
			cout << "Ne postoji takav cvor!" << endl;
		cout << endl;
	}

	//4.zadatak
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
	
	//5.zadatak
	void povezanost()
	{
		LinkedNode* ptr1 = start;
		Edge* ptr2;

		while (ptr1 != NULL)
		{
			int n = 0;
			ptr2 = ptr1->adj;
			while (ptr2 != NULL)
			{
				if (ptr2->dest != NULL)
					n++;
				ptr2 = ptr2->link;
			}
			if (n != noElem)
				throw "Graf je slabo povezan!";
			ptr1 = ptr1->next;
		}
		cout << "Graf je jako povezan!" << endl;
	}

	//6.zadatak
	int** matricaSusedstva()
	{
		int **matrix;
		matrix = new int*[this->noElem + 1];   //// matrica ce imati po jednu kolonu i vrstu vise zbog predstavljanja cvorova
		for (int i = 0; i<this->noElem + 1; i++)
			matrix[i] = new int[this->noElem + 1];

		for (int i = 0; i<this->noElem + 1; i++)    ////inicijalizujemo celu matricu susedstva na 0.
			for (int j = 0; j<this->noElem + 1; j++)
				matrix[i][j] = 0;

		LinkedNode *ptr1 = this->start;
		int i = 1;
		while (ptr1 != NULL)   //popunjavamo 0-tu vrstu i 0-tu kolonu vrednostima cvorova
		{
			matrix[0][i] = ptr1->node;
			matrix[i][0] = ptr1->node;
			i++;
			ptr1 = ptr1->next;
		}

		for (int i = 1; i <= this->noElem; i++)/// popunjavanje matrice susedstva vrednostima 0 i 1
		{
			for (int j = 1; j <= this->noElem; j++)
			{
				if (this->findEdge(matrix[i][0], matrix[0][j]) != NULL)
				{
					matrix[i][j] = 1;
				}
			}
		}
		return matrix;
	}
	void printMatrix(int** matrix)
	{
		cout << matrix[0][0] << " ";
		for (int i = 1; i <= this->noElem; i++)
			cout << matrix[0][i] << " ";
		cout << endl;
		for (int i = 1; i <= this->noElem; i++)
		{
			for (int j = 0; j <= this->noElem; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};
