#pragma once

#include <iostream>

#include <stack>

#include "Node.h"

using namespace std;

class MaxHeap
{
public:
	MaxHeap();
	~MaxHeap();

	bool isEmpty() { return _root == 0; }

	void insert(int element);
	void heapInsert(int element);

	void mix(MaxHeap& mh1, MaxHeap& mh2);
	void toMinHeap();

private:
	Node* _root;
	int _numberOfElements;

	void invertInsert(int element);
	void heapInvertInsert(int element);
	void _delete(Node* node);

	int* toArray();
	int* toOrganizedArray();

	Node** toNodeArray();
	Node** toOrganizedNodeArray();

	void reset() { _delete(_root); _root = 0; }
};