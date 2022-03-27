#pragma once

template <class T>
class BSTNode
{
public:
	T key;
	BSTNode<T>* left;
	BSTNode<T>* right;

public:
	BSTNode() { this->left = this->right = nullptr; }

	BSTNode(T element);
	BSTNode(T element, BSTNode<T>* left, BSTNode<T>* right);

	~BSTNode() { }

	bool isLower(T element) const { return this->key < element; }
	bool isEqual(T element) const { return this->key == element; }
	bool isGreater(T element) const { return this->key > element; }
};

template <class T>
BSTNode<T>::BSTNode(T element)
{
	this->key = element;
	this->left = this->right = nullptr;
}

template <class T>
BSTNode<T>::BSTNode(T element, BSTNode<T>* left, BSTNode<T>* right)
{
	this->key = element;
	this->left = left;
	this->right = right;
}