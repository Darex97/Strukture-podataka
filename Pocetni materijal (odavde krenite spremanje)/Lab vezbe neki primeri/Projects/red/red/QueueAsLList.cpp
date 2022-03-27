#include "Node.h"
#include "QueueAsLList.h"
#include <iostream>
using namespace std;


QueueAsLList::QueueAsLList()
{
	head = tail = NULL;
}
QueueAsLList::~QueueAsLList()
{

}
int QueueAsLList::getHead()
{
	if (isEmpty())
		throw "Red je prazan";
	else
		return head->getInfo();
}
void QueueAsLList::enqueue(int el)
{
	if (isEmpty())
	{
		head = tail = new Node(el);
		noElem++;
	}
	else
	{
		tail->next = new Node(el);
		tail = tail->next;
		noElem++;
	}
	 
}
int QueueAsLList::dequeue()
{
	Node * pom;
	int el;
	if (isEmpty())
		throw "Red je prazan";
	else
	{
		el = head->getInfo();
		pom = head;
		head = head->getNext();
		delete pom;
		noElem--;
		return el;
	}
}
int QueueAsLList::numberOfElements()
{
	return noElem;
}
void QueueAsLList::print()
{
	for (Node * tmp = head; tmp != NULL; tmp = tmp->next)
		cout << tmp->getInfo() << " ";
}