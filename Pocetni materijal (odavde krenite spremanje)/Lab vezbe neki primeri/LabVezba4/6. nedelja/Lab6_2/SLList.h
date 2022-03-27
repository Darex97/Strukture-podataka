// SLList.h: interface for the SLList class.
//Status OK!
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SLLIST_H__AB6C06D0_8E85_4A04_B1A9_D2A3A8CA879B__INCLUDED_)
#define AFX_SLLIST_H__AB6C06D0_8E85_4A04_B1A9_D2A3A8CA879B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SLLNode.h"
#include <iostream.h>

template <class T>
class SLList  
{
protected:
	SLLNode<T> *tail;
	SLLNode<T> *head;
public:
	SLList(){ head = tail = NULL;}
	virtual ~SLList();
	bool isEmpty(){ return head==NULL;}
	void addToHead(T el);
	void addToTail(T el);
	T deleteFromHead();
	T deleteFromTail();
	SLLNode<T>* findNodePtr(T el);
	SLLNode<T>* getHead(){ return head;}
	SLLNode<T>* getNext(SLLNode<T> *ptr);
	T getHeadEl();
	T getNextEl(T el);
	void printAll();
	bool isInList(T el);
	void deleteEl(T el);
};

template <class T>
SLList<T>::~SLList(){
	while(!isEmpty()){
		T tmp = deleteFromHead();
	}
}

template <class T>
void SLList<T>::printAll(){
	for(SLLNode<T>* tmp = head;tmp != NULL; tmp = tmp->next)
		cout<<tmp->print()<<" ";
}

template <class T>
void SLList<T>::addToHead(T el){
	head = new SLLNode<T>(el,head);
	if(tail == NULL) tail = head;
}

template <class T>
void SLList<T>::addToTail(T el){
	if (!isEmpty)()){
		tail->next = new SLLNode<T>(el);
		tail = tail->next;
	}
	else head = tail = new SLLNode<T>(el);
}

template <class T>
T SLList<T>::deleteFromHead(){
	T el = head->info;
	SLLNode<T> *tmp = head;
	if (head == tail) head = tail = NULL;
	else head = head->next;
	delete tmp;
	return el;
}

template <class T>
T SLList<T>::deleteFromTail(){
	T el = tail->info;
	SLLNode<T> *tmp = tail;
	if(head == tail) head = tail = NULL;
	else{
		SLLNode<T> *tmp;
		for (tmp = head;tmp->next!=tail;tmp=tmp->next);
		tail = tmp;
		tail->next = NULL;
	}
	delete tmp;
	return el;
}

template <class T>
bool SLList<T>::isInList(T el){
	SLLNode<T> *tmp;
	for(tmp=head;tmp != NULL && !(tmp->info.isEqual(el));tmp=tmp->next);
	return tmp != NULL;
}

template <class T>
SLLNode<T>* SLList<T>::findNodePtr(T el){
	SLLNode<T> *tmp;
	for(tmp=head;tmp != NULL && !(tmp->isEqual(el));tmp=tmp->next);
	if(tmp == NULL) throw "Element not found!";

	else return tmp;
}

template <class T>
SLLNode<T>* SLList<T>::getNext(SLLNode<T>* ptr){
	if(ptr) return ptr->next;
	else throw "NULL pointer exception!";
}

template <class T>
T SLList<T>::getHeadEl(){
	if(head == NULL) throw "The list is empty!";
	return (head->info);
}

template <class T>
T SLList<T>::getNextEl(T el){
	SLLNode<T>* curNode = findNodePtr(el);
	if(curNode->next == NULL) throw "END";
	return ((curNode->next)->info);
}

template <class T>
void SLList<T>::deleteEl(T el){
	if(!isEmpty())
		if(head==tail && head->isEqual(el)){
			SLLNode<T> *tmp = head;
			delete tmp;
			head = tail = NULL;
		} 
		else if (el == head->info){
			SLLNode<T> *tmp = head;
			head = head->next;
			delete tmp;
		}
		else{
			SLLNode<T> *pred, *tmp;
			for(pred=head,tmp=head->next;tmp!=NULL && !(tmp->isEqual(el));pred=pred->next,tmp=tmp->next);
			if(tmp != NULL){
				pred->next = tmp->next;
				if(tmp != tail)
					tail=pred;
				delete tmp;
			}
		}
}

#endif // !defined(AFX_SLLIST_H__AB6C06D0_8E85_4A04_B1A9_D2A3A8CA879B__INCLUDED_)
