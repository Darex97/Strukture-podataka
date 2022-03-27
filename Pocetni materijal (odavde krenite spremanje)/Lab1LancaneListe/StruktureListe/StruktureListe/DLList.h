#pragma once
#include<iostream>
#include"DLLNode.h"

template <class T>
class DLList {
protected:
	DLLNode<T> *head, *tail;
public:
	DLList() { head = tail = NULL; }
	~DLList();
	bool isEmpty() { return tail == NULL; }
	void printAll();
	DLLNode<T>* findNodePtr(T el);
	DLLNode<T>* getHead() { return head; }
	DLLNode<T>* getNext(DLLNode<T>* ptr);
	T getHeadEl();
	T getNextEl(T el);
	bool isInList(T el);
	void deleteEl(T el);
	void addToHead(T el);
	void addToTail(T el);
	T deleteFromHead();
	T deleteFromTail();
	void MovePartToEnd(int val1, int val2);
};
template<class T>
DLList<T>::~DLList() {
	//while (!isEmpty()) {
		//T tmp = deleteFromHead();
	//}
	//Iskomentarisao sam ovaj deo jer
	//nemamo ovu fju definisanu.
}
template<class T>
void DLList<T>::addToHead(T el) {
	if (!isEmpty()){
		//Nije prazna lista.
	
		head = new DLLNode<T>(el, NULL, head);
		// info,prev,next

       head->next->prev = head;//sredjuemo da pokazivaci znaju na sta pokazuju
	}
	else {
		//Ako lista jeste prazna, onda su prvi i poslednji element isti.
		head = tail = new DLLNode<T>(el);
	}
}
template <class T>
void DLList<T>::addToTail(T el) 
{
	if (!isEmpty())
	{
		tail = new DDLNode<T>(el, tail, NULL);//stari tejl ti je parametar
		tail->prev->next = tail;//sredjuemo da pokazivaci znaju na sta pokazuju
	}
	else head = tail = new DDList<T>(el);
}
template<class T>
void DLList<T>::deleteEl(T el)
{
	if (!isEmpty())
	
	   //Provera da li postoji samo jedan element.
		if (head == tail && head->isEqual(el))
		{
			DLLNode<T> *tmp = head;
			delete tmp;
			head = tail = NULL;
		}
	//Da li je trazeni element prvi.
	else if (el == head->info) {
		DLLNode<T> *tmp = head;
		head = head->next;
		head->prev = NULL;
		delete tmp;
	}
	else {
		DLLNode<T> *tmp;
		for (tmp = head->next;tmp != NULL && !(tmp->isEqual(el));tmp = tmp->next);
		tmp = tmp->next;
		if (tmp != NULL) {
			//Next od prethodnog ce biti next od trenutnog.
			tmp->prev->next = tmp->next;
			if (tmp->next)
				//Prev od narednog uzima link prethodnog od tekuceg elem.
				//NACRTAJ!!!!
				tmp->next->prev = tmp->prev;
			if (tmp == tail)
				tail = tmp->prev;
			delete tmp;
		}
	}
}
template<class T>
void DLList<T>::printAll() {
	for (DLLNode<T>* tmp = head; tmp != NULL;tmp = tmp->next)

		cout << tmp->print() << " ";
}
template<class T>
void DLList<T>::MovePartToEnd(int val1,int val2)
{
	//Kolokvijum 2016, redovni
	DLLNode<T> *tmpVal1, *prvi, *poslednji, *tmpVal2,*krajisnik;
	for (tmpVal1 = head;tmpVal1->info != val1;tmpVal1 = tmpVal1->next);
	prvi = tmpVal1->next;
	for (tmpVal2 = tmpVal1;tmpVal2->info != val2;tmpVal2 = tmpVal2->next);
	poslednji = tmpVal2->prev;
	if (poslednji = prvi->next)
	{
		return;//susedni su nema zamene mesta
	}
	if (poslednji->next == NULL)
	{
		return;//vec su ti na kraju ti elementi
	}


	tmpVal1->next = tmpVal2;
	tmpVal2->prev = tmpVal1;
	for (krajisnik = tmpVal2;krajisnik->next != NULL;krajisnik = krajisnik->next);
	prvi->prev = krajisnik;
	krajisnik->next = prvi;
	poslednji->next = NULL;
}