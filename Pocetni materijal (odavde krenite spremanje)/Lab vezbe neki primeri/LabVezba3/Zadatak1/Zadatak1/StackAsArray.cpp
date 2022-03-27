#include "StackAsArray.h"


StackAsArray::StackAsArray(void)
{
}
StackAsArray::StackAsArray(int size)
{
	this->size=size;
	array=new int[this->size];
	this->head=-1;
}
int StackAsArray::NumberOfElements()
{
	if (head==-1)
		return 0;
	else
		return head+1;
}
bool StackAsArray::isEmpty()
{
	if (this->head==-1)
		return true;
	else
		return false;
}
void StackAsArray::enqueue(int number)
{
	if (++this->tail<this->size)
		this->array[tail]=number;
	else
		throw "Stek je pun.";
}
int StackAsArray::dequeue()
{
	int result;
	if (numofelements == 0)
		throw "Red je prazan";
	else
		result = array[head];
		if (++head == size) head = 0;
	numofelements--;
	if (numofelements == 0) head = tail = -1;
	return result;

}
StackAsArray::~StackAsArray(void)
{
	delete []this->array;
}
void StackAsArray::print()
{
	for (int i = 0; i < numofelements; i++)
		cout << array[i] << endl;
}