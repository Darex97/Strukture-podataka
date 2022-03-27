#include"GraphAsLists.h"


void main()
{
	try
	{
		GraphAsLists graph;

		graph.insertNode(1);
		graph.insertNode(2);
		graph.insertNode(3);
		graph.insertNode(4);
		graph.insertNode(5);
		graph.insertNode(6);
		graph.insertNode(7);

		graph.insertEdge(1,7);
		graph.insertEdge(1,3);
		graph.insertEdge(1,2);
		graph.insertEdge(7,5);
		graph.insertEdge(3,2);
		graph.insertEdge(3,4);
		graph.insertEdge(4,7);
		graph.insertEdge(4,2);
		graph.insertEdge(4,6);
		graph.insertEdge(4,6);
		graph.insertEdge(5,7);
		graph.insertEdge(6,7);

		graph.print();

		cout<<"Cvor sa najvecim ulaznum stepenom je:"<<(graph.indegMax())->node<<endl;
		cout<<"Cvor sa najvecim izlaznim stepenom je:"<<(graph.outdegMax())->node<<endl;
		cout<<"Cvor sa 0 ulaznim stepenom je:"<<(graph.zeroIndeg())->node<<endl;
		cout<<"Cvor sa 0 izlaznim stepenom je:"<<(graph.zeroOutdeg())->node<<endl<<endl<<endl;

		graph.printMatrix(graph.AdjecencyMatrix());


	}
	catch(char *message)
	{
		cout<<message<<endl;
	}

}