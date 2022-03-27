#pragma once
#include"SLLNode.h"
class CSortList
{
private:
	SLLNode *head;
public:
	CSortList();
	void AddToHead(int number);
	void Sort(bool up);
	~CSortList(void);
};

