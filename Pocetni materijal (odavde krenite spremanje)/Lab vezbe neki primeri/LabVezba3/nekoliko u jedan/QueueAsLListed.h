#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
class QueueAsLListed
{
public:
	Node* head;
	Node* tail;
	//long numOfElements;
	QueueAsLListed()
	{
		head=tail=NULL;
		//numOfElements=0;
	}
	bool isEmpty() { return (head==NULL); }
	~QueueAsLListed()
	{
	}
	int getHead()
	{
		if (head==NULL)
		{
			cout<<"je prazan"<<endl;
			return 0;
		}
		else return head->info;
	}
	void enqueue(int k)
	{
		if (!isEmpty())
		{
		tail->next=new Node(k);
		tail=tail->next;
		}
		else
			head=tail=new Node(k);

	}

	int dequeue ()
	{
		
		
		int rez=0;
		rez=head->info;
		Node* tmp=head;
		
		
		if(head==tail)
	         head=tail=NULL;
		else head=head->next;
		delete tmp;
		return rez;
	}
	void print()
	{
		while (head!=NULL)
		{
			cout<<dequeue()<<"  ";
		}
	}
};
