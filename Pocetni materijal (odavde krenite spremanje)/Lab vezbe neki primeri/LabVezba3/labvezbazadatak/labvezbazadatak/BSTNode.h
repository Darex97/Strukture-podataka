#pragma once
#include<iostream>
using namespace std;

class BSTNode
{
public:
	int key;
	BSTNode *left,*right;
public:
	BSTNode()
	{
		this->left=this->right=NULL;
	}
	BSTNode(int el)
	{
		this->key=el;
		this->left=this->right=NULL;
	}
	BSTNode(int el,BSTNode *left,BSTNode *right)
	{
		this->key=el;
		this->left=left;
		this->right=right;
	}
	bool isLT(int el)
	{
		if (this->key < el)
			return true;
		else
			return false;
	}
	bool isGT(int el)
	{
		if (this->key > el)
			return true;
		else
			return false;
	}
	bool isEQ(int el)
	{
		if (this->key == el)
			return true;
		else
			return false;
	}
	void setKey(int el)
	{
		this->key=el;
	}
	int getKey()
	{
		return this->key;
	}
	BSTNode* getLeft()
	{
		return this->left;
	}
	BSTNode* getRight()
	{
		return this->right;
	}
	void visit()
	{
		cout<<this->key<<" "<<endl;
	}
	~BSTNode();
};

