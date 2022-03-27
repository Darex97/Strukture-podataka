#pragma once
#include "SLLnode.h"
#include "HashObject.h"
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
	int getHeadEl() { return head->info ;}
	void printAll();
	void addToHead(int el);
	void BubbleSort();
	HashObject getNextEl(HashObject obj);
	SLLNode* findNode(HashObject obj );
	void SwapNeighbors(SLLNode* ptr, SLLNode* prev);
};

