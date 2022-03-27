#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

/*template <class T>
class CNodeDataInfo
{
public:
	int num;
	CNode<T>* head;

	CNodeDataInfo(int num);
	
	void SetElementRow(int i, T el);
	~CNodeDataInfo(void);
};

template <class T>
CNodeDataInfo<T>::CNodeDataInfo(int num)
{
	this->num = num;
	this->head = NULL;
}

template <class T>
CNode<T>* CNodeDataInfo<T>::SetElement(int i, T el) {
	if (el == 0)
		return;

	if (head == NULL) {
		// First element
		CNode<T>* temp = new CNode<T>(num, i, NULL);
		head = temp;
		return head;
	}
	
	// Exists?
	for (temp = head; temp != NULL && temp->j == i; temp = temp->next);
	if (temp != NULL) {
		temp->data = el;
		return temp;
	}

	CNode* prev = NULL;
	for (temp = head; temp != NULL && temp->j < i; prev = temp, temp = temp->next);
	if (temp != NULL) {
		CNode<T>* temp = new CNode<T>(num, i, head);
		head = temp;
		return head;
	} else {
		CNode<T>* node = new CNode<T>(num, i, temp);
		prev->next = node;
		return node;
	}
}

template <class T>
void CNodeDataInfo<T>::SetSpecific(CNode<T>* p) {
	// First element?
	if (head == NULL) {
		head = p;
		return;
	}

	CNode<T>* temp;
	
	// Exists?
	for (temp = head; temp != NULL && temp == p; temp = temp->next);


}

template <class T>
CNodeDataInfo::~CNodeDataInfo(void)
{
}*/