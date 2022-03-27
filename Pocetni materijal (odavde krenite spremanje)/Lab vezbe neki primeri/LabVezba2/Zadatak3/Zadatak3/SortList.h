#pragma once
#include "SLLnode.h"
#include<iostream>
using namespace std;
class SortList
{
protected:
	SLLNode *head;
	SLLNode *tail;
public:
	SortList() {head=tail=NULL;}
	~SortList(void);
	void printAll();
	void addToHead(int el);
	void BubbleSort();
	void SwapNeighbors(SLLNode* ptr, SLLNode* prev);
};
