#include "QueueAsArray.h"

QueueAsArray::QueueAsArray(int n)
{
	duzina=n;
	this->niz=new int[duzina];
	head=tail=-1;
	brelemenata=0;
}
QueueAsArray::~QueueAsArray()
{
	delete [] niz;
}
void QueueAsArray::enqueue(int x)
{
	if(brelemenata==duzina)
		throw "Prekoracenje";
	if(++tail==duzina)
		tail=0;
	niz[tail]=x;
	if(brelemenata==0)
		head=tail;
	brelemenata++;
}
int QueueAsArray::dequeue()
{
	if(brelemenata==0)
		throw "Potkoracenje";
	int rezultat=niz[head];
	if(++head==duzina)
		head=0;
	brelemenata--;
	if(brelemenata==0)
		head=tail=-1;
	return rezultat;
}