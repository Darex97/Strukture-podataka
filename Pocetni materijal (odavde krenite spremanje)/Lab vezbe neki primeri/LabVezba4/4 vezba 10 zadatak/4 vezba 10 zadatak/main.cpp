#include"element.h"
#include"adresiranje.h"
#include"tablica.h"
#include<iostream>
using namespace std;
void main()
{
	try
	{
		adresiranje<int,char> m(10);
	    element<int,char> p(254941,"SANJA");
		m.insert(p);
		p=element<int,char>(982311,"JOVANOVIC");
		m.insert(p);
		p=element<int,char>(4564034,"STRUKTURE");
		m.insert(p);
		p=element<int,char>(9765356,"LAB_VEZBA");
		m.insert(p);
		m.display();
	}
	catch(char *iz)
	{
		cout<<iz<<endl;
	}
}