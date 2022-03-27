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
		
		graf.print();
		cout << endl;
		int *br = new int[4];
		for (int i = 0; i < 4; i++)
			br[i] = 0;
		LinkedNode *nizElemenataSaNulaUlaznimStepenom;
		int brojElemenataNizaCvorovaSaNulaUlaznimStepenom = 0;
		cout << graf.zeroIndeg(nizElemenataSaNulaUlaznimStepenom, &brojElemenataNizaCvorovaSaNulaUlaznimStepenom);
		
			graf.zeroInDeg();
		cout << endl;

		//cout << "Cvor sa ulaznim stepenom 0: " << graf.zeroIndeg()->node << endl;
	}
	catch (char* e)
	{
		cout << e << endl;
	}
}