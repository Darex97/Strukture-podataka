#pragma once

#include <iostream>

#include <exception>

using namespace std;

class Tree
{
public:
	Tree(int numberOfLevels);
	~Tree();

	bool isEmpty() { return !_taken[0]; }
	bool isFull() { return _currNumberOfElements == _maxNumberOfElements; }
	bool isInTree(int element) { return search(element) != -1; }

	void insert(int element);
	void remove(int element);

	int search(int element);

	void balance();

	void preorder() 
	{
		if ( isEmpty() )
			cout << "Tree is empty" << endl;
		preorder (0);
		cout << endl;
	}
	void inorder()
	{
		if ( isEmpty() )
			cout << "Tree is empty" << endl;
		inorder(0);
		cout << endl;
	}
	void postorder()
	{
		if ( isEmpty() )
			cout << "Tree is empty" << endl;
		postorder(0);
		cout << endl;
	}

	void print();

	int* toArray();
	int* toOrganizedArray();

	int getSize() { return _maxNumberOfElements; }
	int getCurrentNumberOfElements() { return _currNumberOfElements; }
	int getNumberOfLevels() { return _numberOfLevels; }



	int differentNodes();
	int height();
	int moment();
	int numberOfLeaves();
	void deleteLeaves();
	void mirror();
	void mix(Tree& t1, Tree& t2);
	int levelWithMostNodes();

private:
	bool* _taken;
	int* _key;
	int* _left;
	int* _right;

	int _maxNumberOfElements;
	int _currNumberOfElements;
	int _numberOfLevels;

	void preorder(int coef);
	void inorder(int coef);
	void postorder(int coef);

	void balance(int* data, int size);
	void balance(int* data, int first, int last);
};