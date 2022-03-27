#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class DequeAsLList
{
public:
	Node* head, *tail;
	int noElem;
public:
	DequeAsLList();
	~DequeAsLList() {}
	void enqueueHead(int el);
	void enqueueTail(int el);
	int dequeueHead();
	int dequeueTail();
	int getHead();
	int getTail();
	bool isEmpty();
	int numberOfElements();
	void print();
};