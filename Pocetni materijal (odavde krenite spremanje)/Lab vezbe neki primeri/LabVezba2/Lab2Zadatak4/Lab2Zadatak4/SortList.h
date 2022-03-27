#pragma once
#include"SLLNode.h"

class CSortList
{
	SLLNode *head;
public:
	CSortList();
	void AddToHead(int num);
	void Sort(bool up);
	void Swap(SLLNode *tmp1,SLLNode *prev1,SLLNode *tmp2,SLLNode *prev2);
	void SwapNeighbours(SLLNode *tmp,SLLNode *prev);
	void PRINT();
	~CSortList(void);
};

