#pragma once
#include<iostream>
using namespace std;

class DoubleStack
{
private:
	int size;
	int *_array;
	int top1;
	int top2;
public:
	DoubleStack();
	bool isEmpty();
	bool isFull();
	void push(int number,bool s);
	int pop(bool s);
	int numOfElements();
	DoubleStack(int size);
	void print();
	~DoubleStack(void);
};

