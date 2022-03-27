#include "DequeueAsArray.h"

DequeueAsArray::DequeueAsArray(int x)
	: QueueAsArray(x)
{
}
void DequeueAsArray::enqueuehead(int x)
{
	if(brel==velicina)
		throw "Prekoracenje";
	if(brel==0)
		head=tail=0;
	else 
		if(head--==0)
			head=velicina-1;
	niz[head]=x;
	brel++;
}
int DequeueAsArray::dequeuetail()
{
	if(brel==0)
		throw "Potkoracenje";
	int rez=gettail();
	if(tail--==0)
		tail=velicina-1;
	brel--;
	return rez;
}
void DequeueAsArray::stampaj()
{
	int tmp=head;
	while(head!=tail)
	{
		if(head==velicina)
			head=0;
		cout<<gethead()<<" ";
		head++;
	}
	cout<<gethead()<<endl;//jer kad su jednaki pokazuju na 1 element
	cout<<"/////"<<endl;
	head=tmp;
}