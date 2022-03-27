#include"Node.h"
#include"DequeueAsList.h"

void main()
{
	try
	{
		DequeueAsList D;
		D.enqueueHead(2);
		D.enqueueHead(1);
		D.enqueueTail(3);
		D.enqueueTail(4);
		D.PRINT();

		D.dequeueTail();
		D.PRINT();
		D.dequeueTail();
		D.PRINT();
		D.dequeueTail();
		D.PRINT();
		D.dequeueTail();
		D.PRINT();
	}
	catch(char *message)
	{
		cout<<message<<endl;
	}
}