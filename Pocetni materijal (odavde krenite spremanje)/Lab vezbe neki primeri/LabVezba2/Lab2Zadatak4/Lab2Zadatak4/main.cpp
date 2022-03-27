#include<iostream>
#include"SLLNode.h"
#include"SortList.h"
using namespace std;

void main()
{
	CSortList lista;
	lista.AddToHead(4);
	lista.AddToHead(3);
	lista.AddToHead(0);
	lista.AddToHead(6);
	lista.AddToHead(1);
	lista.AddToHead(2);
	lista.AddToHead(4);
	lista.AddToHead(9);
	lista.AddToHead(12);
	lista.PRINT();

	lista.Sort(0);
	lista.PRINT();


}
