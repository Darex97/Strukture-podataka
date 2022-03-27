#pragma once
#include "BSTNode.h"

class BSTree
{
protected:
	BSTNode *koren;
	int noElem;
public:
	BSTree()
	{
		noElem = 0;
		koren = NULL;
	}

	~BSTree()
	{
		deleteTree(koren);
	}

	void deleteTree(BSTNode *p)
	{
		if (p != NULL)
		{
			deleteTree(p->levi);
			deleteTree(p->desni);
			delete p;
		}
	}

	bool isEmpty()
	{
		return koren == NULL;
	}

	void insert(int elem)
	{
		BSTNode *p = koren, *prev = NULL;
		while (p != NULL)
		{
			prev = p;
			if (p->isLower(elem))
				p = p->desni;
			else
				p = p->levi;
		}
		if (koren == NULL)
			koren = new BSTNode(elem);
		else if (prev->isLower(elem))
			prev->desni = new BSTNode(elem);
		else
			prev->levi = new BSTNode(elem);
		noElem++;
	}
	void inorder()
	{
		inorder(koren);
	}
	void inorder(BSTNode *p)
	{
		if (p != NULL)
		{
			inorder(p->levi);
			p->visit();
			inorder(p->desni);
		}
	}

	void preorder()
	{
		preorder(koren);
	}
	void preorder(BSTNode *p)
	{
		if (p != NULL)
		{
			p->visit();
			preorder(p->levi);
			preorder(p->desni);
		}
	}

	void postorder()
	{
		postorder(koren);
	}
	void postorder(BSTNode *p)
	{
		if (p != NULL)
		{
			preorder(p->levi);
			preorder(p->desni);
			p->visit();
		}
	}
	BSTNode* search(int elem)
	{
		search(koren, elem);
	}
	BSTNode* search(BSTNode *p, int el)
	{
		while (p != NULL)
		{
			if (p->isEqual(el))
				return p;
			else if (p->isGreater(el))
				p = p->levi;
			else
				p = p->desni;
		}
		return NULL;
	}
};