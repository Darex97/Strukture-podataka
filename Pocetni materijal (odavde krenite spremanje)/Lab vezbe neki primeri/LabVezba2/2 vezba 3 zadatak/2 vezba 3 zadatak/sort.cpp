#include "sort.h"
#include "cvor.h"
#include<iostream>
using namespace std;

sort::~sort(void)
{
}
void sort::addtohead(int el)
{
	head=new cvor(el,head);
	if(tail==NULL) tail=head;
}
void sort::printall()
{
	for(cvor *tmp=head;tmp!=NULL;tmp=tmp->next)
		cout<<tmp->print()<<" ";
}
void sort::bubblesort()
{
  int i,j,n=0,h;
  cvor *q, *p, *t;
  for(q=head;q!=NULL;q=q->next)   
    n++;
  for(i=1,t=head;i<n; t=t->next,i++)
    for(j=0,p=head;j<n-i;p=p->next,j++)
       if((p->info) > (p->next)->info)
       {
	     h=p->info;
         p->info=(p->next)->info;
         (p->next)->info=h;
       }
}
void sort::selectionsort()
{ 
	cvor *p,*q,*min;
   int tmp;
 
   for(p=head->next;p->next!=NULL;p=p->next)
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