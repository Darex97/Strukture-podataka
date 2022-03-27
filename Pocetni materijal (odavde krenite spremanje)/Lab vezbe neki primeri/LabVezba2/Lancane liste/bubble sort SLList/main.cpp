#include "SLList.h"
#include <iostream.h>

void main()
{
	SLList lista;
	
	lista.AddToTail(8);
	lista.AddToTail(7);
	lista.AddToTail(6);
	lista.AddToTail(5);
	lista.AddToTail(4);
	lista.AddToTail(3);
	lista.AddToTail(2);
	lista.AddToTail(1);
	lista.AddToTail(0);
	lista.AddToTail(-1);
/*	lista.AddToTail(457);
	lista.AddToTail(4521);
	lista.AddToTail(121);
	lista.AddToTail(15);
	lista.AddToTail(25);
	lista.AddToTail(51234);*/
	lista.Print();

	lista.Sort();

	lista.Print();
}