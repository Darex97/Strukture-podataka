#pragma once
#include "Cvor.h"
#include <iostream>
using namespace std;

class Lista {

public:

	Cvor *head, *tail;
public:

	Lista()
	{
		head = tail = NULL;
	}
	~Lista()
	{
	}
	bool isEmpty()
	{
		return head == NULL;
	}
	void AddToHead(double elm)
	{
		head = new Cvor(elm, head);
		if (tail == NULL)
			tail = head;
	}
	void AddToTail(double elm)
	{
		if (!isEmpty())
		{
			tail->next = new Cvor(elm);
			tail = tail->next;
		}
		else
			head = tail = new Cvor(elm);
	}
	void printAll()
	{
		for (Cvor* tmp = head; tmp != NULL; tmp = tmp->next)
		{
			cout << tmp->print() << " ";
			
		}
	}
};