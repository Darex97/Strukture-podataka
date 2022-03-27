#include "DLList.h"
#include <iostream.h>

void main()
{
	DLList lista;
	lista.AddToTail(12);
	lista.AddToTail(1);
	lista.AddToTail(5);
	lista.AddToTail(3);
	lista.AddToTail(4);
	lista.AddToTail(7);
	lista.Print();
}