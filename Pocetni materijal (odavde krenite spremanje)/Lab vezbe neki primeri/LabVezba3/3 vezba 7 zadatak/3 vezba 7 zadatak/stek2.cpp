#include "stek2.h"
#include<iostream>
using namespace std;
stek2::stek2(int t)
{
	n=t;
	a=new int[n];
	top1=-1;
	top2=n;
}

stek2::~stek2(void)
{
	delete [] a;
}
void stek2::pushstek1(int el)
{
	if(top1+1==top2)
		throw "nema mesta u prvom steku";
	top1++;
	a[top1]=el;

}
void stek2::puchstek2(int el)
{
	if(top2-1==top1)
		throw "nema mesta u drugom steku";
	top2--;
	a[top2]=el;
}
int stek2::popstek1()
{
	if(top1==-1)
		throw "stek 1 je prazan";
	int pom=a[top1];
	top1--;
	return pom;
}
int stek2::popstek2()
{
	if(top2==n)
throw "stek 2 je prazan";
	int pom=a[top2];
	top2++;
	return pom;
}
void stek2::stampajstek1()
{
	for(int i=top1;i>=0;i--)
			cout<<a[i]<<endl;
}
void stek2::stampajstek2()
{
	for(int i=top2;i<n;i++)
			cout<<a[i]<<endl;

}