#include "BSTree.h"
#include"QueueAsArray.h"


BSTree::BSTree(void)
{
	this->root=NULL;
	this->numOfElements=0;
}



bool BSTree::isEmpty()
{
	return this->root == NULL;
}



void BSTree::insert(int el)
{
	BSTNode *p=this->root;
	BSTNode *prev=NULL;

	while (p != NULL)
	{
		prev=p;
		
		if (p->isLT(el))
			p=p->right;
		else
			p=p->left;
	}

	if (this->root == NULL)
	{
		this->root=new BSTNode(el);
	}
	else
	{
		if (prev->isLT(el))
			prev->right=new BSTNode(el);
		else
			prev->left=new BSTNode(el);
	}
	this->numOfElements++;
}




BSTNode* BSTree::search(int el)      //ove tri f-je realizuju trazenje u uredjenom stablu
{
	return search(this->root,el);
}
BSTNode* BSTree::search(BSTNode* p,int el)
{
	while (p != NULL)
	{
		if (p->isEQ(el))
			return p;
		else
			if (p->isGT(el))
				p=p->left;
			else
				p=p->right;
	}
	return NULL;
}
bool BSTree::isInTree(int el) //ova f-ja poziva f-ju search(el) koja u sebi poziva f-ju search(BSTNode *p,int el)(ova f-ja vraca pointer na cvor ili NULL).Vraca true ili false u zavisnosti od toga da li su prethodne f-je vratile pok na cvor ili NULL
{
	return search(el) != NULL;
}



void BSTree::preorder()
{
	this->preorder(this->root);
}
void BSTree::preorder(BSTNode *p)
{
	if (p != NULL)
	{
		p->visit();
		this->preorder(p->left);
		this->preorder(p->right);
	}
}
void BSTree::inorder()
{
	this->inorder(this->root);
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
void BSTree::postorder()
{
	this->postorder(this->root);
}
void BSTree::postorder(BSTNode *p)
{
	if (p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		p->visit();
	}
}

int BSTree::numOfUnique()// ????????????????????????????????????????
{	
	int num=0;
	numOfUnique(this->root,num);
	return num;
}
void BSTree::numOfUnique(BSTNode *p1,int &num)
{
	//radi sa pomocnim nizom!!!
}



int BSTree::moment()
{
	return this->numOfElements;
}



int BSTree::TreeHeight()
{
	return TreeHeight(this->root);
}
int BSTree::TreeHeight(BSTNode *p)
{
	if(p==NULL)
		return 0;
    else 
	{ 
		int h1=TreeHeight(p->left); 
		int h2=TreeHeight(p->right);
		if (h1 > h2) 
			return h1+1; 
		else 
			return h2+1;  
	}
}



void BSTree::Delete()
{
	DeleteLeaf(this->root,this->root);
}
void BSTree::DeleteLeaf(BSTNode* node,BSTNode* prev)		
{
	if(node)
	{
		if(!node->getLeft() && !node->getRight())
		{
			if(prev->getKey() >= node->getKey())
			{
				prev->left->setKey(0);
				prev->left=NULL;
			}
			else
			{
				prev->right->setKey(0);
				prev->right=NULL;
			}
			delete node;
			return;
		}
		DeleteLeaf(node->left,node);
		DeleteLeaf(node->right,node);
	}
}


BSTree* BSTree::Mirror()
{
	BSTree *mirror=new BSTree();
	Mirror(this->root,mirror);
	return mirror;
}
void BSTree::Mirror(BSTNode *p,BSTree *mirror)
{
	if (p!=NULL)
	{
		mirror->insertMirror(p->key);
		Mirror(p->left,mirror);
		Mirror(p->right,mirror);
	}
}
void BSTree::insertMirror(int el)
{
	
	BSTNode *p=this->root;
	BSTNode *prev=NULL;

	while (p != NULL)
	{
		prev=p;
		
		if (p->isLT(el))
			p=p->left;
		else
			p=p->right;
	}

	if (this->root == NULL)
	{
		this->root=new BSTNode(el);
	}
	else
	{
		if (prev->isLT(el))
			prev->left=new BSTNode(el);
		else
			prev->right=new BSTNode(el);
	}
	this->numOfElements++;
}



BSTNode* BSTree::returnParent(BSTNode *node)//??????
{
	BSTNode *parent=NULL;
	parent=returnParent(this->root,node,parent);
	return parent;
}
BSTNode* BSTree::returnParent(BSTNode *p,BSTNode *Node,BSTNode *Parent)//????????
{
	if (p!=NULL)
	{
		if(p->left==Node || p->right==Node)
		{
			return Parent=p;
		}
		return Parent;
		returnParent(p->left,Node,Parent);
		returnParent(p->right,Node,Parent);
	}
}



int BSTree::TreeWeight()
{
	int num=0;
	TreeWeight(this->root,num);
	return num;
}
void BSTree::TreeWeight(BSTNode *p,int &num)
{
	
	if (p!=NULL)
	{
		if (p->left==NULL && p->right==NULL)
			num++;
		TreeWeight(p->left,num);
		TreeWeight(p->right,num);
	}
}



void BSTree::Merge(BSTNode *p)
{
	if (p!=NULL)
	{
		this->insert(p->key);
		Merge(p->left);
		Merge(p->right);
	}
}
void BSTree::deleteTree(BSTNode *obj)
{
	if (obj != NULL)
	{	
		this->deleteTree(obj->left);
		this->deleteTree(obj->right);
		delete obj;
	}	
}
void BSTree::breadthFirst()
{
	BSTNode *p=this->root;
	QueueAsArray queue(this->numOfElements);

	if (p!=NULL)
	{
		queue.enqueue(p);
		while (!queue.isEmpty())
		{
			p=queue.dequeue();
			p->visit();
			if (p->left!=NULL)
				queue.enqueue(p->left);
			
			if (p->right!=NULL)
				queue.enqueue(p->right);
		}
	}
}
int BSTree::Level()
{
	int level=0;
	BSTNode **niz=new BSTNode*[this->numOfElements*2];///// zavrsi!!!!!! zavrsiiii!!
	BSTNode *p=this->root;
	if (p!=NULL)
	{
		int i=2;
		niz[0]=p;
		niz[1]=NULL;

		int pok=0;

	}
	return level;
}
BSTree::~BSTree(void)
{
	deleteTree(this->root);
}
