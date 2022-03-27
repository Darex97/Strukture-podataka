#include "StackAsArray.h"
#include <iostream>
using namespace std;
void main()
{
	try
	{
		StackAsArray a(10);
		a.push(3);
		a.push(4);
		a.push(5);
		a.push(6);
		a.stampaj();
		a.pop();
		a.pop();
		a.push(7);
		a.stampaj();
	}
	catch(char *a)
	{
		cout<<a<<endl;
	}
}