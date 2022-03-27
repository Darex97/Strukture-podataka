#pragma once
#include <stddef.h>
template <class T>
class NodeElement
{
public:
	T element;
	int x, y;
	NodeElement<T> * linkV, * linkK;

	NodeElement(T el, int x, int y)
	{
		this->x = x;
		this->y = y;
		element = el;
		linkK = linkV = NULL;
	}

	void podesiEl(NodeElement<T> * a, NodeElement<T> * b)
	{
		linkV = a;
		linkK = b;
	}

	~NodeElement() {}
};