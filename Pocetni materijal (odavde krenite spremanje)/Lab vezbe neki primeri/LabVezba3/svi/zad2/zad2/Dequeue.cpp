#include "Dequeue.h"

Dequeue::Dequeue(int x)
{
	this->duzina=x;
	this->niz=new int[duzina];
	head=tail=-1;
	this->brelemenata=0;
}
Dequeue::~Dequeue()
{
	delete [] niz;
}
void Dequeue::enqueuehead(int x)
{
	if(brelemenata==duzina)
		throw "Prekoracenje";
	if(brelemenata==0)
		head=tail=0;
	else
		if(head--==0)
			head=tail=duzina-1;
	niz[head]=x;
	++brelemenata;
}
void Dequeue::enqueuetail(int x)
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
int Dequeue::dequeuehead()
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
int Dequeue::dequeuetail()
{
	if(brelemenata==0)
		throw "Potkoracenje";
	int rezultat=niz[tail];
	if(tail--==0)
		tail=duzina-1;
	brelemenata--;
	return rezultat;
}