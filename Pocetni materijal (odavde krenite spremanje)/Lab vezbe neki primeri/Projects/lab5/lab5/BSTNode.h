#pragma once
#include <iostream>
using namespace std;

class BSTNode
{
public:
	int el;
	BSTNode *levi, *desni;
public:
	BSTNode()
	{
		levi = desni = NULL;
	}
	BSTNode(int elem)
	{
		el = elem;
		levi = desni = NULL;
	}
	BSTNode(int elem, BSTNode *left, BSTNode *right)
	{
		el = elem;
		levi = left;
		desni = right;
	}

	bool isGreater(int elem)
	{
		if (el > elem)
			return true;
		else
			return false;
	}

	bool isLower(int elem)
	{
		if (el < elem)
			return true;
		else
			return false;
	}

	bool isEqual(int elem)
	{
		if (el == elem)
			return true;
		else
			return false;
	}

	void setEl(int elem)
	{
		el = elem;
	}

	int getElem()
	{
		return el;
	}

	void visit()
	{
		cout << el << " ";
	}
};