#pragma once
#include "BSTNode.h"
#include <iostream>

using namespace std;

template <class T>
class BSTree
{
private:
	BSTNode<T> *root;
	int numElements;
public:
	BSTree(void);
	void insert(T element);
	
	int calculateWeight();
	int calculateWeight(BSTNode<T>* start);
	
	void print();
	void print(BSTNode<T>* start, int depth);

	void deleteTree();
	void deleteTree(BSTNode<T> *start);

	BSTNode<T>* search(T element);
	BSTNode<T>* search(BSTNode<T> *start, T element);

	~BSTree(void);
};


template <class T>
BSTree<T>::BSTree(void) {
	root = NULL;
	numElements = 0;
}

template <class T>
void BSTree<T>::insert(T element) {
	BSTNode<T>* temp = new BSTNode<T>(element);
	
	BSTNode<T> *p = root, *prev = NULL;

	if (root == NULL)
		root = temp;
	else {
		while (p != NULL) {
			prev = p;

			if (p->key < element)
				p = p->right;
			else
				p = p->left;
		}

		if (prev->key < element)
			prev->right = temp;
		else
			prev->left = temp;
	}

	numElements++;
}

template <class T>
int BSTree<T>::calculateWeight() {
	return calculateWeight(root);
}

template <class T>
int BSTree<T>::calculateWeight(BSTNode<T> *start) {
	if (start->left == NULL && start->right == NULL)
		return 1;

	int num = 0;

	if (start->left != NULL)
		num += calculateWeight(start->left);

	if (start->right != NULL)
		num += calculateWeight(start->right);

	return num;
}

template <class T>
void BSTree<T>::print() {
	if (root != NULL)
		print(root, 0);
	else
		cout << "Tree is empty.";
}

template <class T>
void BSTree<T>::print(BSTNode<T> *start, int depth) {
	cout << start->key << endl;
	
	for (int i = 0; i < depth; i++)
		cout << " ";

	if (start->left == NULL)
		cout << "left: NULL " << endl;
	else {
		cout << "left: " << endl;
		print(start->left, depth + 1);
	}

	if (start->right == NULL)
		cout << "right: NULL " << endl;
	else {
		cout << "right: " << endl;
		print(start->right, depth + 1);
	}
}

template <class T>
void BSTree<T>::deleteTree() {
	deleteTree(root);
}

template <class T>
void BSTree<T>::deleteTree(BSTNode<T> *start) {
	if (start == NULL)
		return;

	deleteTree(start->left);
	deleteTree(start->right);

	delete start;
}

template <class T>
BSTNode<T>* BSTree<T>::search(T element) {
	search(root, element);
}

template <class T>
BSTNode<T>* BSTree<T>::search(BSTNode<T> *start, T element) {
	if (start->key == element || start == NULL)
		return start;

	if (start->key > element)
		search(start->left, element);
	else
		search(start->right, element);
}

template <class T>
BSTree<T>::~BSTree() {
	deleteTree(root);
}