#include<iostream>
#include <cstring>
#include "tabla.h"
#include "element.h"
using namespace std;

void main()
{
	try
	{
	    tabla<int,char> m(10);
	    element<int,char> p(2549412,"SANJA");
		m.insert(p);
		m.display();
		p=element<int,char>(1234512,"JOVANOVIC");
		m.insert(p);
		p=element<int,char>(4564034,"STRUKTURE");
		m.insert(p);
		p=element<int,char>(9765356,"LAB_VEZBA");
		m.insert(p);
		m.display();
	}
	
	catch(char *izuzetak)
	{
		cout << izuzetak << endl;
	}
}