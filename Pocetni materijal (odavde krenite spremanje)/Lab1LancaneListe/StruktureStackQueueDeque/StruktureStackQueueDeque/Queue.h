#pragma once
class Queue {
protected:
	int* niz;
	long size;
	long head;
	long tail;
	long numOfElements;
public:
	Queue(long nsize)
	{
		size = nsize;
		niz = new int[size];
		head = tail = -1;
		numOfElements = 0;
	}
	bool isEmpty();
	long numberOfElements();
	~Queue();
	int getHead();
	void enqueue(int objekat);
	int dequeue();
	

};