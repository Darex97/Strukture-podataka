#include<iostream>
using namespace std;
class Stack
{
public:

	virtual int getTop() { throw exception("zoves virtuelnu fju"); }
	virtual void push(int object){ throw exception("zoves virtuelnu fju"); }
	virtual int pop(){ throw exception("zoves virtuelnu fju"); }
	virtual bool isEmpty() { return true; }
	virtual long numberOfElements() { return 0; }


};