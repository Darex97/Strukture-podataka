#include "Stek.h"

void main()
{
	try
	{
		Stek a(10);
		a.push(5);
		a.push(4);
		a.push(3);
		a.push(2);
		a.push(1);
		a.stampaj();
		a.reverseastack();
		a.stampaj();
		a.reverseaqueue();
		a.stampaj();
		Stek b(2);
		b.copyStack(a);
		b.stampaj();
	}
	catch(char* a)
	{
		cout<<a<<endl;
	}
}