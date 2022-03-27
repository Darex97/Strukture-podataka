#pragma once

class StackJedan
{
public: 
	virtual int getTop()=0;//samo cita, ne uklanja vrsni element
	virtual void push(int object)=0;
	virtual int pop()=0;
	virtual bool isEmpty() { return true; }
	virtual long numberOfElements() = 0;
};