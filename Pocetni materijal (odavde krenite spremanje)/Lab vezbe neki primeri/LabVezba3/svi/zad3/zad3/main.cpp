#include "StackAsLList.h"

void main()
{
	try
	{
		StackAsLList a;
		a.push(5);
		a.push(4);
		a.push(3);
		a.push(2);
		a.push(1);
		a.stampaj();
		a.pop();
		a.pop();
		a.stampaj();

	}
	catch(char* a)
	{
		cout<<a<<endl;
	}
}