#pragma once
#include "cvor.h"
#include<iostream>
using namespace std;
class dekkaolista
{
protected:
	cvor *head;
	cvor *tail;
public:
	dekkaolista(){head=tail=NULL;}
	~dekkaolista(void);
	void addtohead(int el);
	void addtotail(int el);
	int deletefromhead();
	int deletefromtail();
	void printall();
};
