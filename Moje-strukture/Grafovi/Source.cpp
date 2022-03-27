#include<iostream>
#include"Edge.h"
#include"GraphAsLists.h"
#include"LinkedNode.h"
using namespace std;
void main()
{


	
	int k;
	GraphAsLists a;
	int b[] = {0,1,2,3,4,5,-1 };
	for (int i = 0; i < 6; i++)
		a.inserNode(i);
	a.insertEdge(0,1,1);
	a.insertEdge(0,3,2);
	a.insertEdge(0,5,3);
	a.insertEdge(1,4,1);
	a.insertEdge(5,3,1);
	a.insertEdge(5,2,2);
	a.insertEdge(2,4,1);
	a.print();
	k=a.Proslipredmeti(b);
	cout << endl<<k;






}