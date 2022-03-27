#pragma once
#include "iostream"
using namespace std;
class Node {
public:
	int exp;
	double coef;
	Node *next;
	Node()
	{
		exp = coef = 0;
		next = NULL;
	}
	Node(int x, double y, Node* z)
	{
		exp = x;
		coef = y;
		next = z;
	}



};

