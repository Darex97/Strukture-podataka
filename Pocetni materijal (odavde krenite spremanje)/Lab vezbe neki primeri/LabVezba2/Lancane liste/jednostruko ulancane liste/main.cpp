#include "SLList.h"
#include <iostream.h>

void main()
{
	SLList *lista=new SLList;
	lista->AddToHead(9);
	lista->AddToTail(5);
	lista->AddToTail(3);
	lista->AddToTail(7);
	lista->Print();
	//lista->Sort();
	//lista->Print();
	delete lista;
}