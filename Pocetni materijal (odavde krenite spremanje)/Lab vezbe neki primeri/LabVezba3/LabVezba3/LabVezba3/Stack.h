#pragma once
class Stack
{
private:
	int *_array;
	int size;
	int top;
public:
	Stack(int size);
	void push(int number);
	int pop();
	~Stack();
};

