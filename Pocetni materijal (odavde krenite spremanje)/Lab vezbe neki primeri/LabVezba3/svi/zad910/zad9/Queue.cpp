#include "Queue.h"

Queue::Queue(int x)
{
	velicina=x;
	niz=new int[x];
	head=tail=-1;
	brel=0;
}
Queue::~Queue()
{
	delete [] niz;
}
void Queue::enqueue(int x)
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
int Queue::dequeue()
{
	if(brel==0)
		throw "Potkoracenje";
	int rez=niz[head];
	if(++head==velicina)
		head=0;
	if(brel==0)
		head=tail;
	brel--;
	return rez;
}