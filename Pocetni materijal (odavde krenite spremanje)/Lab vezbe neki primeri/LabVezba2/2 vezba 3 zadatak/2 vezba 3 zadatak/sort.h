#pragma once
#include "cvor.h"
#include<iostream>
using namespace std;
class sort
{
protected:
	cvor *head;
	cvor *tail;
public:
	sort(){head=tail=NULL;}
	~sort(void);
	void addtohead(int el);
	void printall();
	void bubblesort();
	void selectionsort();
};
