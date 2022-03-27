#include "dekkaolista.h"
#include "cvor.h"
#include<iostream>
using namespace std;

dekkaolista::~dekkaolista(void)
{
}
void dekkaolista::printall()
{
	for(cvor *tmp=head;tmp!=NULL;tmp=tmp->next)
		cout<<tmp->info<<endl;
}
void dekkaolista::addtohead(int el)
{
	head=new cvor(el,head);
	if(tail==NULL)
		tail=head;
}
void dekkaolista::addtotail(int el)
{
	if(head!=NULL)
	{
		tail->next=new cvor(el);
		tail=tail->next;
	}
	else
		head=tail=new cvor(el);
}
int dekkaolista::deletefromhead()
{
	int el=head->info;
	cvor *tmp=head;
	if(head==tail)
		head=tail=NULL;
	else
		head=head->next;
	delete tmp;
	return el;
}
int dekkaolista::deletefromtail()
{
	int el=tail->info;
	cvor *tmp=tail;
	if(head==tail)
		head=tail=NULL;
	else
	{
		cvor *p;
		for(p=head;p->next!=tail;p=p->next);
		tail=p;
		tail->next=NULL;
	}
	delete tmp;
	return el;
}
