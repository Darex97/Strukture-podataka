//#include "Stack.h"
#include<iostream>
using namespace std;
class StackAsArray //:public Stack
{protected:
	int* array;
	long size;
	long top;
public:
	StackAsArray(long nsize) {
		size = nsize;
		array = new int[size];
		top = -1;
	}
	bool isEmpty() { return (top == -1); }
	long numberOfElements() { return(top + 1); }
	~StackAsArray() { delete[] array; }
	void push(int object) {
		if (top==(size-1))
			cout << "pun";
		array[++top] = object;
	}
	int pop() {
		if (isEmpty())
			cout << "prazan";
		int result = array[top--];
		cout << result << endl;
		return result;

	}
	int getTop()
	{
		if (isEmpty())
			cout << "prazan";
		return array[top];
	}



};