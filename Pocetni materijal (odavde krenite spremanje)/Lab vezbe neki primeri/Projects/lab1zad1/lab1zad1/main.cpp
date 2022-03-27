#include "CPolynom.h"
#include <iostream>
using namespace std;

void main()
{
	CPolynom a(3);
	a.dodaj(3, 12);
	a.dodaj(2, 1);
	a.dodaj(1, 4);
	a.dodaj(0, 2);
	a.print();
	
	CPolynom b(2);
	b.dodaj(2, 7);
	b.dodaj(1, 5);
	b.dodaj(0, 3);
	b.print();

	CPolynom c;
	c=a.saberi(b);
	c.print();
}