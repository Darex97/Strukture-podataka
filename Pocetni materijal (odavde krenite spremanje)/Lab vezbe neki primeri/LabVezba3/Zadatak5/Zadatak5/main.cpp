#include"Node.h"
#include"QueueAsList.h"

void main()
{
	try{
	QueueAsList R;
	R.enqueue(5);
	R.enqueue(6);
	R.enqueue(9);
	R.enqueue(0);
	R.enqueue(3);
	R.PRINT();
	cout<<"br elemenata:"<<R.numberOfElements()<<endl;
	cout<<R.dequeue()<<endl;
	R.PRINT();
	cout<<"br elemenata:"<<R.numberOfElements()<<endl;
	cout<<R.dequeue()<<endl;
	R.PRINT();
	cout<<R.dequeue()<<endl;
	R.PRINT();
	cout<<R.dequeue()<<endl;
	R.PRINT();
	cout<<R.dequeue()<<endl;
	R.PRINT();
	}
	catch(char *message)
	{
		cout<<message<<endl;
	}
}