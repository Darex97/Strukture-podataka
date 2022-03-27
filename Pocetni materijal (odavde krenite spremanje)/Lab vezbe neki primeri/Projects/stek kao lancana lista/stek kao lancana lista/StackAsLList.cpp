#include "Node.h"
#include "StackAsLList.h"
#include <iostream>
using namespace std;

StackAsLList::StackAsLList()
{
	top = NULL;
}
void StackAsLList::addToTop(int el)
{
	if (top == NULL)
	{
		top = new Node(el);
		noElem++;
	}
	else
	{
		top = new Node(el, top);
		noElem++;
	}
}
int StackAsLList::deleteFromTop()
{
	int el;
	Node * pom1;
	if (isEmpty())
		throw "Stek je prazan";
	else
		el = top->info;
		pom1 = top;
		top = top->next;
		delete pom1;
		noElem--;
		return el;
}

int	StackAsLList::getElement()
{
	int el;
	if (isEmpty())
		throw "Stek je prazan";
	else
		el = top->info;
	return el;
}
void StackAsLList::print()
{
	if (isEmpty())
		throw "Stek je prazan";
	else
		for (Node * tmp = top; tmp != NULL; tmp = tmp->next)
			cout << tmp->getInfo() << endl;
}
int StackAsLList::numberOfElements()
{
	return noElem;
}