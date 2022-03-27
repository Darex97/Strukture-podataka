#include <iostream>
#include "StackAsArray.h"
#include "QueueAsArray.h"
#include "DequeAsArray.h"

using namespace std;

void main()
{
	try{
	QueueAsArray<int> a(10);
	a.enqueue(1);
	a.enqueue(62);
	a.enqueue(33);
	cout<<a.getHead()<<endl;}
	catch(char *a)
	{cout<<a<<endl;}
}
