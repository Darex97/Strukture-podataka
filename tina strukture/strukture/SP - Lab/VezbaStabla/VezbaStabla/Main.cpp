#include <iostream>

using namespace std;

#include "DynamicBSTree1.h"
#include "DynamicBSTree2.h"
#include "DSException.h"

int main()
{
	/* Prvi zadatak */
	DynamicBSTree1<int>* tree1 = new DynamicBSTree1<int>();

	StaticBSTree<int>* staticTree = nullptr;

	try
	{
		staticTree = tree1->staticBSTree();

		cout << "Static Tree: ";
		staticTree->print();

		delete staticTree;

		BSTNode<int>* tempNode = tree1->search(10);

		if (tempNode == nullptr)
		{
			cout << "Node not found." << endl;
		}
		else
		{
			cout << "Node key: " << tempNode->key << endl;
		}

		tree1->insert(5);

		staticTree = tree1->staticBSTree();

		cout << "Static Tree: ";
		staticTree->print();

		delete staticTree;

		tree1->insert(2);
		tree1->insert(10);

		cout << "Number of nodes: " << tree1->getNumberOfNodes() << endl;
		cout << "Height: " << tree1->getHeight() << endl;

		tree1->insert(1);
		tree1->insert(6);

		cout << "Number of nodes: " << tree1->getNumberOfNodes() << endl;
		cout << "Height: " << tree1->getHeight() << endl;

		tempNode = tree1->search(10);

		if (tempNode == nullptr)
		{
			cout << "Node not found." << endl;
		}
		else
		{
			cout << "Node key: " << tempNode->key << endl;
		}

		tempNode = tree1->search(55);

		if (tempNode == nullptr)
		{
			cout << "Node not found." << endl;
		}
		else
		{
			cout << "Node key: " << tempNode->key << endl;
		}

		cout << "Tree1 - Breadth First: ";
		tree1->breadthFirst();

		cout << "Tree1 - Preorder: ";
		tree1->preorder();
		cout << endl;

		staticTree = tree1->staticBSTree();

		cout << "Static Tree: ";
		staticTree->print();
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

	delete staticTree;

	delete tree1;

	cout << endl;

	/* Drugi zadatak */
	DynamicBSTree2<int>* tree2 = new DynamicBSTree2<int>();

	try
	{
		BSTNode<int>* tempNode = tree2->search(10);

		if (tempNode == nullptr)
		{
			cout << "Node not found." << endl;
		}
		else
		{
			cout << "Node key: " << tempNode->key << endl;
		}

		cout << "Level with max. number of nodes: " << tree2->levelWithMaxNumberOfNodes() << endl;

		tree2->insert(5);

		cout << "Level with max. number of nodes: " << tree2->levelWithMaxNumberOfNodes() << endl;

		tree2->insert(2);
		tree2->insert(7);

		cout << "Number of nodes: " << tree2->getNumberOfNodes() << endl;

		tree2->insert(1);

		cout << "Level with max. number of nodes: " << tree2->levelWithMaxNumberOfNodes() << endl;

		tree2->insert(10);
		tree2->insert(6);

		cout << "Number of nodes: " << tree2->getNumberOfNodes() << endl;

		tempNode = tree2->search(10);

		if (tempNode == nullptr)
		{
			cout << "Node not found." << endl;
		}
		else
		{
			cout << "Node key: " << tempNode->key << endl;
		}

		cout << "Tree2 - Breadth First: ";
		tree2->breadthFirst();

		cout << "Tree2 - Preorder: ";
		tree2->preorder();
		cout << endl;

		cout << "Level with max. number of nodes: " << tree2->levelWithMaxNumberOfNodes() << endl;
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

	delete tree2;

	return 0;
}