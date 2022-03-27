#pragma once
#include"HashObject.h"
class HashTable 
{
protected:
	int count;
	int length;
	HashObject *niz; 
public:
	HashTable();
	HashTable(int);
	~HashTable();

	int f(char*);//Mislim da je lepo da uvek prvo 
	//definises transformaciju kljuca pre hes funkcije
	//jer ces je u njoj pozvati, pa da znas sta ti ona radi
	int h(HashObject);//hes funkcija
	int g(int);//sekundarna transformacija
	

	void insert(HashObject obj);
	int findUnoccupied(HashObject obj);
	int findMatch(char* k);
	void withdraw(char*);
	void printAll();
};