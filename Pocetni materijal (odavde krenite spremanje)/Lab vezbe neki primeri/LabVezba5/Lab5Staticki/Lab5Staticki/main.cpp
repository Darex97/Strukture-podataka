#include"BSTree.h"
#include<iostream>
using namespace std;


void main()
{
	try
	{
		BSTree *tree=new BSTree(15);
		tree->insert(4);
		tree->insert(2);
		tree->insert(2);
		tree->insert(9);
		tree->insert(9);
		tree->insert(10);
		tree->insert(7);
		tree->print();
		

		cout<<"Broj jedinstvenih cvorova:"<<tree->numOfUnique()<<endl;
		cout<<"Visina stabla:"<<tree->TreeHeight()<<endl;
		cout<<"Tezina stabla:"<<tree->TreeWeight()<<endl;
	}
	catch(char *message)
	{
		cout<<message<<endl;
	}
}