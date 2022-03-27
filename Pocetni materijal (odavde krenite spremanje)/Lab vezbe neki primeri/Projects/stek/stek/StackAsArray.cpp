#include "StackAsArray.h"
#include <iostream>
using namespace std;

StackAsArray::StackAsArray(int duzina)
{
	size = duzina;
	array = new int[size];
	top = -1;
}
StackAsArray::~StackAsArray()
{
	delete[] array;
}
int StackAsArray::getTop()
{
	int result;
	if (top == -1)
		throw "Lista je prazna";
	else
	result = array[top];
		return result;
}
void StackAsArray::push(int el)
{
	if (top == size - 1)
		throw "Lista je puna";
	else
		array[++top] = el;
}
int StackAsArray::pop()
{
	int result;
	if (isEmpty())
		throw "Lista je prazna";
	else
		result = array[top--];
	return result;
}
bool StackAsArray::isEmpty()
{
	return top == -1;
}
int StackAsArray::numberOfElements()
{
	int br;
	if (isEmpty())
		throw "Lista je prazna";
	else
	br = top + 1;
	return br;
}
void StackAsArray::print()
{
	for (int i = top; i > -1; i--)
		cout << array[i] << endl;
}