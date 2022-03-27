#pragma once
#include <iostream>
using namespace std;
class Stack
	
{
public:
	virtual int getTop(){ throw new exception ("virtual function cal");}
	virtual void push(int object) { throw new exception ("virtual function cal");}
	virtual int pop(){ throw new exception ("virtual function cal");}
	virtual bool isEmpty() { return true;}
	virtual long numberOfElements() {return 0;}
};
