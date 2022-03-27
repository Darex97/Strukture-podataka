#include"SLList.h"
#include<cmath>
class HashTable 
{
public:
	int broj;
	int duzina;
	SLList* niz;//Svaki put cu da ti stavim istu napomenu:
	//niz lancanih listi
public:
	HashTable();
	HashTable(int);
	~HashTable();

	int f(int br) { return abs(br); }
	int h(HashObject);

	void insert(HashObject);
	HashObject* findMatch(int);
	
	//void withdraw(int);//po kljucu da trazimo, kljuc je broj sada
	void printAll();



};