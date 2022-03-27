#pragma once
#include"BSTNode.h"

class DinamicBSTree 
{
protected:

	BSTNode* root;
public:
	DinamicBSTree();
	~DinamicBSTree();
	void deleteTree(BSTNode*);
	void insert(int);
	void visit();//visit nam je inorder stamapanje
	void visit(BSTNode*);
	int max(int, int);

	int height();//3. zadatak
	int height(BSTNode*);
	

	int momentOfTree();//5. zadatak
	int momentOfTree(BSTNode*);

	int tezina();//7. zadatak
	int tezina(BSTNode*);

	void brisanjeListova();//9. zadatak
	void brisanjeListova(BSTNode*);

	void mirror();//11.zadatak
	void mirror(BSTNode*);

	void spajamStabla(DinamicBSTree& ds);//13.zadatak
	void spajamStabla(BSTNode*);

	int najviseCvorova();//15. zadatak
	void najviseCvorova(int*, BSTNode*);//povrati tip je void zato sto
	//resenja upisujemo u rezultujuci niz
	int dubinaCvora(BSTNode*);
	BSTNode* roditeljCvora(BSTNode*, BSTNode*);

	//2015 
	int getDeepest();
	int getDeepest(BSTNode* node, BSTNode** deepest);
	
	//2015 popravni - dobar
	int CountGreater(int value);
	int CountGreater(BSTNode* b,int);

	//2014 - dobar
	int deleteRightLeaves();
	int deleteRightLeaves(BSTNode* p);

	//2013
	//int getDepth(BSTNode* p); 
	//ovo je zapravo moja fja dubinaCvora, identicna

	//2013 popravni
	// Treba napisati fja koja brise sve listove. Imas uradjeno.

	//2016 popravni
	//dovoljno je za ovaj zadatak naci samo sumu
	//nije potrebno razdvajati levu i desnu, ali sam ostavio da bi 
	//imao i to ako ti zatreba
	BSTNode* findMaximal();
	BSTNode* findMaximal(BSTNode*);
	int levaSuma(BSTNode* p);
	int desnaSuma();
	int desnaSuma(BSTNode* p);
	int levaSuma();
	int razlikaSuma(BSTNode*);
	int razlikaSuma();
	int suma(BSTNode*);
	void nadjiCvor(int* s, BSTNode* povratni, BSTNode* r);
};