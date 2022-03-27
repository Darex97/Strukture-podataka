#pragma once
#include<iostream>
using namespace std;
/*Zad 4. Projektovati klasu za rad sa hash tablicom sa
spoljašnjim ulanèavanjem koja služi za smeštanje podataka
o telefonskim pretplatnicima u jednom gradu, bez korišæenja
posebnog prostora za smeštanje sinonima. Izabrati velièinu 
tablice i hash funkciju tako da ima što je moguæe bolje rasipanje vrednosti.
Pretpostaviti da su telefonski brojevi sedmocifreni celi brojevi, 
a da broj telefonskih pretplatnika nije veæi od 1000. */
class HashObject
{
public:
	int key;//broj telefona
	char* record;//ime
	HashObject* next;
public:
	HashObject();
	HashObject(int);
	HashObject(int, char*);
	HashObject(int, char*, HashObject*);
	~HashObject();

	HashObject operator=(HashObject);
	bool operator==(HashObject obj) { return key == obj.key; }
	bool isEqualKey(int k) { return key == k; }
	int getKey() { return this->key; }
	char* getRecord() { return this->record; }
	void print();


};