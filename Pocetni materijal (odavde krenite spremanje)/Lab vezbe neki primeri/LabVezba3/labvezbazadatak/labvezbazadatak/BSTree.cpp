#include "BSTree.h"


void BSTree::insert(int el)
{
	BSTNode *p=this->root,*prev=NULL;

	while (p!=NULL)
	{
		prev=p;
		if (p->isLT(el))
			p=p->right;
		else
			p=p->left;
	}
	if (this->root==NULL)
		this->root=new BSTNode(el);
	else
	{
		if (prev->isLT(el))
			prev->right=new BSTNode(el);
		else
			prev->left=new BSTNode(el);
	}
	this->numOfElements++;
}

int BSTree::TreeHeight()
{
	return TreeHeight(this->root);
}
int BSTree::TreeHeight(BSTNode *p)
{
	int h1=0;
	int h2=0;
	if(p==NULL)
		return 0;
    else 
	{ 
		h1=TreeHeight(p->left); 
		h2=TreeHeight(p->right);
		if (h1 > h2) 
			return h1+1; 
		else 
			return h2+1;  
	}
}
void BSTree::inorder()
{
	inorder(this->root);
}
void BSTree::inorder(BSTNode *p)
{
	if (p!=NULL)
	{
		inorder(p->left);
		p->visit();
		inorder(p->right);

	}
}
BSTree::~BSTree(void)
{
}
