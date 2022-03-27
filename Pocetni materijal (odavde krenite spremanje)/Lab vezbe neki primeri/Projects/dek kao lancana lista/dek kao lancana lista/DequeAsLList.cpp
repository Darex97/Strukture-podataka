#include "DequeAsLList.h"
#include "Node.h"
#include <iostream>
using namespace std;

DequeAsLList::DequeAsLList()
{
	head = tail = NULL;
	noElem = 0;
}

void DequeAsLList::enqueueHead(int el)
{
	if (!isEmpty())
	{
		head = new Node(el, NULL, head);
		head->next->prev = head;
		noElem++;
	}
	else
	{
		head = tail = new Node(el);
		noElem++;
	}
}
void DequeAsLList::enqueueTail(int el)
{
	if (!isEmpty())
	{
		tail = new Node(el, tail, NULL);
		tail->prev->next = tail;
		noElem++;
	}
	else
	{
		head = tail = new Node(el);
		noElem++;
	}
}
int DequeAsLList::dequeueHead()
{
	Node* pom;
	int elem;
	if (isEmpty())
		throw "Dek je prazan!";
	else
	{
		pom = head;
		elem = head->info;
		if (head == tail)
		{
			head = tail = NULL;
		}
		else
		{
			head = head->next;
			head->prev = NULL;
		}
		delete pom;
		noElem--;
		return elem;
	}
}
int DequeAsLList::dequeueTail()
{
	Node* pom;
	int elem;
	if (isEmpty())
		throw "Dek je prazan!";
	else
	{
		pom = tail;
		elem = tail->info;
		if (head == tail)
		{
			head = tail = NULL;
		}
		else
		{

			tail = tail->prev;
			tail->next = NULL;
		}
		delete pom;
		noElem--;
		return elem;
	}
}
int DequeAsLList::getHead()
{
	int elem;
	if (isEmpty())
		throw "Dek je prazan!";
	else
		elem = head->info;
	return elem;
}
int DequeAsLList::getTail()
{
	int elem;
	if (isEmpty())
		throw "Dek je prazan!";
	else
		elem = tail->info;
	return elem;
}
bool DequeAsLList::isEmpty()
{
	return (noElem == 0);
}
int DequeAsLList::numberOfElements()
{
	return noElem;
}
void DequeAsLList::print()
{
	for (Node* tmp = head; tmp != NULL; tmp = tmp->next)
	{
		cout << tmp->getInfo() << " ";
	}
}
