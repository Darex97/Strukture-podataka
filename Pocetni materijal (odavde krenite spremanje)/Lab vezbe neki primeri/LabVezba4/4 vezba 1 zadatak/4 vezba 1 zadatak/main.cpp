#include<iostream>
#include <cstring>
#include "tabla.h"
#include "element.h"
using namespace std;

void main()
{
	try
	{
	tabla<char*,int> m(10);
	    element<char*,int> p("if");
		m.insert(p);
		p=element<char*,int>("for");
		m.insert(p);
		p=element<char*,int>("while");
		m.insert(p);
		p=element<char*,int>("char");
		m.insert(p);
		p=element<char*,int>("int");
		m.insert(p);
		p=element<char*,int>("double");
		m.insert(p);
		m.display();
	}
	
	catch(char *izuzetak)
	{
		cout << izuzetak << endl;
	}
}