#include "StaticSortList.h"
#include <iostream>
using namespace std;

void main()
{
	try{
	CStaticSortList lista(6);
	lista.addToHead(5);
	lista.addToHead(2);
	lista.addToHead(7);
	lista.addToHead(1);
	lista.bubbleSort(true);
	lista.print();
	}
	catch (char* s)
	{
		cout << s << endl;
	}
}