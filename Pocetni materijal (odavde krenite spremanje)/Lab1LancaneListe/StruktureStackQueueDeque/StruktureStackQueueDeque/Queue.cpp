#include"Queue.h"

bool Queue::isEmpty() { return (numOfElements == 0); }

long Queue::numberOfElements() { return this->numOfElements; }

Queue::~Queue() { delete[] niz; }
int Queue::getHead() {
	if (this->numOfElements == 0)
		throw "Queue Underflow.";
	return niz[head];
}
void Queue::enqueue(int objekat) {
	if (this->numOfElements == size)
		throw "Queue Overflow.";
	if (++tail == size)
		tail = 0;//ciklicno, rodjo
	niz[tail] = objekat;
	if (numOfElements == 0)
		head = tail;
	numOfElements++;
}
int Queue::dequeue() {
	if (numOfElements == 0)
		throw "Queue underflow.";
	int result = niz[head];
	if (++head == size)
		head = 0;
	numOfElements--;
	if (numOfElements == 0)
		head = tail = -1;
	return result;
}

