
#include<iostream.h>
#include"GraphAsMat.h"
#include"Izuzetak.h"


void main()
{
	try
	{
		GraphAsMat<int> graf(8);
		graf.insertNode(3);
		graf.insertNode(5);
		graf.insertNode(1);
		graf.insertNode(23);
		graf.insertNode(11);
		graf.insertEdge(11,23);
		graf.insertEdge(23,5);
		graf.insertEdge(23,3);
		graf.insertEdge(1,23);
		graf.insertEdge(1,5);
		graf.insertEdge(1,3);
		graf.insertEdge(3,5);
		graf.printMat();
		graf.printNode();
	}
	catch(Izuzetak d)
	{
		d.prikazi();
	}
}

