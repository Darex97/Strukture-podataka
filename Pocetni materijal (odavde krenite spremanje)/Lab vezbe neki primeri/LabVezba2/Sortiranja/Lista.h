#pragma once
#include "Node.h"
class Lista
{
	Node* head;
public:
	Lista(void){head=nullptr;}
	void AddToHead(int el);
	void printAll();
	void Bubble();
	void Insertion();
	void Selection();
	bool isEmpty(){return head == nullptr;}
	int deleteFromHead();
	~Lista(void);
};

