#include "Stek.h"

Stek::Stek()
{
	vrh=NULL;
}
void Stek::deletefromhead()
{
	Node *tmp=vrh;
	vrh=vrh->getnext();
	delete tmp;
}
Stek::~Stek()
{
	while(!IsEmpty())
		deletefromhead();
}
void Stek::push(int x)
{
	vrh=new Node(x,vrh);
}
int Stek::pop()
{
	if(vrh==NULL)
		throw "Magacin je prazan";
	Node *tmp=vrh;
	int rez=vrh->getinfo();
	vrh=vrh->getnext();
	delete tmp;
	return rez;
}
void Stek::stampaj()
{
	for(Node* tmp=vrh;tmp!=NULL;tmp=tmp->getnext())
		tmp->print();
	cout<<"/////"<<endl;
}