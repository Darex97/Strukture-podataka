#pragma once
#include "Node.h"

#include <iostream>
#include <cstdlib>
using namespace std;

class ReorgList
{
public:
	ReorgList();
	~ReorgList();

	void addToTail(Node& node);
	void addToHead(Node& node);
	void removeFromHead();

	void addToHead();

	void getToStart(int key);

	void getTransp(int key);

	void print();


private:
	Node* _head;
};