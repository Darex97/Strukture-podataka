#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
class CLList
{
private:
	CNode* head;
public:
	CLList(void);
	void addToHead(T data);
	void deleteNode(CNode* ptr);
	//CNode* getNextElement(CNode* 
	~CLList(void);
};

template <class T>
CLList<T>::CLList() {
	head = NULL;
}

template <class T>
void CLList<T>::addToHead(T data) {
	CNode<T>* el = new CNode<T>(data, this->head);
	this->head = el;
}

template <class T>
void CLList<T>::deleteNode(CNode* ptr) {
	CNode *prev = NULL, *curr;

	while (curr = head; curr != ptr && curr->next != NULL; prev = curr, curr = curr->next);

	if (prev == NULL) {
		delete head;
		head = NULL;
	} else {
		if (curr == ptr) {
			prev->next = curr->next;
			delete curr;
		}
	}
}