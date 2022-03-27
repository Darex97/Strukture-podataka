#pragma once
#include "DLLNode.h"

template <class T>
class DLList
{
protected:
	DLLNode<T> *head, *tail;
public:
	DLList(void);
	virtual ~DLList(void);
	bool isEmpty();
	void printAll();
	DLLNode<T>* findNodePtr(T el);
	DLLNode<T>* getHead();
	DLLNode<T>* getTail();
	DLLNode<T>* getNext(DLLNode<T> *ptr);
	DLLNode<T>* getPrev(DLLNode<T> *ptr);
	T getHeadEl();
	T getNextEl(T el);
	bool isInList(T e);
	void delteEl(T el);
	void addToHead(T el);
	void addToTail(T el);
	T deleteFromHead();
	T deleteFromTail();
	void SwapWithNext(DLLNode<T> *ptr);
	void BubbleSort();

};
template <class T>
DLList<T>::~DLList()
{
	while(!isEmpty())
	{
		T tmp = deleteFromHead();
	}
}
template <class T>
DLList<T>::DLList()
{
	head = tail = NULL;
}
template <class T>
DLLNode<T>* DLList<T>::getHead()
{
	return this->head;
}
template <class T>
DLLNode<T>* DLList<T>::findNodePtr(T el)
{
	DLLNode<T> *tmp;
	for(tmp=head;tmp!=NULL && !(tmp->isEqual(el)); tmp=tmp->next);
	if(tmp==NULL)
		throw "Elemenat nije nadjen";
	else return tmp;
}
template <class T>
DLLNode<T>* DLList<T>::getNext(DLLNode<T> *ptr)
{
	if(ptr) return ptr->next;
	else throw "NUlL Pointer Eception | getNext";
}
template <class T>
T DLList<T>::getHeadEl()
{
	if(head==NULL)
		throw "Lista je prazna";
	return head->info;
}
template <class T>
T DLList<T>::getNextEl(T el)
{
	DLLNode<T> *curNode = findNodePtr(el);
	if(curNode->next==NULL)
		throw "Nema narednog elementa";
	return ((curNode->next)->info);
}
template <class T>
void DLList<T>::addToHead(T el)
{
	if(!isEmpty())
	{
		head = new DLLNode<T>(el,NULL,head);
		head ->next->prev=head;
	}
	else head = tail = new DLLNode<T>(el);
}
template <class T>
void DLList<T>::addToTail(T el)
{
	if(!isEmpty())
	{
		tail=new DLLNode<T>(el,tail,NULL);
		tail->prev->next=tail;
	}
	else head = tail = new DLLNode<T>(el);
}
template <class T>
T DLList<T>::deleteFromHead()
{
	if(!isEmpty())
	{

		T el = head ->info;
		DLLNode<T> *tmp = head;
		if(head==tail)
			head=tail=NULL;
		else {
			head = head->next;
			head->prev=NULL;
		}
		delete tmp;
		return el;
	}
	else throw "Lista je prazna";
}
template <class T>
T DLList<T>::deleteFromTail(){
	if(!isEmpty())
	{
		T el = tail -> info;
		DLLNode<T>* tmp = tail;
		if(head == tail) head = tail = NULL;
		else{
			tail = tail->prev;
			tail->next=NULL;
		}
		delete tmp;
		return el;
	}
	else throw "Lista je prazna";
}
template <class T>
void DLList<T>::printAll()
{
	for(DLLNode<T>* tmp = head; tmp!=NULL;tmp=tmp->next)
		cout << tmp->print() << " " ;
}
template <class T>
bool DLList<T>::isInList(T el)
{
	DLLNode<T>* tmp;
	for(tmp=head; tmp!=NULL && !(tmp->isEqual(el));tmp=tmp->next);
	return tmp!=NULL;
}
template <class T>
void DLList<T>::delteEl(T el)
{
	if(!isEmpty())
		if (head==tail && head->isEqual(el))
		{
			DLLNode<T> *tmp=head;
			delete tmp;
			head=tail=NULL;
		}
		else if(el==head->info)
		{
			DLLNode<T>* tmp=head;
			head=head->next;
			delete tmp;
		}
		else
		{
			DLLNode<T> *pred, *tmp;
			for(pred = head, tmp=head->next;tmp!=NULL && !(tmp->isEqual(el))
				pred=pred->next,tmp=tmp->next);
				if(tmp!=NULL)
				{
					pred->next=tmp->next;
					if(tmp==tail)
						tail=pred;
					delete tmp;
				}
		}
}
template <class T>
bool DLList<T>::isEmpty()
{
	return head == NULL;
}
template <class T>
DLLNode<T>* DLList<T>::getPrev(DLLNode<T> *ptr)
{
	if(ptr) return ptr->prev;
	else throw "NUlL Pointer Exception | getPrev";
}
template <class T>
void DLList<T>::SwapWithNext(DLLNode<T> *ptr)
{ 
	DLLNode<T> *tmp;
	if(head->next==tail)
	{
		tmp=ptr->next;
		tail=ptr;
		head=tmp;
		tail->next=NULL;
		tail->prev=tmp;
		head->prev=NULL;
		head->next=ptr;
	}
	else if(ptr==head)
	{	tmp=ptr->next->next;
		head=ptr->next;
		head->next=ptr;
		ptr->next=tmp;
		ptr->prev=head;
		head->prev=NULL;
		tmp->prev=ptr;
	}
	else if(ptr->next==tail)
		{
			tmp=ptr->next;
			tail=ptr;
			tmp->next=tail;
			tmp->prev=ptr->prev;
			ptr->prev->next=tmp;
			tail->prev=tmp;
			tail->next=NULL;

		}
	else {
	tmp=ptr->next->next;
	ptr->next->next->prev=ptr;
	ptr->next->next=ptr;
	ptr->next->prev=ptr->prev;
	ptr->prev->next=ptr->next;
	ptr->prev=ptr->next;
	ptr->next=tmp;
	}
}
template <class T> 

 
void DLList<T>::BubbleSort()
{
	DLLNode<T> *temp, *tmptail;
	int k=1;
	while(k!=0)
	{
		k=0;
	temp=this->getHead();
	tmptail=this->getTail();
	while(temp != tmptail)
	{
		int flag=0;
		if(temp->next==tmptail) flag=1;


	if(temp->info > temp->next->info)
	{
		this->SwapWithNext(temp);
		k=1;
	}
		if(flag==0) temp=temp->next;
		else temp=tmptail;
	}
	tmptail=tmptail->prev;
	
	}
}

template <class T>
DLLNode<T>* DLList<T>::getTail()
{
	return this->tail;
}





