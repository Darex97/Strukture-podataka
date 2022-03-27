#pragma once
#include<iostream>
#include"BSTNode.h"
using namespace std;

class BSTree
{
protected:
	BSTNode *root;
	int numOfElements;
public:
	BSTree()
	{
		this->root=NULL;
		this->numOfElements=0;
	}
	void insert(int el);
	int TreeHeight();
	int TreeHeight(BSTNode *p);
	void inorder();
	void inorder(BSTNode *p);
	void visit(BSTNode *p);
	~BSTree(void);
};

