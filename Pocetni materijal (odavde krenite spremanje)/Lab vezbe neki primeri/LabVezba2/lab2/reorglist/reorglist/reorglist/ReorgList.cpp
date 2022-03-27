#include "ReorgList.h"

ReorgList::ReorgList() : _head(0) {}

ReorgList::~ReorgList()
{
	while(_head)
		removeFromHead();
}

void ReorgList::removeFromHead()
{
	if(_head)
	{
		Node* temp = _head;
		_head = _head->getNext();
		delete temp;
	}
}

void ReorgList::addToTail(Node& node)
{
	while(_head)
		_head = _head->getNext();
	_head->setNext(&node);
}

void ReorgList::addToHead(Node& node)
{
	node.setNext(_head);
	_head = &node;
}


void ReorgList::getToStart(int key)
{
	Node* iter = _head;
	Node* prev = 0;
	while(iter && iter->getData() != key)
	{
		prev = iter;
		iter = iter->getNext();
	}

	if(iter)
	{	
		prev->setNext(iter->getNext());//veza next prethodnog ide ispred trenutnog
		iter->setNext(_head);//ovamo vracamo vezu 
		_head = iter;//na pocetak
	}
	else
		cout << "Element not found!" << endl;

}
void ReorgList::getTransp(int key)
{
	Node* iter = _head;
	Node* prev = 0;
	Node* prevPrev = 0;
	while(iter && iter->getData() != key)
	{
		prevPrev = prev;
		prev = iter;
		iter = iter->getNext();
	}

	if(iter)
	{
		prevPrev->setNext(iter);
		prev->setNext(iter->getNext());
		iter->setNext(prev);
	}
	else
		cout << "Element not found!" << endl;
}

void ReorgList::print()
{
	Node* iter = _head;
	for(; iter; iter = iter->getNext())
	{
		cout << iter->getData() << " ";
	}
	cout << endl;
}

void ReorgList::addToHead()
{
	_head = new Node(rand() % 50, _head);
}