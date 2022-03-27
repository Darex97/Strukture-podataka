#include "Edge.h"
#include "LinkedNode.h"
#include "GraphAsLists.h"

void main()
{
	try
	{
		GraphAsList graf;

		graf.insertNode(1);
		graf.insertNode(2);
		graf.insertNode(3);
		graf.insertNode(4);
		graf.insertEdge(1, 2);
		graf.insertEdge(1, 3);
		graf.insertEdge(2, 3);
		graf.insertEdge(4, 1);
		graf.insertEdge(4, 2);
		graf.insertEdge(4, 3);
		
		/*graf.insertEdge(1, 1);
		graf.insertEdge(1, 4);
		graf.insertEdge(2, 1);
		graf.insertEdge(2, 2);
		graf.insertEdge(2, 4);
		graf.insertEdge(3, 1);
		graf.insertEdge(3, 4);
		graf.insertEdge(3, 2);
		graf.insertEdge(3, 3);
		graf.insertEdge(4, 4);*/

		graf.print();

		cout << endl;
		cout << "Cvor sa maksimalnim ulaznim stepenom: " << graf.maxInDeg()->node << endl;
		cout << endl;

		cout << "Cvor sa maksimalnim izlaznim stepenom: " << graf.maxOutDeg()->node << endl;
		cout << endl;

		graf.zeroOutDeg();
		cout << endl;
		
		graf.zeroInDeg();
		cout << endl;

		graf.printMatrix(graf.matricaSusedstva());
		cout << endl;

		graf.povezanost();
	}
	catch (char* e)
	{
		cout << e << endl;
	}
}