#pragma once
#include<iostream>
using namespace std;

class  Node
{   public:
	int info;
	Node* next,*prev;
public:
	Node()
	{   cout<<"konstr Node()"<<endl;
		//info=0;
		prev=NULL;
		next=NULL;
	}
	Node(int el)
	{   cout<<"Konstr Node(el)"<<endl;
		info=el;
		next=NULL;
		prev=NULL;
	}
	Node(int el,Node* n,Node* nn)
	{  cout<<"Konstr Node(el,n,nn)"<<endl;
		info=el;
		prev=n;
		next=nn;
	}
	Node(int el,Node* n)
	{  cout<<"Konstr Node(el,n,nn)"<<endl;
		info=el;
		next=n;
	}
	int printel()
	{
		return info;
	}
	~Node()
	{
	}
};
