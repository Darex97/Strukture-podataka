#pragma once
#include "GraphAsLists.h"
#include"Edge.h"
#include"LinkedNode.h"
void GraphAsLists::print()
{
	LinkedNode* ptr = start;
	while (ptr != NULL)
	{
		cout << ptr->node << "->";
		Edge* pa = ptr->adj;
		while (pa != NULL)
		{
			cout << pa->dest->node << "|";
			pa = pa->link;
		}
		cout << "\r\n";
		ptr = ptr->next;
	}
}
	LinkedNode* GraphAsLists::findNode(int pod)
	{
		LinkedNode* ptr = start;
		while (ptr != NULL && ptr->node != pod)
			ptr = ptr->next;
		return ptr;

	}
	Edge* GraphAsLists::findEdge(int a, int b)
	{
		LinkedNode* pa = findNode(a);
		LinkedNode* pb = findNode(b);
		if (pa == NULL || pb == NULL)
			return NULL;
		Edge* ptr = pa->adj;
		while (ptr != NULL && ptr->dest != pb)
			ptr = ptr->link;
		return ptr;
	}
	bool GraphAsLists::inserNode(int t)
	{
		LinkedNode* newNode = new LinkedNode(t, NULL, start, 0);
		if (newNode == NULL)
			return false;
		start = newNode;
		nodeNum++;
		return true;

	}
	bool GraphAsLists::insertEdge(int a, int b,int w)//modifikovana sa tezinu
	{
		LinkedNode* pa = findNode(a);
		LinkedNode* pb = findNode(b);
		if (pa == NULL || pb == NULL)
			return false;
		Edge* ptr = new Edge(pb, pa->adj,w);
		if (ptr == NULL)
			return false;
		pa->adj = ptr;
		return true;

	}
	bool GraphAsLists::deleteEdge(int a, int b)
	{
		Edge* pot = findEdge(a, b);
		if (pot == NULL)
			return false;
		LinkedNode* pa = findNode(a);
		if (pot == pa->adj)
		{
			pa->adj = pot->link;
			delete pot;
			return true;
		}
		Edge* tpot = pa->adj;
		while (tpot->link != pot)
			tpot = tpot->link;
		tpot->link = pot->link;
		delete pot;
		return true;


	}
	/*bool GraphAsLists::deleteNode(int pod)
	{
		LinkedNode* ptr;
		if (start == NULL)
			return false;
		if (start->node == pod)
		{
			Edge* pot = start->adj;
			while(pot!=NULL)
			{
				Edge* tpot = pot->link;
				delete pot;
				pot = tpot;

			}
			deleteEdgeToNode(start);
			ptr = start;
			start = start->next;
			delete ptr;
			nodeNum--;
			return true;
		}
		else
		{
			ptr = start->next;
			LinkedNode* par = start;
			while (ptr != NULL && ptr->node != pod)
			{
				par = ptr;
				ptr = ptr->next;
			}
			if (ptr == NULL)
				return false;
			par->next = ptr->next;
			Edge* pot = ptr->adj;
			while(pot!=NULL)
			{
				Edge* tpot = pot->link;
				delete pot;
				pot = tpot;
			}
			deleteEdgeToNode(ptr);
			delete ptr;
			nodeNum--;
			return true;
		}

	}*/
	bool GraphAsLists::Merge(int id1, int id2)
	{
		LinkedNode* i1, * i2,*i3;
		i1 = findNode(id1);
		i2 = findNode(id2);
		if (i1 == NULL || i2 == NULL)
			return false;
		Edge* a, * b,*c;
		b = i2->adj;
		a = i1->adj;
		while (b)
		{
			while (a->link != NULL)
				a = a->link;
			a->link = b;
			b = b->link;
			
		}
		a = i1->adj;
		if(a!=NULL)
		b = i1->adj->link;
		if (b != NULL)
			c = i1->adj->link->link;
		else c = NULL;
		if (a->dest == b->dest)
		{
			a->link = b->link;
			delete b;
			a = i1->adj;
			if(a!=NULL)
			b = i1->adj->link;
			if (b != NULL)
				c = i1->adj->link->link;
			else c = NULL;

		}
		while (a)
		{
			while (c)
			{
				if (a == c)
				{
					b->link = c->link;
					delete c;
					
					b = i1->adj->link;
					if(b!=NULL)
					c = i1->adj->link->link;
				}
				
				b = b->link;
				c = c->link;
			}
			a = a->link;
		}
		i3 = start;
		while (i3)
		{
			if (i3->node != i2->node)
			{
				a = i3->adj;
				while (a)
				{
					if (a->dest == i2)
						a->dest = i1;
					a = a->link;
				}

			}
			
			i3 = i3->next;
		}
		i3 = start;
		i1 = i3->next;
		while (i1)
		{
			if (i1->node == i2->node)
				i3->next = i2->next;
			i3 = i3->next;
			i1 = i1->next;
		}

		
		delete i2;
		//i2->adj = NULL;
		return true;

	}
	int GraphAsLists::Putavionom(int id)
	{
		LinkedNode* sledeci=NULL;
		LinkedNode* p = findNode(id);
		if (p == NULL)
			return 0;
		int maxp = 0;
		Edge* pomocni;
		
		while (p)
		{
			pomocni = p->adj;
			int trazim = 0;
			if (pomocni == NULL)
				return maxp;
			else
			{
				while (pomocni)
				{
					if (pomocni->weight > trazim)
					{
						trazim = pomocni->weight;
						sledeci = pomocni->dest;
					}
					pomocni = pomocni->link;
				}
			
			
			}
			maxp = maxp + trazim;
			p = sledeci;
		}
		
		


	}
	int GraphAsLists::Proslipredmeti(int predmeti[])
	{
		Edge* pom;
		LinkedNode* a;
		int* p = predmeti;
		
		int potrebni = 0;
		while (*p>=0)
		{
			a = findNode(*p);
			int dodaj = 0;
			if (a == NULL)
				potrebni = potrebni + dodaj;
			else
			{
				pom = a->adj;
				while (pom)
				{
					dodaj++;
					pom = pom->link;
				}
				potrebni = potrebni + dodaj;
			}
			
			p++;
		}

		return potrebni;
	}