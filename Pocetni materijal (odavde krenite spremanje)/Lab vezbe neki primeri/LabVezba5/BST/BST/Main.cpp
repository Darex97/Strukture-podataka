#include<iostream>
#include"BSTTree.h"
using namespace std;
void main()
{
	BSTTree<int> bt;
	bt.Insert(3);
	bt.Insert(33);
	bt.Insert(4);
	bt.Insert(2);
	bt.Insert(7);
	bt.Insert(12);
	bt.preorder();
	cout<<endl;
	cout<<bt.BrCvorova(bt.root);
	cout<<endl;
	bt.Mirror(bt.root);
	
	bt.preorder();
	
}