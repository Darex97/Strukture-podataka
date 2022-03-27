#include "QueueAsArray.h"

QueueAsArray::QueueAsArray(int x)
{
	velicina=x;
	niz=new int[x];
	head=tail=-1;
	brel=0;
}
QueueAsArray::~QueueAsArray()
{
	delete [] niz;
}
void QueueAsArray::enqueue(int x)
{
	if(brel==velicina)
		throw "Prekoracenje";
	if(++tail==velicina)
		tail=0;
	niz[tail]=x;
	if(brel==0)
		head=tail;
	brel++;
}
int QueueAsArray::dequeue()
{
	if(brel==0)
		throw "Potkoracenje";
	int rez=gethead();
	if(++head==velicina)
		head=0;
	brel--;
	if(brel==0)
		head=tail=-1;
	return rez;
}
