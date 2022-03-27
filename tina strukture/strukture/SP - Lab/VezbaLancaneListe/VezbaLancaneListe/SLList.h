#pragma once

#include <iostream>

using namespace std;

#include "SLLNode.h"
#include "DSException.h"

template <class T>
class SLList
{
private:
	SLLNode<T>* head;
	SLLNode<T>* tail;

public:
	SLList() { this->head = this->tail = nullptr; }

	void addToHead(T element);

	bool isEmpty() const { return this->head == nullptr; }

	T deleteFromTail();

	~SLList();

	void printAll() const;
	void removeDuplicates();

	void addToTail(T element);
	T deleteFromHead();
	SLLNode<T>* getNext(SLLNode<T>* ptr) const;
	T getHeadEl() const;
	bool isInList(T element) const;
	SLLNode<T>* findNodePtr(T element) const;
	T getNextEl(T element) const;
	void deleteEl(T element);

	SLLNode<T>* getHead() const { return this->head; }
	SLLNode<T>* getTail() const { return this->tail; }
};

template <class T>
void SLList<T>::addToHead(T element)
{
	this->head = new SLLNode<T>(element, this->head);

	if (this->tail == nullptr)
	{
		this->tail = this->head;
	}
}

template <class T>
T SLList<T>::deleteFromTail()
{
	if (this->isEmpty())
	{
		throw DSException("Singly Linked List is empty!");
	}

	SLLNode<T>* tempNode = this->tail;
	T tempNodeInfo = tempNode->info;

	if (this->head == this->tail)
	{
		this->head = this->tail = nullptr;
	}
	else
	{
		SLLNode<T>* temp = this->head;

		while (temp->next != this->tail)
		{
			temp = temp->next;
		}

		this->tail = temp;
		this->tail->next = nullptr;
	}

	delete tempNode;

	return tempNodeInfo;
}

template <class T>
SLList<T>::~SLList()
{
	while (!this->isEmpty())
	{
		T tempInfo = this->deleteFromTail();
	}
}

template <class T>
void SLList<T>::printAll() const
{
	if (this->isEmpty())
	{
		cout << "Singly Linked List is empty!" << endl;
	}
	else
	{
		for (SLLNode<T>* temp = this->head; temp != nullptr; temp = temp->next)
		{
			cout << temp->print() << " ";
		}

		cout << endl;
	}
}

template <class T>
void SLList<T>::removeDuplicates()
{
	if (this->isEmpty())
	{
		cout << "Singly Linked List is empty!" << endl;
	}
	else
	{
		for (SLLNode<T>* current = this->head; current != nullptr && current->next != nullptr;
			current = current->next)
		{
			SLLNode<T>* temp = current;

			while (temp->next != nullptr)
			{
				if (current->isEqual(temp->next->info))
				{
					SLLNode<T>* tempNode = temp->next;

					if (this->tail == tempNode)
					{
						this->tail = temp;
					}

					temp->next = tempNode->next;

					delete tempNode;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
	}
}

template <class T>
void SLList<T>::addToTail(T element)
{
	if (this->isEmpty())
	{
		this->head = this->tail = new SLLNode<T>(element);
	}
	else
	{
		this->tail->next = new SLLNode<T>(element);
		this->tail = this->tail->next;
	}
}

template <class T>
T SLList<T>::deleteFromHead()
{
	if (this->isEmpty())
	{
		throw DSException("Singly Linked List is empty!");
	}

	SLLNode<T>* tempNode = this->head;
	T tempNodeInfo = tempNode->info;

	if (this->head == this->tail)
	{
		this->head = this->tail = nullptr;
	}
	else
	{
		this->head = tempNode->next;
	}

	delete tempNode;

	return tempNodeInfo;
}

template <class T>
SLLNode<T>* SLList<T>::getNext(SLLNode<T>* ptr) const
{
	if (this->isEmpty())
	{
		throw DSException("Singly Linked List is empty!");
	}

	if (ptr == nullptr)
	{
		throw DSException("NULL pointer exception!");
	}

	return ptr->next;
}

template <class T>
T SLList<T>::getHeadEl() const
{
	if (this->isEmpty())
	{
		throw DSException("Singly Linked List is empty!");
	}

	return this->head->info;
}

template <class T>
bool SLList<T>::isInList(T element) const
{
	SLLNode<T>* temp = this->head;

	while (temp != nullptr && !temp->isEqual(element))
	{
		temp = temp->next;
	}

	return temp != nullptr;
}

template <class T>
SLLNode<T>* SLList<T>::findNodePtr(T element) const
{
	if (this->isEmpty())
	{
		throw DSException("Singly Linked List is empty!");
	}

	SLLNode<T>* temp = this->head;

	while (temp != nullptr && !temp->isEqual(element))
	{
		temp = temp->next;
	}

	if (temp == nullptr)
	{
		throw DSException("Element not found!");
	}

	return temp;
}

template <class T>
T SLList<T>::getNextEl(T element) const
{
	SLLNode<T>* temp = this->findNodePtr(element);

	if (temp->next == nullptr)
	{
		throw DSException("Next element does not exist!");
	}

	return temp->next->info;
}

template <class T>
void SLList<T>::deleteEl(T element)
{
	if (this->isEmpty())
	{
		cout << "Singly Linked List is empty!" << endl;
	}
	else if (this->head->isEqual(element))
	{
		T tempInfo = this->deleteFromHead();
	}
	else
	{
		SLLNode<T>* tempNode = this->findNodePtr(element);
		SLLNode<T>* beforeTempNode = this->head;

		while (beforeTempNode->next != tempNode)
		{
			beforeTempNode = beforeTempNode->next;
		}

		beforeTempNode->next = tempNode->next;

		if (this->tail == tempNode)
		{
			this->tail = beforeTempNode;
		}

		delete tempNode;
	}
}