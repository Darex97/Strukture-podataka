#include "StackAsArray.h"
void main()
{
	try
	{
		StackAsArray a(10);
		a.push(5);
		a.push(4);
		a.push(3);
		a.push(2);
		a.push(1);
		a.stampaj();
		a.pop();
		a.pop();
		a.push(10);
		a.stampaj();
	}
	catch(char *a)
	{
		cout<<a<<endl;
	}
}