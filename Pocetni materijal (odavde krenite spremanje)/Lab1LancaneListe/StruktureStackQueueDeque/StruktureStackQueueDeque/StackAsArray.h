#pragma once
#include"StackJedan.h"

class StackAsArray : public StackJedan
{
protected:
	int* array;
	int size;
	int top;
public:
	StackAsArray(long nsize) {
		size = nsize;
		array = new int[size];
		top = -1;//vrh
	}
	
	bool isEmpty();
	long numberOfElements();
	virtual ~StackAsArray();
	void push(int object);
	int pop();
	int getTop();

	
};
