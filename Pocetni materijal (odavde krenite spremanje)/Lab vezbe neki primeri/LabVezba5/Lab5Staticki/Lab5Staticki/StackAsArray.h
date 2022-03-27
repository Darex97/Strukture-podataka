#pragma once

class StackAsArray
{
public:
	int* _array;
	int size;
	int top;
public:
	StackAsArray(void);
	~StackAsArray(void);

	StackAsArray(int size)
	{
		this->size=size;
		//niz=new BSTNode(n);
		top=-1;
	}

	bool IsEmpty()
	{
		if(top==-1)
			return true;
		return false; 
	}

	void push (int el)
	{
		top++;
		this->_array[top]=el;
	}
	int pop ()
	{
		int tmp;
		tmp=this->_array[top];
		top--;
		return tmp;
	}
};
