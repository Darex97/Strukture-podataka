#include "lista.h"
#include"HashObject.h"

#include<iostream>

using namespace std;

class HashTable
{
protected : // polja
	unsigned int lenght;	// za svaku tablicu
	unsigned int count;		// -||-

	lista *arrayS;			// za tablicu sa spoljnjim ulancavanjem

protected: // funkcije

	unsigned int h (HashObject obj)
	{
		return (f(obj.getKey())%lenght);
	}
	// primarna transformacija za kljuceve tipa int
	unsigned int f(int i) 
	{ 
		return abs(i); 
	}
	// sekundarna transformacija | za otvoreno adresiranje
	unsigned int g(int i)  
	{ return (i+1)%lenght;}

public:
	unsigned int getLenght() { return lenght; } // za svaku tabelu
	double getLoadFactor() { return (double)count/(double)lenght; }// -||-

	HashTable(unsigned int len);
	void InsertS(HashObject obj); // umetanje za spoljnje ulancavanje
	void withDraw(HashObject obj);
	void withDraw(int key);
	HashObject find (int key);
	~HashTable();
};

