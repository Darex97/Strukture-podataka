#pragma once
#include <iostream>

using namespace std;

template <class T>
class BSTNode
{
public:
	T key;
	BSTNode<T> *left;
	BSTNode<T> *right;

	BSTNode(void);
	BSTNode(T key);
	BSTNode(T key, BSTNode<T> *left, BSTNode<T> *right);
};

template <class T>
BSTNode<T>::BSTNode(void) {
	left = right = NULL;
	key = (T)0;
}

template <class T>
BSTNode<T>::BSTNode(T key) {
	this->key = key;
	left = right = NULL;
}

template <class T>
BSTNode<T>::BSTNode(T key, BSTNode<T> *left, BSTNode<T> *right) {
	this->key = key;
	this->left = left;
	this->right = right;
}