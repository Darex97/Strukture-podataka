#pragma once
#include <iostream>
#include <exception>
class BSTNode
{
public: 
	int value;
	BSTNode* left;
	BSTNode* right;
public:
	BSTNode() {
		value = 0;
		left = NULL;
		right = NULL;
	}
	BSTNode(int el) {
		value = el;
		left = NULL;
		right = NULL;
	}
};

