#pragma once

class Stack
{
public:
	char* niz;
	int n;
	int top;
	Stack(void){}
	Stack(int a);
	~Stack(void);
	bool isEmpty() {return top==-1;}
	void push(char c);
	char pop();
	char getTop();
	int prioritet(char c);
	void uPostfix(char* s);
};
