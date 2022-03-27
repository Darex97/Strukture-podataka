#include<iostream>
#include"BSTNode.h"
#include"BSTree.h"
using namespace std;

void main()
{
	BSTree *tree=new BSTree();
	tree->insert(8);
	(*tree).insert(9);
	(*tree).insert(5);
	(*tree).insert(6);
	(*tree).insert(3);
	(*tree).insert(0);
	(*tree).insert(10);
	cout<<"Stablo:"<<endl;
	tree->inorder();
	cout<<"Visina stabla:"<<tree->TreeHeight()<<endl;
	
}