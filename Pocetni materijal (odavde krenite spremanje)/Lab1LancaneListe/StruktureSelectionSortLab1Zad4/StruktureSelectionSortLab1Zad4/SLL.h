#pragma once
#include"CvorListe.h"
#include<iostream>
using namespace std;
class SLL {
	protected:
		CvorListe *head, *tail;
    public:
	int glavniBrojac = 0;
	int glavniBubbleBrojac = 1;
		
    public:
		SLL() { head = tail = NULL; }
		~SLL();
		//SLL(SLL& S);
		bool isEmpty() { return head == NULL; }
		void addToHead(int element);
		void addToTail(int element);
		int deleteFromHead();
		int deleteFromTail();
	    CvorListe* getHead() { return head; }
		void printAll();
		void deleteEl();
		void SelectionSort();
		void BubbleSort();
		void zameniMesta(CvorListe* i, CvorListe* j);

};