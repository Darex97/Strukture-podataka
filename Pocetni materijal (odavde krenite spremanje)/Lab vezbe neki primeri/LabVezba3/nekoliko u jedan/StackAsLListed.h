#pragma once
#include "Node.h"
#include  "Stack.h"
#include <iostream>
using namespace std;
class StackAsLListed: public Stack
{
public:
	Node* top;
	long numberElements;
	StackAsLListed()
	{
		top=NULL;
		numberElements=0;
	}
	~StackAsLListed()
	{
	}
	int getTop()
	{
		if (top==NULL)
			throw new exception ("stack underflow");
		return top->info;
	}
	/*void push(Node* n)
	{
		n->next=top->next;
		top->next=n;
	}*/
	void push(int k)
	{
		top=new Node(k,top);
		numberElements++;
	}
	int pop()
	{
		if(top==NULL)
			throw new exception ("stack underflow");
		
		int rez=0;
		
		Node* tmp=top;
		rez=top->info;
		numberElements--;
		if(numberElements==0)
	          top=NULL;
		else top=top->next;
		delete tmp;
		return rez;
	}
	bool isEmpty()
	{
		return (top==NULL);
	}
	long numberOfElements()
	{
		return numberElements;
	}
	void print()
	{
		while (top!=NULL)
	        {
		       cout<<pop()<<"  ";
	        }
	}
	/*void CopyStack(StackAsLListed s1,StackAsLListed s2)
	{
		StackAsLListed pom;
	   if(s1.top==NULL)
	   { 
	      {  
			int x=pop();
			pom.push(x);
		  }
		  while (s1.top!=NULL)
		  {
            int x=pop();
			pom.push(x);
		  }
	   }
		while (pom.top!=NULL)
		{ int p=pom.pop();
			s2.push(p);
		}
	}*/
};
void CopyStack(StackAsLListed &s1,StackAsLListed &s2)
	{
		StackAsLListed pom;
	 /*  if(s1.top==NULL)
	   { 
	      {  
			int x=s1.pop();
			pom.push(x);
		  }*/
		  while (s1.top!=NULL)
		  {
            int x=s1.pop();
			pom.push(x);
		  }
        //}
		while (pom.top!=NULL)
		{ int p=pom.pop();
			s2.push(p);
			s1.push(p);
		}
		//s2.print();
	}