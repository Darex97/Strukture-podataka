#include"SLNode.h"
#include"SortList.h"
#include<iostream>
using namespace std;

void main()
{
	CSortList lista;
	lista.AddToHead(5);
	lista.AddToHead(4);
	lista.AddToHead(0);
	lista.AddToHead(1);
	lista.AddToHead(10);
	lista.AddToHead(7);
	lista.AddToHead(3);
	lista.PRINT();
	lista.Sort(1);
	lista.PRINT();

}