#pragma once

class Node
{
public:
	Node();
	Node(int row, int col, int data, Node* rowNext, Node* colNext) 
		: _row(row), _col(col), _data(data), _rowNext(rowNext), _colNext(colNext)
	{}
	

	int getRow() { return _row; }
	int getCol() { return _col; }
	int getData() { return _data; }
	Node* getRowNext() { return _rowNext; }
	Node* getColNext() { return _colNext; }

	void setRow(int row) { _row = row; }
	void setCol(int col) { _col = col; }
	void setData(int data) { _data = data; }
	void setRowNext(Node* rowNext) { _rowNext = rowNext; }
	void setColNext(Node* colNext) { _colNext = colNext; }

private:
	int _row;
	int _col;
	int _data;
	Node* _rowNext;
	Node* _colNext;
};