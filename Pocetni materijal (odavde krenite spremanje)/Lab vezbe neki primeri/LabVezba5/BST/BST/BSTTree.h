#pragma once
#include"BSTNode.h"
#include<iostream>
using namespace std;
template<class T>
class BSTTree
{
public:
	BSTNode<T>* root;
	int NoEl;
    
	BSTTree()
	{
		root=NULL;
		NoEl=0;
	}
	int Visina(BSTNode<T>* p);
	void BrisiList(BSTNode<T>* p);
	int BrCvorova(BSTNode<T>* p);
	void Mirror(BSTNode<T>* p);
	~BSTTree()
	{
		deleteTree(root);
	}
	void NONode()
	{
		 NoNode(root);
	}
	int NoNode(BSTNode<T>* n);
	BSTNode<T>* RetRoot()
	{
		return root;
	}

	void preorder(BSTNode<T> * p);
	void preorder()
	{
		preorder(root);
	}
	void deleteTree(BSTNode<T> * p);
	void Insert(T el);
};
template<class T>
void BSTTree<T>::preorder(BSTNode<T>* p)
{
if(p!=NULL)
{
	preorder(p->l);
	p->print();
	preorder(p->r);
}
}
template<class T>
void BSTTree<T>::Insert(T el)
{
	BSTNode<T> *p=root,*prev=NULL;
	while(p!=NULL)
	{
		prev=p;
		if(p->Manje(el))
			p=p->r;
		else
			p=p->l;
	}
	if(root==NULL)
		root=new BSTNode<T>(el);
	else if(prev->Manje(el))
		prev->r=new BSTNode<T>(el);
	else
		prev->l=new BSTNode<T>(el);
	NoEl++;
}
template<class T>
void BSTTree<T>::deleteTree(BSTNode<T> *p)
{
	if(p!=NULL)
	{
		deleteTree(p->l);
		deleteTree(p->r);
		delete p;
	}
}
template<class T>
int BSTTree<T>::Visina(BSTNode<T> *p)
{
	if(p==NULL)
		return 0;
    else { 
    int lD = Visina(p->l); 
    int rD= Visina(p->r);
    if (lD > rD) return(lD+1); 
    else return(rD+1); 
  } 
} 

template<class T>
int BSTTree<T>::BrCvorova(BSTNode<T> *p)
{
	if(p==NULL)
		return 0;
	return (BrCvorova(p->l)+1+ BrCvorova(p->r));
}
template<class T>
void BSTTree<T>::Mirror(BSTNode<T> *p)
{
	if(p==NULL)
		return;
	else
	{
		BSTNode<T>* pom;
		Mirror(p->l);
		Mirror(p->r);

		pom=p->l;
		p->l=p->r;
		p->r=pom;
	}
}
