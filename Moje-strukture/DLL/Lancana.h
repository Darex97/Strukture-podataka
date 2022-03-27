#pragma once
#include"Cvor.h"
#include<iostream>
using namespace std;
class Lancana
{protected:
	Cvor* head, * tail;
public:
	Lancana() { head = tail = NULL; }
	~Lancana();

	bool prazna() { return head == NULL; }
	void print();
	Cvor* nadjicvor(int el);
	Cvor* getHead() { return head; }
	Cvor* nadjisl(Cvor* ptr);
	int headel() { return head->info; }
	int getNextEl(int el);
	bool ulisti(int el);
	void deleteEl(int el);
	void dodajnaGlavu(int el);
	void dodajnaRep(int el);
	int DeleteGlava();
	int DeleteREp();



};