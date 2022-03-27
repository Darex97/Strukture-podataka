#include "DequeueAsLList.h"

void main()
{
	try
	{
		DequeueAsLList a;
		a.enqueuehead(3);
		a.enqueuehead(2);
		a.enqueuehead(1);
		a.stampaj();
		a.enqueuetail(4);
		a.enqueuetail(5);
		a.stampaj();
		a.dequeuehead();
		a.dequeuetail();
		a.stampaj();
	}
	catch(char *a)
	{
		cout<<a<<endl;
	}
}