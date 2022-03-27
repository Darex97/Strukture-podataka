#include "Lista.h"
#include "Node.h"
#include <iostream>
using namespace std;

void main()
{
	Lista l1;
	l1.AddToHead(1);
	l1.AddToHead(217);
	l1.AddToHead(2);
	l1.AddToHead(21);
	l1.AddToHead(4);
	l1.printAll();

	l1.Insertion();
	l1.printAll();

	system("pause");
}