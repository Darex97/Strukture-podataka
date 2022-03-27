#pragma once
#include <iostream>

using namespace std;

template <class T>
class CNode
{
public:
	int i;
	int j;
	T data;
	CNode* nextrow;
	CNode* nextcol;

	CNode(void);
	CNode(int i, int j, T data, CNode* nextrow, CNode* nextcol);
	~CNode(void);
};

template <class T>
CNode<T>::CNode(void)
{
	nextrow = nextcol = NULL;
}

template <class T>
CNode<T>::CNode(int i, int j, T data, CNode* nextrow, CNode* nextcol)
{
	this->i = i;
	this->j = j;
	this->data = data;
	this->nextrow = nextrow;
	this->nextcol = nextcol;
}

template <class T>
CNode<T>::~CNode(void)
{
}