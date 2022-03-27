#pragma once
#include "SLNode.h"

template<class T>
class SLList {
private:
	SLNode<T>* head;
	SLNode<T>* tail;
public:
	SLList() { head = tail = nullptr; }
	~SLList() { while (!isEmpty()) removeFromHead(); }
	bool isEmpty() {
		return head == nullptr;
	}
	SLNode<T>* getHead() { return head; }
	SLNode<T>* getTail() { return tail; }
	void printList() {
		SLNode<T>* ptr = head;
		while (ptr != nullptr) {
			cout << ptr->getValue() << "|" << ptr->getNext() << " -> ";;
			ptr = ptr->getNext();
		}
	}
	SLNode<T>* find(T value) {
		SLNode<T>* ptr = head;
		while (ptr != nullptr && ptr->getValue() != value) {
			ptr = ptr->getNext();
		}
		return ptr;
	}
	void insertHead(T value) {
		SLNode<T>* node = new SLNode<T>(value, head);
		if (!head)
			tail = node;
		head = node;
	}
	void insertTail(T value) {
		SLNode<T>* node = new SLNode<T>(value,nullptr);
		if (!tail)
			head = node;
		else
			tail->getNextRef() = node;
		tail = node;
	}

	void insertBefore(T value, T spot) {
		SLNode<T>* prev = nullptr;
		SLNode<T>* ptr = head;
		while (ptr != nullptr && ptr->getValue()!=spot) {
			prev = ptr;
			ptr = ptr->getNext();
		}
		if (!ptr)
			throw exception("Element not found.");
		else
		{
			SLNode<T>* node = new SLNode<T>(value, ptr);
			if (prev == nullptr)
				head = node;
			else
				prev->getNextRef() = node;
		}
	}
	void insertAfter(T value, T spot) {
		SLNode<T>* ptr = head;
		while (ptr != nullptr && ptr->getValue() != spot) {
			ptr = ptr->getNext();
		}
		if (ptr == nullptr)
			throw exception("Element not found.");
		else
		{
			SLNode<T>* node = new SLNode<T>(value, ptr->getNext());
			ptr->getNextRef() = node;
			if (ptr == tail)
				tail = node;
		}
	}
	void remove(T value) {
		SLNode<T>* prev = nullptr;
		SLNode<T>* ptr = head;
		while (ptr != nullptr && ptr->getValue() != value) {
			prev = ptr;
			ptr = ptr->getNext();
		}
		if (isEmpty())
			throw exception("The list is empty.");
		if (head == tail && head->getValue() == value)
			head = tail = nullptr;
		else if (head->getValue() == value)
			head = head->getNext();
		else {
			if (ptr != nullptr)
			{
				prev->getNextRef() = ptr->getNext();
				if (ptr == tail)
					tail = prev;
			}
			else
				throw exception("Element not found.");
		}

		delete ptr;
	}

	void removeFromHead() {
		if (!head)
			throw exception("The list is empty");
		else
		{
			SLNode<T>* ptr = head;
			if (tail == ptr)
				tail = nullptr;
			head = ptr->getNext();
			delete ptr;
		}
	}
	void removeFromTail() {
		if(!tail)
			throw exception("The list is empty");
		else
		{
			SLNode<T>* ptr = tail;
			if (head == tail)
			{
				tail = nullptr;
				head = nullptr;
			}
			else {
				SLNode<T>* tmp = head;
				while (tmp != nullptr && tmp->getNext() != tail) {
					tmp = tmp->getNext();
				}
				tail = tmp;
				tmp->getNextRef() = nullptr;
			}
			delete ptr;
		}
	}
	
};