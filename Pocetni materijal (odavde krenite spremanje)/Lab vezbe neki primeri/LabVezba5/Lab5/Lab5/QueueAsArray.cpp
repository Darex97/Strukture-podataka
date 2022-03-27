#include "QueueAsArray.h"



QueueAsArray::QueueAsArray(int size)
{
	this->size=size;
	this->_array=new BSTNode*[size];
	this->head=this->tail=-1;
	this->numOfElements=0;
}

void QueueAsArray::enqueue(BSTNode *el)
{
	if (this->numOfElements==this->size)
		throw "Red je pun";
	if (++this->tail==this->size)
		this->tail=0;
	this->_array[this->tail]=el;
	if (this->numOfElements==0)
		head=tail;
	this->numOfElements++;
}
BSTNode* QueueAsArray::dequeue()
{
	if (this->numOfElements==0)
		throw "Red je prazan.";
	BSTNode *result=this->_array[this->head];
	if (++this->head==size)
		this->head=0;
	this->numOfElements--;
	if (this->numOfElements==0)
		this->head=this->tail=-1;
	return result;
}

QueueAsArray::~QueueAsArray(void)
{
}
