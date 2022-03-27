#pragma once
//#include"Edge.h"
#include<iostream>
using namespace std;

class Edge;  //zbog cega je ovo potrebno da bi program radio?

class LinkedNode
{
public:
	int node;
	Edge *adj;
	LinkedNode *next;
	int status;
	int indeg,outdeg;//ulazni/izlazni stepen
public:
	LinkedNode()
	{
		this->node=NULL;
		this->next=NULL;
		this->adj=NULL;
		this->status=0;
		this->indeg=this->outdeg=0;
	}
	LinkedNode(int el)
	{
		this->node=el;
		this->adj=NULL;
		this->next=NULL;
		this->status=0;
		this->indeg=this->outdeg=0;
	}
	LinkedNode(int el,Edge *adj,LinkedNode *next,int status)      // zasto se postavlja status nije mi jasno????
	{
		this->node=el;
		this->status=status;
		this->adj=adj;
		this->next=next;
		this->indeg=this->outdeg=0;
	}
	void visit()
	{
		cout<<this->node<<endl;
	}
	~LinkedNode(void);
};

