#pragma once
#include"SLNode.h"

class CSortList
{
private:
	SLLNode *head;
	SLLNode *tail;
public:
	CSortList();
	void AddToHead(int number);
	void Sort(bool up);
	void PRINT();
	void SwapNeighbours(SLLNode *tmp,SLLNode *prev);
	~CSortList();
};

