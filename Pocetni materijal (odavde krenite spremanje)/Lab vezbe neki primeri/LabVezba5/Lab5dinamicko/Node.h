#pragma once

#include <iostream>

using namespace std;

class Node
{
public:
	Node() : _key(0), _left(0), _right(0) {}
	Node(int key) : _key(key), _left(0), _right(0) {}
	Node(int key, Node* left, Node* right) : _key(key), _left(left), _right(right) {}
	~Node() {}

	int getKey() { return _key; }
	Node* getLeft() { return _left; }
	Node* getRight() { return _right; }

	void setKey(int key) { _key = key; }
	void setLeft(Node* left) { _left = left; }
	void setRight(Node* right) { _right = right; }

	bool isEqual(int key) { return _key == key; }
	bool isGreater(int key) { return _key > key; }
	bool isLesser(int key) { return _key < key; }

	void print() { cout << _key << " "; }

private:
	int _key;
	Node* _left;
	Node* _right;
};