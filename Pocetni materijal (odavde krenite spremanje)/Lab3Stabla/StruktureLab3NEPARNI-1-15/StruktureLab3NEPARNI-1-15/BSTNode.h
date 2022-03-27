#pragma once
#include<iostream>
using namespace std;

class BSTNode
{
public:
	int key;
	BSTNode* left, *right;
public:
	BSTNode() { left = NULL; right = NULL; }
	BSTNode(int el) { key = el;left = NULL;right = NULL; }
	BSTNode(int el, BSTNode* l, BSTNode* r) 
	{
		key = el;
		left = l;
		right = r;
	}

	/*bool isLT(int el) { return key < el; }
	bool isGT(int el) { return key > el; }
	bool isEQ(int el) { return key == el; }*/
	void setKey(int el) { key = el; }
	void visit() { cout << key << " "; }

};