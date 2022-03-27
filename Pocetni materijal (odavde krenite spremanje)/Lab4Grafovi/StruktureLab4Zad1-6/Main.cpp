#pragma once
#include"GraphAsLists.h"
void main()
{
	
/*	GraphAsLists g;
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	 g.insertNode(d);
	 g.insertNode(c);
	 g.insertNode(b);
	 g.insertNode(a);


	
	//g.insertNode(e); Ovo dodaj da proveris 3. i 4. zadatak
	g.insertEdge(a,b);
	g.insertEdge(a,c);
	g.insertEdge(a,d);
	g.insertEdge(b,a);
	g.insertEdge(c,a);
	g.insertEdge(d,a);
	g.insertEdge(d, b);

	cout << "Graf preko lancanih listi:"<<endl;
	g.print();

	g.maxInDeg();
	g.maxOutDeg();
	g.outZero();
	g.inZero();
	g.BFS(a);
	cout << endl<<"Da li je graf jako povezan:"<<endl;
	g.stronglyConnencted();
	g.adjescentMatrix();*/

	//2016, primer1:
	//ovo radi:
	/*GraphAsLists g;
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	g.insertNode(d);
	g.insertNode(c);
	g.insertNode(b);
	g.insertNode(a);
	g.insertEdge(a, b,10);
	g.insertEdge(a, c,50);
	g.insertEdge(a, d,40);
	g.insertEdge(b, a,15);
	g.insertEdge(c, a,20);
	g.insertEdge(d, a,40);
	g.insertEdge(d, b, 20);
	g.getReachable(a,50);*/
	//2016, primer2:

	GraphAsLists g;
	int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, gg = 7, h = 8;
	g.insertNode(a);
	g.insertNode(b);
	g.insertNode(c);
	g.insertNode(d);
	g.insertNode(e);
	g.insertNode(f);
	g.insertNode(gg);
	g.insertNode(h);
	g.insertEdge(a,b,10);
	g.insertEdge(b,e,10);
	g.insertEdge(e,gg,15);
	g.insertEdge(gg,a,30);
	g.insertEdge(d,a,20);
	g.insertEdge(b,f,5);
	g.insertEdge(f,d,40);
	g.insertEdge(f,c,15);
	g.insertEdge(c,h,30);
	g.print();
	g.BFS(a);
	g.getReachable(a, 50);
}