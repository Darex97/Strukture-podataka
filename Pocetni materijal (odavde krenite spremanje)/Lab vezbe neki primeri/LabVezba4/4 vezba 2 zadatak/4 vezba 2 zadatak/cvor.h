#pragma once
#include<iostream>
using namespace std;
template<class t>
class cvor
{
public:
	t info;
	cvor<t> *next;
	cvor(){next=NULL;}
	cvor(t r){info=r;next=NULL;}
	cvor(t r,cvor<t> *n){info=r;next=n;}
	bool isequal(t el){return el==info;}

};