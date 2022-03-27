#include<iostream>
using namespace std;
class QueueAsArray
{
protected:
	int* array;
	long size;
	long head;
	long tail;
	long numOfElements;
public:
	QueueAsArray(long nSize)
	{
		size = nSize;
		array = new int[size];
		head = tail = -1;
		numOfElements = 0;
	}
	bool isEmpty() { return(numOfElements == 0); }
	long numberOfElements() { return numOfElements; }
	~QueueAsArray() { delete[] array; }
	int getHead()
	{
		if (numOfElements == 0)
			cout << "prazan";
		return array[head];
	}
	void enqueue(int object)
	{
		if (numOfElements == size)
			cout << "punn";
		if (++tail == size)
			tail = 0;
		array[tail] = object;
		if (numOfElements == 0)
			head = tail;
		numOfElements++;
	}
	int dequeue()
	{
		if (numOfElements == 0)
			cout << "prazann";
		int result = array[head];
		if (++head == size) head = 0;
		numOfElements--;
		if (numOfElements == 0)
			head = tail = -1;
		return result;
	}

};