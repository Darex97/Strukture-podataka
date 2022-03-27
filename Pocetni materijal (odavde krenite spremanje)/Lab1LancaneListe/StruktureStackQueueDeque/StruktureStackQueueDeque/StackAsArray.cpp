#include"StackAsArray.h"
#include"StackJedan.h"
//definisemo funkcije ciju smo deklaraciju naveli u 
//apstraktnoj klasi

StackAsArray::~StackAsArray() { delete[] array; }

bool StackAsArray::isEmpty() { return(top == -1); }

long StackAsArray::numberOfElements() { return (top + 1); }//da ne pamtimo poseban element



void StackAsArray::push(int object)
{
	if ( top == (size - 1))
		throw "Stack overflow.";
	array[++top] = object;
}

int StackAsArray::pop() {
	if (top == -1)
		throw "Stack underflow.";
	int result = array[top--];
	return result;
}
//nema brisanja elementa nakon citanja

int StackAsArray::getTop() {
	if (top == -1)
		throw "Stack underflow.";
	return array[top];
}