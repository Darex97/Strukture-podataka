#include"CStaticSortDList.h"
#include<iostream>
using namespace std;
void main()
{
	CStaticSortDList list(5);
	list.AddToHead(34);
	list.AddToHead(23);
	list.AddToHead(100);
	list.AddToHead(200);
	
	list.printList();
	list.Sort(false);
	list.printList();
}
