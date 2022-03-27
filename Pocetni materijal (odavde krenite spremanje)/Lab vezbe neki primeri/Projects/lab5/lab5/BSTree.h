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

	void brisanjeListova()
	{
		if (koren != NULL)
			if (koren->levi == NULL && koren->desni == NULL)
			{
				delete koren;
				koren = NULL;
			}
		brisanjeListova(koren);
	}

	void brisanjeListova(BSTNode* p)
	{
		if (p == NULL)
			return;
		if (p->levi != NULL)
			if (p->levi->levi == NULL && p->levi->desni == NULL)
			{
				delete p->levi;
				p->levi = NULL;
			}
		if (p->desni != NULL)
			if (p->desni->levi == NULL && p->desni->desni == NULL)
			{
				delete p->desni;
				p->desni = NULL;
			}
		brisanjeListova(p->levi);
		brisanjeListova(p->desni);
	}
};