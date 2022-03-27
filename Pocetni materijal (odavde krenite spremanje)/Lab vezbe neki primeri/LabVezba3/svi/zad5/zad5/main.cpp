#include "QueueAsLList.h"

void main()
{
	try
	{
		QueueAsLList a;
		a.enqueue(1);
		a.enqueue(2);
		a.enqueue(3);
		a.stampaj();
		a.dequeue();
		a.stampaj();
		a.enqueue(5);
		a.stampaj();
	}
	catch(char *a)
	{
		cout<<a<<endl;
	}
}