#pragma once
#include<iostream>
#include "element.h"
#include "tablica.h"
#include "tabla.h"
#include "cvor.h"
using namespace std;
template <class t>
class lista
{
public:
	cvor<t> *head;
	cvor<t> *tail;
	lista(){head=tail=NULL;}
	void printall();
	void addtotail(t el);
	void deletefromtail();
	void  addToHead(t el);
	t getHead();
	t getNext(t el);
	cvor<t>* findNode(t el);
	void deleteel(t el);
	
};
template <class t>
void lista<t>::printall()

{
	for(cvor<t> *tmp=head;tmp!=NULL;tmp=tmp->next)
		cout<<tmp->info<<"\t";
}
template <class t>
void lista<t>::addtotail(t el)
{
	if(head!=NULL){
		tail->next=new cvor<t>(el);
		tail=tail->next;
	}
	else
		tail=head=new cvor<t>(el);
}
template <class t>
void lista<t>::deletefromtail()
{
	cvor<t> *tmp=tail;
	if(head==tail)
		head=tail=NULL;
	else
	{
		cvor<t> *pom;
		for(pom=head;pom->next!=tail;pom=pom->next);
			tail=pom;
		tail->next=NULL;
	}
	delete tmp;
}
template <class t>
t lista<t>::getHead()
{
	if(head==NULL)
		throw "lista je prazna:";
	else
		return (head->info);
}
template <class t>
t lista<t>::getNext(t el)
{
	cvor<t> *tmp=findNode(el);
	if(tmp->next==NULL)
		throw "nema elementa";
	else
		return ((tmp->next)->info);
}
template <class t>
cvor<t>* lista<t>::findNode(t el)
{
	cvor<t> *tmp;
	for(tmp=head;tmp!=NULL && !(tmp->isequal(el));tmp=tmp->next);
		if(tmp==NULL)
			throw "element nije nadjen";
		else return tmp;
}
template<class t>
void lista<t>::deleteel(t el)
{
	if(head->info==el){
             cvor<t> *tmp=head;
	if(head==tail)
		head=tail=NULL;
	else
		head=head->next;

	delete tmp;
	}
        else 
        {
        if(head==tail && head->info==el)
          {
              cvor<t> *tmp=head;
              delete tmp;
              head=tail=NULL;
          }
       else
      {
         cvor<t> *tmp,*pred;
         for(pred=head,tmp=head->next;tmp->next!=NULL && !(tmp->isequal(el));pred=pred->next,tmp=tmp->next);
         if(tmp!=NULL)
         pred->next=tmp->next;
         if(tmp==tail)
         tail=pred;
         delete tmp;
      }
    }
}
template <class t>
void lista<t>::addToHead(t el)
{
	head = new cvor<t>(el,head);
	if(tail == NULL)
		tail = head;
}