#pragma once
#include<iostream>
using namespace std;
class SLLNode
{
public:
	int info;
	SLLNode *next;
	SLLNode(){next=NULL;} 
	SLLNode(int el)
	{
		info=el;
		next=NULL;
	}
	SLLNode(int el, SLLNode *n) {
	info = el; next = n;
	}
	~SLLNode(void); 
	int print() {return info;};
};