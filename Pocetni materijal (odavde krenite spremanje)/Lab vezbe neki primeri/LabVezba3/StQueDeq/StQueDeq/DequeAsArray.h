#include "QueueAsArray.h"


#include <iostream>

using namespace std;

template <class T>
class DequeAsArray : public QueueAsArray<T>
{
public:

DequeAsArray(long nsize) : QueueAsArray<T>(nsize){ };

void enqueueHead(T object)
{
	if (numOfElements == size)
	throw "Deque overflow!";
	if (numOfElements == 0)
	head = tail = 0;
	else if (head— == 0)
	head = size - 1;
	array [head] = object;
	++numOfElements;
};
T dequeueHead() { return dequeue(); };

T getTail(){
	if (numOfElements == 0)
	throw "Deque underflow!";
	return array[tail];
};
void enqueueTail(T object) { enqueue (object); };

T dequeueTail(){
	if (numOfElements == 0)
	throw "Deque underflow!";
	T result = array [tail];
	if (tail- == 0)
	tail = size - 1;
	--numOfElements;
	return result;
	};
};