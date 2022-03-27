#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class CSparseMatrix
{
public:
	CNode<T> **rows, **columns;
	int dimx;
	int dimy;

	CSparseMatrix(void);
	CSparseMatrix(int dimx, int dimy);

	void SetAt(T el, int i, int j);
	T GetAt(int i, int j);
	void Print();
	~CSparseMatrix(void);
};

template <class T>
CSparseMatrix<T>::CSparseMatrix(void) {
	dimx = dimy = 0;
	rows = columns = NULL;
}

template <class T>
CSparseMatrix<T>::CSparseMatrix(int dimx, int dimy) {
	this->dimx = dimx;
	this->dimy = dimy;

	rows = new CNode<T>*[dimx];
	columns = new CNode<T>*[dimy];;
}

template <class T>
T CSparseMatrix<T>::GetAt(int i, int j) {
	CNode<T> *temp;
	
	for (temp = row[i]->head; temp != NULL && temp->j == j);

	if (temp != NULL)
		return temp->data;
	else
		return 0;
}

template <class T>
void CSparseMatrix<T>::Print() {
	for (int i = 0; i < dimx; i++) {
		for (int j = 0; j < dimy; j++) {
			cout << GetAt(i, j) << " ";
		}
		cout << endl;
	}
}

template <class T>
void CSparseMatrix<T>::SetAt(T el, int i, int j) {
	if (el == 0)
		return;

	if (rows[i] == NULL) {
		// So, this is the first element.
		CNode *node = new CNode(i, j, el, NULL, NULL);
		rows[i] = cols[i] = node;

		return;
	}

	// Maybe this element already exists?
	CNode *temp = NULL;
	for (temp = rows[i]; temp != NULL && temp->j != j; temp = temp->nextrow);

	if (temp != NULL) {
		temp->data = el;
		return;
	}

	// Nope, this is the new one. Update rows and columns.
	CNode *prev = NULL;
	temp = NULL
	for (temp = rows[i]; temp != NULL && temp->j < j; prev = temp, temp = temp->nextrow);

	if (temp == NULL) {
		// To the end of the list!
		CNode *node = new CNode(i, j, el, NULL, NULL);
		prev->next = node;
	} else {
		// Somewhere in the middle
		CNode *node = new CNode(i, j, el, temp->next, NULL);
		prev->next = node;
	}


}