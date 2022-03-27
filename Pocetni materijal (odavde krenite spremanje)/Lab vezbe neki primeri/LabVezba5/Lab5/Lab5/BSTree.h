#pragma once
#include"BSTNode.h"
#include<iostream>
using namespace std;

class BSTree
{
public:
	BSTNode *root;
	int numOfElements;
public:
	BSTree();
	void deleteTree(BSTNode *obj);
	~BSTree();
	bool isEmpty();
	void insert(int el);//ubacuje cvor sa zadatom vrednoscu kljuca(el) na odgovarajuce mesto u UREDJENOM STABLU!!!
	void insertMirror(int el);
	bool isInTree(int el);  //ispituje da li postoji cvor sa zadatim elementom
	BSTNode* search(int el);  //trazi cvor sa zadatim elementom polazeci od korena stabla
	BSTNode* search(BSTNode *p,int el);  //trazi cvor sa zadatim elementom polazeci od cvora p
	void preorder();  //preorder obilazak stabla polazeci od korena
	void inorder();  //inorder obilazak stabla polazeci od korena
	void postorder();  //postorder obilazak stabla polazeci od korena
	void preorder(BSTNode *p);  //preorder obilazak stabla polazeci od cvora p
	void inorder(BSTNode *p);  //inorder obilazak stabla polazeci od cvora p
	void postorder(BSTNode *p);  //postorder obilazak stabla polazeci od cvora p
	//void iterativePreorder();  //iterativni preorder obilazak stabla polazeci od korena
	//void iterativeInorder();  //iterativni inorder obilazak stabla polazeci od korena
	//void iterativePostorder();  //iterativni postorder obilazak stabla polazeci od korena
	int numOfUnique();
	void numOfUnique(BSTNode *p1,int &num);
	int moment();
	int TreeHeight();
	int TreeHeight(BSTNode *p);
	int TreeWeight();
	void TreeWeight(BSTNode *p,int &num);
	void Delete();
	void DeleteLeaf(BSTNode *node,BSTNode *prev);
	BSTNode* returnParent(BSTNode *node);
	BSTNode* returnParent(BSTNode *p,BSTNode *s,BSTNode *k);
	BSTree* Mirror();
	void Mirror(BSTNode *p,BSTree *t);
	void Merge(BSTNode *p);
	void breadthFirst();
	int Level();
};

