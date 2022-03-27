#pragma once
#include<iostream>
using namespace std;
class cvor
{
public:
	int info;
	cvor *next;
	

public:
	cvor(){next=NULL;}
	~cvor(void);
	cvor(int el){info=el; next=NULL;}
	cvor(int el,cvor *r){info=el; next=r;}
	int print(){return info;}
};
