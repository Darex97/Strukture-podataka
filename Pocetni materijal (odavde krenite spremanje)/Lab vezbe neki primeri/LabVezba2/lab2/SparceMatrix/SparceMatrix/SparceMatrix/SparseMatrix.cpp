#include "SparseMatrix.h"

SparseMatrix::SparseMatrix()
	: _rows(0), _cols(0)
{
}

SparseMatrix::SparseMatrix(int rows, int cols)
	: _rows(new Node*[rows]), _cols(new Node*[cols]), _rowSize(rows), _colSize(cols)
{
	for(int iter = 0; iter < rows; iter++)
		_rows[iter] = 0;
	for(int iter = 0; iter < cols; iter++)
		_cols[iter] = 0;
}

void SparseMatrix::print()
{
	for(int iRow = 0; iRow < _rowSize; iRow++)
	{	
		if(_rows[iRow])
			for(int iCol = 0; iCol < _colSize; iCol++)
			{	
				Node* temp = _cols[iCol];
				while(temp && temp->getRow() != iRow)
					temp = temp->getColNext();
				if(temp)
					cout << temp->getData() << " ";
				else
					cout << "0 ";
			}
		else
			for(int iter = 0; iter < _colSize; iter++)
				cout << "0 ";
		cout << endl;
	}
}

void SparseMatrix::addElement(int row, int col, int data)
{
	Node* temp = new Node(row, col, data, 0, 0);
	
	if(!_rows[row])
		_rows[row] = temp;

	if(_rows[row] && _rows[row]->getCol() > col)
	{	
		temp->setRowNext(_rows[row]);
		_rows[row] = temp;
	}
//
	if(!_cols[col])
		_cols[col] = temp;

	if(_cols[col] && _cols[col]->getRow() > row)
	{
		temp->setColNext(_cols[col]);
		_cols[col] = temp;
	}

	Node* tempCol = _cols[col];
	if(tempCol && tempCol->getRow() < row)
	{
		while(tempCol->getColNext() && tempCol->getRow() < row)
			tempCol = tempCol->getColNext();
		tempCol->setColNext(temp);
	}

	Node* tempRow = _rows[row];
	if(tempRow && tempRow->getCol() < col)
	{
		while(tempRow->getRowNext() && tempRow->getCol() < col)
			tempRow = tempRow->getRowNext();
		tempRow->setRowNext(temp);
	}
}

int SparseMatrix::getElement(int row, int col)
{
	if(!_rows[row] || !_cols[col])
		return 0;

	Node* rowIter = _rows[row];
	while(rowIter && rowIter->getRow() != row)
		rowIter = rowIter->getRowNext();

	if(rowIter && rowIter->getCol() == col)
		return rowIter->getData();

}