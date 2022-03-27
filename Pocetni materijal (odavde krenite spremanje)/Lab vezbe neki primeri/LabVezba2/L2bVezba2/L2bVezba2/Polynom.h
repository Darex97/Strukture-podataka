#pragma once
#include"SLLNode.h"
class CPolynom
{
private:
	SLLNode *head;
	SLLNode *tail;
public:
	CPolynom();
	/*void AddTodHead(double coef,int exp);*/
	void AddToTail(double coef,int exp);
	void Add(double coef,int exp);
	void PRINT();
	void Merge(CPolynom *P1,CPolynom *P2);
	~CPolynom(void);
};

