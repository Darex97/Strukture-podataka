#include "Dvamagacina.h"

void main()
{
	try
	{
		Dvamagacina a(10);
		a.push1(3);
		a.push1(2);
		a.push1(1);
		a.push2(1);
		a.push2(2);
		a.push2(3);
		a.stampaj();
		a.push1(0);
		a.push1(1);
		a.push2(4);
		a.push2(5);
		a.stampaj();
		a.pop1();
		a.push2(6);
		a.stampaj();
		a.pop2();
		a.pop2();
		a.push1(2);
		a.push1(3);
		a.stampaj();
	}
	catch(char *a)
	{
		cout<<a<<endl;
	}
}