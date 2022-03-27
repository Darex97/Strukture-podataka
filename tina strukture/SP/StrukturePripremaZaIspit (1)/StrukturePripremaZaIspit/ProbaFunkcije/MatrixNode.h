#pragma once
#include <iostream>
class MatrixNode
{
private:
	int i, j;
	int value;
	MatrixNode* right;
	MatrixNode* down;
public:
	MatrixNode() {
		i = j = value = 0;
		right = down = NULL;
	}
	MatrixNode(int i,int j,int value) {
		this->i = i;
		this->j = j;
		this->value = value;
		right =NULL;
		down = NULL;
	}
	MatrixNode(int i, int j,int value, MatrixNode* next, MatrixNode* down) {
		this->i = i;
		this->j = j;
		this->value = value;
		this->right = next;
		this->down = down;
	}
	~MatrixNode() {
		right = down = nullptr;
	}
	int getI() { return i; }
	int getJ() { return j; }
	int getValue() { return value; }
	MatrixNode* getRight() { return right; }
	MatrixNode* getDown() { return down; }
	MatrixNode*& getRightRef() { return right; }
	MatrixNode*& getDownRef() { return down; }
};

