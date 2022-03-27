#pragma once
#include"Red.h"
#include"Cvor.h"
#include<iostream>
using namespace std;
class Stablo
{protected:
	Cvor* root;
	long brel;
public:
	Stablo() { root = NULL; brel = 0; }
	~Stablo();
	void deleteTre(Cvor* t);
	bool isEmpty() { return root == NULL; }
	void insert(int el,int dana,int testiranih);//modifikovano
	bool isInTree(int el) { return search(el) != NULL; }
	Cvor* search(int el) { return search(root, el); }
	Cvor* search(Cvor* p, int el);
	void balance(int data[], int first, int last);
	void deleteByCopying(int el);
	void deleteByMerging(int el);
	void preorder() { preorder(root); }
	void inorder() { inorder(root); }
	void postorder() { postorder(root); }
	void preorder(Cvor* p);
	void inorder(Cvor* p);
	void postorder(Cvor* p);
	int maxLvl();
	int maxLvl(Cvor* p, int* count);
	int height();
	int height(Cvor* a);
	int max(int a, int b);
	int Vratizbir();
	int Vratizbir(Cvor*);
	Cvor* nadji(Cvor* root, int value);
	Cvor* nadji(int value);
	Cvor* testirani(Cvor* cvor, int day);
	Cvor* testirani(int day);
	//void breathFirst();// radi se sa specijalni red
	//void iterativePreorder(); za ova tri koristim stek isto ko za pseudo kod
	//void iterativeInorder();
	//void iterativePostorder();



};

