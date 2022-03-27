#include "Lista.h"
#include"Node.h"
#include<iostream>
using namespace std;

void Lista::AddToHead(int el)
{
	if(head==NULL)
		head=new Node (el);
	else
	{
		head=new Node(el,head);
	}

}
int Lista::deleteFromHead()
{
	int el=head->info;
	Node* tmp=head;
	head=head->next;
	delete tmp;
	return el;
}
Lista::~Lista()
{
	while(!isEmpty()){
		int tmp=deleteFromHead();
	}
}
void Lista::printAll()
{
	Node* tmp;
	for(tmp=head;tmp!=NULL;tmp=tmp->next)
	{
		cout<<tmp->printel()<<" ";
	}
	cout<<endl;
}
void Lista::Bubble()
{
	if(head==NULL)
		throw("Nema elementa!");
	Node * p=new Node();
	Node *t=new Node();
	int n=0,i,j,h;
	for(p=head;p!=NULL;p=p->next)
		n++;
	for(i=1,t=head;i<n;t=t->next,++i)
	{
		for(j=0,p=head;j<n-i;p=p->next,++j)
		{
			if(p->info > (p->next)->info)
			{
				h=p->info;
				p->info=(p->next)->info;
				(p->next)->info=h;
			}
		}
	}

}
void Lista::Insertion() 
{
	
	Node *ptr1, *prev1;
	Node *ptr2, *prev2;
	prev1 = head;
	for (ptr1=head->next; ptr1!=NULL; ) {
		prev2 = NULL;
		ptr2=head;
		while (ptr2!=ptr1 && ptr1->info > ptr2->info) {
			prev2 = ptr2;
			ptr2 = ptr2->next;
		}
		if (ptr1 != ptr2) {
			if(prev2!=NULL){
			prev1->next = ptr1->next;
			prev2->next = ptr1;
			ptr1->next = ptr2;
		}
		else{
			prev1->next=ptr1->next;
			head=ptr1;
			ptr1->next=ptr2;
		}
		ptr1=prev1->next;
	} else {
		prev1=ptr1;
		ptr1=ptr1->next;
		}

	}
}
void Lista::Selection()
{
	Node *p,*q,*min;
	
   int tmp;
 
   for(p=head;p->next!=NULL;p=p->next)
   {
      min=p;
      for(q=p->next;q;q=q->next)
      if((q->info) < (min->info))
      min=q;
      if(min!=p)
      {
         tmp=p->info;
         p->info=min->info;
         min->info=tmp;
	  }
   }
}