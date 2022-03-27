#include "DequeueAsArray.h"

void main()
{
	try
	{
		DequeueAsArray a(10);
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(3);
		a.stampaj();
		a.enqueuehead(5);
		a.enqueuehead(6);
		a.stampaj();
		a.dequeuetail();
		a.stampaj();
		a.dequeue();
		a.stampaj();
	}
	catch(char *a)
	{
		cout<<a<<endl;
	}
}