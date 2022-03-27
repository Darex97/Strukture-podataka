#include <iostream>

using namespace std;

#include "DynamicGraph.h"
#include "DSException.h"

int main()
{
	DynamicGraph<int, double>* graph = new DynamicGraph<int, double>();

	try
	{
		cout << "Length of min cycle: " << graph->minLengthCycle() << endl;
	}
	catch (const DSException& ex)
	{
		cout << "Error Message: " << ex.getMessage() << endl;
	}
	catch (const exception& ex)
	{
		cout << "Error Message: " << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Caught unknown exception!" << endl;
	}

	graph->insertNode(4);
	graph->insertNode(3);
	graph->insertNode(2);
	graph->insertNode(1);

	LinkedNode<int, double>* tempNode = graph->findNode(5);

	if (tempNode == nullptr)
	{
		cout << "Node not found." << endl;
	}
	else
	{
		cout << "Node info: " << tempNode->info << endl;
	}

	tempNode = graph->findNode(3);

	if (tempNode == nullptr)
	{
		cout << "Node not found." << endl;
	}
	else
	{
		cout << "Node info: " << tempNode->info << endl;
	}

	try
	{
		cout << "Length of min cycle: " << graph->minLengthCycle() << endl;
	}
	catch (const DSException& ex)
	{
		cout << "Error Message: " << ex.getMessage() << endl;
	}
	catch (const exception& ex)
	{
		cout << "Error Message: " << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Caught unknown exception!" << endl;
	}

	graph->insertEdge(4, 2, 4.0);
	graph->insertEdge(4, 1, 2.0);
	graph->insertEdge(3, 1, 5.0);
	graph->insertEdge(2, 1, 10.0);
	graph->insertEdge(1, 4, 3.0);
	graph->insertEdge(1, 1, 15.0);
	graph->insertEdge(1, 2, 6.0);
	graph->insertEdge(1, 3, 1.0);

	Edge<int, double>* tempEdge = graph->findEdge(0, 4);

	if (tempEdge == nullptr)
	{
		cout << "Edge not found." << endl;
	}
	else
	{
		cout << "Edge weight: " << tempEdge->weight << endl;
	}

	tempEdge = graph->findEdge(1, 4);

	if (tempEdge == nullptr)
	{
		cout << "Edge not found." << endl;
	}
	else
	{
		cout << "Edge weight: " << tempEdge->weight << endl;
	}

	cout << "Graph: " << endl;
	graph->print();

	try
	{
		cout << "Breadth Traversal: ";
		unsigned int numberOfVisitedNodes = graph->breadthTraversal(1);
		cout << endl;
		cout << "Number of visited nodes: " << numberOfVisitedNodes << endl;

		cout << "Length of min cycle: " << graph->minLengthCycle() << endl;
	}
	catch (const DSException& ex)
	{
		cout << "Error Message: " << ex.getMessage() << endl;
	}
	catch (const exception& ex)
	{
		cout << "Error Message: " << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Caught unknown exception!" << endl;
	}

	graph->deleteEdgeWithMaxWeight();

	cout << "Graph: " << endl;
	graph->print();

	try
	{
		cout << "Length of min cycle: " << graph->minLengthCycle() << endl;
	}
	catch (const DSException& ex)
	{
		cout << "Error Message: " << ex.getMessage() << endl;
	}
	catch (const exception& ex)
	{
		cout << "Error Message: " << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Caught unknown exception!" << endl;
	}

	graph->deleteEdgeWithMaxWeight();

	cout << "Graph: " << endl;
	graph->print();

	try
	{
		cout << "Length of min cycle: " << graph->minLengthCycle() << endl;
	}
	catch (const DSException& ex)
	{
		cout << "Error Message: " << ex.getMessage() << endl;
	}
	catch (const exception& ex)
	{
		cout << "Error Message: " << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Caught unknown exception!" << endl;
	}

	delete graph;
}