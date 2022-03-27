#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class SparseMatrix
{
public:
	SparseMatrix();
	SparseMatrix(int rows,int cols);

	void addElement(int row, int col, int data);

	int getElement(int row, int col);

	void print();


private:
	Node** _rows;
	Node** _cols;
	int _rowSize;
	int _colSize;
};