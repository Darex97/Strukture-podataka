#pragma once
class DequeueAsArray
{
protected:
	int *array;
	int size;
	int head;
	int tail;
	int num_of_elements;
public:
	DequeueAsArray();
	virtual int getHead();
	int getTail();
	virtual int NumberOfElements();
	virtual bool isEmpty();
	virtual void enqueueHead(int number);
	void enqueueTail(int number);
	virtual int dequeueHead();
	int dequeueTail();
	~DequeueAsArray();
};