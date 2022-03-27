#pragma once

#include "DSException.h"

template <class T>
class StaticQueue
{
private:
	T* queue;
	int size;
	int head;
	int tail;
	int numberOfElements;

public:
	StaticQueue(int size);

	~StaticQueue();

	bool isEmpty() const { return this->numberOfElements == 0; }
	int getNumberOfElements() const { return this->numberOfElements; }

	T getHead() const;
	void enqueue(T element);
	T dequeue();
};

template <class T>
StaticQueue<T>::StaticQueue(int size)
{
	this->queue = new T[size];
	this->size = size;
	this->head = this->tail = -1;
	this->numberOfElements = 0;
}

template <class T>
StaticQueue<T>::~StaticQueue()
{
	if (this->queue)
	{
		delete[] this->queue;
	}
}

template <class T>
T StaticQueue<T>::getHead() const
{
	if (this->isEmpty())
	{
		throw DSException("Queue underflow!");
	}

	return this->queue[this->head];
}

template <class T>
void StaticQueue<T>::enqueue(T element)
{
	if (this->size == this->numberOfElements)
	{
		throw DSException("Queue overflow!");
	}

	if (++this->tail == this->size)
	{
		this->tail = 0;
	}

	this->queue[this->tail] = element;

	if (this->isEmpty())
	{
		this->head = this->tail;
	}

	this->numberOfElements++;
}

template <class T>
T StaticQueue<T>::dequeue()
{
	if (this->isEmpty())
	{
		throw DSException("Queue underflow!");
	}

	T result = this->queue[this->head];

	if (++this->head == this->size)
	{
		this->head = 0;
	}

	this->numberOfElements--;

	if (this->isEmpty())
	{
		this->head = this->tail = -1;
	}

	return result;
}