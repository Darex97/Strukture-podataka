// Lista.cpp: implementation of the Lista class.
//
//////////////////////////////////////////////////////////////////////

#include "Lista.h"
#include <iostream.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
Lista::Lista()
{
	
	exp=koef=0;
	sledeci=tail=head=0;
}

void Lista::Unesi(int b)
{
	head=0;
	tail=0;
	if(b!=0)
		{
		
		Lista* n=new Lista;
		head=n;
		tail=n;
		cout << "Unesite exponent i koeficijent ";
		cin >> n->exp >> n->koef;
		n->sledeci=0;
		for(int i=1;i<b;i++)
		{
		Lista* n=new Lista;
		cout << "Unesite exponent i koeficijent ";
		cin >> n->exp >> n->koef;
		tail->sledeci=n;
		n->sledeci=0;
		tail=n;
		}
	
		}	
}
void Lista::Prikazi()
{
	Lista* p;
	p=head;
	while(p->sledeci!=0)
		{
		cout << p->koef<<"*x na"<<p->exp<<"+";
		p=p->sledeci;
		}
	cout << tail->koef<<"*x na"<<tail->exp<<endl;
}
void Lista::addTohead(int e,int k)
{
	Lista* n=new Lista;
	if(head==0)
		{
		tail=n;
		head=n;
		n->sledeci=0;
		}
		else
		{
		n->sledeci=head;
		head=n;
		}
	n->exp=e;
	n->koef=k;
}