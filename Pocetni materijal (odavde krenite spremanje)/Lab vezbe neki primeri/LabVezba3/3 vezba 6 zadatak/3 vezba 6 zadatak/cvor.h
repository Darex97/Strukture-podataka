#pragma once
#include<iostream>
using namespace std;
class cvor
{
public:
	int info;
	cvor *next;
	cvor(){next=NULL;}
	cvor(int a){info=a;next=NULL;}
	cvor(int a,cvor *t){info=a;next=t;}
	~cvor(void);
};
