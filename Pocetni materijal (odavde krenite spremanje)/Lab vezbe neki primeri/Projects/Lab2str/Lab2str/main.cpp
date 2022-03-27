#include "Cvor.h"
#include "Lista.h"
#include <iostream>
using namespace std;

void main()
{
	/*Cvor a(5);
	Cvor b(6);
	a.print();
	b.print();*/
	Lista c;
	c.AddToHead(3);
	c.AddToHead(4);
	c.AddToHead(3);
	c.AddToHead(6);
	c.AddToHead(3);
	c.AddToHead(8);
	c.AddToTail(1);
	c.printAll();
}