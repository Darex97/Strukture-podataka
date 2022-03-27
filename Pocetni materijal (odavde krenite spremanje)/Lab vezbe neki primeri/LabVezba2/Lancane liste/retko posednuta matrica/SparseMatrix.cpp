// SparseMatrix.cpp: implementation of the SparseMatrix class.
//
//////////////////////////////////////////////////////////////////////

#include "SparseMatrix.h"
#include "Node.h"
#include <iostream>
using namespace std;


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SparseMatrix::SparseMatrix(int n){
	noElements = 0;
	size = n;
	load_factor = 0;
	colums = new Node*[size];
	for(unsigned int i=0;i<size;i++)
		colums[i] = NULL;
	rows = new Node*[size];
	for(int i=0;i<size;i++)
		rows[i] = NULL;
}

SparseMatrix::~SparseMatrix(){
	unsigned int i = 0;
	while(i<size){
		for (Node *pom = rows[i];pom != NULL;){
			Node *tmp = pom;
			pom = pom->linkv;
			delete tmp;
		}
		i++;
	}
	delete [] colums;
	delete [] rows;
}

void SparseMatrix::addElement(int x, int y, int z){//radi
	if (rows[x] == NULL && colums[y] == NULL){
		rows[x] = new Node(x,y,z,rows[x],colums[y]);
		colums[y] = rows[x];
	}
	
	else if(rows[x] == NULL){
		Node *pom;
		for(pom = colums[y];pom->linkk != NULL;pom = pom->linkk);
		pom->linkk = new Node(x,y,z,rows[x],NULL);
		rows[x] = pom->linkk;
	}
	else if(colums[y] == NULL){
		Node *pom;
		for(pom = rows[x];pom->linkv != NULL;pom = pom->linkv);
		pom->linkv = new Node(x,y,z,NULL,colums[y]);
		colums[y] = pom->linkv;
	}
	else {
		Node *pom1;
		Node *pom2;
		for(pom1 = colums[y];pom1->linkk != NULL;pom1 = pom1->linkk);
		for(pom2 = rows[x];pom2->linkv != NULL;pom2 = pom2->linkv);
		pom1->linkk = new Node(x,y,z,NULL,NULL);
		pom2->linkv = pom1->linkk;
	}
	noElements++;
	load_factor = (double)noElements/(size*size);
}

void SparseMatrix::display(){
	unsigned int i;
	for(i=0;i<size;i++){
		for(Node *pom = rows[i];pom != NULL; pom = pom->linkv)
			pom->print();
		cout<<endl;
	}
}

double SparseMatrix::getLoadFactor(){ return load_factor;}