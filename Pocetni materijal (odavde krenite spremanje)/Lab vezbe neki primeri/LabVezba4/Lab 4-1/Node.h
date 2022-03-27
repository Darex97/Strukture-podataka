#pragma once

template <class T>
class CNode
{
public:
	CNode* next;
	T data;

	CNode(void);
	CNode(T data, CNode* next);
	~CNode(void);
};

template <class T>
CNode<T>::CNode(T data, CNode* next) {
	this->data = data;
	this->next = next;
}